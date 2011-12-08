<?php

class SwtorArticlesMigration extends SwtorMigration {
  public function __construct() {    
    parent::__construct();

    // Give the task a description.
    $this->description = t('Migrate article pages');

    // We need to migrate users before articles.
    $this->dependencies = array('SwtorUsers');

    $source_fields = array(
      'nid' => t('The node ID of the article'),
      'title_image' => t('Article images from field image'),
      'image_gallery' => t('Image gallery found on some articles'),
      'field_video' => t('Video field'),
    );

    // Select all article nodes.
    $query = db_select($this->source_db .'.node', 'n')
             ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'))
             ->condition('n.type', 'article_with_image');
    $query->join($this->source_db .'.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->join($this->source_db .'.users', 'u', 'n.uid = u.uid');
    $query->addField('u', 'name');
    $query->orderBy('n.changed');

    // Add information about migrating updates of content.
    $this->highwaterField = array(
      'name' => 'changed',
      'alias' => 'n',
    );

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('article');

    // Define the SQL mapping.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

     // Make the mappings
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
    $this->addFieldMapping('revision')
         ->defaultValue(TRUE);
    $this->addFieldMapping('revision_uid', 'uid');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('comment', 'comment');
    $this->addFieldMapping('language')
         ->defaultValue('und');

    $this->addFieldMapping(NULL, 'name');
    $this->addFieldMapping(NULL, 'vid');
    $this->addFieldMapping(NULL, 'type');
    $this->addFieldMapping(NULL, 'language');
    $this->addFieldMapping(NULL, 'moderate');
    $this->addFieldMapping(NULL, 'tnid');
    $this->addFieldMapping(NULL, 'translate');

    // Map uid base on user migration.
    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('SwtorUsers');

    // Unmapped source fields
    $this->addFieldMapping(NULL, 'field_video')
         ->issueGroup(t('DNM'));

    // Unmapped fields.
    $this->addFieldMapping('path')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping('pathauto')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping('field_tags')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping('field_source')
         ->issueGroup(t('DNM'));

    // Map body and summary.
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field' => 'teaser'), 'editor_html', NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping(NULL, 'teaser');

    // Map title image files, the file is copied in the prepareRow method.
    $associated_file_arguments = MigrateFileFieldHandler::arguments(NULL, 'file_copy', FILE_EXISTS_RENAME);
    $this->addFieldMapping('field_image', 'title_image')
         ->arguments($associated_file_arguments);

    // Map gallery images
    $associated_file_arguments = MigrateFileFieldHandler::arguments(NULL, 'file_copy', FILE_EXISTS_RENAME);
    $this->addFieldMapping('field_articles_gallery', 'image_gallery')
         ->arguments($associated_file_arguments);
  }

  public function prepareRow($current_row) {
    // Get more information about the title images
    $image_query = db_select($this->source_db . '.content_type_article_with_image', 'cfi')
                   ->condition('cfi.nid', $current_row->nid);
    $image_query->join($this->source_db . '.files', 'f', 'cfi.field_image_fid = f.fid');
    $image_query->addField('f', 'filepath');
    $image_query->addField('cfi', 'field_image_data', 'data');
    $results = $image_query->execute();
    $current_row->title_image = $this->build_image_array($results);

    // Get information about the articles galleries.
    $image_query = db_select($this->source_db . '.content_field_image_gallery', 'cfig')
                   ->condition('cfig.nid', $current_row->nid);
    $image_query->join($this->source_db . '.files', 'f', 'cfig.field_image_gallery_fid = f.fid');
    $image_query->addField('f', 'filepath');
    $image_query->addField('cfig', 'field_image_gallery_data', 'data');
    $results = $image_query->execute();
    $current_row->image_gallery = $this->build_image_array($results);

    return TRUE;
  }

  /**
   * Build image array that can be used to migrate image files. It makes
   * assumptions about the data stucture of the $sql_results object.
   */
  private function build_image_array($sql_results) {
    $images = array();
    foreach ($sql_results as $row) {
      $image_data = array('alt' => '', 'title' => '');
      if ($row->data) {
        $image_data = unserialize($row->data);
      }
      $current_image_data = array(
        'path' => $this->source_path .'/'. $row->filepath,
        'alt' => $image_data['alt'],
        'title' => $image_data['title'],
      );
      $images[] = drupal_json_encode($current_image_data);
    }

    return $images;
  }
}
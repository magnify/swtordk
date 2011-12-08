<?php

class SwtorForumMigration extends SwtorMigration {
  public function __construct() {
    parent::__construct();

    // Give the task a description.
    $this->description = t('Migrate forum nodes');

    // We need to migrate users before articles.
    $this->dependencies = array('SwtorUsers');

    // Select all forum nodes.
    $query = db_select($this->source_db . '.node', 'n')
             ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'))
             ->condition('n.type', 'forum');
    $query->join($this->source_db . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->join($this->source_db . '.users', 'u', 'n.uid = u.uid');
    $query->addField('u', 'name');
    $query->join($this->source_db . '.term_node', 'tn', 'tn.nid = n.nid');
    $query->join($this->source_db . '.term_data', 'td', 'tn.tid = td.tid');
    $query->addField('td', 'name', 'taxonomy_forums');
    $query->orderBy('n.changed');

    // Add information about migrating updates of content.
    $this->highwaterField = array(
      'name' => 'changed',
      'alias' => 'n',
    );

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('forum');

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

    // Map body and summary.
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field' => 'teaser'), 'filtered_html', NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping(NULL, 'teaser');

    // Map taxonomy form.
    $this->addFieldMapping('taxonomy_forums', 'taxonomy_forums');

    // Unmapped fields.
    $this->addFieldMapping('path')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping('pathauto')
         ->issueGroup(t('DNM'));
  }
}

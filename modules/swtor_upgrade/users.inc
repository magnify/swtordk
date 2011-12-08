<?php

class SwtorUsersMigration extends SwtorMigration {
  public function __construct() {
    parent::__construct();

    $this->description = t('Swtor users');
    $this->map = new MigrateSQLMap($this->machineName,
        array('uid' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'ID of sources user',
              ),
             ),
        MigrateDestinationUser::getKeySchema()
    );

    $source_fields = array(
      'fullname' => t('Users full name'),
      'age' => t('The users age.'),
      'skype' => t('The users skype number.'),
      'wlm' => t('The user messagner ID.'),
      'origin' => t('Origin title'),
    );

    $query = db_select($this->source_db . '.users', 'swuser')
             ->fields('swuser', array('uid', 'name', 'pass', 'mail', 'mode',
                                      'sort', 'threshold', 'theme', 'signature',
                                      'signature_format', 'created', 'access',
                                      'login', 'status', 'timezone', 'language',
                                      'picture', 'init', 'data', 'timezone_name'))
             ->condition('uid', 0, '!=');
    $this->source = new MigrateSourceSQL($query, $source_fields);

    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    // One good way to organize your mappings is in three groups - mapped fields,
    // unmapped source fields, and unmapped destination fields

    // Mapped fields

    // This is a shortcut you can use when the source and destination fields are
    // identical
    $this->addSimpleMappings(array('pass', 'theme', 'signature',
                                   'signature_format', 'created', 'access',
                                   'login', 'status', 'timezone', 'language',
                                   'picture', 'init'));

    // Make sure that name and mail is unique.
    $this->addFieldMapping('name', 'name')
         ->dedupe('users', 'name');
    $this->addFieldMapping('mail', 'mail')
         ->dedupe('users', 'mail');

    // Map fields loaded in prepare row.
    $this->addFieldMapping('field_fullname', 'fullname');
    $this->addFieldMapping('field_age', 'age');
    $this->addFieldMapping('field_skype', 'skype');
    $this->addFieldMapping('field_wlm', 'wlm');

    // Instead of mapping a source field to a destination field, you can
    // hardcode a default value. You can also use both together - if a default
    // value is provided in addition to a source field, the default value will
    // be applied to any rows where the source field is empty or NULL.
    $this->addFieldMapping('roles')
         ->defaultValue(2);

    // Unmapped source fields
    $this->addFieldMapping(NULL, 'mode')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'sort')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'threshold')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'timezone_name')
         ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'origin')
         ->issueGroup(t('DNM'));

    // We may need to test if this is need.
    $this->addFieldMapping(NULL, 'data')
         ->issueGroup(t('DNM'));

    // Unmapped destination fields

    // This is a shortcut you can use to mark several destination fields as DNM
    // at once
    $this->addUnmigratedDestinations(array('is_new'));
  }

  public function prepareRow($current_row) {
    $source_id = $current_row->uid;

    // Find fullname.
    $query = db_select($this->source_db . '.profile_values', 'pv')
             ->fields('pv', array('value'))
             ->condition('fid', 2)
             ->condition('uid', $source_id);
    $results = $query->execute();
    foreach ($results as $row) {
      $current_row->fullname = $row->value;
    }

    // Find age.
    $query = db_select($this->source_db . '.profile_values', 'pv')
             ->fields('pv', array('value'))
             ->condition('fid', 3)
             ->condition('uid', $source_id);
    $results = $query->execute();
    foreach ($results as $row) {
      $current_row->age = $row->value;
    }

    // Find vml.
    $query = db_select($this->source_db . '.profile_values', 'pv')
             ->fields('pv', array('value'))
             ->condition('fid', 5)
             ->condition('uid', $source_id);
    $results = $query->execute();
    foreach ($results as $row) {
      $current_row->wlm = $row->value;
    }

    // Find skype.
    $query = db_select($this->source_db . '.profile_values', 'pv')
             ->fields('pv', array('value'))
             ->condition('fid', 6)
             ->condition('uid', $source_id);
    $results = $query->execute();
    foreach ($results as $row) {
      $current_row->skype = $row->value;
    }

//  (SELECT pv.value FROM profile_values pv WHERE pv.fid = 7 AND pv.uid = u.uid) as origin

    return TRUE;
  }
}

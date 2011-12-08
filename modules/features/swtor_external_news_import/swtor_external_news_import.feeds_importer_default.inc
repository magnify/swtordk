<?php
/**
 * @file
 * swtor_external_news_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function swtor_external_news_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'external_news_importer';
  $feeds_importer->config = array(
    'name' => 'External news import',
    'description' => 'Import external news from other sources',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'NewsParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'external_news',
        'expire' => '2419200',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'updated',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'author',
            'target' => 'field_news_author',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'summary',
            'target' => 'field_news_teaser',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'image',
            'target' => 'field_image_url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'url',
            'target' => 'field_source_url:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => 'news_importer',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['external_news_importer'] = $feeds_importer;

  return $export;
}

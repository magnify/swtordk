<?php
/**
 * @file
 * swtor_external_news_import.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function swtor_external_news_import_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function swtor_external_news_import_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function swtor_external_news_import_node_info() {
  $items = array(
    'external_news' => array(
      'name' => t('External news'),
      'base' => 'node_content',
      'description' => t('External news imported via feeds (should not be create by users)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news_importer' => array(
      'name' => t('News importer'),
      'base' => 'node_content',
      'description' => t('Feeds news importer (RSS 1.0, RSS 2.0 and Atom feeds)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

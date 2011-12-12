<?php
/**
 * @file
 * swtor_taxonomy_tags_listing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function swtor_taxonomy_tags_listing_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

<?php
/**
 * @file
 * swtor_featured_content.features.inc
 */

/**
 * Implements hook_views_api().
 */
function swtor_featured_content_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function swtor_featured_content_image_default_styles() {
  $styles = array();

  // Exported image style: frontpage_slideshow
  $styles['frontpage_slideshow'] = array(
    'name' => 'frontpage_slideshow',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '620',
          'height' => '250',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

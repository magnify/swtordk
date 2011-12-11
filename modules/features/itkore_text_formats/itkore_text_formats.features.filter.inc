<?php
/**
 * @file
 * itkore_text_formats.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function itkore_text_formats_filter_default_formats() {
  $formats = array();

  // Exported format: Editor HTML
  $formats['editor_html'] = array(
    'format' => 'editor_html',
    'name' => 'Editor HTML',
    'cache' => '0',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'media_filter' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <span> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <br> <p> <i> <u> <b> <table> <td> <tr> <th> <img> <video> <object> <embed> <param> <audio> <h2> <h3> <h4> <h5> <h6> <iframe>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(),
      ),
      'bbcode' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'bbcode_make_links' => '1',
          'bbcode_filter_nofollow' => '1',
          'bbcode_encode_mailto' => '1',
          'bbcode_paragraph_breaks' => '2',
          'bbcode_debug' => '0',
        ),
      ),
      'ckeditor_link_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}

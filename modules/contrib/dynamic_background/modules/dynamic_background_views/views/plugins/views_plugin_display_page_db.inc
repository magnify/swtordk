<?php

/**
 * @file
 * Contains the dynamic background views page display plugin, which is an
 * extension of the std. view page display.
 */

/**
 * The plugin that handles a full page.
 *
 * @ingroup views_display_plugins
 */
class views_plugin_display_page_db extends views_plugin_display_page {

  function option_definition() {
    $options = parent::option_definition();

    $options['dynamic_background'] = array(
      'title' => 'Dynamic background',
      'description' => t('Select a background for the current page.'),
      'default' => t('No image'),
    );

    return $options;
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    // Find the currently selected image.
    $view_id = $this->view->name . '_' . $this->display->id;
    $image_id = 0;
    $options['dynamic_background'] = array(
      'category' => 'page',
      'title' => t('Dynamic background'),
      'value' => !is_null($image_id) ? 'Image ' . ($image_id + 1) : t('No image'),
    );

    // Try loading styling and js.
    drupal_add_js(drupal_get_path('module', 'dynamic_background') . '/js/dynamic_background_selector.js', 'file');
    drupal_add_css(drupal_get_path('module', 'dynamic_background_views') . '/css/dynamic_background.admin.css', 'module');
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'dynamic_background':
        $view_id = $form_state['view']->name . '_' . $form_state['view']->current_display;
        $form['#title'] .= t('The selected background');
        $form['dynamic_background'] = dynamic_background_image_selector_form('views', $view_id);
        break;
    }
  }

  /**
   * Provide the validation of the default form for setting options.
   */
  function options_validate(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_validate($form, $form_state);

    // Check that only one image have been selected
    switch ($form_state['section']) {
      case 'dynamic_background':
        $no_of_images = 0;
        foreach ($form_state['values']['dynamic_background'] as $key => $value) {
          if ($value['selected']) {
            $no_of_images++;
            if ($no_of_images > 1) {
              form_error($form['dynamic_background'][$key], t('You should only select one image.'));
            }
          }
        }
        break;
    }
  }

  /**
   * Provide the submit handler of the default form for setting options.
   */
  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    switch ($form_state['section']) {
      case 'dynamic_background':
        $view_id = $form_state['view']->name . '_' . $form_state['view']->current_display;
        // Check if any image have been selected.
        $image_id = NULL;
        foreach ($form_state['values']['dynamic_background'] as $key => $value) {
          if ($value['selected']) {
            $image_id = $key;
            break;
          }
        }

        // Try to save the image in the database.
        //$this->save_background($image_id, $view_id);
        break;
    }
  }

  /**
   * Helper function that saves the selected background image for the current
   * view.
   */
  protected function save_background($image_id, $view_id) {
    if (!is_null($image_id)) {
      if (!is_null(dynamic_background_views_get_image_id($view_id))) {
        // Image found, so update the record.
        $res = db_update('dynamic_background_views')
          ->fields(array('data' => $image_id))
          ->condition('view_id', $view_id)
          ->execute();
      }
      else {
        // No image found, so insert the image.
        db_insert('dynamic_background_views')
          ->fields(array('view_id' => $view_id,
                         'data' => $image_id))
          ->execute();
      }
    }
    else {
      // No image passe, so delete the one in the database, id it's there.
      db_delete('dynamic_background_views')
        ->condition('view_id', $view_id)
        ->execute();
    }
  }
}

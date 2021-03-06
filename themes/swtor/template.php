<?php

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('swtor_rebuild_registry')) {
  system_rebuild_theme_data();
}

/**
 * Implements hook_preprocess_html().
 *
 * Add condication stylesheets for IE.
 */
function swtor_preprocess_html(&$vars) {
  // Add conditional CSS for IE9 and below.
  drupal_add_css(path_to_theme() . '/styles/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 9', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));

  // Add tor tooltip javascript.
  drupal_add_js('http://tor.zamimg.com/tooltips.js', 'external');  
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Remove openid form login block and style the reset.
 */
function swtor_form_user_login_block_alter(&$form, &$form_state, $form_id) {  
  // Unset open-id elements and default links.
  unset($form['links']);
  unset($form['openid_links']);
  unset($form['openid_identifier']);
  unset($form['openid.return_to']);
  
  // Add forgot password link to pass title.
  $form['pass']['#title'] = t('Password') . ' (<a href="/user/password" title="' . t('Forgot it?') .'" tabindex="3">' . t('Forgot it?') . '</a>)';

  // Add class to the login button and move actions into the right place.
$form['actions']['submit']['#attributes'] = array('class' => array('btn yellow'));
  $form['actions']['#weight'] = 5;

  // New user
  if (variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL)) {
    $form['signup'] = array(
      '#markup' => '<div class="new-user"><span>' . t('New user?') . '</span>' . l(t('Create user!'), 'user/register', array('attributes' => array('id' => 'create-new-account', 'title' => t('Create a new user account.')))). '</div>',
      '#weight' => 10,
    );
  }
}

/**
 * Helper function that creates views preprocess functions foreach view.
 */
function swtor_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'swtor_preprocess_views_view__'.$vars['view']->name; 
    if (function_exists($function)) {
     $function($vars);
    }
  }
}

/**
 * Implementation of hook_preprocess_panels_pane().
 *
 * This function create templets suggestions for panels panes. e.g
 * panels-pane--featured-content.tpl.php or at panel level
 * panels-pane--top-right.tpl.php.
 */
function swtor_preprocess_panels_pane(&$vars) {
  // Suggestions base on sub-type.
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . str_replace('-', '__', $vars['pane']->subtype);

  // Suggestions on panel level
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $vars['pane']->panel;
}

/**
 * Helper function that builds the HTML for twitter buttons in views lists.
 */
function swtor_build_tweet_button($nid, $title, $name, $type) {
  drupal_add_js('http://platform.twitter.com/widgets.js');

  $token_replacements = array(
    '!title'        => $title,
    '!author_name'  => $name,
    '!node_type'    => $type,
    '!node_url'     => url('node/'.$nid, array('absolute' => TRUE)),
  );

  return theme('tweetbutton_display', array('tokens' => $token_replacements));
}

/**
 * Implements hook_preprocess_views_view_field().
 * We use this hook to implement facebook like buttons in views lists on the
 * front page of the site.
 */
function swtor_preprocess_views_view_field(&$vars) {
  $view = $vars['view'];
  $field = $vars['field'];
  // In the media_detail view, replace nid field with a fb like button
  if (module_exists('fb_social') && ($view->name == 'frontpage' || $view->name == 'taxonomy_tags_listing') && $field->field == 'nid') {
    // Create a "pseudo-node" object to send to fb_social_like_link
    $row = $vars['row'];
    $pnode = new stdClass();
    $pnode->status = 1;
    $pnode->type = $row->node_type;
    $pnode->nid = $row->nid;
    fb_social_fb_plugin_load('like');
    $preset = fb_social_preset_load('swtor_like');
    $link = fb_social_like_link($preset, 'node', $pnode);
    $vars['output'] = $link['fb_social_like_swtor_like']['title'];

    // Add tweet button.
    $vars['output'] .= swtor_build_tweet_button($row->nid, $row->node_title, 'swtordk', $row->node_type);
  }
}

/**
 * Implements hook_breadcrumb().
 *
 * Remove the current page title from the breadcrumb.
 */
function swtor_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];

    // Build breadcrumb.
  if (!empty($breadcrumb)) {
    $path = drupal_get_path_alias();

    // Add breadcrumb for news subjects.
    if (preg_match('/^artikler\/+/', $path)) {
      $breadcrumb[] = l(t('Articles'), 'artikler');
    }

    // Add current page title to the end of the breadcrumb.
    if ($title = drupal_get_title()) {
      $breadcrumb[] = '<span>' . $title . '</span>';
    }

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= implode(' / ', $breadcrumb);
  }

  return $output;
}

/**
 * Theme function to display a link, optionally buttonized.
 */
function swtor_advanced_forum_l(&$variables) {
  $text = $variables['text'];
  $path = empty($variables['path']) ? NULL : $variables['path'];
  $options = empty($variables['options']) ? array() : $variables['options'];
  $button_class = 'btn';

  $l = '';
  if (!isset($options['attributes'])) {
    $options['attributes'] = array();
  }
  if (!is_null($button_class)) {
    // Buttonized link: add our button class and the span.
    if (!isset($options['attributes']['class'])) {
      $options['attributes']['class'] = array("button");
    }
    else {
      $options['attributes']['class'][] = "btn";
    }
    $options['html'] = TRUE;
    $l = l('<span>' . $text . '</span>', $path, $options);
  }
  else {
    // Standard link: just send it through l().
    $l = l($text, $path, $options);
  }

  return $l;
}

/**
 * Theme function to format the reply link at the top/bottom of topic.
 */
function swtor_advanced_forum_reply_link(&$variables) {
  $node = $variables['node'];

  // Get the information about whether the user can reply and the link to do
  // so if the user is allowed to.
  $reply_link = advanced_forum_get_reply_link($node);

  if (is_array($reply_link)) {
    // Reply is allowed. Variable contains the link information.
    $output = '<div class="topic-reply-allowed">';
    $output .= theme('advanced_forum_l', array(
      'text' => $reply_link['title'],
      'path' => $reply_link['href'],
      'options' => $reply_link['options'],
      'button_class' => 'btn'
        ));
    $output .= '</div>';
    return $output;
  }
  elseif ($reply_link == 'reply-locked') {
    // @TODO: The double span here is icky but I don't know how else to get
    // around the fact that there's no "a" to put the button class on.
    return '<div class="topic-reply-locked"><span class="btn danger"><span>' . t('Topic locked') . '</span></span></div>';
  }
  elseif ($reply_link == 'reply-forbidden') {
    // User is not allowed to reply to this topic.
    return theme('comment_post_forbidden', array('node' => $node));
  }
}

/**
 * Implements hook_pathauto_alias_alter().
 */
function swtor_pathauto_alias_alter(&$alias, array &$context) {
  // Force all aliases to be saved as language neutral.
  $context['language'] = LANGUAGE_NONE;
}

/**
 * Add user picture to forum posts.
 */
function swtor_advanced_forum_simple_author_pane(&$variables) {
  $context = $variables['context'];
  // Sending the context rather than the account makes it work for anon comments.
  $name = theme('username', array('account' => $context));
  $account = user_load($context->uid);

  $uri = '';
  if (isset($account->field_user_picture['und'][0]['uri'])) {
    $uri = $account->field_user_picture['und'][0]['uri'];
    $image = array(
      'style_name' => 'user_picture',
      'path' => $uri,
      'attributes' => array('class' => 'picture'),
    );
    $picture = theme('image_style', $image);
  }
  else {
    $picture = '<img class="picture" width="45" height="45" alt="" src="/' . drupal_get_path('theme', 'swtor') . '/images/user-default.png' . '" typeof="foaf:Image">';
  }
  return '<div class="author-pane">' . $name . $picture . '</div>';
}
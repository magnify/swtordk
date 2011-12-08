<?php
/**
 * @file
 * swtor_external_news_import.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function swtor_external_news_import_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'external_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'External news';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'External news';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Source URL */
  $handler->display->display_options['fields']['field_source_url']['id'] = 'field_source_url';
  $handler->display->display_options['fields']['field_source_url']['table'] = 'field_data_field_source_url';
  $handler->display->display_options['fields']['field_source_url']['field'] = 'field_source_url';
  $handler->display->display_options['fields']['field_source_url']['label'] = '';
  $handler->display->display_options['fields']['field_source_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_source_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_source_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_source_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_source_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_source_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_source_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_source_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_source_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_source_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_source_url']['field_api_classes'] = 0;
  /* Field: Content: Image URL */
  $handler->display->display_options['fields']['field_image_url']['id'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['table'] = 'field_data_field_image_url';
  $handler->display->display_options['fields']['field_image_url']['field'] = 'field_image_url';
  $handler->display->display_options['fields']['field_image_url']['label'] = '';
  $handler->display->display_options['fields']['field_image_url']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_image_url']['alter']['text'] = '<img src="[field_image_url]" />';
  $handler->display->display_options['fields']['field_image_url']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_image_url']['alter']['path'] = '[field_source_url]';
  $handler->display->display_options['fields']['field_image_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_image_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['rel'] = 'external';
  $handler->display->display_options['fields']['field_image_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image_url']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_source_url]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 1;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['rel'] = 'external';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_news_teaser']['id'] = 'field_news_teaser';
  $handler->display->display_options['fields']['field_news_teaser']['table'] = 'field_data_field_news_teaser';
  $handler->display->display_options['fields']['field_news_teaser']['field'] = 'field_news_teaser';
  $handler->display->display_options['fields']['field_news_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_news_teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['max_length'] = '35';
  $handler->display->display_options['fields']['field_news_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_news_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_news_teaser']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd. M Y H:i';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'external_news' => 'external_news',
  );

  /* Display: Extenal news block */
  $handler = $view->new_display('block', 'Extenal news block', 'block');

  /* Display: External news pane */
  $handler = $view->new_display('panel_pane', 'External news pane', 'external_news_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nyheder fra SWTOR.COM';
  $handler->display->display_options['pane_title'] = 'External news';
  $handler->display->display_options['pane_category']['name'] = 'News panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['external_news'] = $view;

  return $export;
}

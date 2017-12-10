<?php
/**
 * @file
 * affiliate_marquee.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function affiliate_marquee_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rotating_marquee';
  $view->description = 'Displays a rotating marquee of marquee content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rotating Marquee';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'slides';
  $handler->display->display_options['style_options']['wrapper_class'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => 'marquee',
    'image_link' => '',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_link_website_1']['id'] = 'field_link_website_1';
  $handler->display->display_options['fields']['field_link_website_1']['table'] = 'field_data_field_link_website';
  $handler->display->display_options['fields']['field_link_website_1']['field'] = 'field_link_website';
  $handler->display->display_options['fields']['field_link_website_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_website_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_website_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_website_1']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_link_website_1]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_link_website']['id'] = 'field_link_website';
  $handler->display->display_options['fields']['field_link_website']['table'] = 'field_data_field_link_website';
  $handler->display->display_options['fields']['field_link_website']['field'] = 'field_link_website';
  $handler->display->display_options['fields']['field_link_website']['label'] = '';
  $handler->display->display_options['fields']['field_link_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_website']['click_sort_column'] = 'url';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="caption-content">
<h3>[title]</h3>
[body]
</div>
<div class="link-wrapper">[field_link_website]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'caption';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'marquee_content' => 'marquee_content',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Rotating Marquee';
  $export['rotating_marquee'] = $view;

  return $export;
}

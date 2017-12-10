<?php
/**
 * @file
 * affiliate_blog.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function affiliate_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_blog_series',
        1 => 'post_date',
        2 => 'field_author',
        3 => 'conditional_preview_image',
        4 => 'body',
        5 => 'field_tags',
        6 => 'share_this',
        7 => 'group_post_utilities',
        8 => 'links',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'field_blog_series' => 'ds_content',
      'post_date' => 'ds_content',
      'field_author' => 'ds_content',
      'conditional_preview_image' => 'ds_content',
      'body' => 'ds_content',
      'field_tags' => 'ds_content',
      'share_this' => 'ds_content',
      'group_post_utilities' => 'ds_content',
      'links' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|blog_post|full'] = $ds_layout;

  return $export;
}

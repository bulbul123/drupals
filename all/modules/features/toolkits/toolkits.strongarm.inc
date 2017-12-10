<?php
/**
 * @file
 * toolkits.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function toolkits_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_allowed_types';
  $strongarm->value = array(
    0 => 'toolkit',
    1 => 'toolkit_page',
  );
  $export['book_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_block_mode';
  $strongarm->value = 'book pages';
  $export['book_block_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_child_type';
  $strongarm->value = 'toolkit_page';
  $export['book_child_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_toolkit';
  $strongarm->value = '0';
  $export['comment_anonymous_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_toolkit_collaborator';
  $strongarm->value = 0;
  $export['comment_anonymous_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_toolkit_page';
  $strongarm->value = 0;
  $export['comment_anonymous_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_toolkit_resource';
  $strongarm->value = 0;
  $export['comment_anonymous_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_webform';
  $strongarm->value = 0;
  $export['comment_anonymous_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_toolkit';
  $strongarm->value = 1;
  $export['comment_default_mode_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_toolkit_collaborator';
  $strongarm->value = 1;
  $export['comment_default_mode_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_toolkit_page';
  $strongarm->value = 1;
  $export['comment_default_mode_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_toolkit_resource';
  $strongarm->value = 1;
  $export['comment_default_mode_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_webform';
  $strongarm->value = 1;
  $export['comment_default_mode_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_toolkit';
  $strongarm->value = '50';
  $export['comment_default_per_page_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_toolkit_collaborator';
  $strongarm->value = '50';
  $export['comment_default_per_page_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_toolkit_page';
  $strongarm->value = '50';
  $export['comment_default_per_page_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_toolkit_resource';
  $strongarm->value = '50';
  $export['comment_default_per_page_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_webform';
  $strongarm->value = '50';
  $export['comment_default_per_page_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_toolkit';
  $strongarm->value = 1;
  $export['comment_form_location_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_toolkit_collaborator';
  $strongarm->value = 1;
  $export['comment_form_location_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_toolkit_page';
  $strongarm->value = 1;
  $export['comment_form_location_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_toolkit_resource';
  $strongarm->value = 1;
  $export['comment_form_location_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_webform';
  $strongarm->value = 1;
  $export['comment_form_location_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_toolkit';
  $strongarm->value = '1';
  $export['comment_preview_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_toolkit_collaborator';
  $strongarm->value = '1';
  $export['comment_preview_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_toolkit_page';
  $strongarm->value = '1';
  $export['comment_preview_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_toolkit_resource';
  $strongarm->value = '1';
  $export['comment_preview_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_webform';
  $strongarm->value = '1';
  $export['comment_preview_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_toolkit';
  $strongarm->value = 1;
  $export['comment_subject_field_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_toolkit_collaborator';
  $strongarm->value = 1;
  $export['comment_subject_field_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_toolkit_page';
  $strongarm->value = 1;
  $export['comment_subject_field_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_toolkit_resource';
  $strongarm->value = 1;
  $export['comment_subject_field_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_webform';
  $strongarm->value = 1;
  $export['comment_subject_field_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_toolkit';
  $strongarm->value = '1';
  $export['comment_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_toolkit_collaborator';
  $strongarm->value = '1';
  $export['comment_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_toolkit_page';
  $strongarm->value = '1';
  $export['comment_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_toolkit_resource';
  $strongarm->value = '1';
  $export['comment_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_webform';
  $strongarm->value = '1';
  $export['comment_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_id_arg_pass_id_fields';
  $strongarm->value = array(
    'product_testimonials_block' => 'product_testimonials_block',
    'product_tour_screenshots' => 'product_tour_screenshots',
    'conditional_preview_image' => 'conditional_preview_image',
    'toolkit_page_resources' => 'toolkit_page_resources',
    'toolkit_pages' => 'toolkit_pages',
    'toolkit_page_pages' => 'toolkit_page_pages',
    'toolkit_page_pages_sitemap' => 'toolkit_page_pages_sitemap',
    'new' => 'new',
  );
  $export['ds_id_arg_pass_id_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__toolkit';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => TRUE,
      ),
      'table_of_contents' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'author_preview' => array(
        'custom_settings' => FALSE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'simplified_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'sitemap' => array(
        'custom_settings' => FALSE,
      ),
      'carousel_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'resource_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'epub_export' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'topics_blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'country_toolkit_teaser' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__toolkit_collaborator';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'author_preview' => array(
        'custom_settings' => FALSE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'carousel_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'resource_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'simplified_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'sitemap' => array(
        'custom_settings' => FALSE,
      ),
      'table_of_contents' => array(
        'custom_settings' => FALSE,
      ),
      'epub_export' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__toolkit_page';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'author_preview' => array(
        'custom_settings' => FALSE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'simplified_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'table_of_contents' => array(
        'custom_settings' => TRUE,
      ),
      'sitemap' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'epub_export' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__toolkit_resource';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'author_preview' => array(
        'custom_settings' => FALSE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'simplified_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'table_of_contents' => array(
        'custom_settings' => FALSE,
      ),
      'sitemap' => array(
        'custom_settings' => FALSE,
      ),
      'resource_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'epub_export' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__webform';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'author_preview' => array(
        'custom_settings' => FALSE,
      ),
      'blog_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'simplified_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'table_of_contents' => array(
        'custom_settings' => FALSE,
      ),
      'carousel_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'resource_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'sitemap' => array(
        'custom_settings' => FALSE,
      ),
      'epub_export' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '24',
            'visible' => TRUE,
          ),
          'epub_export' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_admin_title';
  $strongarm->value = '';
  $export['menu_block_10_admin_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_depth';
  $strongarm->value = '1';
  $export['menu_block_10_depth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_expanded';
  $strongarm->value = 0;
  $export['menu_block_10_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_follow';
  $strongarm->value = 0;
  $export['menu_block_10_follow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_level';
  $strongarm->value = '1';
  $export['menu_block_10_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_parent';
  $strongarm->value = 'menu-toolkit-action-menu:0';
  $export['menu_block_10_parent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_sort';
  $strongarm->value = 0;
  $export['menu_block_10_sort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_10_title_link';
  $strongarm->value = 0;
  $export['menu_block_10_title_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
    2 => 3,
    3 => 4,
    4 => 5,
    5 => 6,
    6 => 7,
    7 => 8,
    8 => 9,
    9 => 10,
  );
  $export['menu_block_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_toolkit';
  $strongarm->value = array();
  $export['menu_options_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_toolkit_collaborator';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_toolkit_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_toolkit_resource';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_webform';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_toolkit';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_toolkit_collaborator';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_toolkit_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_toolkit_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_webform';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_toolkit';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_toolkit_collaborator';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_toolkit_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_toolkit_resource';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_webform';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_toolkit';
  $strongarm->value = '1';
  $export['node_preview_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_toolkit_collaborator';
  $strongarm->value = '1';
  $export['node_preview_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_toolkit_page';
  $strongarm->value = '1';
  $export['node_preview_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_toolkit_resource';
  $strongarm->value = '1';
  $export['node_preview_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_webform';
  $strongarm->value = '1';
  $export['node_preview_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_toolkit';
  $strongarm->value = 0;
  $export['node_submitted_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_toolkit_collaborator';
  $strongarm->value = 0;
  $export['node_submitted_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_toolkit_page';
  $strongarm->value = 0;
  $export['node_submitted_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_toolkit_resource';
  $strongarm->value = 0;
  $export['node_submitted_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_webform';
  $strongarm->value = 0;
  $export['node_submitted_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_blocks';
  $strongarm->value = array(
    0 => (object) array(
      'id' => '12',
      'title' => 'All toolkit resources',
      'description' => '',
      'class' => 'OgBlocksGroupMembersByContentType',
      'content_type' => 'toolkit_resource',
      'view' => 'all_toolkit_resources:page',
      'hash' => '0dc5d855c9afe69cef4580e7193d9978',
    ),
    1 => (object) array(
      'id' => '8',
      'title' => 'Collaborators',
      'description' => '',
      'class' => 'OgBlocksGroupMembersByContentType',
      'content_type' => 'toolkit_collaborator',
      'view' => 'toolkit_collaborators:block',
      'hash' => 'ab4d196d7c6b2f8e00f5c5a78768fdc1',
    ),
    2 => (object) array(
      'id' => '10',
      'title' => 'Toolkit Radioactivity',
      'description' => '',
      'class' => 'OgBlocksGroupMembersByContentType',
      'content_type' => 'toolkit_resource',
      'view' => 'toolkit_resource_activity:block',
      'hash' => '9ee02014ea9ccde82d82a7033164eaa5',
    ),
    3 => (object) array(
      'id' => '11',
      'title' => 'Toolkit Sidebar',
      'description' => '',
      'class' => 'OgBlocksGroupMembersByContentType',
      'content_type' => 'toolkit',
      'view' => 'toolkit_sidebar_for_pages:block',
      'hash' => 'c1ff9f69ceea717a7c5cda4a3385bc01',
    ),
    4 => (object) array(
      'id' => '9',
      'title' => 'What\'s New',
      'description' => '',
      'class' => 'OgBlocksGroupMembersByContentType',
      'content_type' => 'toolkit_resource',
      'view' => 'whats_new_toolkit_resources_:block',
      'hash' => 'd21456ed0bb8f4c59b4f32f3c8defd42',
    ),
  );
  $export['og_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_toolkit_collaborator';
  $strongarm->value = 'omitted';
  $export['og_group_type_toolkit_collaborator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_toolkit_page';
  $strongarm->value = 'omitted';
  $export['og_group_type_toolkit_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_toolkit_resource';
  $strongarm->value = 'omitted';
  $export['og_group_type_toolkit_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_webform';
  $strongarm->value = 'omitted';
  $export['og_group_type_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_toolkit_collaborator_pattern';
  $strongarm->value = 'toolkits/[node:book:root:title]/collaborator/[node:title]';
  $export['pathauto_node_toolkit_collaborator_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_toolkit_page_pattern';
  $strongarm->value = '[node:group-path]/[node:title]';
  $export['pathauto_node_toolkit_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_toolkit_pattern';
  $strongarm->value = 'toolkits/[node:title]';
  $export['pathauto_node_toolkit_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_toolkit_resource_pattern';
  $strongarm->value = '[node:group-path]/[node:title]';
  $export['pathauto_node_toolkit_resource_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_webform_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_webform_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_language_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_language_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_toolkis_featured_display_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_toolkis_featured_display_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_toolkis_popular_display_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_toolkis_popular_display_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_toolkits_new_display_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_toolkits_new_display_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_toolkits_sponsors_list_display_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_toolkits_sponsors_list_display_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_toolkit_topics_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_toolkit_topics_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'toolkits_contents_block_toolkits_intro';
  $strongarm->value = 'Practical collections of trusted public health resources, chosen by experts, arranged for easy use. <br><font size="-1">Are Toolkits helping you? <a href="mailto:toolkits@k4health.org"><font color="FFFFFF">Tell us how!</font> </font>';
  $export['toolkits_contents_block_toolkits_intro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'toolkits_contents_block_toolkits_order_cd';
  $strongarm->value = '<p>K4Health offers an offline version of toolkits on CD-ROM to people working in developing countries with limited Internet access.</p>
<p><a class="more" href="/offline-toolkit-order-form">Order Now</a></p>
';
  $export['toolkits_contents_block_toolkits_order_cd'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'toolkits_contents_block_toolkits_subscribe';
  $strongarm->value = '<p>Claritas est etiam processus dynamicus, qui sequitur mutationem consuetudium lectorum. Mirum est notare quam littera gothica, quam nunc putamus parum claram, anteposuerit litterarum formas humanitatis per seacula quarta decima et quinta decima</p>
<p class="overlay-red"><a class="button-go button pill-large" href="/toolkits/subscribe">Subscribe</a></p>
';
  $export['toolkits_contents_block_toolkits_subscribe'] = $strongarm;

  return $export;
}

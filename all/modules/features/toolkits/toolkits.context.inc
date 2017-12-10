<?php
/**
 * @file
 * toolkits.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function toolkits_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_navigation';
  $context->description = '';
  $context->tag = 'global';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~toolkit_section' => '~toolkit_section',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-7' => array(
          'module' => 'menu_block',
          'delta' => '7',
          'region' => 'utility',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-10',
        ),
        'translate_this-button' => array(
          'module' => 'translate_this',
          'delta' => 'button',
          'region' => 'header',
          'weight' => '-9',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'menu_block-4' => array(
          'module' => 'menu_block',
          'delta' => '4',
          'region' => 'footer',
          'weight' => '-13',
        ),
        'menu-devel' => array(
          'module' => 'menu',
          'delta' => 'devel',
          'region' => 'admin_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('global');
  $export['global_navigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit';
  $context->description = 'Toolkits, toolkit pages, toolkit resources';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'toolkit' => 'toolkit',
        'toolkit_page' => 'toolkit_page',
        'toolkit_resource' => 'toolkit_resource',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'toolkits/*/feedback' => 'toolkits/*/feedback',
        'toolkits/*/about' => 'toolkits/*/about',
        'toolkits/*/resources' => 'toolkits/*/resources',
        'search/toolkit/*' => 'search/toolkit/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_breadcrumb_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_breadcrumb_block',
          'region' => 'breadcrumb',
          'weight' => '-10',
        ),
        'toolkits_contents_block-toolkits_contents_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_contents_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'book-navigation' => array(
          'module' => 'book',
          'delta' => 'navigation',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'toolkits_contents_block-toolkits_print_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_print_block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-toolkit_sidebar_for_pages-block' => array(
          'module' => 'views',
          'delta' => 'toolkit_sidebar_for_pages-block',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Toolkits, toolkit pages, toolkit resources');
  t('type');
  $export['toolkit'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_about';
  $context->description = '';
  $context->tag = 'type';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits/*/about' => 'toolkits/*/about',
        'toolkits/*/feedback' => 'toolkits/*/feedback',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_contents_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_contents_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'book-navigation' => array(
          'module' => 'book',
          'delta' => 'navigation',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'toolkits_search_block-toolkits_search_block' => array(
          'module' => 'toolkits_search_block',
          'delta' => 'toolkits_search_block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'toolkits_contents_block-toolkits_print_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_print_block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('type');
  $export['toolkit_about'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_all_resources';
  $context->description = '';
  $context->tag = 'path';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits/*/resources' => 'toolkits/*/resources',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_admin_menu' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_admin_menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('path');
  $export['toolkit_all_resources'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_only';
  $context->description = '';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'toolkit' => 'toolkit',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_admin_menu' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_admin_menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'views-toolkit_header_image-block' => array(
          'module' => 'views',
          'delta' => 'toolkit_header_image-block',
          'region' => 'featured',
          'weight' => '-9',
        ),
        'toolkits_contents_block-toolkit_updated' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkit_updated',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('type');
  $export['toolkit_only'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_page';
  $context->description = '';
  $context->tag = 'type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'toolkit_page' => 'toolkit_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_breadcrumb_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_breadcrumb_block',
          'region' => 'breadcrumb',
          'weight' => '-10',
        ),
        'toolkits_contents_block-toolkits_admin_menu' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_admin_menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'toolkits_contents_block-toolkits_resource_count' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_resource_count',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-toolkit_page_resources-block' => array(
          'module' => 'views',
          'delta' => 'toolkit_page_resources-block',
          'region' => 'content',
          'weight' => '40',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('type');
  $export['toolkit_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_resource';
  $context->description = 'Add admin menu to toolkit resources';
  $context->tag = 'path';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits/*/resource/*' => 'toolkits/*/resource/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_admin_menu' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_admin_menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add admin menu to toolkit resources');
  t('path');
  $export['toolkit_resource'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit_section';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits' => 'toolkits',
        'toolkits/*' => 'toolkits/*',
        'search/toolkit/*' => 'search/toolkit/*',
        'search/toolkits/*' => 'search/toolkits/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-7' => array(
          'module' => 'menu_block',
          'delta' => '7',
          'region' => 'utility',
          'weight' => '-8',
        ),
        'toolkits_search_block-toolkits_search_all_block' => array(
          'module' => 'toolkits_search_block',
          'delta' => 'toolkits_search_all_block',
          'region' => 'header',
          'weight' => '-72',
        ),
        'translate_this-button' => array(
          'module' => 'translate_this',
          'delta' => 'button',
          'region' => 'header',
          'weight' => '-71',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'navigation',
          'weight' => '-9',
        ),
        'toolkits_contents_block-toolkits_breadcrumb_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_breadcrumb_block',
          'region' => 'breadcrumb',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['toolkit_section'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_add_user';
  $context->description = 'Adds context for toolkit add user in collaborate admin area';
  $context->tag = 'toolkits';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'group/node/*/admin/people/add-user' => 'group/node/*/admin/people/add-user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_permissions-tk-add-user' => array(
          'module' => 'toolkits_permissions',
          'delta' => 'tk-add-user',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds context for toolkit add user in collaborate admin area');
  t('toolkits');
  $export['toolkits_add_user'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_featured_center';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        856 => 856,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-2c5804a45e6b244dfc4e3238903202ac' => array(
          'module' => 'views',
          'delta' => '2c5804a45e6b244dfc4e3238903202ac',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_featured_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_featured_left';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        855 => 855,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-2c5804a45e6b244dfc4e3238903202ac' => array(
          'module' => 'views',
          'delta' => '2c5804a45e6b244dfc4e3238903202ac',
          'region' => 'content',
          'weight' => '76',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_featured_left'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_featured_right';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        857 => 857,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-2c5804a45e6b244dfc4e3238903202ac' => array(
          'module' => 'views',
          'delta' => '2c5804a45e6b244dfc4e3238903202ac',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_featured_right'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_new_center';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        862 => 862,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_9' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_9',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_new_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_new_left';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        861 => 861,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_9' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_9',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_new_left'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_new_right';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        863 => 863,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_9' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_9',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_new_right'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_popular_center';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        859 => 859,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_10' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_10',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_popular_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_popular_left';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        858 => 858,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_10' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_10',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_popular_left'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_popular_right';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        860 => 860,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_10' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_10',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_popular_right'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_sponsors_list_center';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        865 => 865,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_8' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_8',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_sponsors_list_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_sponsors_list_left';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        864 => 864,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_8' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_8',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_sponsors_list_left'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_sponsors_list_right';
  $context->description = '';
  $context->tag = 'toolkitsdashboard';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        866 => 866,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'og_blocks-og_blocks_8' => array(
          'module' => 'og_blocks',
          'delta' => 'og_blocks_8',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('toolkitsdashboard');
  $export['toolkits_sponsors_list_right'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_subscribe';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits/subscribe' => 'toolkits/subscribe',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'toolkits_contents_block-toolkits_rss_block' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_rss_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'node/5511',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['toolkits_subscribe'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkits_topics';
  $context->description = 'Toolkits topics taxonomy page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits/topics/*' => 'toolkits/topics/*',
        'toolkits/all' => 'toolkits/all',
        'toolkits/archive' => 'toolkits/archive',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-toolkit_topics-block' => array(
          'module' => 'views',
          'delta' => 'toolkit_topics-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'toolkits_contents_block-toolkits_archive' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_archive',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Toolkits topics taxonomy page');
  t('page');
  $export['toolkits_topics'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkts_landing';
  $context->description = 'Main toolkits landing page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'toolkits' => 'toolkits',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-nodequeue_10-block' => array(
          'module' => 'views',
          'delta' => 'nodequeue_10-block',
          'region' => 'featured',
          'weight' => '-74',
        ),
        'toolkits_contents_block-toolkits_intro_text' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_intro_text',
          'region' => 'featured',
          'weight' => '-73',
        ),
        'views-all_toolkits-block_1' => array(
          'module' => 'views',
          'delta' => 'all_toolkits-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'toolkits_contents_block-toolkits_archive' => array(
          'module' => 'toolkits_contents_block',
          'delta' => 'toolkits_archive',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main toolkits landing page');
  t('page');
  $export['toolkts_landing'] = $context;

  return $export;
}

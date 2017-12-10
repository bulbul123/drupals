<?php
/**
 * @file
 * affiliate_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function affiliate_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'attached_files';
  $context->description = 'Display a sidebar block with attached files';
  $context->tag = 'global';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'author_profile' => 'author_profile',
        'blog_post' => 'blog_post',
        'image' => 'image',
        'marquee_content' => 'marquee_content',
        'page' => 'page',
        'partner' => 'partner',
        'project' => 'project',
        'resource' => 'resource',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-attached_files-block' => array(
          'module' => 'views',
          'delta' => 'attached_files-block',
          'region' => 'sidebar_first',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display a sidebar block with attached files');
  t('global');
  $export['attached_files'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'base_footer';
  $context->description = 'Adds the footer blocks';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-6' => array(
          'module' => 'block',
          'delta' => 6,
          'region' => 'footer',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the footer blocks');
  t('global');
  $export['base_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'base_search';
  $context->description = 'Adds facets to search page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-10',
        ),
        'facetapi-H8t5HB0FXQR0lyo2OdJ6i9pqGROuNg6r' => array(
          'module' => 'facetapi',
          'delta' => 'H8t5HB0FXQR0lyo2OdJ6i9pqGROuNg6r',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds facets to search page');
  t('page');
  $export['base_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main_content';
  $context->description = 'Main Content Area';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main Content Area');
  t('global');
  $export['main_content'] = $context;

  return $export;
}

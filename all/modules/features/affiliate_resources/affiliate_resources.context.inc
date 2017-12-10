<?php
/**
 * @file
 * affiliate_resources.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function affiliate_resources_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources_default';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'resources' => 'resources',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-resources-block_1' => array(
          'module' => 'views',
          'delta' => 'resources-block_1',
          'region' => 'content',
          'weight' => '-32',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => 9,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['resources_default'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources_menu';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'resources' => 'resources',
        'resources/*' => 'resources/*',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'resources',
    'menu' => 'resources',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['resources_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources_solr';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'resources' => 'resources',
        'resources/*' => 'resources/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr_search_block-apachesolr_search_block' => array(
          'module' => 'apachesolr_search_block',
          'delta' => 'apachesolr_search_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-0MtHWNXs5IJEaK0JOo5kJvtjp14R4s8h' => array(
          'module' => 'facetapi',
          'delta' => '0MtHWNXs5IJEaK0JOo5kJvtjp14R4s8h',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'affiliate_resources_extra-resources_extra_solr_info' => array(
          'module' => 'affiliate_resources_extra',
          'delta' => 'resources_extra_solr_info',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-fkPwnw0MGFWYQ0bmcm4qcDfRurWXL9Sc' => array(
          'module' => 'facetapi',
          'delta' => 'fkPwnw0MGFWYQ0bmcm4qcDfRurWXL9Sc',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['resources_solr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources_solr_only';
  $context->description = 'Context for resources page when search terms or facets are present';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'resources' => 'resources',
        'resources/*' => 'resources/*',
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
          'weight' => '-32',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for resources page when search terms or facets are present');
  t('page');
  $export['resources_solr_only'] = $context;

  return $export;
}

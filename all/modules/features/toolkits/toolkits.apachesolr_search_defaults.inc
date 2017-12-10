<?php
/**
 * @file
 * toolkits.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function toolkits_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'toolkit_search';
  $searcher->label = 'Toolkit Search';
  $searcher->description = '';
  $searcher->search_path = 'search/toolkits';
  $searcher->page_title = 'Toolkits';
  $searcher->env_id = 'acquia_search_server_1';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:(toolkit OR toolkit_page OR toolkit_resource)',
    ),
    'apachesolr_search_custom_enable' => 0,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'browse',
  );
  $export['toolkit_search'] = $searcher;

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'toolkit_specific_search';
  $searcher->label = 'Toolkit Specific Search';
  $searcher->description = '';
  $searcher->search_path = 'search/toolkit/%';
  $searcher->page_title = 'Toolkit Search';
  $searcher->env_id = 'acquia_search_server_1';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:(toolkit OR toolkit_page OR toolkit_resource)',
    ),
    'apachesolr_search_custom_enable' => 0,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'browse',
  );
  $export['toolkit_specific_search'] = $searcher;

  return $export;
}

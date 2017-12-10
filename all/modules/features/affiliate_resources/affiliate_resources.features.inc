<?php
/**
 * @file
 * affiliate_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function affiliate_resources_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function affiliate_resources_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function affiliate_resources_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resources'),
      'base' => 'node_content',
      'description' => t('A resource.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

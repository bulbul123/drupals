<?php
/**
 * @file
 * affiliate_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function affiliate_base_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function affiliate_base_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function affiliate_base_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Country Profile'),
      'base' => 'node_content',
      'description' => t('A country profile.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

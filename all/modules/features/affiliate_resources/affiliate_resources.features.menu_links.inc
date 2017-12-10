<?php
/**
 * @file
 * affiliate_resources.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function affiliate_resources_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:resources
  $menu_links['main-menu:resources'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'resources',
    'router_path' => 'resources',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(
        'title' => 'Publications and resources produced by K4Health',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-41',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Resources');


  return $menu_links;
}

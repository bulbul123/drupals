<?php
/**
 * @file
 * toolkits.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function toolkits_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-toolkit-action-menu:toolkits/support
  $menu_links['menu-toolkit-action-menu:toolkits/support'] = array(
    'menu_name' => 'menu-toolkit-action-menu',
    'link_path' => 'toolkits/support',
    'router_path' => 'toolkits/support',
    'link_title' => 'Create a Toolkit',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create a Toolkit');


  return $menu_links;
}

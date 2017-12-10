<?php
/**
 * @file
 * toolkits.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function toolkits_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-toolkit-action-menu.
  $menus['menu-toolkit-action-menu'] = array(
    'menu_name' => 'menu-toolkit-action-menu',
    'title' => 'Toolkit Action Menu',
    'description' => '',
  );
  // Exported menu: menu-toolkit-menu.
  $menus['menu-toolkit-menu'] = array(
    'menu_name' => 'menu-toolkit-menu',
    'title' => 'Toolkit Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Toolkit Action Menu');
  t('Toolkit Menu');


  return $menus;
}

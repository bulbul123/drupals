<?php
/**
 * @file
 * toolkits.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function toolkits_default_fe_block_settings() {
  $export = array();

  // k4hmain
  $theme = array();

  $theme['block-toolkits_intro'] = array(
    'module' => 'block',
    'theme' => 'k4hmain',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'toolkits_intro',
  );

  $export['k4hmain'] = $theme;

  // seven
  $theme = array();

  $theme['block-toolkits_intro'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
    'machine_name' => 'toolkits_intro',
  );

  $export['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}

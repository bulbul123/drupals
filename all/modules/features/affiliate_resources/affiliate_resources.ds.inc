<?php
/**
 * @file
 * affiliate_resources.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function affiliate_resources_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'multimedia';
  $ds_view_mode->label = 'Multimedia';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['multimedia'] = $ds_view_mode;

  return $export;
}

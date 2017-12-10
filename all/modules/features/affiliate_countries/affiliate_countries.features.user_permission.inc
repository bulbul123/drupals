<?php
/**
 * @file
 * affiliate_countries.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function affiliate_countries_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'content administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}

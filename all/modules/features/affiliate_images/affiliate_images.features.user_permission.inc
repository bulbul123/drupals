<?php
/**
 * @file
 * affiliate_images.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function affiliate_images_user_default_permissions() {
  $permissions = array();

  // Exported permission: create image content.
  $permissions['create image content'] = array(
    'name' => 'create image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content administrator',
      2 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any image content.
  $permissions['delete any image content'] = array(
    'name' => 'delete any image content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own image content.
  $permissions['delete own image content'] = array(
    'name' => 'delete own image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any image content.
  $permissions['edit any image content'] = array(
    'name' => 'edit any image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own image content.
  $permissions['edit own image content'] = array(
    'name' => 'edit own image content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content administrator',
      2 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'content administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}

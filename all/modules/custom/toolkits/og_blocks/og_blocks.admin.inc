<?php

function og_blocks_add_block_form($form, &$form_state) {
  $form['og_block_title'] = array(
    '#type' => 'textfield',
    '#title' => 'Block title',
    '#description' => 'Provide a title for this block when adding it to a context later',
    '#required' => true,
    '#size' => 100
  );
  
  module_load_include('inc', 'og_blocks', 'og_blocks.blocks');
  
  $form['og_block_class'] = array(
    '#type' => 'select',
    '#title' => 'Block class',
    '#options' => og_blocks_get_block_class_options(),
    '#default_value' => 'OgBlocksBasic',
  );
  
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Add Block'),
  );
  
  $form['#submit'] = array('og_blocks_add_block_form_submit');
  return $form;
}

function og_blocks_add_block_form_submit($form, &$form_state) {
  module_load_include('inc', 'og_blocks', 'og_blocks.blocks');
  $class = $form_state['values']['og_block_class'];
  $instance = new $class;
  $instance->title = $form_state['values']['og_block_title'];
  $instance->create();
  $form_state['redirect'] = array('admin/structure/block');
}

/**
 * Menu callback: confirm deletion of og blocks.
 */
function og_blocks_delete($form, &$form_state, $delta = 0) {
  // module_load_include('module', 'og_blocks');
  module_load_include('inc', 'og_blocks', 'og_blocks.blocks');
  $instance = og_blocks_load_block($delta);
  $form['block_title'] = array('#type' => 'hidden', '#value' => $title);
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);

  return confirm_form($form, t('Are you sure you want to delete the "%name" block?', array('%name' => $instance->title)), 'admin/structure/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Deletion of menu blocks.
 */
function og_blocks_delete_submit($form, &$form_state) {
  $delta = $form_state['values']['delta'];
  $block_id = intval(array_pop(explode('_', $delta)));
  db_delete('og_blocks')
    ->condition('id', $block_id, '=')
    ->execute();
  cache_clear_all();
  $form_state['redirect'] = array('admin/structure/block');
}

/**
 * Alters the block admin form to add delete links next to menu blocks.
 */
function _og_blocks_form_block_admin_display_form_alter(&$form, $form_state) {
  foreach ($form['blocks'] as $delta => $block) {
    // see if this block starts with "og_blocks"
    if(substr($delta, 0, 9) != 'og_blocks'){ continue; }
    $form['blocks'][$delta]['delete'] = array(
      '#type' => 'link',
      '#title' => t('delete'),
      '#href' => 'admin/structure/block/delete-og-block/'. $delta
    );
  }
}
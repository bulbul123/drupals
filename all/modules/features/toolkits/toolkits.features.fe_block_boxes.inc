<?php
/**
 * @file
 * toolkits.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function toolkits_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Toolkits Intro';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'toolkits_intro';
  $fe_block_boxes->body = '<p>Practical collections of trusted public health resources, chosen by experts, arrangd for easy use.</p>
';

  $export['toolkits_intro'] = $fe_block_boxes;

  return $export;
}

<?php
/**
 * @file
 * affiliate_marquee.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function affiliate_marquee_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_marquee_content';
  $strongarm->value = 0;
  $export['comment_anonymous_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_marquee_content';
  $strongarm->value = 1;
  $export['comment_default_mode_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_marquee_content';
  $strongarm->value = '50';
  $export['comment_default_per_page_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_marquee_content';
  $strongarm->value = 1;
  $export['comment_form_location_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_marquee_content';
  $strongarm->value = '0';
  $export['comment_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_marquee_content';
  $strongarm->value = '1';
  $export['comment_preview_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_marquee_content';
  $strongarm->value = 1;
  $export['comment_subject_field_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_marquee_content';
  $strongarm->value = array();
  $export['menu_options_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_marquee_content';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_marquee_content';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_marquee_content';
  $strongarm->value = '1';
  $export['node_preview_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_marquee_content';
  $strongarm->value = 0;
  $export['node_submitted_marquee_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_marquee_content_pattern';
  $strongarm->value = 'marquee/[node:title]';
  $export['pathauto_node_marquee_content_pattern'] = $strongarm;

  return $export;
}

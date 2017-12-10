<?php
/**
 * @file
 * Administration function for toolkits_resource_pages module.
 */

/**
 * Default settings form to list publishers that have given their permission to bundle in offline toolkits.
 */
function toolkits_resource_pages_settings() {
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Toolkit settings'),
    '#collapsible' => FALSE,
  );

  $form['settings']['toolkit_resource_teaser_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Toolkit resource teaser length.'),
    '#default_value' => variable_get('toolkit_resource_teaser_length', '150'),
    '#size' => 6,
    '#description' => t('The maximum length (in characters) of the teaser for resources listed on toolkit pages.'),
  );

  $form['settings']['toolkit_teaser_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Toolkit teaser length.'),
    '#default_value' => variable_get('toolkits_teaser_length', '600'),
    '#size' => 6,
    '#description' => t('The maximum length (in characters) of other teasers in toolkits (i.e. toolkit listings and taxonomy pages).'),
  );

  $form['settings']['toolkits_resource_pages_publisher_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label to display above list of publishers (see list below).'),
    '#default_value' => variable_get('toolkits_resource_pages_publisher_label', 'Check if the publisher is among those that have already given consent to bundle resources:'),
    '#size' => 60,
    '#description' => t('This label will display directly above the list of publishers in the toolkit resource node form.'),
  );

  $publishers = _toolkits_resource_pages_default_publishers();

  $form['settings']['toolkits_resource_pages_publishers'] = array(
    '#type' => 'textarea',
    '#title' => t('List publishers that have given permission to bundle their resources in offline Toolkits.'),
    '#default_value' => variable_get('toolkits_resource_pages_publishers', implode("\n", $publishers)),
    '#rows' => 10,
    '#resizable' => TRUE,
    '#maxlength' => 800000,
    '#description' => t('List all publishers that have given their permission to include their resources in our offline Toolkit bundles.'),
  );

  return system_settings_form($form);
}


function toolkits_resource_pages_settings_form_submit($form, &$form_state) {
  // Save form settings.
  system_settings_form_submit($form, $form_state);
}

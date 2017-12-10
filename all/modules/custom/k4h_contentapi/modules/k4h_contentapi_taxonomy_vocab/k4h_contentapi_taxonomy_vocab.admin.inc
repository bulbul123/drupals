<?php

/**
 * @file
 * Admin Form for the k4h_contentapi_taxonomy module
 */

/**
 * Content API Taxonomy management form
 **/
function k4h_contentapi_taxonomy_vocab_admin_form($form_state) {
  $form = array();

  $vocabularies = array();
  $vocabs = taxonomy_get_vocabularies();
  foreach ($vocabs as $vocab) {
    $vocabularies[$vocab->vid] = $vocab->name;
  }

  $form['allowed_vocabularies'] = array(
    '#title' => t('Allowed Vocbaularies'),
    '#description' => t('Choose the Vocabularies you want users to be able to access from the API'),
    '#type' => 'select',
    '#options' => $vocabularies,
    '#multiple' => TRUE,
    '#default_value' => variable_get('k4h_contentapi_taxonomy_vocab_allowed_vocabs', array_keys($vocabularies)),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
} // end function k4h_contentapi_taxonomy_vocab_admin_form

/**
 * Submit function for the admin form
 **/
function k4h_contentapi_taxonomy_vocab_admin_form_submit($form, &$form_state) {
  variable_set('k4h_contentapi_taxonomy_vocab_allowed_vocabs', $form_state['values']['allowed_vocabularies']);
} // end function k4h_contentapi_taxonomy_vocab_admin_form_submit


<?php

/**
 * @file
 * Admin forms for functionality provided by the Security module.
 */

/**
 * Implements hook_form()
 */
function security_content_client_hashing_form($form, $form_state) {
  $form = array();

  $form['security_client_hashing_status'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => array(
      0 => 'Disabled',
      1 => 'Enabled',
    ),
    '#default_value' => variable_get('security_client_hashing_status', 0),
    '#title' => t('Client Side Hashing'),
    '#description' => t('Enabling this will use Javascript to hash passwords before sending them to Drupal. This can greatly increase the security of your login forms but is not a substitute for using an SSL certificate to encrypt traffic.'),
  );

  if (variable_get('security_client_hashing_status', FALSE) || (isset($form_state['values']['security_client_hashing_salt']) && $form_state['values']['security_client_hashing_status'])) {
    $form['security_client_hashing_salt'] = array(
      '#type' => 'textfield',
      '#required' => FALSE,
      '#default_value' => variable_get('security_client_hashing_salt', 'checkthelog'),
      '#title' => t('Client Hashing Salt'),
      '#description' => t('A salt is an additional piece of data used when hashing passwords to provide additional randomness.  The Security module provides a basic salt by default but you can set your own here.'),
    );
    $form['security_client_hashing_key_size'] = array(
      '#type' => 'radios',
      '#required' => TRUE,
      '#options' => array(
        128/32 => '128/32',
        256/32 => '256/32',
        512/32 => '512/32',
      ),
      '#default_value' => variable_get('security_client_hashing_key_size', 128/32),
      '#title' => t('Key Size'),
      '#description' => t('Set the key size here.'),
    );
    $form['security_client_hashing_iterations'] = array(
      '#type' => 'radios',
      '#required' => TRUE,
      '#options' => array(
        250 => '250',
        500 => '500',
        1000 => '1000',
      ),
      '#default_value' => variable_get('security_client_hashing_iterations', 250),
      '#title' => t('Iterations'),
      '#description' => t('Set the number of iterations to use when generating the key.  Note that higher values can slow the user\'s browser down.'),
    );
  }

  $form['#submit'][] = '_security_enable_client_hashing';

  return system_settings_form($form);
}

function _security_enable_client_hashing($form, &$form_state) {
  drupal_set_message(t('Please update your account password.'), 'status');
  $token = drupal_hash_base64(drupal_random_bytes(55));
  $_SESSION['pass_reset_' . $GLOBALS['user']->uid] = $token;
  $form_state['redirect'] = array(
    'user/' . $GLOBALS['user']->uid . '/edit',
    array(
      'query' => array(
        'pass-reset-token' => $token,
      ),
    ),
  );
}

/**
 * Implements hook_form()
 */
function security_content_security_policy_form($form, $form_state) {
  $form = array();

  // Note that this puts the wrapper outside of the block.  See:  http://drupal.org/node/1623514
  $form['#prefix'] = '<div id="security-content-security-policy-form">';
  $form['#suffix'] = '</div>';

  $form['security_content_security_policy_status'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => array(
      0 => 'Disabled',
      1 => 'Enabled',
    ),
    '#default_value' => variable_get('security_content_security_policy_status', 0),
    '#title' => t('Content Security Policy Status'),
  );

  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['security_content_security_policy_additional_js_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Javascript Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'additional_settings',
    'security_restrict_javascript_source_self' => array(
      '#type' => 'checkbox',
      '#title' => t('Javascript Source Restrictions'),
      '#description' => t('Restrict Javascript to just your domain.  This can be expanded with the other sources below.'),
      '#default_value' => variable_get('security_restrict_javascript_source_self', 0),
      '#ajax' => array(
        'callback' => '_security_content_security_policy_update_ajax',
        'wrapper' => 'security-content-security-policy-form',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    ),
    'security_restrict_javascript_source_google_analytics' => array(
      '#type' => 'checkbox',
      '#title' => t('Javascript Allow Google Analytics'),
      '#description' => t('Allow external Javascript from Google Analytics.'),
      '#default_value' => variable_get('security_restrict_javascript_source_google_analytics', 0),
    ),
    'security_restrict_javascript_source_facebook' => array(
      '#type' => 'checkbox',
      '#title' => t('Javascript Allow Facebook'),
      '#description' => t('Allow external Javascript from Facebook.'),
      '#default_value' => variable_get('security_restrict_javascript_source_facebook', 0),
    ),
    'security_restrict_javascript_source_other' => array(
      '#type' => 'checkbox',
      '#title' => t('Javascript Allow Custom'),
      '#description' => t('Enabled a text field to add a custom Javascript source.'),
      '#default_value' => variable_get('security_restrict_javascript_source_other', 0),
      '#ajax' => array(
        'callback' => '_security_content_security_policy_update_ajax',
        'wrapper' => 'security-content-security-policy-form',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    ),
    'security_restrict_javascript_source_other_custom' => array(
      '#type' => 'textfield',
      '#title' => t('Javascript Custom Source'),
      '#description' => t('Enter a custom source to allow javascript from.'),
      '#default_value' => variable_get('security_restrict_javascript_source_other_custom', ''),
    ),
    'security_restrict_javascript_no_inline' => array(
      '#type' => 'checkbox',
      '#title' => t('Disable inline Javascript'),
      '#description' => t('This turns on/off any inline Javascript and instead puts it in a temporary file and serves it to the user.  Minor performance hit.'),
      '#default_value' => variable_get('security_restrict_javascript_no_inline', 1),
    ),
  );

  if (variable_get('security_restrict_javascript_source_self', 0) != 1 && ((isset($form_state['values']['security_restrict_javascript_source_self']) && $form_state['values']['security_restrict_javascript_source_self'] != 1) || !isset($form_state['values']['security_restrict_javascript_source_self']))) {
    $form['security_content_security_policy_additional_js_settings']['security_restrict_javascript_source_google_analytics']['#disabled'] = TRUE;
    $form['security_content_security_policy_additional_js_settings']['security_restrict_javascript_source_facebook']['#disabled'] = TRUE;
    $form['security_content_security_policy_additional_js_settings']['security_restrict_javascript_source_other']['#disabled'] = TRUE;
    $form['security_content_security_policy_additional_js_settings']['security_restrict_javascript_source_other_custom']['#disabled'] = TRUE;
  } elseif (variable_get('security_restrict_javascript_source_other', 0) != 1 && (isset($form_state['values']['security_restrict_javascript_source_other']) && $form_state['values']['security_restrict_javascript_source_other'] != 1)) {
    $form['security_content_security_policy_additional_js_settings']['security_restrict_javascript_source_other_custom']['#disabled'] = TRUE;
  }

  $form['security_content_security_policy_additional_css_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('CSS Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'additional_settings',
    'security_restrict_css_source_self' => array(
      '#type' => 'checkbox',
      '#title' => t('CSS Source Restrictions'),
      '#description' => t('Restrict CSS to just your domain.'),
      '#default_value' => variable_get('security_restrict_css_source_self', 0),
      '#ajax' => array(
        'callback' => '_security_content_security_policy_update_ajax',
        'wrapper' => 'security-content-security-policy-form',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    ),
    'security_restrict_css_source_other' => array(
      '#type' => 'checkbox',
      '#title' => t('CSS Allow Custom'),
      '#description' => t('Allow CSS from a custom domain.'),
      '#default_value' => variable_get('security_restrict_css_source_other', 0),
      '#ajax' => array(
        'callback' => '_security_content_security_policy_update_ajax',
        'wrapper' => 'security-content-security-policy-form',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    ),
    'security_restrict_css_source_other_custom' => array(
      '#type' => 'textfield',
      '#title' => t('CSS Custom Source'),
      '#description' => t('Enter a custom source to allow CSS from.'),
      '#default_value' => variable_get('security_restrict_css_source_other_custom', ''),
    ),
  );

  if (variable_get('security_restrict_css_source_self', 0) == 0 && (isset($form_state['values']['security_restrict_css_source_self']) && $form_state['values']['security_restrict_css_source_self'] == 0)) {
    $form['security_content_security_policy_additional_css_settings']['security_restrict_css_source_other']['#disabled'] = TRUE;
    $form['security_content_security_policy_additional_css_settings']['security_restrict_css_source_other_custom']['#disabled'] = TRUE;
  } elseif (variable_get('security_restrict_css_source_other', 0) == 0 && (isset($form_state['values']['security_restrict_css_source_other']) && $form_state['values']['security_restrict_css_source_other'] != 1)) {
    $form['security_content_security_policy_additional_css_settings']['security_restrict_css_source_other_custom']['#disabled'] = TRUE;
  }

  return system_settings_form($form);
}

/**
 * An AJAX callback for choosing a custom javascript origin
 */
function _security_content_security_policy_update_ajax($form, $form_state) {
  return $form;
}

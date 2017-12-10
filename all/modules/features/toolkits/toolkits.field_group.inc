<?php
/**
 * @file
 * toolkits.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function toolkits_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body|node|toolkit_resource|resource_teaser';
  $field_group->group_name = 'group_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toolkit_resource';
  $field_group->mode = 'resource_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'body',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_toolkit_organization',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'body',
      'instance_settings' => array(
        'classes' => ' group-body field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_toolkit_resource_resource_teaser_group_body',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_body|node|toolkit_resource|resource_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|toolkit_resource|resource_teaser';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toolkit_resource';
  $field_group->mode = 'resource_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Direct Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_toolkit_external_links',
      1 => 'field_toolkit_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Direct Links',
      'instance_settings' => array(
        'classes' => ' group-links field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_links|node|toolkit_resource|resource_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|toolkit_resource|full';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toolkit_resource';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Data',
    'weight' => '36',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meta Data',
      'instance_settings' => array(
        'classes' => 'resource-meta group-meta field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_toolkit_resource_full_group_meta',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_meta|node|toolkit_resource|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|toolkit_resource|resource_teaser';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toolkit_resource';
  $field_group->mode = 'resource_teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Data',
    'weight' => '2',
    'children' => array(
      0 => 'field_toolkit_languages',
      1 => 'field_toolkit_length',
      2 => 'field_toolkit_year',
      3 => 'node_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meta Data',
      'instance_settings' => array(
        'classes' => ' group-meta field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_toolkit_resource_resource_teaser_group_meta',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_meta|node|toolkit_resource|resource_teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_toolkits_landing_blocks|node|toolkit|form';
  $field_group->group_name = 'group_toolkits_landing_blocks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toolkit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Landing Page Blocks',
    'weight' => '16',
    'children' => array(
      0 => 'field_toolkits_featured',
      1 => 'field_toolkits_new',
      2 => 'field_toolkits_popular',
      3 => 'field_toolkits_sponsors_list',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Landing Page Blocks',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-toolkits-landing-blocks field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_toolkits_landing_blocks|node|toolkit|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Direct Links');
  t('Landing Page Blocks');
  t('Meta Data');
  t('body');

  return $field_groups;
}

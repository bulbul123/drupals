<?php
/**
 * @file
 * affiliate_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function affiliate_blog_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author_preview|node|author_profile|author_preview';
  $field_group->group_name = 'group_author_preview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'author_profile';
  $field_group->mode = 'author_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_author_photo',
      1 => 'field_organization_title',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Author Info',
      'instance_settings' => array(
        'classes' => 'contributor-info group-author-preview field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_author_profile_author_preview_group_author_preview',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_author_preview|node|author_profile|author_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|author_profile|full';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'author_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '4',
    'children' => array(
      0 => 'field_link_facebook',
      1 => 'field_link_linkedin',
      2 => 'field_link_twitter',
      3 => 'field_link_website',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'classes' => 'social-links group-links field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_author_profile_full_group_links',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_links|node|author_profile|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|node|author_profile|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'author_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Links',
    'weight' => '8',
    'children' => array(
      0 => 'field_link_facebook',
      1 => 'field_link_linkedin',
      2 => 'field_link_twitter',
      3 => 'field_link_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Links',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-social field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_social|node|author_profile|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author Info');
  t('Links');
  t('Social Links');

  return $field_groups;
}

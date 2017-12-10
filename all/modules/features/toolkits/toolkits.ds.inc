<?php
/**
 * @file
 * toolkits.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function toolkits_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_page|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_page';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'toolkit_page_attached_resources' => array(
      'weight' => '2',
      'label' => 'above',
      'format' => 'default',
    ),
    'toolkit_page_resources' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
    ),
  );
  $export['node|toolkit_page|print'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_page|simplified_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_page';
  $ds_fieldsetting->view_mode = 'simplified_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'teaser-description',
      ),
    ),
  );
  $export['node|toolkit_page|simplified_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_page|sitemap';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_page';
  $ds_fieldsetting->view_mode = 'sitemap';
  $ds_fieldsetting->settings = array(
    'toolkit_page_pages' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
    ),
    'toolkit_page_pages_sitemap' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|toolkit_page|sitemap'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_page|table_of_contents';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_page';
  $ds_fieldsetting->view_mode = 'table_of_contents';
  $ds_fieldsetting->settings = array(
    'toolkit_page_pages' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|toolkit_page|table_of_contents'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'teaser-title',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_reset',
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-name-post-date',
      ),
    ),
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-name-body',
      ),
    ),
  );
  $export['node|toolkit_page|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|toolkit_resource|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_toolkit_author' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Author(s)',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
      ),
    ),
    'field_toolkit_external_links' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'External Links',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-item',
      ),
    ),
    'field_toolkit_files' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'File',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-item',
      ),
    ),
    'field_toolkit_languages' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Languages',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-item',
      ),
    ),
    'field_toolkit_length' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Length',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'span',
        'fi-cl' => 'field-item',
      ),
    ),
    'field_toolkit_organization' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Organization',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label field-name-field-toolkit-organization',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-item',
      ),
    ),
    'field_toolkit_year' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Year',
        'lb-el' => 'div',
        'lb-cl' => 'field-label',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-inline-label',
        'fis' => TRUE,
        'fis-el' => 'div',
        'fis-cl' => 'field-items',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-item',
      ),
    ),
  );
  $export['node|toolkit_resource|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|toolkit_resource|print'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|resource_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'resource_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'teaser-title',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'resource-title',
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => 'more',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_reset',
      ),
    ),
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'teaser-description',
      ),
    ),
    'field_toolkit_external_links' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'li',
        'fi-cl' => '',
      ),
    ),
    'field_toolkit_files' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'li',
        'fi-cl' => '',
      ),
    ),
    'field_toolkit_languages' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'span',
        'fi-cl' => 'separated',
      ),
    ),
    'field_toolkit_length' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'span',
        'fi-cl' => 'separated',
      ),
    ),
    'field_toolkit_organization' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'span',
        'fi-cl' => 'resource-organization separated-pipe',
      ),
    ),
    'field_toolkit_year' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'span',
        'fi-cl' => 'separated',
      ),
    ),
    'group_links' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['node|toolkit_resource|resource_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|simplified_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'simplified_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'title-teaser',
      ),
    ),
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'teaser-description',
      ),
    ),
  );
  $export['node|toolkit_resource|simplified_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit_resource|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit_resource';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'teaser-title',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_reset',
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-name-post-date',
      ),
    ),
    'body' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'field-name-body',
      ),
    ),
    'group_audience' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'field-name-content-type',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'toolkit content-type',
      ),
    ),
  );
  $export['node|toolkit_resource|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit|carousel_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit';
  $ds_fieldsetting->view_mode = 'carousel_teaser';
  $ds_fieldsetting->settings = array(
    'new' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'teaser-title',
      ),
      'ft' => array(
        'func' => 'theme_ds_field_reset',
      ),
    ),
    'field_toolkit_carousel_image' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'carousel-image',
      ),
    ),
  );
  $export['node|toolkit|carousel_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'content_type' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|toolkit|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'toolkit_collaborators_print' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_about' => array(
      'ft' => array(
        'lb' => 'About the Toolkit',
      ),
    ),
  );
  $export['node|toolkit|print'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit|table_of_contents';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit';
  $ds_fieldsetting->view_mode = 'table_of_contents';
  $ds_fieldsetting->settings = array(
    'toolkit_pages' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|toolkit|table_of_contents'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|toolkit|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'toolkit';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'content_type' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'teaser-title',
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|toolkit|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function toolkits_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'new';
  $ds_field->label = 'New';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|node_is_new-block',
    'block_render' => '1',
  );
  $export['new'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_collaborators_print';
  $ds_field->label = 'Toolkit Collaborators Print';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$g_nid = $entity->nid;
if (empty($g_nid)) {
  $g_nid = arg(4);
}
$result = db_query("SELECT ogm.etid FROM og_membership ogm INNER JOIN node n ON ogm.etid = n.nid INNER JOIN og on ogm.gid = og.gid WHERE og.etid = $g_nid AND n.type = \'toolkit_collaborator\'");
$view_args = array();
foreach ($result as $record) {
  $view_args[] = $record->etid;
}
$view_arg = implode(\',\', $view_args);
print \'<div class="block-og-blocks"><h2 class="block-title title-left">Brought to You by</h2>\';
print views_embed_view(\'toolkit_collaborators\', \'block\', $view_arg);
print \'</div>\';
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['toolkit_collaborators_print'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_page_attached_resources';
  $ds_field->label = 'Resources';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print views_embed_view(\'toolkit_page_resources\', \'block_1\', $entity->nid);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['toolkit_page_attached_resources'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_page_pages';
  $ds_field->label = 'Toolkit Page Pages';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|toolkit_page_pages-block',
    'block_render' => '1',
  );
  $export['toolkit_page_pages'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_page_pages_sitemap';
  $ds_field->label = 'Toolkit Page Pages Sitemap';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|2d3de821e6b9b6fb3f078bf80b96fabb',
    'block_render' => '1',
  );
  $export['toolkit_page_pages_sitemap'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_page_resources';
  $ds_field->label = 'Toolkit page resources';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|b0a2a7bda250de285f70a7e5cdf23b66',
    'block_render' => '1',
  );
  $export['toolkit_page_resources'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'toolkit_pages';
  $ds_field->label = 'Toolkit Pages';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|toolkit_pages-block',
    'block_render' => '1',
  );
  $export['toolkit_pages'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function toolkits_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_collaborator|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_collaborator';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_collaborator_image',
      ),
    ),
    'fields' => array(
      'field_collaborator_image' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_collaborator|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_page|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_page';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'toolkit_page_attached_resources',
        2 => 'toolkit_page_resources',
        3 => 'field_toolkit_page_files',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'toolkit_page_attached_resources' => 'ds_content',
      'toolkit_page_resources' => 'ds_content',
      'field_toolkit_page_files' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_page|print'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_page|simplified_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_page';
  $ds_layout->view_mode = 'simplified_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_page|simplified_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_page|sitemap';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_page';
  $ds_layout->view_mode = 'sitemap';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'toolkit_page_pages_sitemap',
        2 => 'toolkit_page_pages',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'toolkit_page_pages_sitemap' => 'ds_content',
      'toolkit_page_pages' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_page|sitemap'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_page|table_of_contents';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_page';
  $ds_layout->view_mode = 'table_of_contents';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'toolkit_page_pages',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'toolkit_page_pages' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_page|table_of_contents'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_page|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_resource|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_resource';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_toolkit_thumbnail',
        1 => 'body',
        2 => 'field_toolkit_files',
        3 => 'field_toolkit_external_links',
        4 => 'field_toolkit_length',
        5 => 'field_toolkit_year',
        6 => 'field_toolkit_organization',
        7 => 'field_toolkit_languages',
        8 => 'field_toolkit_author',
        9 => 'field_toolkit_tags',
      ),
    ),
    'fields' => array(
      'field_toolkit_thumbnail' => 'ds_content',
      'body' => 'ds_content',
      'field_toolkit_files' => 'ds_content',
      'field_toolkit_external_links' => 'ds_content',
      'field_toolkit_length' => 'ds_content',
      'field_toolkit_year' => 'ds_content',
      'field_toolkit_organization' => 'ds_content',
      'field_toolkit_languages' => 'ds_content',
      'field_toolkit_author' => 'ds_content',
      'field_toolkit_tags' => 'ds_content',
    ),
    'classes' => array(),
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|toolkit_resource|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_resource|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_resource';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_toolkit_thumbnail',
        2 => 'body',
        3 => 'field_toolkit_files',
        4 => 'field_toolkit_languages',
        5 => 'field_toolkit_organization',
        6 => 'field_toolkit_author',
        7 => 'field_toolkit_year',
        8 => 'field_toolkit_length',
        9 => 'field_toolkit_external_links',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_toolkit_thumbnail' => 'ds_content',
      'body' => 'ds_content',
      'field_toolkit_files' => 'ds_content',
      'field_toolkit_languages' => 'ds_content',
      'field_toolkit_organization' => 'ds_content',
      'field_toolkit_author' => 'ds_content',
      'field_toolkit_year' => 'ds_content',
      'field_toolkit_length' => 'ds_content',
      'field_toolkit_external_links' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_resource|print'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_resource|resource_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_resource';
  $ds_layout->view_mode = 'resource_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'group_body',
        2 => 'group_meta',
        3 => 'field_toolkit_year',
        4 => 'field_toolkit_external_links',
        5 => 'group_links',
        6 => 'field_toolkit_length',
        7 => 'field_toolkit_files',
        8 => 'field_toolkit_languages',
        9 => 'field_toolkit_organization',
        10 => 'body',
        11 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_body' => 'ds_content',
      'group_meta' => 'ds_content',
      'field_toolkit_year' => 'ds_content',
      'field_toolkit_external_links' => 'ds_content',
      'group_links' => 'ds_content',
      'field_toolkit_length' => 'ds_content',
      'field_toolkit_files' => 'ds_content',
      'field_toolkit_languages' => 'ds_content',
      'field_toolkit_organization' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'limit' => array(
      'field_toolkit_external_links' => '1',
      'field_toolkit_files' => '1',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_resource|resource_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_resource|simplified_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_resource';
  $ds_layout->view_mode = 'simplified_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_resource|simplified_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit_resource|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit_resource';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'group_audience',
        1 => 'post_date',
        2 => 'title',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'group_audience' => 'ds_content',
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit_resource|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit|carousel_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit';
  $ds_layout->view_mode = 'carousel_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'new',
        1 => 'field_toolkit_carousel_image',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'new' => 'ds_content',
      'field_toolkit_carousel_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit|carousel_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'content_type',
        1 => 'post_date',
        2 => 'title',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'content_type' => 'ds_content',
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit|table_of_contents';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit';
  $ds_layout->view_mode = 'table_of_contents';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'toolkit_pages',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'toolkit_pages' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit|table_of_contents'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|toolkit|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'toolkit';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'content_type',
        1 => 'post_date',
        2 => 'title',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'content_type' => 'ds_content',
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|toolkit|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'webform',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'webform' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|webform|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'webform',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'webform' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|webform|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function toolkits_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'carousel_teaser';
  $ds_view_mode->label = 'Carousel Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['carousel_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sitemap';
  $ds_view_mode->label = 'Sitemap';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['sitemap'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'table_of_contents';
  $ds_view_mode->label = 'Table of contents';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['table_of_contents'] = $ds_view_mode;

  return $export;
}

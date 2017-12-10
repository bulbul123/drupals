<?php
/**
 * @file
 * toolkits.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function toolkits_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function toolkits_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function toolkits_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_toolkits
  $nodequeues['featured_toolkits'] = array(
    'name' => 'featured_toolkits',
    'title' => 'Featured Toolkits',
    'subqueue_title' => '',
    'size' => '0',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'insert_at_front' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'toolkit',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function toolkits_image_default_styles() {
  $styles = array();

  // Exported image style: resource-thumbnail.
  $styles['resource-thumbnail'] = array(
    'name' => 'resource-thumbnail',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '108',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'resource-thumbnail',
  );

  // Exported image style: toolkit-carousel.
  $styles['toolkit-carousel'] = array(
    'name' => 'toolkit-carousel',
    'effects' => array(
      14 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '220',
          'height' => '150',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'toolkit-carousel',
  );

  // Exported image style: toolkit-collaborator.
  $styles['toolkit-collaborator'] = array(
    'name' => 'toolkit-collaborator',
    'effects' => array(
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '100',
          'upscale' => 0,
        ),
        'weight' => '-10',
      ),
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '200',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '-9',
      ),
    ),
    'label' => 'toolkit-collaborator',
  );

  // Exported image style: toolkit-featured.
  $styles['toolkit-featured'] = array(
    'name' => 'toolkit-featured',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '804',
          'height' => '280',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'toolkit-featured',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function toolkits_node_info() {
  $items = array(
    'toolkit' => array(
      'name' => t('Toolkit'),
      'base' => 'node_content',
      'description' => t('A toolkit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'toolkit_collaborator' => array(
      'name' => t('Toolkit Collaborator'),
      'base' => 'node_content',
      'description' => t('A collaborator on a toolkit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'toolkit_page' => array(
      'name' => t('Toolkit Page'),
      'base' => 'node_content',
      'description' => t('A page in a toolkit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'toolkit_resource' => array(
      'name' => t('Toolkit Resource'),
      'base' => 'node_content',
      'description' => t('A resource in a toolkit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * affiliate_projects.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function affiliate_projects_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'affiliate_projects';
  $openlayers_maps->title = 'Affiliate Projects';
  $openlayers_maps->description = 'Projects';
  $openlayers_maps->data = array(
    'width' => '320',
    'height' => '250',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'simple_ol_popup' => array(
        'layers' => array(
          'affiliate_projects_openlayers_1' => 'affiliate_projects_openlayers_1',
        ),
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'affiliate_projects_openlayers_1',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'mapbox_world_glass',
    'layers' => array(
      'mapbox_world_glass' => 'mapbox_world_glass',
      'affiliate_projects_openlayers_1' => 'affiliate_projects_openlayers_1',
    ),
    'layer_weight' => array(
      'affiliate_projects_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => 'default',
      'affiliate_projects_openlayers_1' => 'simple-red',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => 'default',
      'affiliate_projects_openlayers_1' => 'simple-red',
    ),
    'layer_activated' => array(
      'affiliate_projects_openlayers_1' => 'affiliate_projects_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'affiliate_projects_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['affiliate_projects'] = $openlayers_maps;

  return $export;
}

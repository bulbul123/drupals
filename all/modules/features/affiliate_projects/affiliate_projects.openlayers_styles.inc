<?php
/**
 * @file
 * affiliate_projects.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function affiliate_projects_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'simple-red';
  $openlayers_styles->title = 'Simple Red';
  $openlayers_styles->description = 'Basic red circle';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#A8384B',
    'strokeWidth' => 5,
    'fillOpacity' => 0,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['simple-red'] = $openlayers_styles;

  return $export;
}

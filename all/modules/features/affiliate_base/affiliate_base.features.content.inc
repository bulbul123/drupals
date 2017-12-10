<?php
/**
 * @file
 * affiliate_base.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function affiliate_base_content_defaults() {
  $content = array();

  $content['front'] = (object) array(
    'exported_path' => 'front',
    'title' => 'Home',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'und',
    'created' => '1326138025',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'front',
    'body' => array(),
  );

  $content['page-not-found'] = (object) array(
    'exported_path' => 'page-not-found',
    'title' => 'Page Not Found',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'und',
    'created' => '1326138025',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'page-not-found',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<p>The requested page could not be found.</p>',
          'summary' => '',
          'format' => 'full_html',
        ),
      ),
    ),
  );

return $content;
}

<?php

/**
 * Implementation of hook_views_query_alter().
 * Alter the toolkits_updates query to filter out resources from non-core toolkits.
 */
function toolkits_misc_views_query_alter(&$view, &$query) {
  if ($view->name == 'toolkits_updates') {
//    $query->table_queue['node']
    $query->tags[] = 'toolkits_updates';
//    dpr($query);
  }
}

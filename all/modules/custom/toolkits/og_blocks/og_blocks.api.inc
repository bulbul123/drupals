<?php
/**
 * Get all nodes in this group
 * 
 * @param int $gid Group ID
 */
function og_blocks_get_group_members($gid) {
  return og_blocks_query_get_group_members($gid)->execute();
}


/**
 * Get members nodes by content type
 * 
 * @param int $gid Group ID
 * @param string $content_type The content type to select
 */
function og_blocks_get_group_members_by_content_type($gid, $content_type) {
  return og_blocks_query_get_group_members($gid)
    ->condition('n.type', $content_type, '=')
    ->condition('ogm.entity_type', 'node', '=')
    ->condition('n.status', 1, '=')
    ->execute();
}

/**
 * Get the query object for finding members of this group
 * 
 * Used by other API calls
 * 
 * @param int $gid Group ID
 */
function og_blocks_query_get_group_members($gid) {
  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid', 'type'))
    ->join('og_membership', 'ogm', 'ogm.gid = :gid AND ogm.etid = n.nid', array(':gid' => $gid));
  return $query;
}

<?php
/**
 * @file
 * affiliate_images.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function affiliate_images_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'affiliate_image_galleries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Affiliate Image Galleries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Representative node */
  $handler->display->display_options['relationships']['tid_representative']['id'] = 'tid_representative';
  $handler->display->display_options['relationships']['tid_representative']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['tid_representative']['field'] = 'tid_representative';
  $handler->display->display_options['relationships']['tid_representative']['required'] = TRUE;
  $handler->display->display_options['relationships']['tid_representative']['subquery_sort'] = 'node.nid';
  $handler->display->display_options['relationships']['tid_representative']['subquery_view'] = '';
  $handler->display->display_options['relationships']['tid_representative']['subquery_namespace'] = '';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['relationship'] = 'tid_representative';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['field_image_file']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_image_file']['alter']['link_class'] = 'image';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image_file']['element_class'] = 'image-holder';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = '<strong> <em> <br> <a>';
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['preserve_tags'] = '<br> <a> <strong> <em>';
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['description']['element_wrapper_class'] = 'caption';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="image-holder"><span class="image">[field_image_file]</span></span>
<span class="title">[name]</span>
<span class="caption">[description]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'image_gallery' => 'image_gallery',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['relationship'] = 'tid_representative';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['field_image_file']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_image_file']['alter']['link_class'] = 'image';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image_file']['element_class'] = 'image-holder';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = '<strong> <em> <br> <a>';
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['preserve_tags'] = '<br> <a> <strong> <em>';
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['description']['element_wrapper_class'] = 'caption';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="image-holder"><span class="image">[field_image_file]</span></span>
<span class="title">[name]</span>
<span class="caption">[description]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['path'] = 'photo-gallery';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Photo Gallery';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photo Galleries';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['relationship'] = 'tid_representative';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['field_image_file']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_image_file']['alter']['link_class'] = 'image';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image_file']['element_class'] = 'image-holder';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = '<strong> <em> <br> <a>';
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['preserve_tags'] = '<br> <a> <strong> <em>';
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['description']['element_wrapper_class'] = 'caption';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="image-holder"><span class="image">[field_image_file]</span></span>
<span class="title">[name]</span>
<span class="caption">[description]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'photo-gallery/[name]';
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $export['affiliate_image_galleries'] = $view;

  $view = new view();
  $view->name = 'affiliate_image_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Affiliate Image Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['text'] = '<span class="caption"><span>[title]</span></span>
[field_image_file]
';
  $handler->display->display_options['fields']['field_image_file']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => 'gallery',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Galleries (field_image_galleries) */
  $handler->display->display_options['arguments']['field_image_galleries_tid']['id'] = 'field_image_galleries_tid';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['table'] = 'field_data_field_image_galleries';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['field'] = 'field_image_galleries_tid';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_image_galleries_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_image_galleries_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_image_galleries_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['validate_options']['vocabularies'] = array(
    'image_gallery' => 'image_gallery',
  );
  $handler->display->display_options['arguments']['field_image_galleries_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_image_galleries_tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'photo-gallery/%';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'slideshow');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_file']['id'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['table'] = 'field_data_field_image_file';
  $handler->display->display_options['fields']['field_image_file']['field'] = 'field_image_file';
  $handler->display->display_options['fields']['field_image_file']['label'] = '';
  $handler->display->display_options['fields']['field_image_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['text'] = '<span class="caption"><span>[title]</span></span>
[field_image_file]
';
  $handler->display->display_options['fields']['field_image_file']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image_file']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_image_file']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_file']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['path'] = 'photo-gallery/%/slideshow';
  $export['affiliate_image_gallery'] = $view;

  return $export;
}

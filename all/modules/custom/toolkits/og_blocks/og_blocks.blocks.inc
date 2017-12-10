<?php
/**
 * Basic block
 * 
 * Used for the real blocks below, but can be used to act on all group members.
 */
class OgBlocksBasic {
  public $title = 'Basic';
  public $id = null;
  public $cache = DRUPAL_NO_CACHE;
  public $settings = array();
  
  /**
   * Constructor
   */
  public function __construct($id=null){
    $this->id = $id;
    
    // load from the database
    if($this->id){
      // calling og_blocks_get_blocks() will handle the storage switch for us
      $data = db_select('og_blocks')
        ->fields('og_blocks')
        ->condition('id', $this->id, '=')
        ->execute()
        ->fetchAssoc();
      
      $this->title = $data['title'];
      $this->settings = $data;
    }
  }
  
  /**
   * Configure function for this block type
   */
  public function configure(&$form){
    $form['og_block_title'] = array(
      '#type' => 'textfield',
      '#title' => 'Title',
      '#default_value' => $this->title
    );
    
    $form['og_block_class'] = array(
      '#type' => 'select',
      '#title' => 'OG Block Type',
      '#options' => og_blocks_get_block_class_options(),
      '#default_value' => get_class($this)
    );
  }
  
  /**
   * Create the block in the database
   */
  public function create() {
    if ($this->id) { return; }
    $this->id = db_insert('og_blocks')
      ->fields(array(
        'title' => $this->title,
        'class' => get_class($this)
      ))->execute();
    og_blocks_sync_storage('db');
  }
  
  public function get_nodes() {
    module_load_include('inc', 'og_blocks', 'og_blocks.api');
    if(module_exists('og_context')){
      $context = og_context();
      return og_blocks_get_group_members($context->gid);
    }
    return false;
  }
  
  public function get_setting($setting, $default=false){
    if (!isset($this->settings[$setting])) {
      return $default;
    }
    return $this->settings[$setting];
  }
  
  public function info(){
    return array(
      'info' => t($this->title),
      'cache' => $this->cache
    );
  }
  
  protected function line_item($item){
    return '<li>'. $item .'</li>';
  }
  
  public function save(&$edit){
    $this->set_setting('title', $edit['og_block_title']);
    $this->set_setting('class', $edit['og_block_class']);
    $this->update();
  }
    
  public function set_setting($setting, $value){
    $this->settings[$setting] = $value;
  }
  
  public function update() {
    if (!$this->id) { return; }
    
    $fields = $this->settings;
    unset($fields['id']);
    db_update('og_blocks')
      ->fields($fields)
      ->condition('id', $this->id, '=')
      ->execute();
    og_blocks_sync_storage('db');
  }
  
  public function view(){
    $block = array();

    $output_view = $this->get_setting('view');

    // get the nodes that belong to this group and are of the requested type
    $nodes = $this->get_nodes();

    // check if we have results
    if ($nodes) {
      // get the ids
      $items = array();
      foreach ($nodes as $node) {
        $items[] = $node->nid;
      }
      
      if (!$output_view) {
        // default output when no view is selected
        $entities = entity_load('node', $items);
        $entity_items = array();
        foreach ($entities as $entity) {
          $entity_items[] = '<a href="/'. drupal_lookup_path('alias', 'node/'. $entity->nid) .'">'. $entity->title .'</a>';
        }
        // this fails?
        // $content = theme_item_list(array('items' => $entity_items));

        // since theme_item_list fails, create our own basic HTML list
        $items = implode("\n", array_map(array($this, 'line_item'), $entity_items));
        $content = '<ul>'. $items .'</ul>';
        $block['content'] = array('#markup' => $content);
      } // end default output
      else {
        // if a view is passed/selected
        $output_view = explode(':', $output_view);
        
        $item_arguments = implode('+', $items);
        
        // $content = views_get_view_result($output_view[0], $output_view[1], $items);
        $view = views_get_view($output_view[0]);
        $view->init();
        $view->set_display('block');
        $view->set_arguments(array($item_arguments));
        $block['content'] = $view->render();
      } // end view passed
    }
    return $block;
  }
}

/**
 * Group Members By Content Type Block
 */
class OgBlocksGroupMembersByContentType extends OgBlocksBasic {
  public $title = 'Group Members by Content Type';
  
  public function configure(&$form){
    parent::configure($form);
    
    $form['block_content_type'] = array(
      '#type' => 'textfield',
      '#title' => 'Content type',
      '#description' => 'Enter the machine name for the content type to display',
      '#default_value' => $this->get_setting('content_type', ''),
    );

    $view_options = array_merge(array('' => 'None'), views_get_views_as_options());
    $form['block_view'] = array(
      '#type' => 'select',
      '#title' => 'Pass to view',
      '#options' => $view_options,
      '#description' => 'Pass the output to a view. If not, it will display a list of titles',
      '#default_value' => $this->get_setting('view')
    );
    return $form;
  }
  
  public function get_nodes() {
    module_load_include('inc', 'og_blocks', 'og_blocks.api');
    if (module_exists('og_context')) {
      $context = og_context();
      $content_type = $this->get_setting('content_type');
      return og_blocks_get_group_members_by_content_type($context->gid, $content_type);
    }
    return false;
  }
  
  public function save(&$edit){
    parent::save($edit);
    $this->set_setting('content_type', $edit['block_content_type']);
    $this->set_setting('view', $edit['block_view']);
    $this->update();
  }
}

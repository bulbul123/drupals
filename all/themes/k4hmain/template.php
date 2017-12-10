<?php

define('TK_DATA_DIR', 'toolkit_color_css');

function k4hmain_preprocess_html(&$variables, $hook) {
  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  if (!$variables['is_front']) {
    // Add unique class for each page.
    if (isset($_GET['q'])) {
      $path = drupal_get_path_alias($_GET['q']);
      // Add unique class for each website section.
      list($section, ) = explode('/', $path, 2);
      if (arg(0) == 'node') {
        if (arg(1) == 'add') {
          $section = 'node-add';
        }
        elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
          $section = 'node-' . arg(2);
        }
      }
      if (arg(0) == 'print' && arg(2) == 'export') {
        $section = 'print';
      }
      $variables['classes_array'][] = drupal_html_class('section-' . $section);
    }
  }

  // Add Google Fonts to the Site
  drupal_add_css('//fonts.googleapis.com/css?family=Droid+Serif:400,400italic,700,700italic', array('type' => 'external'));
  drupal_add_css('//fonts.googleapis.com/css?family=PT+Serif:400,400italic,700,700italic', array('type' => 'external'));
  drupal_add_css('//fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic', array('type' => 'external'));

  // Add Share this
  drupal_add_js('//s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4eeb508c181eafca', array('type' => 'external'));

//  Temporarily including this code in case we need to use it again in the near future
//  if (!isset($_COOKIE['Drupal_visitor_surveymonkey']) || $_COOKIE['Drupal_visitor_surveymonkey'] === FALSE) {
//    user_cookie_save(array('surveymonkey' => TRUE));

  // Add Survey Monkey code for Idea Lab recruitment
    $survey_on = variable_get('survey_monkey', FALSE);
    if ($survey_on) {
      drupal_add_js('https://www.research.net/jsPop.aspx?sm=Z_2fblW_2bbyKNQCWrvI8m1z2w_3d_3d', array('type' => 'external', 'scope' => 'footer', 'cache' => FALSE));
    }

  // Add headers to login, comment, feedback and all resources pages form pages to tell browsers not to cache
  if (substr($_GET['q'], 0, 10) === 'user/login'
      || substr($_GET['q'], 0, 13) === 'comment/reply'
      || (substr($_SERVER['REQUEST_URI'], 0, 10) === '/toolkits/' && substr($_SERVER['REQUEST_URI'], -9, 9) === '/feedback')
      || substr($_GET['q'], 0, 21) === 'all-toolkit-resources'
      || (substr($_SERVER['REQUEST_URI'], 0, 10) === '/toolkits/' && substr($_SERVER['REQUEST_URI'], -10, 10) === '/resources')) {
    drupal_add_http_header('Pragma', 'No-cache');
    drupal_add_http_header('Cache-control', 'No-cache, No-store');
  }

} //k4hmain_preprocess_html

// Add Custom Classes to Menu Links
function k4hmain_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  // Custom classes (learn-more class has special handling, so change that slightly)
  $custom_class = (($element['#title'] == 'Learn More') && (strstr($element['#theme'], 'menu_link__book_toc'))) ? 'learn-more-class' :  str_replace(' ','-',strtolower(check_plain($element['#title'])));
  $element['#attributes']['class'][] = $custom_class;
  $element['#localized_options']['attributes']['class'][] = $custom_class;
  $element['#localized_options']['html'] = TRUE;

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }


  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
} //k4hmain_menu_link

/**
 * Implements hook_preprocess_page()
 */

function k4hmain_preprocess_page(&$vars) {
  // Include fluidsurveys code where designated
//  _k4hmain_add_fluidsurveys();

  // Swap out the toolkits logo in the toolkit section.
  if ((arg(1, request_uri()) == 'toolkits' || strpos(arg(1, request_uri()), 'toolkits?page=') === 0) || (arg(1, request_uri()) == 'search' && arg(2, request_uri()) == 'toolkit')) {
//    $vars['logo'] = (url(path_to_theme() . '/logo-toolkits.png'));
    $vars['front_page'] = url('toolkits');
    $vars['theme_hook_suggestions'][] = 'page__section_toolkits';

    $arg2 = arg(2, request_uri());

    // Add class to toolkit home page.
    if(!$arg2) {
      $vars['classes_array'][] = 'content-fill page-toolkit-home';
    }

    switch ($arg2) {
      case 'resources':
      case 'collaborators':
      case 'all':
        $vars['classes_array'][] = 'content-fill';
    }
  }

  // Add color css for toolkits
  if (function_exists('toolkits_misc_current_toolkit') && toolkits_misc_current_toolkit()) {
    $toolkit = toolkits_misc_current_toolkit();
    $toolkit_color = $toolkit->field_toolkit_color_main['und'][0]['jquery_colorpicker'];
    $file_path = TK_DATA_DIR . '/' . $toolkit_color . '.css';
    $css_file = file_exists($file_path) ? $file_path : k4hmain_rebuild_toolkit_color_css($toolkit_color);
    drupal_add_css($css_file, array('type' => 'file', 'weight' => 111115, 'group' => CSS_THEME));
  }

  // Remove contextual-link-region class from the page
  // @todo Find out what module is adding this class.
  // This is treating the symptom and not the cause.  There is a module
  // that is injecting this class, causing the entire page div to activate
  // contextual hover links.  Specifically on the contributors page view.
  $key = array_search('contextual-links-region', $vars['classes_array']);
  if ($key !== FALSE) {
    unset($vars['classes_array'][$key]);
  }

 //Add a last updated var for topics pages.
   if(isset($vars['node']) && $vars['node']->type=='topic_page') {
     $node=$vars['node'];
     foreach ($node->field_topic_grouping[$node->language] as $item) { 
       $termId = $item['tid'];
     }
     $last_updated =db_query("SELECT max(node.changed) from node WHERE node.nid IN (SELECT field_data_field_topic_grouping.entity_id FROM field_data_field_topic_grouping WHERE field_data_field_topic_grouping.field_topic_grouping_tid = :tid)",array(':tid'=>$termId))->fetchField();
    $vars['last_updated']=$last_updated;
    $vars['last_updated']=date('F d, Y', $last_updated);
   }
}

/**
 * Implements hook_process_page()
 *
 * This must be done process because the breadcrumb is not set in preprocess.
 */

function k4hmain_process_page(&$vars) {
  // Check to see if we are on the toolkits page.
  if(!arg(2, request_uri()) && arg(1, request_uri()) == 'toolkits') {
    unset($vars['breadcrumb']);
    unset($vars['title']);
  }
//dpr($vars);
//exit();
}

function k4hmain_preprocess_node(&$vars) {
//dpr($vars);
  $types = array('toolkit_page', 'toolkit_resource');
  if (in_array($vars['type'], $types) && (isset($vars['body'][0]['value']) && strstr($vars['body'][0]['value'], '.mp4'))) {
    drupal_add_js('//vjs.zencdn.net/4.5/video.js', array('type' => 'external', 'scope' => 'header', 'every_page' => FALSE));
    drupal_add_css('//vjs.zencdn.net/4.5/video-js.css', array('type' => 'external'));
  }

  // Add flash player to content if a video file is attached and displaying node page (full display)
  $args = arg();
  $orig_q = explode('/', drupal_lookup_path('source', ltrim($_SERVER['REQUEST_URI'], '/')));
  if (count($args) >= 2 && ($args[1] == $vars['nid'] || count($orig_q) > 1 && $orig_q[1] == $vars['nid']) && !empty($vars['field_toolkit_files']) && $vars['elements']['#view_mode'] != 'print') {
    $vars = _k4hmain_add_flash_player($vars);
  } // end check if there are files

  // Shortcut class variables
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  // Add a class to titles based on the view mode
  $title_classes[] = 'title-' . $vars['view_mode'];

   // Share this Link
    if (isset($vars['content']['share_this'])) {
      global $base_url;

      $vars['content']['share_this']['0']['#markup'] = l(
        t('Share'),
        '//www.addthis.com/bookmark.php',
        array(
        'attributes' => array(
          'addthis:url' => $base_url . '/' . drupal_lookup_path('alias','node/' . $vars['nid']),
          'addthis:title' => $vars['title'],
          'class' => 'addthis_button_compact'
          ),
        )
      );
    } //if

    // Blog Read More
    if(isset($vars['content']['node_link'])) {
      $vars['content']['node_link']['0']['#markup'] = l(
        t('Read More'),
        'node/' . $vars['nid'],
        array(
        'attributes' => array(
          'class' => 'read-more',
          ),
        )
      );
    } //if

  // Add a Comment
  if(isset($vars['content']['add_a_comment']) && user_access('post comments')) {
    $vars['content']['add_a_comment']['0']['#markup'] = l(
      t('Add a Comment'),
      'node/' . $vars['nid'],
      array(
      'attributes' => array(
        'class' => 'add-comment',
        ),
        'fragment' => 'comment-form',
        )
    );
  } //if
  else {

    unset($vars['content']['add_a_comment']);

  } //else

    // Number of Comments
    if(isset($vars['content']['number_of_comments'])) {

      $comment_count = $vars['content']['number_of_comments']['#items'][0]['value'];
      $comment_or_comments = ($comment_count == 1) ? t('Comment') : t('Comments');
      $vars['content']['number_of_comments']['0']['#markup'] = l(
        $comment_count . ' ' . $comment_or_comments,
        'node/' . $vars['nid'],
        array(
        'attributes' => array(
          'class' => 'comment-count',
          ),
          'fragment' => 'comments',
          )
      );

  } //if

  // Check if comments are closed but not hidden
  if(isset($vars['comment']) && $vars['comment'] == 1) {

    unset($vars['content']['add_a_comment']);

  } //if
  elseif(isset($vars['comment']) && $vars['comment'] == 0) {

    unset($vars['content']['add_a_comment']);
    unset($vars['content']['number_of_comments']);

  } //elseif

/* Commenting out for now -- this is not wanted at this point
  // Add expander JS to resource pages.
  if($vars['type'] == 'toolkit_page' && $vars['view_mode'] == 'full') {
    // Only add js if there is no table in the content to avoid blank content area when "more" is clicked"
    if (!strstr($vars['body'][0]['value'], '<table')) {
      drupal_add_js(
        path_to_theme() . '/js/jquery.expander.min.js',
        array(
          'type' => 'file',
          'scope' => 'footer'
        )
      );
      drupal_add_js("
        jQuery(document).ready(function () {
          jQuery('.node-toolkit-page .field-name-body .field-item').expander({
            slicePoint: 1000,
            expandText: 'Read More',
            userCollapseText: 'Read Less',
            moreClass: 'read-more-down',
            lessClass: 'read-more-up',
            summaryClass: 'expander-summary',
            expandPrefix: '',
            expandEffect: 'fadeIn',
            collapseEffect: 'fadeOut'
          });
        });
        ",
        array(
          'type' => 'inline',
          'scope' => 'footer'
        )
      );
    }
  }
*/

  // Alter Resource Teaser variables
  if($vars['view_mode'] == 'resource_teaser') {
    $vars['content']['node_link'][0]['#markup'] =
      l(
        'Read More',
        substr($vars['node_url'], 1),
        array(
          'attributes' => array(
            'class' => array('more'),
          )
        )
      );
  }

  //Add cURL handling of call to MailChimp to deal with mixed content
  if(request_path()=="k4health-newsletters") {
    $curl= curl_init();
    curl_setopt ($curl, CURLOPT_URL, 'http://us4.campaign-archive2.com/generate-js/?u=4c824d609a93e07ec89e2df8e&fid=1877&show=10');
    curl_setopt ($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt ($curl, CURLOPT_CONNECTTIMEOUT, 0);
    $result=curl_exec($curl);
    $vars['content']['body'][0]['#markup'].='<script language="javascript">'.$result.'</script>';
  }

} //k4hmain_preprocess_node

function k4hmain_preprocess_search_results(&$vars) {
  if ($vars['module'] == 'apachesolr_search') {
    $vars['title'] = '';
  }
  else {
    $vars['title'] = t('Search Results');
  }
}

function k4hmain_preprocess_search_result(&$vars) {
  unset($vars['info_split']['user'], $vars['info_split']['comments']);
  if(isset($vars['result']['node']->created)) {
     $vars['info_split']['date'] = format_date($vars['result']['node']->created, 'small');
  }
  $vars['info_split']['date'] = t('Posted on:') . ' ' . format_date(strtotime($vars['info_split']['date']));
  $vars['info'] = join(' - ', $vars['info_split']);
}

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function k4hmain_facetapi_link_inactive($variables) {
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = '<span class="name">' . (($sanitize) ? check_plain($variables['text']) : $variables['text']) . '</span>';

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['text'] = theme('facetapi_count', $variables) . ' ' . $variables['text'];
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Returns HTML for the inactive facet item's count.
 *
 * @param $variables
 *   An associative array containing:
 *   - count: The item's facet count.
 *
 * @ingroup themeable
 */
function k4hmain_facetapi_count($variables) {
  return '<span class="facet-count">' . (int) $variables['count'] . '</span>';
}

/**
 * Returns HTML for an inactive facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @ingroup themeable
 */
function k4hmain_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget'),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements) . ' <strong>' . $link_text . '</strong>';
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Returns HTML for the deactivation widget.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The text of the facet link.
 *
 * @ingroup themable
 */
function k4hmain_facetapi_deactivate_widget($variables) {
  return '<span class="facet-remove">-</span>';
}

function k4hmain_apachesolr_search_noresults() {
    return '<div class="no-results">' . t('<ul>
  <li>Check if your spelling is correct, or try removing filters.</li>
  <li>Remove quotes around phrases to match each word individually: <em>"blue drop"</em> will match less than <em>blue drop</em>.</li>
  <li>You can require or exclude terms using + and -: <em>big +blue drop</em> will require a match on <em>blue</em> while <em>big blue -drop</em> will exclude results that contain <em>drop</em>.</li>
  </ul>') . '</div>';
}

function k4hmain_preprocess_breadcrumb(&$vars) {
  /* Remove the home link from Toolkits breadcrumb */
  if (arg(1, request_uri()) == 'toolkits') {
    array_shift($vars['breadcrumb']);
  }
  elseif (
    
    (arg(1, request_uri()) == 'search') &&
    (arg(2, request_uri()) == 'toolkit')
  ) {
    $vars['breadcrumb'] = array(
      l('Toolkits','toolkits'),
    );
    
  }
}

/**
* Output breadcrumb as an unorderd list with unique and first/last classes */
function k4hmain_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $last = end($breadcrumb);
  $title = drupal_get_title();

  if (strip_tags($last) == $title) {
    $breadcrumb[count($breadcrumb) - 1] = $title;
  } // if
  else {
    $breadcrumb[] = $title;
  } // else

  $breadcrumb = array_unique($breadcrumb);
  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2>' . t('You are here') . '</h2>';
    $crumbs = '<ul>';
    $array_size = count($breadcrumb);
    $i = 0;
    while ( $i < $array_size) {
      $crumbs .= '<li>' . $breadcrumb[$i] . '</li>';
      $i++;
    }
    $crumbs .= '</ul>';
    return $crumbs;
  }
}

/**
 * Implements hook_preprocess_block()
 */

function k4hmain_preprocess_block(&$vars) {
  /* Set shortcut variables. */
  $block_id = $vars['block']->bid;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  #print $block_id . '<br/>';

  /* Add certain classes to all blocks */
  $title_classes[] = 'block-title';
  $content_classes[] = 'content';

  /* Add classes based on the block delta. */
  switch ($block_id) {
    /* Main Menu blocks */
    case 'menu_block-2':
    case 'menu_block-9':
      $classes[] = 'main-menu';
      break;
    /* Toolkit sidebar navigation block */
    case 'book-navigation':
      $classes[] = 'toolkit-background';
      $title_classes[] = 'element-invisible';
      $content_classes[] = 'navigation-collapsible';
      break;
    /* Toolkit contents block */
    case 'toolkits_contents_block-toolkits_contents_block':
      $classes[] = 'toolkit-background block-inset block-align-top';
      $title_classes[] = 'block-inset-title';
      break;
    /* Toolkit print links block */
    case 'toolkits_contents_block-toolkits_print_block':
      $classes[] = 'toolkit-background';
      $classes[] = 'block-plain';
      break;
    /* Toolkit search block */
    case 'toolkits_search_block-toolkits_search_block':
      $classes[] = 'toolkit-background';
      $classes[] = 'block-plain';
      $title_classes[] = 'title-centered';
      break;
    /* Toolkit sidebar block */
    case 'views-toolkit_sidebar_for_pages-block':
      $classes[] = 'block-plain';
      break;
    /* Toolkit What's New block */
    case 'og_blocks-og_blocks_9':
      $classes[] = 'block-divider-top';
      $title_classes[] = 'title-left';
      break;
    /* Toolkit Brought to you by block */
    case 'og_blocks-og_blocks_8':
      $classes[] = 'block-plain';
      $title_classes[] = 'title-left';
      break;
    /* Toolkit Most Popular block */
    case 'og_blocks-og_blocks_10':
      $classes[] = 'block-divider-top';
      $classes[] = 'block-plain';
      $title_classes[] = 'title-left';
      break;
    /* Toolkit Featured Carousel block */
    case 'views-nodequeue_10-block':
      $classes[] = 'block-rich block-rich-gray block-toolkit-featured';
      $title_classes[] = 'title-rich title-centered';
      break;
    /* Latest Toolkit Updates block */
    case 'views-toolkits_updates-block':
      $classes[] = 'content-list';
      break;
    /* Toolkit Topics block */
    case 'views-toolkit_topics-block':
      $classes[] = 'link-list';
      break;
    /* Toolkit Subscribe block */
    case 'toolkits_contents_block-toolkits_subscribe':
      $classes[] = 'block-inset block-rich block-rich-red block-cover block-no-divider text-align-center';
      $title_classes[] = 'title-rich';
      break;
    /* Toolkit Intro block */
    case 'toolkits_contents_block-toolkits_intro_text':
      $classes[] = 'block-rich block-rich-red block-cover block-no-divider text-align-center block-tout block-toolkit-intro shift-region';
      $title_classes[] = 'title-rich';
      break;
    /* Toolkit Intro block */
    case 'menu_block-10':
      $classes[] = 'block-rich block-rich-red block-cover text-align-center block-toolkit-actions shift-region';
      $content_classes[] = 'overlay-red';
      break;
    /* Toolkit Order on CD block */
    case 'toolkits_contents_block-toolkits_order_cd_block':
      $classes[] = 'block-callout block-callout-cd';
      $title_classes[] = 'title-callout';
      break;
    /* Toolkit Archive block */
    case 'toolkits_contents_block-toolkits_archive':
//      $classes[] = 'block-callout block-archive';
//      $title_classes[] = 'title-callout';
      break;
    /* Toolkit Collaborating Organizations block */
    case 'views-35b8ae7fb4a582bbbf862d87ff433c07':
      $classes[] = 'block-carousel-vertical';
      break;
    /* Toolkit Admin Menu block */
    case 'toolkits_contents_block-toolkits_admin_menu':
      $classes[] = 'block-embossed-gray';
      break;
    /* Toolkit Page Resources block */
    case 'views-toolkit_page_resources-block':
      $title_classes[] = 'title-left';
      break;
    /* Toolkit Featured Resources block */
    case 'views-2c5804a45e6b244dfc4e3238903202ac':
      $classes[] = 'block-og-blocks block-divider-top';
      $title_classes[] = 'title-left';
      break;
  }
}

/**
 * Returns CSS based on toolkit color.
 *
 * @param $color
 *  A hexadecimal color value. Defaults to light blue from mockup.
 */
function _k4hmain_get_toolkit_color_css($color = '4c7fbf') {
  $output = 'body.section-toolkits #breadcrumb,
body.section-toolkits #block-k4h-epub-toolkits-download-block,
body.section-toolkits #block-k4h-epub-offline-order-form,
body.section-toolkits .toolkit-background { background-color: #' . $color . '}

body.section-toolkits h1.page-title { color: #' . $color . '}

body.section-toolkits .book-navigation .page-links a:hover { color: #' . $color . '}

body.section-toolkits ul.inline li a,
body.section-toolkits ul.inline li a:hover,
body.section-toolkits .button-toolkit,
body.section-toolkits .button-toolkit:hover { background-color: #' . $color . '}';
  return $output;
}

/**
 * Helpfer function. Adds fuildsurveys code to nodes in toolkits specified to have it.
 */
function _k4hmain_add_fluidsurveys() {
  if (!(arg(0) == 'node' && ctype_digit(arg(1)))) {
    return;
  }
  $node = node_load(arg(1));
  // Put toolkit nids => gids in this array
  $groups = array(
/*
    11074 => 48,
    6245 => 17,
    11075 => 49,
    7055 => 31,
    11079 => 53,
    11073 => 47,
    8746 => 35,
    8748 => 37,
*/
  );
  if (count($groups) == 0) {
    return;
  }
  $entity_type = 'node';
  $entity = entity_object_load($node->nid, $entity_type);
  list($id, $vid, $bundle) = entity_extract_ids($entity->type, $entity);
  $is_group = og_is_group_type($entity_type, $bundle);
  $gid = NULL;
  if ($is_group) {
    $gid = $groups[$node->nid];
  }
  if (og_is_group_content_type($entity_type, $bundle)) {
    $gid = $node->group_audience[$node->language][0]['gid'];
  }
  // If we're not in a toolkit that gets a survey, stop here
  if (empty($gid)) {
    return;
  } 

  $tk_surveys = array(
    '48' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-m-e/prompt/1630/',
      'id'   => '1630',
    ),
    '17' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-km/prompt/1629/',
      'id'   => '1629',
    ),
    '49' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-lam/prompt/1628/',
      'id'   => '1628',
    ),
    '31' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-miycn-fp/prompt/1627/',
      'id'   => '1627',
    ),
    '53' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-alhiv/prompt/1626/',
      'id'   => '1626',
    ),
    '47' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-mcp/prompt/1625/',
      'id'   => '1625',
    ),
    '35' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing-implants/prompt/1624/',
      'id'   => '1624',
    ),
    '37' => array(
      'href' => '//fluidsurveys.com/surveys/k4health/k4health-toolkits-a-b-testing/prompt/1623/',
      'id'   => '1623',
    ),
  );

  // Load js for fluidsurveys
  if ($tk_surveys[$gid]) {
    drupal_add_js('//fluidsurveys.com/media/static/survey-prompts.js',
      array(
        'type' => 'external',
        'scope' => 'footer'
      )
    );
    drupal_add_js("
        var FSPROMPT = new SurveyPrompt({
          id: {$tk_surveys[$gid]['id']},
          href: \"{$tk_surveys[$gid]['href']}\",
          \"$\": jQuery
          // cookie: 'fs-popup-{$tk_surveys[$gid]['id']}'
        }).setup();
        jQuery.noConflict(true);
      ",
      array(
        'type' => 'inline',
        'scope' => 'footer'
      )
    );
  }
  return TRUE;
}


/**
 * Helpfer function. Adds flash player with loaded video file to
 * node content in toolkits when a video file is attached.
 */
function _k4hmain_add_flash_player($vars) {
  foreach ($vars['field_toolkit_files'] as $id => $file) {
    // This could be an array of file arrays, if so don't do anything
    if (!$file['type']) {
      return $vars;
    }

    if ($file['type'] == 'video') {
      $filename = drupal_encode_path('/sites/default/files/' . $file['filename']);
      if(strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE')) {
        drupal_add_js(
          '/sites/all/libraries/OSFlvPlayer_v4.2/AC_RunActiveContent.js',
          array(
            'type' => 'file',
            'scope' => 'header'
          )
        );
        require_once('sites/all/libraries/flvinfo2.php');
        $flvinfo = new FLVInfo2();
        $fl = 'sites/default/files/' . str_replace(" ", "\x20", $file['filename']);
        $info = $flvinfo->getInfo("$fl",true);
        $width = $info->video->width;
        $height = $info->video->height;
      } else {
        drupal_add_js(
          'sites/all/libraries/OSFlvPlayer_v4.2/rac.js',
          array(
            'type' => 'file',
            'scope' => 'header',
            'preprocess' => FALSE,
          )
        );
        $width = ''; 
        $height = ''; 
      }

      // Add script to end of content
      $vars['content']['body'][0]['#markup'] .= "<div style='text-align: center'>
<script src='/sites/all/libraries/OSFlvPlayer_v4.2/AC_RunActiveContent.js' language='javascript'></script>
<!-- saved from url=(0013)about:internet -->
<script language='javascript'>
 AC_FL_RunContent('codebase', '//download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0', 'width', '$width', 'height', '$height', 'src', ((!DetectFlashVer(9, 0, 0) && DetectFlashVer(8, 0, 0)) ? '/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer' : '/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer'), 'pluginspage', 'www.macromedia.com/go/getflashplayer', 'id', 'flvPlayer', 'allowFullScreen', 'true', 'movie', ((!DetectFlashVer(9, 0, 0) && DetectFlashVer(8, 0, 0)) ? '/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer' : '/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer'), 'FlashVars', 'movie=$filename&btncolor=0x333333&accentcolor=0x20b3f7&txtcolor=0xffffff&volume=&autoload=on');
</script>
<noscript>
 <object width='$width' height='$height' id='flvPlayer'>
  <param name='allowFullScreen' value='true'>
  <param name='movie' value='/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer.swf?movie=$filename&btncolor=0x333333&accentcolor=0x20b3f7&txtcolor=0xffffff&volume=&autoload=on'>
  <embed src='/sites/all/libraries/OSFlvPlayer_v4.2/OSplayer.swf?movie=$filename&btncolor=0x333333&accentcolor=0x20b3f7&txtcolor=0xffffff&volume=&autoload=on' width='$width' height='$height' allowFullScreen='true' type='application/x-shockwave-flash'>
 </object>
</noscript>
</div>";

    } // end if file type is video
  }
  return $vars;
}

function k4hmain_rebuild_toolkit_color_css($color) {
  $dir = file_build_uri(TK_DATA_DIR);
  $data_css = file_build_uri(TK_DATA_DIR . '/' . $color . '.css');
  if(!file_exists($data_css)) {
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
    file_unmanaged_save_data('', $data_css);
  }

  $data = _k4hmain_get_toolkit_color_css($color);
  $path = $data_css;

  if (file_put_contents($path, $data)) {
    return $path;
  }
  else {
    return '<p>Fail. Typically this will happen when the server can\'t write to
    the css file(s). To fix, adjust the file perms or ownership of the css file(s).</p>';
  }

}

/**
 * Implementation of hook_cron().
 */
function k4hmain_cron() {
  // Clean up toolkit css files in sites/default/files dir
  $colors = db_query("SELECT DISTINCT(field_toolkit_color_main_jquery_colorpicker) FROM field_data_field_toolkit_color_main")->fetchAll();
  $files = scandir(file_build_uri(TK_DATA_DIR));
  $current_files = array();
  foreach ($files as $file) {
    $current_files[] = $filename = pathinfo($file, PATHINFO_FILENAME);
  }
  $missing_css = array_diff($colors, $current_files);
  $delete_files = array_diff($current_files, $colors);

  // Create missing css files -- NOT SURE WE NEED THIS AS THEY ARE CREATED ON THE FLY IF NOT PRESENT
  foreach ($missing_css as $color) {
    k4hmain_rebuild_toolkit_color_css($color);
  }

  // Delete files no longer needed
  foreach ($delete_files as $delete_file) {
    file_unmanaged_delete(file_build_uri(TK_DATA_DIR . '/' . $delete_file . '.css'));
    watchdog('k4hmain', 'deleted old toolkit color css file');
  }
}

/**
 * Implementation of hook_form_alter().
 *
 * Filter possible xss attacks coming from URL parameters out of forms.
 */
function k4hmain_form_alter(&$form, &$form_state, $form_id) {
  $replacements = array(';' => '', ':' => '', '(' => '', ')' => '');
  $form['#action'] = strtr(filter_xss($form['#action']), $replacements);
  if (isset($form['basic'])) {
    $form['basic']['get']['#default_value'] = strtr(filter_xss($form['basic']['get']['#default_value']), $replacements);
  }
}

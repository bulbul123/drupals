<?php

/**
 * @file
 * Generates the PDF versions of the pages
 *
 * This file is included by the print_pdf module and includes the
 * functions that interface with the PDF generation packages.
 *
 * @ingroup print
 */

module_load_include('inc', 'print', 'print.pages');

function og_analytics_print_pdf_controller($start = '-31 days', $end = '-1 day') {
  $parts = explode('/', $_GET['q']);
  $nid = $parts[2];
  array_shift($parts);
  $q = implode('/', $parts);
  if (!strstr($q, '/print')) {
    $q .= '/print';
  }
  $toolkit_title = db_query("SELECT label FROM {og} WHERE etid = :etid LIMIT 1", array(':etid' => $nid))->fetchField();
/* In case we try to create PDFs
  $find = array("-", " ", "'", ",");
  $replace = array('', '-', '', '');
  $toolkit = str_replace($find, $replace, trim($toolkit_title));
  $date = date('Y-m-d');
  $filename = 'analytics_' . $toolkit . '_' . $date . '.pdf';
  $pdf_filename = (empty($filename)) ? 'analytics' : $filename;
  if (function_exists('transliteration_clean_filename')) {
    $pdf_filename = transliteration_clean_filename($pdf_filename, language_default('language'));
  }
  $http = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on') ? 'https://' : 'http://';
  $domain = (!empty($_SERVER['HTTP_HOST'])) ? $_SERVER['HTTP_HOST'] : $_SERVER['SERVER_NAME'];
*/
  $parts = explode('&', $_GET['q']);
  $start = explode('=', $parts[1]);
  $start = $start[1];
  $end = explode('=', $parts[2]);
  $end = $end[1];
  if ($nid == 'ajax') {
    $nid = explode('=', $parts[3]);
    $nid = $nid[1];
  }
  $html = og_analytics_google_analytics_reports_summary_page($nid, $start, $end);
  $lang = (isset($_GLOBALS['locale'])) ? $_GLOBALS['locale'] : language_default('language');
  $print = array(
    'language' => $lang,
    'title'    => 'Analytics for ' . $toolkit_title,
    'head'     => drupal_Get_html_head(),
    'favicon'  => theme_get_setting('toggle_favicon') ? '<link rel="shortcut icon" href="' . theme_get_setting("favicon") . '" type="image/x-icon"/>' . "\n" : '',
  );
  $css_files = array(drupal_get_path('module', 'og_analytics') . '/css/og_analytics.css', drupal_get_path('module', 'og_analytics') . '/css/og_analytics_print.css');
  $style = '';
  foreach ($css_files as $css_file) {
      if (file_exists($css_file)) {
        $style .= file_get_contents($css_file, TRUE);
      }
  }
  $print['css'] = "<style type='text/css' media='all'>$style</style>\n";
  $print['content'] = $html;
  include_once(drupal_get_path('module', 'og_analytics') . '/theme/og_analytics.tpl.php');
exit();

/* In case we try to create PDFs
//  $page = menu_execute_active_handler($q, FALSE);
//    $html = drupal_render($page);

    // Run wkhtmltopdf
    $descriptorspec = array(
        0 => array('pipe', 'r'), // stdin
        1 => array('pipe', 'w'), // stdout
        2 => array('pipe', 'w'), // stderr
    );

    $process = proc_open('sites/all/libraries/wkhtmltox/bin/wkhtmltopdf -q - -', $descriptorspec, $pipes);

    // Send the HTML on stdin
    fwrite($pipes[0], $html);
    fclose($pipes[0]);

    // Read the outputs
    $pdf = stream_get_contents($pipes[1]);
    $errors = stream_get_contents($pipes[2]);

    // Close the process
    fclose($pipes[1]);
    $return_value = proc_close($process);

    // Output the results
    if ($errors) {
        throw new Exception('PDF generation failed: ' . $errors);
    } else {
        header('Content-Type: application/pdf');
        header('Cache-Control: public, must-revalidate, max-age=0'); // HTTP/1.1
        header('Pragma: public');
        header('Expires: Sat, 26 Jul 1997 05:00:00 GMT'); // Date in the past
        header('Last-Modified: ' . gmdate('D, d M Y H:i:s').' GMT');
        header('Content-Length: ' . strlen($pdf));
        header('Content-Disposition: inline; filename="' . $pdf_filename . '";');
        echo $pdf;
    }
return;

  module_load_include('inc', 'print_pdf', 'print_pdf.pages');
///dpr($http . $domain . '/og_analytics_printpdf/' . $q);
//  $page = menu_execute_active_handler($q, FALSE);
//  $pdf = print_pdf_generate_path($http . $domain . '/' . $q, $query = NULL, $cid = NULL, $pdf_filename = $filename);
    $node = node_load($nid);
    $meta = array(
      'node' => $node,
//      'url' => url(drupal_get_path_alias(empty($node->nid) ? $node->path : "node/$node->nid"), array('absolute' => TRUE)),
      'url' => url($q, array('absolute' => TRUE)),
    );
    if (isset($node->name)) $meta['name'] = $node->name;
    if (isset($node->title)) $meta['title'] = $node->title;
//  module_load_include('inc', 'print_pdf', 'lib_handlers/print_pdf_wkhtmltopdf/print_pdf_wkhtmltopdf.pages');

    $pdf = '';
    $cachemiss = FALSE;
    $cache_enabled = variable_get('print_pdf_cache_enabled', PRINT_PDF_CACHE_ENABLED_DEFAULT);
    if ($cache_enabled && isset($node->nid)) {
      // See if the file exists in the cache
      $cachefile = drupal_realpath(print_pdf_cache_dir()) . '/' . $filename;
      if (is_readable($cachefile)) {
        // Get the PDF content from the cached file
        $pdf = file_get_contents($cachefile);
        if ($pdf === FALSE) {
          watchdog('print_pdf', 'Failed to read from cached file %file', array('%file' => $cached), WATCHDOG_ERROR);
        }
      }
      else {
        $cachemiss = TRUE;
      }
    }

//    $html = drupal_render_page($page);

    // Img elements must be set to absolute
    $pattern = '!<(img\s[^>]*?)>!is';
    $html = preg_replace_callback($pattern, '_print_rewrite_urls', $html);

    // Convert the a href elements, to make sure no relative links remain
    $pattern = '!<(a\s[^>]*?)>!is';
    $html = preg_replace_callback($pattern, '_print_rewrite_urls', $html);
    // And make anchor links relative again, to permit in-PDF navigation
    $html = preg_replace("!${base_url}/" . $link['path'] . '/.*?#!', '#', $html);
    // If cache is off or file is not cached, generate one from scratch
    if (empty($pdf)) {
      $pdf = print_pdf_generate_html($html, $meta, $pdf_filename);
    }

    if (!empty($pdf)) {
      // A PDF was created, save it to cache if configured
      if ($cachemiss) {
        if (file_unmanaged_save_data($pdf, $cachefile, FILE_EXISTS_REPLACE) == FALSE) {
          watchdog('print_pdf', 'Failed to write to "%f".', array('%f' => $filename), WATCHDOG_ERROR);
        }
      }

      return $pdf_filename ? print_pdf_dispose_content($pdf, $pdf_filename) : $pdf;
    }
//  return print_pdf_wkhtmltopdf_print_pdf_generate($html);

//dpr($html);
//exit();
*/
}

/*
function og_analytics_print_pdf_controller() {
  print_pdf_controller();
}
*/
/**
 * Generate a PDF version of the printer-friendly page
 *
 * @see print_controller()
 * @see _print_pdf_dompdf()
 * @see _print_pdf_tcpdf()
 */
function og_analytics_print_pdf_controller_old() {
  // Disable caching for generated PDFs, as Drupal doesn't ouput the proper headers from the cache
  $GLOBALS['conf']['cache'] = FALSE;

  $args = func_get_args();
  $path = filter_xss(implode('/', $args));
  $cid = isset($_GET['comment']) ? (int)$_GET['comment'] : NULL;

  // Handle the query
  $query = $_GET;
  unset($query['q']);

  if (!empty($path)) {
    if ($alias = drupal_lookup_path('source', $path)) {
      // Alias
      $path_arr = explode('/', $alias);
      $node = node_load($path_arr[1]);
    }
    elseif (ctype_digit($args[0])) {
      // normal nid
      $node = node_load($args[0]);
    }
    elseif ($args[0] == 'book' && $args[1] == 'export' && ctype_digit($args[3])) {
      // Path is book/export/html/[nid]
      $node = node_load($args[3]);
    }

    $pdf_filename = variable_get('print_pdf_filename', PRINT_PDF_FILENAME_DEFAULT);
    if (!empty($pdf_filename) && !empty($node)) {
      $pdf_filename = token_replace($pdf_filename, array('node' => $node), array('clear' => TRUE));
    }
    else {
      $pdf_filename = token_replace($pdf_filename, array('site'), array('clear' => TRUE));
      if (empty($pdf_filename)) {
        // If empty, use a fallback solution
        $pdf_filename = str_replace('/', '_', $path);
      }
    }
  }
  else {
    $pdf_filename = 'page';
  }

  if (function_exists('transliteration_clean_filename')) {
    $pdf_filename = transliteration_clean_filename($pdf_filename, language_default('language'));
  }

  drupal_alter('print_pdf_filename', $pdf_filename, $path);

  module_load_include('inc', 'print_pdf', 'print_pdf.pages');
  $pdf = print_pdf_generate_path($path, $query, $cid, $pdf_filename . '.pdf');
  if ($pdf == NULL) {
    drupal_goto($path);
    exit;
  }

  $nodepath = (isset($node->nid)) ? 'node/' . $node->nid : drupal_get_normal_path($path);
  db_merge('print_pdf_page_counter')
    ->key(array('path' => $nodepath))
    ->fields(array(
        'totalcount' => 1,
        'timestamp' => REQUEST_TIME,
    ))
    ->expression('totalcount', 'totalcount + 1')
    ->execute();

  drupal_exit();
}

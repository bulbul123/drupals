<?php
/**
 * @file
 * Theme implementation to display the Google Analytics summary.
 */
?>

<div class="google-analytics-summary google-analytics-reports">
  <div class="google-analytics-visits">
    <h3><?php print t('Sessions ' . $timespan); ?></h3>
    <?php print $visit_chart; ?>
  </div>

  <div class="google-analytics-totals">
    <h3><?php print t('Site Usage'); ?></h3>
    <table>
      <tr class="odd">
        <td><?php print $entrances; ?></td>
        <th><?php print t('Sessions'); ?></th>
        <td><?php print $bounces; ?></td>
        <th><?php print t('Bounce Rate'); ?></th>
      </tr>
      <tr class="even">
        <td><?php print $pageviews; ?></td>
        <th><?php print t('Pageviews'); ?></th>
        <td><?php print $time_on_site; ?></td>
        <th><?php print t('Avg. Time on Site'); ?></th>
      </tr>
      <tr class="odd">
        <td><?php print $pages_per_visit; ?></td>
        <th><?php print t('Pages/Session'); ?></th>
        <td><?php print $new_sessions; ?></td>
        <th><?php print t('% New Sessions'); ?></th>
      </tr>
    </table>
    <?php print $site_usage_legend; ?>
  </div>

  <div class="google-analytics-pages">
    <h3><?php print t('Top Pages'); ?></h3>
    <?php print $pages; ?>

<?php
/*
    <div class="google-analytics-searches">
      <h3><?php print t('Top Searches'); ?></h3>
      <?php print $searches; ?>
    </div>
*/
?>

    <div class="google-analytics-countries">
      <h3><?php print t('Top Countries'); ?></h3>
      <?php print $countries; ?>
    <?php print $countries_legend; ?>
    </div>
  </div>

<?php
/*
  <div class="google-analytics-pages">
    <h3><?php print t('List of Top Countries'); ?></h3>
    <?php print $countries_list; ?>

    </div>
*/
?>
  </div>

  <div class="clearfix">
    <div class="google-analytics-referrals">
      <h3><?php print t('Top Referrals'); ?></h3>
      <?php print $referrals; ?>
    <?php print $referrals_legend; ?>
    </div>

    <div class="google-analytics-keywords">
      <h3><?php print t('Top Keywords'); ?></h3>
      <?php print $keywords; ?>
    <?php print $keywords_legend; ?>
    </div>
  </div>


  <div class="clearfix">
    <div class="google-analytics-source_types">
      <h3><?php print t('Source Types'); ?></h3>
      <?php print $source_types; ?>
    <?php print $source_types_legend; ?>
    </div>
  </div>
  <div class="clearfix">
    <div class="google-analytics-allpageviews">
      <h3><?php print t('Page Views'); ?></h3>
      <?php print $allpageviews; ?>
    <?php //print $source_types_legend; ?>
    </div>
</div>

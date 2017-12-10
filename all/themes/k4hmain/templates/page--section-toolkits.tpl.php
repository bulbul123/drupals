<div id="page" class="<?php print $classes; ?>">
  <div id="utility">
    <div class="container">
      <?php if ($page['utility']) { ?>
          <?php print render($page['utility']); ?>
      <? } // end utility ?>
    </div>
  </div>

  <div id="header">
    <div class="container">
      <h1 id="logo">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php else: ?>
          <a href="<?php print $base_path; ?>"><?php print $site_name; ?></a>
        <?php endif; ?>
      </h1>
      <?php if ($page['header']) { ?>
          <?php print render($page['header']); ?>
      <? } // end header ?>
      <?php if ($page['navigation']) { ?>
        <div id="navigation">
          <?php print render($page['navigation']); ?>
        </div>
      <? } // end navigation ?>
    </div>
  </div>

  <div id="main">
    <div class="container">

      <?php if ($messages) { ?>
        <div id="messages">
            <?php print $messages; ?>
        </div>
      <? } // end messages ?>

      <?php if (render($breadcrumb) && !$is_front) { ?>
          <div id="breadcrumb" class="clearfix">
            <?php print render($breadcrumb);
              if ($page['breadcrumb']) {
                print render($page['breadcrumb']);
              } ?>
          </div>
        <? } // end breadcrumb ?>

      <div id="main-content">
        <div id="content">

          <?php if ($page['highlighted']) { ?>
            <div id="highlighted">
              <?php print render($page['highlighted']); ?>
            </div>
          <? } // end highlighted ?>

          <?php if ($page['featured']) { ?>
            <div id="featured">
              <?php print render($page['featured']); ?>
            </div>
          <? } // end featured ?>

          <?php if (render($tabs)) { ?>
            <div id="tabs">
              <?php print render($tabs); ?>
            </div>
          <? } // end tabs ?>

          <?php if (!$is_front && isset($title) && strlen($title) > 0) { ?>
            <h1 class="page-title"><?php print $title; ?></h1>
          <? } ?>

          <div id="content-inner">

            <?php if ($page['help']) { ?>
              <div id="help">
                <?php print render($page['help']); ?>
              </div>
            <? } // end help ?>

            <?php print render($page['content']); ?>

          </div>

          <?php if ($page['sidebar_second']) { ?>
            <div id="sidebar-second">
              <?php print render($page['sidebar_second']); ?>
            </div>
          <? } // end content_below ?>

        </div>

        <?php if ($page['sidebar_first']) { ?>
          <div id="sidebar-first" class="aside">
            <?php print render($page['sidebar_first']); ?>
          </div>
        <? } // end sidebar_first ?>

      </div>

    </div>
  </div>

  <div id="footer">
    <div class="container">
      <?php print render($page['footer']); ?>
    </div>
  </div>

  <?php if ($page['admin_footer']) { ?>
    <div id="admin-footer">
      <div class="container">
        <?php print render($page['admin_footer']); ?>
      </div>
    </div>
  <? } // end admin_footer ?>

</div>

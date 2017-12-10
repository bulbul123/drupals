(function ($) {
  $(document).ready(function() {

    // Initialize adding of classes and hiding of submenus for book nav
    $('li.expanded ul.menu').hide();
    $('li.expanded a.active + ul.menu').show();
    $('li.expanded a.active + ul.menu').find('ul.menu').show();
    $('li.expanded a.active').parents('ul.menu').show();
    $('li.expanded').addClass('alter-expanded');
    $('li.expanded').not('li.expanded li.expanded').children('a').after( '<div class="expander"><a href="#" class="expandapply" title="click to expand"></a></div>' );
    $('li.expanded:has(.active) .expander a.expandapply').removeClass('expandapply').addClass('collapseapply').attr('title', 'click to collapse');;

    // Adjust expander icon placement for different size sidebar-first
    if ( $('#sidebar-first').css('width') == '368px' ) {
      $('#block-book-navigation li.expanded .expander').css("margin-left", "330px");
    }

    // Toggle between showing and hiding submen items
    $('div.expander').toggle(function() {
      $(this)
        .closest('li.expanded')
        .find('ul.menu')
        .slideDown(300, 'swing', false);
      $(this)
        .children('a')
        .addClass("collapseapply").removeClass("expandapply").attr('title', 'click to collapse');
      $(this)
        .closest('li.expanded')
        .find('a')
        .removeClass('leaf');
      return false;
    }, function() {
      $(this)
        .closest('li.expanded')
        .find('ul.menu')
        .slideUp(300, 'swing', false);
      $(this)
        .children('a')
        .addClass("expandapply").removeClass("collapseapply").attr('title', 'click to expand');
      $(this)
        .closest('li.expanded')
        .find('a')
        .addClass('leaf');
      return false;
    });

  });
})(jQuery); //$

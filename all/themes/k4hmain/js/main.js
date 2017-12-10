(function ($) {

  Drupal.behaviors.k4health = {
    attach: function() {
      $(".field-name-body").fitVids();
    }
  }

  $(document).ready(function(){
    //$(".views-exposed-widget select").uniform();

    //  Navigation DropDown
    createDropDownNav($(".main-menu .menu-block-wrapper"));

    // Hide linkchecker permission restricted lines
    $('.page-node-linkchecker td').each(function(index) {
       if ($(this).text()=="Permission restrictions deny you access to this broken link.") {
          $(this).hide();
       }
    });

    //  Utility Toggle
    createToggleNav($(".menu-block-1"));

    //  Colloborating Organization scrolling
    if( $(".block-carousel-vertical").length > 0 ){
      scrollUpdates();
    }

    $(".field-name-body").fitVids();

    // Remove top border to blog list...weird issue with load more module.
    if($('.blog-list').length > 0) {

      $('.blog-list li:first-child').addClass('first');

    } //if
    // Contributor add masonry
    if ($('.section-contributor .contributor-list').length >0) {
	$('.view-blog-authors .item-list ul').masonry({
 		itemSelector:'li.views-row',
	});	

    }

    // Calendar Tooltip
    if($('.calendar-calendar').length > 0) {

      $('.calendar-calendar').find('a').each(function() {
        $(this).attr('data-original-title',$(this).text());
      });

      $('.calendar-calendar a').twipsy({
        animate: false
      });

    } //if

    // Accordion for New Visitors
    if($('#block-views-for-new-visitors-block').length > 0) {

      $('#block-views-for-new-visitors-block').find('.description-wrap').hide();
      $('#block-views-for-new-visitors-block').find('h3 a').click(function() {

        if ($(this).hasClass('.active')) {

          $(this).removeClass('.active').parent().parent().find('.description-wrap').slideUp();

        } //if
        else {

          $('#block-views-for-new-visitors-block').find('h3 a').removeClass('.active');
          $('#block-views-for-new-visitors-block').find('.description-wrap').slideUp();
          $(this).addClass('.active').parent().parent().find('.description-wrap').slideDown();

        } //else
        return false;
      });

    } //if

    $('a[href][rel=twipsy]').twipsy({animate: false});

    // Launch Fancybox on inline images
    if ($('.zoom').length > 0) {

      var zoomIcon = '<span>Zoom</span>';
      $('a.zoom').each(function(){
        $(this).append(zoomIcon);
      });

      $('a.zoom').fancybox({
        padding: 0,
        beforeShow: function() {
          var imgAlt = $(this.element).find("img").attr("alt");
          $(".fancybox-image").attr("alt", imgAlt);
        }
      });

    } // if

    // Add fancybox overlay when needed, especially for elearning courses
    if ($('.overlay').length > 0) {
      $('a.overlay').fancybox({
        padding: 4,
        type: 'iframe',
        width: '960',
        height: '570',
        autoScale: false,
        autoDimensions: false
      });
    } // if

    // Flexslider
    if($('.flexslider').length > 0 && $('.slides li').length > 1) {

      // Start up Flexslider
      $('.flexslider').flexslider({
        animation: "slide",
        controlNav: false,
        //slideshowSpeed: 70000000000,
        before: function(){
          $('.front .flex-direction-nav').hide();
        },
        after: function(){
          $('.front .flex-direction-nav').fadeIn();
        }
      });

    } //if

    //  Toolkits Home Slideshow

    if($(".block-toolkit-featured").length > 0){
      createFeatureSlideshow($(".block-toolkit-featured"));
    }

    //  Toolkits Home Tabs

    if($("#block-views-toolkits-updates-block, #block-views-all-toolkits-block-1").length > 1) {
      createTabbedContent($("#block-views-toolkits-updates-block, #block-views-all-toolkits-block-1"));
      // Set a cookie for the tab so whenever user goes to this page it will remember which tab to shoW
      $(window).bind('hashchange', function() {
        var index = window.location.hash.replace(/[^0-9]/g, '');
        $.cookie('toolkitstab', index);
      });
    }

   }); //document.ready

   function createDropDownNav(menu) {
    /* Get the window's width, and check whether it is narrower than 480 pixels */
    //var windowWidth = $(window).width();
    //if (windowWidth <= 480) {

       /* Clone our navigation */
       var mainNavigation = menu.clone();

       /* Replace unordered list with a "select" element to be populated with options, and create a variable to select our new empty option menu */
       menu.append('<select class="menu" id="navigation-dropdown"></select>');
       var selectMenu = $('select.menu');

       $(selectMenu).append('<option value="" selected="selected">Go To…</option>');
       //$(selectMenu).append('<option value="/">Home</option>');

       /* Navigate our nav clone for information needed to populate options */
       $(mainNavigation).children('ul').children('li').each(function() {

          /* Get top-level link and text */
          var href = $(this).children('a').attr('href');
          var text = $(this).children('a').text();

          /* Append this option to our "select" */
          if(text != "Home"){
            $(selectMenu).append('<option value="'+href+'">'+text+'</option>');
          }

          /* Check for "children" and navigate for more options if they exist */
          if ($(this).children('ul').length > 0) {
             $(this).children('ul').children('li').each(function() {

                /* Get child-level link and text */
                var href2 = $(this).children('a').attr('href');
                var text2 = $(this).children('a').text();

                /* Append this option to our "select" */
                $(selectMenu).append('<option value="'+href2+'">--- '+text2+'</option>');
             });
          }
       });
    //}

    /* When our select menu is changed, change the window location to match the value of the selected option. */
    $(selectMenu).change(function() {
       location = this.options[this.selectedIndex].value;
    });
  }

  function createFeatureSlideshow(t, n) {
    if (!n) {
      n = 3;
    }
    t.data('n', n);
    t.addClass('carousel');
    var slides = t.find("li.views-row");
    if(slides.length > n){
      var slideList = slides.eq(0).parent();
      t.find('.block-content').addClass("sliding");
      slideList.addClass("slider");
      slideList.width((slides.length/n * 100) + "%");
      slideList.wrap("<div class='slider-wrapper'></div>");
      var w = (100/slides.length) + "%";
      slides.each(function(index){
        $(this).width(w);
        $(this).css({"left":(100/slides.length)*index + "%", "top":0});
      });

      var slidernav = $("<div class='slider-nav'></div>");
      slidernav.appendTo($(".slider-wrapper").parent());

      //  Previous Link
      $("<a href='#' class='slide-previous'>Previous</a>").click(function(){
        moveSlider(t, 1);
        return false;
      }).appendTo(slidernav);


      var slidejump = $("<ul class='slide-jump'></ul>");

      var j = 0;
      var total = slides.length/n;
      while(j < total) {
        var item = $("<li class='slide-pager-item'></li>");
        var link = $("<a href='#' class='slide-pager-link'>" + (j+1) + "</a>").data('j', -j).click(function(){
          animateSlider(slideList, $(this).data('j'));
          return false;
        });
        link.appendTo(item);
        item.appendTo(slidejump);
        j++;
      }

      slidejump.appendTo(slidernav);
      $('.slide-pager-item:nth-child(1) .slide-pager-link').addClass("active");

      //  Next Link
      $("<a href='#' class='slide-next'>Next</a>").click(function(){
        moveSlider(t, -1);
        return false;
      }).appendTo(slidernav);

    }
  }

  function moveSlider(t, direction){
    var slider = t.find("ul.slider");
    var wrap = slider.parent();
    var l = slider.position().left/wrap.width();

    var count = Math.round(slider.width()/wrap.width());
    var max = 0;
    var min = -count;

    if(l + direction <= max && l + direction > min) {
      l += direction;
      animateSlider(slider, l);
    }
  }

  function animateSlider(slider, l) {
    if(!slider.hasClass("switching")){
      slider.addClass("switching");
      $('.slide-pager-link.active').removeClass("active");
      $('.slide-pager-item:nth-child(' + ((l * -1) + 1) + ') .slide-pager-link').addClass("active");
      slider.animate({
        left: (100 * l) + "%"
        }, {duration:250, easing:"swing", complete: function(){slider.removeClass("switching");}});
    }
  }

  function createToggleNav(menu) {
    $("<a href='#' class='toggle'><span>More K4Health Websites</span></a>").click(function(){
      menu.toggleClass("hidden");
      $(this).toggleClass("hidden");
    }).appendTo(menu.parent());
    menu.toggleClass("hidden");
  }

  function createTabbedContent(t) {
    t.wrapAll("<div class='tabbed-content'></div>");
    var container = t.eq(0).parent();
    var nav = $("<ul class='tabbed-navigation'></ul>");
    var hash = window.location.hash.replace(/[^0-9]/g, '');
    t.each(function(index){
      $(this).addClass("tabbed");

      var title = $(this).find("h2.block-title").text();
      // console.log(title);
      var item = $("<li></li>");
      // Update url with hash (anchor)
      var link = $("<a onClick='window.location.href=\"#" + index + "\";'>" + title + "</a>").click(function(){
      //var link = $("<a href='#" + index + "'>" + title + "</a>").click(function(){
        setCurrentTab(container, index);
        return false;
      });
      item.append(link);
      item.appendTo(nav);
      // If no hash, get it from cookie, then show tab based on hash
      if(hash==null){
        var hash = $.cookie("toolkitstab");
        if(hash==null){
          var hash = 0;
        }
      }
      if(hash == index){
        $(this).addClass("shown");
        item.addClass("shown");
//      }else if(index == 0){
//        $(this).addClass("shown");
//        item.addClass("shown");
      }
    });
    container.prepend(nav);
  }

  function setCurrentTab(t, i) {
    var nav = t.find("ul.tabbed-navigation");
    t.find(".tabbed").each(function(index){
      $(this).removeClass("shown");
      nav.find("li").eq(index).removeClass("shown");
      if(index == i) {
        $(this).addClass("shown");
        nav.find("li").eq(i).addClass("shown");
      }
    });
  }

     /*----------------------------------------------------------------------------------------------------

   Scroll Updates

   ----------------------------------------------------------------------------------------------------*/

   var updatesScrollFactor = 3;
   var updatesScrolling = false;
   var updatesScrollIndex = 0;

   function scrollUpdates() {
     var content = $(".block-carousel-vertical").find(".view-content");
     content.wrapInner("<div class='view-scrolling-container'><div class='view-scrolling'></div></div>");
     content.find('.view-scrolling-container').css({position: 'relative', height: '272px', overflow: 'hidden' });
     content.find('.view-scrolling').css({position: 'absolute'});
     var previous = $("<a href='#' class='previous'>Previous</a>").click(function(){
       switchUpdates(-1);
       return false;
     });
     var next = $("<a href='#' class='next'>Next</a>").click(function(){
       switchUpdates(1);
       return false;
     });
     content.prepend(previous).append(next);
     switchUpdates(0, true);
   }

   function switchUpdates(dir, force) {
     var newUpdatesScrollIndex = Math.max(0, updatesScrollIndex + dir*updatesScrollFactor);
     if(newUpdatesScrollIndex >= $(".block-carousel-vertical").find(".view-scrolling").find(".views-row").length) {
       newUpdatesScrollIndex -= updatesScrollFactor;
     }
     if((!updatesScrolling && newUpdatesScrollIndex != updatesScrollIndex) || force){
       updatesScrolling = true;
       updatesScrollIndex = newUpdatesScrollIndex;
       if(updatesScrollIndex + updatesScrollFactor >= $(".block-carousel-vertical").find(".view-scrolling").find(".views-row").length) {
         $(".block-carousel-vertical").find(".next").addClass("disabled");
       } else {
         $(".block-carousel-vertical").find(".next").removeClass("disabled");
       }
       if(updatesScrollIndex == 0){
         $(".block-carousel-vertical").find(".previous").addClass("disabled");
       } else {
         $(".block-carousel-vertical").find(".previous").removeClass("disabled");
       }

       var t = -($(".block-carousel-vertical").find(".view-scrolling").find(".views-row").eq(updatesScrollIndex).position().top);

       //  Slide the Updates
       $(".block-carousel-vertical").find(".view-scrolling").animate({
         top: t
       },500, function(){ updatesScrolling = false; })

       //  Fade Out Updates
       $(".block-carousel-vertical").find(".view-scrolling").find(".views-row").each(function(ind){
         var hidden = .5;
         if($.browser.msie) {
           if($.browser.version < 8){
             hidden = 0;
           }
         }
         var a = (ind >= updatesScrollIndex && ind < updatesScrollIndex + updatesScrollFactor) ? 1 : hidden;
         $(this).animate({
           opacity: a
         }, 500);
       })
     }
   }

 })(jQuery); //$

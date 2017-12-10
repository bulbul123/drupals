 /** 
 * Load Google Analytics code for global data repository, external from drupal module
 **/
 (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
 (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
 m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
 })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

 ga('create', 'UA-54574871-1', 'auto', {'name': 'global'});
 ga('global.require', 'displayfeatures');
 ga('global.send', 'pageview');

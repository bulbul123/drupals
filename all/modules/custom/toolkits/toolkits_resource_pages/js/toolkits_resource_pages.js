(function($) {
  Drupal.behaviors.toolkits_resource_pages = {
    attach: function(context, settings) {
			
			var allPages = new Array();
			
			function setPages(method, id, pageMaster) {
				
				// -- Gets all PIDs we want into an array --
				$.get("/resource_pages/"+method+"/"+id, function(data){
					var pageIds = data.split('+');
					var pages = pageMaster.clone();

					pages.children().each(function() {
						if (jQuery.inArray($(this).val(), pageIds) == -1) {
							$(this).remove();
						}	
					});
					$('#edit-field-toolkit-page-und').replaceWith(pages);
				});
				
			}
			
			$(document).ready(function(){
				
				// --- Gets the full list of pages and stores it ---
				allPages = $('#edit-field-toolkit-page-und').clone();
				
				// --- Parse the get string to see if a gid has been passed and pre-filled ---
				var getString = window.location.search;
				getString = getString.replace('?', '');
				getString = getString.replace(/&/g, '=');
				getString = getString.split('=');
				
				// --- Loop through get vaules to see if gid has been set ---
				$.each(getString, function(index, value){
					if (value == 'gids_node[]' || value == 'gids_node%5B%5D') {
						var nid = getString[index+1];
						setPages('nid', nid, allPages);
					}
				});
			});
				
			$('#edit-group-audience-und').change(function(){
				var gid = $(this).val();
				setPages('gid', gid, allPages);	
			});
		} // attach
	}; // Drupal.behaviors
})(jQuery)

function Console(txt){
  if('console' in window && 'log' in window.console)
  {
      if(typeof window.console != 'undefined' && typeof window.console.log != 'undefined')
      {
          console.log(txt);
      }
  }
}

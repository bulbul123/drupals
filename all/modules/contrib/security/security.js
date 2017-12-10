(function ($) {

  /**
   * Core behavior for Security module
   *
   * Attach a listener to the login form and add a submit handler
   */
  Drupal.behaviors.security = {
    attach: function (context, settings) {
      $('.security-user-login-form', context).once(function() {
        $(this).submit(function() {
          $this = $(this);
          $pw_fields = $this.find('input[type=password]');
          $pw_fields.each(function() {
            var hashed = CryptoJS.PBKDF2($(this).val(), Drupal.settings.security.salt, { keySize: Drupal.settings.security.keySize, iterations: Drupal.settings.security.iterations }).toString();
            $(this).val(hashed);
          })
        });
      });
    }
  };

})(jQuery);

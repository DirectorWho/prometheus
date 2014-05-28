(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {
  // Place code below here.

  $(document).ready(function() {

    // Get value of campus type select list and toggle field visibility

    $( "#edit-field-campus-type-und" ).change(function() {
      var currentVal = $( "#edit-field-campus-type-und option:selected" ).text();
      alert( currentValue );
    });

  });

    // end custom jQuery
}
};

})(jQuery, Drupal, this, this.document);

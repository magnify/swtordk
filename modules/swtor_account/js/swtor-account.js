(function ($) {

$(document).ready(function() {
  var account = $('#swtor-account');
  var logout = $('.logout', account);

  function showContent() {
    $('.content', account)
    .show(50)
    $(this)
    .addClass('expanded');

    // Show logout after animation
    logout.show();
  }

  function hideContent() {
    $('.content', account)
    .hide(50)
    $(this)
    .removeClass('expanded');
    
    // Hide logout to avoid animation on show
    logout.show();
  }


  var config = {
    over: showContent, // function = onMouseOver callback (REQUIRED)
    timeout: 500, // number = milliseconds delay before onMouseOut
    out: hideContent // function = onMouseOut callback (REQUIRED)
  };

  account.hoverIntent(config);
  
  // Add click handler.
//  account.click(function() {
//    // Can't use toggle, as logout link floats down (in animation).
//    var content = $('.content', account);
//    if (content.is(":visible")) {
//      account.removeClass('expanded');
//      content.hide();
//    }
//    else {
//      account.addClass('expanded');
//      content.fadeIn();
//    }
//
//    return false;
//  });
});

})(jQuery);
(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {
  // Place code below here.

  $(document).ready(function() {

    //set up variable for mobile. set this to keep track of width so functions are run only on transition from
    // moble to desktop and vice versa. if this isn't done, functions will fire constantly as window is resized
    var mobile = 0;
    // keeps track if function has been run
    var functionStatus = 0;

    function setMobileValue() {
      var viewport = $(window).width();
      if (viewport < 970) {
        mobile = 1;
      }
      else {
        mobile = 0;
      }
    }

    setMobileValue();

    // determine if width is 'mobile' and if function has already been run
    function fireMobileFunctions() {
      if (mobile === 1 && functionStatus == 0) {
        // turn this 'on' so that it doesn't run multiple times during resize
        functionStatus = 1;
        addMobileMenuItem();
        toggleMenu();
        equalHeightColumns();
      }
      else if (mobile === 0 && functionStatus == 1)  {
        //turn 'off' so that it will run again if resized to mobile
        functionStatus = 0;
        removeMobileMenuItem();
        equalHeightColumns();
        // unbind click events from toglleMenu function
        $('.menu-link').unbind();
        $('.menuparent > a').unbind();
        //remove toggled class
        $('a').removeClass('toggled');
      }
    }

    fireMobileFunctions();

    $('body').addClass('js');

    // toggle menu

    // the toggle menu doesn't allow the first element to act as a link - it's instead a toggle.
    // the bit below copies the parent link and adds it to the child ul so that the page is accessible
    function addMobileMenuItem() {
      $links = $('li.menuparent').children('a:first-child');
      if ($links.length > 0){
        $links.each(function(i,link) {
          $(link).next().prepend($('<li></li>').append($(link).clone()))
        })
      }
    }

    //remove any items that have been added on resize when going back to desktop width
    function removeMobileMenuItem() {
      $("li.menuparent").each(function() {
         var menuParent = $(this).children('a').text();
         var firstChildItem = $(this).find("ul li:first-child a").text();
         if (menuParent == firstChildItem){
         $(this).find("ul li:first-child").remove();
         }
      });
    }

function equalHeightColumns() {
  if (mobile === 0) {
    var columnHeight = 0;
    var contentHeight = $('#content').outerHeight();
    var sidebarFirstHeight = $('.region-sidebar-first').outerHeight();
    var sidebarSecondHeight = $('.region-sidebar-second').outerHeight();
    if ((contentHeight > sidebarFirstHeight) && (contentHeight > sidebarSecondHeight)) {
      columnHeight = contentHeight;
    }
    else if ((sidebarFirstHeight > contentHeight) && (sidebarFirstHeight > sidebarSecondHeight)) {
      columnHeight = sidebarFirstHeight;
    }
    else if ((sidebarSecondHeight > contentHeight) && (sidebarSecondHeight > sidebarFirstHeight)) {
      columnHeight = sidebarSecondHeight;
    }
    if (columnHeight < $('.view-school-search .view-data').height()) {
     columnHeight = $('.view-school-search .view-data').height() + 50;
    }
    $('.column').height(columnHeight);
  }
  else {
    $('.column').css('height', 'auto');
  }
}

  window.setTimeout(equalHeightColumns, 75);

    function toggleMenu() {
        // add the toggle classes
  		  var $menu = $('.region-menu .menu'),
    	  $menulink = $('.menu-link'),
    	  $menuTrigger = $('.menuparent > a');

    		$menulink.click(function(e) {
    			e.preventDefault();
    			$menulink.toggleClass('toggled');
    			$menu.toggleClass('toggled');
    		});

    		$menuTrigger.click(function(e) {
    			e.preventDefault();
    			var $this = $(this);
    			$this.toggleClass('toggled').next('ul').toggleClass('toggled');
    		});
    }

      $(window).resize(function() {
        setMobileValue();
        fireMobileFunctions();
      });

  		});

      // start vertiscroll

      /*

Vertiscroll!

a jQuery plugin to style your scrollbars
http://roxon.in/scripts/vertiscroll/

Copyright (c) 2012 Roko Cypryn Buljan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/
(function(a){a.fn.vertiscroll=function(b){var c=a.extend({width:12,areawidth:18,cover:18,color:"#000",background:"transparent",cursor:"n-resize",areacursor:"pointer",radius:"12px 0 0 12px",animate:400,footer:2,fluid:false,hidden:false,mousemove:false,mousemovemode:"default",mousemoveresponse:10},b);return this.each(function(){var K=a(this);K.wrap('<div class="overflow" />');var m=K.css("border-top-right-radius"),d=K.css("border-bottom-right-radius"),z=K.closest(".overflow"),B=K.css("float"),J=["-width","-style","-color"],M=["top","right","bottom","left"],A,g,L,h=false,q=K.innerWidth(),p=parseInt(K.css("padding-right"),10)+parseInt(K.css("padding-left"),10),l=parseInt(K.css("top"),10),t=parseInt(K.css("left"),10),u=a("<div>",{"class":"scrollbar",style:"position:absolute; right:0px; width:"+c.width+"px; cursor:"+c.cursor+"; background-color:"+c.color+";"}).css({borderRadius:c.radius}),w=a("<div>",{"class":"scrollarea",style:"cursor:"+c.areacursor+"; position:absolute; height:100% ;z-index:2; top:0px; right:0px; width:"+c.areawidth+"px; background-color:"+c.background}).css({userSelect:"none"}).append(u).appendTo(z);for(i=0;i<c.footer;i++){K.append("<br />")}for(i=0;i<M.length;i++){var O="",r=K.css("margin-"+M[i]);for(j=0;j<J.length;j++){O+=" "+K.css("border-"+M[i]+""+J[j])}z.css("margin-"+M[i],r).css("border-"+M[i],O)}z.css({overflow:"hidden",position:"relative","float":B,left:t,top:l,borderRadius:"0 "+m+" "+d+" 0"});K.css({overflow:"auto","padding-right":"+="+c.cover,margin:0,border:0,top:0,left:0});function f(){var Q=K.scrollTop();u.css({top:parseInt(Q/g*A,10),height:L})}function o(){A=K.innerHeight();g=K[0].scrollHeight;L=parseInt(A/(g/A),10);z.height(A);if(c.fluid===true){z.css({width:"auto"});K.css({width:z.innerWidth()-p})}else{z.css({width:q})}f();if(g>A){if(c.hidden===false){w.show()}}else{w.hide()}}o();a(window).load(function(){o()}).on("resize focus",function(){o();if(c.fluid===true){K.css({width:z.innerWidth()-p})}});var I=((document.ontouchstart!==null)?"mousedown":"touchstart");var C=((document.ontouchmove!==null)?"mousemove":"touchmove");var P=((document.ontouchend!==null)?"mouseup":"touchend");var e,D,F,s,x;u.on(I,function(Q){Q.preventDefault();Q.stopPropagation();F=w.height();s=u.height();h=true;D=w.offset().top;e=u.offset().top-D;x=Q.pageY-a(this).offset().top;if(I==="touchstart"){x=Q.originalEvent.touches[0].pageY-a(this).offset().top;a(this).css({opacity:0.7})}a(document).on("mousemove touchmove",y);a(document).on(P,function(){a(this).css({opacity:1});N();setTimeout(function(){h=false},24)})});function y(R){var S=R.pageY-D-x;if(C==="touchmove"){var S=R.originalEvent.touches[0].pageY-D-x}S=Math.min(Math.max(0,S),F-s);u.css({top:S,opacity:1});var Q=u.position().top;K.scrollTop(parseInt(Q*g/A,10))}function N(){a(document).off(C,y);a(document).off(P,N)}K.scroll(function(){if(!h){f()}});w.on("click",function(T){T.preventDefault();if(!h){T.stopPropagation();var R=T.pageY-a(this).offset().top,S=L/2,Q=R-S;K.stop().animate({scrollTop:Q*g/A},c.animate)}});if(c.mousemove!==false){var H=0,G=0,v,k,n=0,E=(function(){G+=(H-G)/c.mousemoveresponse;var Q=Math.round(G*((g/A)-1));K.scrollTop(Q)});if(c.mousemovemode!="default"){n=A}K.on("mousemove",function(Q){clearTimeout(k);if(g>A){H=Math.abs(Q.pageY-a(this).offset().top-n)}}).on("mouseenter mouseleave",function(Q){if(Q.type=="mouseenter"&&h!==true){clearInterval(v);v=setInterval(E,15)}else{k=setTimeout(function(){clearInterval(v)},50*c.mousemoveresponse)}})}})}})(jQuery);


      // end vertiscroll

      // call mixitup and vertiscroll
      $(function(){
        alert('hit both');
        $('.view-school-search').mixItUp();
        $('.scrollable').vertiscroll();
      });


    // end custom jQuery
}
};

})(jQuery, Drupal, this, this.document);

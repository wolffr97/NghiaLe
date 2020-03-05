jQuery(document).ready(function() {

    // Active menu
    var pathname = window.location.pathname;
    var id = 'so-do-phong';
    if(pathname.indexOf('hotel') != -1){
        var arr = pathname.split('/');
        id = arr.slice(-1);
    }
    
    /*
    if(id.indexOf('QuestionList') != -1){
        jQuery('#QuestionList').attr('class', 'nav-parent nav-active active');
        jQuery('#' + id).closest('ul').css('display', 'block');
    }
    */
    
    jQuery('#' + id).attr('class', 'active');
    // End active menu
    
    jQuery("div.alert-success").delay(3000).slideUp();
    
    jQuery('#table1').dataTable();
    
    jQuery('#table2').dataTable({
      "sPaginationType": "full_numbers"
    });
    
    // Chosen Select
    jQuery("select").chosen({
      'min-width': '100px',
      'white-space': 'nowrap',
      disable_search_threshold: 10
    });
    
    // Delete row in a table
    jQuery('.delete-row').click(function(){
      var url = window.location.href;
      var deleteId = jQuery(this).attr('id');
      var id = deleteId.split('_')[1];

      var formData = {
            id: id,
            _token: $('input[name=_token').val() // Important
        }

      var c = confirm("Bạn muốn xóa dòng này?");
      if(c)
        $.ajax({
               type:'POST',
               url: url + '/deletePost',
               data: formData,
               success:function(data){
                jQuery('#' + deleteId).closest('tr').fadeOut(function(){
                  jQuery('#' + deleteId).remove();
                });
               }
            });
        
        return false;

    });

    var intputElements = document.getElementsByTagName("input");
    for (var i = 0; i < intputElements.length; i++) {
        intputElements[i].oninvalid = function (e) {
            e.target.setCustomValidity("");
            if (!e.target.validity.valid) {
                e.target.setCustomValidity("This field is required");
            }
        }
    }

    var textAreaElements = document.getElementsByTagName("textarea");
    for (var i = 0; i < textAreaElements.length; i++) {
        textAreaElements[i].oninvalid = function (e) {
            e.target.setCustomValidity("");
            if (!e.target.validity.valid) {
                e.target.setCustomValidity("This field is required");
            }
        }
    }

    jQuery('#print').click(function(){
      var host = window.location.host;
      var pathName = window.location.pathname;
      var params = window.location.search.substr(1).split('&');
      params = params.toString().replace(/\,/g,"&");
      var url = "http://" + host + pathName + "/print?" + params;
      //alert(params);
      //window.location.href = url;
      window.open(url, '_blank');
    });
    
  });
// Date Picker
jQuery('#datepickerTuNgay').datepicker();
jQuery('#datepickerDenNgay').datepicker();


function format_curency(a) {
    var money = a.value.replace(/\./g, "");
    var isNum = /^\d+$/.test(money);
    var num = parseInt(money);

    if (!isNum || num < 1) {
        money = "";
    }

    a.value = money.replace(/(\d)(?=(\d{3})+(?!\d))/g, "$1.");
}

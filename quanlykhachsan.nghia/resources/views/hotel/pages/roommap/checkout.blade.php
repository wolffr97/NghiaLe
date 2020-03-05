@extends('hotel.templates.template')

@section('title', 'Trả phòng')

@section('main_content')
<link href="{{url('/')}}/resources/assets/css//bootstrap-datetimepicker.css" rel="stylesheet">
<script src="{{url('/')}}/resources/assets/js/moment-with-locales.js"></script>
<script src="{{url('/')}}/resources/assets/js/bootstrap-datetimepicker.js"></script>
<div class="row">
    <div class="col-md-12">
        <form id="basicForm" class="form-horizontal" method="POST">
            <div class="panel panel-default">
                <div class="panel-heading">
                    <div class="panel-btns">
                        <a href="" class="minimize">−</a>
                    </div>
                    <h1 class="panel-title">TRẢ PHÒNG</h1>
                </div>
                <input type="hidden" name="_token" value="{!! csrf_token() !!}" />
                @if(count($errors) > 0)
                <div class="alert alert-danger">
                    <ul>
                        @foreach($errors->all() as $error)
                            {!! $error !!}
                        @endforeach
                    </ul>
                </div>
                @endif
                <div class="panel-body">
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Tên phòng</label>
                        <label class="col-sm-3 control-label">
                            <strong style="font-size: 25px;">{!! $hotelRoom->name !!}</strong>
                        </label>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-2 control-label">Giá phòng</label>
                        <label class="col-sm-3 control-label">
                            <strong>{!! number_format($hotelRoom->cost) !!} VND</strong>
                        </label>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-2 control-label">Thời gian đến</label>
                        <label class="col-sm-3 control-label">
                            <strong>{!! $hotelRoom->time_in !!}</strong>
                        </label>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-2 control-label">Thời gian trả phòng</label>
                        <label class="col-sm-3 control-label">
                            <strong>{!! $hotelRoom->time_out !!}</strong>
                        </label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Loại đặt phòng</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->rent_type !!}</label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Số lượng (ngày/giờ)</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->rent_num !!}</label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Tên khách hàng</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->customerName !!}</label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Giới tính</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->gender !!}</label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Số CMND/Passport</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->identifier !!}</label>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Địa chỉ</label>
                        <label class="col-sm-3 control-label">{!! $hotelRoom->address !!}</label>
                    </div>
                </div>
                <!-- panel-body -->
                <div class="panel-footer">
                    <div class="row">
                        <div class="col-sm-12">
                            <h1 class="panel-title">PHỤ THU</h1>
                            <div class="form-group">
                                <label class="col-sm-2 control-label">Tên<span class="asterisk">*</span></label>
                                <div class="col-sm-4">
                                    <input type="text" name="nameVal" id="nameVal" class="form-control" placeholder="Tên sản phẩm" oninput="not_input_blank(this);" required="required">
                                </div>
                            </div>
                            <div class="form-group">
                                <label class="col-sm-2 control-label">Giá<span class="asterisk">*</span></label>
                                <div class="col-sm-4">
                                    <input type="text" name="priceVal" id="priceVal" class="form-control" placeholder="Giá" oninput="format_curency(this);" required="required">
                                </div>
                            </div>
                            <div class="form-group">
                                <label class="col-sm-2 control-label">Số lượng<span class="asterisk">*</span></label>
                                <div class="col-sm-4">
                                    <input type="number" min="1" step="1" name="numVal" id="numVal" class="form-control" placeholder="Số lượng" oninput="validatedPositiveNum(this);" value="1" required="required">
                                </div>
                            </div>
                            <div class="form-group" id="group-btn-extras">
                                <div class="col-sm-6" style="text-align:center;">
                                    <button class="btn btn-primary" id="btnExtras">Thêm</button>
                                </div>
                            </div>
                            <!--
                            <div class="table-responsive">
                                <table class="table">
                                    <thead>
                                        <tr>
                                            <th style="background-color: #428BCA; color: #FFF;">Tên</th>
                                            <th style="background-color: #428BCA; color: #FFF;">Giá</th>
                                            <th style="background-color: #428BCA; color: #FFF;">Số lượng</th>
                                            <th style="background-color: #428BCA; color: #FFF;"></th>
                                        </tr>
                                    </thead>
                                    <tbody id="table-extras">
                                    </tbody>
                                </table>
                            </div>
                            -->
                            <!-- table-responsive -->
                        </div>
                    </div>
                </div>
                <div class="panel-footer" style="text-align: center;">
                    <div class="row">
                        <div class="col-sm-6 col-sm-offset-3">
                            <button class="btn btn-primary" id="btn-save">LƯU</button>
                        </div>
                    </div>
                </div>
            </div>
            <!-- panel -->
            <!-- Hidden value -->
            <input type="hidden" name="idList" id="idList"/>
            <input type="hidden" name="nameList" id="nameList"/>
            <input type="hidden" name="priceList" id="priceList"/>
            <input type="hidden" name="numList" id="numList"/>
            <input type="hidden" name="rent_num" value="{!! $hotelRoom->rent_num !!}"/>
            <input type="hidden" name="cost" value="{!! $hotelRoom->cost !!}"/>
            <input type="hidden" name="time_out" value="{!! $hotelRoom->time_out !!}"/>
            <!-- End hidden value -->
            
        </form>
    </div>
</div>
<script type="text/javascript">
    /*
    $(function () {
        $('#from-datetimepicker').datetimepicker({
            locale: 'vi'
        });
        
        $('#to-datetimepicker').datetimepicker({
            useCurrent: false,
            locale: 'vi'
        });
        
        $("#from-datetimepicker").on("dp.change", function (e) {
            $('#to-datetimepicker').data("DateTimePicker").minDate(e.date);
        });
        
        $("#to-datetimepicker").on("dp.change", function (e) {
            $('#from-datetimepicker').data("DateTimePicker").maxDate(e.date);
        });
    });
    */
    function format_curency(a) {
        var money = a.value.replace(/\./g, "");
        var isNum = /^\d+$/.test(money);
        var num = parseInt(money);

        if (!isNum || num < 1) {
            money = "";
        }

        if(num > 100000000){
            money = '100000000';
        }

        a.value = money.replace(/(\d)(?=(\d{3})+(?!\d))/g, "$1.");
    }

    function not_input(a) {
        a.value = '';
    }

    function not_input_blank(a) {
        if(a.value == ' ') a.value = '';
    }

    function validatedPositiveNum(a) {
        var isNum = /^\d+$/.test(a.value);
        var num = parseInt(a.value);

        if (!isNum || num < 1) {
            a.value = '';
        }

        if (num > 10000){
            a.value = '10000';
        }
    }

    $('#btn-save').on('click', function(){
        $('#nameVal').removeAttr('required');
        $('#priceVal').removeAttr('required');
        $('#numVal').removeAttr('required');
        $("#basicForm").submit();
    });
    
    /**
    * Add extras price
    */
    $(function(){
        $('#btnExtras').on('click', function(e){
            // Validate blank value
            var nameVal = $('#nameVal').val().replace(',', '');
            var priceVal = $('#priceVal').val().replace('.', '').replace(',', '');
            var numVal = $('#numVal').val();
            if(!nameVal || !priceVal || !numVal) return;

            var newId = 1;
            var idList = $("#idList").val();
            var arrIdList = [];
            if (!!idList){
                arrIdList = idList.split(",");
                arrIdList = arrIdList.sort();
                var maxVal = arrIdList.slice(-1);
                newId = parseInt(maxVal) + 1;
            }
            arrIdList.push(newId);
            $('#idList').val(arrIdList.join());
            
            var nameList = $("#nameList").val();
            var arrNameList = [];
            if (!!nameList) arrNameList = nameList.split(",");
            arrNameList.push(nameVal);
            $('#nameList').val(arrNameList.join());

            var priceList = $("#priceList").val();
            var arrPriceList = [];
            if (!!priceList) arrPriceList = priceList.split(",");
            arrPriceList.push(priceVal);
            $('#priceList').val(arrPriceList.join());

            var numVal = $('#numVal').val();
            var numList = $("#numList").val();
            var arrNumList = [];
            if (!!numList) arrNumList = numList.split(",");
            arrNumList.push(numVal);
            $('#numList').val(arrNumList.join());

            // Create table
            if(arrNumList.length == 1){
                var tableHtml = '<div class="table-responsive">'
                    + 	 '			<table class="table">'
                    + 	 '				<thead>'
                    + 	 '					<tr>'
                    +    '						<th style="background-color: #428BCA; color: #FFF;">Tên</th>'
                    +    '						<th style="background-color: #428BCA; color: #FFF;">Giá</th>'
                    +    '    					<th style="background-color: #428BCA; color: #FFF;">Số lượng</th>'
                    +    '    					<th style="background-color: #428BCA; color: #FFF;">Tổng</th>'
                    +    '    					<th style="background-color: #428BCA; color: #FFF;"></th>'
                    +    '					</tr>'
                    +    '				</thead>'
                    +    '				<tbody id="table-extras"></tbody>'
                    +    '			</table>'
                    +    '		</div>';
                $(tableHtml).insertAfter("#group-btn-extras");
            }
            var priceSum = parseInt(priceVal) * parseInt(numVal);

            priceVal = priceVal.replace(/(\d)(?=(\d{3})+(?!\d))/g, "$1.");
            priceSum = priceSum.toString().replace(/(\d)(?=(\d{3})+(?!\d))/g, "$1.");
            
            var tr = '<tr class="tr-extras">'
                    + '<td>' + nameVal + '</td>'
                    + '<td>' + priceVal + ' VND</td>'
                    + '<td>' + numVal + '</td>'
                    + '<td><strong>' + priceSum + '</strong> VND</td>'
                    + '<td class="table-action">'
                    +		'<span class="delete-row" id="delete-extras-' + newId + '">'
                    +			'<i class="fa fa-trash-o"></i>'
                    +		'</span>'
                    +	'</td>'
                    +'</tr>';
            // Add new tr: name, price, number
            $('#table-extras').append(tr);

            //  Prevent form submit
            e.preventDefault();
            $('#nameVal').val('');
            $('#priceVal').val('');
            $('#numVal').val('1');
            
        })

        // Handle delete row extra
        $(document).on('click', 'span[id^=delete-extras]', function(){
            var id = $(this).attr('id').split('-').slice(-1);
            
            if($('.tr-extras').length == 1){// If it have one row
                $('#idList').val('');
                $('#nameList').val('');
                $('#priceList').val('');
                $('#numList').val('');

                // Hide table
                $('.table-responsive').remove();
            }else{// More
                
                var idList = $("#idList").val();
                var arrIdList = [];
                if (!!idList) arrIdList = idList.split(",");
                var index = arrIdList.indexOf(id);
                if(index > -1) arrIdList.splice(index, 1);
                $('#idList').val(arrIdList.join());

                var nameList = $("#nameList").val();
                var arrNameList = [];
                if (!!nameList) arrNameList = nameList.split(",");
                if(index > -1) arrNameList.splice(index, 1);
                $('#nameList').val(arrNameList.join());

                var priceList = $("#priceList").val();
                var arrPriceList = [];
                if (!!priceList) arrPriceList = priceList.split(",");
                if(index > -1) arrPriceList.splice(index, 1);
                $('#priceList').val(arrPriceList.join());

                var numList = $("#numList").val();
                var arrNumList = [];
                if (!!numList) arrNumList = numList.split(",");
                if(index > -1) arrNumList.splice(index, 1);
                $('#numList').val(arrNumList.join());
            }
                
            // Remove row
            $(this).closest('tr').remove();
        })
    });
</script>
@endsection

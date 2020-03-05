@extends('hotel.templates.template') @section('title', 'Đặt phòng')

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
                    <h1 class="panel-title">ĐẶT PHÒNG</h1>
                </div>
                <input type="hidden" name="_token" value="{!! csrf_token() !!}" />
                <div class="panel-body">
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Tên phòng</label>
                        <div class="col-sm-9">
                            <label class="col-sm-3 control-label">
                                <strong style="font-size: 25px;">{!! $data->hotelRoomName !!}</strong>
                            </label>
                        </div>
                    </div>

                    <div class="table-responsive" style="text-align: center;">
                        <table class="table">
                            <thead>
                                <tr>
                                    <th style="background-color: #428BCA; color: #FFF; text-align: center;">Loại phòng</th>
                                    <th style="background-color: #428BCA; color: #FFF; text-align: center;">Theo ngày</th>
                                    <th style="background-color: #428BCA; color: #FFF; text-align: center;">Giờ đầu</th>
                                    <th style="background-color: #428BCA; color: #FFF; text-align: center;">Giờ tiếp theo</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>{!! $data->hotelPriceName !!} VND</td>
                                    <td>{!! number_format($data->price_day) !!} VND</td>
                                    <td>{!! number_format($data->price_hour) !!} VND</td>
                                    <td>{!! number_format($data->price_hour_next) !!} VND</td>
                                </tr>
                            </tbody>
                        </table>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Loại đặt phòng<span
                            class="asterisk">*</span></label>
                        <div class="col-sm-9">
                            <select class="form-control input-sm mb15" name="rent_type">
                                <option value="0">Theo ngày</option>
                                <option value="1">Theo giờ</option>
                            </select>
                        </div>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Số lượng (ngày/giờ)</label>
                        <div class="col-sm-9">
                            <input type="number" min="1" name="rent_num" class="form-control" placeholder="Số lượng" value="1" oninput="input_unsigned(this);"/>
                        </div>
                    </div>
                    <!-- table-responsive -->
                    <!--
                    <div class="form-group">
                        <label class="col-sm-2 control-label">Giá phòng<span class="asterisk">*</span>
                        </label>
                        <div class="col-sm-9">
                            <input type="text" name="score" class="form-control" placeholder="Giá phòng" required value="{!! old('score') !!}" oninput="format_curency(this);"/>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-2 control-label">Thời gian đến</label>
                        <div class='col-sm-9 input-group date' id='from-datetimepicker'>
                            <input type='text' name="time_in" id="time_in" class="form-control" placeholder="Thời gian đến" oninput="not_input(this);"/>
                            <span class="input-group-addon">
                                <span class="glyphicon glyphicon-calendar"></span>
                            </span>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-2 control-label">Thời gian trả phòng</label>
                        <div class='col-sm-9 input-group date' id='to-datetimepicker'>
                            <input type='text' name="time_out" id="time_out" class="form-control" placeholder="Thời gian trả phòng" oninput="not_input(this);"/>
                            <span class="input-group-addon">
                                <span class="glyphicon glyphicon-calendar"></span>
                            </span>
                        </div>
                    </div>
                    -->
                </div>
                <div class="form-group">
                    <label class="col-sm-2 control-label">Tên khách hàng<span class="asterisk">*</span></label>
                    <div class="col-sm-9">
                        <input type="text" name="name" class="form-control" placeholder="Tên khách hàng" oninput="not_input_blank(this);" required="required">
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-sm-2 control-label">Giới tính<span
                        class="asterisk">*</span></label>
                    <div class="col-sm-9">
                        <select class="form-control input-sm mb15" name="gender">
                            <option value="1">Nam</option>
                            <option value="0">Nữ</option>
                            <option value="2">Chưa xác định</option>
                        </select>
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-sm-2 control-label">Số CMND/Passport<span class="asterisk">*</span></label>
                    <div class="col-sm-9">
                        <input type="text" name="identifier" class="form-control" placeholder="Số CMND/Passport" oninput="not_input_blank(this);" required="required">
                    </div>
                </div>
                <div class="form-group">
                    <label class="col-sm-2 control-label">Địa chỉ</label>
                    <div class="col-sm-9">
                        <input type="text" name="address" class="form-control" placeholder="Địa chỉ" oninput="not_input_blank(this);">
                    </div>
                </div>
                <!-- panel-body -->
                <div class="panel-footer" style="text-align: center;">
                    <div class="row">
                        <div class="col-sm-6 col-sm-offset-3">
                            <button class="btn btn-primary">Lưu</button>
                            <button type="reset" class="btn btn-default">Reset</button>
                        </div>
                    </div>
                </div>
            </div>
            <!-- panel -->
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
        a.value = "";
    }

    function input_unsigned(val){
        var isNum = /^\d+$/.test(val.value);
        var num = parseInt(val.value);

        if (!isNum || num < 1) {
            val.value = "";
        }

        if(num > 1000){
            val.value = '1000';
        }
    }

    function not_input_blank(a) {
        if(a.value == ' ') a.value = '';
    }
</script>
@endsection

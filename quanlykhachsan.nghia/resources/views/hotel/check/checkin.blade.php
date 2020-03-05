@extends('hotel.templates.template')

@section('title', 'Hotel Management')

@section('main_content')
<div class="row">
  <!-- <div class="panel panel-default">
    <div class="panel-body">
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Phòng</label>
          <div class="col-sm-8">
            <select class="form-control" data-placeholder="Chọn phòng">
              <option value=""></option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
              <option value="United States">Phòng 1</option>
            </select>
          </div>
        </div>
      </div>
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Tình trạng</label>
          <div class="col-sm-8">
            <select class="form-control" data-placeholder="Tình trạng phòng...">
              <option value=""></option>
              <option value="United States">Đang ở</option>
              <option value="United States">Hết giờ</option>
            </select>
          </div>
        </div>
      </div>
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Từ ngày</label>
          <div class="col-sm-8">
            <div class="input-group">
                <input type="text" class="form-control" placeholder="mm/dd/yyyy" id="datepickerTuNgay">
                <span class="input-group-addon"><i class="glyphicon glyphicon-calendar"></i></span>
              </div>
          </div>
        </div>
      </div>
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Đến ngày</label>
          <div class="col-sm-8">
            <div class="input-group">
                <input type="text" class="form-control" placeholder="mm/dd/yyyy" id="datepickerDenNgay">
                <span class="input-group-addon"><i class="glyphicon glyphicon-calendar"></i></span>
              </div>
          </div>
        </div>
      </div>
    </div>
  </div> -->
  <div class="row">
    <div class="col-sm-12 col-lg-12">
        <div class="panel panel-default">
            <div class="panel-body">
                <div class="table-responsive">
                  <table class="table" id="table2">
                    <thead>
                      <tr>
                        <th style="background-color: #428BCA; color: #FFF;">#</th>
                        <th style="background-color: #428BCA; color: #FFF;">Tên phòng</th>
                        <th style="background-color: #428BCA; color: #FFF;">Loại thuê</th>
                        <th style="background-color: #428BCA; color: #FFF;">Thời gian vào</th>
                        <th style="background-color: #428BCA; color: #FFF;">Thời gian đã thuê</th>
                        <th style="background-color: #428BCA; color: #FFF;">Đơn giá</th>
                      </tr>
                    </thead>
                    <tbody>
                      @foreach($data as $key=>$item)
                        <tr>
                          <td>{!! $key + 1 !!}</td>
                          <td>{!! $item['name'] !!}</td>
                          <td>{!! $item['rent_type'] !!}</td>
                          <td>{!! $item['time_in'] !!}</td>
                          <td>{!! $item['rent_num'] !!}</td>
                          <td>{!! number_format($item['cost']) !!} VND</td>
                        </tr>
                      @endforeach
                    </tbody>
                 </table>
                </div><!-- table-responsive -->
                
            </div><!-- panel-body -->
        </div><!-- panel -->
        
    </div><!-- col-sm-9 -->
    
</div><!-- row -->

</div>
@endsection
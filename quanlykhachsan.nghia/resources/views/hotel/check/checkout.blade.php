@extends('hotel.templates.template')

@section('title', 'Hotel Management')

@section('main_content')
<div class="row">
<div class="panel panel-default">
  <form id="search" method="GET" action="{!! url('/') !!}/hotel/checkout">
    <div class="panel-body">
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Phòng</label>
          <div class="col-sm-8">
            <select class="form-control" data-placeholder="Tìm kiếm" name="room">
              <option value="-1">Tất cả</option>
              @foreach($rooms as $key=>$item)
                <option value="{!! $item['id'] !!}" {!! ($roomSearch == $item['id'] ? 'selected' : '') !!}>{!! $item['name'] !!}</option>
              @endforeach
            </select>
          </div>
        </div>
      </div>
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Loại thuê</label>
          <div class="col-sm-8">
            <select class="form-control" data-placeholder="Loại thuê..." name="rent_type">
              <option value="-1" {!! ($rentTypeSearch == '-1' ? 'selected' : '') !!}>Tất cả</option>
              <option value="1" {!! ($rentTypeSearch == '1' ? 'selected' : '') !!}>ĐẶT GIỜ</option>
              <option value="0" {!! ($rentTypeSearch == '0' ? 'selected' : '') !!}>ĐẶT NGÀY</option>
            </select>
          </div>
        </div>
      </div>
      <hr>
      <div class="col-sm-6">
        <div class="form-group">
          <label class="col-sm-2 control-label">Từ ngày</label>
          <div class="col-sm-8">
            <div class="input-group">
                <input type="text" class="form-control" placeholder="mm/dd/yyyy" id="datepickerTuNgay" name="fromDate" value="{!! $fromDateSearch !!}">
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
                <input type="text" class="form-control" placeholder="mm/dd/yyyy" id="datepickerDenNgay" name="toDate" value="{!! $toDateSearch !!}">
                <span class="input-group-addon"><i class="glyphicon glyphicon-calendar"></i></span>
              </div>
          </div>
        </div>
      </div>
      <div class="col-sm-12">
        <br />
      </div>
      
      <div class="col-sm-12">
        <div class="form-group" style="text-align:center">
          <button class="btn btn-primary">Search</button>
        </div>
      </div>
    </div>
  </form>
  </div> 
  <div class="row">
    <div class="col-sm-12 col-lg-12">
        <div class="panel panel-default">
            <div class="panel-body">
                <div class="table-responsive">
                  <div class="span11" style="float: right; margin-bottom: 20px">
                      <fieldset>
                          <a id="print" class="btn btn-info" target="_blank"><i class="glyphicon glyphicon-print" ></i>&nbsp&nbspIn&nbsp&nbsp&nbsp&nbsp&nbsp</a>
                      </fieldset>
                  </div>
                    <table class="table" id="table2">
                    <thead>
                      <tr>
                        <th style="background-color: #428BCA; color: #FFF;">#</th>
                        <th style="background-color: #428BCA; color: #FFF;">Tên phòng</th>
                        <th style="background-color: #428BCA; color: #FFF;">Loại thuê</th>
                        <th style="background-color: #428BCA; color: #FFF;">Đơn giá</th>
                        <th style="background-color: #428BCA; color: #FFF;">Thời gian vào</th>
                        <th style="background-color: #428BCA; color: #FFF;">Thời gian ra</th>
                        <th style="background-color: #428BCA; color: #FFF;">Thời gian đã thuê</th>
                        <th style="background-color: #428BCA; color: #FFF;">Phụ thu</th>
                        <th style="background-color: #428BCA; color: #FFF;">Tổng giá</th>
                      </tr>
                    </thead>
                    <tbody>
                      @foreach($data as $key=>$item)
                        <tr>
                          <td>{!! $key + 1 !!}</td>
                          <td>{!! $item['roomName'] !!}</td>
                          <td>{!! $item['rent_type'] !!}</td>
                          <td>{!! number_format($item['cost']) !!} VND</td>
                          <td>{!! $item['time_in'] !!}</td>
                          <td>{!! $item['time_out'] !!}</td>
                          <td>{!! $item['rent_num'] !!}</td>
                          <td>{!! number_format($item['extraCost']) !!} VND</td>
                          <td>{!! number_format($item['allCost']) !!} VND</td>
                        </tr>
                      @endforeach
                    </tbody>
                 </table>
                </div><!-- table-responsive -->
              <hr>
              <h3>Thống kê doanh thu: </h3>
              <table class="table">
                <tr>
                  <td>Số lượng checkout</td>
                  <td>{!! count($data) !!}</td>
                </tr>
                <tr>
                  <td>Tổng doanh thu phòng</td>
                  <td>{!! number_format($revenue_room) !!} VND</td>
                </tr>
                <tr>
                  <td>Tổng phụ thu</td>
                  <td>{!! number_format($revenue_extra) !!} VND</td>
                </tr>
                <tr>
                  <td>Tổng cộng</td>
                  <td>{!! number_format($revenue_all) !!} VND</td>
                </tr>
              </table>  
            </div><!-- panel-body -->
        </div><!-- panel -->
        
    </div><!-- col-sm-9 -->
    
</div><!-- row -->

</div>
@endsection
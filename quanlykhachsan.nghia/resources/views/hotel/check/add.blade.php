@extends('hotel.templates.template')

@section('title', 'Hotel Management')

@section('main_content')
<div class="row">
  <div class="col-md-12">
    <form id="form1" class="form-horizontal" method="POST">
      <div class="panel panel-default">
        <div class="panel-heading">
          <br/>
          <div>
            <h4 class="panel-title">Thêm giá phòng mới</h4>
            <input type="hidden" name="_token" value="{!! csrf_token() !!}"/>
          </div>
          <br/>
        </div>
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
            <label class="col-sm-2">Tên:</label>
            <div class="col-sm-10">
              <input type="text" name="txtName" class="form-control" required/>
            </div>
          </div>
          <div class="form-group">
            <label class="col-sm-2">Giá theo ngày:</label>
            <div class="col-sm-10">
              <input type="number" name="txtPriceDay" class="form-control" required/>
            </div>
          </div>
          <div class="form-group">
            <label class="col-sm-2">Giá giờ đầu:</label>
            <div class="col-sm-10">
              <input type="number" name="txtPriceHour" class="form-control" required/>
            </div>
          </div>
          <div class="form-group">
            <label class="col-sm-2">Giá giờ tiếp theo:</label>
            <div class="col-sm-10">
              <input type="number" name="txtPriceHourNext" class="form-control" required/>
            </div>
          </div>
        </div><!-- panel-body -->
        <div class="panel-footer" style="text-align: center;">
          <button class="btn btn-primary">Submit</button>
        </div><!-- panel-footer -->
      </div><!-- panel-default -->
    </form>
      
  </div>
</div>
@endsection
@extends('hotel.templates.template')

@section('title', 'Hotel Management')

@section('main_content')
<div class="col-md-12">
  <h1 class="subtitle mb5" style="text-align: center; font-size: 30px;" >Quản lý giá phòng</h1>
  <div>
    <a href="price/add" class="btn btn-primary">Thêm</a>
  </div>
  <input type="hidden" name="_token" value="{!! csrf_token() !!}"/>
  <div class="clearfix mb30"></div>
    <div class="table-responsive">
    <table class="table" id="table2">
        <thead>
          <tr>
            <th style="background-color: #428BCA; color: #FFF;">#</th>
            <th style="background-color: #428BCA; color: #FFF;">Tên</th>
            <th style="background-color: #428BCA; color: #FFF;">Giá theo ngày</th>
            <th style="background-color: #428BCA; color: #FFF;">Giá giờ đầu</th>
            <th style="background-color: #428BCA; color: #FFF;">Giá giờ tiếp theo</th>
            <th style="background-color: #428BCA; color: #FFF;"></th>
          </tr>
        </thead>
        <tbody>
          @foreach($data as $key=>$item)
            <tr>
              <td>{!! $key + 1 !!}</td>
              <td>{!! $item['name'] !!}</td>
              <td>{!! number_format($item['price_day']) !!} VND</td>
              <td>{!! number_format($item['price_hour']) !!} VND</td>
              <td>{!! number_format($item['price_hour_next']) !!} VND</td>
              <td class="table-action">
                <a href="price/edit/{!! $item['id'] !!}"><i class="fa fa-pencil"></i></a>
                <a href="price/delete/{!! $item['id'] !!}" class="delete-row" onclick="return confirm('Bạn có chắc muốn xóa không?');"><i class="fa fa-trash-o"></i></a>
              </td>
            </tr>
            @endforeach
        </tbody>
     </table>
    </div><!-- table-responsive -->
</div>
@endsection

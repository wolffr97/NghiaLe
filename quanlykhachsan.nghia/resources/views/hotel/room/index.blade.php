@extends('hotel.templates.template') @section('title', 'Hotel
Management') @section('main_content')
<!-- Script
<script src="{{url('/')}}/public/app/lib/angular.min.js"></script>
<script src="{{url('/')}}/public/app/app.js"></script>
<script src="{{url('/')}}/public/app/controllers/HotelRoomController.js"></script>
End script -->
<div class="col-md-12">
    <h1 class="subtitle mb5" style="text-align: center; font-size: 30px;">Quản
        lý phòng</h1>
    <div>
        <a href="room/add" class="btn btn-primary">Thêm</a>
    </div>
    <div class="clearfix mb30"></div>
    <div class="table-responsive">
        <table class="table" id="table2">
            <thead>
                <tr>
                    <th style="background-color: #428BCA; color: #FFF;">#</th>
                    <th style="background-color: #428BCA; color: #FFF;">Tên phòng</th>
                    <th style="background-color: #428BCA; color: #FFF;"></th>
                </tr>
            </thead>
            <tbody>
                @foreach($data as $key=>$item)
                <tr>
                    <td>{!! $key + 1 !!}</td>
                    <td>{!! $item['name'] !!}</td>
                    <td class="table-action">
                        <a href="room/edit/{!! $item['id'] !!}">
                            <i class="fa fa-pencil"></i>
                        </a>
                        <a href="room/delete/{!! $item['id'] !!}" class="delete-row" onclick="return confirm('Bạn có chắc muốn xóa không?');"><i class="fa fa-trash-o"></i></a>
                    </td>
                </tr>
                @endforeach
            </tbody>
        </table>
    </div>
    <!-- table-responsive -->
</div>
@endsection

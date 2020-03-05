@extends('hotel.templates.template')

@section('title', 'Không tìm thấy đường dẫn')

@section('main_content')
<div class="w3-row w3-margin-bottom">
    <div class="w3-col l12 w3-center" style="padding:3%">
        <h2>SORRY :( ĐƯỜNG DẪN KHÔNG TỒN TÀI</h2>
        <a href="{{url('/')}}/hotel"><strong>Quay lại trang chủ</strong></a>
    </div>
</div>
@endsection

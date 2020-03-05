@extends('hotel.templates.template') @section('title', 'Hotel
Management') @section('main_content')
<div class="row">
    <div class="col-md-12">
        <form id="form1" class="form-horizontal" method="POST">
            <div class="panel panel-default">
                <div class="panel-heading">
                    <br />
                    <div>
                        <h4 class="panel-title">Thêm phòng mới</h4>
                        <input type="hidden" name="_token" value="{!! csrf_token() !!}" />
                    </div>
                    <br />
                </div>
                @if(count($errors) > 0)
                <div class="alert alert-danger">
                    <ul>@foreach($errors->all() as $error) {!! $error !!} @endforeach
                    </ul>
                </div>
                @endif
                <div class="panel-body">
                    <div class="col-sm-12">
                        <label class="col-sm-2 control-label">Tên phòng</label>
                        <div class="col-sm-8">
                            <input type="text" class="form-control" name="txtName" required />
                        </div>
                    </div>
                    <div class="col-sm-12">
                        <br />
                    </div>
                    <div class="col-sm-12">
                        <label class="col-sm-2 control-label">Giá phòng</label>
                        <div class="col-sm-8">
                            <select class="form-control" name="price">
                              @foreach($prices as $key=>$item)
                                <option value="{!! $item['id'] !!}">{!! $item['name'] !!}</option>
                              @endforeach
                            </select>
                        </div>
                    </div>
                </div>
                <!-- panel-body -->
                <div class="panel-footer" style="text-align: center;">
                    <button class="btn btn-primary">Submit</button>
                </div>
                <!-- panel-footer -->
            </div>
            <!-- panel-default -->
        </form>

    </div>
</div>
@endsection

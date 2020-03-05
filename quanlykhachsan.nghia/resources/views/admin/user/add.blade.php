@extends('danhmuc.danhmuc')
@section('header')
<section class="nav nav-page">
<div class="container">
<div class="row">
    <div class="span7">
        <header class="page-header">
            <h3>Quản lý User<br/>
                <small>Thêm</small>
            </h3>
        </header>
    </div>
    
</div>
</div>
</section>
@stop
@section('content')
<section>
    <div class="container">
        <form action="{!! route('admin.user.addGet') !!}" method="POST">
            <input type="hidden" name="_token" value="{!! csrf_token() !!}" />
            <div class="row">
                        <div class="form-group">
                            <label class="col-md-4 control-label">Tên</label>
                            <div class="col-md-6">
                                <input type="text" class="form-control" name="txtName" value="{{ old('txtName') }}">
                                <div>
                                {!! $errors->first('txtName') !!}
                            </div>
                            </div>
                        </div>
                        <div class="form-group">
                            <label class="col-md-4 control-label">Email</label>
                            <div class="col-md-6">
                                <input type="text" class="form-control" name="txtEmail" value="{{ old('txtEmail') }}">
                                <div>
                                {!! $errors->first('txtEmail') !!}
                            </div>
                            </div>
                        </div>
                        <div class="form-group">
                            <label class="col-md-4 control-label">Mật khẩu</label>
                            <div class="col-md-6">
                                <input type="password" class="form-control" name="password">
                                <div>
                                {!! $errors->first('password') !!}
                            </div>
                            </div>
                        </div>

                        <div class="form-group">
                            <label class="col-md-4 control-label">Xác nhận lại mật khẩu</label>
                            <div class="col-md-6">
                                <input type="password" class="form-control" name="password_confirmation">
                                <div>
                                {!! $errors->first('password_confirmation') !!}
                            </div>
                            </div>
                        </div>

                        
                        <div class="control-group ">
                            <label class="control-label">Loại quản lý</label>
                            <div class="col-md-6">
                                <select class="form-control" name="manageType">
                                    @foreach($manageType as $item)
                                      <option value="{!! $item['id'] !!}">{!! $item['name'] !!}</option>
                                    @endforeach
                                </select>
                            </div>
                        </div>
                        
                </div>
            <footer id="submit-actions" class="form-actions">
                <button id="submit-button" type="submit" class="btn btn-primary" name="action" value="CONFIRM"><i class="icon-save"></i>&nbsp&nbspLưu&nbsp&nbsp</button>
                <a href="{!! URL::route('admin.user.index') !!}" class="btn"><i class="icon-remove"></i>&nbsp&nbspHủy&nbsp&nbsp</a>
            </footer>
        </form>
    </div>
</section>
@stop

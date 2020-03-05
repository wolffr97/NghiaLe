@extends('danhmuc.danhmuc')
@section('header')
<section class="nav nav-page">
                        <div class="container">
<div class="row">
                                <div class="span7">
                                    <header class="page-header">
                                        <h3>Quản lý Khách sạn<br/>
                                            <small>Sửa</small>
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
            <form action="" method="POST">
            <input type="hidden" name="_token" value="{!! csrf_token() !!}" />
            <div id="acct-password-row" class="span7">
                <fieldset>
                    <div class="control-group ">
                        <label class="control-label">Tên Khách sạn</label>
                        <div class="controls">
                            <input id="new-pass-control" name="txtName" class="span4" type="text" value="{!! $data->name !!}" autocomplete="false">
                            <div>
                                {!! $errors->first('txtName') !!}
                            </div>
                        </div>
                    </div>
                    <div class="control-group ">
                        <label class="control-label">Địa chỉ</label>
                        <div class="controls">
                            <input id="new-pass-control" name="txtAddr" class="span4" type="text" value="{!! $data->address !!}" autocomplete="false">
                            <div>
                                {!! $errors->first('txtAddr') !!}
                            </div>
                        </div>
                    </div>
                    <div class="control-group ">
                        <label class="control-label">Số điện thoại</label>
                        <div class="controls">
                            <input id="new-pass-control" name="txtPhone" class="span4" type="number" value="{!! $data->phone !!}" autocomplete="false">
                            <div>
                                {!! $errors->first('txtPhone') !!}
                            </div>
                        </div>
                    </div>
                    <div class="control-group ">
                        <label class="control-label">Email</label>
                        <div class="controls">
                            <input id="new-pass-control" name="txtEmail" class="span4" type="text" value="{!! $data->email !!}" autocomplete="false">
                            <div>
                                {!! $errors->first('txtEmail') !!}
                            </div>
                        </div>
                    </div>
                </fieldset>
                <footer id="submit-actions" class="form-actions">
                    <button id="submit-button" type="submit" class="btn btn-primary" name="action" value="CONFIRM"><i class="icon-save"></i>&nbsp&nbspLưu&nbsp&nbsp</button>
                        <a href="{!! URL::route('danhmuc.khuvuc.getList') !!}" class="btn"><i class="icon-remove"></i>&nbsp&nbspHủy&nbsp&nbsp</a>
                </footer>
            </div>
            </form>
        </div>
    </section>
@stop

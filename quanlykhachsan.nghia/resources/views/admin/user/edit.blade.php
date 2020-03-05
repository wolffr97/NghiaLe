@extends('danhmuc.danhmuc')
@section('header')
<section class="nav nav-page">
    <div class="container">
        <div class="row">
            <div class="span7">
                <header class="page-header">
                    <h3>Quản lý User<br/>
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
                <div class="row">
                    <div id="acct-verify-row" class="span9">
                        <div class="control-group ">
                            <label class="control-label">Tên</label>
                            <div class="controls">
                                <input id="current-pass-control" name="txtName" class="span4" type="text" value="{!! $user->name !!}">
                                <div>
                                    {!! $errors->first('txtName') !!}
                                </div>
                            </div>
                        </div>
                        <div class="control-group ">
                            <label class="control-label">Email</label>
                            <div class="controls">
                                <input id="current-pass-control" name="txtEmail" class="span4" type="text" value="{!! $user->email !!}">
                                <div>
                                    {!! $errors->first('txtEmail') !!}
                                </div>
                            </div>
                        </div>
                        <div class="control-group ">
                            <label class="control-label">Loại quản lý</label>
                            <div class="controls">
                                <select class="span4" name="manageType">
                                    @foreach($manageType as $item)
                                      <option value="{!! $item['id'] !!}" {!! ($user->manage_type_id == $item['id'] ? 'selected' : '') !!}>{!! $item['name'] !!}</option>
                                    @endforeach
                                </select>
                            </div>
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

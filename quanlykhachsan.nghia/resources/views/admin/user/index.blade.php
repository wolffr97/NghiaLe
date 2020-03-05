@extends('danhmuc.danhmuc')
@section('header')
<section class="nav nav-page">
    <div class="container">
        <div class="row">
            <div class="span7">
                <header class="page-header">
                    <h3>Quản lý User<br/>
                        <small></small>
                    </h3>
                </header>
            </div>                      
        </div>
    </div>
</section>

@stop
@section('content')
<div class="span16" >
        <div class="box-header">
            <div class="row">
                <div class="span11">
                    <fieldset>
                        <a href="{!! URL::route('admin.user.addGet') !!}" class="btn btn-info"><i class="icon-plus"></i>&nbspThêm</a>
                        <a href="#" class="btn btn-info"><i class="icon-print"></i>&nbsp&nbspIn&nbsp&nbsp&nbsp&nbsp&nbsp</a>
                    </fieldset>
                </div>
                <div class="" >
                    <fieldset>
                        <input id="current-pass-control" name="" class="span4" type="text" value="" autocomplete="false">
                        <a href="#" class="btn btn-info" style="margin-top: -8px"><i class="icon-search"></i>Tìm kiếm</a>
                    </fieldset>
                </div>
            </div>
            
        </div>
        <table class="table table-bordered table-hover tablesorter" id="sample-table">
            <thead style="background:#EFEFEF;">
                <tr>
                    <th class="span">Tên User</th>
                    <th class="span">Email</th>
                    <th class="span">Quyền</th>
                    <th class="span">Loại quản lý</th>
                    <th class="span"></th>
                </tr>
            </thead>
            <tbody>
            @foreach ($users as $item)
            <tr>
                    <td>{!! $item->name !!}</td>
                    <td>{!! $item->email !!}</td>
                    @if($item->role_id == '1')
                        <td>Admin</td>
                    @else
                        <td>Quản lý</td>
                    @endif
                    <td>{!! $item->manageType !!}</td>
                    
                    <td class="td-actions">
                        <a href="{!! URL::route('admin.user.editGet' , $item->id) !!}" class="btn btn-small btn-info"><i class="btn-icon-only icon-edit"></i></a>
                        <a onclick="return confirmDel('Bạn có chắc muốn xóa dữ liệu này?')"  href="{!! URL::route('admin.user.deleteGet',$item->id) !!}" class="btn btn-small btn-danger">
                            <i class="btn-icon-only icon-remove"></i>

                        </a>
                    </td>
                </tr>
            @endforeach    
            </tbody>
        </table>
    </div>
@stop

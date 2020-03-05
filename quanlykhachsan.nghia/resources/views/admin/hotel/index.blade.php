@extends('danhmuc.danhmuc')
@section('header')
<section class="nav nav-page">
    <div class="container">
        <div class="row">
            <div class="span7">
                <header class="page-header">
                    <h3>Quản lý Khách sạn<br/>
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
                        <a href="{!! URL::route('admin.hotel.addGet') !!}" class="btn btn-info"><i class="icon-plus"></i>&nbspThêm</a>
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
        <div class="table-responsive">
            <table class="table" id="table2">
            <!-- <table class="table table-bordered table-hover tablesorter" id="sample-table"> -->
                <thead style="background:#EFEFEF;">
                    <tr>
                        <th class="span3">Tên Khách sạn</th>
                        <th>Địa chỉ</th>
                        <th>Số điện thoại</th>
                        <th>Email</th>
                        <th class="span2"></th>
                    </tr>
                </thead>
                <tbody>
                @foreach ($hotel as $item)
                <tr>
                        <td>{!! $item->name !!}</td>
                        <td>{!! $item->address !!}</td>
                        <td>{!! $item->phone !!}</td>
                        <td>{!! $item->email !!}</td>
                        <td class="td-actions">
                            <a href="{!! URL::route('admin.hotel.editGet' , $item->id) !!}" class="btn btn-small btn-info"><i class="btn-icon-only icon-edit"></i></a>

                            <a href="{!! URL::route('admin.hotel.deleteGet',$item->id) !!}" class="btn btn-small btn-danger delete-row">
                                <i class="btn-icon-only icon-remove"></i>
                            </a>
                        </td>
                    </tr>
                @endforeach    
                </tbody>
            </table>
        </div>
    </div>
@stop

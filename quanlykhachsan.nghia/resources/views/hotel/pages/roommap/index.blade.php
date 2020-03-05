@extends('hotel.templates.template')

@section('title', 'SƠ ĐỒ PHÒNG')

@section('main_content')
<div class="row">
    @foreach($data as $key => $item)
    <a href="so-do-phong/{!! $item['url'] !!}/{!! $item['id'] !!}">
        <div class="col-sm-6 col-md-3">
            <div class="panel panel-{!! $item['class'] !!} panel-stat">
                <div class="panel-heading">
                    <div class="stat">
                        <div class="row">
                            <div class="col-xs-4">
                                <img src="{{url('/')}}/resources/assets/images/is-document.png" alt="">
                            </div>
                            <div class="col-xs-8">
                                <small class="stat-label">{!! $item['name'] !!}</small>
                                <h4>{!! $item['order'] !!}</h4>
                            </div>
                        </div>
                        <!-- row -->
                        <div class="mb15"></div>
                        <div class="row">
                            <div class="col-xs-6">
                                <small class="stat-label">Thời gian vào</small>
                                <h4>{!! $item['time_in'] !!}</h4>
                            </div>
                            <div class="col-xs-6">
                                <small class="stat-label">Loại đặt phòng</small>
                                <h4>{!! $item['rent_type'] !!}</h4>
                                <h4>{!! $item['rent_num'] !!}</h4>
                            </div>
                        </div>
                        <!-- row -->
                    </div>
                    <!-- stat -->
                </div>
                <!-- panel-heading -->
            </div>
            <!-- panel -->
        </div>
    </a>
    @endforeach
</div>
<script type="text/javascript">
    $(function(){
        setTimeout(function(){ location.reload();; }, 5 * 60 * 1000);
    });
</script>
@endsection

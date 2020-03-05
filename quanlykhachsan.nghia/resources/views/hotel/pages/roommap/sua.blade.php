@extends('hotel.templates.template')

@section('title', 'Balo English')
@section('controller', 'User')

@section('main_content')
<div class="row">
  <div class="col-md-12">
    <form id="form1" class="form-horizontal" method="POST">
      <div class="panel panel-default">
        <div class="panel-heading">
          <h4 class="panel-title" style="text-align: center;">Edit class</h4>
          <input type="hidden" name="_token" value="{!! csrf_token() !!}"/>
        </div>
        @if(count($errors) > 0)
          <div class="alert alert-danger">
            <ul>
              @foreach($errors->all() as $error)
                {!! $error !!}
              @endforeach
            </ul>
          </div>
        @endif
        <div class="panel-body">
        
          <div class="form-group">
            <label class="col-sm-2">Lesson name <span class="asterisk">*</span></label>
            <div class="col-sm-10">
              <input type="text" name="name" class="form-control" required value="{!! old('name',isset($data) ? $data['name'] : null) !!}"/>
            </div>
          </div>
          <div class="form-group">
                    <label class="col-sm-2">Class</label>
                    <div class="col-sm-9">
                      <select class="form-control input-sm mb15" name="class_id">
                        @foreach($class as $item)
                          <option value="{!! $item['id'] !!}" {!! ($data['class_id'] == $item['id'] ? 'selected' : '') !!}>{!! $item['name'] !!}</option>
                        @endforeach
                      </select>
                    </div>
                  </div>
        </div><!-- panel-body -->
        <div class="panel-footer" style="text-align: center;">
          <button class="btn btn-primary">Submit</button>
        </div><!-- panel-footer -->
      </div><!-- panel-default -->
    </form>
      
  </div>
</div>
@endsection

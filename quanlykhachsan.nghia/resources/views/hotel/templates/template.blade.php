<!DOCTYPE html>
<html lang="en">
    @include('hotel.widgets.header')
    <body>
            <section>
                @include('hotel.widgets.leftmenu')
                  <div class="mainpanel">
                      @include('hotel.widgets.barheader')
                    <div class="col-lg-12">
                        <!--
                        @if(Session::has('flash-message'))
                            <br />
                            <div class="alert alert-{!! Session::get('flash-type') !!}">
                                {!! Session::get('flash-message') !!}
                            </div>
                        @endif
                        -->
                    </div>
                    <div class="contentpanel">
                         @yield('main_content')
                    </div><!-- contentpanel -->
                </div><!-- mainpanel -->
                  @include('hotel.widgets.rightpanel')
            </section>
        <script src="{{url('/')}}/resources/assets/js/myscript.js"></script>
    </body>
</html>

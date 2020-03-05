<!DOCTYPE html>
<html lang="en">
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
    
    <title>PHẦN MỀM QUẢN LÝ</title>

    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <meta name="layout" content="main"/>
    
    <script type="text/javascript" src="http://www.google.com/jsapi"></script>

    <script src="{{ url('public/lib/js/jquery/jquery-1.12.3.min.js')}}" type="text/javascript" ></script>

    <link href="{{ url('public/lib/css/customize-template.css')}}" type="text/css" media="screen, projection" rel="stylesheet" />

</head>
    <body>
        <div id="body-container">
            <div id="body-content">
                <div class='container' >
                    <div class="signin-row row" >
                        <div class="span3"></div>
                            <div class="span10">
                                <div class="container-signin" style="margin-top: -30px; text-align: center;">
                                    <!--<img src="{{ url('public/lib/images/logologin.png')}}" width="300px" height="50px" alt="">-->
                                    <legend>PHẦN MỀM QUẢN LÝ</legend>
                                    @if (count($errors) > 0)
                                        <div class="alert alert-danger">
                                            Có lỗi trong quá trình đăng nhập:<br/>
                                                @foreach ($errors->all() as $error)
                                                    {{ $error }}
                                                @endforeach
                                        </div>
                                    @endif
                                    <form  method='POST' id='loginForm' class='form-signin' autocomplete='off' action="{{ url('/auth/login') }}">
                                        <input type="hidden" name="_token" value="{{ csrf_token() }}">
                                        <div class="form-inner">
                                            <div class="input-prepend">
                                                <span class="add-on" rel="tooltip" title="" data-placement="top"><i class="icon-user"></i>&nbsp&nbspTài khoản</span>
                                                <input type="email" class="form-control" name="username" value="{{ old('username') }}">
                                            </div>

                                            <div class="input-prepend">
                                                <span class="add-on"><i class="icon-key" style="margin-left:4px;">&nbspMật khẩu</i></span>
                                                <input type="password" class="form-control" name="password">
                                            </div>
                                            <!-- <label class="checkbox" for='remember_me'>
                                                <input type="checkbox" name="remember">Ghi nhớ tài khoản và mật khẩu
                                            </label> -->
                                        </div>
                                        <footer class="signin-actions">
                                            <button type="submit" class="btn btn-info" style="margin-left: 20px">
                                                <i class="icon-ok"></i>&nbsp&nbspĐồng ý
                                            </button>
                                        </footer>
                                    </form>
                                </div>
                            </div>
                        <div class="span3"></div>
                    </div>
                </div>
            </div>
        </div>
        <div id="spinner" class="spinner" style="display:none;">
            Loading&hellip;
        </div>
    </body>
</html>

<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.
|
*/

// Route::get('/', 'WelcomeController@index');

Route::controllers([
    'auth' => 'Auth\AuthController',
    'password' => 'Auth\PasswordController',
]);

$this->get('logout', 'Auth\AuthController@logout');
Route::group(['middleware' => 'auth'], function() {
    Route::get('home',['as' => 'home','uses' => 'WelcomeController@index']);
    Route::get('danhmuc',['as' => 'danhmuc.danhmuc','uses' => 'WelcomeController@danhmuc']);
    Route::get('hethong',['as' => 'hethong.hethong', 'uses' => 'WelcomeController@hethong']);
    Route::get('chucnang', ['as' => 'chucnang.chucnang', 'uses' => 'WelcomeController@chucnang']);
    Route::get('trogiup', ['as' => 'trogiup.trogiup', 'uses' => 'WelcomeController@trogiup']);

//Hệ thống
Route::group(['prefix' => 'hethong'], function() {
    Route::get('/', function ()
    {
        return view('hethong.hethong');
    });

    Route::group(['prefix' => 'thongtincongty'], function() {
        Route::get('thongtincongty',['as' => 'hethong.thongtincongty.getList','uses' => 'ThongtincongtyController@getList']);
        Route::get('themthongtincongty', ['as' => 'hethong.thongtincongty.getAdd','uses' => 'ThongtincongtyController@getAdd']);
        Route::post('themthongtincongty', ['as' => 'hethong.thongtincongty.getAdd','uses' => 'ThongtincongtyController@postAdd']);
        Route::get('suathongtincongty/{id}', ['as' => 'hethong.thongtincongty.getEdit','uses' => 'ThongtincongtyController@getEdit']);
        Route::post('suathongtincongty/{id}', ['as' => 'hethong.thongtincongty.postEdit','uses' => 'ThongtincongtyController@postEdit']);

    });

    Route::group(['prefix' => 'taotaikhoan'], function() {

        Route::get('taotaikhoan', ['as' => 'hethong.taotaikhoan.getList','uses' => 'TaotaikhoanController@getList']);
    
    });

    Route::group(['prefix' => 'phanquyen'], function() {
        Route::get('phanquyen', ['as' => 'hethong.phanquyen.getList','uses' => 'PhanquyenController@getList']);
        Route::get('themphanquyen', ['as' => 'hethong.phanquyen.getAdd','uses' => 'PhanquyenController@getAdd']);
        Route::get('suaphanquyen', ['as' => 'hethong.phanquyen.getEdit','uses' => 'PhanquyenController@getEdit']);
    });

    Route::group(['prefix' => 'doimatkhau'], function() {
        Route::get('doimatkhau', ['as' => 'hethong.doimatkhau.getEdit','uses' => 'DoimatkhauController@getEdit']);
        Route::post('doimatkhau', ['as' => 'hethong.doimatkhau.postEdit','uses' => 'DoimatkhauController@postEdit']);
    });
});


//Danh mục
Route::group(['prefix' => 'danhmuc'], function() {
    Route::get('/', function ()
    {
        return view('danhmuc.danhmuc');
    });
    
    Route::group(['prefix' => 'vattu'], function() {
        Route::get('vattu',['as' => 'danhmuc.vattu.getList','uses' => 'VattuController@getList']);
        Route::get('themvattu',['as' => 'danhmuc.vattu.getAdd','uses' => 'VattuController@getAdd']);
        Route::post('themvattu', ['as' => 'danhmuc.vattu.postAdd','uses' => 'VattuController@postAdd']);
        Route::get('suavattu/{id}', ['as' => 'danhmuc.vattu.getEdit','uses' => 'VattuController@getEdit']);
        Route::post('suavattu/{id}', ['as' => 'danhmuc.vattu.postEdit','uses' => 'VattuController@postEdit']);
        Route::get('xoavattu/{id}', ['as' => 'danhmuc.vattu.getDelete','uses' => 'VattuController@getDelete']);
        Route::get('in', ['as' => 'danhmuc.vattu.getPDF','uses' => 'VattuController@getPDF']);
    });

    Route::group(['prefix' => 'khuvuc'], function() {
        Route::get('khuvuc', ['as' => 'danhmuc.khuvuc.getList','uses' => 'KhuvucController@getList']);
        Route::get('themkhuvuc', ['as' => 'danhmuc.khuvuc.getAdd','uses' => 'KhuvucController@getAdd']);
        Route::post('themkhuvuc', ['as' => 'danhmuc.khuvuc.postAdd','uses' => 'KhuvucController@postAdd']);
        Route::get('suakhuvuc/{id}', ['as' => 'danhmuc.khuvuc.getEdit','uses' => 'KhuvucController@getEdit']);
        Route::post('suakhuvuc/{id}', ['as' => 'danhmuc.khuvuc.postEdit','uses' => 'KhuvucController@postEdit']);
        Route::get('xoakhuvuc/{id}', ['as' => 'danhmuc.khuvuc.getDelete','uses' => 'KhuvucController@getDelete']);
    });

    Route::group(['prefix' => 'nhasanxuat'], function() {
        Route::get('nhasanxuat', ['as' => 'danhmuc.nhasanxuat.getList','uses' => 'NhasanxuatController@getList']);
        Route::get('themnhasanxuat', ['as' => 'danhmuc.nhasanxuat.getAdd','uses' => 'NhasanxuatController@getAdd']);
        Route::post('themnhasanxuat', ['as' => 'danhmuc.nhasanxuat.postAdd','uses' => 'NhasanxuatController@postAdd']);
        Route::get('suanhasanxuat/{id}', ['as' => 'danhmuc.nhasanxuat.getEdit','uses' => 'NhasanxuatController@getEdit']);
        Route::post('suanhasanxuat/{id}', ['as' => 'danhmuc.nhasanxuat.postEdit','uses' => 'NhasanxuatController@postEdit']);
        Route::get('xoanhasanxuat/{id}', ['as' => 'danhmuc.nhasanxuat.getDelete','uses' => 'NhasanxuatController@getDelete']);
    });

    Route::group(['prefix' => 'nhaphanphoi'], function() {
        Route::get('nhaphanphoi', ['as' => 'danhmuc.nhaphanphoi.getList','uses' => 'NhaphanphoiController@getList']);
        Route::get('themnhaphanphoi', ['as' => 'danhmuc.nhaphanphoi.getAdd','uses' => 'NhaphanphoiController@getAdd']);
        Route::post('themnhaphanphoi', ['as' => 'danhmuc.nhaphanphoi.postAdd','uses' => 'NhaphanphoiController@postAdd']);
        Route::get('suanhaphanphoi/{id}', ['as' => 'danhmuc.nhaphanphoi.getEdit','uses' => 'NhaphanphoiController@getEdit']);
        Route::post('suanhaphanphoi/{id}', ['as' => 'danhmuc.nhaphanphoi.postEdit','uses' => 'NhaphanphoiController@postEdit']);
        Route::get('xoanhaphanphoi/{id}', ['as' => 'danhmuc.nhaphanphoi.getDelete','uses' => 'NhaphanphoiController@getDelete']);
    });

    Route::group(['prefix' => 'chatluong'], function() {
        Route::get('chatluong', ['as' => 'danhmuc.chatluong.getList','uses' => 'ChatluongController@getList']);
        Route::get('themchatluong', ['as' => 'danhmuc.chatluong.getAdd','uses' => 'ChatluongController@getAdd']);
        Route::post('themchatluong', ['as' => 'danhmuc.chatluong.postAdd','uses' => 'ChatluongController@postAdd']);
        Route::get('suachatluong/{id}', ['as' => 'danhmuc.chatluong.getEdit','uses' => 'ChatluongController@getEdit']);
        Route::post('suachatluong/{id}', ['as' => 'danhmuc.chatluong.postEdit','uses' => 'ChatluongController@postEdit']);
        Route::get('xoachatluong/{id}', ['as' => 'danhmuc.chatluong.getDelete','uses' => 'ChatluongController@getDelete']);
    });

    Route::group(['prefix' => 'congtrinh'], function() {
        Route::get('congtrinh', ['as' => 'danhmuc.congtrinh.getList','uses' => 'CongtrinhController@getList']);
        Route::get('themcongtrinh', ['as' => 'danhmuc.congtrinh.getAdd','uses' => 'CongtrinhController@getAdd']);
        Route::post('themcongtrinh', ['as' => 'danhmuc.congtrinh.postAdd','uses' => 'CongtrinhController@postAdd']);
        Route::get('suacongtrinh/{id}', ['as' => 'danhmuc.congtrinh.getEdit','uses' => 'CongtrinhController@getEdit']);
        Route::post('suacongtrinh/{id}', ['as' => 'danhmuc.congtrinh.postEdit','uses' => 'CongtrinhController@postEdit']);
        Route::get('xoacongtrinh/{id}', ['as' => 'danhmuc.congtrinh.getDelete','uses' => 'CongtrinhController@getDelete']);
    });

    Route::group(['prefix' => 'donvitinh'], function() {
        Route::get('donvitinh', ['as' => 'danhmuc.donvitinh.getList','uses' => 'DonvitinhController@getList']);
        Route::get('themdonvitinh', ['as' => 'danhmuc.donvitinh.getAdd','uses' => 'DonvitinhController@getAdd']);
        Route::post('themdonvitinh', ['as' => 'danhmuc.donvitinh.postAdd','uses' => 'DonvitinhController@postAdd']);
        Route::get('suadonvitinh/{id}', ['as' => 'danhmuc.donvitinh.getEdit','uses' => 'DonvitinhController@getEdit']);
        Route::post('suadonvitinh/{id}', ['as' => 'danhmuc.donvitinh.postEdit','uses' => 'DonvitinhController@postEdit']);
        Route::get('xoadonvitinh/{id}', ['as' => 'danhmuc.donvitinh.getDelete','uses' => 'DonvitinhController@getDelete']);
    });

    Route::group(['prefix' => 'nhomvattu'], function() {
        Route::get('nhomvattu', ['as' => 'danhmuc.nhomvattu.getList','uses' => 'NhomvattuController@getList']);
        Route::get('themnhomvattu', ['as' => 'danhmuc.nhomvattu.getAdd','uses' => 'NhomvattuController@getAdd']);
        Route::post('themnhomvattu', ['as' => 'danhmuc.nhomvattu.postAdd','uses' => 'NhomvattuController@postAdd']);
        Route::get('suanhomvattu/{id}', ['as' => 'danhmuc.nhomvattu.getEdit','uses' => 'NhomvattuController@getEdit']);
        Route::post('suanhomvattu/{id}', ['as' => 'danhmuc.nhomvattu.postEdit','uses' => 'NhomvattuController@postEdit']);
        Route::get('xoanhomvattu/{id}', ['as' => 'danhmuc.nhomvattu.getDelete','uses' => 'NhomvattuController@getDelete']);
    });

    Route::group(['prefix' => 'mucdich'], function() {
        Route::get('mucdich', ['as' => 'danhmuc.mucdich.getList','uses' => 'MucdichController@getList']);
        Route::get('themmucdich', ['as' => 'danhmuc.mucdich.getAdd','uses' => 'MucdichController@getAdd']);
        Route::get('suamucdich', ['as' => 'danhmuc.mucdich.getEdit','uses' => 'MucdichController@getEdit']);
    });

    Route::group(['prefix' => 'phongban'], function() {
        Route::get('phongban', ['as' => 'danhmuc.phongban.getList','uses' => 'PhongbanController@getList']);
        Route::get('themphongban', ['as' => 'danhmuc.phongban.getAdd','uses' => 'PhongbanController@getAdd']);
        Route::post('themphongban', ['as' => 'danhmuc.phongban.postAdd','uses' => 'PhongbanController@postAdd']);
        Route::get('suaphongban/{id}', ['as' => 'danhmuc.phongban.getEdit','uses' => 'PhongbanController@getEdit']);
        Route::post('suaphongban/{id}', ['as' => 'danhmuc.phongban.postEdit','uses' => 'PhongbanController@postEdit']);
        Route::get('xoaphongban/{id}', ['as' => 'danhmuc.phongban.getDelete','uses' => 'PhongbanController@getDelete']);
    });

    Route::group(['prefix' => 'nhanvien'], function() {
        Route::get('nhanvien', ['as' => 'danhmuc.nhanvien.getList','uses' => 'NhanvienController@getList']);
        Route::get('themnhanvien', ['as' => 'danhmuc.nhanvien.getAdd','uses' => 'NhanvienController@getAdd']);
        Route::post('themnhanvien', ['as' => 'danhmuc.nhanvien.postAdd','uses' => 'NhanvienController@postAdd']);
        Route::get('suanhanvien/{id}', ['as' => 'danhmuc.nhanvien.getEdit','uses' => 'NhanvienController@getEdit']);
        Route::post('suanhanvien/{id}', ['as' => 'danhmuc.nhanvien.postEdit','uses' => 'NhanvienController@postEdit']);
        Route::get('xoanhanvien/{id}', ['as' => 'danhmuc.nhanvien.getDelete','uses' => 'NhanvienController@getDelete']);
    });

    Route::group(['prefix' => 'user'], function() {
        Route::get('', ['as' => 'admin.user.index','uses' => 'UserController@index']);
        Route::get('add', ['as' => 'admin.user.addGet','uses' => 'UserController@addGet']);
        Route::post('add', ['as' => 'admin.user.addPost','uses' => 'UserController@addPost']);
        Route::get('edit/{id}', ['as' => 'admin.user.editGet','uses' => 'UserController@editGet']);
        Route::post('edit/{id}', ['as' => 'admin.user.editPost','uses' => 'UserController@editPost']);
        Route::get('delete/{id}', ['as' => 'admin.user.deleteGet','uses' => 'UserController@deleteGet']);
    });

    Route::group(['prefix' => 'kho'], function() {
        Route::get('kho', ['as' => 'danhmuc.kho.getList','uses' => 'KhoController@getList']);
        Route::get('themkho', ['as' => 'danhmuc.kho.getAdd','uses' => 'KhoController@getAdd']);
        Route::post('themkho', ['as' => 'danhmuc.kho.postAdd','uses' => 'KhoController@postAdd']);
        Route::get('suakho/{id}', ['as' => 'danhmuc.kho.getEdit','uses' => 'KhoController@getEdit']);
        Route::post('suakho/{id}', ['as' => 'danhmuc.kho.postEdit','uses' => 'KhoController@postEdit']);
        Route::get('xoakho/{id}', ['as' => 'danhmuc.kho.getDelete','uses' => 'KhoController@getDelete']);
    });

    Route::group(['prefix' => 'hotel'], function() {
        Route::get('', ['as' => 'admin.hotel.index','uses' => 'HotelController@index']);
        Route::get('add', ['as' => 'admin.hotel.addGet','uses' => 'HotelController@addGet']);
        Route::post('add', ['as' => 'admin.hotel.addPost','uses' => 'HotelController@addPost']);
        Route::get('edit/{id}', ['as' => 'admin.hotel.editGet','uses' => 'HotelController@editGet']);
        Route::post('edit/{id}', ['as' => 'admin.hotel.editPost','uses' => 'HotelController@editPost']);
        Route::get('delete/{id}', ['as' => 'admin.hotel.deleteGet','uses' => 'HotelController@deleteGet']);
    });
});


//Chuc nang
Route::group(['prefix' => 'chucnang'], function() {
    Route::get('/', function ()
    {
        return view('chucnang.chucnang');
    });

    Route::group(['prefix' => 'nhapkho'], function() {
        Route::get('xem-theo-chung-tu', ['as' => 'chucnang.nhapkho.danhsach','uses' => 'NhapkhoController@getDanhsach']);
        Route::get('nhapkho', ['as' => 'chucnang.nhapkho.getList','uses' => 'NhapkhoController@getList']);
        Route::post('nhapkho', ['as' => 'chucnang.nhapkho.postList','uses' => 'NhapkhoController@postList']);
        Route::get('themnhapkho', ['as' => 'chucnang.nhapkho.getAdd','uses' => 'NhapkhoController@getAdd']);
        
        Route::get('suanhapkho/{id}', ['as' => 'chucnang.nhapkho.getEdit','uses' => 'NhapkhoController@getEdit']);
        Route::post('suanhapkho/{id}', ['as' => 'chucnang.nhapkho.postEdit','uses' => 'NhapkhoController@postEdit']);

        Route::get('xoanhapkho/{id}', ['as' => 'chucnang.nhapkho.getDelete','uses' => 'NhapkhoController@getDelete']);
        Route::get('xem-theo-vat-tu', ['as' => 'chucnang.nhapkho.getVattu','uses' => 'NhapkhoController@getVattu']);
        //Ajax Nha phan phoi - Nhap kho
        Route::get('nhaphanphoi/ajax-call', function(){
            $state_id = Input::get('state_id');
            $city = DB::table('nhaphanphoi')->where('id',$state_id)->get();
            return Response::json($city);
        });
        //Ajax Vật tư - Nhập kho
        Route::get('vattu/ajax-call', function(){
            $vattu_id = Input::get('vattu_id');
            $country = DB::table('vattu')
                ->where('vattu.id',$vattu_id)
                ->join('donvitinh','donvitinh.id','=','vattu.dvt_id')
                ->select('vattu.*','donvitinh.dvt_ten')
                ->get();
            return Response::json($country);
        });

        Route::get('nhaphang/{id}/{qty}', ['as' => 'chucnang.nhapkho.postNhaphang','uses' => 'NhapkhoController@postNhaphang']);

         Route::get('sua-theo-vat-tu/{id}', ['as' => 'chucnang.nhapkho.getEdit1','uses' => 'NhapkhoController@getEdit1']);
        Route::post('sua-theo-vat-tu/{id}', ['as' => 'chucnang.nhapkho.postEdit1','uses' => 'NhapkhoController@postEdit1']);

        Route::get('xoavattu/{id}/{ad}', ['as' => 'chucnang.nhapkho.getDeletePro','uses' => 'NhapkhoController@getDeletePro']);

        Route::get('suavattu/{id}/{ad}', ['as' => 'chucnang.nhapkho.getEditPro','uses' => 'NhapkhoController@getEditPro']);

        Route::get('in/{id}', ['as' => 'chucnang.nhapkho.getPDF','uses' => 'NhapkhoController@getPDF']);

    });

    Route::group(['prefix' => 'xuatkho'], function() {
        Route::get('xuatkho', ['as' => 'chucnang.xuatkho.getList','uses' => 'XuatkhoController@getList']);
        Route::post('xuatkho', ['as' => 'chucnang.xuatkho.postList','uses' => 'XuatkhoController@postList']);
        Route::get('themxuatkho', ['as' => 'chucnang.xuatkho.getAdd','uses' => 'XuatkhoController@getAdd']);
        
        Route::get('suaxuatkho/{id}', ['as' => 'chucnang.xuatkho.getEdit','uses' => 'XuatkhoController@getEdit']);
        Route::post('suaxuatkho/{id}', ['as' => 'chucnang.xuatkho.postEdit','uses' => 'XuatkhoController@postEdit']);

        Route::get('xemtheovattu', ['as' => 'chucnang.xuatkho.getVattu','uses' => 'XuatkhoController@getVattu']);
        Route::get('xemtheochungtu', ['as' => 'chucnang.xuatkho.getChungtu','uses' => 'XuatkhoController@getChungtu']);
        
         //Ajax Vật tư - Xuất kho
        Route::get('vattu/ajax-call', function(){
            $vattu_id = Input::get('vattu_id');
            // $country = DB::table('vattu')
            //     ->where('vattu.id',$vattu_id)
            //     ->join('donvitinh','donvitinh.id','=','vattu.dvt_id')
            //     ->select('vattu.*','donvitinh.dvt_ten')
            //     ->get();
            $country = DB::table('vattukho')
            ->where('vattukho.vt_id',$vattu_id)
            ->join('vattu','vattu.id','=','vattukho.vt_id')
            ->join('kho','kho.id','=','vattukho.kho_id')
            ->join('donvitinh','donvitinh.id','=','vattu.dvt_id')
            ->select('vattu.vt_ten','donvitinh.dvt_ten','kho.kho_ten','vattukho.vt_id','kho.id')
            ->get();
            // $city = DB::table('kho')
            //     ->where('vattukho.vt_id',$vattu_id)
            //     ->join('vattukho','vattukho.kho_id','=','kho.id')
            //     ->select('kho.id','kho.kho_ten')
            //     ->get();
            return Response::json($country);
        });

        Route::get('xuathang/{id}/{qty}', ['as' => 'chucnang.xuatkho.postXuathang','uses' => 'XuatkhoController@postXuathang']);
        Route::get('xoaxuatkho/{id}', ['as' => 'chucnang.xuatkho.getDelete','uses' => 'XuatkhoController@getDelete']);

        Route::get('sua-theo-vat-tu/{id}', ['as' => 'chucnang.xuatkho.getEdit1','uses' => 'XuatkhoController@getEdit1']);
        Route::post('sua-theo-vat-tu/{id}', ['as' => 'chucnang.xuatkho.postEdit1','uses' => 'XuatkhoController@postEdit1']);

        Route::get('xoavattu/{id}/{ad}', ['as' => 'chucnang.xuatkho.getDeletePro','uses' => 'XuatkhoController@getDeletePro']);

        Route::get('suavattu/{id}/{ad}', ['as' => 'chucnang.xuatkho.getEditPro','uses' => 'XuatkhoController@getEditPro']);

    });

    Route::group(['prefix' => 'thekho'], function() {
        //
    });



    Route::group(['prefix' => 'chuyenkho'], function() {
        Route::get('chuyenkho', ['as' => 'chucnang.chuyenkho.getList','uses' => 'ChuyenkhoController@getList']);
        Route::post('chuyenkho', ['as' => 'chucnang.chuyenkho.postList','uses' => 'ChuyenkhoController@postList']);
        Route::get('themchuyenkho', ['as' => 'chucnang.chuyenkho.getAdd','uses' => 'ChuyenkhoController@getAdd']);
        
        Route::get('sua-theo-chung-tu/{id}', ['as' => 'chucnang.chuyenkho.getEdit','uses' => 'ChuyenkhoController@getEdit']);
        Route::post('sua-theo-chung-tu/{id}', ['as' => 'chucnang.chuyenkho.postEdit','uses' => 'ChuyenkhoController@postEdit']);
        
        Route::get('sua-theo-vat-tu/{id}', ['as' => 'chucnang.chuyenkho.getEdit1','uses' => 'ChuyenkhoController@getEdit1']);
        Route::post('sua-theo-vat-tu/{id}', ['as' => 'chucnang.chuyenkho.postEdit1','uses' => 'ChuyenkhoController@postEdit1']);

        Route::get('xoachuyenkho/{id}', ['as' => 'chucnang.chuyenkho.getDelete','uses' => 'ChuyenkhoController@getDelete']);

        Route::get('xoavattu/{id}/{ad}', ['as' => 'chucnang.chuyenkho.getDeletePro','uses' => 'ChuyenkhoController@getDeletePro']);

        Route::get('suavattu/{id}/{ad}', ['as' => 'chucnang.chuyenkho.getEditPro','uses' => 'ChuyenkhoController@getEditPro']);

        Route::get('xemtheovattu', ['as' => 'chucnang.chuyenkho.getVattu','uses' => 'ChuyenkhoController@getVattu']);
        Route::get('xemtheochungtu', ['as' => 'chucnang.chuyenkho.getChungtu','uses' => 'ChuyenkhoController@getChungtu']);
         //Ajax Vật tư - Xuất kho
        Route::get('vattu/ajax-call', function(){
            $vattu_id = Input::get('vattu_id');
            
            $country = DB::table('vattukho')
            ->where('vattukho.vt_id',$vattu_id)
            ->join('vattu','vattu.id','=','vattukho.vt_id')
            ->join('kho','kho.id','=','vattukho.kho_id')
            ->join('donvitinh','donvitinh.id','=','vattu.dvt_id')
            ->select('vattu.vt_ten','donvitinh.dvt_ten','kho.kho_ten','vattukho.vt_id','kho.id')
            ->get();
            
            return Response::json($country);
        });

        Route::get('chuyenvt/{id}/{qty}', ['as' => 'chucnang.chuyenkho.postChuyenkho','uses' => 'ChuyenkhoController@postChuyenkho']);
    });

    Route::group(['prefix' => 'xuatnhapton'], function() {
        //
    });

    //chuc nang bao cáo
    Route::get('khohang', ['as' => 'chucnang.khohang.getKhohang','uses' => 'BaocaoController@getKhohang']);
    Route::get('thekho', ['as' => 'chucnang.khohang.thekho','uses' => 'BaocaoController@thekho']);
    Route::get('ton-kho-tong-hop', ['as' => 'chucnang.khohang.tongton','uses' => 'BaocaoController@tongton']);
    Route::get('ton-kho-theo-nhom', ['as' => 'chucnang.khohang.nhomton','uses' => 'BaocaoController@nhomton']);
    Route::get('ton-kho-theo-chat-luong', ['as' => 'chucnang.khohang.chatluongton','uses' => 'BaocaoController@chatluongton']);
    Route::get('ton-kho-theo-nha-phan-phoi', ['as' => 'chucnang.khohang.nppton','uses' => 'BaocaoController@nppton']);
});

//Tro giup
Route::group(['prefix' => 'trogiup'], function() {
    Route::get('/', function ()
    {
        return view('trogiup.trogiup');
    });

    Route::group(['prefix' => 'thongtinphanmem'], function() {
        Route::get('thongtinphanmem', ['as' => 'trogiup.thongtinphanmem.getList','uses' => 'ThongtinphanmemController@getList']);
    });


    Route::get('huongdansudung', ['as' => 'trogiup.getHuongdan','uses' => 'TrogiupController@getHuongdan']);

    Route::get('lien-he', ['as' => 'trogiup.getLienhe','uses' => 'TrogiupController@getLienhe']);
    Route::post('lien-he', ['as' => 'trogiup.postLienhe','uses' => 'TrogiupController@postLienhe']);

    Route::get('phan-hoi', ['as' => 'trogiup.getPhanhoi','uses' => 'TrogiupController@getPhanhoi']);
    Route::post('phan-hoi', ['as' => 'trogiup.postPhanhoi','uses' => 'TrogiupController@postPhanhoi']);
    Route::get('thong-tin', ['as' => 'trogiup.getThongtin','uses' => 'TrogiupController@getThongtin']);
});

});
// Password reset link request routes...
Route::get('login',['as'=>'admin.login.getLogin','uses'=>'Auth\AuthController@getLogin']);
Route::post('login',['as'=>'admin.login.postLogin','uses'=>'Auth\AuthController@postLogin']);





Route::get('demo','WelcomeController@demo');


//Hotel management
Route::group(['prefix' => 'hotel'], function() {
    Route::get('/', function ()
    {
        return view('hotel.pages.index');
    });

    Route::group(['prefix' => 'so-do-phong'], function() {
        Route::get('', 'HotelRoomMapController@index');
        Route::get('dat-phong/{id}', 'HotelRoomMapController@checkInGet');
        Route::post('dat-phong/{id}', 'HotelRoomMapController@checkInPost');
        Route::get('tra-phong/{id}', 'HotelRoomMapController@checkOutGet');
        Route::post('tra-phong/{id}', 'HotelRoomMapController@checkOutPost');
        Route::get('sua-dat-phong/{id}', 'HotelRoomMapController@editGet');
        Route::post('sua-dat-phong/{id}', 'HotelRoomMapController@editPost');
    });

    Route::group(['prefix' => 'room'], function() {
        Route::get('', 'HotelRoomController@index');
        Route::get('add', 'HotelRoomController@addGet');
        Route::post('add', 'HotelRoomController@addPost');
        Route::get('edit/{id}', 'HotelRoomController@editGet');
        Route::post('edit/{id}', 'HotelRoomController@editPost');
        Route::get('delete/{id}', 'HotelRoomController@deleteGet');
    });

    Route::group(['prefix' => 'price'], function() {
        Route::get('', 'HotelPriceController@index');
        Route::get('list', 'HotelPriceController@listAll');
        Route::get('add', 'HotelPriceController@addGet');
        Route::post('add', 'HotelPriceController@addPost');
        Route::get('edit/{id}', 'HotelPriceController@editGet');
        Route::post('edit/{id}', 'HotelPriceController@editPost');
        Route::get('delete/{id}', 'HotelPriceController@deleteGet');
    });

    Route::get('checkin', 'HotelCheckController@checkin');
    Route::get('checkout', 'HotelCheckController@checkout');
    Route::get('checkout/print', 'HotelCheckController@print_checkout');

});

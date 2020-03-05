<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

use App\Http\Requests\NhanvienAddRequest;
use App\Http\Requests\NhanvienEditRequest;

use App\Nhanvien;
use DB,Hash;
use App\User;
class NhanvienController extends Controller {

    public function getList()
    {
        $nhanvien = DB::table('nhanvien')->get();
        return view('danhmuc.nhanvien.nhanvien', compact('nhanvien'));
    }

    public function getAdd()
    {
        $nguoidungs = DB::table('nguoidung')->get();
        foreach ($nguoidungs as $key => $val) {
           $nguoidung[] = ['id' => $val->id, 'name'=> $val->nd_ten];
          }
        return view('danhmuc.nhanvien.themnhanvien',compact('nguoidung'));
    }

    public function postAdd(Request $request)
    {
        $user = new User;
        $user->name = $request->name;
        $user->email = $request->txtEmail;
        $user->password = Hash::make($request->password);
        $user->nguoidung_id = $request->selQuyen;
        $user->remember_token = $request->_token;
        $user->save();


        $nhanvien = new Nhanvien;
        $nhanvien->nv_ma = $request->txtMa;
        $nhanvien->nv_ten = $request->txtTen;
        $nhanvien->nv_gioitinh = $request->rdGioitinh;
        $nhanvien->nv_ngaysinh = $request->dateNgaysinh;
        $nhanvien->nv_cmnd = $request->txtCMND;
        $nhanvien->nv_diachi = $request->txtDiachi;
        $nhanvien->nv_sdt = $request->txtSDT;
        $nhanvien->nv_email = $request->txtEmail;
        $nhanvien->nv_ngayvaolam = $request->dateNVL;
        $nhanvien->user_id = $user->id;
        $nhanvien->save();
        return redirect()->route('danhmuc.nhanvien.getList')->with(['flash_level'=>'success','flash_message'=>'Thêm thành công!!!']);
    }

    public function getEdit($id)
    {
        $phongbans = DB::table('phongban')->get();
        foreach ($phongbans as $key => $val) {
           $phongban[] = ['id' => $val->id, 'name'=> $val->pb_ten];
          }
        $nhanvien = DB::table('nhanvien')->where('id', $id)->first();
        return view('danhmuc.nhanvien.suanhanvien', compact('nhanvien'));
    }

    public function postEdit($id, Request $request)
    {
        DB::table('nhanvien')->where('id',$id)->update([
            'nv_ten' => $request->txtTen,
            'nv_gioitinh' => $request->rdGioitinh,
            'nv_ngaysinh' => $request->dateNgaysinh,
            'nv_cmnd' => $request->txtCMND,
            'nv_diachi' => $request->txtDiachi,
            'nv_sdt' => $request->txtSDT,
            'nv_email' => $request->txtEmail,
            'nv_ngayvaolam' => $request->dateNVL,
            ]);
        return redirect()->route('danhmuc.nhanvien.getList')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
    }

    public function getDelete($id)
    {
         DB::table('nhanvien')->where('id',$id)->delete();
        return redirect()->route('danhmuc.nhanvien.getList')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
    }


}

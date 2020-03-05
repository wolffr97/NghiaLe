<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

use App\Http\Requests\NhaphanphoiAddRequest;
use App\Http\Requests\NhaphanphoiEditRequest;

use App\Nhaphanphoi;
use DB;

class NhaphanphoiController extends Controller {

	public function getList()
	{
		$nhaphanphoi = DB::table('nhaphanphoi')->get();
		return view('danhmuc.nhaphanphoi.nhaphanphoi', compact('nhaphanphoi'));
	}

	public function getAdd()
	{
		$khuvucs = DB::table('khuvuc')->get();
		foreach ($khuvucs as $key => $val) {
		   $khuvuc[] = ['id' => $val->id, 'name'=> $val->kv_ten];
		  }
		return view('danhmuc.nhaphanphoi.themnhaphanphoi', compact('khuvuc'));
	}

	public function postAdd(NhaphanphoiAddRequest $request)
	{
		$nhaphanphoi = new Nhaphanphoi;
		$nhaphanphoi->npp_ma = $request->txtMa;
		$nhaphanphoi->npp_ten = $request->txtTen;
		$nhaphanphoi->npp_diachi = $request->txtDiachi;
		$nhaphanphoi->npp_sdt = $request->txtSDT;
		$nhaphanphoi->npp_fax = $request->txtFAX;
		$nhaphanphoi->npp_taikhoan = $request->txtTaikhoan;
		$nhaphanphoi->npp_email = $request->txtEmail;
		$nhaphanphoi->npp_nhanviendaidien = $request->txtNhanviendaidien;
		$nhaphanphoi->kv_id = $request->selKV;
		$nhaphanphoi->save();
		return redirect()->route('danhmuc.nhaphanphoi.getList')->with(['flash_level'=>'success','flash_message'=>'Thêm thành công!!!']);
	}

	public function getEdit($id)
	{
		$khuvucs = DB::table('khuvuc')->get();
		foreach ($khuvucs as $key => $val) {
		   $khuvuc[] = ['id' => $val->id, 'name'=> $val->kv_ten];
		  }
		$nhaphanphoi = DB::table('nhaphanphoi')->where('id', $id)->first();
		return view('danhmuc.nhaphanphoi.suanhaphanphoi', compact('nhaphanphoi','khuvuc'));
	}

	public function postEdit($id, NhaphanphoiEditRequest $request)
	{
		DB::table('nhaphanphoi')->where('id',$id)->update([
			'npp_ten' => $request->txtTen,
			'npp_diachi' => $request->txtDiachi,
			'npp_sdt' => $request->txtSDT,
			'npp_fax' => $request->txtFAX,
			'npp_taikhoan' => $request->txtTaikhoan,
			'npp_email' => $request->txtEmail,
			'npp_nhanviendaidien' => $request->txtNhanviendaidien,
			'kv_id' => $request->selKV,
			]);
		return redirect()->route('danhmuc.nhaphanphoi.getList')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
	}

	public function getDelete($id)
	{
		 DB::table('nhaphanphoi')->where('id',$id)->delete();
		return redirect()->route('danhmuc.nhaphanphoi.getList')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
	}

}

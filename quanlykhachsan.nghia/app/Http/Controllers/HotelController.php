<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;
use App\Hotel;
use App\Http\Requests\HotelRequest;
use DB;

class HotelController extends Controller {


	public function index()
	{
		$hotel = DB::table('hotels')->get();
		return view('admin.hotel.index',compact('hotel'));
	}

	public function addGet()
	{
		return view('admin.hotel.add');
	}

	public function addPost(hotelRequest $request)
	{
		$hotel = new Hotel;
		$hotel->name = $request->txtName;
		$hotel->address = $request->txtAddr;
		$hotel->phone = $request->txtPhone;
		$hotel->email = $request->txtEmail;
		$hotel->save();
		return redirect()->route('admin.hotel.index')->with(['flash_level'=>'success','flash_message'=>'Thêm thành công!!!']);
	}

	public function editGet($id)
	{
		$data = DB::table('hotels')->where('id',$id)->first();
		return view('admin.hotel.edit',compact('data'));
	}


	public function editPost(hotelRequest $request, $id)
	{
		DB::table('hotels')->where('id',$id)->update(
			[
			'name' => $request->txtName,
			'address' => $request->txtAddr,
			'phone' => $request->txtPhone,
			'email' => $request->txtEmail
			]);
		return redirect()->route('admin.hotel.index')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
	}

	public function deleteGet($id)
	{
		DB::table('hotels')->where('id',$id)->delete();
		return redirect()->route('admin.hotel.index')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
	}
}

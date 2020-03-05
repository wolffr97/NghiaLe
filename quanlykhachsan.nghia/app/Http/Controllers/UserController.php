<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;
use DB,Hash;
use App\User;
use App\ManageType;
use App\Hotel;
class UserController extends Controller {

	public function index()
	{
		$users = DB::table('users')
                    ->leftJoin('manage_types', 'users.manage_type_id', '=', 'manage_types.id')
                    ->select('users.*', 'manage_types.name as manageType')
                    ->orderBy('users.id','ASC')
                    ->get();
		return view('admin.user.index', compact('users'));
	}

	public function addGet()
	{
		$manageType = ManageType::select('id','name')->orderBy('id','DESC')->get()->toArray();
		$hotel = Hotel::select('id','name')->orderBy('id','DESC')->get()->toArray();		
		return view('admin.user.add',compact('manageType'));
	}

	public function addPost(Request $request)
	{
		$user = new User;
        $user->name = $request->txtName;
        $user->email = $request->txtEmail;
        $user->password = Hash::make($request->password);
        $user->role_id = 2;
        $user->manage_type_id = $request->manageType;
        $user->remember_token = $request->_token;
        $user->save();
		return redirect()->route('admin.user.index')->with(['flash_level'=>'success','flash_message'=>'Thêm thành công!!!']);
	}

	public function editGet($id)
	{
		$manageType = ManageType::select('id','name')->orderBy('id','DESC')->get()->toArray();
		$user = DB::table('users')->where('id', $id)->first();
		return view('admin.user.edit', compact('user','manageType'));
	}

	public function editPost($id, Request $request)
	{
		DB::table('users')->where('id',$id)->update([
			'name' => $request->txtName,
			'email' => $request->txtEmail,
			'manage_type_id' => $request->manageType
			]);
		return redirect()->route('admin.user.index')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
	}

	public function deleteGet($id)
	{
		 DB::table('users')->where('id',$id)->delete();
		return redirect()->route('admin.user.index')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
	}


}

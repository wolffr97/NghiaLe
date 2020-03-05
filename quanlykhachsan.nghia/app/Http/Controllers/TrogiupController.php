<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

// use Illuminate\Http\Request;

use DB,Mail,Request;

class TrogiupController extends Controller {

	
	public function getLienhe()
	{
		return view('trogiup.lienhe.lienhe');
	}

	public function postLienhe()
	{
		$data = ['email'=>Request::input('txtEmail'),'name'=>Request::input('txtTen'),'content'=>Request::input('txtNoidung')];
		Mail::send('emails.blank',$data,function($msg){
			$msg->from('warehousecantho@gmail.com','User ');
			$msg->to('warehousecantho@gmail.com','Support')->subject('Liên hệ');
		});

		echo "<script>
             alert('Cảm ơn bạn đã góp ý. Chúng tôi sẽ liên hệ với bạn trong thời gian sớm nhất');
             window.location='".url('trogiup/lien-he')."'
		</script>";
	}

	public function getPhanhoi()
	{
		return view('trogiup.phanhoi.phanhoi');
	}

	public function postPhanhoi()
	{

	}

	public function getThongtin()
	{
		$thongtincongty = DB::table('thongtincongty')->get();
		return view('hethong.thongtincongty.thongtincongty', compact('thongtincongty'));
	}

	public function getHuongdan()
	{
		return view('trogiup.huongdansudung.huongdansudung');
	}

}

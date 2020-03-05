<?php namespace App\Http\Controllers;

class WelcomeController extends Controller {

	/*
	|--------------------------------------------------------------------------
	| Welcome Controller
	|--------------------------------------------------------------------------
	|
	| This controller renders the "marketing page" for the application and
	| is configured to only allow guests. Like most of the other sample
	| controllers, you are free to modify or remove it as you desire.
	|
	*/

	/**
	 * Create a new controller instance.
	 *
	 * @return void
	 */
	// public function __construct()
	// {
	// 	$this->middleware('guest');
	// }

	/**
	 * Show the application welcome screen to the user.
	 *
	 * @return Response
	 */
	public function index()
	{
		return view('master');
	}

	public function danhmuc()
	{
		return view('danhmuc.danhmuc');
	}

	public function hethong()
	{
		return view('hethong.hethong');
	}

	public function chucnang()
	{
		return view('chucnang.chucnang');
	}

	public function trogiup()
	{
		return view('trogiup.trogiup');
	}

	public function demo ()
	{
		return view('demo');
	}
}

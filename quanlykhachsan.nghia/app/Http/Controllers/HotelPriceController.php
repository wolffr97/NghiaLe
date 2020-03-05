<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;
use App\HotelPrice;
use DB;

class HotelPriceController extends Controller {


    public function index()
    {
        $data = HotelPrice::select('id','name','price_day','price_hour','price_hour_next')->orderBy('id','DESC')->get()->toArray();
        return view('hotel.price.index',compact('data'));
    }

    public function listAll()
    {
        $data = HotelPrice::select('id','name','price_day','price_hour','price_hour_next')->orderBy('id','DESC')->get()->toArray();
        return $data;
    }

    public function addGet()
    {
        return view('hotel.price.add');
    }

    public function addPost(Request $request)
    {
        $data = new HotelPrice;
        $data->name = $request->txtName;
        $data->price_day = str_replace('.', '', $request->txtPriceDay);
        $data->price_hour = str_replace('.', '', $request->txtPriceHour);
        $data->price_hour_next = str_replace('.', '', $request->txtPriceHourNext);
        $data->save();
        return redirect('hotel/price')->with(['flash_level'=>'success','flash_message'=>'Thêm thành công!!!']);
    }

    public function editGet($id)
    {
        $data = HotelPrice::findOrFail($id)->toArray();
        return view('hotel.price.edit',compact('data'));
    }


    public function editPost(Request $request, $id)
    {
        $data = HotelPrice::find($id);
        $data->name = $request->txtName;
        $data->price_day = str_replace('.', '', $request->txtPriceDay);
        $data->price_hour = str_replace('.', '', $request->txtPriceHour);
        $data->price_hour_next = str_replace('.', '', $request->txtPriceHourNext);
        $data->save();
        return redirect('hotel/price')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
    }

    public function deleteGet($id)
    {
        DB::table('hotel_prices')->where('id',$id)->delete();
        return redirect('hotel/price')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
    }
}

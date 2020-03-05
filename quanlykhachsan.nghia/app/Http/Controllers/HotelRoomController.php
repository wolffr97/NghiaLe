<?php

namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use App\HotelRoom;
use App\HotelPrice;
use DB;

class HotelRoomController extends Controller {
    public function index() {
        $data = HotelRoom::select('id', 'name')
            ->where('manage_id', 1)
            ->orderBy('id', 'DESC')->get()->toArray();
        
        return view('hotel.room.index', compact('data'));
    }
    
    public function addGet() {
        $prices = HotelPrice::select('id', 'name')
            ->where('deleted',0)
            ->orderBy('id', 'DESC')->get()->toArray();
        return view( 'hotel.room.add',compact('prices'));
    }
    
    public function addPost(Request $request) {
        $data = new HotelRoom ();
        $data->name = $request->txtName;
        $data->manage_id = 1;
        $data->hotel_price_id = $request->price;
        $data->save ();
        return redirect ( 'hotel/room' )->with ( [
                'flash_level' => 'success',
                'flash_message' => 'Thêm thành công!!!'
        ] );
    }
    
    public function editGet($id) {
        $prices = HotelPrice::select('id', 'name')
            ->where('deleted',0)
            ->orderBy('id', 'DESC')->get()->toArray();
        $data = HotelRoom::findOrFail ( $id )->toArray ();
        return view ( 'hotel.room.edit', compact ( 'data','prices') );
    }
    
    public function editPost(Request $request, $id) {
        $data = HotelRoom::find ( $id );
        $data->name = $request->name;
        $data->manage_id = 1;
        $data->hotel_price_id = $request->price;
        $data->save ();
        return redirect ( 'hotel/room' )->with ( [
                'flash_level' => 'success',
                'flash_message' => 'Sửa thành công!!!'
        ] );
    }
    
    public function deleteGet($id) {
        DB::table ( 'hotel_rooms' )->where ( 'id', $id )->delete ();
        return redirect ( 'hotel/room' )->with ( [
                'flash_level' => 'success',
                'flash_message' => 'Xóa thành công!!!'
        ] );
    }
}

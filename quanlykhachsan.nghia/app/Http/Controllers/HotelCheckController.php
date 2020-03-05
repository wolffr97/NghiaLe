<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Input;
use App\HotelCheck;
use App\HotelRoom;
use App\HotelManagement;
use App\HotelExtra;
use DB,PDF;

use Config;
use DateTime;

class HotelCheckController extends Controller {


	public function checkin()
	{
		$_data = HotelRoom::select('id','name'
                                )
                            ->where('manage_id', 1)
                            ->where('status', Config::get('constants.OFF'))
                            ->orderBy('id', 'ASC')->get()->toArray();
        $data = array();
        foreach ($_data as $key => $item){
            $rent_type = '';
            $rent_num = '';
            
            $infoRoomOrder = HotelManagement::select(
                                                    'time_in',
                                                    'time_out',
                                                    'rent_type',
                                                    'rent_num',
                                                    'cost'
                                                    )
                                                    ->where('hotel_room_id', $item['id'])
                                                    ->where('manage_id', 1)
                                                    ->where('deleted', Config::get('constants.ON'))
                                                    ->orderBy('id', 'DESC')
                                                    ->first();
            
            if($infoRoomOrder['rent_type'] == Config::get('constants.DAY')){
                $rent_type = 'ĐẶT NGÀY';
                $rent_num = $infoRoomOrder['rent_num'].' NGÀY';
            }else{
                $rent_type = 'ĐẶT GIỜ';
                $rent_num = $infoRoomOrder['rent_num'].' GIỜ';
            }
            $item['time_in'] = $infoRoomOrder['time_in'];
            $item['rent_type'] = $rent_type;
            $item['rent_num'] = $rent_num;
            $item['cost'] = $infoRoomOrder['cost'];
            
            $data[] = $item;
		}
		return view('hotel.check.checkin', compact('data'));
	}

	public function checkout()
	{
            $rent_type = '';
            $rent_num = '';
            $data = array();
            $revenue_room = 0;
            $revenue_extra = 0;
            $revenue_all = 0;

            $roomSearch = Input::get('room');
            $rentTypeSearch = Input::get('rent_type');

            $fromDateSearch = Input::get('fromDate');
            $fromDate = new DateTime($fromDateSearch);

            $toDateSearch = Input::get('toDate');
            $toDate = new DateTime($toDateSearch);

            $rooms = HotelRoom::select('id','name')
            	->where('manage_id', 1)
            	->orderBy('id','DESC')->get();
            $_data = HotelManagement::query();
            $_data = $_data->select(
            	'hotel_managements.id',
                'time_in',
                'time_out',
                'rent_type',
                'rent_num',
                'cost',
                'hotel_rooms.name as roomName'
                )
            	->leftJoin('hotel_rooms','hotel_managements.hotel_room_id', '=', 'hotel_rooms.id')
                ->where('hotel_managements.manage_id', 1)
                ->where('hotel_managements.deleted', Config::get('constants.ON'))
                ->where('hotel_managements.status', Config::get('constants.OFF'));

            if ($roomSearch != null && $roomSearch != "-1")
			{
			    $_data = $_data->where('hotel_rooms.id', $roomSearch);
			}
			if ($rentTypeSearch != null && $rentTypeSearch != "-1")
			{
			    $_data = $_data->where('hotel_managements.rent_type', $rentTypeSearch);
			}
			
			
			if ($fromDateSearch != null && $toDateSearch == null){
				$fromDateFormated = $fromDate->format('Y-m-d 00:00:00');
				$_data = $_data->where('hotel_managements.time_out', '>=', $fromDateFormated);
			}
			if ($toDateSearch != null && $fromDateSearch == null){
				$toDateFormated = $toDate->format('Y-m-d 23:59:59');
				$_data = $_data->where('hotel_managements.time_out', '<=', $toDateFormated);
			}
			if ($toDateSearch != null && $fromDateSearch != null){
				$fromDateFormated = $fromDate->format('Y-m-d 00:00:00');
				$toDateFormated = $toDate->format('Y-m-d 23:59:59');
				$_data = $_data->whereBetween('hotel_managements.time_out', [$fromDateFormated, $toDateFormated]);
			}
			$_data = $_data->orderBy('hotel_managements.id', 'DESC')->get();
            foreach($_data as $key => $item){
            	
	            if($item['rent_type'] == Config::get('constants.DAY')){
	                $rent_type = 'ĐẶT NGÀY';
	                $rent_num = $item['rent_num'].' NGÀY';
	            }else{
	                $rent_type = 'ĐẶT GIỜ';
	                $rent_num = $item['rent_num'].' GIỜ';
	            }

	            $item['allCost'] = 0;
	            $item['extraCost'] = 0;
	            $extras = HotelExtra::select(
	            	'num',
	            	'cost'
	            	)
	            	->where('hotel_management_id', $item['id'])
	            	->where('deleted', Config::get('constants.ON'))
	            	->orderBy('id', 'DESC')
	            	->get();
	            foreach($extras as $key=>$extra){
	            	$item['extraCost'] += ($extra['num'] * $extra['cost']);
	            }
	            $item['rent_type'] = $rent_type;
	            $item['rent_num'] = $rent_num;
	            $item['allCost'] = $item['extraCost'] + $item['cost'];

	            $revenue_room += $item['cost'];
	            $revenue_extra += $item['extraCost'];
	            $revenue_all += $item['allCost'];
	            $data[] = $item;
            }
            
            
		return view('hotel.check.checkout', compact('data','revenue_room', 'revenue_extra', 'revenue_all','rooms','roomSearch','rentTypeSearch','fromDateSearch','toDateSearch'));
	}


	public function addGet()
	{
		return view('hotel.price.add');
	}

	public function addPost(Request $request)
	{
		$data = new HotelPrice;
		$data->name = $request->txtName;
		$data->price_day = $request->txtPriceDay;
		$data->price_hour = $request->txtPriceHour;
		$data->price_hour_next = $request->txtPriceHourNext;
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
        $data->price_day = $request->txtPriceDay;
		$data->price_hour = $request->txtPriceHour;
		$data->price_hour_next = $request->txtPriceHourNext;
        $data->save();
        return redirect('hotel/price')->with(['flash_level'=>'success','flash_message'=>'Sửa thành công!!!']);
	}

	public function deleteGet($id)
	{
        DB::table('hotel_prices')->where('id',$id)->delete();
		return redirect('hotel/price')->with(['flash_level'=>'success','flash_message'=>'Xóa thành công!!!']);
	}

	public function print_checkout()
    {
    	
        $rent_type = '';
        $rent_num = '';
        $data = array();
        $revenue_room = 0;
        $revenue_extra = 0;
        $revenue_all = 0;

        $roomSearch = Input::get('room');
        $rentTypeSearch = Input::get('rent_type');

        $date = new DateTime();
        $fromDateSearch = Input::get('fromDate');
        $fromDate = new DateTime($fromDateSearch);

        $toDateSearch = Input::get('toDate');
        $toDate = new DateTime($toDateSearch);

        $rooms = HotelRoom::select('id','name')
        	->where('manage_id', 1)
        	->orderBy('id','DESC')->get();
        $_data = HotelManagement::query();
        $_data = $_data->select(
        	'hotel_managements.id',
            'time_in',
            'time_out',
            'rent_type',
            'rent_num',
            'cost',
            'hotel_rooms.name as roomName'
            )
        	->leftJoin('hotel_rooms','hotel_managements.hotel_room_id', '=', 'hotel_rooms.id')
            ->where('hotel_managements.manage_id', 1)
            ->where('hotel_managements.deleted', Config::get('constants.ON'))
            ->where('hotel_managements.status', Config::get('constants.OFF'));

        if ($roomSearch != null && $roomSearch != "-1")
		{
		    $_data = $_data->where('hotel_rooms.id', $roomSearch);
		}
		if ($rentTypeSearch != null && $rentTypeSearch != "-1")
		{
		    $_data = $_data->where('hotel_managements.rent_type', $rentTypeSearch);
		}
		
		
		if ($fromDateSearch != null && $toDateSearch == null){
			$fromDateFormated = $fromDate->format('Y-m-d 00:00:00');
			$_data = $_data->where('hotel_managements.time_out', '>=', $fromDateFormated);
		}
		if ($toDateSearch != null && $fromDateSearch == null){
			$toDateFormated = $toDate->format('Y-m-d 23:59:59');
			$_data = $_data->where('hotel_managements.time_out', '<=', $toDateFormated);
		}
		if ($toDateSearch != null && $fromDateSearch != null){
			$fromDateFormated = $fromDate->format('Y-m-d 00:00:00');
			$toDateFormated = $toDate->format('Y-m-d 23:59:59');
			$_data = $_data->whereBetween('hotel_managements.time_out', [$fromDateFormated, $toDateFormated]);
		}
		$_data = $_data->orderBy('hotel_managements.id', 'DESC')->get();
        foreach($_data as $key => $item){
        	
            if($item['rent_type'] == Config::get('constants.DAY')){
                $rent_type = 'ĐẶT NGÀY';
                $rent_num = $item['rent_num'].' NGÀY';
            }else{
                $rent_type = 'ĐẶT GIỜ';
                $rent_num = $item['rent_num'].' GIỜ';
            }

            $item['allCost'] = 0;
            $item['extraCost'] = 0;
            $extras = HotelExtra::select(
            	'num',
            	'cost'
            	)
            	->where('hotel_management_id', $item['id'])
            	->where('deleted', Config::get('constants.ON'))
            	->orderBy('id', 'DESC')
            	->get();
            foreach($extras as $key=>$extra){
            	$item['extraCost'] += ($extra['num'] * $extra['cost']);
            }
            $item['rent_type'] = $rent_type;
            $item['rent_num'] = $rent_num;
            $item['allCost'] = $item['extraCost'] + $item['cost'];

            $revenue_room += $item['cost'];
            $revenue_extra += $item['extraCost'];
            $revenue_all += $item['allCost'];
            $data[] = $item;
        }
        
        $pdf = PDF::loadView('hotel.check.pdf',compact('data','revenue_room', 'revenue_extra', 'revenue_all','rooms','roomSearch','rentTypeSearch','fromDateSearch','toDateSearch'));
        return $pdf->stream();
    }
}

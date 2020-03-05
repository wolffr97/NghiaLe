<?php namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;

use DB;
use App\HotelRoom;
use App\HotelManagement;
use App\HotelCustomer;
use App\HotelExtra;

use Config;
use DateTime;

class HotelRoomMapController extends Controller {

    public function index(){
        $_data = HotelRoom::select(
                                    'id',
                                    'name',
                                    'status'
                                )
                            ->where('manage_id', 1)
                            ->orderBy('id', 'ASC')->get()->toArray();
        $data = array();
        foreach ($_data as $key => $item){
            $time_in = 'dd/mm/yyyy 00:00:00';
            $rent_type = '';
            $rent_num = '';
            if($item['status']== Config::get('constants.ON')){
                $item['class'] = 'success';
                $item['url'] = 'dat-phong';
                $item['order'] = 'PHÒNG TRỐNG';
            }else{
                $infoRoomOrder = HotelManagement::select(
                                                    'time_in',
                                                    'time_out',
                                                    'rent_type',
                                                    'rent_num'
                                                    )
                                                    ->where('hotel_room_id', $item['id'])
                                                    ->where('manage_id', 1)
                                                    ->orderBy('id', 'DESC')
                                                    ->first();
                $item['url'] = 'tra-phong';
                if($this->compareDateWithCurrentDate($infoRoomOrder['time_expired'])){
                    $item['class'] = 'danger';
                    $item['order'] = 'HẾT GIỜ';
                }else{
                    $item['class'] = 'primary';
                    $item['order'] = 'ĐÃ ĐẶT';
                }
                $date = new DateTime($infoRoomOrder['time_in']);
                $time_in= $date->format('d-m-Y H:i:s');
                if($infoRoomOrder['rent_type'] == Config::get('constants.DAY')){
                    $rent_type = 'ĐẶT NGÀY';
                    $rent_num = $infoRoomOrder['rent_num'].' NGÀY';
                }else{
                    $rent_type = 'ĐẶT GIỜ';
                    $rent_num = $infoRoomOrder['rent_num'].' GIỜ';
                }
            }
            $item['time_in'] = $time_in;
            $item['rent_type'] = $rent_type;
            $item['rent_num'] = $rent_num;
            
            $data[] = $item;
        }

        return view('hotel.pages.roommap.index', compact('data'));
    }
    
    public function checkInGet($hotel_room_id){
        $data = DB::table('hotel_rooms')
                        ->join('hotel_prices', 'hotel_rooms.hotel_price_id', '=', 'hotel_prices.id')
                        ->where('hotel_rooms.id', $hotel_room_id)
                        ->select('hotel_rooms.*', 'hotel_prices.*', 'hotel_prices.name as hotelPriceName', 'hotel_rooms.name as hotelRoomName', 'hotel_rooms.id as hotelRoomId')
                        ->first();
        if(empty($data)) return redirect('hotel/so-do-phong');
        return view('hotel.pages.roommap.checkin', compact('data'));
    }
    
    public function checkInPost($hotel_room_id, Request $request){

        // Get price information by hotel_room_id
        $priceInfos = DB::table('hotel_rooms')
                            ->join('hotel_prices', 'hotel_rooms.hotel_price_id', '=', 'hotel_prices.id')
                            ->where('hotel_rooms.id', $hotel_room_id)
                            ->select('hotel_prices.price_day', 'hotel_prices.price_hour', 'hotel_prices.price_hour_next')
                            ->first();
        
        // Save hotel customer
        $hotelCustomer = new HotelCustomer();
        $hotelCustomer->name = $request->name;
        $hotelCustomer->gender = $request->gender;
        $hotelCustomer->identifier = $request->identifier;
        $hotelCustomer->address = $request->address;
        $hotelCustomer->hotel_room_id = $hotel_room_id;
        $hotelCustomer->note = '';
        $hotelCustomer->deleted = Config::get('constants.ON');
        $hotelCustomer->save();
        
        // Save hotel management
        $hotelManagement = new HotelManagement();
        $hotelManagement->manage_id = 1;
        $hotelManagement->hotel_room_id = $hotel_room_id;
        $hotelManagement->hotel_customer_id = $hotelCustomer->id;
        $hotelManagement->time_in = date('Y-m-d H:i:s');
        
        // When customer undefined time out
        if($request->rent_num != 0) $hotelManagement->time_expired = $this->getTimeout($request->rent_type
                                                                                , $request->rent_num
                                                                                , $hotelManagement->time_in);
        $hotelManagement->cost = $this->getPrice($request->rent_type
                                                , $request->rent_num
                                                , $priceInfos->price_day
                                                , $priceInfos->price_hour
                                                , $priceInfos->price_hour_next);
        
        $hotelManagement->rent_type = $request->rent_type;
        $hotelManagement->rent_num = $request->rent_num;
        $hotelManagement->note = '';
        $hotelManagement->status = Config::get('constants.ON');
        $hotelManagement->deleted = Config::get('constants.ON');
        $hotelManagement->save();
        
        // Update status of room
        DB::table('hotel_rooms')
        ->where('hotel_rooms.id', $hotel_room_id)
        ->update(['hotel_rooms.status' => Config::get('constants.OFF')]);
        
        return redirect('hotel/so-do-phong');
    }
    
    public function checkOutGet($hotel_room_id){
        $hotelRoom = HotelRoom::select(
                                        'id',
                                        'name'
                                        )
                ->where('id', $hotel_room_id)
                ->where('manage_id', 1)
                ->first();
        
        $infoRoomOrder = HotelManagement::select(
                                        'id',
                                        'time_in',
                                        'time_expired',
                                        'rent_type',
                                        'rent_num',
                                        'cost'
                                        )
                        ->where('hotel_room_id', $hotel_room_id)
                        ->where('manage_id', 1)
                        ->orderBy('id', 'DESC')
                        ->first();
        
        $hotelCustomer = HotelCustomer::select(
                                'name',
                                'gender',
                                'identifier',
                                'address'
                                )
                                ->where('hotel_room_id', $hotel_room_id)
                                ->orderBy('id', 'DESC')
                                ->first();
        
                                // Get price information by hotel_room_id
                                $priceInfos = DB::table('hotel_rooms')
                                                ->join('hotel_prices', 'hotel_rooms.hotel_price_id', '=', 'hotel_prices.id')
                                                ->where('hotel_rooms.id', $hotel_room_id)
                                                ->select('hotel_prices.price_day', 'hotel_prices.price_hour', 'hotel_prices.price_hour_next')
                                                ->first();

        try{
            $date = new DateTime($infoRoomOrder['time_in']);
            $hotelRoom->time_in = $date->format('d-m-Y H:i:s');
            $hotelRoom->time_out = date('d-m-Y H:i:s');
            $hotelRoom->rent_type = 'ĐẶT THEO GIỜ';
            if($infoRoomOrder['rent_type'] == Config::get('constants.DAY')){
                $hotelRoom->rent_type = 'ĐẶT THEO NGÀY';
            }
            
            // No defined time out
            /*
            if(empty(strtotime($infoRoomOrder['time_expired']))){
                $hotelRoom->rent_num = $this->getHoursOrDaysFromTwoDate($infoRoomOrder['rent_type'], $infoRoomOrder['time_in'], date('Y-m-d H:i:s'));
                $hotelRoom->cost = $this->getPrice($infoRoomOrder['rent_type'], $hotelRoom->rent_num, $priceInfos->price_day, $priceInfos->price_hour, $priceInfos->price_hour_next);
            }else{
                $hotelRoom->rent_num = $infoRoomOrder['rent_num'];
                $hotelRoom->cost = $infoRoomOrder['cost'];
            }
            */
            $hotelRoom->rent_num = $this->getHoursOrDaysFromTwoDate($infoRoomOrder['rent_type'], $infoRoomOrder['time_in'], date('Y-m-d H:i:s'));
            $hotelRoom->cost = $this->getPrice($infoRoomOrder['rent_type'], $hotelRoom->rent_num, $priceInfos->price_day, $priceInfos->price_hour, $priceInfos->price_hour_next);
            
            $hotelRoom->customerName = $hotelCustomer['name'];
            if($hotelCustomer['gender'] == Config::get('constants.MALE')){
                $hotelRoom->gender = 'NAM';
            }elseif ($hotelCustomer['gender'] == Config::get('constants.FEMALE')){
                $hotelRoom->gender = 'NỮ';
            }else{
                $hotelRoom->gender = 'CHƯA XÁC ĐỊNH';
            }
            $hotelRoom->identifier = $hotelCustomer['identifier'];
            $hotelRoom->address = $hotelCustomer['address'];
            
        }catch (\Exception $e) {
            return redirect('hotel');
        }
        return view('hotel.pages.roommap.checkout', compact('hotelRoom'));
    }
    
    public function checkOutPost($hotel_room_id, Request $request){
        $infoRoomOrder = HotelManagement::select(
                                    'id'
                                    )
                ->where('hotel_room_id', $hotel_room_id)
                ->where('manage_id', 1)
                ->orderBy('id', 'DESC')
                ->first();
        
        $arrNameList = explode(',', $request->nameList);
        $arrPriceList = explode(',', $request->priceList);
        $arrNumList = explode(',', $request->numList);
        
        $length = count($arrNameList);
        for ($i = 0; $i < $length; $i++){
            $hotelExtra = new HotelExtra();
            $hotelExtra->name = $arrNameList[$i];
            $hotelExtra->num = $arrNumList[$i];
            $hotelExtra->cost = $arrPriceList[$i];;
            $hotelExtra->hotel_management_id = $infoRoomOrder->id;
            $hotelExtra->save();
        }
        
        // Update status of room
        DB::table('hotel_rooms')
            ->where('hotel_rooms.id', $hotel_room_id)
            ->update(	['hotel_rooms.status' => Config::get('constants.ON')]
                    );
        
            // Update status of room in hotel managements
            /*
             DB::table('hotel_managements')
             ->where('hotel_managements.id', $infoRoomOrder->id)
             ->update(	['hotel_managements.status' => Config::get('constants.OFF')],
             
             ['hotel_managements.rent_num' => $hotelRoom->rent_num],
             ['hotel_managements.cost' => $hotelRoom->cost]
             );
             */
            $date = new DateTime($request->time_out);
            
            $infoRoomOrder->time_out = $date->format('Y-m-d H:i:s');
            $infoRoomOrder->status = Config::get('constants.OFF');
            $infoRoomOrder->rent_num = $request->rent_num;
            $infoRoomOrder->cost = $request->cost;
            $infoRoomOrder->save();
        
        return redirect('hotel/so-do-phong');
    }
    /**
     * Get hotel price: days or hours
     *
     * @author VuLee
     * @param unknown $rent_type
     * @param unknown $rent_num
     * @param unknown $price_day
     * @param unknown $price_hour
     * @param unknown $price_hour_next
     * @return number
     */
    private function getPrice(	$rent_type,
                                $rent_num,
                                $price_day,
                                $price_hour,
                                $price_hour_next){
        
        if($rent_type == Config::get('constants.DAY')){
            return $rent_num * $price_day;
        }
        // Calculate to stay with hours
        return $price_hour + ($rent_num - 1) * $price_hour_next;
    }
    
    /**
     * Get time when customer check out their room
     *
     * @author VuLee
     * @param unknown $rent_type
     * @param unknown $rent_num
     * @param unknown $time_in
     * @return string|unknown
     */
    private function getTimeout($rent_type, $rent_num, $time_in){
        if(empty($rent_num)) return null;
        $now = date($time_in);
        if($rent_type == Config::get('constants.DAY')){
            $date_minus = date("Y-m-d", strtotime("$now +$rent_num day"));
            return $date_minus.' 12:00:00';
        }
        return date("Y-m-d H:i:s", strtotime("$now +$rent_num hour"));
    }
    
    /**
     * Check expirate date
     *
     * @author VuLee
     * @param unknown $time_out
     * @return boolean
     */
    private function compareDateWithCurrentDate($time_expired){
        if(empty($time_expired)) return false;
        
        $now = date('Y-m-d H:i:s');
        if(strtotime($now) >= strtotime($time_out)) return true;
        
        $date_minus = date("Y-m-d H:i:s", strtotime("$now +15 minute"));// Plus 15 minutes
        if(strtotime($date_minus) >= strtotime($time_out)) return true;
        return false;
        
    }
    
    /**
     * Get hours from 2 date
     *
     * @author VuLee
     * @param unknown $dateFrom
     * @param unknown $dateTo
     * @return number
     */
    private function getHoursOrDaysFromTwoDate($rent_type, $dateFrom, $dateTo){
        if($rent_type == Config::get('constants.DAY')){
            $datetime1 = date_create($dateFrom);
            $datetime2 = date_create($dateTo);
            
            $diff = $datetime2->diff($datetime1);
            
            $days = $diff->days;
            if(empty($days)) return 1;
            return $days;
            
        }else{
            $datetime1 = date_create($dateFrom);
            $datetime2 = date_create($dateTo);
            
            $diff = $datetime2->diff($datetime1);
            
            $hours = $diff->h;
            $hours = $hours + ($diff->days * 24);
            
            // Greater than 10 minutes then add 1 hour
            if(($diff->i) > 10) $hours += 1;
            if(empty($hours)) return 1;
            return $hours;
        }
        
        return 0;
    }

}

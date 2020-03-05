<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class HotelCheck extends Model {

protected $table = 'hotel_managements';

 protected $fillable = ['id','manage_id','hotel_room_id','time_in','time_out','cost','rent_type','rent_num','note','deleted'];

 public $timestamps = true;

}

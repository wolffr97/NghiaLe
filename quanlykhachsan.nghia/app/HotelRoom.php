<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class HotelRoom extends Model {

protected $table = 'hotel_rooms';

 protected $fillable = ['id','name'];

 public $timestamps = true;

}

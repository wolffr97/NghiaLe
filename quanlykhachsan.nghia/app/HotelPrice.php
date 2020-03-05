<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class HotelPrice extends Model {

protected $table = 'hotel_prices';

 protected $fillable = ['id','name','price_day','price_hour','price_hour_next'];

 public $timestamps = true;

}

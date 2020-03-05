<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class HotelExtra extends Model {

    protected $table = 'hotel_extras';

    protected $fillable = ['id','name','num','cost','hotel_management_id','deleted'];

    public $timestamps = true;

}

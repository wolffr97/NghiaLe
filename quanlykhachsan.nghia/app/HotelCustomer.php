<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class HotelCustomer extends Model {

    protected $table = 'hotel_customers';

    protected $fillable = ['id','name'];

    public $timestamps = true;

}

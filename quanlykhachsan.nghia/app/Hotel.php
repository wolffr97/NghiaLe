<?php namespace App;

use Illuminate\Database\Eloquent\Model;

class Hotel extends Model {

protected $table = 'hotels';

 protected $fillable = ['id','name','address','phone','email'];

 public $timestamps = true;

}

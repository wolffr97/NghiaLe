<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateNhaphanphoiTable extends Migration {

	public function up()
	{
		Schema::create('nhaphanphoi', function(Blueprint $table)
		{
			$table->increments('id');
			$table->char('npp_ma',10);
			$table->String('npp_ten',100);
			$table->String('npp_diachi',200);
			$table->char('npp_sdt',20);
			$table->char('npp_fax',20);
			$table->String('npp_taikhoan',50);
			$table->String('npp_email');
			$table->String('npp_nhanviendaidien',200);
			$table->integer('kv_id')->unsigned();
            $table->foreign('kv_id')->references('id')->on('khuvuc')->onUpdate('cascade');
			$table->timestamps();
		});
	}

	/**
	 * Reverse the migrations.
	 *
	 * @return void
	 */
	public function down()
	{
		Schema::drop('nhaphanphoi');
	}

}

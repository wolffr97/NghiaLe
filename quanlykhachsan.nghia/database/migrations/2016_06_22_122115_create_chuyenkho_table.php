<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateChuyenkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('chuyenkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->char('ck_ma',10);
			$table->date('ck_ngay');
			$table->String('ck_lydo',200);
            $table->integer('nv_id')->unsigned();
            $table->foreign('nv_id')->references('id')->on('nhanvien')->onUpdate('cascade');
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
		Schema::drop('chuyenkho');
	}

}

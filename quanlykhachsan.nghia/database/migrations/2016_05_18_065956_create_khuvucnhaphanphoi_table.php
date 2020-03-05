<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateKhuvucnhaphanphoiTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('khuvucnhaphanphoi', function (Blueprint $table) {
		    $table->integer('kv_id')->unsigned();
            $table->foreign('kv_id')->references('id')->on('khuvuc')->onUpdate('cascade');
            $table->integer('npp_id')->unsigned();
            $table->foreign('npp_id')->references('id')->on('nhaphanphoi')->onUpdate('cascade');
		});
	}

	/**
	 * Reverse the migrations.
	 *
	 * @return void
	 */
	public function down()
	{
		Schema::drop('khuvucnhaphanphoi');
	}

}

<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateVattukhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('vattukho', function(Blueprint $table)
		{
		$table->increments('id');
		$table->integer('vt_id')->unsigned();
        $table->foreign('vt_id')->references('id')->on('vattu')->onUpdate('cascade');
        $table->integer('kho_id')->unsigned();
        $table->foreign('kho_id')->references('id')->on('kho')->onUpdate('cascade');
        $table->integer('sl_nhap');
        $table->integer('sl_xuat');
        $table->integer('sl_ton');
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
		Schema::drop('vattukho');
	}

}

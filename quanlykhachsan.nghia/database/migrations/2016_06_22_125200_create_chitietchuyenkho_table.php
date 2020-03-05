<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateChitietchuyenkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('chitietchuyenkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->integer('ctck_soluong');
			$table->decimal('ctck_thanhtien',10,2);
			$table->integer('vt_id')->unsigned();
            $table->foreign('vt_id')->references('id')->on('vattu')->onUpdate('cascade');
            $table->integer('ck_id')->unsigned();
            $table->foreign('ck_id')->references('id')->on('chuyenkho')->onUpdate('cascade');
            $table->integer('khocu_id')->unsigned();
            $table->foreign('khocu_id')->references('id')->on('kho')->onUpdate('cascade');
            $table->integer('khomoi_id')->unsigned();
            $table->foreign('khomoi_id')->references('id')->on('kho')->onUpdate('cascade');
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
		Schema::drop('chitietchuyenkho');
	}

}

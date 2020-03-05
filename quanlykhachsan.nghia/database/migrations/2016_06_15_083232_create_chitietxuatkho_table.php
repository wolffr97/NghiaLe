<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateChitietxuatkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('chitietxuatkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->integer('ctxk_soluong');
			$table->decimal('ctxk_thanhtien',10,2);
			$table->integer('vt_id')->unsigned();
            $table->foreign('vt_id')->references('id')->on('vattu')->onUpdate('cascade');
            $table->integer('xk_id')->unsigned();
            $table->foreign('xk_id')->references('id')->on('xuatkho')->onUpdate('cascade');
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
		Schema::drop('chitietxuatkho');
	}

}

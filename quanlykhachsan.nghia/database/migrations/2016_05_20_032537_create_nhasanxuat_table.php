<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateNhasanxuatTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('nhasanxuat', function (Blueprint $table) {
		    $table->increments('id');
			$table->char('nsx_ma',10);
			$table->String('nsx_ten',100);
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
		Schema::drop('nhasanxuat');
	}

}

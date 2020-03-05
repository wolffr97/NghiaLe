<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateKhuvucTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('khuvuc', function(Blueprint $table)
		{
			$table->increments('id');
			$table->timestamps();
			$table->string('kv_ma',10);
			$table->string('kv_ten', 100);
		});
	}

	/**
	 * Reverse the migrations.
	 *
	 * @return void
	 */
	public function down()
	{
		Schema::drop('khuvuc');
	}

}

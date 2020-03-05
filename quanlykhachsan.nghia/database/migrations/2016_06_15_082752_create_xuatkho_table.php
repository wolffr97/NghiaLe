<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateXuatkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('xuatkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->char('xk_ma',10);
			$table->date('xk_ngaylap');
			$table->String('xk_diachi');
			$table->String('xk_lydo',200);
			$table->decimal('xk_tongtien',10,2);
			$table->integer('ct_id')->unsigned();
            $table->foreign('ct_id')->references('id')->on('congtrinh')->onUpdate('cascade');
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
		Schema::drop('xuatkho');
	}

}

<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateNhapkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('nhapkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->char('nk_ma',10);
			$table->date('nk_ngaylap');
			$table->String('nk_lydo',200);
			$table->decimal('nk_tongtien',10,2);
			$table->integer('npp_id')->unsigned();
            $table->foreign('npp_id')->references('id')->on('nhaphanphoi')->onUpdate('cascade');
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
		Schema::drop('nhapkho');
	}

}

<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateVattuTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('vattu', function (Blueprint $table) {
		    $table->increments('id');
			$table->char('vt_ma',10);
			$table->String('vt_ten',100);
			$table->integer('vt_soluong');
			$table->integer('dvt_id')->unsigned();
            $table->foreign('dvt_id')->references('id')->on('donvitinh')->onUpdate('cascade');
			$table->integer('nvt_id')->unsigned();
            $table->foreign('nvt_id')->references('id')->on('nhomvattu')->onUpdate('cascade');
            $table->integer('cl_id')->unsigned();
            $table->foreign('cl_id')->references('id')->on('chatluong')->onUpdate('cascade');
            $table->integer('kho_id')->unsigned();
            $table->foreign('kho_id')->references('id')->on('kho')->onUpdate('cascade');
            $table->integer('npp_id')->unsigned();
            $table->foreign('npp_id')->references('id')->on('nhaphanphoi')->onUpdate('cascade');
            $table->integer('nsx_id')->unsigned();
            $table->foreign('nsx_id')->references('id')->on('nhasanxuat')->onUpdate('cascade');
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
		Schema::drop('vattu');
	}

}

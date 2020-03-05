<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateChitietnhapkhoTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('chitietnhapkho', function(Blueprint $table)
		{
			$table->increments('id');
			$table->integer('ctnk_soluong');
			$table->decimal('ctnk_thanhtien',10,2);
			$table->integer('vt_id')->unsigned();
            $table->foreign('vt_id')->references('id')->on('vattu')->onUpdate('cascade');
            $table->integer('nk_id')->unsigned();
            $table->foreign('nk_id')->references('id')->on('nhapkho')->onUpdate('cascade');
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
		Schema::drop('chitietnhapkho');
	}

}

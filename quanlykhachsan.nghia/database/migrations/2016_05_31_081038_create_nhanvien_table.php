<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateNhanvienTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('nhanvien', function(Blueprint $table)
		{
			$table->increments('id');
			$table->char('nv_ma',10);
			$table->String('nv_ten',100);
			$table->String('nv_gioitinh',10);
			$table->date('nv_ngaysinh');
			$table->String('nv_diachi',200);
			$table->char('nv_cmnd',15);
			$table->char('nv_sdt',20);
			$table->string('nv_email');
			$table->date('nv_ngayvaolam');
			$table->integer('pb_id')->unsigned();
            $table->foreign('pb_id')->references('id')->on('phongban')->onUpdate('cascade');
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
		Schema::drop('nhanvien');
	}

}

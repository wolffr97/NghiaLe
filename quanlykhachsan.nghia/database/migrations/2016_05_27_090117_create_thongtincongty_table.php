<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateThongtincongtyTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('thongtincongty', function (Blueprint $table) 
		{
		    $table->increments('id');
		    $table->String('cty_ten',200);
		    $table->String('cty_diachi',200);
		    $table->char('cty_sdt',20);
		    $table->char('cty_fax',20);
		    $table->String('cty_web',50);
		    $table->String('cty_email',50);
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
		Schema::drop('thongtincongty');
	}

}

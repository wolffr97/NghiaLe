<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class ThongtincongtyAddRequest extends Request {

	/**
	 * Determine if the user is authorized to make this request.
	 *
	 * @return bool
	 */
	public function authorize()
	{
		return true;
	}

	/**
	 * Get the validation rules that apply to the request.
	 *
	 * @return array
	 */
	public function rules()
	{
		return [
			'txtTen' => 'required|unique:thongtincongty,cty_ten',
			'txtDiachi' => 'required'
		];
	}

	public function messages()
	{
		return [
			'txtTen.unique' => 'not same',
			'txtTen.required' =>'not null',
			'txtDiachi.required' => 'not null'
		];
	}

}

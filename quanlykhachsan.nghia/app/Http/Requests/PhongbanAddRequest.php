<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class PhongbanAddRequest extends Request {

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
			'txtMa' => 'required|unique:phongban,pb_ma',
			'txtTen' => 'required'
		];
	}

	public function messages()
	{
		return [
			'txtMa.required' => 'not null',
			'txtMa.unique' => 'not same',
			'txtTen.required' =>'not null'
		];
	}

}

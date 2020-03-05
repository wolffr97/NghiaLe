<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class NhomvattuAddRequest extends Request {

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
			'txtMa' => 'required|unique:nhomvattu,nvt_ma',
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

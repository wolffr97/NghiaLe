<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class VattuEditRequest extends Request {

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
			'txtMa' => 'required',
			'txtTen' => 'required',
			'selCLuong' => 'required',
			'selDVT' => 'required',
			'selNVT' => 'required',
			'txtSLuong' => 'required|integer',
			'selKho' => 'required',
			'selNPP' => 'required',
			'selNSX' => 'required'
		];
	}

	public function messages()
	{
		return [
			'txtMa.required' => 'not null', 
			'required' =>'not null',
			'integer' => 'type integer'
		];
	}

}

<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class NhanvienEditRequest extends Request {

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
			'txtTen' => 'required',
			'selPB' => 'required',
			'txtEmail' => 'email',
			// 'txtSDT' => 'required',
			// 'txtCMND' => 'integer|min:9|max:12'
		];
	}

	public function messages()
	{
		return [
			'txtMa.unique' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Dữ liệu đã tồn tại!</strong>
								</div>',
			'txtTen.required' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Vui lòng không để trống trường này!</strong>
								</div>',
			'selPB.required' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Vui lòng không để trống trường này!</strong>
								</div>',
			'txtEmail.required' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Vui lòng không để trống trường này!</strong>
								</div>',
			'txtEmail.email' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Email không hợp lệ!</strong>
								</div>',
			// 'txtSDT.required' => '<div class="alert alert-danger">
   //  								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
   //  								<strong>Vui lòng nhập số!</strong>
			// 					</div>',
			// 'txtCMND.integer' => '<div class="alert alert-danger">
   //  								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
   //  								<strong>Vui lòng nhập số!</strong>
			// 					</div>',
			'txtMa.size' => '<div class="alert alert-danger">
    								<button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
    								<strong>Mã nhân viên không quá 10 ký tự!</strong>
								</div>'
		];
	}
}

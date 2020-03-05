<?php namespace App\Http\Requests;

use App\Http\Requests\Request;

class HotelRoomMapRequest extends Request {

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
            'txtName' => 'required:hotels,name',
            'address' => 'required:hotels,address',
            'txtPhone' => 'required:hotels,phone',
        ];
    }

    public function messages()
    {
        return [
            'txtName.required' => '<div class="alert alert-danger">
                                    <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
                                    <strong>Vui lòng không để trống trường này!</strong>
                                </div>',
            'txtAddr.required' => '<div class="alert alert-danger">
                                    <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
                                    <strong>Vui lòng không để trống trường này!</strong>
                                </div>',
            'txtPhone.required' => '<div class="alert alert-danger">
                                    <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
                                    <strong>Vui lòng không để trống trường này!</strong>
                                </div>'
        ];
    }
}

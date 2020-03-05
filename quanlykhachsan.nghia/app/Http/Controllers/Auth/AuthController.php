<?php namespace App\Http\Controllers\Auth;

use App\Http\Controllers\Controller;
use Illuminate\Contracts\Auth\Guard;
use Illuminate\Contracts\Auth\Registrar;
use Illuminate\Foundation\Auth\AuthenticatesAndRegistersUsers;

use App\Http\Requests\LoginRequest;

use Auth;

class AuthController extends Controller {


    use AuthenticatesAndRegistersUsers;

    public function __construct(Guard $auth, Registrar $registrar)
    {
        $this->auth = $auth;
        $this->registrar = $registrar;

        $this->middleware('guest', ['except' => 'logout']);
    }

    
    public function getLogin()
    {
        return view('auth.login');
    }

    public function postLogin(LoginRequest $request)
    {
        $login  = array(
            'email' => $request->username,
            'password' => $request->password
            );
        if ($this->auth->attempt($login)) {
            // Authentication passed...
            //return redirect()->route('hotel');
            return redirect('hotel/so-do-phong');
        }
        else {
            return redirect()->back();
        }
        
    }

    public function logout()
    {
        Auth::logout();
        return redirect()->route('admin.login.getLogin');
    }

    public function register()
    {
        return view('auth.register');
    }

    
}

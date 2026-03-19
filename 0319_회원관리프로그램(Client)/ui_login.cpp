//ui_login.cpp
#include "std.h"

HWND hlogin_edit_id, hlogin_edit_pw, hlogin_static_msg, hlogin_btn_login;

void ui_login_Init(HWND hDlg)
{
	hlogin_edit_id		= GetDlgItem(hDlg, IDC_EDIT_LOGIN_ID);
	hlogin_edit_pw		= GetDlgItem(hDlg, IDC_EDIT_LOGIN_PW);
	hlogin_static_msg	= GetDlgItem(hDlg, IDC_STATIC_MSG);
	hlogin_btn_login	= GetDlgItem(hDlg, IDC_BTN_LOGIN);
}

void ui_login_Invoke(HWND hDlg)
{
	TCHAR id[20], pw[20];
	GetWindowText(hlogin_edit_id, id, _countof(id));
	GetWindowText(hlogin_edit_pw, pw, _countof(pw));
	try
	{
		login_data_check(id, pw);
		con_LogIn(hDlg, id, pw);

		SetWindowText(hlogin_static_msg, TEXT("로그인 성공"));

		SetWindowText(hlogin_edit_id, TEXT(""));
		SetWindowText(hlogin_edit_pw, TEXT(""));
		


	}
	catch (const TCHAR* msg)
	{
		SetWindowText(hlogin_static_msg, msg);
	}
}

void login_data_check(TCHAR* id, TCHAR* pw)
{
	if (_tcslen(id) == 0 || _tcslen(pw) == 0)
		throw TEXT("모든 정보를 입력하세요");
}




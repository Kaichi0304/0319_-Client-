//ui_insert.cpp
#include "std.h"

HWND hinsert_edit_id, hinsert_edit_pw, hinsert_edit_name, hinsert_edit_phone;
HWND hinsert_static_msg, hinsert_btn_login;

void ui_insert_Init(HWND hDlg)
{
	hinsert_edit_id		= GetDlgItem(hDlg, IDC_EDIT_ADD_ID);
	hinsert_edit_pw		= GetDlgItem(hDlg, IDC_EDIT_ADD_PW);
	hinsert_edit_name	= GetDlgItem(hDlg, IDC_EDIT_ADD_NAME);
	hinsert_edit_phone	= GetDlgItem(hDlg, IDC_EDIT_ADD_PHONE);
	hinsert_static_msg	= GetDlgItem(hDlg, IDC_STATIC_ADD_MSG);
	hinsert_btn_login	= GetDlgItem(hDlg, IDC_BTN_ADDMEMBER);
}

void ui_insert_Invoke(HWND hDlg)
{
	TCHAR id[20], pw[20], name[20], phone[20];
	GetWindowText(hinsert_edit_id, id, _countof(id));
	GetWindowText(hinsert_edit_pw, pw, _countof(pw));
	GetWindowText(hinsert_edit_name, name, _countof(name));
	GetWindowText(hinsert_edit_phone, phone, _countof(phone));

	try
	{
		insert_data_check(id, pw, name, phone);
		con_InsertMember(hDlg, id, pw, name, phone);

		

		SetWindowText(hinsert_edit_id, TEXT(""));
		SetWindowText(hinsert_edit_pw, TEXT(""));
		SetWindowText(hinsert_edit_name, TEXT(""));
		SetWindowText(hinsert_edit_phone, TEXT(""));
	}
	catch (const TCHAR* msg)
	{
		SetWindowText(hinsert_static_msg, msg);
	}
}

void insert_data_check(TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	if (_tcslen(id) == 0 || _tcslen(pw) == 0 || _tcslen(name) == 0 || _tcslen(phone) == 0)
		throw TEXT("모든 정보를 입력하세요");
}
void ui_insert_Ack(PacketInsertMemberAck* pdata)
{
	if(pdata->result == true )
		SetWindowText(hinsert_static_msg, TEXT("회원가입 성공"));
	else
		SetWindowText(hinsert_static_msg, TEXT("회원가입 실패"));
}
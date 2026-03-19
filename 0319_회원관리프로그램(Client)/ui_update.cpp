//ui_update.cpp
#include "std.h"

HWND hupdate_edit_id, hupdate_edit_phone, hupdate_static_msg, hupdate_btn_update;


void ui_update_Init(HWND hDlg)
{
	hupdate_edit_id		= GetDlgItem(hDlg, IDC_EDIT_UPDATE_ID);
	hupdate_edit_phone	= GetDlgItem(hDlg, IDC_EDIT_UPDATE_PHONE);
	hupdate_static_msg	= GetDlgItem(hDlg, IDC_STATIC_UPDATE_MSG);
	hupdate_btn_update	= GetDlgItem(hDlg, IDC_BTN_UPDATEMEMBER);
}

void ui_update_Invkoe(HWND hDlg)
{
	TCHAR id[20], phone[20];
	GetWindowText(hupdate_edit_id, id, _countof(id));
	GetWindowText(hupdate_edit_phone, phone, _countof(phone));

	try
	{
		update_data_check(id, phone);
		con_UpdateMember(hDlg, id, phone);

		SetWindowText(hupdate_static_msg, TEXT("회원 검색 성공"));
	}
	catch (const TCHAR* msg)
	{
		SetWindowText(hupdate_static_msg, msg);
	}
}

void update_data_check(TCHAR* id, TCHAR* phone)
{
	if (_tcslen(id) == 0 || _tcslen(phone) == 0)
		throw TEXT("모든 정보를 입력하세요");
}
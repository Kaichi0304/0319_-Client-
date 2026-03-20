//ui_select.cpp
#include "std.h"

HWND hselect_edit_id, hselect_edit_pw, hselect_edit_name, hselect_edit_phone;
HWND hselect_static_msg, hselect_btn_select, hselect_check_pw;

void ui_select_Init(HWND hDlg)
{
	hselect_edit_id		= GetDlgItem(hDlg, IDC_EDIT_SELECT_ID);
	hselect_edit_pw		= GetDlgItem(hDlg, IDC_EDIT_SELECT_PW);
	hselect_edit_name	= GetDlgItem(hDlg, IDC_EDIT_SELECT_NAME);
	hselect_edit_phone	= GetDlgItem(hDlg, IDC_EDIT_SELECT_PHONE);
	hselect_static_msg	= GetDlgItem(hDlg, IDC_STATIC_SELECT_MSG);
	hselect_btn_select	= GetDlgItem(hDlg, IDC_BTN_SELECTMEMBER);
	hselect_check_pw	= GetDlgItem(hDlg, IDC_CHECK_SELECT_PW);
}

void ui_select_Invoke(HWND hDlg)
{
	TCHAR id[20];
	GetWindowText(hselect_edit_id, id, _countof(id));

	try
	{
		select_data_check(id);
		con_SelectMember(hDlg, id);
	}
	catch (const TCHAR* msg)
	{
		SetWindowText(hselect_static_msg, msg);
	}
}

void select_data_check(TCHAR* id)
{
	if (_tcslen(id) == 0 )
		throw TEXT("모든 정보를 입력하세요");
}

void ui_select_CheckBox_Invoke(HWND hDlg)
{	
	if (SendMessage(hselect_check_pw, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
	{
		SendMessage(hselect_edit_pw, EM_SETPASSWORDCHAR, (WPARAM)'*', (LPARAM)'*');
		SetFocus(hselect_edit_pw);
	}
	else
	{		
		SendMessage(hselect_edit_pw, EM_SETPASSWORDCHAR, 0, 0);
		SetFocus(hselect_edit_pw);
	}	
}

void ui_select_Ack(PacketSelectMemberAck* pdata)
{

	if (pdata->result == true)
	{
		SetWindowText(hselect_edit_pw, pdata->pw);
		SetWindowText(hselect_edit_name, pdata->name);
		SetWindowText(hselect_edit_phone, pdata->phone);

		SetWindowText(hselect_static_msg, TEXT("회원 검색 성공"));
	}
	else
	{
		SetWindowText(hselect_edit_pw, pdata->pw);
		SetWindowText(hselect_edit_name, pdata->name);
		SetWindowText(hselect_edit_phone, pdata->phone);
		SetWindowText(hselect_static_msg, TEXT("회원 검색 실패"));
	}

}
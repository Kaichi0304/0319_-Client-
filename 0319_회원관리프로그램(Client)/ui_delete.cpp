//ui_delete.cpp
#include "std.h"

HWND hdelete_edit_id, hdelete_static_msg, hdelete_btn_delete;

void ui_delete_Init(HWND hDlg)
{
	hdelete_edit_id		= GetDlgItem(hDlg, IDC_EDIT_DELETE_ID);
	hdelete_static_msg	= GetDlgItem(hDlg, IDC_STATIC_DELETE_MSG);
	hdelete_btn_delete	= GetDlgItem(hDlg, IDC_BTN_DELETEMEMBER);
}

void ui_delete_Invoke(HWND hDlg)
{
	TCHAR id[20];
	GetWindowText(hdelete_edit_id, id, _countof(id));

	try
	{
		delete_data_check(id);
		con_DeleteMember(hDlg, id);
	}
	catch (const TCHAR* msg)
	{
		SetWindowText(hdelete_static_msg, msg);
	}
}
void delete_data_check(TCHAR* id)
{
	if (_tcslen(id) == 0)
		throw TEXT("모든 정보를 입력하세요");
}
void ui_delete_Ack(PacketDeleteMemberAck* pdata)
{
	if (pdata->result == true)
	{
		SetWindowText(hdelete_edit_id, TEXT(""));
		SetWindowText(hdelete_static_msg, TEXT("회원삭제 성공"));
	}
	else
	{
		SetWindowText(hdelete_edit_id, TEXT(""));
		SetWindowText(hdelete_static_msg, TEXT("회원삭제 실패"));
	}
	
}
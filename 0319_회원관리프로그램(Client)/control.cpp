//control.cpp
#include "std.h"


void con_RecvData(HWND hDlg, COPYDATASTRUCT* pdata)
{
	if (pdata->dwData == PACKET_SELECTMEMBER_RETURN)
	{
		Select_Return(hDlg, (PacketSelectMemberReturn*)pdata->lpData);
	}
}
void con_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	ipc_LogIn(hDlg, id, pw);

}

void con_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	ipc_InsertMember(hDlg, id, pw, name, phone);

}

void con_SelectMember(HWND hDlg, TCHAR* id)
{
	ipc_Select(hDlg, id);
	
}

void con_DeleteMember(HWND hDlg, TCHAR* id)
{
	ipc_Delete(hDlg, id);
	throw TEXT("회원삭제 실패");
}

void con_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone)
{
	throw TEXT("전화번호 변경 실패");
}


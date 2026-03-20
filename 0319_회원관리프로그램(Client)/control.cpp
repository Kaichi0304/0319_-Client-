//control.cpp
#include "std.h"




void con_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	ipc_LogIn(hDlg, id, pw);

}
void con_LogInMemberAck(PacketLogInMemberAck* pdata)
{
	ui_login_Ack(pdata);
}

void con_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	ipc_InsertMember(hDlg, id, pw, name, phone);


}
void con_InsertMemberAck(PacketInsertMemberAck* pdata)
{
	ui_insert_Ack(pdata);
}

void con_SelectMember(HWND hDlg, TCHAR* id)
{
	ipc_SelectMember(hDlg, id);
	
}
void con_SelectMemberAck(PacketSelectMemberAck* pdata)
{
	ui_select_Ack(pdata);
}

void con_DeleteMember(HWND hDlg, TCHAR* id)
{
	ipc_DeleteMember(hDlg, id);
	
}
void con_DeleteMemberAck(PacketDeleteMemberAck* pdata)
{
	ui_delete_Ack(pdata);
}

void con_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone)
{
	ipc_UpdateMember(hDlg, id, phone);
	
}
void con_UpdateMemberAck(PacketUpdateMemberAck* pdata)
{
	ui_update_Ack(pdata);
}

void con_GetMember(HWND hDlg)
{
	ipc_GetMemberList(hDlg);
}
void con_GetMemberListAck(PacketGetMemberListAck* pdata)
{
	ui_getlist_Ack(pdata);
}

void con_RecvData(HWND hDlg, COPYDATASTRUCT* pdata)
{
	if (pdata->dwData == PACKET_INSERTMEMBER_ACK)
	{
		con_InsertMemberAck((PacketInsertMemberAck*)pdata->lpData);
	}
	else if (pdata->dwData == PACKET_LOGINMEMBER_ACK)
	{
		con_LogInMemberAck((PacketLogInMemberAck*)pdata->lpData);
	}
	else if (pdata->dwData == PACKET_SELECTMEMBER_ACK)
	{
		con_SelectMemberAck((PacketSelectMemberAck*)pdata->lpData);
	}
	else if (pdata->dwData == PACKET_DELETEMEMBER_ACK)
	{
		con_DeleteMemberAck((PacketDeleteMemberAck*)pdata->lpData);
	}
	else if (pdata->dwData == PACKET_UPDATEMEMBER_ACK)
	{
		con_UpdateMemberAck((PacketUpdateMemberAck*)pdata->lpData);
	}
	else if (pdata->dwData == PACKET_GETMEMBERLIST_ACK)
	{
		con_GetMemberListAck((PacketGetMemberListAck*)pdata->lpData);
	}
}


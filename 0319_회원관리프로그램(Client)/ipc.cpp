//ipc.cpp
#include "std.h"

#define SERVER_NAME   TEXT("회원관리서버")

void SendData(void* packet, int size, int flag)
{
	HWND hTarget = FindWindow(0, SERVER_NAME);
	if (hTarget == 0)
		throw TEXT("서버 찾기 실패");

	COPYDATASTRUCT cs;
	cs.cbData = size;			//실제 보낼 데이터 크기*
	cs.lpData = packet;			//보낼 데이터의 주소
	cs.dwData = flag;			//내 맘대로

	SendMessage(hTarget, WM_COPYDATA, 0, (LPARAM)&cs);
	
}

void ipc_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	PacketLogIn packet = ipc_pack_LogIn(hDlg, id, pw);
	SendData(&packet, sizeof(packet), packet.flag);
	
}

void ipc_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	PacketInsertMember packet =  ipc_pack_InsertMember(hDlg, id, pw, name, phone);

	SendData(&packet, sizeof(packet), packet.flag);
	
}
void ipc_SelectMember(HWND hDlg,TCHAR* id)
{
	PacketSelectMember packet = ipc_pack_SelectMember(hDlg, id);
	SendData(&packet, sizeof(packet), packet.flag);
	
}
void ipc_DeleteMember(HWND hDlg,TCHAR* id)
{
	PacketDeleteMember packet = ipc_pack_DeleteMember(hDlg, id);
	SendData(&packet, sizeof(packet), packet.flag);
	
}
void ipc_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone)
{
	PacketUpdateMember packet = ipc_pack_UpdateMember(hDlg, id,phone);
	SendData(&packet, sizeof(packet), packet.flag);
	

}

void ipc_GetMemberList(HWND hDlg)		//여기수정
{
	PacketGetMemberList packet = ipc_pack_GetMemberList(hDlg);
	SendData(&packet, sizeof(packet), packet.flag);
	
}


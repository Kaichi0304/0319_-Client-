//ipc.cpp
#include "std.h"

#define SERVER_NAME   TEXT("회원관리서버")

bool SendData(void* packet, int size, int flag)
{
	HWND hTarget = FindWindow(0, SERVER_NAME);
	if (hTarget == 0)
		throw TEXT("서버 찾기 실패");

	COPYDATASTRUCT cs;
	cs.cbData = size;			//실제 보낼 데이터 크기*
	cs.lpData = packet;			//보낼 데이터의 주소
	cs.dwData = flag;			//내 맘대로

	SendMessage(hTarget, WM_COPYDATA, 0, (LPARAM)&cs);
	return true;
}

void ipc_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	PacketLogIn packet = ipc_pack_LogIn(hDlg, id, pw);
	bool b = SendData(&packet, sizeof(packet), packet.flag);
	if (b == false)
	{
		throw TEXT("로그인 실패");
	}
}

void ipc_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	PacketInsertMember packet =  ipc_pack_InsertMember(hDlg, id, pw, name, phone);

	bool b = SendData(&packet, sizeof(packet), packet.flag);
	if (b == false)
	{
		throw TEXT("회원가입 실패");
	}
}
void ipc_Select(HWND hDlg,TCHAR* id)
{
	PacketSelectMember packet = ipc_pack_SelectMember(hDlg, id);
	bool b = SendData(&packet, sizeof(packet), packet.flag);
	if (b == false)
	{
		throw TEXT("회원검색 실패");
	}
}
void ipc_Delete(HWND hDlg,TCHAR* id)
{
	PacketSelectMember packet = ipc_pack_DeleteMember(hDlg, id);
	bool b = SendData(&packet, sizeof(packet), packet.flag);
	if (b == false)
	{
		throw TEXT("회원삭제 실패");
	}
}

INT_PTR OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_RecvData(hDlg, (COPYDATASTRUCT*)lParam);

	return TRUE;
}


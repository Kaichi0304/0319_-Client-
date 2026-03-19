//ipc_packet.h
#pragma once

#define PACKET_LOGIN			1
#define PACKET_INSERTMEMBER		2
#define PACKET_SELECTMEMBER		3
#define PACKET_SELECTMEMBER_RETURN 4
#define PACKET_DELETEMEMBER			5

struct PacketLogIn
{
	int flag;
	HWND hDlg;
	TCHAR id[20];
	TCHAR pw[20];
};

struct PacketInsertMember
{
	int flag;
	HWND hDlg;
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	TCHAR phone[20];
};

struct PacketSelectMember
{
	int flag;
	HWND hDlg;
	TCHAR id[20];
};
struct PacketSelectMemberReturn
{
	int flag;
	HWND hDlg;
	TCHAR pw[20];
	TCHAR name[20];
	TCHAR phone[20];
};

PacketLogIn ipc_pack_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
PacketInsertMember ipc_pack_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);

PacketSelectMember ipc_pack_SelectMember(HWND hDlg,TCHAR* id);

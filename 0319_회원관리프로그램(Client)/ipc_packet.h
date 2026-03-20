//ipc_packet.h
#pragma once
#define PACKET_SELECTMEMBER_RETURN		7
#define PACKET_LOGIN					1
#define PACKET_INSERTMEMBER				2
#define PACKET_SELECTMEMBER				3
#define PACKET_DELETEMEMBER				4
#define PACKET_UPDATEMEMBER				5
#define PACKET_GETMEMBERLIST			6
//Server -> Client
#define PACKET_INSERTMEMBER_ACK			11
#define PACKET_DELETEMEMBER_ACK			12
#define PACKET_UPDATEMEMBER_ACK			13
#define PACKET_LOGINMEMBER_ACK			14
#define PACKET_SELECTMEMBER_ACK			15
#define PACKET_GETMEMBERLIST_ACK		16




//Client -> Server
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
typedef struct PacketSelectMember PacketDeleteMember;
struct PacketUpdateMember
{
	int flag;
	HWND hDlg;
	TCHAR id[20];
	TCHAR phone[20];
};
struct PacketGetMemberList
{
	int flag;
	HWND hDlg;
	
};

//Server -> Client
struct PacketInsertMemberAck
{
	int flag;
	bool result;
	TCHAR id[20];

};
typedef struct PacketInsertMemberAck PacketDeleteMemberAck;
typedef struct PacketInsertMemberAck PacketUpdateMemberAck;
struct PacketLogInMemberAck
{
	int flag;
	HWND hDlg;
	bool result;
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	TCHAR phone[20];
};
typedef struct PacketLogInMemberAck PacketSelectMemberAck;
struct PacketGetMemberListAck
{
	int flag;
	int size;
	MEMBER members[20];
};

PacketLogIn ipc_pack_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
PacketInsertMember ipc_pack_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);

PacketSelectMember ipc_pack_SelectMember(HWND hDlg,TCHAR* id);
PacketDeleteMember ipc_pack_DeleteMember(HWND hDlg, TCHAR* id);

PacketUpdateMember ipc_pack_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone);

PacketGetMemberList ipc_pack_GetMemberList(HWND hDlg);
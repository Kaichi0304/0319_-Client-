//ipc_packet.cpp
#include "std.h"

PacketLogIn ipc_pack_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	PacketLogIn packet;

	packet.flag = PACKET_LOGIN;
	packet.hDlg = hDlg;
	_tcscpy_s(packet.id, _countof(packet.id), id);
	_tcscpy_s(packet.pw, _countof(packet.pw), pw);

	return packet; 
}

PacketInsertMember ipc_pack_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	PacketInsertMember packet;

	packet.flag = PACKET_INSERTMEMBER;
	packet.hDlg = hDlg;
	_tcscpy_s(packet.id, _countof(packet.id), id);
	_tcscpy_s(packet.pw, _countof(packet.pw), pw);
	_tcscpy_s(packet.name, _countof(packet.name), name);
	_tcscpy_s(packet.phone, _countof(packet.phone), phone);

	return packet;
}

PacketSelectMember ipc_pack_SelectMember(HWND hDlg, TCHAR* id)
{
	PacketSelectMember packet;
	packet.flag = PACKET_SELECTMEMBER;
	packet.hDlg = hDlg;
	_tcscpy_s(packet.id, _countof(packet.id), id);

	return packet;
}
PacketDeleteMember ipc_pack_DeleteMember(HWND hDlg, TCHAR* id)
{
	PacketDeleteMember packet;
	packet.flag = PACKET_DELETEMEMBER;
	packet.hDlg = hDlg;
	_tcscpy_s(packet.id, _countof(packet.id), id);
	return packet;
}

PacketUpdateMember ipc_pack_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone)
{
	PacketUpdateMember packet;
	packet.flag = PACKET_UPDATEMEMBER;
	packet.hDlg = hDlg;
	_tcscpy_s(packet.id, _countof(packet.id), id);
	_tcscpy_s(packet.phone, _countof(packet.phone), phone);

	return packet;


}
PacketGetMemberList ipc_pack_GetMemberList(HWND hDlg)
{
	PacketGetMemberList packet;
	packet.flag = PACKET_GETMEMBERLIST;
	packet.hDlg = hDlg;
	return packet;
}
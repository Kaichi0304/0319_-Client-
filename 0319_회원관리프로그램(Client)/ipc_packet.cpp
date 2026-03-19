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
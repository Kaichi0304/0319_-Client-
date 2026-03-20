//control.h
#pragma once



//client -> server
void con_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
void con_LogInMemberAck(PacketLogInMemberAck* pdata);

void con_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);
void con_InsertMemberAck(PacketInsertMemberAck* pdata);

void con_SelectMember(HWND hDlg, TCHAR* id);
void con_SelectMemberAck(PacketSelectMemberAck* pdata);

void con_DeleteMember(HWND hDlg, TCHAR* id);
void con_DeleteMemberAck(PacketDeleteMemberAck*pdata);

void con_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone);
void con_UpdateMemberAck(PacketUpdateMemberAck* pdata);

void con_GetMember(HWND hDlg);
void con_GetMemberListAck(PacketGetMemberListAck* pdata);

// server->client 
void con_RecvData(HWND hDlg, COPYDATASTRUCT* pdata);
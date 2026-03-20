//ipc.h
#pragma once

//서버 전송 역할
void SendData(void* packet, int size, int flag);

void ipc_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
void ipc_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);
void ipc_SelectMember(HWND hDlg, TCHAR* id);
void ipc_DeleteMember(HWND hDlg, TCHAR* id);
void ipc_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone);
void ipc_GetMemberList(HWND hDlg);
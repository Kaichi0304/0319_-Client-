//ipc.h
#pragma once

//서버 전송 역할
bool SendData(void* packet, int size, int flag);

void ipc_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
void ipc_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);
void ipc_Select(HWND hDlg, TCHAR* id);

INT_PTR OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam);
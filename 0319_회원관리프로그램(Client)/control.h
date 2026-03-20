//control.h
#pragma once

void con_RecvData(HWND hDlg, COPYDATASTRUCT* pdata);

void con_LogIn(HWND hDlg, TCHAR* id, TCHAR* pw);
void con_InsertMember(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);
void con_SelectMember(HWND hDlg, TCHAR* id);
void con_DeleteMember(HWND hDlg, TCHAR* id);
void con_UpdateMember(HWND hDlg, TCHAR* id, TCHAR* phone);

void con_GetMember(HWND hDlg, TCHAR* id, TCHAR* phone);


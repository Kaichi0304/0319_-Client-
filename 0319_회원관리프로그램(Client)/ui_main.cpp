//ui_main.cpp
#include "std.h"

void ui_main_Init(HWND hDlg)
{
	ui_login_Init(hDlg);
	ui_insert_Init(hDlg);
	ui_select_Init(hDlg);
	ui_delete_Init(hDlg);
	ui_update_Init(hDlg);
	ui_printall_Init(hDlg);
}

void ui_main_LogIn(HWND hDlg)
{
	ui_login_Invoke(hDlg);
}

void ui_main_Insert(HWND hDlg)
{
	ui_insert_Invoke(hDlg);
}

void ui_main_Select(HWND hDlg)
{
	ui_select_Invoke(hDlg);
}

void ui_main_Select_Check(HWND hDlg)
{
	ui_select_CheckBox_Invoke(hDlg);
}

void ui_main_Delete(HWND hDlg)
{
	ui_delete_Invoke(hDlg);
}

void ui_main_Update(HWND hDlg)
{
	ui_update_Invkoe(hDlg);
}

void ui_main_MemberList(HWND hDlg)
{
	ui_printall_Invkoe(hDlg);
}
//ui_printall.cpp
#include "std.h"

HWND hprint_listbox, hprint_btn_list;

void ui_printall_Init(HWND hDlg)
{
	hprint_listbox = GetDlgItem(hDlg, IDC_LIST_MEMBERLIST);
	hprint_btn_list = GetDlgItem(hDlg, IDC_BTN_MEMBERLIST);
}

void ui_printall_Invkoe(HWND hDlg)
{
	//con_GetMemberList(hDlg);
}
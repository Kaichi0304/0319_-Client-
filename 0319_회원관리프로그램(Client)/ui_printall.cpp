//ui_printall.cpp
#include "std.h"

vector<MEMBER*> members;

HWND hprint_listbox, hprint_btn_list;

void ui_printall_Init(HWND hDlg)
{
	hprint_listbox = GetDlgItem(hDlg, IDC_LIST_MEMBERLIST);
	hprint_btn_list = GetDlgItem(hDlg, IDC_BTN_MEMBERLIST);
}

void ui_printall_Invkoe(HWND hDlg)
{
	con_GetMember(hDlg);
}
void ui_getlist_Ack(PacketGetMemberListAck* pdata)
{
	SendMessage(hprint_listbox, LB_RESETCONTENT, 0, 0);
	for (int i = 0; i < pdata->size; i++)
	{
		MEMBER member = pdata->members[i];
		TCHAR buf[100];
		wsprintf(buf, TEXT("ID: %s \t 이름: %s \t 전화: %s"), member.id, member.name, member.phone);	//비번은 제외
		SendMessage(hprint_listbox, LB_ADDSTRING, 0, (LPARAM)buf);
		
		
	}
	
}
//handler.cpp
#include "std.h"

INT_PTR OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	ui_main_Init(hDlg);

	return TRUE;
}

INT_PTR OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam)) 
	{
	case IDCANCEL: EndDialog(hDlg, IDCANCEL);  return TRUE;
	//로그인 버튼
	case IDC_BTN_LOGIN:			ui_main_LogIn(hDlg);	return TRUE;
	//회원가입 버튼
	case IDC_BTN_ADDMEMBER:		ui_main_Insert(hDlg);	return TRUE;
	//회원검색 버튼
	case IDC_BTN_SELECTMEMBER:	ui_main_Select(hDlg); return TRUE;
	//패스워드 보기 체크박스
	case IDC_CHECK_SELECT_PW:	ui_main_Select_Check(hDlg); return TRUE;
	//회원삭제 버튼
	case IDC_BTN_DELETEMEMBER:	ui_main_Delete(hDlg); return TRUE;
	//전화번호변경 버튼
	case IDC_BTN_UPDATEMEMBER:	ui_main_Update(hDlg); return TRUE;
	//회원리스트 보기 버튼
	case IDC_BTN_MEMBERLIST:	ui_main_MemberList(hDlg); return TRUE;
	}
	return 0;
}

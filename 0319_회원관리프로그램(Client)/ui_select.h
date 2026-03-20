//ui_select.h
#pragma once

void ui_select_Init(HWND hDlg);

void ui_select_Invoke(HWND hDlg);
void select_data_check(TCHAR* id);

void ui_select_CheckBox_Invoke(HWND hDlg);

void ui_select_Ack(PacketSelectMemberAck* pdata);

//void Select_Return(HWND hDlg, PacketSelectMemberReturn* pdata);
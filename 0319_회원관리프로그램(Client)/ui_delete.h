//ui_delete.h
#pragma once

void ui_delete_Init(HWND hDlg);

void ui_delete_Invoke(HWND hDlg);
void delete_data_check(TCHAR* id);

void ui_delete_Ack(PacketDeleteMemberAck* pdata);

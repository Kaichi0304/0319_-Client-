//ui_insert.h
#pragma once

//Client -> Server
void ui_insert_Init(HWND hDlg);

void ui_insert_Invoke(HWND hDlg);
void insert_data_check(TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone);
// Server->Client 

void ui_insert_Ack(PacketInsertMemberAck* pdata);
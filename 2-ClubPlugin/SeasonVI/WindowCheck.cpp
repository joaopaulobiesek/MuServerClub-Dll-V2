#include "pch.h"

CWindowCheck gWindowCheck;

CWindowCheck::CWindowCheck()
{

}

CWindowCheck::~CWindowCheck()
{

}

void CWindowCheck::Scan()
{
	HWND WindowHwnd;
	//if (CHeckCheat == 1)
	//{
		for (std::vector<WNDW_LIST_INFO>::iterator it = gListManager.gWindowListInfo.begin(); it != gListManager.gWindowListInfo.end(); it++)
		{
			switch (it->type)
			{
			case WINDOW_NAME:
				if ((WindowHwnd = FindWindowExA(0, 0, 0, it->text)) != 0)
				{
					DWORD pid = 0;
					GetWindowThreadProcessId(WindowHwnd, &pid);
					gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_WINDOW_DETECTION, it->text, pid);
					//gProtocol.ClientHideShowSend(NameAccount, it->text, 2);
					return;
				}
				break;
			case WINDOW_CLASS:
				if ((WindowHwnd = FindWindowExA(0, 0, it->text, 0)) != 0)
				{
					DWORD pid = 0;
					GetWindowThreadProcessId(WindowHwnd, &pid);
					gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_WINDOW_DETECTION, it->text, pid);
					//gProtocol.ClientHideShowSend(NameAccount, it->text, 2);
					return;
				}
				break;
			}
		}
	//}
}

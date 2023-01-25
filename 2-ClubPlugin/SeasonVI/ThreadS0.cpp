#include "pch.h"

CThreadS0 gThreadS0;

CThreadS0::CThreadS0() // OK
{
	this->GET_HWND = 0;
	this->Count = 0;
	this->GetAntLag = 0;
}

CThreadS0::~CThreadS0() // OK
{
}

void CThreadS0::Init()
{
	switch (*(DWORD*)(gOffsetS0.MAIN_SCREEN_STATE))
	{
	case SelectServer_2:
		gWindowCheck.CHeckCheat = 0;
		this->Count = 0;
		if (this->GET_HWND == 0)
		{
			this->GET_HWND = 1;
			gMapName.Scan();
			this->BaseAddress = (DWORD)GetModuleHandle("Main.dll");
			this->SelectServerThread(0);
		}
		else if (this->GET_HWND == 3 || this->GET_HWND == 4)
		{
			this->GET_HWND = 2;
			this->SelectServerThread(1);
		}
		break;
	case SwitchCharacter_2:
		gWindowCheck.CHeckCheat = 0;
		if (this->GET_HWND == 1 || this->GET_HWND == 2)
		{
			if (this->Count < 5) this->Count++;
			if (this->Count == 3)
			{
				this->GET_HWND = 3;
				gMain.hWnd = GetForegroundWindow();
				this->SwitchCharacterThread(0);
			}
		}
		break;
	case GameProcess_2:
		gWindowCheck.CHeckCheat = 1;
		this->Count = 0;
		if (this->GET_HWND == 3)
		{
			this->GET_HWND = 4;
			this->GameProcessThread(1);
		}
		this->GetAntLag++;
		if (this->GetAntLag >= 10)
		{
			this->GetAntLag = 0;
			if (gFeatures.antiLag != 0) { /*gAntiLagS0.ActiveDisabled(1);*/ }
		}
		this->GameProcessThread(0);
		break;
	default:
		break;
	}
}

void CThreadS0::SelectServerThread(int Cod_ID)
{
}

void CThreadS0::SwitchCharacterThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		char* GetAccountN = (char*)gOffset.AccountAddress;
		if (gOffset.PortNumberAddress != 0) gProtocol.PortNumber = *(DWORD*)(this->BaseAddress + (DWORD)gOffset.PortNumberAddress);
		wsprintf(gThread.NameAccount, GetAccountN);
		gProtocol.ClientConnectSend();
	}
}

void CThreadS0::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		int Map;
		char* name;
		Map = *(DWORD*)(gOffsetS0.MAIN_MAP_CODE);
		name = (char*)gOffset.AccountAddress;

		if (gProtocol.ActiveWindowName)
		{
			DWORD hour = gClock.m_ClockMain.DateHour;
			DWORD minute = gClock.m_ClockMain.DateMinute;
			DWORD second = gClock.m_ClockMain.DateSecond;

			gProcessWindowS0.SetWindowName(name, Map, hour, minute, second);
		}
	}
	else
	{
		//if (gFeatures.antiLag != 0)
			//gAntiLagS0.ActiveDisabled(0);
	}
}
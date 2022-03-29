#include "pch.h"

CThreadS6 gThreadS6;

CThreadS6::CThreadS6() // OK
{
	this->GET_HWND = 0;
	this->Count = 0;
	this->GetAntLag = 0;
}

CThreadS6::~CThreadS6() // OK
{

}

void CThreadS6::Init()
{
	switch (*(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE))
	{
	case SelectServer_2:
		gWindowCheck.CHeckCheat = 0;
		gSpeed.CHeckSpeed = 0;
		if (this->GET_HWND == 0)
		{
			this->GET_HWND = 1;
			gMain.hWnd = *(HWND*)(gOffset.HwndAddress);
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
		gSpeed.CHeckSpeed = 0;
		if (this->GET_HWND == 1 || this->GET_HWND == 2)
		{
			this->Count++;
			if (this->Count == 3)
			{
				this->GET_HWND = 3;
				this->SwitchCharacterThread(0);
			}
		}
		break;
	case GameProcess_2:
		gWindowCheck.CHeckCheat = 1;
		gSpeed.CHeckSpeed = 1;
		if (this->GET_HWND == 3)
		{
			this->GET_HWND = 4;
			this->GameProcessThread(1);
		}
		this->GetAntLag++;
		if (this->GetAntLag >= 10)
		{
			this->GetAntLag = 0;
			if (gFeatures.antiLag != 0) { gAntiLagS6.ActiveDisabled(1); }
		}
		this->GameProcessThread(0);
		break;
	default:
		break;
	}
}

void CThreadS6::SelectServerThread(int Cod_ID)
{
}

void CThreadS6::SwitchCharacterThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		char* GetAccountN = (char*)gOffset.AccountAddress;
		wsprintf(gThread.NameAccount, GetAccountN);
		gProtocol.ClientConnectSend();
	}
}

void CThreadS6::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		this->BaseAddress = (DWORD)GetModuleHandle("Main.dll");
		lpViewObj lpViewPlayer = &*(ObjectPreview*)*(int*)(gOffsetS6.MAIN_VIEWPORT_STRUCT);

		DWORD Map = *(DWORD*)(gOffsetS6.MAIN_MAP_CODE);
		DWORD PosX = lpViewPlayer->MapPosX;
		DWORD PosY = lpViewPlayer->MapPosY;

		if (gSpeed.CHeckSpeed == 1) {
			gSpeed.m_SpeedMain.Map = Map;
			gSpeed.m_SpeedMain.X = PosX;
			gSpeed.m_SpeedMain.Y = PosY;

			gSpeed.CheckLimit(Map, PosX, PosY);
		}
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS6.ActiveDisabled(0); }
	}
}
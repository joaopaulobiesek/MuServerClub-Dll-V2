#include "pch.h"

CThreadS17 gThreadS17;

CThreadS17::CThreadS17() // OK
{
	this->GET_HWND = 0;
	this->Count = 0;
	this->GetAntLag = 0;
}

CThreadS17::~CThreadS17() // OK
{

}

void CThreadS17::Init()
{
	switch (*(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE))
	{
	case SelectServer:
		gWindowCheck.CHeckCheat = 0;
		if (GET_HWND == 0)
		{
			GET_HWND = 1;
			gMain.hWnd = *(HWND*)(gOffset.HwndAddress);
			SelectServerThread(0);
		}
		else if (GET_HWND == 3 || GET_HWND == 4)
		{
			GET_HWND = 2;
			SelectServerThread(1);
		}
		break;
	case SwitchCharacter:
		gWindowCheck.CHeckCheat = 0;
		if (GET_HWND == 1 || GET_HWND == 2)
		{
			Count++;
			if (Count == 3)
			{
				GET_HWND = 3;
				SwitchCharacterThread(0);
			}
		}
		break;
	case GameProcess:
		gWindowCheck.CHeckCheat = 1;
		if (GET_HWND == 3)
		{
			GET_HWND = 4;
			GameProcessThread(1);
		}
		GetAntLag++;
		if (GetAntLag >= 10)
		{
			GetAntLag = 0;
			if (gFeatures.antiLag != 0) { gAntiLagS17.ActiveDisabled(1); }
		}
		GameProcessThread(0);
		break;
	default:
		break;
	}
}

void CThreadS17::SelectServerThread(int Cod_ID)
{
}

void CThreadS17::SwitchCharacterThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		char* GetAccountN = (char*)gOffset.AccountAddress;
		wsprintf(gThread.NameAccount, GetAccountN);
	}	
}

void CThreadS17::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		DWORD Level;
		DWORD MLevel;
		DWORD PosX;
		DWORD PosY;
		int Map;
		DWORD BaseAddress = (DWORD)GetModuleHandle("Main.dll");
		//GetCharacterN = (char*)(*(DWORD*)(gOffset.CharacterAddress)+0x54);
		Level = *(int*)(*(DWORD*)(gOffset.CharacterAddress));
		MLevel = *(int*)(*(DWORD*)(gOffset.CharacterAddress) + 0x18);
		Map = *(DWORD*)(gOffsetS17.MAIN_MAP_CODE);
		PosX = *(int*)(*(DWORD*)(gOffsetS17.MAIN_VIEWPORT_STRUCT) + 0x180);
		PosY = *(int*)(*(DWORD*)(gOffsetS17.MAIN_VIEWPORT_STRUCT) + 0x184);
		gCamera3dS17.PosX = PosX;
		gCamera3dS17.PosY = PosY;
		if (gFeatures.camera3D != 0) { gCamera3dS17.PosXC = *(DWORD*)(gOffsetS17.gCameraPosXC); }
		if (gFeatures.camera3D != 0) { gCamera3dS17.PosYC = *(DWORD*)(gOffsetS17.gCameraPosYC); }
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS17.ActiveDisabled(0); }
		if (gFeatures.camera3D != 0) {
			RECT rect;
			GetWindowRect(gMain.hWnd, &rect);
			gCamera3dS17.width = floor((float)rect.right - rect.left);
			gCamera3dS17.height = floor((float)rect.bottom - rect.top);
			gCamera3dS17.midwidth = floor((float)gCamera3dS17.width / 2);
			gCamera3dS17.midheight = floor((float)gCamera3dS17.height / 2);
			gCamera3dS17.rangewidth = floor((float)gCamera3dS17.width / 20);
			gCamera3dS17.rangeheight = floor((float)gCamera3dS17.height / 20);

			gCamera3dS17.actualz = -45;
		}
	}
}
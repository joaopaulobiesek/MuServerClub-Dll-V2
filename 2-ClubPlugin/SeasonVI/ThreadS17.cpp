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
	case SwitchCharacter:
		gWindowCheck.CHeckCheat = 0;
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
	case GameProcess:
		gWindowCheck.CHeckCheat = 1;
		if (this->GET_HWND == 3)
		{
			this->GET_HWND = 4;
			this->GameProcessThread(1);
		}
		this->GetAntLag++;
		if (this->GetAntLag >= 10)
		{
			this->GetAntLag = 0;
			if (gFeatures.antiLag != 0) { gAntiLagS17.ActiveDisabled(1); }
		}
		this->GameProcessThread(0);
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
		gProtocol.ClientConnectSend();
	}	
}

void CThreadS17::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		this->BaseAddress = (DWORD)GetModuleHandle("Main.dll");
		this->GetCharacterN = (char*)(*(DWORD*)(gOffset.CharacterAddress)+0x54);
		this->Level = *(int*)(*(DWORD*)(gOffset.CharacterAddress));
		this->MLevel = *(int*)(*(DWORD*)(gOffset.CharacterAddress) + 0x18);
		this->Map = *(DWORD*)(gOffsetS17.MAIN_MAP_CODE);
		this->PosX = *(int*)(*(DWORD*)(gOffsetS17.MAIN_VIEWPORT_STRUCT) + 0x180);
		this->PosY = *(int*)(*(DWORD*)(gOffsetS17.MAIN_VIEWPORT_STRUCT) + 0x184);
		gCamera3dS17.PosX = this->PosX;
		gCamera3dS17.PosY = this->PosY;
		if (gFeatures.camera3D != 0) { gCamera3dS17.PosXC = *(DWORD*)(gOffsetS17.gCameraPosXC); }
		if (gFeatures.camera3D != 0) { gCamera3dS17.PosYC = *(DWORD*)(gOffsetS17.gCameraPosYC); }
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS17.ActiveDisabled(0); }
		if (gFeatures.camera3D != 0) {
			GetWindowRect(gMain.hWnd, &this->rect);
			gCamera3dS17.width = floor((float)this->rect.right - this->rect.left);
			gCamera3dS17.height = floor((float)this->rect.bottom - this->rect.top);
			gCamera3dS17.midwidth = floor((float)gCamera3dS17.width / 2);
			gCamera3dS17.midheight = floor((float)gCamera3dS17.height / 2);
			gCamera3dS17.rangewidth = floor((float)gCamera3dS17.width / 20);
			gCamera3dS17.rangeheight = floor((float)gCamera3dS17.height / 20);

			gCamera3dS17.actualz = -45;
		}
	}
}
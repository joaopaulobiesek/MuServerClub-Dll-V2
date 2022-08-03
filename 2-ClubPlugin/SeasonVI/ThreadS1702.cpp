#include "pch.h"

CThreadS1702 gThreadS1702;

CThreadS1702::CThreadS1702() // OK
{
	this->GET_HWND = 0;
	this->Count = 0;
	this->GetAntLag = 0;
}

CThreadS1702::~CThreadS1702() // OK
{

}

void CThreadS1702::Init()
{
	switch (*(DWORD*)(gOffsetS1702.MAIN_SCREEN_STATE))
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
			if (gFeatures.antiLag != 0) { gAntiLagS1702.ActiveDisabled(1); }
		}
		this->GameProcessThread(0);
		break;
	default:
		break;
	}
}

void CThreadS1702::SelectServerThread(int Cod_ID)
{
}

void CThreadS1702::SwitchCharacterThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		char* GetAccountN = (char*)gOffset.AccountAddress;
		wsprintf(gThread.NameAccount, GetAccountN);
		gProtocol.ClientConnectSend();
	}	
}

void CThreadS1702::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		this->BaseAddress = (DWORD)GetModuleHandle("Main.dll");
		this->GetCharacterN = (char*)(*(DWORD*)(gOffset.CharacterAddress)+0x54);
		this->Level = *(int*)(*(DWORD*)(gOffset.CharacterAddress));
		this->MLevel = *(int*)(*(DWORD*)(gOffset.CharacterAddress) + 0x18);
		this->Map = *(DWORD*)(gOffsetS1702.MAIN_MAP_CODE);
		this->PosX = *(int*)(*(DWORD*)(gOffsetS1702.MAIN_VIEWPORT_STRUCT) + 0x180);
		this->PosY = *(int*)(*(DWORD*)(gOffsetS1702.MAIN_VIEWPORT_STRUCT) + 0x184);
		gCamera3dS1702.PosX = this->PosX;
		gCamera3dS1702.PosY = this->PosY;
		if (gFeatures.camera3D != 0) { gCamera3dS1702.PosXC = *(DWORD*)(gOffsetS1702.gCameraPosXC); }
		if (gFeatures.camera3D != 0) { gCamera3dS1702.PosYC = *(DWORD*)(gOffsetS1702.gCameraPosYC); }
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS1702.ActiveDisabled(0); }
		if (gFeatures.camera3D != 0) {
			GetWindowRect(gMain.hWnd, &this->rect);
			gCamera3dS1702.width = floor((float)this->rect.right - this->rect.left);
			gCamera3dS1702.height = floor((float)this->rect.bottom - this->rect.top);
			gCamera3dS1702.midwidth = floor((float)gCamera3dS1702.width / 2);
			gCamera3dS1702.midheight = floor((float)gCamera3dS1702.height / 2);
			gCamera3dS1702.rangewidth = floor((float)gCamera3dS1702.width / 20);
			gCamera3dS1702.rangeheight = floor((float)gCamera3dS1702.height / 20);

			gCamera3dS1702.actualz = -45;
		}
	}
}
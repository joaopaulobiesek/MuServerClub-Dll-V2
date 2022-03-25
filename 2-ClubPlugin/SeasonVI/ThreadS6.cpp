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
		if (this->GET_HWND == 3)
		{
			this->GET_HWND = 4;
			this->GameProcessThread(1);
		}
		this->GetAntLag++;
		if (this->GetAntLag >= 10)
		{
			this->GetAntLag = 0;
			if (gFeatures.antiLag != 0) { gAntiLagS15.ActiveDisabled(1); }
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
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS6.ActiveDisabled(0); }
		if (gFeatures.camera3D != 0) {
			GetWindowRect(gMain.hWnd, &this->rect);
			gCamera3dS6.width = floor((float)this->rect.right - this->rect.left);
			gCamera3dS6.height = floor((float)this->rect.bottom - this->rect.top);
			gCamera3dS6.midwidth = floor((float)gCamera3dS6.width / 2);
			gCamera3dS6.midheight = floor((float)gCamera3dS6.height / 2);
			gCamera3dS6.rangewidth = floor((float)gCamera3dS6.width / 20);
			gCamera3dS6.rangeheight = floor((float)gCamera3dS6.height / 20);

			gCamera3dS6.actualz = -45;
		}
	}
}
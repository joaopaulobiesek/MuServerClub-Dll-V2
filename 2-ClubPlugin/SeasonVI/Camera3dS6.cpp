#include "pch.h"

CCamera3dS6 gCamera3dS6;

CCamera3dS6::CCamera3dS6() // OK
{
}

CCamera3dS6::~CCamera3dS6() // OK
{
}

void CCamera3dS6::InitKB(int Parameter)
{
	if (gFeatures.camera3D == 0) return; // Desativa Camera 

	switch (Parameter)
	{
	case 1: //Ativar/Desativar Câmera 3D
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->m_Start.Active != 2)
			{
				this->m_Start.Active = 2;
				pDrawMessageS6("Disabled Camera 3D!", 1);
			}
			else
			{
				this->m_Start.Active = 1;
				pDrawMessageS6("Active Camera 3D!", 1);
			}
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 2: //Reseta a Câmera 3D
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			this->m_Start.Calc = 39.0;
		SetFloat((DWORD)this->m_OffSet.Zoom1, 39.0);
		SetFloat((DWORD)this->m_OffSet.Zoom2, 39.0);
		SetFloat((DWORD)this->m_OffSet.RotX, -45.0);
		SetFloat((DWORD)this->m_OffSet.RotY, -48.5);
		SetDouble((DWORD)this->m_OffSet.PosZ, 150);
		pDrawMessageS6("Reset Camera 3D!", 1);
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	default:
		break;
	}
}

void CCamera3dS6::Init()
{
	if (gFeatures.camera3D == 0) return; // Desativa Camera 

	this->m_Start.Calc = 39.0;

	this->m_Start.Active = 2;

	this->MinPercent = 50.0;

	this->MaxPercent = 130.0;

	this->Precision = 2.0;
}

void CCamera3dS6::ThreadCamS6()
{
	this->ActiveCamDelay = 0;//Faz funcionar camera Hook
}

void Zoom2S6()
{
	gCamera3dS6.ActiveCamDelay = 1;
}

void CCamera3dS6::SetIsMove(BOOL IsMove) // OK
{
	if (this->m_Start.Active == 1 && *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6)
	{
		this->m_IsMove = IsMove;
	}
}

void CCamera3dS6::SetIsAutoMove(BOOL IsMove) // OK
{
	if (this->m_Start.Active == 0 && *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6)
	{
		this->m_IsAutoMove = IsMove;
	}
}

void CCamera3dS6::SetCursor(LONG CursorX, LONG CursorY) // OK
{
	if (this->m_Start.Active == 0 || *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6)
	{
		this->m_CursorX = CursorX;
		this->m_CursorY = CursorY;
	}
}

void CCamera3dS6::Zoom(MOUSEHOOKSTRUCTEX* lpMouse)
{
	if (this->ActiveCamDelay == 1 && *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6)
	{
	}
}

void CCamera3dS6::Move(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if (this->m_Start.Active == 1 && this->m_IsMove == 1 && *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6)
	{
	}
}

void CCamera3dS6::AutoMove(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if (this->m_Start.Active == 0 && *(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE) == 6 && this->m_IsAutoMove == 1)
	{
	}
}
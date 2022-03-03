#include "pch.h"

CCamera3dS17 gCamera3dS17;

CCamera3dS17::CCamera3dS17() // OK
{
}

CCamera3dS17::~CCamera3dS17() // OK
{

}

void CCamera3dS17::InitKB(int Parameter)
{
	if (gFeatures.camera3D == 0) return; // Desativa Camera 

	switch (Parameter)
	{
	case 1: //Ativar/Desativar Câmera 3D
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (gCamera3dS17.m_Start.Active != 2)
			{
				gCamera3dS17.m_Start.Active = 2;
				pDrawMessageS17("Disabled Camera 3D!", 1);
			}
			else
			{
				gCamera3dS17.m_Start.Active = 1;
				pDrawMessageS17("Active Camera 3D!", 1);
			}
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 2: //Reseta a Câmera 3D
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			gCamera3dS17.m_Start.Calc = 39.0;
		SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom1, 39.0);
		SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom2, 39.0);
		SetFloat((DWORD)gCamera3dS17.m_OffSet.RotX, -45.0);
		SetFloat((DWORD)gCamera3dS17.m_OffSet.RotY, -48.5);
		SetDouble((DWORD)gCamera3dS17.m_OffSet.PosZ, 150);
		pDrawMessageS17("Reset Camera 3D!", 1);
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	default:
		break;
	}
}

void CCamera3dS17::Init()
{
	if (gFeatures.camera3D == 0) return; // Desativa Camera 

	this->m_Start.Calc = 39.0;

	this->m_Start.Active = 2;

	this->MinPercent = 50.0;

	this->MaxPercent = 130.0;

	this->Precision = 2.0;

	this->m_OffSet.RotY = (float*)gOffsetS17.CameraY;

	this->m_OffSet.PosZ = (double*)gOffsetS17.CameraZ;

	this->m_OffSet.RotX = (float*)gOffsetS17.CameraX;

	this->m_OffSet.Zoom1 = (float*)gOffsetS17.CameraZoom1;

	this->m_OffSet.Zoom2 = (float*)gOffsetS17.CameraZoom2;

	this->m_OffSet.Zoom3 = (float*)gOffsetS17.CameraZoom3;

	this->m_OffSet.ZoomByte = (DWORD*)gOffsetS17.CameraZoomByte;

	this->m_OffSet.ArenaCam = (BYTE*)gOffsetS17.CameraArena;

	SetByte((DWORD)this->m_OffSet.ArenaCam, 5);

	SetByte(gOffsetS17.CameraFuncNull, 0xC3);//Camera FuncNull

	MemorySet(gOffsetS17.CameraHook, 144, 0x5);//Camera Hook

	SetCompleteHook(0xE8, gOffsetS17.CameraHook, &Zoom2S17);//Camera Hook
}

void CCamera3dS17::ThreadCamS17()
{
	gCamera3dS17.ActiveCamDelay = 0;//Faz funcionar camera Hook
}

void Zoom2S17()
{
	gCamera3dS17.ActiveCamDelay = 1;
}

void CCamera3dS17::SetIsMove(BOOL IsMove) // OK
{
	if (this->m_Start.Active == 1 && *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6)
	{
		this->m_IsMove = IsMove;
	}
}

void CCamera3dS17::SetIsAutoMove(BOOL IsMove) // OK
{
	if (this->m_Start.Active == 0 && *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6)
	{
		this->m_IsAutoMove = IsMove;
	}
}

void CCamera3dS17::SetCursor(LONG CursorX, LONG CursorY) // OK
{
	if (this->m_Start.Active == 0 || *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6)
	{
		this->m_CursorX = CursorX;
		this->m_CursorY = CursorY;
	}
}

void CCamera3dS17::Zoom(MOUSEHOOKSTRUCTEX* lpMouse)
{
	if (gCamera3dS17.ActiveCamDelay == 1 && *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6)
	{
		if (((int)lpMouse->mouseData) > 0)// aproxima do char
		{
			if (gCamera3dS17.m_Start.Calc - 2.0 > 20.0)
			{
				gCamera3dS17.m_Start.Calc = gCamera3dS17.m_Start.Calc - 2.0;
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom2, (*gCamera3dS17.m_OffSet.Zoom1));
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom3, gCamera3dS17.m_Start.Calc);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom1, gCamera3dS17.m_Start.Calc);
			}
			else
			{
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom1, 20.0);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom2, 20.0);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom3, 20.0);
			}
		}
		if (((int)lpMouse->mouseData) < 0)// afasta do char
		{
			if (gCamera3dS17.m_Start.Calc + 2.0 < 88)
			{
				gCamera3dS17.m_Start.Calc = gCamera3dS17.m_Start.Calc + 2.0;
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom2, (*gCamera3dS17.m_OffSet.Zoom1));
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom3, gCamera3dS17.m_Start.Calc);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom1, gCamera3dS17.m_Start.Calc);
			}
			else
			{
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom1, 88);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom2, 88);
				SetFloat((DWORD)gCamera3dS17.m_OffSet.Zoom3, 88);
			}
		}
		gCamera3dS17.ActiveCamDelay = 0;
	}
}

void CCamera3dS17::Move(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if (this->m_Start.Active == 1 && this->m_IsMove == 1 && *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6)
	{

		if (this->m_CursorX < lpMouse->pt.x)
		{
			if ((*this->m_OffSet.RotX) > 309.0f)
			{
				SetFloat((DWORD)this->m_OffSet.RotX, -45.0f);
			}
			else
			{
				SetFloat((DWORD)this->m_OffSet.RotX, ((*this->m_OffSet.RotX) + 6.0f));
			}
		}

		if (this->m_CursorX > lpMouse->pt.x)
		{
			if ((*this->m_OffSet.RotX) < -417.0f)
			{
				SetFloat((DWORD)this->m_OffSet.RotX, -45.0f);
			}
			else
			{
				SetFloat((DWORD)this->m_OffSet.RotX, ((*this->m_OffSet.RotX) - 6.0f));
			}
		}

		if (this->m_CursorY < lpMouse->pt.y)
		{
			if ((*this->m_OffSet.RotY) < -45.0f)
			{
				SetFloat((DWORD)this->m_OffSet.RotY, ((*this->m_OffSet.RotY) + 2.420f));
				SetDouble((DWORD)this->m_OffSet.PosZ, ((*this->m_OffSet.PosZ) - 44.0f));
			}
		}

		if (this->m_CursorY > lpMouse->pt.y)
		{
			if ((*this->m_OffSet.RotY) > -90.0f)
			{
				SetFloat((DWORD)this->m_OffSet.RotY, ((*this->m_OffSet.RotY) - 2.420f));
				SetDouble((DWORD)this->m_OffSet.PosZ, ((*this->m_OffSet.PosZ) + 44.0f));
			}
		}

		this->m_CursorX = lpMouse->pt.x;
		this->m_CursorY = lpMouse->pt.y;
	}
}

void CCamera3dS17::AutoMove(MOUSEHOOKSTRUCTEX* lpMouse) // OK
{
	if (this->m_Start.Active == 0 && *(DWORD*)(gOffsetS17.MAIN_SCREEN_STATE) == 6 && this->m_IsAutoMove == 1)
	{
		if (gCamera3dS17.PosX != gCamera3dS17.PosXC || gCamera3dS17.PosY != gCamera3dS17.PosYC)
		{
			POINT point;
			GetCursorPos(&point);
			ScreenToClient(gMain.hWnd, &point);
			if (abs(gCamera3dS17.midwidth - point.x) > gCamera3dS17.rangewidth) {

				if (point.x > gCamera3dS17.midwidth)
				{
					gCamera3dS17.actualz += 3;
				}
				else
				{
					gCamera3dS17.actualz -= 3;
				}

				SetFloat((DWORD)gCamera3dS17.m_OffSet.RotX, gCamera3dS17.actualz);
			}
		}
	}
}
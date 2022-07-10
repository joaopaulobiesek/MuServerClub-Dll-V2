#include "pch.h"

CRankUserS6 gRankUserS6;

CRankUserS6::CRankUserS6()
{

}

void CRankUserS6::DrawInfo()
{

	VAngle Angle;
	// ---
	int PosX, PosY;
	float StartY = 264.0;
	float StartX = 512.0;


	for (int n = 0; n < 10000; n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void* (*)())0x00402BC0)(), n);

		if (!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress + 0x7E);

		char* name = (char*)(ViewportAddress + 0x38);

		int Class = *(WORD*)(ViewportAddress + 0x84);


		if (*(BYTE*)(ViewportAddress + 0x30C) == 0)
		{
			continue;
		}


		if (*(BYTE*)(ViewportAddress + 0xE) == 0)
		{
			continue;
		}

		if ((((pMapNumber) < 18) ? 0 : ((pMapNumber) > 23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
		{
			continue;
		}

		// ---

		Angle.X = *(float*)(ViewportAddress + 0x404);

		Angle.Y = *(float*)(ViewportAddress + 0x408);

		Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		// ---
		PosX -= 42;
		// ---

		if (!((pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 60) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85)) /* && !(GetKeyState(VK_MENU) & 0x8000)*/)
		{
			if (index >= 9000  && gInterface.CharName == 1)
			{
				gInterface.DrawFormat(eGold, (float)PosX + 32, (float)PosY - 23, 45, 1, name); // player
			}
			else if (index < 9000  && gInterface.MonsterName == 1)
			{
				gInterface.DrawFormat(eGold, (float)PosX + 21, (float)PosY - 18, 90, 1, name); // npc / monster
			}
		}

		pGLSwitch();
	}
	// ---
	//pGLSwitch();
	// ---
	glColor3f(1.0, 1.0, 1.0);
}
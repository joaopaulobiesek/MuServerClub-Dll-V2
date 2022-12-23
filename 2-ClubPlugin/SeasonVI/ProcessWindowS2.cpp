#include "pch.h"

CProcessWindowS2 gProcessWindowS2;

CProcessWindowS2::CProcessWindowS2() // OK
{
}

CProcessWindowS2::~CProcessWindowS2() // OK
{
}

void CProcessWindowS2::SetWindowName(char* WindowName, char* GetCharacter, int MapNumber) // OK
{
	char buff[256];

	sprintf_s(buff, sizeof(buff), "%s - [%s] Map: %s", WindowName, GetCharacter, gMapName.GetMap(MapNumber));

	SetWindowText(gMain.hWnd, buff);
}
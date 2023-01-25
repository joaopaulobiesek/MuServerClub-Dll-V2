#include "pch.h"

CProcessWindowS6 gProcessWindowS6;

CProcessWindowS6::CProcessWindowS6() // OK
{
}

CProcessWindowS6::~CProcessWindowS6() // OK
{
}

void CProcessWindowS6::SetWindowName(char* GetCharacter, DWORD MapNumber, DWORD PosX, DWORD PosY, DWORD Hour, DWORD Minute, DWORD Second) // OK
{
	char clockBuff[256];

	if (gProtocol.ActiveWindowClock)
	{
		if (!gProtocol.ActiveWindowWebSite)
			sprintf_s(clockBuff, sizeof(clockBuff), "| %d:%d:%d", Hour, Minute, Second);
		else
			sprintf_s(clockBuff, sizeof(clockBuff), "- %d:%d:%d", Hour, Minute, Second);
	}
	else
		sprintf_s(clockBuff, sizeof(clockBuff), "");

	char webBuff[256];
	if (gProtocol.ActiveWindowWebSite)
		sprintf_s(webBuff, sizeof(webBuff), "| %s", gProtocol.WindowWebSite);
	else
		sprintf_s(webBuff, sizeof(webBuff), "");

	char buff[256];

	sprintf_s(buff, sizeof(buff), "%s - [%s] - (%d,%d) Map: %s %s %s", gProtocol.ServerName, GetCharacter, PosX, PosY, gMapName.GetMap(MapNumber), webBuff, clockBuff);

	SetWindowText(gMain.hWnd, buff);
}
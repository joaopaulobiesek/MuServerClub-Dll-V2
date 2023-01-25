#include "pch.h"

CProcessWindowS0 gProcessWindowS0;

CProcessWindowS0::CProcessWindowS0() // OK
{
}

CProcessWindowS0::~CProcessWindowS0() // OK
{
}

void CProcessWindowS0::SetWindowName(char* GetCharacter, int MapNumber, DWORD Hour, DWORD Minute, DWORD Second) // OK
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

	sprintf_s(buff, sizeof(buff), "%s - [%s] Map: %s %s %s", gProtocol.ServerName, GetCharacter, gMapName.GetMap(MapNumber), webBuff, clockBuff);

	SetWindowText(gMain.hWnd, buff);
}
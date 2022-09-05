#include "pch.h"

CUtil gUtil;

CUtil::CUtil() // OK
{
	this->gServerCount = 0;
	wsprintf(gUtil.DataServerName, "DataServerClub");
}

CUtil::~CUtil() // OK
{
}

void CUtil::ReadStartupInfo(const char* section, const char* path) // OK
{
	GetPrivateProfileString(section, "DataServerName", "DataServerClub", this->DataServerName, sizeof(this->DataServerName), path);

	this->AdvancedLog = GetPrivateProfileInt(section, "AdvancedLog", 0, path);

	this->DataServerPort = GetPrivateProfileInt(section, "Port", 55860, path);
}

void CUtil::ReadStartupDS(const char* section, const char* path, int debug) // OK
{
	char DataServerODBC[32] = { 0 };

	char DataServerUSER[32] = { 0 };

	char DataServerPASS[32] = { 0 };

	GetPrivateProfileString(section, "ODBC", "", DataServerODBC, sizeof(DataServerODBC), ".\\DataServer.ini");

	GetPrivateProfileString(section, "USER", "", DataServerUSER, sizeof(DataServerUSER), ".\\DataServer.ini");

	GetPrivateProfileString(section, "PASS", "", DataServerPASS, sizeof(DataServerPASS), ".\\DataServer.ini");

	if (gQueryManager.Connect(DataServerODBC, DataServerUSER, DataServerPASS) == 0 && debug == 0)
	{
		gUtil.LogAdd(LOG_RED, "Could not connect to database");
	}
	else
	{
		LogAdd(LOG_BLUE, "Connected to database");

		if (gSocketManager.Start(gUtil.DataServerPort) == 0)
		{
			gQueryManager.Disconnect();
		}
		else
		{
			gAllowableIpList.Load("Data\\AllowableIpList.txt");

			gBadSyntax.Load("Data\\BadSyntax.txt");
		}
	}
}

void CUtil::ErrorMessageBox(const char* message, ...) // OK
{
	char buff[256];

	memset(buff, 0, sizeof(buff));

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	MessageBox(0, buff, "Error", MB_OK | MB_ICONERROR);

	ExitProcess(0);
}

void CUtil::LogAdd(eLogColor color, const char* text, ...) // OK
{
	tm today;
	time_t ltime;
	time(&ltime);

	if (localtime_s(&today, &ltime) != 0)
	{
		return;
	}

	char time[32];

	if (asctime_s(time, sizeof(time), &today) != 0)
	{
		return;
	}

	char temp[1024];

	va_list arg;
	va_start(arg, text);
	vsprintf_s(temp, text, arg);
	va_end(arg);

	char log[1024];

	wsprintf(log, "%.8s %s", &time[11], temp);

	gServerDisplayer.LogAddText(color, log, strlen(log));
}

bool CUtil::GetCharacterSlot(char CharacterName[5][11], char* name, BYTE* slot) // OK
{
	for (int n = 0; n < 5; n++)
	{
		if (_stricmp(CharacterName[n], name) == 0)
		{
			(*slot) = n;
			return 1;
		}
	}

	return 0;
}

bool CUtil::CheckTextSyntax(char* text, int size) // OK
{
	for (int n = 0; n < size; n++)
	{
		if (text[n] == 0x20 || text[n] == 0x22 || text[n] == 0x27)
		{
			return 0;
		}
	}

	return 1;
}

int CUtil::GetFreeServerIndex() // OK
{
	int index = -1;
	int count = this->gServerCount;

	if (SearchFreeServerIndex(&index, 0, MAX_SERVER, 10000) != 0)
	{
		return index;
	}

	for (int n = 0; n < MAX_SERVER; n++)
	{
		if (gServerManager[count].CheckState() == 0)
		{
			return count;
		}
		else
		{
			count = (((++count) >= MAX_SERVER) ? 0 : count);
		}
	}

	return -1;
}

int CUtil::SearchFreeServerIndex(int* index, int MinIndex, int MaxIndex, DWORD MinTime) // OK
{
	DWORD CurOnlineTime = 0;
	DWORD MaxOnlineTime = 0;

	for (int n = MinIndex; n < MaxIndex; n++)
	{
		if (gServerManager[n].CheckState() == 0 && gServerManager[n].CheckAlloc() != 0)
		{
			if ((CurOnlineTime = (GetTickCount() - gServerManager[n].m_OnlineTime)) > MinTime && CurOnlineTime > MaxOnlineTime)
			{
				(*index) = n;
				MaxOnlineTime = CurOnlineTime;
			}
		}
	}

	return (((*index) == -1) ? 0 : 1);
}

/*WORD GetServerCodeByName(char* name) // OK
{
	CHARACTER_INFO CharacterInfo;

	if (gCharacterManager.GetCharacterInfo(&CharacterInfo, name) == 0)
	{
		return 0xFFFF;
	}
	else
	{
		return CharacterInfo.GameServerCode;
	}
}*/

CServerManager* CUtil::FindServerByCode(WORD ServerCode) // OK
{
	for (int n = 0; n < MAX_SERVER; n++)
	{
		if (gServerManager[n].CheckState() != 0 && gServerManager[n].m_ServerCode == ServerCode)
		{
			return &gServerManager[n];
		}
	}

	return 0;
}
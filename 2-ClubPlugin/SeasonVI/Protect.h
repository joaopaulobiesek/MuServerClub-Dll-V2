// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "Message.h"
#include "MapName.h"

struct MAIN_FILE_INFO
{
	char IpAddress[32];
	WORD ServerPort;
	int removeSplash;
	char SerialMD5[32];
	char SplashName[32];
	char CameraName[32];
	DWORD CameraCRC32;
	MESSAGE_INFO EngMessageInfo[MAX_MESSAGE];
	MESSAGE_INFO PorMessageInfo[MAX_MESSAGE];
	MESSAGE_INFO SpnMessageInfo[MAX_MESSAGE];
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool ReadDllFile(char* name);
	char JoinsNameEnd[150];
	char KeyStart[50];
	char KeyStartProcess[100];
public:
	MAIN_FILE_INFO m_MainInfo;
	DWORD m_ClientFileCRC;
};

extern CProtect gProtect;

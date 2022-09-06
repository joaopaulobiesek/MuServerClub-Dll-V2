#pragma once

#include "ServerDisplayer.h"
#include "ServerManager.h"


class CUtil
{
public:
	CUtil();
	virtual ~CUtil();
	void ErrorMessageBox(const char* message, ...);
	void LogAdd(eLogColor color,const char* text, ...);
	bool GetCharacterSlot(char CharacterName[5][11], char* name, BYTE* slot);
	bool CheckTextSyntax(char* text, int size);
	int GetFreeServerIndex();
	int SearchFreeServerIndex(int* index, int MinIndex, int MaxIndex, DWORD MinTime);
	void ReadStartupInfo(const char* section, const char* path);
	void ReadStartupDS(const char* section, const char* path, int debug);
	//WORD GetServerCodeByName(char* name);
	CServerManager* FindServerByCode(WORD ServerCode);
public:
	int gServerCount;
	int AdvancedLog;
	int DataServerPort;
	char DataServerName[16];
};

extern CUtil gUtil;

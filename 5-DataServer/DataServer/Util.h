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
	//WORD GetServerCodeByName(char* name);
	CServerManager* FindServerByCode(WORD ServerCode);
public:
	int gServerCount;
};

extern CUtil gUtil;

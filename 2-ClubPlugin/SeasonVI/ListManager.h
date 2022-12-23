// ListManager.h: interface for the CListManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

struct DUMP_LIST_INFO
{
	BYTE type;
	DWORD offset;
	BYTE dump[32];
	char name[32];
};

struct CSUM_LIST_INFO
{
	char path[MAX_PATH];
	DWORD checksum;
};

struct ITRN_LIST_INFO
{
	BYTE type;
	char value[MAX_PATH];
};

struct WNDW_LIST_INFO
{
	BYTE type;
	char text[64];
};

enum DUMP_LIST_TYPE
{
	TYPE_DUMP = 0,
	TYPE_AUX = 1,
};

enum INTERNAL_LIST_TYPE
{
	INTERN_MAPPING = 0,
	INTERN_LIBRARY = 1,
	INTERN_REGISTRY = 2,
};

enum WINDOW_LIST_TYPE
{
	WINDOW_NAME = 0,
	WINDOW_CLASS = 1,
};

struct CUSTOMMONSTER_DATA
{
	int Index;
	WORD ID;
	BYTE Type;
	char Name[25];
	char Dir[50];
	char Folder[50];
	char BMDFile[50];
	float Size;
};

struct NPCNAME_DATA
{
	int Index;
	int NPCId;
	int Map;
	int X;
	int Y;
	char Name[25];
};

struct CLOAKNAME_DATA
{
	int Index;
	int ItemIndex;
	int Mode;
	int IndexCloak;
	char CloakName[100];
	int IndexStrip;
	char StripName[100];
};

struct CUSTOM_SMOKEEFFECT
{
	int Index;
	int ItemIndex;
	float Red;
	float Green;
	float Blue;
};

struct CUSTOM_FOG
{
	int Index;
	int MapNumber;
	int Enable;
	float Red;
	float Green;
	float Blue;
};

struct MAP_NAME
{
	int Index;
	WORD MapNumber;
	char Name[30];
};

class CListManager
{
public:
	CListManager();
	virtual ~CListManager();
public:
	std::vector<DUMP_LIST_INFO> gDumpListInfo;
	std::vector<CSUM_LIST_INFO> gChecksumListInfo;
	std::vector<ITRN_LIST_INFO> gInternalListInfo;
	std::vector<WNDW_LIST_INFO> gWindowListInfo;
	std::vector<NPCNAME_DATA> gCustomNPCListInfo;
	std::vector<CUSTOMMONSTER_DATA> gCustomMonsterListInfo;
	std::vector<CLOAKNAME_DATA> gCustomCloakListInfo;
	std::vector<CUSTOM_SMOKEEFFECT> gCustomSmokeEffectListInfo;
	std::vector<CUSTOM_FOG> gCustomFogListInfo;
	std::vector<MAP_NAME> gCustomMapNameListInfo;
};

extern CListManager gListManager;

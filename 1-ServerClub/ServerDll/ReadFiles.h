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

struct EVENTNAME_DATA
{
	int Index;
	WORD Id;
	char Name[25];
};

struct EVENTNAME_HOUR_DATA
{
	int Index;
	WORD Id;
	int Year;
	int Month;
	int Day;
	int DoW;
	int Hour;
	int Minute;
	int Second;
};

class CReadFiles
{
public:
	CReadFiles();
	virtual ~CReadFiles();
	void DumpList(char* filename);
	void ChecksumList(char* filename);
	void InternalList(char* filename);
	void WindowList(char* filename);
	void CustomMonsterList(char* path);
	void CustomNPCList(char* path);
	void CustomCloakList(char* path);
	void CustomEventList(char* path);
public:
	bool ReloadSwitch;
	bool UpdateSwitch;
	std::vector<DUMP_LIST_INFO> gDumpListInfo;
	std::vector<CSUM_LIST_INFO> gChecksumListInfo;
	std::vector<ITRN_LIST_INFO> gInternalListInfo;
	std::vector<WNDW_LIST_INFO> gWindowListInfo;
	std::vector<NPCNAME_DATA> gCustomNPCListInfo;
	std::vector<CLOAKNAME_DATA> gCustomCloakListInfo;
	std::vector<EVENTNAME_DATA> gCustomEVENTListNameInfo;
	std::vector<EVENTNAME_HOUR_DATA> gCustomEVENTListHourInfo;
	std::vector<CUSTOMMONSTER_DATA> gCustomMonsterListInfo;
};

extern CReadFiles gReadFiles;
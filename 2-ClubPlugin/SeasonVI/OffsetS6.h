#pragma once

#define pDrawMessageS6 ((int(__cdecl*)(LPCSTR Text, int Mode)) gOffsetS6.pDrawMessage)

class COffsetS6
{
public:
	COffsetS6();
	virtual ~COffsetS6();
	void InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg);
	void RecvOffset(SDHP_REQUEST_OFFSET_S6_RECV* lpMsg);
public:
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_VIEWPORT_STRUCT;
	DWORD MAIN_MAP_CODE;
	DWORD pDrawMessage;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD Skill4ActiveHook;
	DWORD ZenActive;
	DWORD ItemActive;
	DWORD PetActive;
	DWORD Terrain1Active;
	DWORD RemoveSetActive;
};

extern COffsetS6 gOffsetS6;
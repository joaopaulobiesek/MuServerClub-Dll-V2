#pragma once

#define pDrawMessageS2 ((int(__cdecl*)(LPCSTR Text, int Mode)) gOffsetS2.pDrawMessage)

class COffsetS2
{
public:
	COffsetS2();
	virtual ~COffsetS2();
	void InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg);
	void RecvOffset(SDHP_REQUEST_OFFSET_S2_RECV* lpMsg);
public:
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_MAP_CODE;
	DWORD pDrawMessage;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD ItemActive;
	DWORD Terrain1Active;
};
extern COffsetS2 gOffsetS2;
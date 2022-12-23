#pragma once

class COffsetS2
{
public:
	COffsetS2();
	virtual ~COffsetS2();
	void InitOffset();
public:
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_MAP_CODE;
	DWORD pDrawMessage;
	DWORD gCameraPosXC;
	DWORD gCameraPosYC;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD ItemActive;
	DWORD Terrain1Active;
};
extern COffsetS2 gOffsetS2;
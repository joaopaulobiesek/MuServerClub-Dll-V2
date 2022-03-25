#pragma once

class COffsetS6
{
public:
	COffsetS6();
	virtual ~COffsetS6();
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
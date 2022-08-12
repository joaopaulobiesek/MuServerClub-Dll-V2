#pragma once

class COffsetS1702
{
public:
	COffsetS1702();
	virtual ~COffsetS1702();
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
	DWORD gCameraPosXC;
	DWORD gCameraPosYC;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD Skill4Active;
	DWORD Skill5Active;
	DWORD Skill6ActiveHook;
	DWORD ZenActive;
	DWORD ItemActive;
	DWORD Pet1Active;
	DWORD Pet2ActiveHook;
	DWORD Pet3Active;
	DWORD Pet4ActiveHook;
	DWORD Char1Moob1Active;
	DWORD Char1Moob2ActiveHook;
	DWORD Char2Moob3Active;
	DWORD Char2Moob4Active;
	DWORD Char2Moob5ActiveHook;
	DWORD Terrain1Active;
	DWORD Terrain2Active;
	DWORD Terrain3Active;
	DWORD Terrain4Active;
	DWORD RemoveSet1Active;
	DWORD RemoveSet2Active;
	DWORD RemoveSet3Active;
	DWORD RemoveSet4Active;
	DWORD RemoveSet5Active;
	DWORD RemoveSet6Active;
	DWORD RemoveSet7Active;
	DWORD RemoveMoob;
	DWORD CameraY;
	DWORD CameraZ;
	DWORD CameraX;
	DWORD CameraZoom1;
	DWORD CameraZoom2;
	DWORD CameraZoom3;
	DWORD CameraZoomByte;
	DWORD CameraArena;
	DWORD CameraFuncNull;
	DWORD CameraHook;
};
extern COffsetS1702 gOffsetS1702;
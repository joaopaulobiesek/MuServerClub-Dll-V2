#pragma once

class COffsetS15
{
public:
	COffsetS15();
	virtual ~COffsetS15();
	void InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg);
	void RecvOffset(SDHP_REQUEST_OFFSET_S15_RECV* lpMsg);
public:
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
	DWORD RemoveSetActive;
	DWORD HitBox1Active;
	DWORD HitBox2Active;
	DWORD HitBox3Active;
	DWORD HitBox4Active;
	DWORD HitBox5Active;
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
extern COffsetS15 gOffsetS15;
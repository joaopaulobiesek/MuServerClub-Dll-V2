#include "pch.h"

CProtocolS15 gProtocolS15;

void CProtocolS15::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x19://Season 15
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSet15((SDHP_REQUEST_OFFSET_S15_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS15((SDHP_REQUEST_KEYBOARD_S15_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS15::RequestOffSet15(SDHP_REQUEST_OFFSET_S15_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		SDHP_REQUEST_OFFSET_S15_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS15.MAIN_SCREEN_STATE;
	pMsg.MAIN_VIEWPORT_STRUCT = gOffsetS15.MAIN_VIEWPORT_STRUCT;
	pMsg.MAIN_MAP_CODE = gOffsetS15.MAIN_MAP_CODE;
	pMsg.pDrawMessage = gOffsetS15.pDrawMessage;
	if (gFeatures.camera3D == 1) {
		pMsg.gCameraPosXC = gOffsetS15.gCameraPosXC;
		pMsg.gCameraPosYC = gOffsetS15.gCameraPosYC;
	}
	if (gFeatures.antiLag == 1) {
		pMsg.WingActive = gOffsetS15.WingActive;
		pMsg.Skill1Active = gOffsetS15.Skill1Active;
		pMsg.Skill2Active = gOffsetS15.Skill2Active;
		pMsg.Skill3Active = gOffsetS15.Skill3Active;
		pMsg.Skill4Active = gOffsetS15.Skill4Active;
		pMsg.Skill5Active = gOffsetS15.Skill5Active;
		pMsg.Skill6ActiveHook = gOffsetS15.Skill6ActiveHook;
		pMsg.ZenActive = gOffsetS15.ZenActive;
		pMsg.ItemActive = gOffsetS15.ItemActive;
		pMsg.Pet1Active = gOffsetS15.Pet1Active;
		pMsg.Pet2ActiveHook = gOffsetS15.Pet2ActiveHook;
		pMsg.Pet3Active = gOffsetS15.Pet3Active;
		pMsg.Pet4ActiveHook = gOffsetS15.Pet4ActiveHook;
		pMsg.Char1Moob1Active = gOffsetS15.Char1Moob1Active;
		pMsg.Char1Moob2ActiveHook = gOffsetS15.Char1Moob2ActiveHook;
		pMsg.Char2Moob3Active = gOffsetS15.Char2Moob3Active;
		pMsg.Char2Moob4Active = gOffsetS15.Char2Moob4Active;
		pMsg.Char2Moob5ActiveHook = gOffsetS15.Char2Moob5ActiveHook;
		pMsg.Terrain1Active = gOffsetS15.Terrain1Active;
		pMsg.Terrain2Active = gOffsetS15.Terrain2Active;
		pMsg.RemoveSetActive = gOffsetS15.RemoveSetActive;
		pMsg.HitBox1Active = gOffsetS15.HitBox1Active;
		pMsg.HitBox2Active = gOffsetS15.HitBox2Active;
		pMsg.HitBox3Active = gOffsetS15.HitBox3Active;
		pMsg.HitBox4Active = gOffsetS15.HitBox4Active;
		pMsg.HitBox5Active = gOffsetS15.HitBox5Active;
	}
	if (gFeatures.camera3D == 1) {
		pMsg.CameraY = gOffsetS15.CameraY;
		pMsg.CameraZ = gOffsetS15.CameraZ;
		pMsg.CameraX = gOffsetS15.CameraX;
		pMsg.CameraZoom1 = gOffsetS15.CameraZoom1;
		pMsg.CameraZoom2 = gOffsetS15.CameraZoom2;
		pMsg.CameraZoom3 = gOffsetS15.CameraZoom3;
		pMsg.CameraZoomByte = gOffsetS15.CameraZoomByte;
		pMsg.CameraArena = gOffsetS15.CameraArena;
		pMsg.CameraFuncNull = gOffsetS15.CameraFuncNull;
		pMsg.CameraHook = gOffsetS15.CameraHook;
	}
	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS15::RequestKeyBoardS15(SDHP_REQUEST_KEYBOARD_S15_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_S15_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	pMsg.Func1 = gServerInfo.Func1;
	pMsg.Func2 = gServerInfo.Func2;
	pMsg.Func3 = gServerInfo.Func3;
	pMsg.Func4 = gServerInfo.Func4;
	pMsg.Func5 = gServerInfo.Func5;
	pMsg.Func6 = gServerInfo.Func6;
	pMsg.Func7 = gServerInfo.Func7;
	pMsg.Func8 = gServerInfo.Func8;
	pMsg.Func9 = gServerInfo.Func9;
	pMsg.Func10 = gServerInfo.Func10;
	pMsg.Func11 = gServerInfo.Func11;
	pMsg.Func12 = gServerInfo.Func12;
	pMsg.Func13 = gServerInfo.Func13;

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
}
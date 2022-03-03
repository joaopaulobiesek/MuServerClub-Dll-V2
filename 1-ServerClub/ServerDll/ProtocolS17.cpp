#include "pch.h"

CProtocolS17 gProtocolS17;

void CProtocolS17::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x21://Season 17
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSet17((SDHP_REQUEST_OFFSET_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS17((SDHP_REQUEST_KEYBOARD_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS17::RequestOffSet17(SDHP_REQUEST_OFFSET_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	SDHP_REQUEST_OFFSET_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS17.MAIN_SCREEN_STATE;
	pMsg.MAIN_VIEWPORT_STRUCT = gOffsetS17.MAIN_VIEWPORT_STRUCT;
	pMsg.MAIN_MAP_CODE = gOffsetS17.MAIN_MAP_CODE;
	pMsg.pDrawMessage = gOffsetS17.pDrawMessage;
	if (gFeatures.camera3D == 1) {
		pMsg.gCameraPosXC = gOffsetS17.gCameraPosXC;
		pMsg.gCameraPosYC = gOffsetS17.gCameraPosYC;
	}
	if (gFeatures.antiLag == 1) {
		pMsg.WingActive = gOffsetS17.WingActive;
		pMsg.Skill1Active = gOffsetS17.Skill1Active;
		pMsg.Skill2Active = gOffsetS17.Skill2Active;
		pMsg.Skill3Active = gOffsetS17.Skill3Active;
		pMsg.Skill4Active = gOffsetS17.Skill4Active;
		pMsg.Skill5Active = gOffsetS17.Skill5Active;
		pMsg.Skill6ActiveHook = gOffsetS17.Skill6ActiveHook;
		pMsg.ZenActive = gOffsetS17.ZenActive;
		pMsg.ItemActive = gOffsetS17.ItemActive;
		pMsg.Pet1Active = gOffsetS17.Pet1Active;
		pMsg.Pet2ActiveHook = gOffsetS17.Pet2ActiveHook;
		pMsg.Pet3Active = gOffsetS17.Pet3Active;
		pMsg.Pet4ActiveHook = gOffsetS17.Pet4ActiveHook;
		pMsg.Char1Moob1Active = gOffsetS17.Char1Moob1Active;
		pMsg.Char1Moob2ActiveHook = gOffsetS17.Char1Moob2ActiveHook;
		pMsg.Char2Moob3Active = gOffsetS17.Char2Moob3Active;
		pMsg.Char2Moob4Active = gOffsetS17.Char2Moob4Active;
		pMsg.Char2Moob5ActiveHook = gOffsetS17.Char2Moob5ActiveHook;
		pMsg.Terrain1Active = gOffsetS17.Terrain1Active;
		pMsg.Terrain2Active = gOffsetS17.Terrain2Active;
		pMsg.RemoveSetActive = gOffsetS17.RemoveSetActive;
	}
	if (gFeatures.camera3D == 1) {
		pMsg.CameraY = gOffsetS17.CameraY;
		pMsg.CameraZ = gOffsetS17.CameraZ;
		pMsg.CameraX = gOffsetS17.CameraX;
		pMsg.CameraZoom1 = gOffsetS17.CameraZoom1;
		pMsg.CameraZoom2 = gOffsetS17.CameraZoom2;
		pMsg.CameraZoom3 = gOffsetS17.CameraZoom3;
		pMsg.CameraZoomByte = gOffsetS17.CameraZoomByte;
		pMsg.CameraArena = gOffsetS17.CameraArena;
		pMsg.CameraFuncNull = gOffsetS17.CameraFuncNull;
		pMsg.CameraHook = gOffsetS17.CameraHook;
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS17::RequestKeyBoardS17(SDHP_REQUEST_KEYBOARD_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_SEND pMsg;

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
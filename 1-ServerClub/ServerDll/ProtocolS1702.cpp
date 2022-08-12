#include "pch.h"

CProtocolS1702 gProtocolS1702;

void CProtocolS1702::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x22://Season 17Ep2
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSetS17((SDHP_REQUEST_OFFSET_S1702_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS17((SDHP_REQUEST_KEYBOARD_S1702_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS1702::RequestOffSetS17(SDHP_REQUEST_OFFSET_S1702_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	SDHP_REQUEST_OFFSET_S1702_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS1702.MAIN_SCREEN_STATE;
	pMsg.MAIN_VIEWPORT_STRUCT = gOffsetS1702.MAIN_VIEWPORT_STRUCT;
	pMsg.MAIN_MAP_CODE = gOffsetS1702.MAIN_MAP_CODE;
	pMsg.pDrawMessage = gOffsetS1702.pDrawMessage;
	if (gFeatures.camera3D == 1) {
		pMsg.gCameraPosXC = gOffsetS1702.gCameraPosXC;
		pMsg.gCameraPosYC = gOffsetS1702.gCameraPosYC;
	}
	if (gFeatures.antiLag == 1) {
		pMsg.WingActive = gOffsetS1702.WingActive;
		pMsg.Skill1Active = gOffsetS1702.Skill1Active;
		pMsg.Skill2Active = gOffsetS1702.Skill2Active;
		pMsg.Skill3Active = gOffsetS1702.Skill3Active;
		pMsg.Skill4Active = gOffsetS1702.Skill4Active;
		pMsg.Skill5Active = gOffsetS1702.Skill5Active;
		pMsg.Skill6ActiveHook = gOffsetS1702.Skill6ActiveHook;
		pMsg.ZenActive = gOffsetS1702.ZenActive;
		pMsg.ItemActive = gOffsetS1702.ItemActive;
		pMsg.Pet1Active = gOffsetS1702.Pet1Active;
		pMsg.Pet2ActiveHook = gOffsetS1702.Pet2ActiveHook;
		pMsg.Pet3Active = gOffsetS1702.Pet3Active;
		pMsg.Pet4ActiveHook = gOffsetS1702.Pet4ActiveHook;
		pMsg.Char1Moob1Active = gOffsetS1702.Char1Moob1Active;
		pMsg.Char1Moob2ActiveHook = gOffsetS1702.Char1Moob2ActiveHook;
		pMsg.Char2Moob3Active = gOffsetS1702.Char2Moob3Active;
		pMsg.Char2Moob4Active = gOffsetS1702.Char2Moob4Active;
		pMsg.Char2Moob5ActiveHook = gOffsetS1702.Char2Moob5ActiveHook;
		pMsg.Terrain1Active = gOffsetS1702.Terrain1Active;
		pMsg.Terrain2Active = gOffsetS1702.Terrain2Active;
		pMsg.Terrain3Active = gOffsetS1702.Terrain3Active;
		pMsg.Terrain4Active = gOffsetS1702.Terrain4Active;
		pMsg.RemoveSet1Active = gOffsetS1702.RemoveSet1Active;
		pMsg.RemoveSet2Active = gOffsetS1702.RemoveSet2Active;
		pMsg.RemoveSet3Active = gOffsetS1702.RemoveSet3Active;
		pMsg.RemoveSet4Active = gOffsetS1702.RemoveSet4Active;
		pMsg.RemoveSet5Active = gOffsetS1702.RemoveSet5Active;
		pMsg.RemoveSet6Active = gOffsetS1702.RemoveSet6Active;
		pMsg.RemoveSet7Active = gOffsetS1702.RemoveSet7Active;
		pMsg.RemoveMoob = gOffsetS1702.RemoveMoob;
	}
	if (gFeatures.camera3D == 1) {
		pMsg.CameraY = gOffsetS1702.CameraY;
		pMsg.CameraZ = gOffsetS1702.CameraZ;
		pMsg.CameraX = gOffsetS1702.CameraX;
		pMsg.CameraZoom1 = gOffsetS1702.CameraZoom1;
		pMsg.CameraZoom2 = gOffsetS1702.CameraZoom2;
		pMsg.CameraZoom3 = gOffsetS1702.CameraZoom3;
		pMsg.CameraZoomByte = gOffsetS1702.CameraZoomByte;
		pMsg.CameraArena = gOffsetS1702.CameraArena;
		pMsg.CameraFuncNull = gOffsetS1702.CameraFuncNull;
		pMsg.CameraHook = gOffsetS1702.CameraHook;
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS1702::RequestKeyBoardS17(SDHP_REQUEST_KEYBOARD_S1702_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_S1702_SEND pMsg;

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
	pMsg.Func14 = gServerInfo.Func14;
	pMsg.Func15 = gServerInfo.Func15;

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
}
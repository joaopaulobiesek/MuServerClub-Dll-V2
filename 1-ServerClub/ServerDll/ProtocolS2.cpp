#include "pch.h"

CProtocolS2 gProtocolS2;

void CProtocolS2::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x11://Season 2
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSetS2((SDHP_REQUEST_OFFSET_S2_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS2((SDHP_REQUEST_KEYBOARD_S2_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS2::RequestOffSetS2(SDHP_REQUEST_OFFSET_S2_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		SDHP_REQUEST_OFFSET_S2_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS2.MAIN_SCREEN_STATE;
	pMsg.MAIN_MAP_CODE = gOffsetS2.MAIN_MAP_CODE;
	pMsg.pDrawMessage = gOffsetS2.pDrawMessage;
	if (gFeatures.antiLag == 1) {
		pMsg.WingActive = gOffsetS2.WingActive;
		pMsg.Skill1Active = gOffsetS2.Skill1Active;
		pMsg.Skill2Active = gOffsetS2.Skill2Active;
		pMsg.Skill3Active = gOffsetS2.Skill3Active;
		pMsg.ItemActive = gOffsetS2.ItemActive;
		pMsg.Terrain1Active = gOffsetS2.Terrain1Active;
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS2::RequestKeyBoardS2(SDHP_REQUEST_KEYBOARD_S2_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_S2_SEND pMsg;

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
#include "pch.h"

CProtocolS0 gProtocolS0;

void CProtocolS0::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x10://Season 0
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSetS0((SDHP_REQUEST_OFFSET_S0_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS0((SDHP_REQUEST_KEYBOARD_S0_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS0::RequestOffSetS0(SDHP_REQUEST_OFFSET_S0_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		SDHP_REQUEST_OFFSET_S0_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS0.MAIN_SCREEN_STATE;
	pMsg.MAIN_MAP_CODE = gOffsetS0.MAIN_MAP_CODE;

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS0::RequestKeyBoardS0(SDHP_REQUEST_KEYBOARD_S0_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_S0_SEND pMsg;

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
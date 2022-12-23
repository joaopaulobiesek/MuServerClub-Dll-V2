#include "pch.h"

CProtocolS2 gProtocolS2;

void CProtocolS2::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x11://Season 2
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS2.RecvOffset((SDHP_REQUEST_OFFSET_S2_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS2((SDHP_REQUEST_KEYBOARD_S2_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS2::RequestOffSetS2()
{
	SDHP_REQUEST_OFFSET_S2_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS2::RequestKeyboardS2()
{
	SDHP_REQUEST_KEYBOARD_S2_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS2::RecvKeyboardS2(SDHP_REQUEST_KEYBOARD_S2_RECV* lpMsg)
{	
	gHookKBS2.Func3 = lpMsg->Func3;
	gHookKBS2.Func4 = lpMsg->Func4;
	gHookKBS2.Func6 = lpMsg->Func6;
	gHookKBS2.Func7 = lpMsg->Func7;
	gHookKBS2.Func10 = lpMsg->Func10;
	gHookKBS2.Func11 = lpMsg->Func11;
}
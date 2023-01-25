#include "pch.h"

CProtocolS0 gProtocolS0;

void CProtocolS0::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x10://Season 0
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS0.RecvOffset((SDHP_REQUEST_OFFSET_S0_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS0((SDHP_REQUEST_KEYBOARD_S0_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS0::RequestOffSetS0()
{
	SDHP_REQUEST_OFFSET_S0_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS0::RequestKeyboardS0()
{
	SDHP_REQUEST_KEYBOARD_S0_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS0::RecvKeyboardS0(SDHP_REQUEST_KEYBOARD_S0_RECV* lpMsg)
{
	gHookKBS2.Func3 = lpMsg->Func3;
	gHookKBS2.Func4 = lpMsg->Func4;
	gHookKBS2.Func6 = lpMsg->Func6;
	gHookKBS2.Func7 = lpMsg->Func7;
	gHookKBS2.Func10 = lpMsg->Func10;
	gHookKBS2.Func11 = lpMsg->Func11;
}
#include "pch.h"

CProtocolS1702 gProtocolS1702;

void CProtocolS1702::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x22://Season 17Ep2
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS1702.RecvOffset((SDHP_REQUEST_OFFSET_S1702_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS17((SDHP_REQUEST_KEYBOARD_S1702_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS1702::RequestOffSetS17()
{
	SDHP_REQUEST_OFFSET_S1702_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS1702::RequestKeyboardS17()
{
	SDHP_REQUEST_KEYBOARD_S1702_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS1702::RecvKeyboardS17(SDHP_REQUEST_KEYBOARD_S1702_RECV* lpMsg)
{
	gHookKBS1702.Func1 = lpMsg->Func1;
	gHookKBS1702.Func2 = lpMsg->Func2;
	gHookKBS1702.Func3 = lpMsg->Func3;
	gHookKBS1702.Func4 = lpMsg->Func4;
	gHookKBS1702.Func5 = lpMsg->Func5;
	gHookKBS1702.Func6 = lpMsg->Func6;
	gHookKBS1702.Func7 = lpMsg->Func7;
	gHookKBS1702.Func8 = lpMsg->Func8;
	gHookKBS1702.Func9 = lpMsg->Func9;
	gHookKBS1702.Func10 = lpMsg->Func10;
	gHookKBS1702.Func11 = lpMsg->Func11;
	gHookKBS1702.Func12 = lpMsg->Func12;
	gHookKBS1702.Func13 = lpMsg->Func13;
}


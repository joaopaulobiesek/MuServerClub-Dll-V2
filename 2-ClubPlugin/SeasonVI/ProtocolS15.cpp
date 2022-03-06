#include "pch.h"

CProtocolS15 gProtocolS15;

void CProtocolS15::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x19://Season 15
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS15.RecvOffset((SDHP_REQUEST_OFFSET_S15_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS15((SDHP_REQUEST_KEYBOARD_S15_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS15::RequestOffSetS15()
{
	SDHP_REQUEST_OFFSET_S15_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS15::RequestKeyboardS15()
{
	SDHP_REQUEST_KEYBOARD_S15_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS15::RecvKeyboardS15(SDHP_REQUEST_KEYBOARD_S15_RECV* lpMsg)
{
	gHookKBS15.Func1 = lpMsg->Func1;
	gHookKBS15.Func2 = lpMsg->Func2;
	gHookKBS15.Func3 = lpMsg->Func3;
	gHookKBS15.Func4 = lpMsg->Func4;
	gHookKBS15.Func5 = lpMsg->Func5;
	gHookKBS15.Func6 = lpMsg->Func6;
	gHookKBS15.Func7 = lpMsg->Func7;
	gHookKBS15.Func8 = lpMsg->Func8;
	gHookKBS15.Func9 = lpMsg->Func9;
	gHookKBS15.Func10 = lpMsg->Func10;
	gHookKBS15.Func11 = lpMsg->Func11;
	gHookKBS15.Func12 = lpMsg->Func12;
	gHookKBS15.Func13 = lpMsg->Func13;
}
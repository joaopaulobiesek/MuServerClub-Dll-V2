#include "pch.h"

CProtocolS17 gProtocolS17;

void CProtocolS17::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x21://Season 17
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS17.RecvOffset((SDHP_REQUEST_OFFSET_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS17((SDHP_REQUEST_KEYBOARD_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS17::RequestOffSetS17()
{
	SDHP_REQUEST_OFFSET_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS17::RequestKeyboardS17()
{
	SDHP_REQUEST_KEYBOARD_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS17::RecvKeyboardS17(SDHP_REQUEST_KEYBOARD_RECV* lpMsg)
{
	gHookKBS17.Func1 = lpMsg->Func1;
	gHookKBS17.Func2 = lpMsg->Func2;
	gHookKBS17.Func3 = lpMsg->Func3;
	gHookKBS17.Func4 = lpMsg->Func4;
	gHookKBS17.Func5 = lpMsg->Func5;
	gHookKBS17.Func6 = lpMsg->Func6;
	gHookKBS17.Func7 = lpMsg->Func7;
	gHookKBS17.Func8 = lpMsg->Func8;
	gHookKBS17.Func9 = lpMsg->Func9;
	gHookKBS17.Func10 = lpMsg->Func10;
	gHookKBS17.Func11 = lpMsg->Func11;
	gHookKBS17.Func12 = lpMsg->Func12;
	gHookKBS17.Func13 = lpMsg->Func13;
}


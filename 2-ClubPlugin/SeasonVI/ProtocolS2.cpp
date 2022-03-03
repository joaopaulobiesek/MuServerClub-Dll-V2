#include "pch.h"

CProtocolS2 gProtocolS2;

void CProtocolS2::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x11://Season 2
		switch (lpMsg[5])
		{
		case 0x01:
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}
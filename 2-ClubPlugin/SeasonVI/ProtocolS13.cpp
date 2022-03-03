#include "pch.h"

CProtocolS13 gProtocolS13;

void CProtocolS13::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x17://Season 13
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
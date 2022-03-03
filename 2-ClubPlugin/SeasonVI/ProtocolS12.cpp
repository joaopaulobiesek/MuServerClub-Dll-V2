#include "pch.h"

CProtocolS12 gProtocolS12;

void CProtocolS12::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x16://Season 12
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
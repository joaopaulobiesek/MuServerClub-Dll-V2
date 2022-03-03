#include "pch.h"

CProtocolS0 gProtocolS0;

void CProtocolS0::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x10://Season 0
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
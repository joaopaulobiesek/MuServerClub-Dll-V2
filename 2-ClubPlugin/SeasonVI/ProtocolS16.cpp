#include "pch.h"

CProtocolS16 gProtocolS16;

void CProtocolS16::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x20://Season 16
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
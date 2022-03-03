#include "pch.h"

CProtocolS10 gProtocolS10;

void CProtocolS10::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x15://Season 10
		switch (lpMsg[5])
		{
		case 0x01:
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}
#include "pch.h"

CProtocolS8 gProtocolS8;

void CProtocolS8::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x14://Season 8
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
#include "pch.h"

CProtocolS6 gProtocolS6;

void CProtocolS6::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x13://Season 6
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
#include "pch.h"

CProtocolS15 gProtocolS15;

void CProtocolS15::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x19://Season 15
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
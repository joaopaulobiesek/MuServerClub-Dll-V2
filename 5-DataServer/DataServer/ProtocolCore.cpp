#include "pch.h"

CProtocolCore gProtocolCore;

CProtocolCore::CProtocolCore() // OK
{
}
CProtocolCore::~CProtocolCore() // OK
{

}

void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size) // OK
{
	gServerManager[index].m_PacketTime = GetTickCount();

	if (AdvancedLog != 0)
	{
		if ((head != 0x00) && (head != 0x07))
		{
			gUtil.LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);
		}
	}

	switch (head)
	{

	}
}
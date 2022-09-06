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

	if (gUtil.AdvancedLog != 0)
	{
		if ((head != 0x00) && (head != 0x07))
		{
			gUtil.LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);
		}
	}

	switch (head)
	{
	case 0x00:
		gProtocolCore.GDServerInfoRecv((SDHP_SERVER_INFO_RECV*)lpMsg, index);
		break;
	case 0x01:
		gProtocolCore.DataServerHWIDRecv((SDHP_HWID_INFO_RECV*)lpMsg, index);
		break;
	}
}

void CProtocolCore::GDServerInfoRecv(SDHP_SERVER_INFO_RECV* lpMsg, int index) // OK
{
	SDHP_SERVER_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	wsprintf(pMsg.DataServerName, "%s", gUtil.DataServerName);

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gServerManager[index].SetServerInfo(lpMsg->ServerName, lpMsg->ServerPort);
}

void CProtocolCore::DataServerHWIDRecv(SDHP_HWID_INFO_RECV* lpMsg, int index) // OK
{
	gScript_HWID.HWID(index, lpMsg->NewHardwareId, lpMsg->HardwareId, lpMsg->account, lpMsg->PcName, lpMsg->PortNumber);
}
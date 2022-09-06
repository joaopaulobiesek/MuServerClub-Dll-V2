#include "pch.h"

CProtocolDataServer gProtocolDataServer;

CProtocolDataServer::CProtocolDataServer() // OK
{
}

CProtocolDataServer::~CProtocolDataServer() // OK
{
}

void ProtocolDataServer(BYTE head, BYTE* lpMsg, int size) // OK
{
	//LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);

	switch (head)
	{
	case 0x00:
		gProtocolDataServer.DGServerInfoRecv((SDHP_DATA_SERVER_INFO_RECV*)lpMsg);
		break;
	}
}

void CProtocolDataServer::GDServerInfoSend() // OK
{
	SDHP_DATA_SERVER_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	pMsg.type = 1;

	pMsg.ServerPort = (WORD)gServerInfo.ServerPort;

	strcpy_s(pMsg.ServerName, gServerInfo.ServerName);

	gConnectionDS.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolDataServer::DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg) // OK
{
	LogAdd(LOG_BLUE, "successfully connected to [%s]", lpMsg->DataServerName);
}

void CProtocolDataServer::DataServerHWID(int Index, char* NewHardwareId, char* HardwareId, char* account, char* PcName, int PortNumber)// OK
{
	SDHP_HWID_INFO_SEND pMsg;

	pMsg.header.set(0x01, sizeof(pMsg));

	LogAdd(LOG_BLACK, "[ClientManager][%d] Account: %s", Index, account);
	LogAdd(LOG_BLACK, "[ClientManager][%d] HwId: %s", Index, HardwareId);
	LogAdd(LOG_BLACK, "[ClientManager][%d] NewHwId: %s", Index, NewHardwareId);
	LogAdd(LOG_BLACK, "[ClientManager][%d] PcName: %s", Index, PcName);
	LogAdd(LOG_BLACK, "[ClientManager][%d] PortNumber: %d", Index, PortNumber);

	pMsg.PortNumber = PortNumber;
	strcpy_s(pMsg.PcName, PcName);
	strcpy_s(pMsg.account, account);
	strcpy_s(pMsg.HardwareId, HardwareId);
	strcpy_s(pMsg.NewHardwareId, NewHardwareId);

	if (PortNumber != -1)
	{
		if (CommaSeparate(gServerInfo.Ports1, PortNumber))
		{
			if (gServerInfo.DS_1_Enabled) gConnectionDS.DataSend((BYTE*)&pMsg, pMsg.header.size);
		}
		else if (CommaSeparate(gServerInfo.Ports2, PortNumber))
		{
			if (gServerInfo.DS_2_Enabled) gConnectionDS2.DataSend((BYTE*)&pMsg, pMsg.header.size);
		}
		else
		{
			LogAdd(LOG_RED, "[ERROR] non-existent port.");
		}
	}
}
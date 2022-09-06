#include "pch.h"

CProtocol2DataServer gProtocol2DataServer;

CProtocol2DataServer::CProtocol2DataServer() // OK
{
}

CProtocol2DataServer::~CProtocol2DataServer() // OK
{
}

void Protocol2DataServer(BYTE head, BYTE* lpMsg, int size) // OK
{
	//LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);

	switch (head)
	{
	case 0x00:
		gProtocol2DataServer.DGServerInfoRecv((SDHP_DATA_SERVER_INFO_RECV*)lpMsg);
		break;
	}
}

void CProtocol2DataServer::GDServerInfoSend() // OK
{
	SDHP_DATA_SERVER_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	pMsg.type = 1;

	pMsg.ServerPort = (WORD)gServerInfo.ServerPort;

	strcpy_s(pMsg.ServerName, gServerInfo.ServerName);

	gConnectionDS2.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocol2DataServer::DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg) // OK
{
	LogAdd(LOG_BLUE, "successfully connected to [%s]", lpMsg->DataServerName);
}
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

	strcpy_s(pMsg.ServerName, "Server DLL TESTE");

	pMsg.ServerCode = (WORD)"0";

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolDataServer::DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg) // OK
{
	gLog.AddLog(LOG_BLUE, "Deu certo");
}
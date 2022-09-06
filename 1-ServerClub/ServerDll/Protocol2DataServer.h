#pragma once

class CProtocol2DataServer
{
public:
	CProtocol2DataServer();
	virtual ~CProtocol2DataServer();
	void GDServerInfoSend();
	void DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg);
public:
};

void Protocol2DataServer(BYTE head, BYTE* lpMsg, int size);
extern CProtocol2DataServer gProtocol2DataServer;
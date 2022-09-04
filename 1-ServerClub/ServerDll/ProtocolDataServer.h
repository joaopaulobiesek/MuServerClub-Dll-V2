#pragma once

//**********************************************//
//********** DataServer -> ServerDLL **********//
//**********************************************//

struct SDHP_DATA_SERVER_INFO_RECV
{
	PBMSG_HEAD header; // C1:00
	BYTE result;
	DWORD ItemCount;
};

//**********************************************//
//********** ServerDLL -> DataServer **********//
//**********************************************//

struct SDHP_DATA_SERVER_INFO_SEND
{
	PBMSG_HEAD header; // C1:00
	BYTE type;
	WORD ServerPort;
	char ServerName[50];
	WORD ServerCode;
};

class CProtocolDataServer
{
public:
	CProtocolDataServer();
	virtual ~CProtocolDataServer();
	void GDServerInfoSend();
	void DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg);
public:
};

void ProtocolDataServer(BYTE head, BYTE* lpMsg, int size);
extern CProtocolDataServer gProtocolDataServer;
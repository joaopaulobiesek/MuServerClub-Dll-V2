#pragma once

struct PBMSG_DS_HEAD
{
    void set(BYTE head, BYTE size) // OK
    {
        this->type = 0xC1;
        this->size = size;
        this->head = head;
    }

    void setE(BYTE head, BYTE size) // OK
    {
        this->type = 0xC3;
        this->size = size;
        this->head = head;
    }

    BYTE type;
    BYTE size;
    BYTE head;
};

//**********************************************//
//********** DataServer -> ServerDLL **********//
//**********************************************//

struct SDHP_DATA_SERVER_INFO_RECV
{
    PBMSG_DS_HEAD header; // C1:00
    char DataServerName[15];
};

//**********************************************//
//********** ServerDLL -> DataServer **********//
//**********************************************//

struct SDHP_DATA_SERVER_INFO_SEND
{
    PBMSG_DS_HEAD header; // C1:00
	BYTE type;
	WORD ServerPort;
	char ServerName[50];
};

struct SDHP_HWID_INFO_SEND
{
    PBMSG_DS_HEAD header; // C1:00
    int PortNumber;
    char PcName[20];
    char account[11];
    char HardwareId[36];
    char NewHardwareId[36];
};

class CProtocolDataServer
{
public:
	CProtocolDataServer();
	virtual ~CProtocolDataServer();
	void GDServerInfoSend();
	void DGServerInfoRecv(SDHP_DATA_SERVER_INFO_RECV* lpMsg);
    void DataServerHWID(int Index, char* NewHardwareId, char* HardwareId, char* account, char* PcName, int PortNumber);
public:
};

void ProtocolDataServer(BYTE head, BYTE* lpMsg, int size);
extern CProtocolDataServer gProtocolDataServer;
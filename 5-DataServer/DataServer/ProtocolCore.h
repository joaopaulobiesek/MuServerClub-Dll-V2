#pragma once

#define SET_NUMBERHB(x) ((BYTE)((DWORD)(x)>>(DWORD)8))
#define SET_NUMBERLB(x) ((BYTE)((DWORD)(x)&0xFF))
#define SET_NUMBERHW(x) ((WORD)((DWORD)(x)>>(DWORD)16))
#define SET_NUMBERLW(x) ((WORD)((DWORD)(x)&0xFFFF))
#define SET_NUMBERHDW(x) ((DWORD)((QWORD)(x)>>(QWORD)32))
#define SET_NUMBERLDW(x) ((DWORD)((QWORD)(x)&0xFFFFFFFF))

#define MAKE_NUMBERW(x,y) ((WORD)(((BYTE)((y)&0xFF))|((BYTE)((x)&0xFF)<<8)))
#define MAKE_NUMBERDW(x,y) ((DWORD)(((WORD)((y)&0xFFFF))|((WORD)((x)&0xFFFF)<<16)))
#define MAKE_NUMBERQW(x,y) ((QWORD)(((DWORD)((y)&0xFFFFFFFF))|((DWORD)((x)&0xFFFFFFFF)<<32)))

//**********************************************//
//************ Packet Base *********************//
//**********************************************//

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

struct PBMSG_HEAD
{
	void set(BYTE head, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
};

struct HEAD_VERSION
{
	void set(BYTE head, BYTE subh, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
	BYTE subh;
};

struct PSBMSG_HEAD
{
	void set(BYTE head, BYTE subh, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
	BYTE subh;
};

struct PWMSG_HEAD
{
	void set(BYTE head, WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->key = rand() % 256;
		this->head = head;
	}

	BYTE type;
	BYTE size[2];
	BYTE key;
	BYTE head;
};

struct PSWMSG_HEAD
{
	void set(BYTE head, BYTE subh, WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size[2];
	BYTE key;
	BYTE head;
	BYTE subh;
};

//**********************************************//
//********** ServerDLL -> DataServer **********//
//**********************************************//

struct SDHP_SERVER_INFO_RECV
{
	PBMSG_DS_HEAD header; // C1:00
	BYTE type;
	WORD ServerPort;
	char ServerName[50];
};

struct SDHP_HWID_INFO_RECV
{
	PBMSG_DS_HEAD header; // C1:00
	int PortNumber;
	char PcName[20];
	char account[11];
	char HardwareId[36];
	char NewHardwareId[36];
};

//**********************************************//
//********** DataServer -> ServerDLL **********//
//**********************************************//

struct SDHP_SERVER_INFO_SEND
{
	PBMSG_DS_HEAD header; // C1:00
	char DataServerName[15];
};

class CProtocolCore
{
public:
	CProtocolCore();
	virtual ~CProtocolCore();
	void GDServerInfoRecv(SDHP_SERVER_INFO_RECV* lpMsg, int index);
	void DataServerHWIDRecv(SDHP_HWID_INFO_RECV* lpMsg, int index);
public:
};

void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
extern CProtocolCore gProtocolCore;
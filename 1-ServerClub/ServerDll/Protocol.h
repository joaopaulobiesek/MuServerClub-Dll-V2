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
//************ Dll -> Server *******************//
//**********************************************//

struct SDHP_CLIENT_INFO_RECV
{
	PBMSG_HEAD header; // C1:00
	DWORD ClientFileCRC;
	char VersionPlugin[8];
	char HardwareId[36];
};

struct SDHP_CONNECTION_STATUS_RECV
{
	PBMSG_HEAD header; // C1:01
};

struct SDHP_CLIENT_DISCONNECT_RECV
{
	PBMSG_HEAD header; // C1:03
	BYTE type;
	char account[11];
	char name[11];
	char CaptionName[64];
	char ProcessName[64];
};

//**********************************************//
//************ Server -> Dll *******************//
//**********************************************//

struct SDHP_CLIENT_INFO_SEND
{
	PBMSG_HEAD header; // C1:00
	BYTE result;
	BYTE Version;
	BYTE HackSwitch;
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
	char IpAddress[32];
	char ClientVersion[8];
	char ClientSerial[17];
	int antiLag;
	int camera3D;
	int customICO;
	int removeSplash;
};

struct SDHP_CONNECTION_STATUS_SEND
{
	PBMSG_HEAD header; // C1:01
};

struct SDHP_WINDOW_LIST_SEND
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CHECKSUM_LIST_SEND
{
	PSWMSG_HEAD header; // C1:02:01
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CLIENT_DISCONNECT_SEND
{
	PBMSG_HEAD header; // C1:03
	BYTE type;
};

//**********************************************//
//***************** Class **********************//
//**********************************************//

class CProtocol
{
public:
	CProtocol();
	virtual ~CProtocol();
	void ConnectionStatusRecv(SDHP_CONNECTION_STATUS_RECV* lpMsg, int index);
	void ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg, int index);
	void ChecksumListSend(int index);
	void WindowListSend(int index);
public:
	DWORD VersionMu;
	DWORD VersionMuHEX;
	DWORD ConnectionStatusTime;
	DWORD ChecksumListMaxCount;
	DWORD WindowListMaxCount;
	DWORD ReconnectStatus;
	DWORD ReconnectSwitch;
	DWORD HackSwitch;
	DWORD ClientInfoOK;
	DWORD ChecksumListOK;
	DWORD WindowListOK;
	DWORD DetectCloseTime;
	DWORD UserAccount;
	DWORD UserStruct;
};

void ProtocolCoreMain(int index, BYTE head, BYTE* lpMsg, int size);
extern CProtocol gProtocol;
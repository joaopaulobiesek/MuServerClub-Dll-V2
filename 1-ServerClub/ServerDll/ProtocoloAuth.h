#pragma once

#define AUTH_ADDRESS_A	"51.79.116.137"
#define AUTH_PORT 1257

void ProtocolCore(BYTE head, BYTE* lpMsg, int size);

struct CONNECT_HEAD
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

struct SERVERDLL_CLIENT_STATUS_RECV
{
	CONNECT_HEAD header; // C1:01
	BYTE Status;
};

struct SERVERDLL_CLIENT_STATUS_SEND
{
	CONNECT_HEAD header; // C1:01
	BYTE Status;
};

struct SERVERDLL_CLIENT_LICENSED_SEND
{
	CONNECT_HEAD header; // C1:00
	int UserId;
	char IpAddress[16];
	char CustomerHardwareId[36];
	char Version[12];
};

struct SERVERDLL_CONNECT_LICENSED_RECV
{
    CONNECT_HEAD header; // C1:00
    int licenseId;
    int versionId;
    BYTE Status;
    char ipAddress[16];
    char hwid[36];
    char expireDate[12];
    char nameId[12];
    /*
        Features
        1: camera3d
        2: antilag
        ---
    */
    int feature_1;
    int feature_2;
    int feature_3;
    int feature_4;
    int feature_5;
    int feature_6;
    int feature_7;
    int feature_8;
    int feature_9;
    int feature_10;
    int feature_11;
    int feature_12;
    int feature_13;
    int feature_14;
    int feature_15;
    int feature_16;
    int feature_17;
    int feature_18;
    int feature_19;
    int feature_20;
};


class CProtocoloAuth
{
public:
    char* SwitchName(int SERVER_TYPE);
    void SwitchFeature();
    void ActiveDataServer();
	void ConnectionLicensedRecv(SERVERDLL_CONNECT_LICENSED_RECV* lpMsg);
	void CHConnectionStatusRecv(SERVERDLL_CLIENT_STATUS_RECV* lpMsg);
	inline void ErrorMessageBox(const char* Error);
	inline void SafeExitProcess();
public:
	char m_Date[12];
	int m_VersionId;
	int m_ProductId;
	int m_PlanProductId;
	SERVERDLL_CONNECT_LICENSED_RECV m_AuthInfo;
};

extern CProtocoloAuth gProtocoloAuth;

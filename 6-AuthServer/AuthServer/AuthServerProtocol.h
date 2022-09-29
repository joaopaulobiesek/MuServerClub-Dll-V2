#pragma once

enum eAuthServerType
{
	AUTH_SERVER_TYPE_NONE = 0,
	AUTH_SERVER_TYPE_S0_SERVERDLL = 1,
	AUTH_SERVER_TYPE_S2_SERVERDLL = 2,
	AUTH_SERVER_TYPE_S4_SERVERDLL = 3,
	AUTH_SERVER_TYPE_S6_SERVERDLL = 4,
	AUTH_SERVER_TYPE_S8_SERVERDLL = 5,
	AUTH_SERVER_TYPE_S10_SERVERDLL = 6,
	AUTH_SERVER_TYPE_S12_SERVERDLL = 7,
	AUTH_SERVER_TYPE_S13_SERVERDLL = 8,
	AUTH_SERVER_TYPE_S14_SERVERDLL = 9,
	AUTH_SERVER_TYPE_S15_SERVERDLL = 10,
	AUTH_SERVER_TYPE_S16_SERVERDLL = 11,
	AUTH_SERVER_TYPE_S12_IGC_SERVERDLL = 12,
};

enum eAuthServerStatus
{
	AUTH_SERVER_STATUS_NONE = 0,
	AUTH_SERVER_STATUS_SUCCESS = 1,
	AUTH_SERVER_STATUS_BLOK = 2,
	AUTH_SERVER_STATUS_PROVISIONAL = 3,
};

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

struct SERVERDLL_CONNECT_LICENSED_SEND
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
		3: custom ico
		4: custom splash
		5: 2fa
		6: emoji
		7: custom monster
		8: guild ico
		9: pet safe zone
		10: custom npc
		11: custom cloak
		12: custom options
		13: custom events time
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

struct SERVERDLL_CLIENT_LICENSED_RECV
{
	CONNECT_HEAD header; // C1:00
	int UserId;
	char IpAddress[16];
	char CustomerHardwareId[36];
	char Version[12];
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

void AuthServerProtocolCore(int index,BYTE head,BYTE* lpMsg,int size);
void ServerConnectionLicensedRecv(SERVERDLL_CLIENT_LICENSED_RECV* lpMsg,int index);
void CHConnectionStatusRecv(SERVERDLL_CLIENT_STATUS_RECV* lpMsg, int index);

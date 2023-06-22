// ServerInfo.h: interface for the CServerInfo class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CServerInfo
{
public:
	CServerInfo();
	virtual ~CServerInfo();
	void ReadInit();
	void ReadConfig();
	void ReadChecksumList();
	void ReadCustomList();
	void ReadWindowList();
	void ReadBlackList();
	void ReadStartupInfo(const char* section, const char* path);
	void ReadWindowNameInfo(const char* section, const char* path);
	void ReadStartupKeyboard(const char* section, const char* path);
	void ReadStartupCustomS6(const char* section, const char* path);
	void ReadStartupDS(const char* section, const char* path);
public:
	DWORD ClientFileCRC;
	DWORD PortNumberAddress;
	int LicenseId;
	int ServerPort;
	int DS_1_Enabled;
	int DS_2_Enabled;
	int DS_1_Port;
	int DS_2_Port;
	int CheckCRC;
	int HackSwitch;
	char ServerName[50];
	char HardwareId[36];
	char IpAddress[32];
	char Ip_1_Address[32];
	char Ip_2_Address[32];
	char IpAddressExt[32];
	char ClientVersion[8];
	char ClientSerial[17];
	char DataServerPort1ODBC[32];
	char DataServerPort2ODBC[32];
	char Ports1[50];
	char Ports2[50];
	int CheckBlackList;
	int CheckWindowList;
	int CheckSumList;
	int CheckCustomList;
	int CheckSQL;
	//Novas Funções
	long m_DataServerPort;
	char m_DataServerAddress[16];
	//WindowName
	int ActiveWindowName;
	int ActiveWindowClock;
	int ActiveWindowWebSite;
	char WindowWebSite[50];
	//AtivaLicençaManual
	int A_VersionId;
	int A_Camera3D;
	int A_AntiLag;
	int A_CustomICO;
	int A_RemoveSplash;
	int A_TwoFactorAuth;
	int A_Emoji;
	int A_CustomMoster;
	int A_GuildIco;
	int A_PetSafeZone;
	int A_CustomNPC;
	int A_CustomCloak;
	int A_CustomOption;
	int A_CustomEventTime;
	int A_DataServer;

	//KeyBoard Function
	int Func1;
	int Func2;
	int Func3;
	int Func4;
	int Func5;
	int Func6;
	int Func7;
	int Func8;
	int Func9;
	int Func10;
	int Func11;
	int Func12;
	int Func13;
	int Func14;
	int Func15;
	int Func16;
	int DownS6;
	int SmokeEffect;
	int CustomFog;
	int KeyEventTime;

	int PetSafeZone_Horse;
	int PetSafeZone_Dinorant;
	int PetSafeZone_Fenrir;

	int ActiveNameServer;
	char Name1Server[32];
	char Name2Server[32];
	char Name3Server[32];
	char Name4Server[32];
};

extern CServerInfo gServerInfo;
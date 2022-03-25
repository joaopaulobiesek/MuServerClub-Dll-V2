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
	void ReadStartupKeyboard(const char* section, const char* path);
	void ReadStartupDS(const char* path);
public:
	DWORD ClientFileCRC;
	int LicenseId;
	int ServerPort;
	int CheckCRC;
	int HackSwitch;
	char HardwareId[36];
	char IpAddress[32];
	char IpAddressExt[32];
	char ClientVersion[8];
	char ClientSerial[17];
	int CheckBlackList;
	int CheckWindowList;
	int CheckSumList;
	int CheckCustomList;
	int CheckSQL;

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
};

extern CServerInfo gServerInfo;
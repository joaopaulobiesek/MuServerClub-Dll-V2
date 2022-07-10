#include "pch.h"

CServerInfo gServerInfo;

CServerInfo::CServerInfo() // OK
{

}

CServerInfo::~CServerInfo() // OK
{

}

void CServerInfo::ReadInit() // OK
{
	if (this->CheckCRC == 1) this->ReadConfig();

	if (this->CheckSumList == 1) this->ReadChecksumList();

	if (this->CheckWindowList == 1) this->ReadWindowList();

	if (this->CheckBlackList == 1) this->ReadBlackList();

	if (this->CheckCustomList == 1) this->ReadCustomList();
}

void CServerInfo::ReadConfig() // OK
{
	CCRC32 CRC32;

	std::ifstream obj;
	obj.open(".\\Data\\MuServer.Club");
	if (obj.is_open())
	{
		obj.close();
		if (CRC32.FileCRC(".\\Data\\MuServer.Club", &this->ClientFileCRC, 1024) == 0)
		{
			this->ClientFileCRC = 0;
		}
		LogAdd(LOG_BLUE, "[ServerInfo] CRC32 loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] CRC32 file does not exist");
	}
}

void CServerInfo::ReadChecksumList() // OK
{
	std::ifstream obj;
	obj.open(".\\Data\\Checksum.List.db");
	if (obj.is_open())
	{
		obj.close();
		gReadFiles.ChecksumList(".\\Data\\Checksum.List.db");
		LogAdd(LOG_BLUE, "[ServerInfo] ChecksumList loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] ChecksumList file does not exist");
	}
}

void CServerInfo::ReadCustomList() // OK
{
	std::ifstream obj;
	obj.open(".\\Custom\\CustomEventName.txt");
	if (obj.is_open())
	{
		obj.close();
		gReadFiles.CustomEventList(".\\Custom\\CustomEventName.txt");
		LogAdd(LOG_BLUE, "[ServerInfo] Custom Event List loaded successfully");
	}
	obj.open(".\\Custom\\CustomNPCName.txt");
	if (obj.is_open())
	{
		obj.close();
		gReadFiles.CustomNPCList(".\\Custom\\CustomNPCName.txt");
		LogAdd(LOG_BLUE, "[ServerInfo] Custom NPC Name loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] Custom NPC Name file does not exist");
	}

	obj.open(".\\Custom\\CustomMonster.txt");
	if (obj.is_open())
	{
		obj.close();
		gReadFiles.CustomMonsterList(".\\Custom\\CustomMonster.txt");
		LogAdd(LOG_BLUE, "[ServerInfo] Custom Monster loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] Custom Monster file does not exist");
	}
}

void CServerInfo::ReadWindowList() // OK
{
	std::ifstream obj;
	obj.open(".\\Data\\Window.List.db");
	if (obj.is_open())
	{
		obj.close();
		gReadFiles.WindowList(".\\Data\\Window.List.db");
		LogAdd(LOG_BLUE, "[ServerInfo] WindowList loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] WindowList file does not exist");
	}

}

void CServerInfo::ReadBlackList() //OK
{
	std::ifstream obj;
	obj.open(".\\BlackList.txt");
	if (obj.is_open())
	{
		obj.close();
		gBlackList.SetList(".\\BlackList.txt");
		LogAdd(LOG_BLUE, "[ServerInfo] BlackList loaded successfully");
	}
	else
	{
		obj.close();
		LogAdd(LOG_RED, "[ServerInfo] BlackList file does not exist");
	}
}

void CServerInfo::ReadStartupInfo(const char* section, const char* path) // OK
{
	this->LicenseId = GetPrivateProfileInt(section, "LicenseId", 0, path);

	this->ServerPort = GetPrivateProfileInt(section, "ServerDllPort", 0, path);

	this->CheckCRC = GetPrivateProfileInt(section, "CheckCRC", 1, path);

	this->CheckBlackList = GetPrivateProfileInt(section, "CheckBlackList", 1, path);

	this->CheckWindowList = GetPrivateProfileInt(section, "CheckWindowList", 1, path);

	this->CheckSumList = GetPrivateProfileInt(section, "CheckSumList", 1, path);

	this->CheckCustomList = GetPrivateProfileInt(section, "CheckCustomList", 1, path);

	this->HackSwitch = GetPrivateProfileInt(section, "HackSwitch", 1, path);

	this->CheckSQL = GetPrivateProfileInt("DataServerInfo", "CheckSQL", 1, path);

	GetPrivateProfileString(section, "IpAddress", "0", this->IpAddressExt, sizeof(this->IpAddressExt), path);

	GetPrivateProfileString(section, "ClientVersion", "", this->ClientVersion, sizeof(this->ClientVersion), path);

	GetPrivateProfileString(section, "ClientSerial", "", this->ClientSerial, sizeof(this->ClientSerial), path);

	GetHardwareId(this->HardwareId);

	LogAdd(LOG_BLUE, "Port: %d", ServerPort);
}

void CServerInfo::ReadStartupDS(const char* path) // OK
{
	char DataServerODBC[32] = { 0 };

	char DataServerUSER[32] = { 0 };

	char DataServerPASS[32] = { 0 };

	GetPrivateProfileString("DataServerInfo", "DataServerODBC", "", DataServerODBC, sizeof(DataServerODBC), path);

	GetPrivateProfileString("DataServerInfo", "DataServerUSER", "", DataServerUSER, sizeof(DataServerUSER), path);

	GetPrivateProfileString("DataServerInfo", "DataServerPASS", "", DataServerPASS, sizeof(DataServerPASS), path);

	if (gQueryManager.Connect(DataServerODBC, DataServerUSER, DataServerPASS) == 0)
	{
		LogAdd(LOG_RED, "Could not connect to database");
	}
	else
	{
		LogAdd(LOG_BLUE, "Connected to database");
	}
}

void CServerInfo::ReadStartupKeyboard(const char* section, const char* path) // OK
{
	this->Func1 = GetPrivateProfileInt(section, "Func1", 0, path);

	this->Func2 = GetPrivateProfileInt(section, "Func2", 0, path);

	this->Func3 = GetPrivateProfileInt(section, "Func3", 0, path);

	this->Func4 = GetPrivateProfileInt(section, "Func4", 0, path);

	this->Func5 = GetPrivateProfileInt(section, "Func5", 0, path);

	this->Func6 = GetPrivateProfileInt(section, "Func6", 0, path);

	this->Func7 = GetPrivateProfileInt(section, "Func7", 0, path);

	this->Func8 = GetPrivateProfileInt(section, "Func8", 0, path);

	this->Func9 = GetPrivateProfileInt(section, "Func9", 0, path);

	this->Func10 = GetPrivateProfileInt(section, "Func10", 0, path);

	this->Func11 = GetPrivateProfileInt(section, "Func11", 0, path);

	this->Func12 = GetPrivateProfileInt(section, "Func12", 0, path);

	this->Func13 = GetPrivateProfileInt(section, "Func13", 0, path);

	this->Func14 = GetPrivateProfileInt(section, "Func14", 0, path);

	this->Func15 = GetPrivateProfileInt(section, "Func15", 0, path);

	this->Func16 = GetPrivateProfileInt(section, "Func16", 0, path);

	LogAdd(LOG_BLUE, "Keyboard loaded successfully");
}

void CServerInfo::ReadStartupCustomS6(const char* section, const char* path) // OK
{
	this->DownS6 = GetPrivateProfileInt(section, "DownS6", 0, path);

	this->PetSafeZone_Horse = GetPrivateProfileInt(section, "PetSafeZoneHorse", 0, path);

	this->PetSafeZone_Dinorant = GetPrivateProfileInt(section, "PetSafeZoneDinorant", 0, path);

	this->PetSafeZone_Fenrir = GetPrivateProfileInt(section, "PetSafeZoneFenrir", 0, path);

	this->ActiveNameServer = GetPrivateProfileInt(section, "ActiveNameServer", 0, path);

	GetPrivateProfileString(section, "Name1Server", "", this->Name1Server, sizeof(this->Name1Server), path);

	GetPrivateProfileString(section, "Name2Server", "", this->Name2Server, sizeof(this->Name2Server), path);

	GetPrivateProfileString(section, "Name3Server", "", this->Name3Server, sizeof(this->Name3Server), path);

	GetPrivateProfileString(section, "Name4Server", "", this->Name4Server, sizeof(this->Name4Server), path);

	LogAdd(LOG_BLUE, "CustomS6 loaded successfully");
}
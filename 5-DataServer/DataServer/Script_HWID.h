#pragma once

class CScript_HWID
{
public:
	CScript_HWID();
	virtual ~CScript_HWID();
	void HWID(int Index, char* NewHardwareId, char* HardwareId, char* account, char* PcName, int PortNumber);
public:
	char m_Account[11];
	char m_HardwareId[36];
	char m_NewHardwareId[50];
	char m_PcName[50];
	int m_PortNumber;
};
extern CScript_HWID gScript_HWID;
#include "pch.h"

CScript_HWID gScript_HWID;

CScript_HWID::CScript_HWID() // OK
{
}

CScript_HWID::~CScript_HWID() // OK
{
}

void CScript_HWID::HWID(int Index, char* NewHardwareId, char* HardwareId, char* account, char* PcName, int PortNumber)// OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	std::string NewHWID = NewHardwareId;
	NewHWID.erase(std::remove_if(NewHWID.begin(), NewHWID.end(), [](char c) { return !isalnum(c); }), NewHWID.end());
	this->m_PortNumber = PortNumber;
	strcpy(this->m_NewHardwareId, NewHWID.c_str());
	memcpy(this->m_HardwareId, HardwareId, sizeof(this->m_HardwareId));
	memcpy(this->m_Account, account, sizeof(this->m_Account));
	memcpy(this->m_PcName, PcName, sizeof(this->m_PcName));

	gQueryManager.Close();
	gQueryManager.BindParameterAsString(1, this->m_HardwareId, sizeof(this->m_HardwareId)); // Anti-Injection
	gQueryManager.BindParameterAsString(2, this->m_NewHardwareId, sizeof(this->m_NewHardwareId)); // Anti-Injection
	gQueryManager.BindParameterAsString(3, this->m_PcName, sizeof(this->m_PcName)); // Anti-Injection
	gQueryManager.BindParameterAsString(4, this->m_Account, sizeof(this->m_Account)); // Anti-Injection
	if (gQueryManager.ExecQuery("UPDATE MEMB_INFO SET HWID=? , NewHWID=? , PcName=? , Port=%d WHERE memb___id=?", this->m_PortNumber) != 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		// Anti-Injection
		gQueryManager.Close();
		gUtil.LogAdd(LOG_BLUE, "[SQL] [HwId]: %s [Acc]: %s ", this->m_NewHardwareId, this->m_Account);
	}
	else
	{
		// Anti-Injection
		gQueryManager.Close();
		gUtil.LogAdd(LOG_RED, "[ERROR] updating HWID.");
	}

	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
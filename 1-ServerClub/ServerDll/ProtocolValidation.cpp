#include "pch.h"

CProtocolValidation gProtocolValidation;

CProtocolValidation::CProtocolValidation() // OK
{
}

CProtocolValidation::~CProtocolValidation() // OK
{
}

int CProtocolValidation::ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg, SDHP_CLIENT_INFO_SEND* pMsg, int index)
{
	if (gServerInfo.ClientFileCRC != lpMsg->ClientFileCRC && gServerInfo.CheckCRC == 1)
	{
		LogAdd(LOG_RED, "[ERROR] CRC Dll %s", lpMsg->HardwareId);
		//LogAdd(LOG_RED, "%d - %d", gServerInfo.ClientFileCRC, lpMsg->ClientFileCRC);
		pMsg->result = 1;
		return 1;
	}

	if (GetCurrentVersion() != ConvertVersionPlugin(lpMsg->VersionPlugin))
	{
		LogAdd(LOG_RED, "%d - %d", GetCurrentVersion(), ConvertVersionPlugin(lpMsg->VersionPlugin));
		pMsg->result = 2;
		return 2;
	}

	if (gBlackList.CheckHardwareId(lpMsg->HardwareId) == 0)
	{
		pMsg->result = 4;
		return 4;
	}

	if (gBlackList.CheckIpAddress(gClientManager[index].m_IpAddr) == 0)
	{
		pMsg->result = 4;
		return 4;
	}

	return 0;
}
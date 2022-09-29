#include "stdafx.h"
#include "AuthServerProtocol.h"
#include "ClientManager.h"
#include "QueryManager.h"
#include "SocketManager.h"
#include "ServerDisplayer.h"
#include "Util.h"

void AuthServerProtocolCore(int index, BYTE head, BYTE* lpMsg, int size) // OK
{
	gClientManager[index].m_PacketTime = GetTickCount();

	switch (head)
	{
	case 0x00:
		ServerConnectionLicensedRecv((SERVERDLL_CLIENT_LICENSED_RECV*)lpMsg, index);
		break;
	case 0x01:
		CHConnectionStatusRecv((SERVERDLL_CLIENT_STATUS_RECV*)lpMsg, index);
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CHConnectionStatusRecv(SERVERDLL_CLIENT_STATUS_RECV* lpMsg, int index) // OK
{
	SERVERDLL_CLIENT_STATUS_SEND pMsg;

	pMsg.header.set(0x01, sizeof(pMsg));

	if (gQueryManager.ExecQuery("select * from ServerclubPlugin where id = %d and Date >= GETDATE()", gClientManager[index].m_licensedId) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.Status = AUTH_SERVER_STATUS_NONE;

		LogAdd(LOG_RED, "ERROR: INVALID LICENSE: %d - %s", gClientManager[index].m_licensedId, gClientManager[index].m_IpAddr);
	}
	else
	{
		/*if ((BYTE)gQueryManager.GetAsInteger("Status") == 0)
		{
			LogAdd(LOG_RED, "Usuario desconectado Status 0: UserID: %d - IP: %s", gClientManager[index].m_licensedId, gClientManager[index].m_IpAddr);
		}*/

		pMsg.Status = AUTH_SERVER_STATUS_SUCCESS;

		gQueryManager.Close();

		//LogAdd(LOG_BLACK, "CHECK CONNECTION: ACCOUNT %d - IP: %s", gClientManager[index].m_licensedId, gClientManager[index].m_IpAddr);
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gClientManager[index].m_OnlineTime = GetTickCount();
}

void ServerConnectionLicensedRecv(SERVERDLL_CLIENT_LICENSED_RECV* lpMsg, int index) // OK
{
	SERVERDLL_CONNECT_LICENSED_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	pMsg.Status = AUTH_SERVER_STATUS_NONE;

	if (gQueryManager.ExecQuery("SELECT *, convert(varchar(12), Date, 103) as DataOut FROM ServerClubPlugin scp join Version v on scp.version = v.Id WHERE scp.id = %d and Date >= GETDATE()", lpMsg->UserId) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.Status = AUTH_SERVER_STATUS_NONE;		

		LogAdd(LOG_RED, "ERROR: INVALID LICENSE: %d - %s", gClientManager[index].m_licensedId, gClientManager[index].m_IpAddr);
	}
	else
	{
		
		char IpAddress[16] = { 0 };

		char HardwareId[36] = { 0 };

		char Date[12] = { 0 };

		pMsg.versionId = gQueryManager.GetAsInteger("version");
		pMsg.feature_1 = gQueryManager.GetAsInteger("camera_3d");
		pMsg.feature_2 = gQueryManager.GetAsInteger("antilag");
		pMsg.feature_3 = gQueryManager.GetAsInteger("custom_ico");
		pMsg.feature_4 = gQueryManager.GetAsInteger("custom_splash");
		pMsg.feature_5 = gQueryManager.GetAsInteger("2fa");
		pMsg.feature_6 = gQueryManager.GetAsInteger("emoji");
		pMsg.feature_7 = gQueryManager.GetAsInteger("custom_monster");
		pMsg.feature_8 = gQueryManager.GetAsInteger("guild_icon");
		pMsg.feature_9 = gQueryManager.GetAsInteger("pet_safe_zone");
		pMsg.feature_10 = gQueryManager.GetAsInteger("custom_npc");
		pMsg.feature_11 = gQueryManager.GetAsInteger("custom_cloak");
		pMsg.feature_12 = gQueryManager.GetAsInteger("custom_options");
		pMsg.feature_13 = gQueryManager.GetAsInteger("custom_event_time");
		pMsg.feature_14 = gQueryManager.GetAsInteger("data_server");
		pMsg.feature_15 = 0;
		pMsg.feature_16 = 0;
		pMsg.feature_17 = 0;
		pMsg.feature_18 = 0;
		pMsg.feature_19 = 0;
		pMsg.feature_20 = 0;

		gQueryManager.GetAsString("ip", IpAddress, sizeof(IpAddress));

		gQueryManager.GetAsString("hwid", HardwareId, sizeof(HardwareId));

		gQueryManager.GetAsString("DataOut", Date, sizeof(Date));

		pMsg.Status = AUTH_SERVER_STATUS_SUCCESS;

		pMsg.licenseId = lpMsg->UserId;

		gClientManager[index].m_licensedId = lpMsg->UserId;

		memcpy(pMsg.ipAddress, IpAddress, sizeof(pMsg.ipAddress));

		memcpy(pMsg.hwid, HardwareId, sizeof(pMsg.hwid));

		memcpy(pMsg.expireDate, Date, sizeof(pMsg.expireDate));

		LogAdd(LOG_BLUE, "SEND INFO: ACCOUNT %d - IP: %s - VERSION %d", gClientManager[index].m_licensedId, pMsg.ipAddress, pMsg.versionId);

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
}

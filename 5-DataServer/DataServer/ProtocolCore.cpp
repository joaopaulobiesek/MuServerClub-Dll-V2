#include "pch.h"

CProtocolCore gProtocolCore;

CProtocolCore::CProtocolCore() // OK
{
}
CProtocolCore::~CProtocolCore() // OK
{

}

void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size) // OK
{
	gServerManager[index].m_PacketTime = GetTickCount();
	gUtil.LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);


	if (AdvancedLog != 0)
	{
		if ((head != 0x00) && (head != 0x07))
		{
			gUtil.LogAdd(LOG_BLACK, "DSPROTOCOL: Head: %x, 1: %x, 2: %x, 3: %x, 4: %x, 5: %x", head, lpMsg[1], lpMsg[2], lpMsg[3], lpMsg[4], lpMsg[5]);
		}
	}

	switch (head)
	{
	case 0x00:
		gProtocolCore.GDServerInfoRecv((SDHP_SERVER_INFO_RECV*)lpMsg, index);
		break;
	}
}


void CProtocolCore::GDServerInfoRecv(SDHP_SERVER_INFO_RECV* lpMsg, int index) // OK
{
	gLog.AddLog(LOG_BLUE, "Deu certo");
	/*SDHP_SERVER_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	pMsg.result = 1;

	pMsg.ItemCount = 0;

	if (gQueryManager.ExecQuery("SELECT ItemCount FROM GameServerInfo WHERE Number=0") == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();
		gQueryManager.ExecQuery("INSERT INTO GameServerInfo (Number,ItemCount,ZenCount,AceItemCount) VALUES (0,0,0,0)");
		gQueryManager.Close();
	}
	else
	{
		pMsg.ItemCount = gQueryManager.GetAsInteger("ItemCount");

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gServerManager[index].SetServerInfo(lpMsg->ServerName, lpMsg->ServerPort, lpMsg->ServerCode);
	*/
	}
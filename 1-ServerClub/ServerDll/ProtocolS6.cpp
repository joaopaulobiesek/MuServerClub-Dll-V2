#include "pch.h"

CProtocolS6 gProtocolS6;

void CProtocolS6::ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x13://Season 6
		switch (lpMsg[4])
		{
		case 0x00:
			this->RequestOffSetS6((SDHP_REQUEST_OFFSET_S6_RECV*)lpMsg, index);
			break;
		case 0x01:
			this->RequestKeyBoardS6((SDHP_REQUEST_KEYBOARD_S6_RECV*)lpMsg, index);
			break;
		case 0x02:
			this->RequestEventListS6((SDHP_REQUEST_EVENT_LIST_S6_RECV*)lpMsg, index);
			break;
		}
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocolS6::RequestOffSetS6(SDHP_REQUEST_OFFSET_S6_RECV* lpMsg, int index)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		SDHP_REQUEST_OFFSET_S6_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	pMsg.MAIN_SCREEN_STATE = gOffsetS6.MAIN_SCREEN_STATE;
	pMsg.MAIN_VIEWPORT_STRUCT = gOffsetS6.MAIN_VIEWPORT_STRUCT;
	pMsg.MAIN_MAP_CODE = gOffsetS6.MAIN_MAP_CODE;
	pMsg.pDrawMessage = gOffsetS6.pDrawMessage;
	if (gFeatures.antiLag == 1) {
		pMsg.WingActive = gOffsetS6.WingActive;
		pMsg.Skill1Active = gOffsetS6.Skill1Active;
		pMsg.Skill2Active = gOffsetS6.Skill2Active;
		pMsg.Skill3Active = gOffsetS6.Skill3Active;
		pMsg.Skill4ActiveHook = gOffsetS6.Skill4ActiveHook;
		pMsg.ZenActive = gOffsetS6.ZenActive;
		pMsg.ItemActive = gOffsetS6.ItemActive;
		pMsg.PetActive = gOffsetS6.PetActive;
		pMsg.Terrain1Active = gOffsetS6.Terrain1Active;
		pMsg.RemoveSetActive = gOffsetS6.RemoveSetActive;
	}

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocolS6::RequestKeyBoardS6(SDHP_REQUEST_KEYBOARD_S6_RECV* lpMsg, int index)
{
	SDHP_REQUEST_KEYBOARD_S6_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	pMsg.Func1 = gServerInfo.Func1;
	pMsg.Func2 = gServerInfo.Func2;
	pMsg.Func3 = gServerInfo.Func3;
	pMsg.Func4 = gServerInfo.Func4;
	pMsg.Func5 = gServerInfo.Func5;
	pMsg.Func6 = gServerInfo.Func6;
	pMsg.Func7 = gServerInfo.Func7;
	pMsg.Func8 = gServerInfo.Func8;
	pMsg.Func9 = gServerInfo.Func9;
	pMsg.Func10 = gServerInfo.Func10;
	pMsg.Func11 = gServerInfo.Func11;
	pMsg.Func12 = gServerInfo.Func12;
	pMsg.Func13 = gServerInfo.Func13;
	pMsg.PetSafeZone_Horse = gServerInfo.PetSafeZone_Horse;
	pMsg.PetSafeZone_Dinorant = gServerInfo.PetSafeZone_Dinorant;
	pMsg.PetSafeZone_Fenrir = gServerInfo.PetSafeZone_Fenrir;
	pMsg.ActiveNameServer = gServerInfo.ActiveNameServer;
	memcpy(pMsg.Name1Server, gServerInfo.Name1Server, sizeof(pMsg.Name1Server));
	memcpy(pMsg.Name2Server, gServerInfo.Name2Server, sizeof(pMsg.Name2Server));
	memcpy(pMsg.Name3Server, gServerInfo.Name3Server, sizeof(pMsg.Name3Server));
	memcpy(pMsg.Name4Server, gServerInfo.Name4Server, sizeof(pMsg.Name4Server));
	pMsg.KeyEventTime = gServerInfo.KeyEventTime;
	pMsg.SmokeEffect = gServerInfo.SmokeEffect;
	pMsg.CustomFog = gServerInfo.CustomFog;
	pMsg.DownS6 = gServerInfo.DownS6;

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS6::RequestEventListS6(SDHP_REQUEST_EVENT_LIST_S6_RECV* lpMsg, int index)
{
	gGetSync.Scan();

	SDHP_REQUEST_EVENT_LIST_S6_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x02, sizeof(pMsg));

	for (int i = 0; i < MAX_EVENT_LIST; i++)
	{
		if (gGetSync.gCustomEventListInfo[i].Id != -1)
		{
			pMsg.Id = i;
			pMsg.TimeEvent = gGetSync.gCustomEventListInfo[i].TimeEvent;
			memcpy(pMsg.NameEvent, gGetSync.gCustomEventListInfo[i].NameEvent, sizeof(pMsg.NameEvent));

			gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);
		}
	}

}
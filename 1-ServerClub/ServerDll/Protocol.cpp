#include "pch.h"

CProtocol gProtocol;

CProtocol::CProtocol() // OK
{
	this->VersionMu = 0;
	this->VersionMuHEX = 0x00;
	this->ConnectionStatusTime = 0;
	this->ChecksumListMaxCount = 0;
	this->WindowListMaxCount = 0;
	this->ReconnectStatus = 0;
	this->ReconnectSwitch = 0;
	this->HackSwitch = 0;
	this->ClientInfoOK = 0;
	this->ChecksumListOK = 0;
	this->WindowListOK = 0;
	this->DetectCloseTime = 0;
	this->UserAccount = 0;
	this->UserStruct = 0;
}

CProtocol::~CProtocol() // OK
{

}

void ProtocolCoreMain(int index, BYTE head, BYTE* lpMsg, int size)
{
	gClientManager[index].m_PacketTime = GetTickCount();

	//LogAdd(LOG_RED, "test 1 %d - %d -", head, lpMsg[4]);
	switch (head)
	{
	case 0x00:
		gProtocol.ClientInfoRecv((SDHP_CLIENT_INFO_RECV*)lpMsg, index);
		break;
	case 0x01:
		gProtocol.ConnectionStatusRecv((SDHP_CONNECTION_STATUS_RECV*)lpMsg, index);
		break;
	case 0x03:
		//CHClientDisconnectRecv((SDHP_CLIENT_DISCONNECT_RECV*)lpMsg, index);
		break;
	case 0x04:
		gProtocol.ClientConnectRecv((SDHP_CLIENT_RECV_CONNECT*)lpMsg, index);
		break;
	case 0x05:
		//CHClientHackRecv((SDHP_CLIENT_HACK_RECV*)lpMsg, index);
		break;
		/*case 0xF3:
			switch (lpMsg[3])
			{
			case 0xE8:
				LogAdd(LOG_RED, "[%d] TESTE", index);
				gCustomEventTime.GCReqEventTime(index, (PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
				break;
			}
			break;*/
	case 0x06:
		gProtocol.ClientRecvHack((SDHP_CLIENT_HACK_RECV*)lpMsg, index);
		break;

	case 0x10://Season 0
		gProtocolS0.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x11://Season 2
		gProtocolS2.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x12://Season 4
		gProtocolS4.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x13://Season 6
		gProtocolS6.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x14://Season 8
		gProtocolS8.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x15://Season 10
		gProtocolS10.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x16://Season 12
		gProtocolS12.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x17://Season 13
		gProtocolS13.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x18://Season 14
		gProtocolS14.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x19://Season 15
		gProtocolS15.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x20://Season 16
		gProtocolS16.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x21://Season 17
		gProtocolS17.ProtocolCore(index, head, lpMsg, size);
		break;
	case 0x22://Season 17Ep2
		gProtocolS1702.ProtocolCore(index, head, lpMsg, size);
		break;
	default:
		gSocketManager.Disconnect(index);
		break;
	}
}

void CProtocol::ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg, int index)
{
	SDHP_CLIENT_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	gOffset.Init(gProtocoloAuth.m_VersionId);

	pMsg.Version = gProtocoloAuth.m_VersionId;

	pMsg.HackSwitch = gServerInfo.HackSwitch;

	pMsg.result = 0;

	gProtocolValidation.ClientInfoRecv(lpMsg, &pMsg, index);

	pMsg.IpAddressAddress = gOffset.IpAddressAddress;
	pMsg.ClientVersionAddress = gOffset.ClientVersionAddress;
	pMsg.ClientSerialAddress = gOffset.ClientSerialAddress;
	pMsg.AccountAddress = gOffset.AccountAddress;
	pMsg.CharacterAddress = gOffset.CharacterAddress;
	pMsg.HwndAddress = gOffset.HwndAddress;
	pMsg.FileProtectAddress1 = gOffset.FileProtectAddress1;
	pMsg.FileProtectAddress2 = gOffset.FileProtectAddress2;

	memcpy(pMsg.IpAddress, gServerInfo.IpAddress, sizeof(pMsg.IpAddress));

	memcpy(pMsg.ClientVersion, gServerInfo.ClientVersion, sizeof(pMsg.ClientVersion));

	memcpy(pMsg.ClientSerial, gServerInfo.ClientSerial, sizeof(pMsg.ClientSerial));

	pMsg.camera3D = gFeatures.camera3D;
	pMsg.antiLag = gFeatures.antiLag;
	pMsg.customICO = gFeatures.customICO;
	pMsg.removeSplash = gFeatures.removeSplash;
	pMsg.twoFactorAuth = gFeatures.twoFactorAuth;
	pMsg.emoji = gFeatures.emoji;
	pMsg.customMoster = gFeatures.customMoster;
	pMsg.guildIco = gFeatures.guildIco;
	pMsg.petSafeZone = gFeatures.petSafeZone;
	pMsg.customNPC = gFeatures.customNPC;
	pMsg.customCloak = gFeatures.customCloak;
	pMsg.customOption = gFeatures.customOption;
	pMsg.customEventTime = gFeatures.customEventTime;

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gProtocol.ChecksumListSend(index);

	gProtocol.WindowListSend(index);

	gProtocol.CustomMonsterListSend(index);

	gProtocol.CustomNPCListSend(index);

	gProtocol.CustomCloakListSend(index);

	gProtocol.CustomSmokeEffectListSend(index);

	gProtocol.CustomFogListSend(index);
}

void CProtocol::ClientRecvHack(SDHP_CLIENT_HACK_RECV* lpMsg, int index)
{
	if (lpMsg->Status == 1)
	{
		LogAddHackSpeed(LOG_RED, "[%d] SPEED HACK DETECTED: MAP:[%d] - X:[%d] - Y:[%d]", index, lpMsg->Map, lpMsg->X, lpMsg->Y);
	}
	if (lpMsg->Status == 2)
	{
		LogAddHack(LOG_RED, "[%d] HACK DETECTED: [%s] - %s", index, lpMsg->Program, lpMsg->Name);
	}
}

void CProtocol::ConnectionStatusRecv(SDHP_CONNECTION_STATUS_RECV* lpMsg, int index) // OK
{
	SDHP_CONNECTION_STATUS_SEND pMsg;

	pMsg.header.set(0x01, sizeof(pMsg));

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gClientManager[index].m_OnlineTime = GetTickCount();
}

void CProtocol::ChecksumListSend(int index) // OK
{
	std::vector<CSUM_LIST_INFO>::iterator MakeList = gReadFiles.gChecksumListInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CHECKSUM_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x01, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gChecksumListInfo.size();

		pMsg.count = 0;

		CSUM_LIST_INFO info;

		for (; MakeList != gReadFiles.gChecksumListInfo.end(); MakeList++)
		{
			memcpy(info.path, MakeList->path, sizeof(info.path));

			info.checksum = MakeList->checksum;

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gChecksumListInfo.end());
}

void CProtocol::WindowListSend(int index) // OK
{
	std::vector<WNDW_LIST_INFO>::iterator MakeList = gReadFiles.gWindowListInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_WINDOW_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x03, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gWindowListInfo.size();

		pMsg.count = 0;

		WNDW_LIST_INFO info;

		for (; MakeList != gReadFiles.gWindowListInfo.end(); MakeList++)
		{
			info.type = MakeList->type;

			memcpy(info.text, MakeList->text, sizeof(info.text));

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gWindowListInfo.end());
}

void CProtocol::CustomMonsterListSend(int index) // OK
{
	std::vector<CUSTOMMONSTER_DATA>::iterator MakeList = gReadFiles.gCustomMonsterListInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CUSTOM_MONSTER_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x05, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gCustomMonsterListInfo.size();

		pMsg.count = 0;

		CUSTOMMONSTER_DATA info;

		for (; MakeList != gReadFiles.gCustomMonsterListInfo.end(); MakeList++)
		{
			info.Index = MakeList->Index;

			info.ID = MakeList->ID;

			info.Type = MakeList->Type;

			strcpy_s(info.Name, MakeList->Name);

			strcpy_s(info.Dir, MakeList->Dir);

			strcpy_s(info.Folder, MakeList->Folder);

			strcpy_s(info.BMDFile, MakeList->BMDFile);

			info.Size = MakeList->Size;

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gCustomMonsterListInfo.end());
}

void CProtocol::CustomNPCListSend(int index) // OK
{
	std::vector<NPCNAME_DATA>::iterator MakeList = gReadFiles.gCustomNPCListInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CUSTOM_NPC_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x07, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gCustomNPCListInfo.size();

		pMsg.count = 0;

		NPCNAME_DATA info;

		for (; MakeList != gReadFiles.gCustomNPCListInfo.end(); MakeList++)
		{

			info.Index = MakeList->Index;

			info.NPCId = MakeList->NPCId;

			info.Map = MakeList->Map;

			info.X = MakeList->X;

			info.Y = MakeList->Y;

			strcpy_s(info.Name, MakeList->Name);

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gCustomNPCListInfo.end());
}

void CProtocol::CustomCloakListSend(int index) // OK
{
	std::vector<CLOAKNAME_DATA>::iterator MakeList = gReadFiles.gCustomCloakListInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CUSTOM_CLOAK_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x09, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gCustomCloakListInfo.size();

		pMsg.count = 0;

		CLOAKNAME_DATA info;

		for (; MakeList != gReadFiles.gCustomCloakListInfo.end(); MakeList++)
		{

			info.Index = MakeList->Index;

			info.ItemIndex = MakeList->ItemIndex;

			info.Mode = MakeList->Mode;

			info.IndexCloak = MakeList->IndexCloak;

			info.IndexStrip = MakeList->IndexStrip;

			strcpy_s(info.CloakName, MakeList->CloakName);

			strcpy_s(info.StripName, MakeList->StripName);

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gCustomCloakListInfo.end());
}

void CProtocol::CustomSmokeEffectListSend(int index) // OK
{
	std::vector<CUSTOM_SMOKEEFFECT>::iterator MakeList = gReadFiles.gCustomSmokeEffectInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CUSTOM_SMOKE_EFFECT_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x0B, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gCustomSmokeEffectInfo.size();

		pMsg.count = 0;

		CUSTOM_SMOKEEFFECT info;

		for (; MakeList != gReadFiles.gCustomSmokeEffectInfo.end(); MakeList++)
		{
			info.Index = MakeList->Index;

			info.ItemIndex = MakeList->ItemIndex;

			info.Red = MakeList->Red;

			info.Green = MakeList->Green;

			info.Blue = MakeList->Blue;

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gCustomSmokeEffectInfo.end());
}

void CProtocol::CustomFogListSend(int index) // OK
{
	std::vector<CUSTOM_FOG>::iterator MakeList = gReadFiles.gCustomFogInfo.begin();

	do
	{
		BYTE send[8192];

		SDHP_CUSTOM_FOG_LIST_SEND pMsg;

		pMsg.header.set(0x02, 0x0D, 0);

		int size = sizeof(pMsg);

		pMsg.MaxCount = gReadFiles.gCustomFogInfo.size();

		pMsg.count = 0;

		CUSTOM_FOG info;

		for (; MakeList != gReadFiles.gCustomFogInfo.end(); MakeList++)
		{
			info.Index = MakeList->Index;

			info.MapNumber = MakeList->MapNumber;

			info.Enable = MakeList->Enable;

			info.Red = MakeList->Red;

			info.Green = MakeList->Green;

			info.Blue = MakeList->Blue;

			if ((size + sizeof(info)) > sizeof(send))
			{
				break;
			}
			else
			{
				memcpy(&send[size], &info, sizeof(info));
				size += sizeof(info);

				pMsg.count++;
			}
		}

		pMsg.header.size[0] = SET_NUMBERHB(size);

		pMsg.header.size[1] = SET_NUMBERLB(size);

		memcpy(send, &pMsg, sizeof(pMsg));

		gSocketManager.DataSend(index, send, size);
	} while (MakeList != gReadFiles.gCustomFogInfo.end());
}

void CProtocol::ClientConnectRecv(SDHP_CLIENT_RECV_CONNECT* lpMsg, int index)// OK
{
	if (lpMsg->NewHardwareId[0] == NULL)
	{
		LogAdd(LOG_RED, "[%d] NewHardwareId NULL", index);
		return;
	}
	if (lpMsg->HardwareId[0] == NULL)
	{
		LogAdd(LOG_RED, "[%d] HardwareId NULL", index);
		return;
	}
	if (lpMsg->account[0] == NULL)
	{
		LogAdd(LOG_RED, "[%d] Account NULL", index);
		return;
	}
	if (lpMsg->PcName[0] == NULL)
	{
		LogAdd(LOG_RED, "[%d] PcName NULL", index);
		return;
	}

	gClientManager[index].SetDataServer(index, lpMsg->NewHardwareId, lpMsg->HardwareId, lpMsg->account, lpMsg->PcName);
}
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
		//CHClientConnectRecv((SDHP_CLIENT_RECV_CONNECT*)lpMsg, index);
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
		//CHClientHideShowRecv((SDHP_CLIENT_HIDESHOW_RECV*)lpMsg, index);
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

	pMsg.HackSwitch = gProtocol.HackSwitch;

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

	gSocketManager.DataSend(index, (BYTE*)&pMsg, pMsg.header.size);

	gProtocol.ChecksumListSend(index);

	gProtocol.WindowListSend(index);
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
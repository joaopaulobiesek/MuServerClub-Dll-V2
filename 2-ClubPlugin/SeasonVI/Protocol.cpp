#include "pch.h"

CProtocol gProtocol;

CProtocol::CProtocol() // OK
{
	this->VersionMu = 0;
	this->VersionMuHEX = 0x00;
	this->ConnectionStatusTime = 0;
	this->ChecksumListMaxCount = 0;
	this->WindowListMaxCount = 0;
	this->CustomMonsterListMaxCount = 0;
	this->CustomNPCListMaxCount = 0;
	this->ReconnectStatus = 0;
	this->ReconnectSwitch = 0;
	this->HackSwitch = 0;
	this->ClientInfoOK = 0;
	this->ChecksumListOK = 0;
	this->WindowListOK = 0;
	this->CustomMonsterListOK = 0;
	this->CustomNPCListOK = 0;
	this->DetectCloseTime = 0;
	this->UserAccount = 0;
	this->UserStruct = 0;
}

CProtocol::~CProtocol() // OK
{

}

void ProtocolCoreMain(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x00:
		gProtocol.ClientInfoRecv((SDHP_CLIENT_INFO_RECV*)lpMsg);
		break;
	case 0x01:
		gProtocol.ConnectionStatusRecv((SDHP_CONNECTION_STATUS_RECV*)lpMsg);
		break;
	case 0x02:
		switch (lpMsg[5])
		{
		case 0x01:
			gProtocol.ChecksumListRecv((SDHP_CHECKSUM_LIST_RECV*)lpMsg);
			break;
		case 0x03:
			gProtocol.WindowListRecv((SDHP_WINDOW_LIST_RECV*)lpMsg);
			break;
		case 0x05:
			gProtocol.CustomMonsterListRecv((SDHP_CUSTOM_MONSTER_LIST_RECV*)lpMsg);
			break;
		case 0x07:
			gProtocol.CustomNPCListRecv((SDHP_CUSTOM_NPC_LIST_RECV*)lpMsg);
			break;
		}
		break;
	case 0x03:
		gProtocol.ClientDisconnectRecv((SDHP_CLIENT_DISCONNECT_RECV*)lpMsg);
		break;
	case 0x04:
		break;
	case 0x05:
		break;
	case 0x06:
		break;
	case 0x07:
		break;
	case 0x08:
		break;
	case 0x09:
		break;
		////////////////// Aqui começas As Season.
	case 0x10://Season 0
		gProtocolS0.ProtocolCore(head, lpMsg, size);
		break;
	case 0x11://Season 2
		gProtocolS2.ProtocolCore(head, lpMsg, size);
		break;
	case 0x12://Season 4
		gProtocolS4.ProtocolCore(head, lpMsg, size);
		break;
	case 0x13://Season 6
		gProtocolS6.ProtocolCore(head, lpMsg, size);
		break;
	case 0x14://Season 8
		gProtocolS8.ProtocolCore(head, lpMsg, size);
		break;
	case 0x15://Season 10
		gProtocolS10.ProtocolCore(head, lpMsg, size);
		break;
	case 0x16://Season 12
		gProtocolS12.ProtocolCore(head, lpMsg, size);
		break;
	case 0x17://Season 13
		gProtocolS13.ProtocolCore(head, lpMsg, size);
		break;
	case 0x18://Season 14
		gProtocolS14.ProtocolCore(head, lpMsg, size);
		break;
	case 0x19://Season 15
		gProtocolS15.ProtocolCore(head, lpMsg, size);
		break;
	case 0x20://Season 16
		gProtocolS16.ProtocolCore(head, lpMsg, size);
		break;
	case 0x21://Season 17
		gProtocolS17.ProtocolCore(head, lpMsg, size);
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocol::ClientInfoSend() // OK
{
	if (ReconnectStatus != 1)
	{
		ClientInfoOK = 0;

		ChecksumListOK = 0;

		CustomMonsterListOK = 0;

		CustomNPCListOK = 0;

		ChecksumListMaxCount = 0;

		CustomMonsterListMaxCount = 0;

		CustomNPCListMaxCount = 0;

		gListManager.gChecksumListInfo.clear();

		gListManager.gCustomMonsterListInfo.clear();

		gListManager.gCustomNPCListInfo.clear();
	}

	SDHP_CLIENT_INFO_SEND pMsg;

	pMsg.header.set(0x00, sizeof(pMsg));

	pMsg.ClientFileCRC = gProtect.m_ClientFileCRC;

	memcpy(pMsg.VersionPlugin, HACKCLIENT_VERSION, sizeof(pMsg.VersionPlugin));

	memcpy(pMsg.HardwareId, GetHardwareId(), sizeof(pMsg.HardwareId));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocol::ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg)
{
	if (lpMsg->result == 0)
	{
		gProtocol.ClientInfoOK = 1;

		gProtocol.ConnectionStatusTime = GetTickCount();

		gProtocol.ReconnectSwitch = 1;

		gProtocol.HackSwitch = lpMsg->HackSwitch;

		gProtocol.VersionMu = lpMsg->Version;

		MemoryCpy((DWORD)gProtocol.IpAddress, lpMsg->IpAddress, sizeof(gProtocol.IpAddress));

		MemoryCpy((DWORD)gProtocol.ClientSerial, lpMsg->ClientSerial, sizeof(gProtocol.ClientSerial));

		gProtocol.ClientVersion[0] = (lpMsg->ClientVersion[0] + 1);

		gProtocol.ClientVersion[1] = (lpMsg->ClientVersion[2] + 2);

		gProtocol.ClientVersion[2] = (lpMsg->ClientVersion[3] + 3);

		gProtocol.ClientVersion[3] = (lpMsg->ClientVersion[5] + 4);

		gProtocol.ClientVersion[4] = (lpMsg->ClientVersion[6] + 5);

		gFeatures.camera3D = lpMsg->camera3D;

		gFeatures.antiLag = lpMsg->antiLag;

		gFeatures.customICO = lpMsg->customICO;

		gFeatures.removeSplash = lpMsg->removeSplash;

		MemoryCpy((DWORD)gProtocol.ClientSerial, lpMsg->ClientSerial, sizeof(gProtocol.ClientSerial));

		gOffset.Init(gProtocol.VersionMu, lpMsg);

		gMain.hWnd = *(HWND*)(lpMsg->HwndAddress);
	}
	else
	{
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(9), 5000);
		ExitProcess(0);
	}
}

void CProtocol::ConnectionStatusRecv(SDHP_CONNECTION_STATUS_RECV* lpMsg) // OK
{
	ConnectionStatusTime = GetTickCount();
}

void CProtocol::ClientSendHack(char* Account, char* Prog, int Status) // OK
{
	SDHP_CLIENT_HACK_SEND pMsg;

	pMsg.header.set(0x06, sizeof(pMsg));

	pMsg.Status = Status;

	memcpy(pMsg.Name, Account, sizeof(pMsg.Name));

	memcpy(pMsg.Program, Prog, sizeof(pMsg.Program));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocol::ChecksumListRecv(SDHP_CHECKSUM_LIST_RECV* lpMsg) // OK
{
	ChecksumListMaxCount = lpMsg->MaxCount;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CSUM_LIST_INFO* lpInfo = (CSUM_LIST_INFO*)(((BYTE*)lpMsg) + sizeof(SDHP_CHECKSUM_LIST_RECV) + (sizeof(CSUM_LIST_INFO) * n));

		gListManager.gChecksumListInfo.push_back((*lpInfo));
	}

	ChecksumListOK = 1;
}

void CProtocol::WindowListRecv(SDHP_WINDOW_LIST_RECV* lpMsg) // OK
{
	//gLog.Output(LOG_DEBUG, GetEncryptedString(43), lpMsg->count, lpMsg->MaxCount);

	WindowListMaxCount = lpMsg->MaxCount;

	for (int n = 0; n < lpMsg->count; n++)
	{
		WNDW_LIST_INFO* lpInfo = (WNDW_LIST_INFO*)(((BYTE*)lpMsg) + sizeof(SDHP_WINDOW_LIST_RECV) + (sizeof(WNDW_LIST_INFO) * n));

		gListManager.gWindowListInfo.push_back((*lpInfo));
	}

	WindowListOK = 1;
}

void CProtocol::CustomMonsterListRecv(SDHP_CUSTOM_MONSTER_LIST_RECV* lpMsg) // OK
{
	//gLog.Output(LOG_DEBUG, GetEncryptedString(43), lpMsg->count, lpMsg->MaxCount);

	CustomMonsterListMaxCount = lpMsg->MaxCount;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOMMONSTER_DATA* lpInfo = (CUSTOMMONSTER_DATA*)(((BYTE*)lpMsg) + sizeof(SDHP_CUSTOM_MONSTER_LIST_RECV) + (sizeof(CUSTOMMONSTER_DATA) * n));

		gListManager.gCustomMonsterListInfo.push_back((*lpInfo));
	}

	CustomMonsterListOK = 1;
}

void CProtocol::CustomNPCListRecv(SDHP_CUSTOM_NPC_LIST_RECV* lpMsg) // OK
{
	//gLog.Output(LOG_DEBUG, GetEncryptedString(43), lpMsg->count, lpMsg->MaxCount);

	CustomNPCListMaxCount = lpMsg->MaxCount;

	for (int n = 0; n < lpMsg->count; n++)
	{
		NPCNAME_DATA* lpInfo = (NPCNAME_DATA*)(((BYTE*)lpMsg) + sizeof(SDHP_CUSTOM_NPC_LIST_RECV) + (sizeof(NPCNAME_DATA) * n));

		gListManager.gCustomNPCListInfo.push_back((*lpInfo));
	}

	CustomNPCListOK = 1;
}

void CProtocol::ConnectionStatusSend() // OK
{
	SDHP_CONNECTION_STATUS_SEND pMsg;

	pMsg.header.set(0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocol::ClientDisconnectRecv(SDHP_CLIENT_DISCONNECT_RECV* lpMsg) // OK
{
	//gLog.Output(LOG_DEBUG,GetEncryptedString(30),lpMsg->type);

	switch (lpMsg->type)
	{
	case CLIENT_DISCONNECT_NONE:
		break;
	case CLIENT_DISCONNECT_DUMP_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(14), 5000);
		break;
	case CLIENT_DISCONNECT_EXECUTABLE_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(15), 5000);
		break;
	case CLIENT_DISCONNECT_FILE_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(16), 5000);
		break;
	case CLIENT_DISCONNECT_FILE_MAPPING_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(17), 5000);
		break;
	case CLIENT_DISCONNECT_LIBRARY_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(18), 5000);
		break;
	case CLIENT_DISCONNECT_REGISTRY_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(19), 5000);
		break;
	case CLIENT_DISCONNECT_MEMORY_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(20), 5000);
		break;
	case CLIENT_DISCONNECT_WINDOW_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(22), 5000);
		break;
	case CLIENT_DISCONNECT_MACRO_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(24), 5000);
		break;
	case CLIENT_DISCONNECT_DEBUGGER_DETECTION:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(25), 5000);
		break;
	case CLIENT_DISCONNECT_DETECTION_SQL:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(33), 5000);
		SafeExitProcess();
		break;
	case CLIENT_DISCONNECT_DETECTION_NOT_AUTH_EXIT:
		//ConnectErroAuthMsg(0);
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(34), 10000);
		SafeExitProcess();
		break;
	case CLIENT_DISCONNECT_DETECTION_NOT_AUTH_MSG:
		//ConnectErroAuthMsg(1);
		SplashScreen(&SplashError, 1, 1, gMessage.GetMessage(35), 5000);
		break;
	default:
		SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(21), 5000);
		break;
	}
}

void CProtocol::ClientDisconnectSend(int type, char* text, DWORD pid) // OK
{
	if (DetectCloseTime == 0)
	{
		DetectCloseTime = GetTickCount();

		SDHP_CLIENT_DISCONNECT_RECV pMsg;

		pMsg.header.set(0x03, sizeof(pMsg));

		pMsg.type = type;

		if (gConnection.CheckState() == 0) { ClientDisconnectRecv(&pMsg); return; }
	}
	else
	{
		return;
	}

	SDHP_CLIENT_DISCONNECT_SEND pMsg;

	pMsg.header.set(0x03, sizeof(pMsg));

	pMsg.type = type;

	if (UserAccount == 0)
	{
		memset(pMsg.account, 0, sizeof(pMsg.account));
	}
	else
	{
		memcpy(pMsg.account, (void*)UserAccount, sizeof(pMsg.account));
	}

	if (UserStruct == 0 || (*(DWORD*)(UserStruct)) == 0)
	{
		memset(pMsg.name, 0, sizeof(pMsg.name));
	}
	else
	{
		memcpy(pMsg.name, (void*)(*(DWORD*)(UserStruct)+0x00), sizeof(pMsg.name));
		MessageBox(0, pMsg.name, "Error", MB_OK | MB_ICONERROR);
	}

	if (text == 0)
	{
		memset(pMsg.CaptionName, 0, sizeof(pMsg.CaptionName));
	}
	else
	{
		memcpy(pMsg.CaptionName, text, sizeof(pMsg.CaptionName));
	}

	if (pid == 0)
	{
		memset(pMsg.ProcessName, 0, sizeof(pMsg.ProcessName));
	}
	else
	{
		memset(pMsg.ProcessName, 0, sizeof(pMsg.ProcessName));

		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, pid);

		if (hProcess != 0)
		{
			wchar_t szProcessName[MAX_PATH];

			if (GetProcessImageFileNameW(hProcess, szProcessName, MAX_PATH) != 0)
			{
				wsprintf(pMsg.ProcessName, "%S", ConvertModuleFileName(szProcessName));
			}

			CloseHandle(hProcess);
		}
	}

	//gLog.Output(LOG_DEBUG,GetEncryptedString(32),pMsg.type,pMsg.account,pMsg.name,pMsg.CaptionName,pMsg.ProcessName);

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocol::ClientConnectSend() // OK
{
	SDHP_CLIENT_SEND_CONNECT pMsg;

	pMsg.header.set(0x04, sizeof(pMsg));

	memcpy(pMsg.NewHardwareId, GetHardwareIdNew(), sizeof(pMsg.NewHardwareId));

	memcpy(pMsg.HardwareId, GetHardwareId(), sizeof(pMsg.HardwareId));

	memcpy(pMsg.account, gThread.NameAccount, sizeof(pMsg.account));

	memcpy(pMsg.PcName, GetPcName(), sizeof(pMsg.PcName));

	//gLog.Output(LOG_DEBUG,GetEncryptedString(31),pMsg.IsReconnect,pMsg.ClientFileCRC,pMsg.HackVersion,pMsg.HardwareId);

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
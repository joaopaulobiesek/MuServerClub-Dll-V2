#include "pch.h"

CProtocoloAuth gProtocoloAuth;
int MsgBox = 0;
int checkLoadInfo = 0;

void ProtocolCore(BYTE head, BYTE* lpMsg, int size) // OK
{
	switch (head)
	{
	case 0x00:
		gProtocoloAuth.ConnectionLicensedRecv((SERVERDLL_CONNECT_LICENSED_RECV*)lpMsg);
		break;
	case 0x01:
		gProtocoloAuth.CHConnectionStatusRecv((SERVERDLL_CLIENT_STATUS_RECV*)lpMsg);
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocoloAuth::SwitchFeature() // OK
{
	if (gFeatures.camera3D == 0)
	{
		LogAdd(LOG_RED, "[Camera 3D] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Camera 3D] Actived!");
	}

	if (gFeatures.antiLag == 0)
	{
		LogAdd(LOG_RED, "[AntiLag] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[AntiLag] Actived!");
	}

	if (gFeatures.customICO == 0)
	{
		LogAdd(LOG_RED, "[Custom ICO] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom ICO] Actived!");
	}

	if (gFeatures.removeSplash == 0)
	{
		LogAdd(LOG_RED, "[Remove Splash] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Remove Splash] Actived!");
	}

	if (gFeatures.twoFactorAuth == 0)
	{
		LogAdd(LOG_RED, "[2 FA] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[2 FA] Actived!");
	}

	if (gFeatures.emoji == 0)
	{
		LogAdd(LOG_RED, "[Emoji] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Emoji] Actived!");
	}

	if (gFeatures.customMoster == 0)
	{
		LogAdd(LOG_RED, "[Custom Moster] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom Moster] Actived!");
	}

	if (gFeatures.guildIco == 0)
	{
		LogAdd(LOG_RED, "[Guild Ico] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Guild Ico] Actived!");
	}

	if (gFeatures.petSafeZone == 0)
	{
		LogAdd(LOG_RED, "[Pet Safe Zone] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Pet Safe Zone] Actived!");
	}

	if (gFeatures.customNPC == 0)
	{
		LogAdd(LOG_RED, "[Custom NPC] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom NPC] Actived!");
	}

	if (gFeatures.customCloak == 0)
	{
		LogAdd(LOG_RED, "[Custom Cloak] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom Cloak] Actived!");
	}

	if (gFeatures.customOption == 0)
	{
		LogAdd(LOG_RED, "[Custom Option] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom Option] Actived!");
	}

	if (gFeatures.customEventTime == 0)
	{
		LogAdd(LOG_RED, "[Custom Event Time] Disabled!");
	}
	else
	{
		LogAdd(LOG_GREEN, "[Custom Event Time] Actived!");
	}
}

char* CProtocoloAuth::SwitchName(int SERVER_TYPE) // OK
{
	char Name[4];
	switch (SERVER_TYPE)
	{
	case AUTH_SERVER_TYPE_NONE:
		memcpy(Name, "TYPE_NONE", sizeof("TYPE_NONE"));
		break;
	case AUTH_SERVER_TYPE_S0_SERVERDLL:
		memcpy(Name, "Ex00", sizeof("Ex00"));
		break;
	case AUTH_SERVER_TYPE_S2_SERVERDLL:
		memcpy(Name, "Ex02", sizeof("Ex02"));
		break;
	case AUTH_SERVER_TYPE_S4_SERVERDLL:
		memcpy(Name, "Ex04", sizeof("Ex04"));
		break;
	case AUTH_SERVER_TYPE_S6_SERVERDLL:
		memcpy(Name, "Ex06", sizeof("Ex06"));
		break;
	case AUTH_SERVER_TYPE_S8_SERVERDLL:
		memcpy(Name, "Ex08", sizeof("Ex08"));
		break;
	case AUTH_SERVER_TYPE_S10_SERVERDLL:
		memcpy(Name, "Ex10", sizeof("Ex10"));
		break;
	case AUTH_SERVER_TYPE_S12_SERVERDLL:
		memcpy(Name, "Ex12", sizeof("Ex12"));
		break;
	case AUTH_SERVER_TYPE_S13_SERVERDLL:
		memcpy(Name, "Ex13", sizeof("Ex13"));
		break;
	case AUTH_SERVER_TYPE_S14_SERVERDLL:
		memcpy(Name, "Ex14", sizeof("Ex14"));
		break;
	case AUTH_SERVER_TYPE_S15_SERVERDLL:
		memcpy(Name, "Ex15", sizeof("Ex15"));
		break;
	case AUTH_SERVER_TYPE_S16_SERVERDLL:
		memcpy(Name, "Ex16", sizeof("Ex16"));
		break;
	case AUTH_SERVER_TYPE_S12_IGC_SERVERDLL:
		memcpy(Name, "IGC12", sizeof("IGC12"));
		break;
	case AUTH_SERVER_TYPE_S17_SERVERDLL:
		memcpy(Name, "Ex17", sizeof("Ex17"));
		break;
	default:
		memcpy(Name, "TYPE_NONE_D", sizeof("TYPE_NONE_D"));
		break;
	}
	return Name;
}

void CProtocoloAuth::ConnectionLicensedRecv(SERVERDLL_CONNECT_LICENSED_RECV* lpMsg) // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START

	if (lpMsg->Status != AUTH_SERVER_STATUS_SUCCESS)
	{
		this->ErrorMessageBox("Status");
		return;
	}
	if (lpMsg->licenseId != gServerInfo.LicenseId)
	{
		this->ErrorMessageBox("User Id");
		return;
	}
	if (strcmp(lpMsg->hwid, gServerInfo.HardwareId) != 0)
	{
		this->ErrorMessageBox("Hardware Id");
		return;
	}
	if (strcmp(lpMsg->ipAddress, gServerInfo.IpAddress) != 0)
	{
		this->ErrorMessageBox("Ip Address");
		return;
	}

	gProtocoloAuth.m_VersionId = lpMsg->versionId;

	gFeatures.camera3D = lpMsg->feature_1;

	gFeatures.antiLag = lpMsg->feature_2;

	gFeatures.customICO = lpMsg->feature_3;

	gFeatures.removeSplash = lpMsg->feature_4;

	gFeatures.twoFactorAuth = lpMsg->feature_5;

	gFeatures.emoji = lpMsg->feature_6;

	gFeatures.customMoster = lpMsg->feature_7;

	gFeatures.guildIco = lpMsg->feature_8;

	gFeatures.petSafeZone = lpMsg->feature_9;

	gFeatures.customNPC = lpMsg->feature_10;

	gFeatures.customCloak = lpMsg->feature_11;

	gFeatures.customOption = lpMsg->feature_12;

	gFeatures.customEventTime = lpMsg->feature_13;

	if (checkLoadInfo == 0)
	{
		this->SwitchFeature();
		checkLoadInfo = 1;		
	}

	gConnection.gConnectionStatusTime = GetTickCount();

	memcpy(this->m_Date, lpMsg->expireDate, sizeof(lpMsg->expireDate));

	gServerDisplayer.SetWindowName();
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void CProtocoloAuth::CHConnectionStatusRecv(SERVERDLL_CLIENT_STATUS_RECV* lpMsg) // OK
{
	VM_TIGER_BLACK_START

		if (lpMsg->Status != AUTH_SERVER_STATUS_SUCCESS)
		{
			gConnection.gReconnectSwitch = 2;
		}
	gConnection.gConnectionStatusTime = GetTickCount();

	VM_TIGER_BLACK_END
}

inline void CProtocoloAuth::ErrorMessageBox(const char* Error) // OK
{
	memset(&this->m_AuthInfo, 0, sizeof(this->m_AuthInfo));

	char buff[256];

	wsprintf(buff, "Authorization failed.\n\nVisit: www.muserver.club \n\nError: %s", Error);

	MessageBox(0, buff, "Error", MB_ICONSTOP | MB_OK);

	this->SafeExitProcess();
}

inline void CProtocoloAuth::SafeExitProcess() // OK
{
	while (true)
	{
		TerminateProcess(GetCurrentProcess(), 0);
		CRASH_APPLICATION_MACRO
	}
}
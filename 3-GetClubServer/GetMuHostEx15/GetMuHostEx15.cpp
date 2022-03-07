// GetMuHostEx15.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "CCRC32.h"
#include "Message.h"
#include "Themida/ThemidaSDK.h"

struct MAIN_FILE_INFO
{
	char IpAddress[32];
	WORD ServerPort;
	int removeSplash;
	char SerialMD5[32];
	char SplashName[32];
	char CameraName[32];
	DWORD CameraCRC32;
	MESSAGE_INFO EngMessageInfo[MAX_MESSAGE];
	MESSAGE_INFO PorMessageInfo[MAX_MESSAGE];
	MESSAGE_INFO SpnMessageInfo[MAX_MESSAGE];
};

int _tmain(int argc, _TCHAR* argv[])
{
	MAIN_FILE_INFO info;

	memset(&info, 0, sizeof(info));

	GetPrivateProfileString("ClubInfo", "IpAddress", "", info.IpAddress, sizeof(info.IpAddress), ".\\ClubInfo.ini");

	info.ServerPort = GetPrivateProfileInt("ClubInfo", "ServerPort", 0, ".\\ClubInfo.ini");

	GetPrivateProfileString("ClubInfo", "PasswordFiles", "", info.SerialMD5, sizeof(info.SerialMD5), ".\\ClubInfo.ini");

	GetPrivateProfileString("ClubInfo", "SplashName", "", info.SplashName, sizeof(info.SplashName), ".\ClubInfo.ini");

	info.removeSplash = GetPrivateProfileInt("ClubInfo", "Splash", 0, ".\\ClubInfo.ini");

	GetPrivateProfileString("ClubInfo", "CameraName", "", info.CameraName, sizeof(info.CameraName), ".\\ClubInfo.ini");

	gMessage.Load("Message.txt");

	memcpy(info.EngMessageInfo, gMessage.m_EngMessageInfo, sizeof(info.EngMessageInfo));

	memcpy(info.PorMessageInfo, gMessage.m_PorMessageInfo, sizeof(info.PorMessageInfo));

	memcpy(info.SpnMessageInfo, gMessage.m_SpnMessageInfo, sizeof(info.SpnMessageInfo));

	CCRC32 CRC32;

	if (CRC32.FileCRC(info.CameraName, &info.CameraCRC32, 1024) == 0)
	{
		info.CameraCRC32 = 0;
	}

	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		for (int n = 0; n < sizeof(MAIN_FILE_INFO); n++)
		{
			((BYTE*)&info)[n] ^= (BYTE)(0xD9 ^ LOBYTE(n));
			((BYTE*)&info)[n] -= (BYTE)(0x98 ^ HIBYTE(n));
		}
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END

		HANDLE file = CreateFile("MuServer.Club", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);

	if (file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if (WriteFile(file, &info, sizeof(MAIN_FILE_INFO), &OutSize, 0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);

	return 0;
}
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

CMain gMain;

extern "C" _declspec(dllexport) void EntryProc() // OK
{
	//Use 1 para desativar todos Custom do server para testes de offset;
	gProtocol.DebuggerCustomDisable = 0;

	gMain.NumberSplash1 = 103;
	gMain.NumberSplash2 = 104;
	gMain.NumberSplash3 = 105;

	char MuDll[32];

	strcpy(MuDll, "MuServer.Club");

	if (gProtect.ReadDllFile(MuDll) == 0)
	{
		char buff2[256];
		wsprintf(buff2, "%s not found or invalid!", MuDll);
		MessageBox(0, buff2, "Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	memcpy(gFileProtect.m_CryPass, gProtect.m_MainInfo.SerialMD5, sizeof(gFileProtect.m_CryPass));

	char buff[256];

	if (gProtect.m_MainInfo.removeSplash != 1)
	{
		wsprintf(buff, "Licensed to %s - Powered by Muserver.club", gProtect.m_MainInfo.SplashName);
		SplashScreen(&SplashInit, 0, 1, buff, 0);
	}

	gThread.Init();

	if (gProtect.m_MainInfo.removeFileProtect == 0)
	{
		gFileProtect.Init();
	}

	if (gProtect.m_MainInfo.removeSplash != 1)
	{
		SplashInit.CloseSplash();
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		gMain.hins = (HINSTANCE)hModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
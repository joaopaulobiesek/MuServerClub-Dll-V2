// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

CMain gMain;

extern "C" _declspec(dllexport) void EntryProc() // OK
{
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

	char buff[256];
	if (gProtect.m_MainInfo.removeSplash != 1)
	{
		wsprintf(buff, "Powered by Muserver.club");
		SplashScreen(&SplashInit, 0, 1, buff, 0);
	}

	gThread.Init();

	gFileProtect.Init();

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
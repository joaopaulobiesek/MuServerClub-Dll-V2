#include "pch.h"

CThread gThread;

CThread::CThread() // OK
{
	wsprintf(this->NameAccount, "MuServerClub");
}

CThread::~CThread() // OK
{

}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) // OK
{
	if (nCode == HC_ACTION)
	{
		switch (gProtocol.VersionMu)
		{
		case 1://Season 0
			break;
		case 2://Season 2
			break;
		case 3://Season 4
			break;
		case 4://Season 6
			gHookKBS6.Init(nCode, wParam, lParam);
			break;
		case 5://Season 8
			break;
		case 6://Season 10
			break;
		case 7://Season 12
			break;
		case 8://Season 13
			break;
		case 9://Season 14
			break;
		case 10://Season 15
			gHookKBS15.Init(nCode, wParam, lParam);
			break;
		case 11://Season 16
			break;
		case 12://Season 12 IGC
			break;
		case 13://Season 17
			gHookKBS17.Init(nCode, wParam, lParam);
			break;
		default:
			break;
		}
	}
	return CallNextHookEx(gMain.HookKB, nCode, wParam, lParam);
}

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) // OK
{
	if (nCode == HC_ACTION)
	{
		switch (gProtocol.VersionMu)
		{
		case 1://Season 0
			break;
		case 2://Season 2
			break;
		case 3://Season 4
			break;
		case 4://Season 6
			gHookMSS6.Init(nCode, wParam, lParam);
			break;
		case 5://Season 8
			break;
		case 6://Season 10
			break;
		case 7://Season 12
			break;
		case 8://Season 13
			break;
		case 9://Season 14
			break;
		case 10://Season 15
			gHookMSS15.Init(nCode, wParam, lParam);
			break;
		case 11://Season 16
			break;
		case 12://Season 12 IGC
			break;
		case 13://Season 17
			gHookMSS17.Init(nCode, wParam, lParam);
			break;
		default:
			break;
		}
	}
	return CallNextHookEx(gMain.HookMS, nCode, wParam, lParam);
}

void CThread::Init()
{
	CheckSystemInformation();

	DWORD ClientInfoTimeOut = GetTickCount();

	int CountId = 0;

	while (!DelayMe(500, 1))
	{
		if ((GetTickCount() - ClientInfoTimeOut) > 60000)
		{
			SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(7), 5000);
			SafeExitProcess();
			return;
		}

		if (gConnection.CheckState() == 0 && gConnection.Init(ProtocolCoreMain) != 0)
		{
			if (gConnection.Connect(gProtect.m_MainInfo.IpAddress, gProtect.m_MainInfo.ServerPort) != 0)
			{
				gProtocol.ClientInfoSend();
				continue;
			}
		}

		if (gProtocol.ClientInfoOK != 0 && gProtocol.ChecksumListOK != 0 && gProtocol.WindowListOK != 0 && gProtocol.CustomMonsterListOK != 0 && gProtocol.CustomNPCListOK != 0)
		{
			DWORD CurProgress = gListManager.gChecksumListInfo.size() + gListManager.gWindowListInfo.size() + gListManager.gCustomMonsterListInfo.size() + gListManager.gCustomNPCListInfo.size();

			DWORD MaxProgress = gProtocol.ChecksumListMaxCount + gProtocol.WindowListMaxCount + gProtocol.CustomMonsterListMaxCount + gProtocol.CustomNPCListMaxCount;

			if (CurProgress >= MaxProgress)
			{
				if (CountId >= 3)
				{
					break;
				}
				else
				{
					CountId++;
				}
			}
		}
	}

	if (gProtocol.HackSwitch == 1)
	{
		if (API_INIT() == 0)
		{
			SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(7), 5000);
			SafeExitProcess(); //Add Aqui envio de Info para servidor!
			return;
		}

		if (gProcessManager.Init() == 0)
		{
			SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(7), 5000);
			SafeExitProcess(); //Add Aqui envio de Info para servidor!
			return;
		}
	}

	this->ThreadHandles[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[1]);

	this->ThreadHandles[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionStatusThread, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[2]);

	this->ThreadHandles[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionReconnectThread, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[3]);

	if (gFeatures.customICO == 1) { this->ThreadHandles[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)IconeMu, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[4]); }

	this->ThreadHandles[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadSeasonCustom, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[5]);

	SetThreadPriority(this->ThreadHandles[0], THREAD_PRIORITY_HIGHEST);

	WaitForMultipleObjects(3, this->ThreadHandles, 1, 2000);

	gThreadCheck.Init();

	gMain.HookKB = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, gMain.hins, GetCurrentThreadId());

	gMain.HookMS = SetWindowsHookEx(WH_MOUSE, MouseProc, gMain.hins, GetCurrentThreadId());

	if (gFeatures.removeSplash == 0)
	{
		if (gProtect.m_MainInfo.removeSplash != gFeatures.removeSplash)
		{
			MessageBox(0, "Module Remove Splash not found", "Error", MB_OK | MB_ICONERROR);
			ExitProcess(0);
		}
	}

	if (gProtocol.VersionMu == 4) 
	{
		gObjUser.Load();
		gInterface.Load();
		gCustomInterface.Load();
		gCustomMonster.Scan();
		gCustomMonster.Load(gCustomMonster.m_CustomMonster);
		gNPCName.Scan();
		gNPCName.Load(gNPCName.m_CustomNpcName);
		gCustomMonster.InitMonster();
	}
}

DWORD WINAPI ThreadSeasonCustom() // OK
{
	while (!DelayMe(500, 100))
	{
		switch (gProtocol.VersionMu)
		{
		case 1://Season 0
			break;
		case 2://Season 2
			break;
		case 3://Season 4
			break;
		case 4://Season 6
			gThreadS6.Init();
			break;
		case 5://Season 8
			break;
		case 6://Season 10
			break;
		case 7://Season 12
			break;
		case 8://Season 13
			break;
		case 9://Season 14
			break;
		case 10://Season 15
			gThreadS15.Init();
			gCamera3dS15.ThreadCamS15();
			break;
		case 11://Season 16
			break;
		case 12://Season 12 IGC
			break;
		case 13://Season 17
			gThreadS17.Init();
			gCamera3dS17.ThreadCamS17();
			break;
		default:
			break;
		}
	}
	return 0;
}

LRESULT CALLBACK IconeMu() // OK
{
	if (!SleepEx(10, 0))
	{
		while (!gMain.hWnd && !SleepEx(10, 0));
	}

	STR_ENCRYPT_START

		HANDLE v0 = LoadImageA(0, "Data//S_icon.ico", 1, 32, 32, 16);

	HANDLE v1 = LoadImageA(0, "Data//B_icon.ico", 1, 128, 128, 16);

	STR_ENCRYPT_END

		SendMessageA(gMain.hWnd, 128, 0, (LPARAM)v0);

	return SendMessageA(gMain.hWnd, 128, 1, (LPARAM)v1);
}

DWORD WINAPI MainThread() // OK
{
	DWORD CycleCount = 0;

	DWORD CycleExecutionDelay = 500;

	LARGE_INTEGER Frequency;

	LARGE_INTEGER InitCounter;

	LARGE_INTEGER NextCounter;

	LARGE_INTEGER ElapsedMicroseconds;

	QueryPerformanceFrequency(&Frequency);

	QueryPerformanceCounter(&InitCounter);

	while (!DelayMe(((CycleExecutionDelay > 500) ? 0 : (500 - CycleExecutionDelay)), 1))
	{
		QueryPerformanceCounter(&NextCounter);

		ElapsedMicroseconds.QuadPart = ((NextCounter.QuadPart - InitCounter.QuadPart) * 1000000) / Frequency.QuadPart;

		if ((ElapsedMicroseconds.QuadPart / 1000) > 1500)
		{
			SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(0), 5000);
			SafeExitProcess();
			return 0;
		}

		QueryPerformanceFrequency(&Frequency);

		QueryPerformanceCounter(&InitCounter);

		if (gProtocol.DetectCloseTime != 0)
		{
			if ((GetTickCount() - gProtocol.DetectCloseTime) > 10000)
			{
				//SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(21), 5000);
				SafeExitProcess();
				return 0;
			}
		}

		if (gOffset.IpAddressAddress != 0)
		{
			MemoryCpy(gOffset.IpAddressAddress, gProtocol.IpAddress, sizeof(gProtocol.IpAddress));
		}

		if (gOffset.ClientVersionAddress != 0)
		{
			MemoryCpy(gOffset.ClientVersionAddress, gProtocol.ClientVersion, sizeof(gProtocol.ClientVersion));
		}

		if (gOffset.ClientSerialAddress != 0)
		{
			MemoryCpy(gOffset.ClientSerialAddress, gProtocol.ClientSerial, sizeof(gProtocol.ClientSerial));
		}

		if (gProtocol.HackSwitch == 1)
		{
			switch (((CycleCount++) % 10))
			{
			case 0:
				API_SCAN();
				gWindowCheck.Scan();
				gProcessManager.CheckProcess(15);
				break;
			case 2:
				API_SCAN();
				gWindowCheck.Scan();
				gProcessManager.CheckProcess(15);
				break;
			case 3:
				gFileCheck.Scan();
				break;
			case 4:
				API_SCAN();
				gWindowCheck.Scan();
				gProcessManager.CheckProcess(15);
				break;
			case 6:
				API_SCAN();
				gWindowCheck.Scan();
				gProcessManager.CheckProcess(15);
				break;
			case 8:
				API_SCAN();
				gWindowCheck.Scan();
				gProcessManager.CheckProcess(15);
				break;
			default:
				break;
			}
		}
		else
		{
			switch (((CycleCount++) % 10))
			{
			default:
				break;
			}
		}

		QueryPerformanceCounter(&NextCounter);

		ElapsedMicroseconds.QuadPart = ((NextCounter.QuadPart - InitCounter.QuadPart) * 1000000) / Frequency.QuadPart;

		CycleExecutionDelay = (DWORD)(ElapsedMicroseconds.QuadPart / 1000);

		QueryPerformanceFrequency(&Frequency);

		QueryPerformanceCounter(&InitCounter);
	}

	return 0;
}

DWORD WINAPI ConnectionReconnectThread() // OK
{
	while (!DelayMe(5000, 100))
	{
		if (gProtocol.ReconnectStatus == 1)
		{
			if (gConnection.Init(ProtocolCoreMain) == 0)
			{
				SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(1), 5000);
				SafeExitProcess();
				continue;
			}

			if (gConnection.Connect(gProtect.m_MainInfo.IpAddress, gProtect.m_MainInfo.ServerPort) == 0)
			{
				gProtocol.ConnectionStatusTime = GetTickCount();
				continue;
			}

			gProtocol.ReconnectStatus = 2;

			gProtocol.ConnectionStatusTime = GetTickCount();

			gProtocol.ClientInfoSend();
			gProtocol.ClientConnectSend();
		}
	}

	return 0;
}

DWORD WINAPI ConnectionStatusThread() // OK
{
	while (!DelayMe(5000, 100))
	{
		if (gConnection.CheckState() == 0)
		{
			if (gProtocol.ReconnectStatus == 0 || gProtocol.ReconnectStatus == 2)
			{
				gProtocol.ReconnectStatus = 1;
				continue;
			}

			if (gProtocol.ReconnectSwitch == 0)
			{
				SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(2), 5000);
				continue;
			}

			if (gProtocol.ReconnectStatus == 1)
			{
				gProtocol.ConnectionStatusTime = GetTickCount();
				continue;
			}
		}
		else
		{
			if ((GetTickCount() - gProtocol.ConnectionStatusTime) > 60000)
			{
				SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(3), 5000);
				gProtocol.ConnectionStatusTime = GetTickCount();
				SafeExitProcess();
				continue;
			}
			else
			{
				gProtocol.ConnectionStatusSend();
				continue;
			}
		}
	}

	return 0;
}
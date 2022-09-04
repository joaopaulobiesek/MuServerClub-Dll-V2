#include "pch.h"

CThreadAuth gThreadAuth;

CThreadAuth::CThreadAuth() // OK
{
	this->CountTime = 0;
	this->CountTimeMinimized = 0;
	this->CountServerDllCheck = 0;
	this->randomNumber = 0;
}

CThreadAuth::~CThreadAuth() // OK
{
}

int CThreadAuth::round(double number)
{
	return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5) + 1;
}

DWORD WINAPI ConnectionReconnectThread() // OK
{
	while (!DelayMe(5000, 100))
	{
		if (gConnectionAuth.gReconnectStatus == 1)
		{
			if (gConnectionAuth.Init(ProtocolCore) == 0)
			{
				gProtocoloAuth.ErrorMessageBox("Reconnect ProtocolCore");
				gProtocoloAuth.SafeExitProcess();
				continue;
			}

			if (gConnectionAuth.Connect(AUTH_ADDRESS_A, AUTH_PORT) == 0)
			{
				gConnectionAuth.gConnectionStatusTime = GetTickCount();
				continue;
			}

			gConnectionAuth.gReconnectStatus = 2;

			gConnectionAuth.gConnectionStatusTime = GetTickCount();

			gConnectionAuth.CHClientInfoSend();
		}
	}

	return 0;
}

DWORD WINAPI ConnectionStatusThread() // OK
{
	while (!DelayMe(5000, 100))
	{
		TimeoutProc();// Responsavel por zerar o UserCountOnline////////////////////////////////////////////
		if (gConnectionAuth.gReconnectSwitch == 2)
		{
			gConnectionAuth.gReconnectStatus = 0;
			closesocket(gConnectionAuth.m_socket);
			gConnectionAuth.m_socket = INVALID_SOCKET;
			closesocket(gSocketManager.m_listen);
			gSocketManager.m_listen = INVALID_SOCKET;
			gConnectionAuth.gConnectionStatusTime = GetTickCount();
			gProtocoloAuth.ErrorMessageBox("ReconnectSwitch = 2 & Status: 0;");
			gProtocoloAuth.SafeExitProcess();
			break;
		}

		if (gConnectionAuth.CheckState() == 0)
		{
			if (gConnectionAuth.gReconnectStatus == 0 || gConnectionAuth.gReconnectStatus == 2)
			{
				gConnectionAuth.gReconnectStatus = 1;
				continue;
			}

			if (gConnectionAuth.gReconnectSwitch == 0)
			{
				gThreadAuth.CountTime++;
				gConnectionAuth.gConnectionStatusTime = GetTickCount();
				if (gThreadAuth.CountTime % 30 == 0) LogAdd(LOG_RED, "Connect Status Error 60s. Count: %d/25", gThreadAuth.round(gThreadAuth.CountTime / 30) + 1);
				if (gThreadAuth.CountTime > 720)
				{
					gProtocoloAuth.ErrorMessageBox("Connect Status Error 60s.");
					gProtocoloAuth.SafeExitProcess();
				}
				continue;
			}

			if (gConnectionAuth.gReconnectStatus == 1)
			{
				gConnectionAuth.gConnectionStatusTime = GetTickCount();
				continue;
			}
		}
		else
		{
			gThreadAuth.CountTime = 0;
			gConnectionAuth.CHConnectionStatusSend();
			continue;
		}
	}

	return 0;
}

void CThreadAuth::Init()
{
	DWORD ClientInfoTimeOut = GetTickCount();

	while (!DelayMe(500, 1))
	{
		if ((GetTickCount() - ClientInfoTimeOut) > 60000)
		{
			//SplashScreen(&SplashError, 2, 1, gMessage.GetMessage(7), 5000);
			LogAdd(LOG_BLACK, "ERRO Init(ProtocolCore)");
			gProtocoloAuth.SafeExitProcess();
			return;
		}

		if (gConnectionAuth.CheckState() == 0 && gConnectionAuth.Init(ProtocolCore) != 0)
		{
			if (gConnectionAuth.Connect(AUTH_ADDRESS_A, AUTH_PORT) != 0)
			{
				gConnectionAuth.CHClientInfoSend();
				break;
			}
		}
	}

	gThreadAuth.ThreadHandles[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionStatusThread, 0, 0, (DWORD*)&gThreadCheckAuth.m_CheckThreadID[1]);

	gThreadAuth.ThreadHandles[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionReconnectThread, 0, 0, (DWORD*)&gThreadCheckAuth.m_CheckThreadID[2]);

	SetThreadPriority(gThreadAuth.ThreadHandles[0], THREAD_PRIORITY_HIGHEST);

	WaitForMultipleObjects(3, gThreadAuth.ThreadHandles, 1, 2000);

	gThreadCheckAuth.Init();
}
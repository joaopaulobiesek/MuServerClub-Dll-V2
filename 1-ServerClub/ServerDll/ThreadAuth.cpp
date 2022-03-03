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
		if (gConnection.gReconnectStatus == 1)
		{
			if (gConnection.Init(ProtocolCore) == 0)
			{
				gProtocoloAuth.ErrorMessageBox("Reconnect ProtocolCore");
				gProtocoloAuth.SafeExitProcess();
				continue;
			}

			if (gConnection.Connect(AUTH_ADDRESS_A, AUTH_PORT) == 0)
			{
				gConnection.gConnectionStatusTime = GetTickCount();
				continue;
			}

			gConnection.gReconnectStatus = 2;

			gConnection.gConnectionStatusTime = GetTickCount();

			gConnection.CHClientInfoSend();
		}
	}

	return 0;
}

DWORD WINAPI ConnectionStatusThread() // OK
{
	while (!DelayMe(5000, 100))
	{
		TimeoutProc();// Responsavel por zerar o UserCountOnline////////////////////////////////////////////
		if (gConnection.gReconnectSwitch == 2)
		{
			gConnection.gReconnectStatus = 0;
			closesocket(gConnection.m_socket);
			gConnection.m_socket = INVALID_SOCKET;
			closesocket(gSocketManager.m_listen);
			gSocketManager.m_listen = INVALID_SOCKET;
			gConnection.gConnectionStatusTime = GetTickCount();
			gProtocoloAuth.ErrorMessageBox("ReconnectSwitch = 2 & Status: 0;");
			gProtocoloAuth.SafeExitProcess();
			break;
		}

		if (gConnection.CheckState() == 0)
		{
			if (gConnection.gReconnectStatus == 0 || gConnection.gReconnectStatus == 2)
			{
				gConnection.gReconnectStatus = 1;
				continue;
			}

			if (gConnection.gReconnectSwitch == 0)
			{
				gThreadAuth.CountTime++;
				gConnection.gConnectionStatusTime = GetTickCount();
				if (gThreadAuth.CountTime % 30 == 0) LogAdd(LOG_RED, "Connect Status Error 60s. Count: %d/25", gThreadAuth.round(gThreadAuth.CountTime / 30) + 1);
				if (gThreadAuth.CountTime > 720)
				{
					gProtocoloAuth.ErrorMessageBox("Connect Status Error 60s.");
					gProtocoloAuth.SafeExitProcess();
				}
				continue;
			}

			if (gConnection.gReconnectStatus == 1)
			{
				gConnection.gConnectionStatusTime = GetTickCount();
				continue;
			}
		}
		else
		{
			gThreadAuth.CountTime = 0;
			gConnection.CHConnectionStatusSend();
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

		if (gConnection.CheckState() == 0 && gConnection.Init(ProtocolCore) != 0)
		{
			if (gConnection.Connect(AUTH_ADDRESS_A, AUTH_PORT) != 0)
			{
				gConnection.CHClientInfoSend();
				break;
			}
		}
	}

	gThreadAuth.ThreadHandles[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionStatusThread, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[1]);

	gThreadAuth.ThreadHandles[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionReconnectThread, 0, 0, (DWORD*)&gThreadCheck.m_CheckThreadID[2]);

	SetThreadPriority(gThreadAuth.ThreadHandles[0], THREAD_PRIORITY_HIGHEST);

	WaitForMultipleObjects(3, gThreadAuth.ThreadHandles, 1, 2000);

	gThreadCheck.Init();
}
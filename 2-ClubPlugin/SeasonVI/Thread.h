#pragma once

enum ObjState
{
	LoadingServer = 2,
	SelectServer = 3,
	SwitchCharacter = 5,
	GameProcess = 6,
};

class CThread
{
public:
	CThread();
	virtual ~CThread();
	void Init();

public:
private:
	HANDLE ThreadHandles[8];
};

DWORD WINAPI MainThread();
DWORD WINAPI ConnectionReconnectThread();
DWORD WINAPI ConnectionStatusThread();
LRESULT CALLBACK IconeMu();
DWORD WINAPI ThreadSeasonCustom();
extern CThread gThread;
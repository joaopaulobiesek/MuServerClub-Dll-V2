#pragma once

enum ObjState
{
	LoadingServer = 2,
	SelectServer = 3,
	SwitchCharacter = 5,
	GameProcess = 6,
};

enum ObjStateS6
{
	LoadingServer_2 = 1,
	SelectServer_2 = 2,
	SwitchCharacter_2 = 4,
	GameProcess_2 = 5,
};

class CThread
{
public:
	CThread();
	virtual ~CThread();
	void Init();

public:
	char NameAccount[12];
private:
	HANDLE ThreadHandles[8];
};

DWORD WINAPI MainThread();
DWORD WINAPI ConnectionReconnectThread();
DWORD WINAPI ConnectionStatusThread();
LRESULT CALLBACK IconeMu();
DWORD WINAPI ThreadSeasonCustom();
extern CThread gThread;
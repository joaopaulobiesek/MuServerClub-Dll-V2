#pragma once

class CThreadS0
{
public:
	CThreadS0();
	virtual ~CThreadS0();
	void Init();
	void SelectServerThread(int Cod_ID);
	void SwitchCharacterThread(int Cod_ID);
	void GameProcessThread(int Cod_ID);
public:
	DWORD GET_HWND;
	int Count;
	int GetAntLag;
private:
	char* GetCharacterN;
	RECT rect;
	DWORD Level;
	DWORD MLevel;
	DWORD PosX;
	DWORD PosY;
	int Map;
	DWORD BaseAddress;
};

extern CThreadS0 gThreadS0;
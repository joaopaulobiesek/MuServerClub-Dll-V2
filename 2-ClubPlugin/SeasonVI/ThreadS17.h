#pragma once

class CThreadS17
{
public:
	CThreadS17();
	virtual ~CThreadS17();
	void Init();
	void SelectServerThread(int Cod_ID);
	void SwitchCharacterThread(int Cod_ID);
	void GameProcessThread(int Cod_ID);
public:
	DWORD GET_HWND;
	int Count;
	int GetAntLag;

};

extern CThreadS17 gThreadS17;
#pragma once

class CThreadS15
{
public:
	CThreadS15();
	virtual ~CThreadS15();
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

extern CThreadS15 gThreadS15;
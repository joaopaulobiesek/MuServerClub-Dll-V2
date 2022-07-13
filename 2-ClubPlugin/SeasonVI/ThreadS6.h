#pragma once

class CThreadS6
{
public:
	CThreadS6();
	virtual ~CThreadS6();
	void Init();
	void InitCustom();
	void SelectServerThread(int Cod_ID);
	void SwitchCharacterThread(int Cod_ID);
	void GameProcessThread(int Cod_ID);
public:
	DWORD GET_HWND;
	int Count;
	int GetAntLag;

	int PetSafeZone_Horse;
	int PetSafeZone_Dinorant;
	int PetSafeZone_Fenrir;

	int ActiveNameServer;
	char Name1Server[32];
	char Name2Server[32];
	char Name3Server[32];
	char Name4Server[32];
	int KeyEventTime;
	int DownS6;
	int SmokeEffect;
	int CustomFog;
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

extern CThreadS6 gThreadS6;
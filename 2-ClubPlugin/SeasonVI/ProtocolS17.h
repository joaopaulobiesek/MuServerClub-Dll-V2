#pragma once

//**********************************************//
//************ Dll -> Server *******************//
//**********************************************//

struct SDHP_REQUEST_OFFSET_S17_SEND
{
	HEAD_VERSION header; // C1:00
};

struct SDHP_REQUEST_KEYBOARD_S17_SEND
{
	HEAD_VERSION header; // C1:00
};

//**********************************************//
//************ Server -> Dll *******************//
//**********************************************//

struct SDHP_REQUEST_OFFSET_S17_RECV
{
	HEAD_VERSION header; // C1:00
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_VIEWPORT_STRUCT;
	DWORD MAIN_MAP_CODE;
	DWORD pDrawMessage;
	DWORD gCameraPosXC;
	DWORD gCameraPosYC;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD Skill4Active;
	DWORD Skill5Active;
	DWORD Skill6ActiveHook;
	DWORD ZenActive;
	DWORD ItemActive;
	DWORD Pet1Active;
	DWORD Pet2ActiveHook;
	DWORD Pet3Active;
	DWORD Pet4ActiveHook;
	DWORD Char1Moob1Active;
	DWORD Char1Moob2ActiveHook;
	DWORD Char2Moob3Active;
	DWORD Char2Moob4Active;
	DWORD Char2Moob5ActiveHook;
	DWORD Terrain1Active;
	DWORD Terrain2Active;
	DWORD RemoveSetActive;
	DWORD CameraY;
	DWORD CameraZ;
	DWORD CameraX;
	DWORD CameraZoom1;
	DWORD CameraZoom2;
	DWORD CameraZoom3;
	DWORD CameraZoomByte;
	DWORD CameraArena;
	DWORD CameraFuncNull;
	DWORD CameraHook;
};

struct SDHP_REQUEST_KEYBOARD_S17_RECV
{
	HEAD_VERSION header; // C1:00
	int Func1; //Ativar/Desativar Câmera 3D
	int Func2; //Reseta a Câmera 3D
	int Func3; //Ativa/Desativa renderização das Asas
	int Func4; //Ativa/Desativa efeitos de Skills e Brilhos
	int Func5; //Ativa/Desativa renderização das moedas no chão
	int Func6; //Ativa/Desativa renderização dos itens do chão
	int Func7; //Ativa/Desativa renderização Terrain Obj
	int Func8; //Ativa/Desativa Set
	int Func9; //Ativa/Desativa renderização dos pets
	int Func10; //Ativa/Desativa renderização de chars e mobs 1
	int Func11; //Ativa/Desativa renderização de chars e mobs 2
	int Func12; //Ativa/Desativa todo AntLag
	int Func13; //Ativa/Desativa efeitos diversos (Skills, Asas, Buffs, Drop de Moedas, Muuns)
};


class CProtocolS17
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
	void RecvKeyboardS17(SDHP_REQUEST_KEYBOARD_S17_RECV* lpMsg);
	void RequestOffSetS17();
	void RequestKeyboardS17();

public:
};

extern CProtocolS17 gProtocolS17;
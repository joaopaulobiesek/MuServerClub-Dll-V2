#pragma once

//**********************************************//
//************ Dll -> Server *******************//
//**********************************************//

struct SDHP_REQUEST_OFFSET_S2_RECV
{
	HEAD_VERSION header; // C1:00
};

struct SDHP_REQUEST_KEYBOARD_S2_RECV
{
	HEAD_VERSION header; // C1:00
};

//**********************************************//
//************ Server -> Dll *******************//
//**********************************************//

struct SDHP_REQUEST_OFFSET_S2_SEND
{
	HEAD_VERSION header; // C1:00
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_MAP_CODE;
	DWORD pDrawMessage;
	DWORD WingActive;
	DWORD Skill1Active;
	DWORD Skill2Active;
	DWORD Skill3Active;
	DWORD ItemActive;
	DWORD Terrain1Active;
};

struct SDHP_REQUEST_KEYBOARD_S2_SEND
{
	HEAD_VERSION header; // C1:00
	int Func1; //Ativar/Desativar C�mera 3D
	int Func2; //Reseta a C�mera 3D
	int Func3; //Ativa/Desativa renderiza��o das Asas
	int Func4; //Ativa/Desativa efeitos de Skills e Brilhos
	int Func5; //Ativa/Desativa renderiza��o das moedas no ch�o
	int Func6; //Ativa/Desativa renderiza��o dos itens do ch�o
	int Func7; //Ativa/Desativa renderiza��o Terrain Obj
	int Func8; //Ativa/Desativa Set
	int Func9; //Ativa/Desativa renderiza��o dos pets
	int Func10; //Ativa/Desativa renderiza��o de chars e mobs 1
	int Func11; //Ativa/Desativa renderiza��o de chars e mobs 2
	int Func12; //Ativa/Desativa todo AntLag
	int Func13; //Ativa/Desativa efeitos diversos (Skills, Asas, Buffs, Drop de Moedas, Muuns)
};

class CProtocolS2
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
	void RequestOffSetS2(SDHP_REQUEST_OFFSET_S2_RECV* lpMsg, int index);
	void RequestKeyBoardS2(SDHP_REQUEST_KEYBOARD_S2_RECV* lpMsg, int index);
public:
};

extern CProtocolS2 gProtocolS2;

#pragma once
class CHookKBS6
{
public:
	CHookKBS6();
	virtual ~CHookKBS6();
	void Init(int nCode, WPARAM wParam, LPARAM lParam);
public:
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
	int Func14; //Ativa/Desativa MiniMap
	int PositionMouse;
};

extern CHookKBS6 gHookKBS6;
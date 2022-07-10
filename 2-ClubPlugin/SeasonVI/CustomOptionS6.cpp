#include "pch.h"

CCustomOptionS6 gCustomOptionS6;

CCustomOptionS6::CCustomOptionS6()
{

	this->JCOption[0].SetText("Show Wing");
	this->JCOption[0].LoadAction(gAntiLagS6.case3, Effect_DisableWing);

	this->JCOption[1].SetText("Show Skill");
	this->JCOption[1].LoadAction(gAntiLagS6.case4, Effect_DisableSkill);

	this->JCOption[2].SetText("Show Drop Zen");
	this->JCOption[2].LoadAction(gAntiLagS6.case5, Effect_DisableDropZen);

	this->JCOption[3].SetText("Show Drop Item");
	this->JCOption[3].LoadAction(gAntiLagS6.case6, Effect_DisableDropItem);

	this->JCOption[4].SetText("Show Pet");
	this->JCOption[4].LoadAction(gAntiLagS6.case9, Effect_DisablePet);

	this->JCOption[5].SetText("Show Obj Terrain");
	this->JCOption[5].LoadAction(gAntiLagS6.case7, Effect_DisableObjTerrain);

	this->JCOption[6].SetText("Show Set");
	this->JCOption[6].LoadAction(gAntiLagS6.case8, Effect_RemoveSet);
}

CCustomOptionS6::~CCustomOptionS6()
{
}

void CCustomOptionS6::PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	EnableAlphaTest(1);

	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central

	float RightX = PosX - 8.0f;
	float LeftX = (PosX + Width) - 8.0f;
	float TopY = PosY - 8.0f;
	float DownY = (PosY + Height) - 8.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 8.0f;
	float w = 16.0f;
	//--
	float IniciarY = PosY - 8.0f;
	float H = 16.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while (vertical || horizontal)
	{
		if (vertical)
		{
			IniciarX += 16.0f;

			if ((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(71512, IniciarX, TopY, w, 16.0f); //arriba

			pDrawGUI(71517, IniciarX, DownY, w, 16.0f); //abajo
		}
		//-- abajo
		if (horizontal)
		{
			IniciarY += 16.0f;

			if ((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(71514, RightX, IniciarY, 16.0f, H); // Lado Izquierdo

			pDrawGUI(71515, LeftX, IniciarY, 16.0f, H); //Lado Derecho
		}
	}

	pDrawGUI(71511, RightX, TopY, 16.0f, 16.0f); //esquina arriba izquierda

	pDrawGUI(71513, LeftX, TopY, 16.0f, 16.0f); //esquina arriba derecha

	pDrawGUI(71516, RightX, DownY, 16.0f, 16.0f);  //esquina abajo izquierda

	pDrawGUI(71518, LeftX, DownY, 16.0f, 16.0f);  //esquina abajo derecha

	pGLSwitch();
	EnableAlphaTest(0);
}

bool CCustomOptionS6::EventPushCursor(int x, int y, int w, int h)
{
	if (pCheckMouseOver(x, y, w, h))
	{
		if (*(BYTE*)0x8793386)
		{
			if (GetTickCount() >= this->TimerPush + 200)
			{
				this->TimerPush = GetTickCount();
				return true;
			}
		}
	}
	return false;
}

void CCustomOptionS6::EventPanelOption()
{
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	x = (double)*(signed int*)(This + 16);
	y = (double)*(signed int*)(This + 20);
	//--
	if (this->EventPushCursor(x + 32, y + 40, 15, 15)) {
		gInterface.MiniMap = !gInterface.MiniMap;
		if (gInterface.MiniMap != 0)
			WritePrivateProfileStringA("Graphics", "MiniMap", "1", "./option.ini");
		else
			WritePrivateProfileStringA("Graphics", "MiniMap", "0", "./option.ini");
	}
	//--
	if (this->EventPushCursor(x + 32, y + 60, 15, 15)) {
		gInterface.CharName = !gInterface.CharName;
		if (gInterface.CharName != 0)
			WritePrivateProfileStringA("Graphics", "CharName", "1", "./option.ini");
		else
			WritePrivateProfileStringA("Graphics", "CharName", "0", "./option.ini");
	}
	//--
	if (this->EventPushCursor(x + 130, y + 40, 15, 15)) {
		gInterface.MonsterName = !gInterface.MonsterName;
		if (gInterface.MonsterName != 0)
			WritePrivateProfileStringA("Graphics", "MonsterName", "1", "./option.ini");
		else
			WritePrivateProfileStringA("Graphics", "MonsterName", "0", "./option.ini");
	}

	int RESOLUTION;
	//===============================================================================\\	 
	//================================RESOLUCIONES===================================\\	
	//===============================================================================\\	
	if (this->EventPushCursor(x - 45, y + 40, 40, 12)) {
		RegeditData(0);
		ChangeSize(0x280u, 480);
		RESOLUTION = 640;
	}
	else if (this->EventPushCursor(x - 45, y + 58, 40, 12)) {
		RegeditData(1);
		RESOLUTION = 800;
		ChangeSize(0x320u, 600);
	}
	else if (this->EventPushCursor(x - 45, y + 78, 40, 12)) {
		RegeditData(2);
		RESOLUTION = 1024;
		ChangeSize(0x400u, 768);
	}
	else if (this->EventPushCursor(x - 45, y + 98, 40, 12)) {
		RegeditData(3);
		RESOLUTION = 1280;
		ChangeSize(0x500u, 768);
	}
	else if (this->EventPushCursor(x - 45, y + 118, 40, 12)) {
		RegeditData(4);
		RESOLUTION = 1366;
		ChangeSize(0x556u, 768);

	}
	else if (this->EventPushCursor(x - 45, y + 138, 40, 12)) {
		RegeditData(5);
		RESOLUTION = 1440;
		ChangeSize(0x5A0u, 900);
	}
	else if (this->EventPushCursor(x - 45, y + 158, 40, 12)) {
		RegeditData(6);
		RESOLUTION = 1600;
		ChangeSize(0x640u, 900);
	}
	else if (this->EventPushCursor(x - 45, y + 178, 40, 12)) {
		RegeditData(7);
		RESOLUTION = 1600;
		ChangeSize(0x640u, 1280);
	}
	else if (this->EventPushCursor(x - 45, y + 198, 40, 12)) {
		RegeditData(8);
		RESOLUTION = 1680;
		ChangeSize(0x690u, 1050);
	}
	else if (this->EventPushCursor(x - 45, y + 218, 40, 12)) {
		RegeditData(9);
		RESOLUTION = 1920;
		ChangeSize(0x780u, 1080);
	}
	//===============================================================================\\	 
	//================================TAMAÑO DE FUENTE===============================\\	
	//===============================================================================\\	
	if (this->EventPushCursor(x + 97, y + 285, 18, 12)) {
		gFont.FontSizeLoad(11);
		gCustomCommonS6.FontHeight = 11;
	}
	if (this->EventPushCursor(x + 117, y + 285, 18, 12)) {
		gFont.FontSizeLoad(12);
		gCustomCommonS6.FontHeight = 12;
	}
	if (this->EventPushCursor(x + 137, y + 285, 18, 12)) {
		gFont.FontSizeLoad(14);
		gCustomCommonS6.FontHeight = 13;
	}
	if (this->EventPushCursor(x + 157, y + 285, 18, 12)) {
		gFont.FontSizeLoad(15);
		gCustomCommonS6.FontHeight = 14;
	}
	if (this->EventPushCursor(x + 177, y + 285, 18, 12)) {
		gFont.FontSizeLoad(16);
		gCustomCommonS6.FontHeight = 15;
	}
	if (this->EventPushCursor(x + 197, y + 285, 18, 12)) {
		gFont.FontSizeLoad(17);
		gCustomCommonS6.FontHeight = 16;
	}
	//===============================================================================\\	

	if (this->EventPushCursor(x + 78, y + 286, 15, 15)) {
		gCustomCommonS6.FontON = !gCustomCommonS6.FontON;
		if (gCustomCommonS6.FontON != 0)
			WritePrivateProfileStringA("FontConfig", "FontON", "1", "./Settings.ini");
		else
			WritePrivateProfileStringA("FontConfig", "FontON", "0", "./Settings.ini");
	}
}

__declspec(naked) void RemoveShadoW()
{
	static DWORD pShadow;
	static DWORD RenderI;
	static DWORD main_addr;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x14]
		MOV RenderI, ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x10]
		MOV pShadow, EDX
	}

	if (gCustomOptionS6.DisableShadow != 0)
		pShadow = RenderI;

	main_addr = (RenderI < pShadow) ? 0x0054A325 : 0x0054A31F;

	_asm
	{
		JMP[main_addr]
	}
}

bool CheckOptionMouseOver(int x, int y, int w, int h)
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	x = (double)*(signed int*)(This + 16) - 4;
	y = (double)*(signed int*)(This + 20) - 4;

	return pCheckMouseOver(x - 70, y, 308, 347);
}

void RenderWindowsOption(int a1) 
{
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	*(signed int*)(This + 16) = 320 - (190 / 2); // Esto dice desde donde empieza las opcion
	x = (double)*(signed int*)(This + 16);
	y = (double)*(signed int*)(This + 20);

	pSetFont(pTextThis(), (int)pFontBigBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen

	gCustomOptionS6.PrintDropBox(x - 70, y, 300, 345, 0, 0);	//Box Game Option
	pDrawText(pTextThis(), x, y + 10, "Game Options", 230, 0, (LPINT)3, 0);
	RenderBitmap(71520, x + 15, y + 30, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0); //BARRA DE ARRIBA

	pDrawText(pTextThis(), x - 150, y + 10, "Resolution", 250, 0, (LPINT)3, 0);
	RenderBitmap(71520, x - 50, y + 30, 50, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0); //BARRA DE ARRIBA NUEVA

//--
	for (int k = 0; k < 7; k++) //AUMENTAR NUMERO SI AUMENTAN OPCIONES
	{
		gCustomOptionS6.JCOption[k].mouseClicked();
	}
	gCustomOptionS6.EventPanelOption();


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (gCustomCommonS6.FontON == 1)
	{
		switch (gCustomCommonS6.FontHeight) {
		case 11:
			if (CheckButtonPressed(x + 97, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 97, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 97, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
			//////////////////////////////////////////////////////
		case 12:
			if (CheckButtonPressed(x + 117, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 117, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 117, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
			//////////////////////////////////////////////////////
		case 13:
			if (CheckButtonPressed(x + 137, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 137, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 137, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
			//////////////////////////////////////////////////////
		case 14:
			if (CheckButtonPressed(x + 157, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 157, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 157, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
			//////////////////////////////////////////////////////
		case 15:
			if (CheckButtonPressed(x + 177, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 177, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 177, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
			//////////////////////////////////////////////////////
		case 16:
			if (CheckButtonPressed(x + 197, y + 284, 18, 12)) {
				RenderBitmap(71521, x + 197, y + 284, 18, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			else {
				RenderBitmap(71521, x + 197, y + 284, 18, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
			}
			break;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	switch (gCustomCommonS6.ChangeResolution) {
	case 0:
		if (CheckButtonPressed(x - 45, y + 40, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 40, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 40, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 1:
		if (CheckButtonPressed(x - 45, y + 58, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 58, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 58, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 2:
		if (CheckButtonPressed(x - 45, y + 78, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 78, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 78, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 3:
		if (CheckButtonPressed(x - 45, y + 98, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 98, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 98, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 4:
		if (CheckButtonPressed(x - 45, y + 118, 40, 12)) {
			RenderBitmap(71521, x - 48, y + 118, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 118, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 5:
		if (CheckButtonPressed(x - 45, y + 138, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 138, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 138, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 6:
		if (CheckButtonPressed(x - 45, y + 158, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 158, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 158, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 7:
		if (CheckButtonPressed(x - 45, y + 178, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 178, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 178, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 8:
		if (CheckButtonPressed(x - 45, y + 198, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 198, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 198, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;
		//////////////////////////////////////////////////////
	case 9:
		if (CheckButtonPressed(x - 45, y + 218, 40, 12)) {
			RenderBitmap(71521, x - 45, y + 218, 40, 12, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		else {
			RenderBitmap(71521, x - 45, y + 218, 40, 12, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
		}
		break;


	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//BOTON CERRAR
	sub_779410((char*)(This + 24), x + 85, y + 320, 60, 22);

	if (CheckButtonPressed(x + 85, y + 320, 60, 22))
	{
		RenderBitmap(71521, x + 85, y + 320, 60, 22, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71521, x + 85, y + 320, 60, 22, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	pSetFont(pTextThis(), (int)pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pDrawText(pTextThis(), x + 85, y + 326, pGetTextLine(pTextLineThis, 1108), 60, 0, (LPINT)3, 0); //-- Closed
}

void RenderOptionText(int a1)
{
	int This; // [sp+74h] [bp-4h]@1
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	char buffer[255]; // ST08_4@1

	This = *(DWORD*)(GetInstance() + 160);

	x = (double)*(signed int*)(This + 16);
	y = (double)*(signed int*)(This + 20);

	pSetFont(pTextThis(), (int)pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	sub_4200F0_Addr(pTextThis(), 0);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	
	pDrawText(pTextThis(), x + 45, y + 40, "Show MiniMap", 0, 0, (LPINT)1, 0); //-- Time Bar
	pDrawText(pTextThis(), x + 45, y + 60, "Show Char Name", 0, 0, (LPINT)1, 0); //-- Show MiniMap
	pDrawText(pTextThis(), x + 145, y + 40, "Show Monster Name", 0, 0, (LPINT)1, 0);
	//TAMAÑO DE FUENTE
	pDrawText(pTextThis(), x + 25, y + 285, "FONT ON", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 103, y + 285, "11", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 123, y + 285, "12", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 143, y + 285, "13", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 163, y + 285, "14", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 183, y + 285, "15", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x + 203, y + 285, "16", 0, 0, (LPINT)1, 0);
	//RESOLUCIONES
	pDrawText(pTextThis(), x - 40, y + 40, "640x480", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 60, "800x600", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 80, "1024x768", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 100, "1280x768", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 120, "1366x768", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 140, "1440x900", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 160, "1600x900", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 180, "1600x1280", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 200, "1680x1050", 0, 0, (LPINT)1, 0);
	pDrawText(pTextThis(), x - 40, y + 220, "1920x1080", 0, 0, (LPINT)1, 0);

	RenderBitmap(71520, x + 15, y + 115, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0); //LINEA ARRIBA DEL VOLUMEN

//-- Sound
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	pDrawText(pTextThis(), x, y + 118, pGetTextLine(pTextLineThis, 389), 230, 0, (LPINT)3, 0); //-- Volumen
//-- Divisor
	RenderBitmap(71520, x + 15, y + 160, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0); //LINEA ABAJO DEL VOLUMEN
//-- Effect Limit
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu); //-- eGold
	pDrawText(pTextThis(), x, y + 165, pGetTextLine(pTextLineThis, 1840), 230, 0, (LPINT)3, 0); //-- Effect Limit
//-- Divisor
	RenderBitmap(71520, x + 15, y + 275, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);	//LINEA DE ABAJO DE TODO
	RenderBitmap(71520, x + 15, y + 310, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);	//LINEA DE ABAJO DE TODO
}

void RenderOptionPanel(int a1)
{
	int This; // [sp+74h] [bp-4h]@1
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1

	This = *(DWORD*)(GetInstance() + 160);

	x = (double)*(signed int*)(This + 16);
	y = (double)*(signed int*)(This + 20);
	//--
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	pDrawButton(31593, x + 27, y + 37, 15, 15, 0.0, (gInterface.MiniMap != 0) ? 0.0 : 15.0); //-- Time Bar

	pDrawButton(31593, x + 27, y + 57, 15, 15, 0.0, (gInterface.CharName != 0) ? 0.0 : 15.0); //-- MiniMap

	pDrawButton(31593, x + 127, y + 37, 15, 15, 0.0, (gInterface.MonsterName != 0) ? 0.0 : 15.0);

	/*int CharName;
	int MonsterName;
	int RankUser;
	int UserTitle;*/
	//-- Volumen
	pDrawButton(71523, x + 27, y + 124, 18, 15, 0, 0);

	pDrawGUI(31596, x + 45, y + 124, 124.0, 16.0);

	if (*(DWORD*)(This + 200) > 0)
	{
		pDrawGUI(31597, x + 45, y + 124, (double)*(signed int*)(This + 200) * 12.40000057220459, 16.0);

		//	*(BYTE *)0xE8C2A8 = *(DWORD *)(This + 200);
	}
	//--
	//int DisableWing;
	//int DisableSkill;
	//int DisableDropZen;
	//int DisableDropItem;
	//int DisablePet;
	//int DisableCharMoob1;
	//int DisableCharMoob2;
	//int DisableObjTerrain;
	//int RemoveSet;
	int* SystemAntiLag[8] = { &gCustomCommonS6.DisableWing, &gCustomCommonS6.DisableSkill, &gCustomCommonS6.DisableDropZen, &gCustomCommonS6.DisableDropItem, &gCustomCommonS6.DisableDropItem, &gCustomCommonS6.DisablePet, &gCustomCommonS6.DisableObjTerrain, &gCustomCommonS6.RemoveSet};

	float JCRenderY = y + 170;
	float JCRenderX = x + 27;

	for (int k = 0; k < 7; k++)
	{
		gCustomOptionS6.JCOption[k].SetLocation(JCRenderX, JCRenderY);
		*(int*)SystemAntiLag[k] = gCustomOptionS6.JCOption[k].SetVisible();

		JCRenderY += 20;

		if (k == 4)
		{
			JCRenderY = y + 170;
			JCRenderX = x + 140;
		}
	}

	pGLSwitch();
	//EnableAlphaTest(0);
}

bool CheckAttackMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	y = (double)*(signed int*)(This + 20);
	x = (double)*(signed int*)(This + 16);

	return pCheckMouseOver(x + 27, y + 37, 15, 15);
}

bool CheckBeepMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	y = (double)*(signed int*)(This + 20);
	x = (double)*(signed int*)(This + 16);

	return pCheckMouseOver(x + 27, y + 57, 15, 15);
}

bool CheckSlideMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD*)(GetInstance() + 160);

	y = (double)*(signed int*)(This + 20);
	x = (double)*(signed int*)(This + 16);

	return pCheckMouseOver(x + 27, y + 77, 15, 15);
}

bool CheckSoundMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD*)(This + 20) + 124;

	return pCheckMouseOver(x, y, w, h);
}

bool CheckEffectMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	/*int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD *)(This + 20);*/

	return false;//pCheckMouseOver( x, y + 181, w, h);
}

void CCustomOptionS6::Init()
{
	SetCompleteHook(0xE9, 0x0054A319, &RemoveShadoW);
	//ventana
	SetCompleteHook(0xE8, 0x008490F5, &CheckOptionMouseOver);
	SetCompleteHook(0xE9, 0x008494B0, &RenderWindowsOption);
	SetCompleteHook(0xE9, 0x00849730, &RenderOptionText);
	SetCompleteHook(0xE9, 0x008499E0, &RenderOptionPanel);
	//principal
	SetCompleteHook(0xE8, 0x00848E5D, &CheckAttackMouseOver);
	SetCompleteHook(0xE8, 0x00848EB2, &CheckBeepMouseOver);
	SetCompleteHook(0xE8, 0x00848F07, &CheckSlideMouseOver);
	SetCompleteHook(0xE8, 0x00848F4B, &CheckSoundMouseOver);
	SetCompleteHook(0xE8, 0x00849087, &CheckEffectMouseOver);
}

void CCustomOptionS6::ChangeSize(int a1, int a2)
{
	int v2; // esi@1
	DWORD v3; // edi@1
	int v4; // eax@2
	int v5; // eax@2
  //  DWORD v5; // edi@1
	DWORD* v6; // esi@2
	int v8; // eax@2
	int v7; // eax@2

	v2 = a2;
	v3 = a1;
	// v4= x;
	// v5= y;
	if (pMUIsLoaded)
	{
		pWinWidth = a1;
		pWinHeight = a2;
		pWinWidthReal = (double)(signed int)a1 / 640.0;
		pWinHeightReal = (double)a2 / 480.0;
		SetWindowPos(pGameWindow, 0, 0, 0, a1, a2 + 30, 0x116u);
		sub_630BC0();
		sub_596AC0(1);
		v4 = sub_482B70();
		*(DWORD*)(v4 + 40) = v3;
		*(DWORD*)(v4 + 44) = v2;
		v5 = sub_407B20();
		*(DWORD*)(v5 + 40) = v3;
		*(DWORD*)(v5 + 44) = v2;
		v6 = (DWORD*)pWindowThis();
		sub_785870(v6[3], *v6, v6[4], 0, 382);
		v7 = GetInstance();
		v8 = sub_861AC0(v7);
		sub_7F0D40(v8);
		sub_7F0C80(v6[78], *v6, 450, 0);
		dword_81C0380 = gCustomCommonS6.FontHeight;// fuente 
		sub_830B70(v6[45], *v6, 1, 1);
		//*(float*)0xD2C848 = 2000.0;  //20000.0;
		//*(float*)0xD2C898 = 1000.0;  //20000.0
		SetFloat((DWORD)(PVOID)(0x00D2C848), 2000.0);
		SetFloat((DWORD)(PVOID)(0x00D2C898), 1000.0);
		gEmojis.AddTextures();
	}
}

void CCustomOptionS6::RegeditData(BYTE data)
{

	HKEY hKey;
	DWORD dwType, dwSize;
	DWORD buffer;
	LONG result;

	RegOpenKeyA(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", &hKey);
	DWORD value = data;
	gCustomCommonS6.ChangeResolution = data;
	RegSetValueExA(hKey, TEXT("Resolution"), 0, REG_DWORD, (const BYTE*)&value, REG_DWORD);
	RegCloseKey(hKey);
	switch (data)
	{
	case 0:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 0", ".\\Settings.ini");
		break;
	case 1:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 1", ".\\Settings.ini");
		break;
	case 2:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 2", ".\\Settings.ini");
		break;
	case 3:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 3", ".\\Settings.ini");
		break;
	case 4:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 4", ".\\Settings.ini");
		break;
	case 5:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 5", ".\\Settings.ini");
		break;
	case 6:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 6", ".\\Settings.ini");
		break;
	case 7:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 7", ".\\Settings.ini");
		break;
	case 8:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 8", ".\\Settings.ini");
		break;
	case 9:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 9", ".\\Settings.ini");
		break;
	}

}
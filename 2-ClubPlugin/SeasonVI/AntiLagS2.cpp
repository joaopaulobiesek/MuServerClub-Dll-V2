#include "pch.h"

CAntiLagS2 gAntiLagS2;

CAntiLagS2::CAntiLagS2() // OK
{
	this->InitCase(0);
}

CAntiLagS2::~CAntiLagS2() // OK
{

}

void CAntiLagS2::InitCase(int Parameter)
{
	this->case3 = Parameter;
	this->case4 = Parameter;
	this->case6 = Parameter;
	this->case7 = Parameter;
	this->case10 = Parameter;
}

void CAntiLagS2::InitKB(int Parameter)
{
	if (gFeatures.antiLag == 0) return; // Desativa AntiLag

	switch (Parameter)
	{
	case 3: //Ativa/Desativa renderização das Asas
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case3 == 0)
			{
				this->case3 = 1;
				SetByte(gOffsetS2.WingActive, 0xC3);
				pDrawMessageS2("AntLag:Wing Active.", 1);
			}
			else
			{
				this->case3 = 0;
				SetByte(gOffsetS2.WingActive, 0x55);
				pDrawMessageS2("AntLag:Wing Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case3);
		WritePrivateProfileStringA("Graphics", "DisableWing", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 4: //Ativa/Desativa efeitos de Skills e Brilhos
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case4 == 0)
			{
				this->case4 = 1;
				SetByte(gOffsetS2.Skill1Active, 0xC3);
				SetByte(gOffsetS2.Skill2Active, 0xC3);
				SetByte(gOffsetS2.Skill3Active, 0xC3);
				pDrawMessageS2("AntLag:Skill Active.", 1);
			}
			else
			{
				this->case4 = 0;
				SetByte(gOffsetS2.Skill1Active, 0x55);
				SetByte(gOffsetS2.Skill2Active, 0x55);
				SetByte(gOffsetS2.Skill3Active, 0x55);
				pDrawMessageS2("AntLag:Skill Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case4);
		WritePrivateProfileStringA("Graphics", "DisableSkill", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 6: //Ativa/Desativa renderização dos itens do chão
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case6 == 0)
			{
				this->case6 = 1;
				SetByte(gOffsetS2.ItemActive, 0x00);
				pDrawMessageS2("AntLag:Item Active.", 1);
			}
			else
			{
				this->case6 = 0;
				SetByte(gOffsetS2.ItemActive, 0x01);
				pDrawMessageS2("AntLag:Item Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case6);
		WritePrivateProfileStringA("Graphics", "DisableDropItem", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 7: //Ativa/Desativa renderização Terrain Obj
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case7 == 0)
			{
				this->case7 = 1;
				SetByte(gOffsetS2.Terrain1Active, 0xC3);
				pDrawMessageS2("AntLag:Terrain Obj Active.", 1);
			}
			else
			{
				this->case7 = 0;
				SetByte(gOffsetS2.Terrain1Active, 0x55);
				pDrawMessageS2("AntLag:Terrain Obj Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case7);
		WritePrivateProfileStringA("Graphics", "DisableObjTerrain", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 10: //Ativa/Desativa todo AntLag
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case10 == 0)
			{
				this->InitCase(1);
				SetByte(gOffsetS2.WingActive, 0xC3);
				SetByte(gOffsetS2.Skill1Active, 0xC3);
				SetByte(gOffsetS2.Skill2Active, 0xC3);
				SetByte(gOffsetS2.Skill3Active, 0xC3);
				SetByte(gOffsetS2.ItemActive, 0x00);
				SetByte(gOffsetS2.Terrain1Active, 0xC3);
				pDrawMessageS2("Active AntLag!", 1);
			}
			else
			{
				this->InitCase(0);
				SetByte(gOffsetS2.WingActive, 0x55);
				SetByte(gOffsetS2.Skill1Active, 0x55);
				SetByte(gOffsetS2.Skill2Active, 0x55);
				SetByte(gOffsetS2.Skill3Active, 0x55);
				SetByte(gOffsetS2.ItemActive, 0x55);
				SetByte(gOffsetS2.Terrain1Active, 0x55);
				pDrawMessageS2("Disabled AntLag!", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case3);
		WritePrivateProfileStringA("Graphics", "DisableWing", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case4);
		WritePrivateProfileStringA("Graphics", "DisableSkill", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case6);
		WritePrivateProfileStringA("Graphics", "DisableDropItem", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case7);
		WritePrivateProfileStringA("Graphics", "DisableObjTerrain", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 11: //Ativa/Desativa efeitos diversos (Skills, Asas)
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case11 == 0)
			{
				this->case11 = 1;
				this->case10 = 1;
				this->InitKB(10);
				this->InitKB(3);
				this->InitKB(4);
			}
			else
			{
				this->case11 = 0;
				this->InitKB(3);
				this->InitKB(4);
			}
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;	
	default:
		break;
	}
}

void CAntiLagS2::ActiveDisabled(int code)
{
	//VM_TIGER_BLACK_START
		//STR_ENCRYPT_START
	if (code == 99)
	{// Puxa Config para o Option Custom
		this->case3 = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini");
		this->case4 = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini");
		this->case6 = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini");
		this->case7 = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini");
	}
	else if (code == 0)
	{
		this->case3 = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini");
		this->case4 = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini");
		this->case6 = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini");
		this->case7 = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini");

		if (this->case3) { this->case3 = 0; this->InitKB(3); }
		if (this->case4) { this->case4 = 0; this->InitKB(4); }
		if (this->case6) { this->case6 = 0; this->InitKB(6); }
		if (this->case7) { this->case7 = 0; this->InitKB(7); }
	}
	else
	{
		if (GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini") != this->case3)
		{
			this->InitKB(3);
		}
		if (GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini") != this->case4)
		{
			this->InitKB(4);
		}
		if (GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini") != this->case6)
		{
			this->InitKB(6);
		}
		if (GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini") != this->case7)
		{
			this->InitKB(7);
		}
	}
	//STR_ENCRYPT_END
		//VM_TIGER_BLACK_END
}
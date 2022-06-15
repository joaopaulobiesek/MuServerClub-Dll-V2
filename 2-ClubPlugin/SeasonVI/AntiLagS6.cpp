#include "pch.h"

CAntiLagS6 gAntiLagS6;

CAntiLagS6::CAntiLagS6() // OK
{
	this->InitCase(0);
}

CAntiLagS6::~CAntiLagS6() // OK
{

}

void CAntiLagS6::InitCase(int Parameter)
{
	this->case3 = Parameter;
	this->case4 = Parameter;
	this->case5 = Parameter;
	this->case6 = Parameter;
	this->case7 = Parameter;
	this->case8 = Parameter;
	this->case9 = Parameter;
	this->case10 = Parameter;
}

void CAntiLagS6::InitKB(int Parameter)
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
				SetByte(gOffsetS6.WingActive, 0xC3);
				pDrawMessageS6("AntLag:Wing Active.", 1);
			}
			else
			{
				this->case3 = 0;
				SetByte(gOffsetS6.WingActive, 0x55);
				pDrawMessageS6("AntLag:Wing Disabled.", 1);
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
				SetByte(gOffsetS6.Skill1Active, 0xC3);
				SetByte(gOffsetS6.Skill2Active, 0xC3);
				MemorySet(gOffsetS6.Skill3Active, ASM::NOP, 0x5);
				pDrawMessageS6("AntLag:Skill Active.", 1);
			}
			else
			{
				this->case4 = 0;
				SetByte(gOffsetS6.Skill1Active, 0x55);
				SetByte(gOffsetS6.Skill2Active, 0x55);
				SetOp((LPVOID)gOffsetS6.Skill3Active, (LPVOID)gOffsetS6.Skill4ActiveHook, ASM::CALL);
				pDrawMessageS6("AntLag:Skill Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case4);
		WritePrivateProfileStringA("Graphics", "DisableSkill", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 5: //Ativa/Desativa renderização das moedas no chão
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case5 == 0)
			{
				this->case5 = 1;
				SetByte(gOffsetS6.ZenActive, 0x00);
				pDrawMessageS6("AntLag:Zen Active.", 1);
			}
			else
			{
				this->case5 = 0;
				SetByte(gOffsetS6.ZenActive, 0x01);
				pDrawMessageS6("AntLag:Zen Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case5);
		WritePrivateProfileStringA("Graphics", "DisableDropZen", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 6: //Ativa/Desativa renderização dos itens do chão
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case6 == 0)
			{
				this->case6 = 1;
				SetByte(gOffsetS6.ItemActive, 0x00);
				pDrawMessageS6("AntLag:Item Active.", 1);
			}
			else
			{
				this->case6 = 0;
				SetByte(gOffsetS6.ItemActive, 0x01);
				pDrawMessageS6("AntLag:Item Disabled.", 1);
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
				SetByte(gOffsetS6.Terrain1Active, 0xC3);
				pDrawMessageS6("AntLag:Terrain Obj Active.", 1);
			}
			else
			{
				this->case7 = 0;
				SetByte(gOffsetS6.Terrain1Active, 0x55);
				pDrawMessageS6("AntLag:Terrain Obj Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case7);
		WritePrivateProfileStringA("Graphics", "DisableObjTerrain", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 8: //Ativa/Desativa Set
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case8 == 0)
			{
				this->case8 = 1;
				SetByte(gOffsetS6.RemoveSetActive, 0xC3);
				pDrawMessageS6("AntLag:Remove Set Active.", 1);
			}
			else
			{
				this->case8 = 0;
				SetByte(gOffsetS6.RemoveSetActive, 0x55);
				pDrawMessageS6("AntLag:Remove Set Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case8);
		WritePrivateProfileStringA("Graphics", "RemoveSet", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 9: //Ativa/Desativa renderização dos pets
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case9 == 0)
			{
				this->case9 = 1;
				SetByte(gOffsetS6.PetActive, 0xC3);
				pDrawMessageS6("AntLag:Pet Active.", 1);
			}
			else
			{
				this->case9 = 0;
				SetByte(gOffsetS6.PetActive, 0x55);
				pDrawMessageS6("AntLag:Pet Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case9);
		WritePrivateProfileStringA("Graphics", "DisablePet", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 10: //Ativa/Desativa todo AntLag
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case10 == 0)
			{
				this->InitCase(1);
				SetByte(gOffsetS6.WingActive, 0xC3);
				SetByte(gOffsetS6.Skill1Active, 0xC3);
				SetByte(gOffsetS6.Skill2Active, 0xC3);
				MemorySet(gOffsetS6.Skill3Active, ASM::NOP, 0x5);
				SetByte(gOffsetS6.ZenActive, 0x00);
				SetByte(gOffsetS6.ItemActive, 0x00);
				SetByte(gOffsetS6.Terrain1Active, 0xC3);
				SetByte(gOffsetS6.RemoveSetActive, 0xC3);
				SetByte(gOffsetS6.PetActive, 0xC3);
				pDrawMessageS6("Active AntLag!", 1);
			}
			else
			{
				this->InitCase(0);
				SetByte(gOffsetS6.WingActive, 0x55);
				SetByte(gOffsetS6.Skill1Active, 0x55);
				SetByte(gOffsetS6.Skill2Active, 0x55);
				SetOp((LPVOID)gOffsetS6.Skill3Active, (LPVOID)gOffsetS6.Skill4ActiveHook, ASM::CALL);
				SetByte(gOffsetS6.ZenActive, 0x01);
				SetByte(gOffsetS6.ItemActive, 0x01);
				SetByte(gOffsetS6.Terrain1Active, 0x55);
				SetByte(gOffsetS6.RemoveSetActive, 0x55);
				SetByte(gOffsetS6.PetActive, 0x55);
				pDrawMessageS6("Disabled AntLag!", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case3);
		WritePrivateProfileStringA("Graphics", "DisableWing", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case4);
		WritePrivateProfileStringA("Graphics", "DisableSkill", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case5);
		WritePrivateProfileStringA("Graphics", "DisableDropZen", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case6);
		WritePrivateProfileStringA("Graphics", "DisableDropItem", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case7);
		WritePrivateProfileStringA("Graphics", "DisableObjTerrain", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case8);
		WritePrivateProfileStringA("Graphics", "RemoveSet", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case9);
		WritePrivateProfileStringA("Graphics", "DisablePet", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case10);
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 11: //Ativa/Desativa efeitos diversos (Skills, Asas, Buffs, Drop de Moedas, Muuns)
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case11 == 0)
			{
				this->case11 = 1;
				this->case10 = 1;
				this->InitKB(10);
				this->InitKB(3);
				this->InitKB(4);
				this->InitKB(5);
				this->InitKB(9);
			}
			else
			{
				this->case11 = 0;
				this->InitKB(3);
				this->InitKB(4);
				this->InitKB(5);
				this->InitKB(9);
			}
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 12:
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			gInterface.MiniMap = (gInterface.MiniMap == 0) ? 1 : 0;
		wsprintf(GraphicsControl, "%d", gInterface.MiniMap);
		WritePrivateProfileStringA("Graphics", "MiniMap", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	default:
		break;
	}
}

void CAntiLagS6::ActiveDisabled(int code)
{
	//VM_TIGER_BLACK_START
		//STR_ENCRYPT_START
	if (code == 99)
	{// Puxa Config para o Option Custom
		this->case3 = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini");
		this->case4 = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini");
		this->case5 = GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./option.ini");
		this->case6 = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini");
		this->case7 = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini");
		this->case8 = GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./option.ini");
		this->case9 = GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./option.ini");
	}
	else if (code == 0)
	{
		this->case3 = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini");
		this->case4 = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini");
		this->case5 = GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./option.ini");
		this->case6 = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini");
		this->case7 = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini");
		this->case8 = GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./option.ini");
		this->case9 = GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./option.ini");

		if (this->case3) { this->case3 = 0; this->InitKB(3); }
		if (this->case4) { this->case4 = 0; this->InitKB(4); }
		if (this->case5) { this->case5 = 0; this->InitKB(5); }
		if (this->case6) { this->case6 = 0; this->InitKB(6); }
		if (this->case7) { this->case7 = 0; this->InitKB(7); }
		if (this->case8) { this->case8 = 0; this->InitKB(8); }
		if (this->case9) { this->case9 = 0; this->InitKB(9); }
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
		if (GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./option.ini") != this->case5)
		{
			this->InitKB(5);
		}
		if (GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini") != this->case6)
		{
			this->InitKB(6);
		}
		if (GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini") != this->case7)
		{
			this->InitKB(7);
		}
		if (GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./option.ini") != this->case8)
		{
			this->InitKB(8);
		}
		if (GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./option.ini") != this->case9)
		{
			this->InitKB(9);
		}
		if (GetPrivateProfileIntA("Graphics", "MiniMap", 0, "./option.ini") != gInterface.MiniMap)
		{
			this->InitKB(12);
		}
	}
	//STR_ENCRYPT_END
		//VM_TIGER_BLACK_END
}
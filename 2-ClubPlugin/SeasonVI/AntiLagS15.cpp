#include "pch.h"

CAntiLagS15 gAntiLagS15;

CAntiLagS15::CAntiLagS15() // OK
{
	this->InitCase(0);
}

CAntiLagS15::~CAntiLagS15() // OK
{

}

void CAntiLagS15::InitCase(int Parameter)
{
	this->case3 = Parameter;
	this->case4 = Parameter;
	this->case5 = Parameter;
	this->case6 = Parameter;
	this->case7 = Parameter;
	this->case8 = Parameter;
	this->case9 = Parameter;
	this->case10 = Parameter;
	this->case11 = Parameter;
	this->case12 = Parameter;
}

void CAntiLagS15::InitKB(int Parameter)
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
				SetByte(gOffsetS15.WingActive, 0xC3);
				pDrawMessageS15("AntLag:Wing Active.", 1);
			}
			else
			{
				this->case3 = 0;
				SetByte(gOffsetS15.WingActive, 0x55);
				pDrawMessageS15("AntLag:Wing Disabled.", 1);
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
				SetByte(gOffsetS15.Skill1Active, 0xC3);
				SetByte(gOffsetS15.Skill2Active, 0xC3);
				SetByte(gOffsetS15.Skill3Active, 0xC3);//Remove Brilho dos Itens
				MemorySet(gOffsetS15.Skill4Active, ASM::NOP, 0x5);
				SetByte(gOffsetS15.Skill5Active, 0xC3);
				pDrawMessageS15("AntLag:Skill Active.", 1);
			}
			else
			{
				this->case4 = 0;
				SetByte(gOffsetS15.Skill1Active, 0x55);
				SetByte(gOffsetS15.Skill2Active, 0x55);
				SetByte(gOffsetS15.Skill3Active, 0x55);//Remove Brilho dos Itens
				SetOp((LPVOID)gOffsetS15.Skill4Active, (LPVOID)gOffsetS15.Skill6ActiveHook, ASM::CALL);
				SetByte(gOffsetS15.Skill5Active, 0x55);//// Esse tava sem não sei o PQ entao se crash remover!
				pDrawMessageS15("AntLag:Skill Disabled.", 1);
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
				SetByte(gOffsetS15.ZenActive, 0x00);
				pDrawMessageS15("AntLag:Zen Active.", 1);
			}
			else
			{
				this->case5 = 0;
				SetByte(gOffsetS15.ZenActive, 0x01);
				pDrawMessageS15("AntLag:Zen Disabled.", 1);
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
				SetByte(gOffsetS15.ItemActive, 0x00);
				pDrawMessageS15("AntLag:Item Active.", 1);
			}
			else
			{
				this->case6 = 0;
				SetByte(gOffsetS15.ItemActive, 0x01);
				pDrawMessageS15("AntLag:Item Disabled.", 1);
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
				SetByte(gOffsetS15.Terrain1Active, 0xC3);
				SetByte(gOffsetS15.Terrain2Active, 0xC3);
				pDrawMessageS15("AntLag:Terrain Obj Active.", 1);
			}
			else
			{
				this->case7 = 0;
				SetByte(gOffsetS15.Terrain1Active, 0x55);
				SetByte(gOffsetS15.Terrain2Active, 0x55);
				pDrawMessageS15("AntLag:Terrain Obj Disabled.", 1);
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
				SetByte(gOffsetS15.RemoveSetActive, 0xC3);
				pDrawMessageS15("AntLag:Remove Set Active.", 1);
			}
			else
			{
				this->case8 = 0;
				SetByte(gOffsetS15.RemoveSetActive, 0x55);
				pDrawMessageS15("AntLag:Remove Set Disabled.", 1);
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
				MemorySet(gOffsetS15.Pet1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Pet3Active, ASM::NOP, 0x5);
				pDrawMessageS15("AntLag:Pet Active.", 1);
			}
			else
			{
				this->case9 = 0;
				SetOp((LPVOID)gOffsetS15.Pet1Active, (LPVOID)gOffsetS15.Pet2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Pet3Active, (LPVOID)gOffsetS15.Pet4ActiveHook, ASM::CALL);
				pDrawMessageS15("AntLag:Pet Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case9);
		WritePrivateProfileStringA("Graphics", "DisablePet", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 10: //Ativa/Desativa renderização de chars e mobs 1
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case10 == 0)
			{
				this->case10 = 1;
				MemorySet(gOffsetS15.Char1Moob1Active, ASM::NOP, 0x5);
				pDrawMessageS15("AntLag:Char-Moob-1 Active", 1);
			}
			else
			{
				this->case10 = 0;
				SetOp((LPVOID)gOffsetS15.Char1Moob1Active, (LPVOID)gOffsetS15.Char1Moob2ActiveHook, ASM::CALL);
				pDrawMessageS15("AntLag:Char-Moob-1 Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case10);
		WritePrivateProfileStringA("Graphics", "DisableCharMoob1", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 11: //Ativa/Desativa renderização de chars e mobs 2
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case11 == 0)
			{
				this->case11 = 1;
				MemorySet(gOffsetS15.Char2Moob3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Char2Moob4Active, ASM::NOP, 0x5);
				pDrawMessageS15("AntLag:Char-Moob-2 Active", 1);
			}
			else
			{
				this->case11 = 0;
				SetOp((LPVOID)gOffsetS15.Char2Moob3Active, (LPVOID)gOffsetS15.Char2Moob5ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Char2Moob4Active, (LPVOID)gOffsetS15.Char2Moob5ActiveHook, ASM::CALL);
				pDrawMessageS15("AntLag:Char-Moob-2 Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case11);
		WritePrivateProfileStringA("Graphics", "DisableCharMoob2", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 12: //Ativa/Desativa todo AntLag
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case12 == 0)
			{
				this->InitCase(1);
				SetByte(gOffsetS15.WingActive, 0xC3);
				SetByte(gOffsetS15.Skill1Active, 0xC3);
				SetByte(gOffsetS15.Skill2Active, 0xC3);
				SetByte(gOffsetS15.Skill3Active, 0xC3);//Remove Brilho dos Itens
				MemorySet(gOffsetS15.Skill4Active, ASM::NOP, 0x5);
				SetByte(gOffsetS15.Skill5Active, 0xC3);
				SetByte(gOffsetS15.ZenActive, 0x00);
				SetByte(gOffsetS15.ItemActive, 0x00);
				SetByte(gOffsetS15.Terrain1Active, 0xC3);
				SetByte(gOffsetS15.Terrain2Active, 0xC3);
				SetByte(gOffsetS15.RemoveSetActive, 0xC3);
				MemorySet(gOffsetS15.Pet1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Pet3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Char1Moob1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Char2Moob3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS15.Char2Moob4Active, ASM::NOP, 0x5);
				pDrawMessageS15("Active AntLag!", 1);
			}
			else
			{
				this->InitCase(0);
				SetByte(gOffsetS15.WingActive, 0x55);
				SetByte(gOffsetS15.Skill1Active, 0x55);
				SetByte(gOffsetS15.Skill2Active, 0x55);
				SetByte(gOffsetS15.Skill3Active, 0x55);//Remove Brilho dos Itens
				SetOp((LPVOID)gOffsetS15.Skill4Active, (LPVOID)gOffsetS15.Skill6ActiveHook, ASM::CALL);
				SetByte(gOffsetS15.Skill5Active, 0x55);//// Esse tava sem não sei o PQ entao se crash remover!
				SetByte(gOffsetS15.ZenActive, 0x01);
				SetByte(gOffsetS15.ItemActive, 0x01);
				SetByte(gOffsetS15.Terrain1Active, 0x55);
				SetByte(gOffsetS15.Terrain2Active, 0x55);
				SetByte(gOffsetS15.RemoveSetActive, 0x55);
				SetOp((LPVOID)gOffsetS15.Pet1Active, (LPVOID)gOffsetS15.Pet2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Pet3Active, (LPVOID)gOffsetS15.Pet4ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Char1Moob1Active, (LPVOID)gOffsetS15.Char1Moob2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Char2Moob3Active, (LPVOID)gOffsetS15.Char2Moob5ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS15.Char2Moob4Active, (LPVOID)gOffsetS15.Char2Moob5ActiveHook, ASM::CALL);
				pDrawMessageS15("Disabled AntLag!", 1);
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
		WritePrivateProfileStringA("Graphics", "DisableCharMoob1", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case11);
		WritePrivateProfileStringA("Graphics", "DisableCharMoob2", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 13: //Ativa/Desativa efeitos diversos (Skills, Asas, Buffs, Drop de Moedas, Muuns)
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case13 == 0)
			{
				this->case13 = 1;
				this->case12 = 1;
				this->InitKB(12);
				this->InitKB(3);
				this->InitKB(4);
				this->InitKB(5);
				this->InitKB(9);
			}
			else
			{
				this->case13 = 0;
				this->InitKB(3);
				this->InitKB(4);
				this->InitKB(5);
				this->InitKB(9);
			}
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	default:
		break;
	}
}

void CAntiLagS15::ActiveDisabled(int code)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		if (code == 0)
		{
			this->case3 = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./option.ini");
			this->case4 = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./option.ini");
			this->case5 = GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./option.ini");
			this->case6 = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./option.ini");
			this->case7 = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./option.ini");
			this->case8 = GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./option.ini");
			this->case9 = GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./option.ini");
			this->case10 = GetPrivateProfileIntA("Graphics", "DisableCharMoob1", 0, "./option.ini");
			this->case11 = GetPrivateProfileIntA("Graphics", "DisableCharMoob2", 0, "./option.ini");

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
			if (GetPrivateProfileIntA("Graphics", "DisableCharMoob1", 0, "./option.ini") != this->case10)
			{
				this->InitKB(10);
			}
			if (GetPrivateProfileIntA("Graphics", "DisableCharMoob2", 0, "./option.ini") != this->case11)
			{
				this->InitKB(11);
			}
		}
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
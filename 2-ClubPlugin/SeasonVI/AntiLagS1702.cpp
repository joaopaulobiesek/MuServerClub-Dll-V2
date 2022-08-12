#include "pch.h"

CAntiLagS1702 gAntiLagS1702;

CAntiLagS1702::CAntiLagS1702() // OK
{
	this->InitCase(0);
}

CAntiLagS1702::~CAntiLagS1702() // OK
{

}

void CAntiLagS1702::InitCase(int Parameter)
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
	this->case14 = Parameter;
	this->case15 = Parameter;
	this->case12 = Parameter;
}

void CAntiLagS1702::InitKB(int Parameter)
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
				SetByte(gOffsetS1702.WingActive, 0xC3);
				pDrawMessageS1702("AntLag:Wing Active.", 1);
			}
			else
			{
				this->case3 = 0;
				SetByte(gOffsetS1702.WingActive, 0x55);
				pDrawMessageS1702("AntLag:Wing Disabled.", 1);
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
				SetByte(gOffsetS1702.Skill1Active, 0xC3);
				SetByte(gOffsetS1702.Skill2Active, 0xC3);
				SetByte(gOffsetS1702.Skill3Active, 0xC3);//Remove Brilho dos Itens
				MemorySet(gOffsetS1702.Skill4Active, ASM::NOP, 0x5);
				SetByte(gOffsetS1702.Skill5Active, 0xC3);
				pDrawMessageS1702("AntLag:Skill Active.", 1);
			}
			else
			{
				this->case4 = 0;
				SetByte(gOffsetS1702.Skill1Active, 0x55);
				SetByte(gOffsetS1702.Skill2Active, 0x55);
				SetByte(gOffsetS1702.Skill3Active, 0x55);//Remove Brilho dos Itens
				SetOp((LPVOID)gOffsetS1702.Skill4Active, (LPVOID)gOffsetS1702.Skill6ActiveHook, ASM::CALL);
				SetByte(gOffsetS1702.Skill5Active, 0x55);//// Esse tava sem não sei o PQ entao se crash remover!
				pDrawMessageS1702("AntLag:Skill Disabled.", 1);
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
				SetByte(gOffsetS1702.ZenActive, 0x00);
				pDrawMessageS1702("AntLag:Zen Active.", 1);
			}
			else
			{
				this->case5 = 0;
				SetByte(gOffsetS1702.ZenActive, 0x01);
				pDrawMessageS1702("AntLag:Zen Disabled.", 1);
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
				SetByte(gOffsetS1702.ItemActive, 0x00);
				pDrawMessageS1702("AntLag:Item Active.", 1);
			}
			else
			{
				this->case6 = 0;
				SetByte(gOffsetS1702.ItemActive, 0x01);
				pDrawMessageS1702("AntLag:Item Disabled.", 1);
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
				SetByte(gOffsetS1702.Terrain1Active, 0xC3);
				SetByte(gOffsetS1702.Terrain2Active, 0xC3);
				SetByte(gOffsetS1702.Terrain3Active, 0xC3);
				SetByte(gOffsetS1702.Terrain4Active, 0xC3);
				pDrawMessageS1702("AntLag:Terrain Obj Active.", 1);
			}
			else
			{
				this->case7 = 0;
				SetByte(gOffsetS1702.Terrain1Active, 0x55);
				SetByte(gOffsetS1702.Terrain2Active, 0x55);
				SetByte(gOffsetS1702.Terrain3Active, 0x55);
				SetByte(gOffsetS1702.Terrain4Active, 0x55);
				pDrawMessageS1702("AntLag:Terrain Obj Disabled.", 1);
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
				SetByte(gOffsetS1702.RemoveSet1Active, 0xC3);
				pDrawMessageS1702("AntLag:Remove Set Active.", 1);
			}
			else
			{
				this->case8 = 0;
				SetByte(gOffsetS1702.RemoveSet1Active, 0x55);
				pDrawMessageS1702("AntLag:Remove Set Disabled.", 1);
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
				MemorySet(gOffsetS1702.Pet1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Pet3Active, ASM::NOP, 0x5);
				pDrawMessageS1702("AntLag:Pet Active.", 1);
			}
			else
			{
				this->case9 = 0;
				SetOp((LPVOID)gOffsetS1702.Pet1Active, (LPVOID)gOffsetS1702.Pet2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Pet3Active, (LPVOID)gOffsetS1702.Pet4ActiveHook, ASM::CALL);
				pDrawMessageS1702("AntLag:Pet Disabled.", 1);
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
				MemorySet(gOffsetS1702.Char1Moob1Active, ASM::NOP, 0x5);
				pDrawMessageS1702("AntLag:Char-Moob-1 Active", 1);
			}
			else
			{
				this->case10 = 0;
				SetOp((LPVOID)gOffsetS1702.Char1Moob1Active, (LPVOID)gOffsetS1702.Char1Moob2ActiveHook, ASM::CALL);
				pDrawMessageS1702("AntLag:Char-Moob-1 Disabled.", 1);
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
				MemorySet(gOffsetS1702.Char2Moob3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Char2Moob4Active, ASM::NOP, 0x5);
				pDrawMessageS1702("AntLag:Char-Moob-2 Active", 1);
			}
			else
			{
				this->case11 = 0;
				SetOp((LPVOID)gOffsetS1702.Char2Moob3Active, (LPVOID)gOffsetS1702.Char2Moob5ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Char2Moob4Active, (LPVOID)gOffsetS1702.Char2Moob5ActiveHook, ASM::CALL);
				pDrawMessageS1702("AntLag:Char-Moob-2 Disabled.", 1);
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
				SetByte(gOffsetS1702.WingActive, 0xC3);
				SetByte(gOffsetS1702.Skill1Active, 0xC3);
				SetByte(gOffsetS1702.Skill2Active, 0xC3);
				SetByte(gOffsetS1702.Skill3Active, 0xC3);//Remove Brilho dos Itens
				MemorySet(gOffsetS1702.Skill4Active, ASM::NOP, 0x5);
				SetByte(gOffsetS1702.Skill5Active, 0xC3);
				SetByte(gOffsetS1702.ZenActive, 0x00);
				SetByte(gOffsetS1702.ItemActive, 0x00);
				SetByte(gOffsetS1702.Terrain1Active, 0xC3);
				SetByte(gOffsetS1702.Terrain2Active, 0xC3);
				SetByte(gOffsetS1702.Terrain3Active, 0xC3);
				SetByte(gOffsetS1702.Terrain4Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet1Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet2Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet3Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet4Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet5Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet6Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet7Active, 0xC3);
				SetByte(gOffsetS1702.RemoveMoob, 0xC3);
				MemorySet(gOffsetS1702.Pet1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Pet3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Char1Moob1Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Char2Moob3Active, ASM::NOP, 0x5);
				MemorySet(gOffsetS1702.Char2Moob4Active, ASM::NOP, 0x5);
				pDrawMessageS1702("Active AntLag!", 1);
			}
			else
			{
				this->InitCase(0);
				SetByte(gOffsetS1702.WingActive, 0x55);
				SetByte(gOffsetS1702.Skill1Active, 0x55);
				SetByte(gOffsetS1702.Skill2Active, 0x55);
				SetByte(gOffsetS1702.Skill3Active, 0x55);//Remove Brilho dos Itens
				SetOp((LPVOID)gOffsetS1702.Skill4Active, (LPVOID)gOffsetS1702.Skill6ActiveHook, ASM::CALL);
				SetByte(gOffsetS1702.Skill5Active, 0x55);//// Esse tava sem não sei o PQ entao se crash remover!
				SetByte(gOffsetS1702.ZenActive, 0x01);
				SetByte(gOffsetS1702.ItemActive, 0x01);
				SetByte(gOffsetS1702.Terrain1Active, 0x55);
				SetByte(gOffsetS1702.Terrain2Active, 0x55);
				SetByte(gOffsetS1702.Terrain3Active, 0x55);
				SetByte(gOffsetS1702.Terrain4Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet1Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet2Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet3Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet4Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet5Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet6Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet7Active, 0x55);
				SetByte(gOffsetS1702.RemoveMoob, 0x55);
				SetOp((LPVOID)gOffsetS1702.Pet1Active, (LPVOID)gOffsetS1702.Pet2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Pet3Active, (LPVOID)gOffsetS1702.Pet4ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Char1Moob1Active, (LPVOID)gOffsetS1702.Char1Moob2ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Char2Moob3Active, (LPVOID)gOffsetS1702.Char2Moob5ActiveHook, ASM::CALL);
				SetOp((LPVOID)gOffsetS1702.Char2Moob4Active, (LPVOID)gOffsetS1702.Char2Moob5ActiveHook, ASM::CALL);
				pDrawMessageS1702("Disabled AntLag!", 1);
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
		wsprintf(GraphicsControl, "%d", this->case14);
		WritePrivateProfileStringA("Graphics", "RemoveSet2", GraphicsControl, ".\\option.ini");
		wsprintf(GraphicsControl, "%d", this->case15);
		WritePrivateProfileStringA("Graphics", "RemoveMob", GraphicsControl, ".\\option.ini");
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
	case 14: //Ativa/Desativa Set 2
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case14 == 0)
			{
				this->case14 = 1;
				SetByte(gOffsetS1702.RemoveSet2Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet3Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet4Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet5Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet6Active, 0xC3);
				SetByte(gOffsetS1702.RemoveSet7Active, 0xC3);
				pDrawMessageS1702("AntLag:Remove Set 2 Active.", 1);
			}
			else
			{
				this->case14 = 0;
				SetByte(gOffsetS1702.RemoveSet2Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet3Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet4Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet5Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet6Active, 0x55);
				SetByte(gOffsetS1702.RemoveSet7Active, 0x55);
				pDrawMessageS1702("AntLag:Remove Set 2 Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case14);
		WritePrivateProfileStringA("Graphics", "RemoveSet2", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	case 15: //Ativa/Desativa Mob
		VM_TIGER_BLACK_START
			STR_ENCRYPT_START
			if (this->case15 == 0)
			{
				this->case15 = 1;
				SetByte(gOffsetS1702.RemoveMoob, 0xC3);
				pDrawMessageS1702("AntLag:Remove Mob Active.", 1);
			}
			else
			{
				this->case15 = 0;
				SetByte(gOffsetS1702.RemoveMoob, 0x55);
				pDrawMessageS1702("AntLag:Remove Mob Disabled.", 1);
			}
		wsprintf(GraphicsControl, "%d", this->case15);
		WritePrivateProfileStringA("Graphics", "RemoveMob", GraphicsControl, ".\\option.ini");
		STR_ENCRYPT_END
			VM_TIGER_BLACK_END
			break;
	default:
		break;
	}
}

void CAntiLagS1702::ActiveDisabled(int code)
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
			this->case14 = GetPrivateProfileIntA("Graphics", "RemoveSet2", 0, "./option.ini");
			this->case15 = GetPrivateProfileIntA("Graphics", "RemoveMob", 0, "./option.ini");

			if (this->case3) { this->case3 = 0; this->InitKB(3); }
			if (this->case4) { this->case4 = 0; this->InitKB(4); }
			if (this->case5) { this->case5 = 0; this->InitKB(5); }
			if (this->case6) { this->case6 = 0; this->InitKB(6); }
			if (this->case7) { this->case7 = 0; this->InitKB(7); }
			if (this->case8) { this->case8 = 0; this->InitKB(8); }
			if (this->case9) { this->case9 = 0; this->InitKB(9); }
			if (this->case14) { this->case14 = 0; this->InitKB(14); }
			if (this->case15) { this->case15 = 0; this->InitKB(15); }
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
			if (GetPrivateProfileIntA("Graphics", "RemoveSet2", 0, "./option.ini") != this->case14)
			{
				this->InitKB(14);
			}
			if (GetPrivateProfileIntA("Graphics", "RemoveMob", 0, "./option.ini") != this->case15)
			{
				this->InitKB(15);
			}
		}
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
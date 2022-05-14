#include "pch.h"

Interface	gInterface;

Interface::Interface() // OK
{
	this->MiniMap = 0;
}

Interface::~Interface() // OK
{

}

void Interface::Load()
{
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);

	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	if (gFeatures.emoji == 1)
	{
		gEmojis.AddTextures();
	}
}

void Interface::LoadImages()
{
	//MiniMap
	pLoadImage("Interface\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\null.tga", 31461, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Lorencia.tga", 31462, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Dungeon.tga", 31463, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Devias.tga", 31464, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Noria.tga", 31465, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Losttower.tga", 31466, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Atlans.tga", 31467, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Tarkan.tga", 31468, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Elbeland.tga", 31469, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Icarus.tga", 31470, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\LandOfTrials.tga", 31471, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Aida.tga", 31472, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Crywolf.tga", 31473, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Kantru.tga", 31474, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Kantru3.tga", 31475, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Barracks.tga", 31476, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Calmness.tga", 31477, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Raklion.tga", 31478, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Vulcanus.tga", 31479, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Kalrutan.tga", 31480, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\Maps\\Kalrutan2.tga", 31481, 0x2601, 0x2900, 1, 0);

	pLoadImage("Interface\\newui_menu01.jpg", 31377, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\newui_menu02.jpg", 31378, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\newui_menu02-03.jpg", 31379, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\newui_menu03.jpg", 31380, 0x2601, 0x2901, 1, 0);
	if (gFeatures.emoji == 1)
	{
		gEmojis.LoadImages();
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick = 0;
	this->Data[MonsterID].OnClick = false;
	this->Data[MonsterID].OnShow = false;
	this->Data[MonsterID].ModelID = ModelID;
	this->Data[MonsterID].Width = Width;
	this->Data[MonsterID].Height = Height;
	this->Data[MonsterID].X = X;
	this->Data[MonsterID].Y = Y;
	this->Data[MonsterID].MaxX = X + Width;
	this->Data[MonsterID].MaxY = Y + Height;
	this->Data[MonsterID].Attribute = 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = X;
		this->Data[ObjectID].Y = Y;
		this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::Work()
{
	gObjUser.Refresh();
	gInterface.DrawMiniMap();
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}

int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}

int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

void Interface::DrawMiniMap()
{
	if (this->MiniMap == 0)
	{
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0;
	// ----
	if (this->MiniMapCheck() || this->CombinedChecks() || CheckMap())
	{
		return;
	}

	// ----
	switch (gObjUser.m_MapNumber)
	{
	case 0:    //Lorencia
	{
		this->DrawGUI(eLORENCIA_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 1:    //Dungeon
	{
		this->DrawGUI(eDUNGEON_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 2:    //Devias
	{
		this->DrawGUI(eDEVIAS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 3:    //Noria
	{
		this->DrawGUI(eNORIA_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 4:    //LostTower
	{
		this->DrawGUI(eLOSTTOWER_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 5:    //Exile (disabled)
	{
		return;
	}
	break;
	// --
	// --
	case 7:    //Atlans
	{
		this->DrawGUI(eATLANS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 8:    //Tarkan
	{
		this->DrawGUI(eTarkan_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 10:    //Icarus
	{
		this->DrawGUI(eICARUS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 31:    //Land of Trials
	{
		this->DrawGUI(eLANDOFTRIALS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 33:    //Aida
	{
		this->DrawGUI(eAIDA_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 34:    //Crywolf Fortress
	{
		this->DrawGUI(eCRYWOLF_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 37:    //Kantru
	{
		this->DrawGUI(eKANTRU_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 38:    //Kantru 3
	{
		this->DrawGUI(eKANTRU3_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 41:    //Barracks
	{
		this->DrawGUI(eBARRACKS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 51:    //Elbeland
	{
		this->DrawGUI(eElbeland_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 56:    //Swamp of Calmness
	{
		this->DrawGUI(eCALMNESS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 57:    //Raklion
	{
		this->DrawGUI(eRAKLION_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 63:    //Vulcanus
	{
		this->DrawGUI(eVULCANUS_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 80:    //Kalrutan
	{
		this->DrawGUI(eKALRUTAN_MAP, StartX, StartY + 30);
	}
	break;
	// --
	case 81:    //Kalrutan 2
	{
		this->DrawGUI(eKALRUTAN2_MAP, StartX, StartY + 30);
	}
	break;

	// --
	default: //Default
	{
		this->DrawGUI(eNULL_MAP, StartX, StartY + 30);
	}
	break;
	}
	// ----
	this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + gObjUser.lpViewPlayer->MapPosX / 2), (float)(294 - 1 + (255 - gObjUser.lpViewPlayer->MapPosY) / 2));
	//}
}

bool Interface::MiniMapCheck()
{
	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(Character) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(GensInfo) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse))
		return true;
	return false;
}

bool Interface::CombinedChecks()/// ???????????????????????????????? retira minimap
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
			&& this->CheckWindow(Warehouse)
			&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
			&& this->CheckWindow(Character)
			&& this->CheckWindow(Store)))
		return true;
	return false;
}

bool Interface::CheckMap()
{
	switch (gObjUser.m_MapNumber)
	{
	case eMapNumber::Lorencia:
		return false;
		break;
	case eMapNumber::Dungeon:
		return false;
		break;
	case eMapNumber::Devias:
		return false;
		break;
	case eMapNumber::Noria:
		return false;
		break;
	case eMapNumber::LostTower:
		return false;
		break;
	case eMapNumber::Atlans:
		return false;
		break;
	case eMapNumber::Tarkan:
		return false;
		break;
	case eMapNumber::Elbeland:
		return false;
		break;
	case eMapNumber::Icarus:
		return false;
		break;
	case eMapNumber::Trials:
		return false;
		break;
	case eMapNumber::Aida:
		return false;
		break;
	case eMapNumber::Crywolf:
		return false;
		break;
	case eMapNumber::Kanturu1:
		return false;
		break;
	case eMapNumber::Kanturu3:
		return false;
		break;
	case eMapNumber::Barracks:
		return false;
		break;
	case eMapNumber::Calmness:
		return false;
		break;
	case eMapNumber::Raklion:
		return false;
		break;
	case eMapNumber::Vulcanus:
		return false;
		break;
	case eMapNumber::Karutan1:
		return false;
		break;
	case eMapNumber::Karutan2:
		return false;
		break;
	default:
		return true;
		break;
	}
}

//Copyright Edit
int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char* Line = strtok(Buff, "\n");

	while (Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}

	return PosY;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if ((gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY))
		return false;

	return true;
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if (this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1)
	{
		this->Data[ObjectID].X = -1;
		this->Data[ObjectID].Y = -1;
		this->Data[ObjectID].MaxX = -1;
		this->Data[ObjectID].MaxY = -1;
	}
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	return pDrawToolTip(X, Y, Buff);
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	//this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow = false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow = false;
	pSetCursorFocus = false;
}
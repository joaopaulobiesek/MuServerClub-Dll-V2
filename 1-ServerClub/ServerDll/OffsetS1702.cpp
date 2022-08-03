#include "pch.h"

COffsetS1702 gOffsetS1702;

COffsetS1702::COffsetS1702() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->IpAddressAddress = 0x01A1FEE0;
	this->ClientVersionAddress = 0x01A20424;
	this->ClientSerialAddress = 0x01A2042C;
	this->AccountAddress = 0x01A4B68C;
	this->CharacterAddress = 0x1A4B684;
	this->HwndAddress = 0x06C18000;
	this->FileProtectAddress1 = 0x016F795F;
	this->FileProtectAddress2 = 0x016F760C;
	this->MAIN_SCREEN_STATE = 0x01A4B6D8;
	this->MAIN_VIEWPORT_STRUCT = 0x088EA7C4;
	this->MAIN_MAP_CODE = 0x01A20A34;
	this->pDrawMessage = 0x014EF0F1;
	this->gCameraPosXC = 0x099098EC;
	this->gCameraPosYC = 0x099098F0;
	this->WingActive = 0x012AFCD6;
	this->Skill1Active = 0x01439B74;
	this->Skill2Active = 0x00816666;
	this->Skill3Active = 0x014DDA79;
	this->Skill4Active = 0x0128310A;
	this->Skill5Active = 0x0151CE1E;
	this->Skill6ActiveHook = 0x015177E5;
	this->ZenActive = 0x015A02BD;
	this->ItemActive = 0x015A07D9;
	this->Pet1Active = 0x01604AB9;
	this->Pet2ActiveHook = 0x0D7DBE2;
	this->Pet3Active = 0x01604ADA;
	this->Pet4ActiveHook = 0x009AA3BA;
	this->Char1Moob1Active = 0x012906C8;
	this->Char1Moob2ActiveHook = 0x01271F0C;
	this->Char2Moob3Active = 0x0159F533;
	this->Char2Moob4Active = 0x0159F56A;
	this->Char2Moob5ActiveHook = 0x0156DE68;
	this->Terrain1Active = 0x015174A7;
	this->Terrain2Active = 0x01519269;
	this->RemoveSetActive = 0x015208A2;
	this->CameraY = 0x0A06D7F0;
	this->CameraZ = 0x017C6208;
	this->CameraX = 0x0A06D7F8;
	this->CameraZoom1 = 0x01A20A58;
	this->CameraZoom2 = 0x01A20A5C;
	this->CameraZoom3 = 0x01A20A60;
	this->CameraZoomByte = 0x0A06DDEC;
	this->CameraArena = 0x015FC7A3;
	this->CameraFuncNull = 0x01603856;
	this->CameraHook = 0x0118C823;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS1702::~COffsetS1702() // OK
{

}

void COffsetS1702::InitOffset()
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.IpAddressAddress = this->IpAddressAddress;
	gOffset.ClientVersionAddress = this->ClientVersionAddress;
	gOffset.ClientSerialAddress = this->ClientSerialAddress;
	gOffset.AccountAddress = this->AccountAddress;
	gOffset.CharacterAddress = this->CharacterAddress;
	gOffset.HwndAddress = this->HwndAddress;
	gOffset.FileProtectAddress1 = this->FileProtectAddress1;
	gOffset.FileProtectAddress2 = this->FileProtectAddress2;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
#include "pch.h"

COffsetS1702 gOffsetS1702;

COffsetS1702::COffsetS1702() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	this->IpAddressAddress = 0x01A4FEE8;
	this->ClientVersionAddress = 0x01A5042C;
	this->ClientSerialAddress = 0x01A50434;
	this->AccountAddress = 0x01A7B74C;
	this->CharacterAddress = 0x01A7B744;
	this->HwndAddress = 0x06C485EC;
	this->FileProtectAddress1 = 0x017234E6;
	this->FileProtectAddress2 = 0x017231FC;
	this->MAIN_SCREEN_STATE = 0x01A7B798;
	this->MAIN_VIEWPORT_STRUCT = 0x0891AD64;
	this->MAIN_MAP_CODE = 0x01A50A28;
	this->pDrawMessage = 0x01518ECC;
	this->gCameraPosXC = 0x099740D8;
	this->gCameraPosYC = 0x099740DC;
	this->WingActive = 0x012CE3F0;
	this->Skill1Active = 0x01460280;
	this->Skill2Active = 0x00816666;
	this->Skill3Active = 0x0150784F;
	this->Skill4Active = 0x012A1A03;
	this->Skill5Active = 0x01546D5A;
	this->Skill6ActiveHook = 0x0154168F;
	this->ZenActive = 0x015CBA1A;
	this->ItemActive = 0x015CBF36;
	this->Pet1Active = 0x016306A5;
	this->Pet2ActiveHook = 0x0D860D3;
	this->Pet3Active = 0x016306C6;
	this->Pet4ActiveHook = 0x09AA42B;
	this->Char1Moob1Active = 0x012AEDA1;
	this->Char1Moob2ActiveHook = 0x01299ED5;
	this->Char2Moob3Active = 0x015CAC61;
	this->Char2Moob4Active = 0x015CAC98;
	this->Char2Moob5ActiveHook = 0x015991FD;
	this->Terrain1Active = 0x0154132F;
	this->Terrain2Active = 0x01543113;
	this->Terrain3Active = 0x01542A0D;
	this->Terrain4Active = 0x015CFD4E;
	this->RemoveSet1Active = 0x0154168F;
	this->RemoveSet2Active = 0x0154631B;
	this->RemoveSet3Active = 0x01546D5A;
	this->RemoveSet4Active = 0x0154923C;
	this->RemoveSet5Active = 0x015D59FD;
	this->RemoveSet6Active = 0x01507488;//Concerta o 2
	this->RemoveSet7Active = 0x01507264;//Este talvez de erro
	this->RemoveMoob = 0x015D643E;
	this->CameraY = 0x0A106AB8;
	this->CameraZ = 0x017F3208;
	this->CameraX = 0x0A106AC0;
	this->CameraZoom1 = 0x01A50A78;
	this->CameraZoom2 = 0x01A50A7C;
	this->CameraZoom3 = 0x01A50A80;
	this->CameraZoomByte = 0x0A107094;
	this->CameraArena = 0x01628382;
	this->CameraFuncNull = 0x0162F442;
	this->CameraHook = 0x011A93C4;
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
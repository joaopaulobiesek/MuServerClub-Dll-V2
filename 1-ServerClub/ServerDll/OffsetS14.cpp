#include "pch.h"

COffsetS14 gOffsetS14;

COffsetS14::COffsetS14() // OK
{
	this->IpAddressAddress = 0x0;
	this->ClientVersionAddress = 0x0;
	this->ClientSerialAddress = 0x0;
	this->AccountAddress = 0x0;
	this->CharacterAddress = 0x0;
	this->HwndAddress = 0x0;
	this->FileProtectAddress1 = 0x0;
	this->FileProtectAddress2 = 0x0;
	this->MAIN_SCREEN_STATE = 0x0;
	this->MAIN_VIEWPORT_STRUCT = 0x0;
	this->MAIN_MAP_CODE = 0x0;
	this->pDrawMessage = 0x0;
	this->gCameraPosXC = 0x0;
	this->gCameraPosYC = 0x0;
	this->WingActive = 0x0;
	this->Skill1Active = 0x0;
	this->Skill2Active = 0x0;
	this->Skill3Active = 0x0;
	this->Skill4Active = 0x0;
	this->Skill5Active = 0x0;
	this->Skill6ActiveHook = 0x0;
	this->ZenActive = 0x0;
	this->ItemActive = 0x0;
	this->Pet1Active = 0x0;
	this->Pet2ActiveHook = 0x0;
	this->Pet3Active = 0x0;
	this->Pet4ActiveHook = 0x0;
	this->Char1Moob1Active = 0x0;
	this->Char1Moob2ActiveHook = 0x0;
	this->Char2Moob3Active = 0x0;
	this->Char2Moob4Active = 0x0;
	this->Char2Moob5ActiveHook = 0x0;
	this->Terrain1Active = 0x0;
	this->Terrain2Active = 0x0;
	this->RemoveSetActive = 0x0;
	this->HitBox1Active = 0x0;
	this->HitBox2Active = 0x0;
	this->HitBox3Active = 0x0;
	this->HitBox4Active = 0x0;
	this->HitBox5Active = 0x0;
	this->CameraY = 0x0;
	this->CameraZ = 0x0;
	this->CameraX = 0x0;
	this->CameraZoom1 = 0x0;
	this->CameraZoom2 = 0x0;
	this->CameraZoom3 = 0x0;
	this->CameraZoomByte = 0x0;
	this->CameraArena = 0x0;
	this->CameraFuncNull = 0x0;
	this->CameraHook = 0x0;
}

COffsetS14::~COffsetS14() // OK
{

}

void COffsetS14::InitOffset()
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
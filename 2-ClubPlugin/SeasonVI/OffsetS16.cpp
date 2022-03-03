#include "pch.h"

COffsetS16 gOffsetS16;

COffsetS16::COffsetS16() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
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
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS16::~COffsetS16() // OK
{

}

void COffsetS16::InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.IpAddressAddress = lpMsg->IpAddressAddress;
	gOffset.ClientVersionAddress = lpMsg->ClientVersionAddress;
	gOffset.ClientSerialAddress = lpMsg->ClientSerialAddress;
	gOffset.AccountAddress = lpMsg->AccountAddress;
	gOffset.CharacterAddress = lpMsg->CharacterAddress;
	gOffset.HwndAddress = lpMsg->HwndAddress;
	gOffset.FileProtectAddress1 = lpMsg->FileProtectAddress1;
	gOffset.FileProtectAddress2 = lpMsg->FileProtectAddress2;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
#include "pch.h"

COffsetS6 gOffsetS6;

COffsetS6::COffsetS6() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = 0x0;
	this->MAIN_VIEWPORT_STRUCT = 0x0;
	this->MAIN_MAP_CODE = 0x0;
	this->pDrawMessage = 0x0;
	this->WingActive = 0x0;
	this->Skill1Active = 0x0;
	this->Skill2Active = 0x0;
	this->Skill3Active = 0x0;
	this->Skill4ActiveHook = 0x0;
	this->ZenActive = 0x0;
	this->ItemActive = 0x0;
	this->PetActive = 0x0;
	this->Terrain1Active = 0x0;
	this->RemoveSetActive = 0x0;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS6::~COffsetS6() // OK
{

}

void COffsetS6::InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.PortNumberAddress = lpMsg->PortNumberAddress;
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

void COffsetS6::RecvOffset(SDHP_REQUEST_OFFSET_S6_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = lpMsg->MAIN_SCREEN_STATE;
	this->MAIN_VIEWPORT_STRUCT = lpMsg->MAIN_VIEWPORT_STRUCT;
	this->MAIN_MAP_CODE = lpMsg->MAIN_MAP_CODE;
	this->pDrawMessage = lpMsg->pDrawMessage;
	this->WingActive = lpMsg->WingActive;
	this->Skill1Active = lpMsg->Skill1Active;
	this->Skill2Active = lpMsg->Skill2Active;
	this->Skill3Active = lpMsg->Skill3Active;
	this->Skill4ActiveHook = lpMsg->Skill4ActiveHook;
	this->ZenActive = lpMsg->ZenActive;
	this->ItemActive = lpMsg->ItemActive;
	this->PetActive = lpMsg->PetActive;
	this->Terrain1Active = lpMsg->Terrain1Active;
	this->RemoveSetActive = lpMsg->RemoveSetActive;

	//if (gFeatures.camera3D == 1) gCamera3dS6.Init();

	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
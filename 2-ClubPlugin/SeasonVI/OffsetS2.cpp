#include "pch.h"

COffsetS2 gOffsetS2;

COffsetS2::COffsetS2() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = 0x0;
	this->MAIN_MAP_CODE = 0x0;
	this->pDrawMessage = 0x0;
	this->WingActive = 0x0;
	this->Skill1Active = 0x0;
	this->Skill2Active = 0x0;
	this->Skill3Active = 0x0;
	this->ItemActive = 0x0;
	this->Terrain1Active = 0x0;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS2::~COffsetS2() // OK
{

}

void COffsetS2::InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg)
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

void COffsetS2::RecvOffset(SDHP_REQUEST_OFFSET_S2_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = lpMsg->MAIN_SCREEN_STATE;
	this->MAIN_MAP_CODE = lpMsg->MAIN_MAP_CODE;
	this->pDrawMessage = lpMsg->pDrawMessage;
	this->WingActive = lpMsg->WingActive;
	this->Skill1Active = lpMsg->Skill1Active;
	this->Skill2Active = lpMsg->Skill2Active;
	this->Skill3Active = lpMsg->Skill3Active;
	this->ItemActive = lpMsg->ItemActive;
	this->Terrain1Active = lpMsg->Terrain1Active;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
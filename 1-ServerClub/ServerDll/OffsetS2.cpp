#include "pch.h"

COffsetS2 gOffsetS2;

COffsetS2::COffsetS2() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	this->IpAddressAddress = 0x006F8E34;
	this->ClientVersionAddress = 0x006F99FC;
	this->ClientSerialAddress = 0x006F9A04;
	this->AccountAddress = 0x05796B64;
	this->CharacterAddress = 0x076C1D90;
	this->HwndAddress = 0x05792778;
	this->FileProtectAddress1 = 0x006CE9D4;
	this->FileProtectAddress2 = 0x006CE80F;
	this->MAIN_SCREEN_STATE = 0x00708760;
	this->MAIN_MAP_CODE = 0x006FB604;
	this->pDrawMessage = 0x0057AC00;
	this->gCameraPosXC = 0x07867638;
	this->gCameraPosYC = 0x0786763C;
	this->WingActive = 0x00527900;
	this->Skill1Active = 0x0056F430;
	this->Skill2Active = 0x00560DA0;
	this->Skill3Active = 0x0056E6E0;
	this->ItemActive = 0x0063BD18;
	this->Terrain1Active = 0x00636C70;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS2::~COffsetS2() // OK
{

}

void COffsetS2::InitOffset()
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
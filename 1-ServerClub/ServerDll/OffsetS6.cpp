#include "pch.h"

COffsetS6 gOffsetS6;

COffsetS6::COffsetS6() // OK
{
	this->IpAddressAddress = 0x00E611B2;
	this->ClientVersionAddress = 0x00E61F68;
	this->ClientSerialAddress = 0x00E61F70;
	this->AccountAddress = 0x08793718;
	this->CharacterAddress = 0x08128AC8;
	this->HwndAddress = 0x00E8C578;
	this->FileProtectAddress1 = 0x009D0040;
	this->FileProtectAddress2 = 0x009CFC26;
	this->MAIN_SCREEN_STATE = 0x00E609E8;
	this->MAIN_VIEWPORT_STRUCT = 0x07BC4F04;
	this->MAIN_MAP_CODE = 0x00E61E18;
	this->pDrawMessage = 0x00597630;
	this->WingActive = 0x00588070;
	this->Skill1Active = 0x00747D60;
	this->Skill2Active = 0x0076EC00;
	this->Skill3Active = 0x0057655B;
	this->Skill4ActiveHook = 0x006097B0;
	this->ZenActive = 0x005F895E;
	this->ItemActive = 0x005F8B5D;
	this->PetActive = 0x00925340;
	this->Terrain1Active = 0x005EDFE0;
	this->RemoveSetActive = 0x0050F390;
}

COffsetS6::~COffsetS6() // OK
{

}

void COffsetS6::InitOffset()
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
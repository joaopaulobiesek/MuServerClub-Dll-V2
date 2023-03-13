#include "pch.h"

COffsetS0 gOffsetS0;

COffsetS0::COffsetS0() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	this->IpAddressAddress = 0x006B6694;
	this->ClientVersionAddress = 0x006B7248;
	this->ClientSerialAddress = 0x006B7250;
	this->AccountAddress = 0x0575490C;
	this->CharacterAddress = 0x0;
	this->HwndAddress = 0x0;//0x05737460; //--> não tenho certeza
	this->FileProtectAddress1 = 0x0068F214;
	this->FileProtectAddress2 = 0x0068F04F;
	this->MAIN_SCREEN_STATE = 0x006C41C0;
	this->MAIN_MAP_CODE = 0x006B8D48;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS0::~COffsetS0() // OK
{

}

void COffsetS0::InitOffset()
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
#include "pch.h"

COffsetS0 gOffsetS0;

COffsetS0::COffsetS0() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = 0x0;
	this->MAIN_MAP_CODE = 0x0;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS0::~COffsetS0() // OK
{

}

void COffsetS0::InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.PortNumberAddress = lpMsg->PortNumberAddress;
		gOffset.IpAddressAddress = lpMsg->IpAddressAddress;
	gOffset.ClientVersionAddress = lpMsg->ClientVersionAddress;
	gOffset.ClientSerialAddress = lpMsg->ClientSerialAddress;
	gOffset.AccountAddress = lpMsg->AccountAddress;
	gOffset.CharacterAddress = lpMsg->CharacterAddress;
	//gOffset.HwndAddress = lpMsg->HwndAddress;
	//gMain.hWnd = *(HWND*)(lpMsg->HwndAddress);
	gOffset.FileProtectAddress1 = lpMsg->FileProtectAddress1;
	gOffset.FileProtectAddress2 = lpMsg->FileProtectAddress2;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void COffsetS0::RecvOffset(SDHP_REQUEST_OFFSET_S0_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = lpMsg->MAIN_SCREEN_STATE;
	this->MAIN_MAP_CODE = lpMsg->MAIN_MAP_CODE;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}
#pragma once

class COffsetS0
{
public:
	COffsetS0();
	virtual ~COffsetS0();
	void InitOffset();
public:
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_MAP_CODE;
};
extern COffsetS0 gOffsetS0;
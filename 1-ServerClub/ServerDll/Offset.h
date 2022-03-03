#pragma once

class COffset
{
public:
	COffset();
	virtual ~COffset();
	void Init(int version);
public:
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
};
extern COffset gOffset;
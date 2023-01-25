#pragma once

class COffsetS0
{
public:
	COffsetS0();
	virtual ~COffsetS0();
	void InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg);
	void RecvOffset(SDHP_REQUEST_OFFSET_S0_RECV* lpMsg);
public:
	DWORD MAIN_SCREEN_STATE;
	DWORD MAIN_MAP_CODE;
};
extern COffsetS0 gOffsetS0;
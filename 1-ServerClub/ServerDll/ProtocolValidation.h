#pragma once

class CProtocolValidation
{
public:
	CProtocolValidation();
	virtual ~CProtocolValidation();
	int ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg, SDHP_CLIENT_INFO_SEND* pMsg, int index);
public:

};
extern CProtocolValidation gProtocolValidation;
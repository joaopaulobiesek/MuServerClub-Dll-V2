#pragma once

class CGetVersion
{
public:
	CGetVersion();
	virtual ~CGetVersion();
	int GetFileVersion(const char* filename, char* ver);
public: 
	/*DWORD dwHandle;
	DWORD sz;
	char* buf;
	VS_FIXEDFILEINFO* pvi;*/
};

extern CGetVersion gGetVersion;
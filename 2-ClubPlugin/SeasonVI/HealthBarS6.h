#pragma once

class CHealthBarS6
{
public:
	CHealthBarS6();
	virtual ~CHealthBarS6();
	void InitHealthBar();
public:
	DWORD HUKADDR;
};
extern CHealthBarS6 gCHealthBarS6;
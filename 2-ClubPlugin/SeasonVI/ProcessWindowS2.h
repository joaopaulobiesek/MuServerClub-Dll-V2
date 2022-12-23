#pragma once
class CProcessWindowS2
{
public:
	CProcessWindowS2();
	virtual ~CProcessWindowS2();
	void SetWindowName(char* GetCharacter, int MapNumber, DWORD Hour, DWORD Minute, DWORD Second);
public:
};

extern CProcessWindowS2 gProcessWindowS2;
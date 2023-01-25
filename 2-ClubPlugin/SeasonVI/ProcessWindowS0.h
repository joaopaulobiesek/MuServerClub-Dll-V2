#pragma once
class CProcessWindowS0
{
public:
	CProcessWindowS0();
	virtual ~CProcessWindowS0();
	void SetWindowName(char* GetCharacter, int MapNumber, DWORD Hour, DWORD Minute, DWORD Second);
public:
};

extern CProcessWindowS0 gProcessWindowS0;
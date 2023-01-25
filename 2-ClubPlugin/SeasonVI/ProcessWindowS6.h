#pragma once
class CProcessWindowS6
{
public:
	CProcessWindowS6();
	virtual ~CProcessWindowS6();
	void SetWindowName(char* GetCharacter, DWORD MapNumber, DWORD PosX, DWORD PosY, DWORD Hour, DWORD Minute, DWORD Second);
public:
};

extern CProcessWindowS6 gProcessWindowS6;
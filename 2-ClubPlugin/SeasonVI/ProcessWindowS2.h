#pragma once
class CProcessWindowS2
{
public:
	CProcessWindowS2();
	virtual ~CProcessWindowS2();
	void SetWindowName(char* WindowName, char* GetCharacter, int MapNumber);
public:
};

extern CProcessWindowS2 gProcessWindowS2;
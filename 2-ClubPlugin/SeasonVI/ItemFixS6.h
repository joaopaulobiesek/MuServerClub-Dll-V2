#pragma once
#define pWinWidth                *(GLsizei*)0x0E61E58
#define pWinHeight                *(GLsizei*)0x0E61E5C
#define sub_6363D0_Addr ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x6363D0)
#define sub_6358A0_Addr ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x6358A0)

void fix_resolution_items_size_1();
int fix_resolution_items_size_2();

class CItemFixS6
{
public:
	CItemFixS6();
	virtual ~CItemFixS6();
	void Init();
public:
private:
};

extern CItemFixS6 gItemFixS6;
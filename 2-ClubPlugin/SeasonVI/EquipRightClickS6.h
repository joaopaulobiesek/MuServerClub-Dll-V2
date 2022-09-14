#pragma once

#define v879340C	*(int*)0x879340C
#define v8793410	*(int*)0x8793410
#define v861110		((void *(*)()) 0x861110)
#define v7DD0F0		((int(__thiscall*)()) 0x007DD0F0)
#define v791070		((int(__thiscall*)(int ButtonNumber)) 0x791070)
#define v50B840		((signed int(__thiscall*)(void *This)) 0x0050B840)
#define v7D9430		((int(__thiscall*)(int This)) 0x7D9430)
#define v7D9410		((int(__thiscall*)(int This)) 0x7D9410)
#define v861260		((int(__thiscall*)(LPVOID This)) 0x861260)
#define v830870		((int(__thiscall*)(int This)) 0x830870)
#define v83C710		((int(__thiscall*)(DWORD *This, int a2)) 0x0083C710)
#define v7DAB80		((int(__thiscall*)(DWORD *This, int a2)) 0x007DAB80)
#define v7DA480		((int(__thiscall*)(DWORD *This, int a2)) 0x007DA480)
#define v830100		((signed int(__thiscall*)(char *This, WORD *a2)) 0x830100)
#define v8359C0		((int(__thiscall*)(int This, WORD *a2, char a3)) 0x8359C0)
#define v7DA6A0     ((int(__thiscall*)(int This, float a2, float a3, float a4)) 0x007DA6A0)
#define v7D94E0		((int(__thiscall*)(int This)) 0x7D94E0)
#define v7D95E0		((int(__thiscall*)(int a1)) 0x7D95E0)
#define v7DC670		((signed int(__thiscall*)(int This, int a2, WORD a3)) 0x7DC670)
#define v5BD850		((char(__cdecl*)(int a1, int a2, int a3)) 0x005BD850)
#define v7DC5D0		((bool(__stdcall*)(int a1, int a2)) 0x007DC5D0)
#define v83C480		((int(__stdcall*)(int a1, int a2)) 0x0083C480)
#define v7DAC10		((int(__stdcall*)(int a1, int a2)) 0x007DAC10)
#define v791050		((int(__cdecl*)(int a1)) 0x00791050)
#define v7DD100		((int(__cdecl*)(int a1, int a2)) 0x007DD100)


#define v833B20		((void(__thiscall*)(void *This, signed int a2)) 0x00833B20)
#define v834320		((int(__thiscall*)(void *This, int a2)) 0x00834320)
#define v64B860		((signed int(__cdecl*)(int a1, int a2)) 0x0064B860)
#define v861260_new		((signed int(__thiscall *)(signed int a1)) 0x861260)
#define v861110_new		((signed int *(__stdcall *)(signed int a1)) 0x861110)

class CEquipRightClickS6
{
public:
	CEquipRightClickS6();
	virtual ~CEquipRightClickS6();
	//static int Equipment(void *This);
	static void Init();
public:
};

extern CEquipRightClickS6 gEquipRightClickS6;
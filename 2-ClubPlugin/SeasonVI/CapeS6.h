#pragma once

#define pDrawViewPort    ((int(__cdecl*)(DWORD ObjectPointer, DWORD ModelPointer, int a3)) 0x56F210)
#define pRefreshViewport    ((void(__cdecl*)(DWORD a1, DWORD a2, int a3)) 0x558630)

#define pRefreshCape1                        ((void(__thiscall*)(ObjectItem * lpItem)) 0x8363D0)
#define pRefreshCape2                        ((void(__thiscall*)(ObjectItem * lpItem)) 0x835E40)

#define pObjOnViewport                ((int(__cdecl*)(int Object))0x5F61C0)
#define sub_57D9A0                    ((DWORD(__cdecl*)(DWORD)) 0x57D9A0)
#define sub_96A4C0                    ((int(__thiscall*)(LPVOID This, signed int a2)) 0x96A4C0)
#define sub_402BC0                    ((LPVOID(*)())0x402BC0)
#define sub_58AA80                    ((DWORD(__cdecl*)(DWORD)) 0x58AA80)
#define sub_558630                    ((void(__cdecl*)(int a1, int a2, int a3)) 0x558630)
#define sub_5012D0                    ((DWORD(__cdecl*)(DWORD)) 0x5012D0)
#define sub_9253D0                    ((int(__thiscall*)(LPVOID This,int a1, short a2)) 0x9253D0)
#define sub_4DB230                    ((LPVOID(*)())0x4DB230)
#define sub_501700                    ((DWORD(__cdecl*)(DWORD, DWORD, DWORD, DWORD, DWORD)) 0x501700)

class CCapeAnimation
{
public:
    CCapeAnimation();
    virtual ~CCapeAnimation();
    void Load();
    static void DrawViewPort(DWORD ObjectPointer, DWORD ModelPointer, DWORD a3);
};

extern CCapeAnimation gCapeAnimation;
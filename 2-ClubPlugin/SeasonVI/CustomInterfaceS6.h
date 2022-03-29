#pragma once

#define pMaxLife		*(WORD*)0x0087935F8
#define pMaxMana		*(WORD*)0x0087935FA
#define sub_4C8640		((char(__thiscall*)(LPVOID This, char a2)) 0x004C8640)
#define sub_791000		((double(__stdcall*)(float a4, float a5, int a6, float a7)) 0x00854FE0)
#define sub_9CEBF0		((signed int(__cdecl*)(double a1)) 0x9CEBF0)

#define sub_849110      ((char(__thiscall*)()) 0x00849110)

#define sub_790B10		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)

#define sub_813DC0		((void(__thiscall*)(int a1, int a5, float a6, float a7, float a8, float a9)) 0x813DC0)

#define sub_861110		((void *(*)()) 0x861110)
#define sub_861200		((int(__thiscall*)(int This)) 0x861200)
#define sub_637A30        ((void(__cdecl*)()) 0x637A30)

class CCustomInterface
{
public:
	CCustomInterface();
	static void DrawInterfaceS2Menu();
	static void DrawInterfaceS2HP();
	static void DrawInterfaceS2SD();
	static void DrawInterfaceS2AG();
	static void DrawInterfaceS2Buttom();
	static void DrawInterfaceS2Exp();
	static void DrawInterfaceS2DisableR();
	static void DrawInterfaceS2SkillClickPosition();
	static void DrawInterfaceS2SkillSwitchClick();
	static void DrawInterfaceS2SkillSwitchBar();
	static void DrawInterfaceS2PotionQ();
	static void DrawInterfaceS2PotionW();
	static void DrawInterfaceS2PotionE();
	static void DrawInterfaceS2Skills(int a1);
	static void DrawInterfaceS2FriendButtom();
	bool EventNewInterface_All(DWORD Event);
	bool EventNewInterface_Party(DWORD Event);
	bool EventNewInterface_Character(DWORD Event);
	bool EventNewInterface_Inventory(DWORD Event);
	void Load();
	DWORD gLevelExperience[401];
	QWORD m_MasterLevelExperienceTable[1001];
private:


};
extern CCustomInterface gCustomInterface;
#pragma once
#include "JCOptionBox.h"

#define sub_630BC0   ((bool(*)()) 0x630BC0)

#define pMUIsLoaded		*(DWORD*)0xE60974
#define pSetFont				((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
//-- Offset Ventanas
#define getWindowConfig_35 ((int(__thiscall*)(int This))0x00861620)

class CCustomOptionS6
{
public:
	CCustomOptionS6();
	virtual ~CCustomOptionS6();
	void Init();
	void EventPanelOption();
	void PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6);
	bool EventPushCursor(int x, int y, int w, int h);
	void RegeditData(BYTE data);
	void ChangeSize(int a1, int a2);
public:
	int DisableObject;
	int DisableShadow;
	int HPMonster;
	int TimerBar;
	int CombatSystem;
	int CharName;
	int MonsterName;
	int RankUser;
	int UserTitle;
	int LagDetectionOption;
public:
	int TimerPush;
	JCOptionBox JCOption[10];
};

extern CCustomOptionS6 gCustomOptionS6;
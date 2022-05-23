#pragma once

class CCustomCommonS6
{
public:
	CCustomCommonS6();
	virtual ~CCustomCommonS6();
	void InitCommon();
public:
	int FontON;
	int FontHeight;
	int ChangeResolution;
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
	int FPS;
	int DisableStaticEffect;
	int DisableDynamicEffect;
	int DisableSkillEffect;
	int DisableGlowEffect;
	int Anisotropy;
	int MaxAnisotropy;
	int Linear;
	int GMT;
	int Fog;
	int MiniMap; 
	int DisableWing;
	int DisableSkill;
	int DisableDropZen;
	int DisableDropItem;
	int DisablePet;
	int DisableCharMoob1;
	int DisableCharMoob2;
	int DisableObjTerrain;
	int RemoveSet;
	int LagDetection;
};

extern CCustomCommonS6 gCustomCommonS6;
/*BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int& EffectID, float StartX, float StartY, float StartWidth, float StartHeight);*/


/*extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableWing;
extern int DisableSkill;
extern int DisableDropZen;
extern int DisableDropItem;
extern int DisablePet;
extern int DisableCharMoob1;
extern int DisableCharMoob2;
extern int DisableObjTerrain;
extern int RemoveSet;
extern int LagDetection;

extern int RGB_RED;
extern int RGB_GREEN;
extern int RGB_BLUE;

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int Fog;
//extern int Tron;
extern int MiniMap;


extern int FontON;
extern int FontHeight;
extern int ChangeResolution;
// Panel system REVISAR SI LO TIENES
extern int DisableObject;
extern int DisableShadow;
extern int HPMonster;
extern int TimerBar;
extern int CombatSystem;
extern int CharName;
extern int MonsterName;
extern int RankUser;
extern int UserTitle;
extern int LagDetectionOption;*/
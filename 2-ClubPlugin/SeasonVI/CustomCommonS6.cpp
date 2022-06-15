#include "pch.h"

CCustomCommonS6 gCustomCommonS6;

CCustomCommonS6::CCustomCommonS6()
{
	this->FontON = 0;
	this->FontHeight = 0;
	this->ChangeResolution = 0;
	this->DisableObject = 0;
	this->DisableShadow = 0;
	this->HPMonster = 0;
	this->TimerBar = 0;
	this->CombatSystem = 0;
	this->CharName = 0;
	this->MonsterName = 0;
	this->RankUser = 0;
	this->UserTitle = 0;
	this->LagDetectionOption = 0;
	this->FPS = 0;
	this->DisableStaticEffect = 0;
	this->DisableDynamicEffect = 0;
	this->DisableSkillEffect = 0;
	this->DisableGlowEffect = 0;
	this->Anisotropy = 0;
	this->MaxAnisotropy = 0;
	this->Linear = 0;
	this->GMT = 0;
	this->Fog = 0;
	this->MiniMap = 0;
	this->DisableWing = 0;
	this->DisableSkill = 0;
	this->DisableDropZen = 0;
	this->DisableDropItem = 0;
	this->DisablePet = 0;
	this->DisableCharMoob1 = 0;
	this->DisableCharMoob2 = 0;
	this->DisableObjTerrain = 0;
	this->RemoveSet = 0;
	this->LagDetection = 0;
}

CCustomCommonS6::~CCustomCommonS6()
{
}

void CCustomCommonS6::InitCommon() // OK
{ 
	FontON = GetPrivateProfileIntA("FontConfig", "FontON", 0, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 11, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 12, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 13, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 14, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 15, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 16, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 17, "./Settings.ini");
	FontHeight = GetPrivateProfileIntA("FontConfig", "FontSize1", 18, "./Settings.ini");
	ChangeResolution = GetPrivateProfileIntA("Interface", "ChangeResolution", 0, "./Settings.ini");

	DisableStaticEffect = GetPrivateProfileIntA("AntiLag", "DisableStaticEffect", 0, "./Settings.ini");
	DisableDynamicEffect = GetPrivateProfileIntA("AntiLag", "DisableDynamicEffect", 0, "./Settings.ini");
	DisableSkillEffect = GetPrivateProfileIntA("AntiLag", "DisableSkillEffect", 0, "./Settings.ini");
	DisableGlowEffect = GetPrivateProfileIntA("AntiLag", "DisableGlowEffect", 0, "./Settings.ini");

	Anisotropy = GetPrivateProfileIntA("Graphics", "Anisotropy", 1, "./Settings.ini");
	MaxAnisotropy = GetPrivateProfileIntA("Graphics", "MaxAnisotropy", 1, "./Settings.ini");
	Linear = GetPrivateProfileIntA("Graphics", "Linear", 1, "./Settings.ini");
	//	Tron					= GetPrivateProfileIntA("Graphics","TronEffects", 0, "./Settings.ini");
	MiniMap = GetPrivateProfileIntA("Graphics", "MiniMap", 1, "./Settings.ini");
	Fog = GetPrivateProfileIntA("Graphics", "Fog", 1, "./Settings.ini");

	GMT = GetPrivateProfileIntA("Other", "ServerTime", 0, "./Settings.ini");

	FPS = GetPrivateProfileIntA("Graphics", "FPS", 0, "./Settings.ini");
	TimerBar = GetPrivateProfileIntA("Setting", "TimerBar", 0, "./Settings.ini");
	MiniMap = GetPrivateProfileIntA("Graphics", "MiniMap", 0, "./Settings.ini");
	CharName = GetPrivateProfileIntA("Graphics", "CharName", 0, "./Settings.ini");
	MonsterName = GetPrivateProfileIntA("Graphics", "MonsterName", 0, "./Settings.ini");
	RankUser = GetPrivateProfileIntA("Graphics", "RankUser", 0, "./Settings.ini");
	UserTitle = GetPrivateProfileIntA("Graphics", "UserTitle", 0, "./Settings.ini");
	CombatSystem = GetPrivateProfileIntA("Graphics", "CombatSystem", 0, "./Settings.ini");
	LagDetection = GetPrivateProfileIntA("Graphics", "LagDetection", 0, "./Settings.ini");
	LagDetectionOption = GetPrivateProfileIntA("Graphics", "LagDetection", 0, "./Settings.ini");

	DisableWing = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./Config.ini");
	DisableSkill = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./Config.ini");
	DisableDropZen = GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./Config.ini");
	DisableDropItem = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./Config.ini");
	DisablePet = GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./Config.ini");
	DisableCharMoob1 = GetPrivateProfileIntA("Graphics", "DisableCharMoob1", 0, "./Config.ini");
	DisableCharMoob2 = GetPrivateProfileIntA("Graphics", "DisableCharMoob2", 0, "./Config.ini");
	DisableObjTerrain = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./Config.ini");
	RemoveSet = GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./Config.ini");
}
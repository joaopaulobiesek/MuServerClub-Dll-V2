#pragma once

struct JCRECT
{
	float x;
	float y;
	float w;
	float h;
};


enum ActionList
{
	Effect_DisableWing = 1,
	Effect_DisableSkill = 2,
	Effect_DisableDropZen = 3,
	Effect_DisableDropItem = 4,
	Effect_DisablePet = 5,
	Effect_DisableCharMoob1 = 6,
	Effect_DisableCharMoob2 = 7,
	Effect_DisableObjTerrain = 8,
	Effect_RemoveSet = 9,
	Effect_LagDetection = 10,
	NONE = 11,
	DEFAULT = 12,
};
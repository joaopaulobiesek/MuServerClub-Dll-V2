#include "pch.h"

CCustomModelEffect gCustomModelEffect;

CCustomModelEffect::CCustomModelEffect() // OK
{
	this->m_CustomModelEffectInfo.clear();
}

CCustomModelEffect::~CCustomModelEffect() // OK
{

}

void CCustomModelEffect::Load(CUSTOM_MODEL_EFFECT_INFO* info) // OK
{
	int index;

	for (int n = 0; n < MAX_MODEL_EFFECT; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_MODEL_EFFECT)
		{
			return;
		}

		this->m_CustomModelEffectInfo.insert(std::pair<int, CUSTOM_MODEL_EFFECT_INFO>(info[n].Index, info[n]));
	}
}

bool CCustomModelEffect::ModelComplete(short a1, BYTE a2, BYTE a3)
{
	std::map<int, CUSTOM_MODEL_EFFECT_INFO>::iterator it = this->m_CustomModelEffectInfo.find(a1);

	for (std::map<int, CUSTOM_MODEL_EFFECT_INFO>::iterator it = this->m_CustomModelEffectInfo.begin(); it != this->m_CustomModelEffectInfo.end(); it++)
	{
		if (a1 == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if (a2 >= it->second.MinLevel && a2 <= it->second.MaxLevel && a3 >= it->second.MinExcellent)
			{
				return true;
			}
		}
	}

	return false;
}

void CCustomModelEffect::ModelRenderEffect(int EffectType, int EffectCode, DWORD* lBone, int lBone2, float* Color, int EffectMode, float Scale)
{
	if (EffectType == 1)
	{
		pPlayDynamicEffect(EffectCode, lBone, lBone2, Color, EffectMode, Scale, 0); // 3}
	}
	else if (EffectType == 2)
	{
		pSkillEffect(EffectCode, (int)lBone, lBone2, Color, EffectMode, 0, 0, 0, 0, 0, 0.0, -1);
	}
	else
	{
		pPlayStaticEffect(EffectCode, lBone, Scale, Color, lBone2, 0, 0);
	}
}

MU3Float lBone[MAX_MODEL_EFFECT];
MU3Float lBone2[MAX_MODEL_EFFECT];

void CCustomModelEffect::ModelEffectRender(DWORD ObjectPointer, DWORD ObjectModel, DWORD a3)
{
	lpViewObj Object = &*(ObjectPreview*)(ObjectPointer);

	vec3_t Color;
	vec3_t ColorRandom;

	Vector(1.0, 1.0, 1.0, Color);

	int Iterator = 0;

	for (std::map<int, CUSTOM_MODEL_EFFECT_INFO>::iterator it = gCustomModelEffect.m_CustomModelEffectInfo.begin(); it != gCustomModelEffect.m_CustomModelEffectInfo.end(); it++)
	{

		lBone[Iterator].X = *(float*)(ObjectModel + 252);
		lBone[Iterator].Y = *(float*)(ObjectModel + 256);
		lBone[Iterator].Z = *(float*)(ObjectModel + 260);
		lBone2[Iterator].X = *(float*)(ObjectModel + 264);
		lBone2[Iterator].Y = *(float*)(ObjectModel + 268);
		lBone2[Iterator].Z = *(float*)(ObjectModel + 272);

		Vector(it->second.Color[0], it->second.Color[1], it->second.Color[2], Color);

		if (Object->HelmSlot == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if (gCustomModelEffect.ModelComplete(Object->HelmSlot, Object->HelmLevel, Object->HelmExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(150);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(150);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		else if (Object->ArmorSlot == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if (gCustomModelEffect.ModelComplete(Object->ArmorSlot, Object->ArmorLevel, Object->ArmorExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(120);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(120);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		else if (Object->PantsSlot == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if (gCustomModelEffect.ModelComplete(Object->PantsSlot, Object->PantsLevel, Object->PantsExcellent))
			{
				lBone[Iterator].Z = lBone[Iterator].Z + (float)(60);
				lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(60);

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		else if (Object->BootsSlot == ITEM2(it->second.ItemType, it->second.ItemIndex))
		{
			if (gCustomModelEffect.ModelComplete(Object->BootsSlot, Object->BootsLevel, Object->BootsExcellent))
			{
				if (Object->InSafeZone)
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(20);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(20);

				}
				else if (Object->PetSlot == ITEM2(13, 37))
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(210);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(210);
				}
				else if (Object->WingsSlot >= 1)
				{
					lBone[Iterator].Z = lBone[Iterator].Z + (float)(180);
					lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(180);
				}

				gCustomModelEffect.ModelRenderEffect(it->second.EffectIndex, it->second.EffectCode, (DWORD*)&lBone[Iterator], (int)&lBone2[Iterator], Color, it->second.EffectType, it->second.EffectScale);
			}
		}
		Iterator++;
	}

	Iterator = 0;
}

void CCustomModelEffect::RenderMonsterEffectMesh(int a1, int a2, int a3)
{
	LPVOID v397; // [sp+8E4h] [bp-4Ch]@2
	float v526; // [sp+870h] [bp-C0h]@125
	int v531; // [sp+884h] [bp-ACh]@125
	int v554; // [sp+8E4h] [bp-4Ch]@2
	float v13; // STE4_4@60
	float v14; // STE0_4@60
	float v15; // STDC_4@60
	float v16; // STD8_4@60
	float v95; // [sp+1E0h] [bp-44h]@38

	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;

	v397 = pGetModel(pModelThis(), *(DWORD*)(a2 + 48));
	v554 = (int)v397;

	if (v397)
	{
		//-- HelMain
		/*if ( *(WORD *)(a1 + 132) == 904 )
		{
			v526 = *(float *)(a2 + 96) * 0.800000023841858;
			Vector((double)((signed int)pRenderRand() % 8) / 10.0 + 0.6000000238418579, 0.0, 0.0, Color);
			Vector( 0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			//-- Effect Statico
			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 0.30000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 0.30000001, Color, a2, 0.0, 0);
			}
			//--
			Vector((double)((signed int)pRenderRand() % 8) / 10.0 + 0.6000000238418579, 0.0, 0.0, Color);

			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 1.0, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 1.0, Color, a2, 0.0, 0);
			}
			Vector(-10.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			//-- Effect Dinamico
			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				CreateParticle2(32283, Bone, a2 + 254, Color, 6, 2.0999999, 0);
			}
			Vector(15.0, 10.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				CreateParticle2(32283, Bone, a2 + 254, Color, 6, 2.0999999, 0);
			}
		}*/
		//-- Kundun
		if (*(WORD*)(a1 + 132) == 905)
		{
			v531 = GetBoneTransform(a2, 8);
			if (v531)
			{
				Vector(1.0, 0.0, 0.0, Color);
				Vector(0, 0, 0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32054, Bone, 0.40000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 9);
			if (v531)
			{
				Vector(1.0, 0.0, 0.0, Color);
				Vector(0, 0, 0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32054, Bone, 0.40000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 100);

			if (v531)
			{
				Vector(1.0, 1.0, 1.0, Color);
				Vector(0, 0, 0, WorldPos);
				TransformPosition(v554, v531, WorldPos, Bone, 1);

				v95 = 1.0f;

				if (*(WORD*)(a2 + 18) == 5)
				{
					if (*(float*)(a2 + 140) <= 10.0 || (signed int)*(WORD*)(a2 + 44) <= 10)
					{
						if (*(float*)(a2 + 140) <= 4.0)
							*(WORD*)(a2 + 44) = 10;
						else
							++* (WORD*)(a2 + 44);
					}
					else
					{
						--* (WORD*)(a2 + 44);
					}
					v95 = (double)*(WORD*)(a2 + 44) * 0.1500000059604645;

					if (*(float*)(a2 + 140) <= 4.0 || *(float*)(a2 + 140) >= 6.0)
					{
						if (*(float*)(a2 + 140) <= 8.0 || *(float*)(a2 + 140) >= 10.0)
						{
							*(WORD*)(a2 + 26) = 0;
						}
						else
						{
							if (*(float*)(a2 + 140) >= 9.0)
							{
								if ((signed int)*(WORD*)(a2 + 26) > 3)
									*(WORD*)(a2 + 26) -= 3;
							}
							else
							{
								*(WORD*)(a2 + 26) += 3;
							}
							v95 = (double)*(WORD*)(a2 + 26) * 0.1500000059604645 + v95;
						}
					}
					else
					{
						if (*(float*)(a2 + 140) >= 5.0)
						{
							if ((signed int)*(WORD*)(a2 + 26) > 3)
								*(WORD*)(a2 + 26) -= 3;
						}
						else
						{
							*(WORD*)(a2 + 26) += 3;
						}
						v95 = (double)*(WORD*)(a2 + 26) * 0.1500000059604645 + v95;
					}
				}
				v13 = sinf(*(float*)0x5EF5A1C * 0.001000000047497451);
				v14 = v13 * 0.300000011920929 + 1.200000047683716;
				pPlayStaticEffect1(32229, Bone, v14, Color, a2, 0.0, 0);
				v15 = sinf(*(float*)0x5EF5A1C * 0.001000000047497451);
				v16 = (v15 * 0.300000011920929 + 1.200000047683716) * v95;
				pPlayStaticEffect1(32231, Bone, v16, Color, a2, 0.0, 0);
			}
		}
		else
		{
			for (std::vector<xMonsterEffect>::iterator it = JCEffectMonster.m_MonsterEffect.begin(); it != JCEffectMonster.m_MonsterEffect.end(); it++)
			{
				if (it->IndexMonster == *(WORD*)(a1 + 132))
				{
					v531 = GetBoneTransform(a2, it->EfectValue);

					if (v531)
					{
						Vector(it->Color[0], it->Color[1], it->Color[2], Color);
						Vector(it->Join[1], it->Join[2], it->Join[0], WorldPos);//<<Posicion a partir del Joint

						if (it->TypeEffect == JCEffect_Dinamic)
						{
							TransformPosition(v554, v531, WorldPos, Bone, 1);
							CreateParticle2(it->IDEffect, Bone, a2 + 254, Color, 6, it->Scale, 0);
						}
						else if (it->TypeEffect == JCEffect_Static)
						{
							TransformPosition(v554, v531, WorldPos, Bone, 1);
							pPlayStaticEffect1(it->IDEffect, Bone, it->Scale, Color, a2, 0.0, 0);
						}
					}
				}
			}
		}
	}
}

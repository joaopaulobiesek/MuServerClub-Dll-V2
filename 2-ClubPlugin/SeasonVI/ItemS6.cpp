#include "pch.h"

//-------------------------------------------------------------------------ITEM SMOKE----------------------------------------
void InitItem() // OK
{

	SetCompleteHook(0xE9, 0x0057AD82, &SetItemEffect);

	SetCompleteHook(0xE9, 0x0057ADC8, &SetColorEffect);
}


DWORD pItemType = 0;
DWORD Item = 0;

__declspec(naked) void SetItemEffect()
{
	__asm
	{
		Mov pItemType, Eax
	}

	Item = gSmokeEffect.GetItemID(pItemType);

	if (pItemType == GET_ITEM_MODEL(11, 43))
	{
		__asm
		{
			Mov Esi, HDK_ITEM_EFFECT_ALLOW
			JMP Esi
		}
	}
	else if (Item != -1)
	{
		__asm
		{
			Mov Esi, HDK_ITEM_EFFECT_ALLOW
			JMP Esi
		}
	}

	__asm
	{
		Mov Esi, HDK_ITEM_EFFECT_NOT_ALLOW
		JMP Esi
	}
}

float RedColor = 255.0;
float GreenColor = 255.0;
float BlueColor = 255.0;

__declspec(naked) void SetColorEffect()
{
	__asm
	{
		Mov pItemType, Edx
	}

	//g_Console.AddMessage(3,"hz = %d",*(DWORD*)0x7BD0458);

	Item = gSmokeEffect.GetItemID(pItemType);

	RedColor = gSmokeEffect.GetRedColor(pItemType);
	GreenColor = gSmokeEffect.GetGreenColor(pItemType);
	BlueColor = gSmokeEffect.GetBlueColor(pItemType);

	if (pItemType == GET_ITEM_MODEL(11, 29))
	{
		__asm
		{
			MOV EAX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [0xD281AC]
			FSTP DWORD PTR DS : [EAX + 0x9C]
			MOV ECX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [0xD23784]
			FSTP DWORD PTR DS : [ECX + 0xA0]
			MOV EDX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [0xD27CA4]
			FSTP DWORD PTR DS : [EDX + 0xA4]
		}
	}
	else if (pItemType == Item)
	{
		__asm
		{
			MOV EAX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [RedColor]
			FSTP DWORD PTR DS : [EAX + 0x9C]
			MOV ECX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [GreenColor]
			FSTP DWORD PTR DS : [ECX + 0xA0]
			MOV EDX, DWORD PTR SS : [EBP + 0xC]
			FLD DWORD PTR DS : [BlueColor]
			FSTP DWORD PTR DS : [EDX + 0xA4]
		}
	}

	__asm
	{
		Mov Esi, HDK_NEXT_ITEM_COLOR
		JMP Esi
	}
}


void PreviewCharSet(int ObjectIndex, BYTE* CharSet, lpViewObj Object, int Mode)
{
	pPreviewCharSet(ObjectIndex, CharSet, Object, Mode);

	lpViewObj lpObj;

	if (Object == 0)
	{
		lpObj = &*(lpViewObj)pGetPreviewStruct(pPreviewThis(), ObjectIndex);
	}
	else
	{
		lpObj = Object;
	}

	BYTE CustomWings = CharSet[16] >> 2;

	if (CustomWings > 0)
	{
		lpObj->WingsSlot = ITEM2(12, 200) + (CustomWings - 1);
	}
}

bool IsCustomWings(WORD ItemID, bool Preview)
{

	if (Preview)
	{
		ItemID -= ITEM_INTER;
	}

	if (ItemID >= ITEM(12, 180) && ItemID <= ITEM(12, 231))
	{
		return true;
	}

	return false;
}
bool IsCustomItem(WORD ItemID, bool Preview)
{

	if (Preview)
	{
		ItemID -= ITEM_INTER;
	}

	if (ItemID >= ITEM(0, 1) && ItemID <= ITEM(11, 200))
	{
		return true;
	}

	return false;
}


//-------------------------------------------------------------------------ITEM SMOKE----------------------------------------

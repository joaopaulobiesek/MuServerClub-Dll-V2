#pragma once

#define MAX_ITEM_SECTION 16
#define MAX_ITEM_TYPE 512
#define MAX_ITEM (MAX_ITEM_SECTION*MAX_ITEM_TYPE)
#define ITEM_BASE_MODEL 1171

#define GET_ITEM(x,y) (((x)*MAX_ITEM_TYPE)+(y))
#define GET_ITEM_MODEL(x,y) ((((x)*MAX_ITEM_TYPE)+(y))+ITEM_BASE_MODEL)

void PreviewCharSet(int ObjectIndex, BYTE* CharSet, lpViewObj Object, int Mode);
void InitItem();
bool IsCustomWings(WORD ItemID, bool Preview);
bool IsCustomItem(WORD ItemID, bool Preview);
void SetItemEffect();
void SetColorEffect();
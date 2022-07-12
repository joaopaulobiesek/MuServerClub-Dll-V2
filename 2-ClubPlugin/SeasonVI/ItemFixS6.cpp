#include "pch.h"

CItemFixS6 gItemFixS6;

CItemFixS6::CItemFixS6() // OK
{
}

CItemFixS6::~CItemFixS6() // OK
{
}

//Function cpp
void fix_resolution_items_size_1()
{
    return sub_6363D0_Addr(0, 0, pWinWidth, pWinHeight);
}

int fix_resolution_items_size_2()
{
    float v2 = (float)pWinWidth / (float)pWinHeight;
    return sub_6358A0_Addr(1.0, v2, 20.0, 2000.0);
}

void CItemFixS6::Init() // OK
{
    SetCompleteHook(0xE8, 0x00772960, &fix_resolution_items_size_1);
    SetCompleteHook(0xE8, 0x007729B3, &fix_resolution_items_size_2);
}
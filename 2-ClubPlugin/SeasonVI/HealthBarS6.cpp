#include "pch.h"

CHealthBarS6 gCHealthBarS6;

CHealthBarS6::CHealthBarS6() // OK
{
}

CHealthBarS6::~CHealthBarS6() // OK
{

}

void MainDllAdd()
{
    ((void(*)())gCHealthBarS6.HUKADDR)();

    gRankUserS6.DrawInfo();
}

void CHealthBarS6::InitHealthBar()
{
    this->HUKADDR = *(DWORD*)(0x005B96E9) + 0x005B96ED;

    SetCompleteHook(0xE8, 0x005B96E8, &MainDllAdd);
}
#include "pch.h"


CCustomInterface gCustomInterface;

CCustomInterface::CCustomInterface()
{

}

void CCustomInterface::DrawInterfaceS2Buttom()
{

}

void CCustomInterface::DrawInterfaceS2Menu()
{
	pDrawImage(31377, 0, 428.0, 256.0, 50.0, 0, 0, 1.0, 0.75, 1, 1, 0);
	pDrawImage(31378, 256.0, 428.0, 128.0, 50.0, 0, 0, 1.0, 0.75, 1, 1, 0);
	//pDrawImage(31379, 222.0, 428.0, 256.0, 50.0, 0, 0, 1.0, 0.75, 1, 1, 0);// barra do 6 ao 0
	pDrawImage(31380, 384.0, 428.0, 256.0, 50.0, 0, 0, 1.0, 0.75, 1, 1, 0);
	gInterface.Work();
}



void CCustomInterface::Load()
{
	SetCompleteHook(0xE8, 0x0080F7FE, &this->DrawInterfaceS2Menu);
}
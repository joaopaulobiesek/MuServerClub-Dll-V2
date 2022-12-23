#include "pch.h"

CSwitchKBS2 gSwitchKBS2;

CSwitchKBS2::CSwitchKBS2() // OK
{
}

CSwitchKBS2::~CSwitchKBS2() // OK
{
}

void CSwitchKBS2::Init(int config)
{
	switch (config)
	{
	case 1: //F6
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 2: //F7
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 3: //F8
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 4: //F9
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 5: //F10
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 6: //F11
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 7: //SHIFT + F6
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 8: //SHIFT + F7
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 9: //SHIFT + F8
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 10: //SHIFT + F9
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 11: //SHIFT + F10
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 12: //SHIFT + F11
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 13: //CTRL + F6
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 14: //CTRL + F7
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 15: //CTRL + F8
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 16: //CTRL + F9
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 17: //CTRL + F10
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 18: //CTRL + F11
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 19: //CTRL + SHIFT + F6
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 20: //CTRL + SHIFT + F7
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 21: //CTRL + SHIFT + F8
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 22: //CTRL + SHIFT + F9
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 23: //CTRL + SHIFT + F10
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 24: //CTRL + SHIFT + F11
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 25: //PageUp
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 26: //PageDown 
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 27: //SHIFT + 0
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 28: //SHIFT + 1
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 29: //SHIFT + 2
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 30: //SHIFT + 3
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 31: //SHIFT + 4
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 32: //SHIFT + 5
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 33: //SHIFT + 6
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 34: //SHIFT + 7
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 35: //SHIFT + 8
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	case 36: //SHIFT + 9
		if (gHookKBS2.Func3 == config) { gAntiLagS2.InitKB(3); }
		if (gHookKBS2.Func4 == config) { gAntiLagS2.InitKB(4); }
		if (gHookKBS2.Func6 == config) { gAntiLagS2.InitKB(6); }
		if (gHookKBS2.Func7 == config) { gAntiLagS2.InitKB(7); }
		if (gHookKBS2.Func10 == config) { gAntiLagS2.InitKB(10); }
		if (gHookKBS2.Func11 == config) { gAntiLagS2.InitKB(11); }
		break;
	}
}
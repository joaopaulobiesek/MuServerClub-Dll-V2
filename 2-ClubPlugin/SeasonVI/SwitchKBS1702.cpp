#include "pch.h"

CSwitchKBS1702 gSwitchKBS1702;

CSwitchKBS1702::CSwitchKBS1702() // OK
{
}

CSwitchKBS1702::~CSwitchKBS1702() // OK
{
}

void CSwitchKBS1702::Init(int config)
{
	switch (config)
	{
	case 1: //F6
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 2: //F7
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 3: //F8
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 4: //F9
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 5: //F10
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 6: //F11
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 7: //SHIFT + F6
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 8: //SHIFT + F7
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 9: //SHIFT + F8
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 10: //SHIFT + F9
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 11: //SHIFT + F10
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 12: //SHIFT + F11
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 13: //CTRL + F6
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 14: //CTRL + F7
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 15: //CTRL + F8
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 16: //CTRL + F9
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 17: //CTRL + F10
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 18: //CTRL + F11
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 19: //CTRL + SHIFT + F6
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 20: //CTRL + SHIFT + F7
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 21: //CTRL + SHIFT + F8
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 22: //CTRL + SHIFT + F9
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 23: //CTRL + SHIFT + F10
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 24: //CTRL + SHIFT + F11
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 25: //PageUp
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 26: //PageDown 
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 27: //SHIFT + 0
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 28: //SHIFT + 1
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 29: //SHIFT + 2
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 30: //SHIFT + 3
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 31: //SHIFT + 4
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 32: //SHIFT + 5
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 33: //SHIFT + 6
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 34: //SHIFT + 7
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 35: //SHIFT + 8
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	case 36: //SHIFT + 9
		if (gHookKBS1702.Func1 == config) { gCamera3dS1702.InitKB(1); }
		if (gHookKBS1702.Func2 == config) { gCamera3dS1702.InitKB(2); }
		if (gHookKBS1702.Func3 == config) { gAntiLagS1702.InitKB(3); }
		if (gHookKBS1702.Func4 == config) { gAntiLagS1702.InitKB(4); }
		if (gHookKBS1702.Func5 == config) { gAntiLagS1702.InitKB(5); }
		if (gHookKBS1702.Func6 == config) { gAntiLagS1702.InitKB(6); }
		if (gHookKBS1702.Func7 == config) { gAntiLagS1702.InitKB(7); }
		if (gHookKBS1702.Func8 == config) { gAntiLagS1702.InitKB(8); }
		if (gHookKBS1702.Func9 == config) { gAntiLagS1702.InitKB(9); }
		if (gHookKBS1702.Func10 == config) { gAntiLagS1702.InitKB(10); }
		if (gHookKBS1702.Func11 == config) { gAntiLagS1702.InitKB(11); }
		if (gHookKBS1702.Func12 == config) { gAntiLagS1702.InitKB(12); }
		if (gHookKBS1702.Func13 == config) { gAntiLagS1702.InitKB(13); }
		if (gHookKBS1702.Func14 == config) { gAntiLagS1702.InitKB(14); }
		if (gHookKBS1702.Func15 == config) { gAntiLagS1702.InitKB(15); }
		break;
	}
}
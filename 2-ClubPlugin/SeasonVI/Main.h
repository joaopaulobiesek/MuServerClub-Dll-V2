#pragma once


class CMain
{
public:

public:
	HINSTANCE hins;
	HWND hWnd;
	HHOOK HookKB;
	HHOOK HookMS;
	int NumberSplash1;
	int NumberSplash2;
	int NumberSplash3;
};

extern CMain gMain;
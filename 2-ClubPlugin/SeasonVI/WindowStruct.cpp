#include "pch.h"

float TransForX(float num)
{
	return (float)(pWinWidthReal <= 1.25) ? num * pWinWidthReal : num * pWinHeightReal;
}

float TransForY(float num)
{
	return (float)num * pWinHeightReal;
}

float TransFor2X(float num)
{
	return (float)num * pWinWidthReal;
}

float ReturnX(float num)
{
	return (float)(pWinWidthReal <= 1.25) ? num / pWinWidthReal : num / pWinHeightReal;
}

float Return2X(float num)
{
	return (float)num / pWinWidthReal;
}

float ReturnY(float num)
{
	return (float)num / pWinHeightReal;
}

bool CheckButtonPressed(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}
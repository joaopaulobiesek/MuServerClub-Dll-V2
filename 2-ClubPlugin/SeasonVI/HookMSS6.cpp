#include "pch.h"

CHookMSS6 gHookMSS6;

CHookMSS6::CHookMSS6() // OK
{
}

CHookMSS6::~CHookMSS6() // OK
{
}

void CHookMSS6::Init(int nCode, WPARAM wParam, LPARAM lParam)
{
	//if (gFeatures.camera3D == 0) return; // Desativa Camera 

	MOUSEHOOKSTRUCTEX* HookStruct = (MOUSEHOOKSTRUCTEX*)lParam;
	switch (wParam)
	{
	case WM_LBUTTONDOWN:
	{
		gCustomEventTimeDraw.EventNext(wParam);
		gCustomEventTimeDraw.EventPrev(wParam);
		gCustomEventTimeDraw.EventEventTimeWindow_Close(wParam);
		break;
	}
	default:
		break;
	}
}
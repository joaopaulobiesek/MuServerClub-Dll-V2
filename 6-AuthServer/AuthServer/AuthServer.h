#pragma once

#define MAX_LOADSTRING 100

#define TIMER_1000 100
#define TIMER_2000 101

extern char m_IpAddress[32];

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK About(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

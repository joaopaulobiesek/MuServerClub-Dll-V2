#pragma once

#define WM_DATA_SERVER_1_MSG_PROC (WM_USER+1)
#define WM_DATA_SERVER_2_MSG_PROC (WM_USER+2)

extern HWND hWnd;

// Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);



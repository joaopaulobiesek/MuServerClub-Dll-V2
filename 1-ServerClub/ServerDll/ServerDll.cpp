// ServerDll.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) // OK
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SERVERDLL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (InitInstance(hInstance, nCmdShow) == 0)
	{
		return 0;
	}

	gServerInfo.ReadStartupInfo("ServerPluginInfo", ".\\ServerPlugin.ini");

	gServerInfo.ReadStartupKeyboard("ConfigFuncKeys", ".\\ServerPlugin.ini");

	gServerInfo.ReadStartupCustomS6("ConfigCustomS6", ".\\ServerPlugin.ini");

	gServerDisplayer.Init(hWnd);

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) == 0)
	{
		if (gSocketManager.Start(gServerInfo.ServerPort) != 0)
		{
			gServerInfo.ReadInit();
		}

		gConnection.Init(hWnd, ProtocolDataServer);

		//if (gConnection.Connect(gServerInfo.m_DataServerAddress, (WORD)gServerInfo.m_DataServerPort, WM_DATA_SERVER_MSG_PROC) == 0)
		if (gConnection.Connect("127.0.0.1", (WORD)"55860", WM_DATA_SERVER_MSG_PROC) == 0)
		{
			LogAdd(LOG_RED, "Falha ao connectar ao data Server");
		}

		gProtocolDataServer.GDServerInfoSend();
	}
	else
	{
		LogAdd(LOG_RED, "WSAStartup() failed with error: %d", WSAGetLastError());
	}

	if (gServerInfo.CheckSQL == 1) gServerInfo.ReadStartupDS(".\\ServerPlugin.ini");

	gThreadAuth.Init();// Inicializa conexão com o AuthServer

	gServerDisplayer.PaintAllInfo();

	SetTimer(hWnd, TIMER_1000, 2000, 0);
	////////////////////////////////////////////////////////////////////////////////////////////
	LONG gwl = GetWindowLong(hWnd, GWL_STYLE);
	gwl &= (~WS_MAXIMIZEBOX); //& (~WS_MINIMIZEBOX);
	SetWindowLong(hWnd, GWL_STYLE, gwl);

	HACCEL hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_SERVERDLL);

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, 0, 0, 0) != 0)
	{
		if (TranslateAccelerator(msg.hwnd, hAccelTable, &msg) == 0)
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}

	return msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance) // OK
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_SERVERDLL);
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = (LPCSTR)IDC_SERVERDLL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) // OK
{
	hInst = hInstance;

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_THICKFRAME, CW_USEDEFAULT, 0, 800, 600, 0, 0, hInstance, 0);

	if (hWnd == 0)
	{
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return 1;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // OK
{
	switch (message)
	{

		HWND hWndStatusBar;

	case WM_CREATE:
	{
		hWndStatusBar = CreateWindowEx(
			0, STATUSCLASSNAME, NULL,
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | CCS_BOTTOM,
			0, 0, 0, 0, hWnd, (HMENU)IDC_STATUSBAR,
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		int iStatusWidths[] = { 110, -1 };

		char text[256];

		SendMessage(hWndStatusBar, SB_SETPARTS, 1, (LPARAM)iStatusWidths);

		wsprintf(text, "LOADING...");

		SendMessage(hWndStatusBar, SB_SETTEXT, 0, (LPARAM)text);

		ShowWindow(hWndStatusBar, SW_SHOW);

	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case IDM_EXIT:
			if (MessageBox(0, "Are you sure to terminate ServerDll?", "Ask terminate server", MB_YESNO | MB_ICONQUESTION) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		case IDM_RELOAD_CONFIG:
			if (gServerInfo.CheckCRC == 1) gServerInfo.ReadConfig();
			gServerInfo.ReadStartupInfo("ServerPluginInfo", ".\\ServerPlugin.ini");
			gServerInfo.ReadStartupKeyboard("ConfigFuncKeys", ".\\ServerPlugin.ini");
			gServerInfo.ReadStartupCustomS6("ConfigCustomS6", ".\\ServerPlugin.ini");
			break;
		case IDM_RELOAD_CHECKSUM:
			gServerInfo.ReadChecksumList();
			break;
		case IDM_RELOAD_BLACKLIST:
			gServerInfo.ReadBlackList();
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_TIMER:
		switch (wParam)
		{
		case TIMER_1000:
			gServerDisplayer.Run();
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) // OK
{
	switch (message)
	{
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return 1;
		}
		break;
	}

	return 0;
}
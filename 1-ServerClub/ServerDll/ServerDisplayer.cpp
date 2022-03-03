// ServerDisplayer.cpp: implementation of the CServerDisplayer class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"

CServerDisplayer gServerDisplayer;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerDisplayer::CServerDisplayer() // OK
{
	for (int n = 0; n < MAX_LOG_TEXT_LINE; n++)
	{
		memset(&this->m_log[n], 0, sizeof(this->m_log[n]));
	}

	this->m_font = CreateFont(50, 0, 0, 0, FW_THIN, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Times");
	this->m_font3 = CreateFont(15, 0, 0, 0, FW_THIN, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "MS Sans Serif");

	this->m_brush[0] = CreateSolidBrush(RGB(105, 105, 105));
	this->m_brush[1] = CreateSolidBrush(RGB(110, 240, 120));

	strcpy_s(this->m_DisplayerText[0], "STANDBY MODE");
	strcpy_s(this->m_DisplayerText[1], "ACTIVE MODE");
}

CServerDisplayer::~CServerDisplayer() // OK
{
	DeleteObject(this->m_font);
	DeleteObject(this->m_brush[0]);
	DeleteObject(this->m_brush[1]);
}

void CServerDisplayer::Init(HWND hWnd) // OK
{
	this->m_hwnd = hWnd;

	gLog.AddLog(1, "LOG");

	gLog.AddLogHack(1, "LOG\\Hack");
	gLog.AddLogHackSpeed(1, "LOG\\Speed");
}

void CServerDisplayer::Run() // OK
{
	this->LogTextPaint();
	this->SetWindowName();
	this->PaintAllInfo();
}

void CServerDisplayer::SetWindowName() // OK
{
	char buff[256];
	
	wsprintf(buff, "[%s] MuServer Club Server ", SERVER_VERSION);

	SetWindowText(this->m_hwnd, buff);

	HWND hWndStatusBar = GetDlgItem(this->m_hwnd, IDC_STATUSBAR);

	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	RECT rect2;

	GetClientRect(hWndStatusBar, &rect2);

	MoveWindow(hWndStatusBar, 0, rect.bottom - rect2.bottom + rect2.top, rect.right, rect2.bottom - rect2.top, true);

	int iStatusWidths[] = { 125, 225, 310, 500, 800 };

	char text[256];

	SendMessage(hWndStatusBar, SB_SETPARTS, 5, (LPARAM)iStatusWidths);

	wsprintf(text, "UserCount : %d/%d", GetUserCount(), MAX_CLIENT);

	SendMessage(hWndStatusBar, SB_SETTEXT, 0, (LPARAM)text);

	wsprintf(text, "Version: %s ", gProtocoloAuth.SwitchName(gProtocoloAuth.m_VersionId));

	SendMessage(hWndStatusBar, SB_SETTEXT, 1, (LPARAM)text);

	wsprintf(text, "Licensed: %d", gServerInfo.LicenseId);

	SendMessage(hWndStatusBar, SB_SETTEXT, 2, (LPARAM)text);

	wsprintf(text, "IP: %s - Port: %d", gServerInfo.IpAddress, gServerInfo.ServerPort);

	SendMessage(hWndStatusBar, SB_SETTEXT, 3, (LPARAM)text);

	wsprintf(text, "Expiration: %s", gProtocoloAuth.m_Date);

	SendMessage(hWndStatusBar, SB_SETTEXT, 4, (LPARAM)text);

	ShowWindow(hWndStatusBar, SW_SHOW);
}

void CServerDisplayer::PaintAllInfo() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	rect.top = 0;
	rect.bottom = 80;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc, TRANSPARENT);

	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_font);

	int state = 0;

	for (int n = 0; n < MAX_CLIENT; n++)
	{
		if (gClientManager[n].CheckState() == 0)
		{
			continue;
		}

		if ((GetTickCount() - gClientManager[n].m_PacketTime) <= 60000)
		{
			state = 1;
			break;
		}
	}

	if (state == 0)
	{
		SetTextColor(hdc, RGB(200, 200, 200));
		FillRect(hdc, &rect, this->m_brush[0]);
		TextOut(hdc, 120, 20, this->m_DisplayerText[0], strlen(this->m_DisplayerText[0]));
	}
	else
	{
		SetTextColor(hdc, RGB(250, 250, 250));
		FillRect(hdc, &rect, this->m_brush[1]);
		TextOut(hdc, 120, 20, this->m_DisplayerText[1], strlen(this->m_DisplayerText[1]));
	}

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::LogTextPaint() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	rect.top = 80;

	HDC hdc = GetDC(this->m_hwnd);

	FillRect(hdc, &rect, (HBRUSH)GetStockObject(0));

	int line = MAX_LOG_TEXT_LINE;

	int count = (((this->m_count - 1) >= 0) ? (this->m_count - 1) : (MAX_LOG_TEXT_LINE - 1));

	for (int n = 0; n < MAX_LOG_TEXT_LINE; n++)
	{
		switch (this->m_log[count].color)
		{
		case LOG_BLACK:
			SetTextColor(hdc, RGB(0, 0, 0));
			break;
		case LOG_RED:
			SetTextColor(hdc, RGB(255, 0, 0));
			break;
		case LOG_GREEN:
			SetTextColor(hdc, RGB(0, 255, 0));
			break;
		case LOG_BLUE:
			SetTextColor(hdc, RGB(0, 0, 255));
			break;
		case LOG_ORANGE:
			SetTextColor(hdc, RGB(255, 127, 0));
			break;
		}

		int size = strlen(this->m_log[count].text);

		if (size > 1)
		{
			TextOut(hdc, 0, (48 + (line * 15)), this->m_log[count].text, size);
			line--;
		}

		count = (((--count) >= 0) ? count : (MAX_LOG_TEXT_LINE - 1));
	}

	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::LogAddText(eLogColor color, char* text, int size) // OK
{
	size = ((size >= MAX_LOG_TEXT_SIZE) ? (MAX_LOG_TEXT_SIZE - 1) : size);

	memset(&this->m_log[this->m_count].text, 0, sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text, text, size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count) >= MAX_LOG_TEXT_LINE) ? 0 : this->m_count);

	gLog.Output(LOG_GENERAL, "%s", &text[9]);
}

void CServerDisplayer::LogAddTextHack(eLogColor color, char* text, int size) // OK
{
	size = ((size >= MAX_LOG_TEXT_SIZE) ? (MAX_LOG_TEXT_SIZE - 1) : size);

	memset(&this->m_log[this->m_count].text, 0, sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text, text, size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count) >= MAX_LOG_TEXT_LINE) ? 0 : this->m_count);

	gLog.OutputHack(LOG_GENERAL, "%s", &text[9]);
}

void CServerDisplayer::LogAddTextHackSpeed(eLogColor color, char* text, int size) // OK
{
	size = ((size >= MAX_LOG_TEXT_SIZE) ? (MAX_LOG_TEXT_SIZE - 1) : size);

	memset(&this->m_log[this->m_count].text, 0, sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text, text, size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count) >= MAX_LOG_TEXT_LINE) ? 0 : this->m_count);

	gLog.OutputHackSpeed(LOG_GENERAL, "%s", &text[9]);
}

void CServerDisplayer::PaintInvasionTime() // OK
{
#if(GAMESERVER_TYPE==0)
	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	int posX1 = rect.right - 445;
	int posX2 = rect.right - 355;

	rect.left = rect.right - 450;
	rect.right = rect.right - 305;
	rect.top = 60;
	rect.bottom = 290;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc, TRANSPARENT);

	FillRect(hdc, &rect, this->m_brush[3]);

	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_font3);

	char text1[20];
	char text2[30];
	int totalseconds;
	int hours;
	int minutes;
	int seconds;
	int days;

	SetTextColor(hdc, RGB(153, 0, 76));
	TextOut(hdc, rect.left + 5, rect.top + 2, "INVASION:", 9);

	for (int n = 0; n < 14; n++)
	{

		SetTextColor(hdc, RGB(0, 102, 204));
		if (n == 0) { wsprintf(text1, "%d - %s", n, "Skeleton King: "); }
		if (n == 1) { wsprintf(text1, "%d - %s", n, "Red Dragon: "); }
		if (n == 2) { wsprintf(text1, "%d - %s", n, "Golden Dragon: "); }
		if (n == 3) { wsprintf(text1, "%d - %s", n, "White Wizard: "); }
		if (n == 4) { wsprintf(text1, "%d - %s", n, "New Year: "); }
		if (n == 5) { wsprintf(text1, "%d - %s", n, "Rabbits: "); }
		if (n == 6) { wsprintf(text1, "%d - %s", n, "Summer: "); }
		if (n == 7) { wsprintf(text1, "%d - %s", n, "Cursed Santa: "); }
		if (n == 8) { wsprintf(text1, "%d - %s", n, "Medusa(S6+): "); }
		if (n == 9) { wsprintf(text1, "%d - %s", n, "Demons(S8+): "); }
		if (n == 10) { wsprintf(text1, "%d- %s", n, "Eggs(S8+): "); }
		if (n == 11) { wsprintf(text1, "%d- %s", n, "Custom 1: "); }
		if (n == 12) { wsprintf(text1, "%d- %s", n, "Custom 2: "); }
		if (n == 13) { wsprintf(text1, "%d- %s", n, "Custom 3: "); }

		if (this->EventInvasion[n] == -1)
		{
			wsprintf(text2, "Disabled");
		}
		else if (this->EventInvasion[n] == 0)
		{
			wsprintf(text2, "Online");
		}
		else
		{
			totalseconds = this->EventInvasion[n];
			hours = totalseconds / 3600;
			minutes = (totalseconds / 60) % 60;
			seconds = totalseconds % 60;

			if (hours > 23)
			{
				days = hours / 24;
				wsprintf(text2, "%d day(s)+", days);
			}
			else
			{
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
			}
		}

		TextOut(hdc, posX1, rect.top + 20 + (15 * n), text1, strlen(text1));
		if (this->EventInvasion[n] == -1)
		{
			SetTextColor(hdc, RGB(255, 0, 0));
		}
		else if (this->EventInvasion[n] == 0)
		{
			SetTextColor(hdc, RGB(0, 190, 0));
		}
		else if (this->EventInvasion[n] < 300)
		{
			SetTextColor(hdc, RGB(0, 190, 0));
		}
		else
		{
			SetTextColor(hdc, RGB(0, 0, 0));
		}
		TextOut(hdc, posX2, rect.top + 20 + (15 * n), text2, strlen(text2));
	}

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
#endif
}

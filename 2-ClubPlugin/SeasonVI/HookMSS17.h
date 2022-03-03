#pragma once
class CHookMSS17
{
public:
	CHookMSS17();
	virtual ~CHookMSS17();
	void Init(int nCode, WPARAM wParam, LPARAM lParam);
public:
};

extern CHookMSS17 gHookMSS17;
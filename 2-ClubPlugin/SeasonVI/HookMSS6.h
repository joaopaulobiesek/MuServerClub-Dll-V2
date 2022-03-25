#pragma once
class CHookMSS6
{
public:
	CHookMSS6();
	virtual ~CHookMSS6();
	void Init(int nCode, WPARAM wParam, LPARAM lParam);
public:
};

extern CHookMSS6 gHookMSS6;
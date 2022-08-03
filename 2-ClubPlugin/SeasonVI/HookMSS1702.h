#pragma once
class CHookMSS1702
{
public:
	CHookMSS1702();
	virtual ~CHookMSS1702();
	void Init(int nCode, WPARAM wParam, LPARAM lParam);
public:
};

extern CHookMSS1702 gHookMSS1702;
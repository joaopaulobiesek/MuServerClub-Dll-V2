#pragma once
class CHookMSS15
{
public:
	CHookMSS15();
	virtual ~CHookMSS15();
	void Init(int nCode, WPARAM wParam, LPARAM lParam);
public:
};

extern CHookMSS15 gHookMSS15;
// ThreadCheck.h: interface for the CThreadCheck class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ProcessQueryAuth.h"

#define MAX_THREAD_CHECK_AUTH 8

class CThreadCheckAuth
{
public:
	CThreadCheckAuth();
	virtual ~CThreadCheckAuth();
	void Init();
	bool CheckThreadState();
	//void CheckThreadIntegrity();
public:
	bool m_IsActive;
	UINT m_IsActiveTime;
	CProcessQueryAuth m_ProcessQuery;
	DWORD m_CheckThreadID[MAX_THREAD_CHECK_AUTH];
	CRITICAL_SECTION m_CheckThreadCriticalSection;
};

extern CThreadCheckAuth gThreadCheckAuth;

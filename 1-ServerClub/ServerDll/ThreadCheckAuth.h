// ThreadCheck.h: interface for the CThreadCheck class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ProcessQueryAuth.h"

#define MAX_THREAD_CHECK 8

class CThreadCheck
{
public:
	CThreadCheck();
	virtual ~CThreadCheck();
	void Init();
	bool CheckThreadState();
	//void CheckThreadIntegrity();
public:
	bool m_IsActive;
	UINT m_IsActiveTime;
	CProcessQuery m_ProcessQuery;
	DWORD m_CheckThreadID[MAX_THREAD_CHECK];
	CRITICAL_SECTION m_CheckThreadCriticalSection;
};

extern CThreadCheck gThreadCheck;

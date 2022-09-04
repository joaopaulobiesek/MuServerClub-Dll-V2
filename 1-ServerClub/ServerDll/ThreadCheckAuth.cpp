// ThreadCheck.cpp: implementation of the CThreadCheck class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"

CThreadCheckAuth gThreadCheckAuth;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThreadCheckAuth::CThreadCheckAuth()
{
	this->m_IsActive = 0;

	this->m_IsActiveTime = 0;

	this->m_CheckThreadID[0] = (DWORD)INVALID_HANDLE_VALUE;

	this->m_CheckThreadID[1] = (DWORD)INVALID_HANDLE_VALUE;

	this->m_CheckThreadID[2] = (DWORD)INVALID_HANDLE_VALUE;

	this->m_CheckThreadID[3] = (DWORD)INVALID_HANDLE_VALUE;

	this->m_CheckThreadID[4] = (DWORD)INVALID_HANDLE_VALUE;

	this->m_CheckThreadID[5] = (DWORD)INVALID_HANDLE_VALUE;

	InitializeCriticalSection(&this->m_CheckThreadCriticalSection);
}

CThreadCheckAuth::~CThreadCheckAuth()
{
	DeleteCriticalSection(&this->m_CheckThreadCriticalSection);
}

void CThreadCheckAuth::Init() //OK
{
	this->m_IsActive = 1;

	this->m_IsActiveTime = GetTickCount();
}

bool CThreadCheckAuth::CheckThreadState() // OK
{
	DWORD result = 0;

	if (this->m_ProcessQuery.Fetch(SystemProcessInformation, sizeof(SYSTEM_PROCESS_INFO_AUTH)) != 0)
	{
		SYSTEM_PROCESS_INFO_AUTH* lpSystemProcessInfo = this->m_ProcessQuery.GetProcessInfoByID((HANDLE)GetCurrentProcessId());

		if (lpSystemProcessInfo != 0)
		{
			for (int n = 0; n < MAX_THREAD_CHECK_AUTH; n++)
			{
				if (((HANDLE)this->m_CheckThreadID[n]) != INVALID_HANDLE_VALUE)
				{
					SYSTEM_THREAD_INFO_AUTH* lpSystemThreadInfo = this->m_ProcessQuery.GetThreadInfoByID(lpSystemProcessInfo, ((HANDLE)this->m_CheckThreadID[n]));

					if (lpSystemThreadInfo == 0 || (lpSystemThreadInfo->ThreadState == Waiting && lpSystemThreadInfo->WaitReason == Suspended))
					{
						return 0;
					}
					else
					{
						result++;
					}
				}
			}
		}
	}

	return ((result == 0) ? 0 : 1);
}
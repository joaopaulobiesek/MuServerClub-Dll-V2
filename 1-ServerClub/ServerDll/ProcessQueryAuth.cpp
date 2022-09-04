// ProcessQuery.cpp: implementation of the CProcessQuery class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"

NTQUERYSYSTEMINFORMATION CProcessQueryAuth::m_NtQuerySystemInformation;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcessQueryAuth::CProcessQueryAuth() // OK
{
	this->Start();
}

CProcessQueryAuth::~CProcessQueryAuth() // OK
{
	this->Close();
}

void CProcessQueryAuth::Start() // OK
{
	this->m_QueryData = 0;

	this->m_QuerySize = 0;

	this->m_QueryStatus = STATUS_SUCCESS;
}

void CProcessQueryAuth::Close() // OK
{
	this->m_QueryData = ((this->m_QueryData == 0) ? (BYTE*)0 : ((HeapFree(GetProcessHeap(), 0, this->m_QueryData) == 0) ? (BYTE*)0 : (BYTE*)0));

	this->m_QuerySize = 0;

	this->m_QueryStatus = STATUS_SUCCESS;
}

bool CProcessQueryAuth::Fetch(SYSTEM_INFORMATION_CLASS SysInfoClass, DWORD QuerySize) // OK
{
	while (this->m_QueryData != 0 || (this->m_QueryData = (BYTE*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, (this->m_QuerySize = ((this->m_QuerySize < QuerySize) ? QuerySize : this->m_QuerySize)))) != 0)
	{
		DWORD ReturnLength;

		if ((this->m_QueryStatus = CProcessQueryAuth::m_NtQuerySystemInformation(SysInfoClass, this->m_QueryData, this->m_QuerySize, &ReturnLength)) == STATUS_INFO_LENGTH_MISMATCH)
		{
			this->m_QueryData = ((this->m_QueryData == 0) ? (BYTE*)0 : ((HeapFree(GetProcessHeap(), 0, this->m_QueryData) == 0) ? (BYTE*)0 : (BYTE*)0));
			this->m_QuerySize = ReturnLength;
		}
		else
		{
			return ((this->m_QueryStatus == STATUS_SUCCESS) ? 1 : 0);
		}
	}

	return 0;
}

SYSTEM_HANDLE_INFO_AUTH* CProcessQueryAuth::GetHandleInfo() // OK
{
	return ((SYSTEM_HANDLE_INFO_AUTH*)this->m_QueryData);
}

SYSTEM_HANDLE_INFO_EX_AUTH* CProcessQueryAuth::GetExtendedHandleInfo() // OK
{
	return ((SYSTEM_HANDLE_INFO_EX_AUTH*)this->m_QueryData);
}

SYSTEM_KERNEL_DEBUGGER_INFO_AUTH* CProcessQueryAuth::GetKernelDebuggerInfo() // OK
{
	return ((SYSTEM_KERNEL_DEBUGGER_INFO_AUTH*)this->m_QueryData);
}

SYSTEM_PROCESS_INFO_AUTH* CProcessQueryAuth::GetProcessInfoByID(HANDLE ProcessId) // OK
{
	SYSTEM_PROCESS_INFO_AUTH* lpSystemProcessInfo = (SYSTEM_PROCESS_INFO_AUTH*)this->m_QueryData;

	while (true)
	{
		if (lpSystemProcessInfo->UniqueProcessId == ProcessId)
		{
			return lpSystemProcessInfo;
		}

		if (lpSystemProcessInfo->NextEntryOffset == 0)
		{
			break;
		}

		lpSystemProcessInfo = (SYSTEM_PROCESS_INFO_AUTH*)((BYTE*)lpSystemProcessInfo + lpSystemProcessInfo->NextEntryOffset);
	}

	return 0;
}

SYSTEM_EXTENDED_PROCESS_INFO_AUTH* CProcessQueryAuth::GetExtendedProcessInfoByID(HANDLE ProcessId) // OK
{
	SYSTEM_EXTENDED_PROCESS_INFO_AUTH* lpSystemProcessInfo = (SYSTEM_EXTENDED_PROCESS_INFO_AUTH*)this->m_QueryData;

	while (true)
	{
		if (lpSystemProcessInfo->UniqueProcessId == ProcessId)
		{
			return lpSystemProcessInfo;
		}

		if (lpSystemProcessInfo->NextEntryOffset == 0)
		{
			break;
		}

		lpSystemProcessInfo = (SYSTEM_EXTENDED_PROCESS_INFO_AUTH*)((BYTE*)lpSystemProcessInfo + lpSystemProcessInfo->NextEntryOffset);
	}

	return 0;
}

SYSTEM_THREAD_INFO_AUTH* CProcessQueryAuth::GetThreadInfoByID(SYSTEM_PROCESS_INFO_AUTH* lpSystemProcessInfo, HANDLE ThreadId) // OK
{
	SYSTEM_THREAD_INFO_AUTH* lpSystemThreadInfo = lpSystemProcessInfo->Threads;

	for (DWORD n = 0; n < lpSystemProcessInfo->NumberOfThreads; n++, lpSystemThreadInfo++)
	{
		if (lpSystemThreadInfo->ClientId.UniqueThread == ThreadId)
		{
			return lpSystemThreadInfo;
		}
	}

	return 0;
}

SYSTEM_EXTENDED_THREAD_INFO_AUTH* CProcessQueryAuth::GetExtendedThreadInfoByID(SYSTEM_EXTENDED_PROCESS_INFO_AUTH* lpSystemProcessInfo, HANDLE ThreadId) // OK
{
	SYSTEM_EXTENDED_THREAD_INFO_AUTH* lpSystemThreadInfo = lpSystemProcessInfo->Threads;

	for (DWORD n = 0; n < lpSystemProcessInfo->NumberOfThreads; n++, lpSystemThreadInfo++)
	{
		if (lpSystemThreadInfo->ThreadInfo.ClientId.UniqueThread == ThreadId)
		{
			return lpSystemThreadInfo;
		}
	}

	return 0;
}

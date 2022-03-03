#include "pch.h"

DWORD API_Address_Count = 0;
DWORD API_Address_Table[64] = { 0 };
HANDLE FileMappingHandle;
HACK_VERIFY_FILE_MAPPING* lpHackVerifyFileMapping;
DWORD MemoryProtectionTime;
DWORD HandleProtectionNumber;
DWORD HandleProtectionObject;
BYTE LibraryLoadSource[6];
std::map<DWORD, MEMORY_CHECK_SOURCE> MemoryCheckSource;

void CheckSystemInformation() // OK
{
	//gLog.Output(LOG_DEBUG, "----------------------------------------------------------------------------------------------------");

	OSVERSIONINFO osvi;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

	MEMORYSTATUSEX mstx;

	mstx.dwLength = sizeof(mstx);

	GlobalMemoryStatusEx(&mstx);

	//gLog.Output(LOG_DEBUG,GetEncryptedString(0),HACKCLIENT_VERSION,osvi.dwMajorVersion,osvi.dwMinorVersion,osvi.dwBuildNumber,(int)(((mstx.ullTotalPhys-mstx.ullAvailPhys)/1024)/1024),(int)((mstx.ullTotalPhys/1024)/1024));
}

bool GetPhysicalDriveSerialNumber(int PhysicalDriveNumber, char* PhysicalDriveSerial, int PhysicalDriveSerialSize) // OK
{
	char PhysicalDrivePath[MAX_PATH];

	wsprintf(PhysicalDrivePath, "\\\\.\\PhysicalDrive%d", PhysicalDriveNumber);

	HANDLE PhysicalDriveHandle = CreateFile(PhysicalDrivePath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);

	if (PhysicalDriveHandle == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD BytesReturned;

	STORAGE_PROPERTY_QUERY StoragePropertyQuery;

	STORAGE_DESCRIPTOR_HEADER StorageDescriptorHeader;

	memset(&StoragePropertyQuery, 0, sizeof(StoragePropertyQuery));

	memset(&StorageDescriptorHeader, 0, sizeof(StorageDescriptorHeader));

	StoragePropertyQuery.PropertyId = StorageDeviceProperty;

	StoragePropertyQuery.QueryType = PropertyStandardQuery;

	if (DeviceIoControl(PhysicalDriveHandle, IOCTL_STORAGE_QUERY_PROPERTY, &StoragePropertyQuery, sizeof(StoragePropertyQuery), &StorageDescriptorHeader, sizeof(StorageDescriptorHeader), &BytesReturned, 0) == 0)
	{
		CloseHandle(PhysicalDriveHandle);
		return 0;
	}

	BYTE* PhysicalDriveBuff = new BYTE[StorageDescriptorHeader.Size];

	memset(PhysicalDriveBuff, 0, StorageDescriptorHeader.Size);

	if (DeviceIoControl(PhysicalDriveHandle, IOCTL_STORAGE_QUERY_PROPERTY, &StoragePropertyQuery, sizeof(StoragePropertyQuery), PhysicalDriveBuff, StorageDescriptorHeader.Size, &BytesReturned, 0) == 0)
	{
		CloseHandle(PhysicalDriveHandle);
		delete[] PhysicalDriveBuff;
		return 0;
	}

	if (((STORAGE_DEVICE_DESCRIPTOR*)PhysicalDriveBuff)->SerialNumberOffset == 0)
	{
		CloseHandle(PhysicalDriveHandle);
		delete[] PhysicalDriveBuff;
		return 0;
	}

	__try
	{
		strcpy_s(PhysicalDriveSerial, PhysicalDriveSerialSize, (char*)(PhysicalDriveBuff + ((STORAGE_DEVICE_DESCRIPTOR*)PhysicalDriveBuff)->SerialNumberOffset));
		CloseHandle(PhysicalDriveHandle);
		delete[] PhysicalDriveBuff;
		return 1;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		CloseHandle(PhysicalDriveHandle);
		delete[] PhysicalDriveBuff;
		return 0;
	}
}

bool API_INIT() // OK
{
	CProcessQuery::m_NtQuerySystemInformation = (NTQUERYSYSTEMINFORMATION)GetProcAddress(GetModuleHandle("Ntdll.dll"), "NtQuerySystemInformation");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "OpenProcess");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "ExitProcess");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "TerminateProcess");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateThread");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "QueryPerformanceCounter");

	API_Address_Table[API_Address_Count++] = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "QueryPerformanceFrequency");

	API_Address_Table[API_Address_Count++] = CHECK_API_REDIRECT((DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "GetTickCount"));

	API_Address_Table[API_Address_Count++] = CHECK_API_REDIRECT((DWORD)GetProcAddress(GetModuleHandle("Ntdll.dll"), "ZwOpenProcess"));

	API_Address_Table[API_Address_Count++] = CHECK_API_REDIRECT((DWORD)GetProcAddress(GetModuleHandle("Ntdll.dll"), "ZwTerminateProcess"));

	API_Address_Table[API_Address_Count++] = CHECK_API_REDIRECT((DWORD)GetProcAddress(GetModuleHandle("Ntdll.dll"), "ZwSuspendProcess"));

	API_Address_Table[API_Address_Count++] = CHECK_API_REDIRECT((DWORD)GetProcAddress(GetModuleHandle("Ntdll.dll"), "ZwSuspendThread"));

	return API_SCAN();
}

bool API_SCAN() // OK
{
	for (DWORD n = 0; n < API_Address_Count; n++)
	{
		if (API_Address_Table[n] == 0)
		{
			continue;
		}

		BYTE opcode = *(BYTE*)(API_Address_Table[n]);

		switch (opcode)
		{
		case 0x68:
		case 0xC2:
		case 0xC3:
		case 0xE8:
		case 0xE9:
		case 0xFF:
			gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_MEMORY_DETECTION, 0, 0);
			return 0;
		}
	}

	return 1;
}
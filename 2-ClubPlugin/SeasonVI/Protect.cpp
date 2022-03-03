#include "pch.h"

CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{

}

CProtect::~CProtect() // OK
{

}

bool CProtect::ReadDllFile(char* name) // OK
{
	CCRC32 CRC32;

	if (CRC32.FileCRC(name, &this->m_ClientFileCRC, 1024) == 0)
	{
		this->m_ClientFileCRC = 0;
		return 0;
	}

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if (file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if (GetFileSize(file, 0) != sizeof(MAIN_FILE_INFO))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if (ReadFile(file, &this->m_MainInfo, sizeof(MAIN_FILE_INFO), &OutSize, 0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	for (int n = 0; n < sizeof(MAIN_FILE_INFO); n++)
	{
		((BYTE*)&this->m_MainInfo)[n] += (BYTE)(0x98 ^ HIBYTE(n));
		((BYTE*)&this->m_MainInfo)[n] ^= (BYTE)(0xD9 ^ LOBYTE(n));
	}

	gMessage.GetLanguage();

	gMessage.LoadEng(this->m_MainInfo.EngMessageInfo);

	gMessage.LoadPor(this->m_MainInfo.PorMessageInfo);

	gMessage.LoadSpn(this->m_MainInfo.SpnMessageInfo);

	CloseHandle(file);
	return 1;
}
// MemScript.h: interface for the CMemScript class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#define MEM_SCRIPT_ALLOC_ERROR "[%s] Could not alloc memory for MemScript\n"
#define MEM_SCRIPT_ERROR_CODE0 "[%s] Could not open file\n"
#define MEM_SCRIPT_ERROR_CODE1 "[%s] Could not alloc file buffer\n"
#define MEM_SCRIPT_ERROR_CODE2 "[%s] Could not read file\n"
#define MEM_SCRIPT_ERROR_CODE3 "[%s] Could not get file buffer\n"
#define MEM_SCRIPT_ERROR_CODE4 "[%s] The file were not configured correctly\n"
#define MEM_SCRIPT_ERROR_CODEX "[%s] Unknow error code: %d\n"

enum eTokenResult
{
	TOKEN_NUMBER = 0,
	TOKEN_STRING = 1,
	TOKEN_END = 2,
	TOKEN_ERROR = 3,
};

class CMemScript
{
public:
	CMemScript();
	virtual ~CMemScript();

	bool SetBuffers(char* path);
	bool SetBuffer(char* filename, int CryptSwitch);
	void GetWzAgInfo(char* buff, DWORD* size);
	int GetChar();
	void UnGetChar(int ch);
	int GetToken();
	int GetNumber();
	int GetAsNumber();
	DWORD GetDword();
	DWORD GetAsDword();
	double GetFloat();
	double GetAsFloat();
	float GetAsFloatNumber();
	char* GetString();
	char* GetAsString();
	void DataCrypt(char** content);

	char* GetLastError();
	void SetLastError(int error);
private:
	char* m_buff;
	DWORD m_size;
	int m_count;
	float m_number;
	DWORD m_dword;
	char m_string[100];
	DWORD m_tick;

	char m_LastError[256];
	char m_path[256];
};
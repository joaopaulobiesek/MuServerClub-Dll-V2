#include "pch.h"
CGetVersion gGetVersion;

CGetVersion::CGetVersion() // OK
{
}

CGetVersion::~CGetVersion() // OK
{
}

//https://helloacm.com/c-function-to-get-file-version-using-win32-api-ansi-and-unicode-version/
int CGetVersion::GetFileVersion(const char* filename, char* ver)
{
    /*DWORD dwHandle, sz = GetFileVersionInfoSizeA(filename, &dwHandle);
    if (0 == sz)
    {
        return 1;
    }
    char* buf = new char[sz];
    if (!GetFileVersionInfoA(filename, dwHandle, sz, &buf[0]))
    {
        delete[] buf;
        return 2;
    }
    VS_FIXEDFILEINFO* pvi;
    sz = sizeof(VS_FIXEDFILEINFO);
    if (!VerQueryValueA(&buf[0], "\\", (LPVOID*)&pvi, (unsigned int*)&sz))
    {
        delete[] buf;
        return 3;
    }
    sprintf(ver, "%d.%d.%d.%d"
        , pvi->dwProductVersionMS >> 16
        , pvi->dwFileVersionMS & 0xFFFF
        , pvi->dwFileVersionLS >> 16
        , pvi->dwFileVersionLS & 0xFFFF
    );
    delete[] buf;*/
    return 0;

    /*this->dwHandle, this->sz = GetFileVersionInfoSizeA(filename, &this->dwHandle);
    if (0 == this->sz)
    {
        return 1;
    }
    this->buf = new char[this->sz];
    if (!GetFileVersionInfoA(filename, this->dwHandle, this->sz, &this->buf[0]))
    {
        delete[] this->buf;
        return 2;
    }
    this->pvi;
    this->sz = sizeof(VS_FIXEDFILEINFO);
    if (!VerQueryValueA(&this->buf[0], "\\", (LPVOID*)&pvi, (unsigned int*)&this->sz))
    {
        delete[] this->buf;
        return 3;
    }
    sprintf(ver, "%d.%d.%d.%d"
        , pvi->dwProductVersionMS >> 16
        , pvi->dwFileVersionMS & 0xFFFF
        , pvi->dwFileVersionLS >> 16
        , pvi->dwFileVersionLS & 0xFFFF
    );
    delete[] this->buf;
    return 0;*/
}
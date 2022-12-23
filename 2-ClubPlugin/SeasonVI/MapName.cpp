#include "pch.h"

CMapName gMapName;

CMapName::CMapName() // OK
{
	this->Init();
	this->m_MapNumberDefault = 200;
}

CMapName::~CMapName() // OK
{

}

void CMapName::Init() // OK
{
	memset(this->m_DefaultMap, 0, sizeof(this->m_DefaultMap));

	for (int n = 0; n < MAX_MAP; n++)
	{
		this->m_MapName[n].Index = -1;
	}
}

void CMapName::LoadMap(MAP_NAME* info) // OK
{
	for (int n = 0; n < MAX_MAP; n++)
	{
		this->SetMap(info[n]);
	}
}

void CMapName::SetMap(MAP_NAME info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_MAP)
	{
		return;
	}
	this->m_MapName[info.Index] = info;
}

MAP_NAME* CMapName::GetMapName(int map) // OK
{
	for (int n = 0; n < MAX_MAP; n++)
	{
		MAP_NAME* lpInfo = this->GetIndexMap(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (lpInfo->MapNumber == map)
		{
			return lpInfo;
		}
	}
	return 0;
}

MAP_NAME* CMapName::GetIndexMap(int index) // OK
{
	if (index < 0 || index >= MAX_MAP)
	{
		wsprintf(this->m_DefaultMap, "NULL");
		return 0;
	}

	if (this->m_MapName[index].Index != index)
	{
		wsprintf(this->m_DefaultMap, "NULL");
		return 0;
	}

	return &this->m_MapName[index];
}

char* CMapName::GetMap(int index) // OK
{
	MAP_NAME* lpInfo = this->GetMapName(index);
	if (lpInfo == 0) { return this->m_DefaultMap; }
	return lpInfo->Name;
}


void CMapName::Scan()
{
	MAP_NAME info;

	for (std::vector<MAP_NAME>::iterator it = gListManager.gCustomMapNameListInfo.begin(); it != gListManager.gCustomMapNameListInfo.end(); it++)
	{
		info.Index = it->Index;

		info.MapNumber = it->MapNumber;

		strcpy_s(info.Name, it->Name);

		this->m_MapName[info.Index] = info;
	}
}

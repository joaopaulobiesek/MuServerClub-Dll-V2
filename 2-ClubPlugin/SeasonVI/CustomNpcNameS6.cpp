#include "pch.h"

cNPCName gNPCName;

cNPCName::cNPCName()
{
	this->Init();
}

cNPCName::~cNPCName()
{

}

void cNPCName::Init()
{
	for (int n = 0; n < MAX_CUSTOM_NPCNAME; n++)
	{
		this->m_CustomNpcName[n].Index = -1;
	}
}

void cNPCName::Load(NPCNAME_DATA* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_NPCNAME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void cNPCName::SetInfo(NPCNAME_DATA info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_NPCNAME)
	{
		return;
	}
	//console.Log("NPCName", "[Load] %d %s", info.Index, info.Name);
	this->m_CustomNpcName[info.Index] = info;
}

NPCNAME_DATA* cNPCName::GetNPCName(int MosnterID, int Map, int X, int Y) // OK
{
	for (int n = 0; n < MAX_CUSTOM_NPCNAME; n++)
	{
		NPCNAME_DATA* lpInfo = this->GetNPCNameByIndex(n);

		if (lpInfo == 0)
		{
			continue;
		}

		if (lpInfo->NPCId == MosnterID && lpInfo->Map == Map && lpInfo->X == X && lpInfo->Y == Y)
		{
			return lpInfo;
		}

		if (lpInfo->NPCId == MosnterID && lpInfo->Map == Map && lpInfo->X == -1 && lpInfo->Y == -1)
		{
			return lpInfo;
		}
	}

	return 0;
}


NPCNAME_DATA* cNPCName::GetNPCNameByIndex(int index) // OK
{
	if (index < 0 || index >= MAX_CUSTOM_NPCNAME)
	{
		return 0;
	}

	if (this->m_CustomNpcName[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomNpcName[index];
}

void cNPCName::Scan()
{
	NPCNAME_DATA info;

	for (std::vector<NPCNAME_DATA>::iterator it = gListManager.gCustomNPCListInfo.begin(); it != gListManager.gCustomNPCListInfo.end(); it++)
	{
		info.Index = it->Index++;

		info.NPCId = it->NPCId;

		info.Map = it->Map;

		info.X = it->X;

		info.Y = it->Y;

		strcpy_s(info.Name, it->Name);

		this->m_CustomNpcName[info.Index] = info;
	}
}
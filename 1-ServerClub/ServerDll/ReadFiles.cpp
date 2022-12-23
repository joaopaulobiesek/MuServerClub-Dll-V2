#include "pch.h"

CReadFiles gReadFiles;

CReadFiles::CReadFiles()
{
	this->ReloadSwitch = 0;
	this->UpdateSwitch = 0;
}

CReadFiles::~CReadFiles()
{
}

void CReadFiles::DumpList(char* filename)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(filename, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gDumpListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == 2)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			DUMP_LIST_INFO TempList;

			TempList.type = lpScript->GetNumber();

			char TempHex[11];

			strcpy_s(TempHex, lpScript->GetAsString());

			sscanf_s(TempHex, "%X", &TempList.offset);

			for (int i = 0; i < 32; i++)
			{
				TempList.dump[i] = lpScript->GetAsNumber();
			}

			char TempName[255];

			strcpy_s(TempName, lpScript->GetAsString());

			TempName[31] = ((strlen(TempName) > 31) ? 0 : TempName[31]);

			strcpy_s(TempList.name, TempName);

			gDumpListInfo.push_back(TempList);
		}
	}
	catch (...)
	{
		ErrorMessageBox("%s file read error", filename);
	}

	delete lpScript;
}

void CReadFiles::ChecksumList(char* filename)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(filename, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gChecksumListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == 2)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			CSUM_LIST_INFO TempList;

			strcpy_s(TempList.path, lpScript->GetString());

			TempList.checksum = lpScript->GetAsDword();

			gChecksumListInfo.push_back(TempList);
		}
	}
	catch (...)
	{
		ErrorMessageBox("%s file read error", filename);
	}

	delete lpScript;
}

void CReadFiles::InternalList(char* filename)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(filename, 1) == 0)
	{
		delete lpScript;
		return;
	}

	gInternalListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == 2)
			{
				break;
			}

			int section = lpScript->GetNumber();

			while (true)
			{
				if (strcmp("end", lpScript->GetAsString()) == 0)
				{
					break;
				}

				ITRN_LIST_INFO TempList;

				memset(&TempList, 0, sizeof(TempList));

				TempList.type = section;

				strcpy_s(TempList.value, lpScript->GetString());

				gInternalListInfo.push_back(TempList);
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox("%s file read error", filename);
	}

	delete lpScript;
}

void CReadFiles::WindowList(char* filename)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(filename, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gWindowListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == 2)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			WNDW_LIST_INFO TempList;

			TempList.type = lpScript->GetNumber();

			strcpy_s(TempList.text, lpScript->GetAsString());

			gWindowListInfo.push_back(TempList);
		}
	}
	catch (...)
	{
		ErrorMessageBox("%s file read error", filename);
	}

	delete lpScript;
}

void CReadFiles::CustomMonsterList(char* path)
{

	CMemScript* lpScript = new CMemScript;

	int Index = 0;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomMonsterListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			CUSTOMMONSTER_DATA info;

			info.Index = Index++;

			info.ID = lpScript->GetNumber();

			info.Type = lpScript->GetAsNumber();

			strcpy_s(info.Name, lpScript->GetAsString());

			strcpy_s(info.Dir, lpScript->GetAsString());

			strcpy_s(info.Folder, lpScript->GetAsString());

			strcpy_s(info.BMDFile, lpScript->GetAsString());

			info.Size = lpScript->GetAsFloatNumber();

			gCustomMonsterListInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}

void CReadFiles::CustomNPCList(char* path)
{

	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomNPCListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			NPCNAME_DATA info;

			memset(&info, 0, sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount++;

			info.NPCId = lpScript->GetNumber();

			info.Map = lpScript->GetAsNumber();

			info.X = lpScript->GetAsNumber();

			info.Y = lpScript->GetAsNumber();

			strcpy_s(info.Name, lpScript->GetAsString());

			gCustomNPCListInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}

void CReadFiles::CustomEventList(char* path)
{

	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomEVENTListNameInfo.clear();

	gCustomEVENTListHourInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpScript->GetAsString()) == 0)
					{
						break;
					}

					EVENTNAME_DATA info;

					memset(&info, 0, sizeof(info));

					static int CustomIndexCount = 0;

					info.Index = CustomIndexCount;

					info.Id = lpScript->GetNumber();

					strcpy_s(info.Name, lpScript->GetAsString());

					gCustomEVENTListNameInfo.push_back(info);

					CustomIndexCount++;
				}
				else if (section == 1)
				{
					if (strcmp("end", lpScript->GetAsString()) == 0)
					{
						break;
					}

					EVENTNAME_HOUR_DATA info;

					memset(&info, 0, sizeof(info));

					static int CustomIndexCount = 0;

					info.Index = CustomIndexCount;

					info.Id = lpScript->GetNumber();

					info.Year = lpScript->GetAsNumber();

					info.Month = lpScript->GetAsNumber();

					info.Day = lpScript->GetAsNumber();

					info.DoW = lpScript->GetAsNumber();

					info.Hour = lpScript->GetAsNumber();

					info.Minute = lpScript->GetAsNumber();

					info.Second = lpScript->GetAsNumber();

					CustomIndexCount++;

					gCustomEVENTListHourInfo.push_back(info);
				}
			}
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}

void CReadFiles::CustomCloakList(char* path)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomCloakListInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			CLOAKNAME_DATA info;

			memset(&info, 0, sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount;

			info.ItemIndex = lpScript->GetNumber();

			info.Mode = lpScript->GetAsNumber();

			info.IndexCloak = 0;

			info.IndexStrip = 0;

			strcpy_s(info.CloakName, lpScript->GetAsString());

			strcpy_s(info.StripName, lpScript->GetAsString());

			CustomIndexCount++;

			gCustomCloakListInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}

void CReadFiles::CustomSmokeEffectList(char* path)
{
	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomSmokeEffectInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_SMOKEEFFECT info;

			memset(&info, 0, sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount;

			info.ItemIndex = lpScript->GetNumber();

			info.Red = lpScript->GetAsFloat();

			info.Green = lpScript->GetAsFloat();

			info.Blue = lpScript->GetAsFloat();
			
			CustomIndexCount++;

			gCustomSmokeEffectInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}

void CReadFiles::CustomFogList(char* path)
{

	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomFogInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_FOG info;

			memset(&info, 0, sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount;

			info.MapNumber = lpScript->GetNumber();

			info.Enable = lpScript->GetAsNumber();

			info.Red = lpScript->GetAsFloat();

			info.Green = lpScript->GetAsFloat();

			info.Blue = lpScript->GetAsFloat();

			CustomIndexCount++;

			gCustomFogInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}



void CReadFiles::CustomMapNameList(char* path)
{

	CMemScript* lpScript = new CMemScript;

	if (lpScript == 0)
	{
		return;
	}

	if (lpScript->SetBuffer(path, 0) == 0)
	{
		delete lpScript;
		return;
	}

	gCustomMapNameInfo.clear();

	try
	{
		while (true)
		{
			if (lpScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpScript->GetString()) == 0)
			{
				break;
			}

			MAP_NAME info;

			memset(&info, 0, sizeof(info));

			static int CustomIndexCount = 0;

			info.Index = CustomIndexCount;

			info.MapNumber = lpScript->GetNumber();

			strcpy_s(info.Name, lpScript->GetAsString());

			CustomIndexCount++;

			gCustomMapNameInfo.push_back(info);
		}
	}
	catch (...)
	{
		printf(lpScript->GetLastError());
	}

	delete lpScript;
}
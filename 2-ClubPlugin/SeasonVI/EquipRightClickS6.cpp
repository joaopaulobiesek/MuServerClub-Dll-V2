#include "pch.h"

CEquipRightClickS6 gEquipRightClickS6;

CEquipRightClickS6::CEquipRightClickS6()
{
}

CEquipRightClickS6::~CEquipRightClickS6()
{
}

signed int dword_1004A274;

int __cdecl sub_10025270(int a1, int a2)
{
	int v2; // eax@4
	int v3; // eax@4 // eax@4

	MessageBox(0, "Entrou", "Error", MB_OK | MB_ICONERROR);
	if (dword_1004A274 >= 0)
	{
		MessageBox(0, "Entrou 2", "Error", MB_OK | MB_ICONERROR);
		if (*(BYTE*)(a1 + 3) != -1)
		{
			MessageBox(0, "Entrou 3", "Error", MB_OK | MB_ICONERROR);
			if ((unsigned int)(dword_1004A274 - 12) > 0x1E7)
			{
				MessageBox(0, "Entrou 4", "Error", MB_OK | MB_ICONERROR);
				v833B20(v861110, dword_1004A274);
			}
			else
			{
				MessageBox(0, "Entrou 5", "Error", MB_OK | MB_ICONERROR);
				v3 = v861260(v861110);
				v834320(v861110, v3);
			}
		}
		dword_1004A274 = 0xFFFFFFFF;
	}
	MessageBox(0, "Saiu", "Error", MB_OK | MB_ICONERROR);
	return v64B860(a1, a2);
}

int __cdecl Equipment(void *This)
{
	int v1; // edi@2
	WORD* v2; // eax@5
	WORD* v3; // edi@5
	WORD* _v4; // eax@4
	char v4; // ST27_1@7
	int v5; // eax@7
	int v6; // eax@7
	int v7; // ebx@7
	unsigned int v8; // ST2C_4@7
	char v10; // ST27_1@12
	int v11; // ebx@12
	int v12; // eax@12
	//int v13; // eax@12
	void* v13;
	int v14; // eax@12
	char v15; // al@17
	char v16; // al@17
	int v17; // ST2C_4@21
	char v18; // ST2C_1@23
	int v19; // eax@23
	char v20; // ST23_1@31
	char v21; // al@31
	char v22; // [sp+2Bh] [bp-409h]@17
	int v23; // [sp+2Ch] [bp-408h]@12
	char v24; // [sp+30h] [bp-404h]@17

	if (!*((DWORD*)This + 16))
		return 0;
	v1 = v7DD0F0();
	if (v1)
	{
		v10 = v50B840(v861110);
		v11 = v7D9430(v1);
		v12 = v7D9410(v1);
		v13 = v861110();
		v14 = v861260(v13);
		v23 = v83C710((DWORD*)v861260(v13), v12);
		if (v830870((int)This) || (_v4 = (WORD*)v7D9430(v1), !v830100((char*)v861110, _v4)) || v23 == -1)
		{
			v17 = *(DWORD*)((int)This + 16);
			if (v7D9410(v1) == v17)
			{
				v7DA6A0(*(DWORD*)((int)This + 16), 0.1, 0.40000001, 0.80000001);
				if ((unsigned __int8)v791070(1))
				{
					v18 = v7D94E0(v1);
					v19 = v7D95E0(*(DWORD*)((int)This + 16));
					if (v19 != -1 && (unsigned __int8)v7DC670(*(DWORD*)((int)This + 16), v19, v11) && (unsigned __int8)v5BD850(v10, v18, v11))
						return 1;
				}
			}
			else if (v830870((int)This) || !v830100((char*)v861110, (WORD*)v11) || *(BYTE*)(v11 + 68) != 1)
			{
				v7DA6A0(*(DWORD*)((int)This + 16), 1.0, 0.2, 0.2);
			}
			else
			{
				v7DA6A0(*(DWORD*)((int)This + 16), 0.1, 0.40000001, 0.80000001);
				if ((unsigned __int8)v791070(1))
				{
					v20 = v7D94E0(v1);
					v21 = v7D95E0(*(DWORD*)((int)This + 16));
					if (v21 != -1)
					{
						if ((unsigned __int8)v7DC670(*(DWORD*)((int)This + 16), v21, v11))
						{
							v5BD850(0, v20, v11);
							return 1;
						}
					}
				}
			}
		}
		else if ((unsigned __int8)v7DC5D0(v879340C, v8793410) == 1)
		{
			if ((unsigned __int8)v791070(1))
			{
				sprintf(&v24, "%d %d", 1, 1);
				v15 = v7D94E0(v1);
				v22 = v83C480(v15, v23);
				v16 = v7D95E0(*(DWORD*)((int)This + 16));
				if (v16 != -1
					&& (unsigned __int8)v7DC670(*(DWORD*)((int)This + 16), v16, v11)
					&& (unsigned __int8)v5BD850(0, (unsigned __int8)(v22 + 12), v11))
				{
					return 1;
				}
			}
		}
		return 0;
	}
	if (!(unsigned __int8)v791050(2))
		return 0;
	if ((unsigned __int8)v7DC5D0(v879340C, v8793410) != 1)
		return 0;
	v2 = (WORD*)v7DAC10(v879340C, v8793410);
	v3 = v2;
	if (!v2)
		return 0;
	if (*v2 < 0)
		return 0;
	v4 = v50B840(v861110);
	//v5 = v861110(v3, 0);
	v6 = v861260(v13);
	v7 = v8359C0(v6, v3, 0);
	v8 = v7DAB80((DWORD*)((int)This + 16), (int)v3);
	if (v8 > 0x1F || v7 < 0)
		return 0;
	if ((unsigned __int8)v7DD100(*(DWORD*)((int)This + 16), (int)v3))
	{
		v7DA480((DWORD*)((int)This + 16), (int)v3);
		v5BD850(0, 0, 0);
	}
	return 1;
}

void CEquipRightClickS6::Init()
{
	SetCompleteHook(0xE9, 0x0082C3DC, &Equipment);
	SetCompleteHook(0xE8, 0x66424B, &sub_10025270);
}
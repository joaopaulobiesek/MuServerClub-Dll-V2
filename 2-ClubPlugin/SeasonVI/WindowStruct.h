#pragma once


#define sub_779350 ((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define sub_779410 ((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x00779410)

#define GetInstance ((int(__cdecl*)()) 0x00861110)
bool CheckButtonPressed(int x, int y, int w, int h);

float TransForX(float num);
float TransForY(float num);
float TransFor2X(float num);
float ReturnX(float num);
float Return2X(float num);
float ReturnY(float num);
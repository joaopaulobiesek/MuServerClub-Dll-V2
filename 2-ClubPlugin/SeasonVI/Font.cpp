#include "pch.h"

Font gFont;

char MyFontFaceName[100];
char sValue[99];

int Bold = GetPrivateProfileIntA("FontConfig", "FontBold", 0, "./Settings.ini");
int Italic = GetPrivateProfileIntA("FontConfig", "FontItalic", 0, "./Settings.ini");
int Unicode = GetPrivateProfileIntA("FontConfig", "FontUnicode", 1, "./Settings.ini");

int Width = GetPrivateProfileIntA("FontConfig", "MainFontWidth", 0, "./Settings.ini");
int UnderLine = GetPrivateProfileIntA("FontConfig", "FontUnderline", 0, "./Settings.ini");
int Quality = GetPrivateProfileIntA("FontConfig", "FontQuality", 3, "./Settings.ini");
int StrikeOut = GetPrivateProfileIntA("FontConfig", "FontStrikeOut", 0, "./Settings.ini");



HFONT Font::LoadNewFont() {
    HFONT MyFont;
    if (Bold == 0) {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    else {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    return MyFont;
}
HFONT Font::LoadNewFont2() {
    HFONT MyFont;
    if (Bold == 0) {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    else {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    return MyFont;
}
HFONT Font::LoadNewFont3() {
    HFONT MyFont;
    if (Bold == 0) {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    else {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    return MyFont;
}
HFONT Font::LoadNewFont4() {
    HFONT MyFont;
    if (Bold == 0) {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    else {
        if (Unicode == 1) {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
        }
        else {
            MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
        }
    }
    return MyFont;
}

HFONT LoadNewFontBold() {
    HFONT MyFont;
    if (Unicode == 1) {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
    }
    else {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
    }
    return MyFont;
}
HFONT LoadNewFontBold2() {
    HFONT MyFont;
    if (Unicode == 1) {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
    }
    else {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
    }
    return MyFont;
}
HFONT LoadNewFontBold3() {
    HFONT MyFont;
    if (Unicode == 1) {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
    }
    else {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
    }
    return MyFont;
}
HFONT LoadNewFontBold4() {
    HFONT MyFont;
    if (Unicode == 1) {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
    }
    else {
        MyFont = CreateFontA(gCustomCommonS6.FontHeight, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
    }
    return MyFont;
}
#define Instance ((int(__cdecl*)()) 0x00861110)
void Font::FontSizeLoad(int a1)
{
    DWORD* v2; // eax
    int result; // eax

    pWinFontHeight = a1;
    gCustomCommonS6.FontHeight = a1;

    LoadNewFont();
    LoadNewFont2();
    LoadNewFont3();
    LoadNewFont4();
    pFontBold = LoadNewFontBold();
    pFontNormal2 = LoadNewFontBold2();
    pFontBigBold = LoadNewFontBold3();
    pFontNormal = LoadNewFontBold4();



    v2 = (DWORD*)Instance();

    sub_830B70(v2[45], *v2, 1, 1);
    result = a1;
    if (gCustomCommonS6.FontHeight = a1) {
        switch (a1)
        {
        case 11:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 11", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 11", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 11", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 11", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 11", ".\\Settings.ini");

            break;
        case 12:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 12", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 12", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 12", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 12", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 12", ".\\Settings.ini");
            break;
        case 13:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 13", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 13", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 13", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 13", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 13", ".\\Settings.ini");
            break;
        case 14:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 14", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 14", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 14", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 14", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 14", ".\\Settings.ini");
            break;
        case 15:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 15", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 15", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 15", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 15", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 15", ".\\Settings.ini");
            break;
        case 16:
            WritePrivateProfileStringA("FontConfig", "FontSize1", " 16", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize2", " 16", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize3", " 16", ".\\Settings.ini");
            WritePrivateProfileStringA("FontConfig", "FontSize4", " 16", ".\\Settings.ini");
            result = WritePrivateProfileStringA("FontConfig", "FontSize5", " 16", ".\\Settings.ini");
            break;
        default:
            return;
        }
    }
    return;
}

void Font::Load() {
    GetPrivateProfileStringA("FontConfig", "FontName", "Tahoma", MyFontFaceName, 100, "./Settings.ini");

    SetCompleteHook(0xE8, Offset_CreateFontA1, &LoadNewFontBold);
    SetCompleteHook(0xE8, Offset_CreateFontA3, &LoadNewFontBold);
    SetCompleteHook(0xE8, Offset_CreateFontA4, &LoadNewFontBold);

    SetCompleteHook(0xE8, Offset_CreateFontA1, &LoadNewFontBold2);
    SetCompleteHook(0xE8, Offset_CreateFontA3, &LoadNewFontBold2);
    SetCompleteHook(0xE8, Offset_CreateFontA4, &LoadNewFontBold2);

    SetCompleteHook(0xE8, Offset_CreateFontA1, &LoadNewFontBold3);
    SetCompleteHook(0xE8, Offset_CreateFontA3, &LoadNewFontBold3);
    SetCompleteHook(0xE8, Offset_CreateFontA4, &LoadNewFontBold3);

    SetCompleteHook(0xE8, Offset_CreateFontA1, &LoadNewFontBold4);
    SetCompleteHook(0xE8, Offset_CreateFontA3, &LoadNewFontBold4);
    SetCompleteHook(0xE8, Offset_CreateFontA4, &LoadNewFontBold4);

    SetCompleteHook(0xE8, Offset_CreateFontA5, &Font::LoadNewFont);
    SetCompleteHook(0xE8, Offset_CreateFontA2, &Font::LoadNewFont);

    SetCompleteHook(0xE8, Offset_CreateFontA5, &Font::LoadNewFont2);
    SetCompleteHook(0xE8, Offset_CreateFontA2, &Font::LoadNewFont2);

    SetCompleteHook(0xE8, Offset_CreateFontA5, &Font::LoadNewFont3);
    SetCompleteHook(0xE8, Offset_CreateFontA2, &Font::LoadNewFont3);

    SetCompleteHook(0xE8, Offset_CreateFontA5, &Font::LoadNewFont4);
    SetCompleteHook(0xE8, Offset_CreateFontA2, &Font::LoadNewFont4);
    //--
    SetByte((Offset_CreateFontA1 + 5), 0x90);
    SetByte((Offset_CreateFontA2 + 5), 0x90);
    SetByte((Offset_CreateFontA3 + 5), 0x90);
    SetByte((Offset_CreateFontA4 + 5), 0x90);
    SetByte((Offset_CreateFontA5 + 5), 0x90);
}
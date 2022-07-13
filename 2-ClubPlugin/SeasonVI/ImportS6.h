#pragma once
// ----------------------------------------------------------------------------------------------

#include "pch.h"
// ----------------------------------------------------------------------------------------------

#include <gl\GL.h>
#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "Ws2_32.lib")

#define MODEL_HELPER            7827
#define ITEM_INTER                    1171
#define ITEM(x, y)                    ((x * 512) + y)
#define ITEM2(x, y)                    ((x * 512) + y + ITEM_INTER)

#define MAIN_SCREEN_STATE_S6 0x00E609E8
//--------------------------------------ITEM
#define HDK_ITEM_EFFECT_ALLOW 0x0057AD8D //0x0052B0E7
#define HDK_ITEM_EFFECT_NOT_ALLOW 0x0057B73B //0x0052B9E0
#define HDK_NEXT_ITEM_COLOR 0x0057AF2E //0x0052B150

// ----------------------------------------------------------------------------------------------
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define pCheckMouseOver				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define pFpsTime				0x0E8CB30
#define pDrawInterface2         ((void(__cdecl*)()) 0x00861110) //1.04D -> 0x00860FC0
#define oDrawInterface2_Call    0x0080F9AB //1.04D -> 0x0080F85B
#define pHelperMouseClick		((char(__thiscall*)(int a1)) 0x007D2920)
//-> Interface
#define pDrawInterfaceS			((char(__cdecl*)()) 0x004D7970)
#define oDrawInterfaceS_Call	0x004DA2AC
#define pDrawInterface			((void(__cdecl*)()) 0x0080F8E0)
#define oDrawInterface_Call		0x0080F7FE
#define pDrawGUI				((void(__cdecl*)(DWORD, float, float, float, float)) 0x00790B50)
#define pDrawToolTip			((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x00597220)
#define pDrawButton				((void(__cdecl*)(DWORD, float, float, float, float, float, float)) 0x00790E40)
#define pDrawColorButton		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)
#define pDrawExtraColor			((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, DWORD)) 0x637A60)
#define pDrawMapObject			((void(__cdecl*)(DWORD, float, float, float, float, float, float, float, float, float, float, float, float, DWORD)) 0x638400)
#define pDrawInfoBox			((char(__cdecl*)(char Text, int Arg2)) 0x00738200)
#define pMakeColor				((DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE)) 0x00412D20)
#define pTextFormat				((int(__cdecl*)(char * Buffer, int Arg2, int LineSize, LPCTSTR Text, int LineWidth, bool Arg6, BYTE Arg7)) 0x540880)
#define pDrawColorText			((int(__cdecl*)(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)) 0x7D04D0)
#define pDrawText				((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
#define pSetTextColor			((void(__thiscall*)(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)) 0x00420040)
#define pSetBlend				((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define pLoadImage				((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pDrawImage              ((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)
#define pLoadModel				((void(__cdecl*)(int ResourceID, char * Path, char * File, int Arg4)) 0x614D10)
#define pLoadTexture			((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x614710)
#define pInitModelData			((void(__cdecl*)()) 0x00617D30)
#define pInitModelData2			((void(__cdecl*)()) 0x00626190)
#define pInitTextureData		((void(__cdecl*)()) 0x0061AED0)
#define pLoadSomeForm			((void(__cdecl*)()) 0x007C2050)
#define oLoadSomeForm_Call		0x007C1D7E
#define pWindowThis				((LPVOID(*)()) 0x861110)
#define pCheckWindow			((bool(__thiscall*)(LPVOID This, int Code)) 0x0085EC20)
#define pCloseWindow			((int(__thiscall*)(LPVOID This, int Code)) 0x0085F9A0)
#define pOpenWindow				((int(__thiscall*)(LPVOID This, int Code)) 0x0085EC50)
#define pOpenInfoBox			((bool(__cdecl*)(LPVOID This, int Arg2, float Arg3)) 0x00790A10)
#define pCursorX				*(int*)0x879340C
#define pCursorY				*(int*)0x8793410
#define pWinWidth				*(GLsizei*)0x0E61E58
#define pWinHeight				*(GLsizei*)0x0E61E5C
#define pWinWidthReal			*(float*)0xE7C3D4
#define pWinHeightReal			*(float*)0xE7C3D8
#define pWinFontHeight			*(int*)0x81C0380
#define pTextLineThis			((LPVOID(*)()) 0x8128ADC)
//#define pGetTextLine			((LPCSTR(__thiscall*)(LPVOID This, int LineNumber)) 0x402320)
#define pDrawItemModel			((int(__cdecl*)(float PosX, float PosY, float Width, float Height, int ItemID, int a6, int a7, int a8, char a9)) 0x005CF310)
#define pSetCursorFocus			*(DWORD*)0xE8CB3C
#define pAllowGUI				((bool(__cdecl*)()) 0x007D4250)
#define oAllowGUI_Call1			0x007D378E
#define oAllowGUI_Call2			0x00811C42
#define pDrawBarForm			((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x6378A0)
#define pGLSwitchBlend			((void(__cdecl*)()) 0x636070)
#define pGLSwitch				((void(__cdecl*)()) 0x635F50)
#define pCharacterBuf			((int(__thiscall*)(void *This, int a2)) 0x0040FCA0)


#define Hero                    *(DWORD*)0x007BC4F04
//-- OpenGL
//#define EnableAlphaTest               ((void  (__cdecl*)(bool Mode)) 0x00635FD0)
#define DisableAlphaBlend             ((void  (__cdecl*)( )) 0x00635F50)
#define RenderItem3D                ((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
#define BeginBitmap                 ((void(*)()) 0x00637770)
#define EndBitmap                 ((void(*)()) 0x00637870)
#define CameraViewNear                *(float*)0xE61E38
#define CameraViewFar               *(float*)0xE61E3C
#define glViewport2                 ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define gluPerspective_2              ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x006358A0)
#define GetOpenGLMatrixF              ((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define EnableDepthTestF              ((void(*)()) 0x00635DE0)
#define EnableDepthMaskF              ((void(*)()) 0x00635E40)
#define CameraMatrixF               (LPVOID)0x87933A0
#define g_WindowWidth               0x00E61E58
#define g_WindowHeight                0x00E61E5C
#define g_fScreenRate_x               *(float*)0x00E7C3D4
#define g_fScreenRate_y               *(float*)0x00E7C3D8
//-- Pick Item
#define GetUI3D                   ((int   (__thiscall*)(int thisa))0x00861AA0)

// ----------------------------------------------------------------------------------------------

//-> User
#define pGetPosFromAngle		((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x635B00)
#define pPartyListStruct		*(PartyList*)0x81CB4E8
#define pGetPartyStruct(Slot)	((Slot * sizeof(PartyList)) + (*(char**)pPartyListStruct))
#define pPartyMemberCount		*(DWORD*)0x81F6B6C
#define pMapNumber				*(int*)0x0E61E18
#define pLastSkillIndex			*(DWORD*)0x81C039C
#define	pViewUnknownTargetID	*(int*)0xE61728		//item target
#define	pViewNPCTargetID		*(int*)0xE6172C
#define	pViewAttackTargetID		*(int*)0xE61730
#define pPreviewThis			((LPVOID(*)()) 0x402BC0)
#define pClearPreviewThis		((LPVOID(*)()) 0x82C5C80)
#define pClearPreview			((void(__thiscall*)(LPVOID This)) 0x4CC780)
#define pGetPreviewStruct		((DWORD(__thiscall*)(LPVOID This, int ViewportID)) 0x0096A4C0)
#define pPreviewCharSet			((void(__cdecl*)(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode)) 0x57FD90)
#define oUserPreviewStruct		*(int*)0x7BC4F04
#define oUserObjectStruct		*(int*)0x8128AC8
#define oUserObjectStruct_		*(int*)0x8128AC4
#define pMasterLevel			*(short*)0x87935D8
#define pMasterPoint			*(short*)0x87935F2
#define pMasterExp				*(__int64*)0x87935E0
#define pMasterNextExp			*(__int64*)0x87935E8
#define pFrameValue1			*(BYTE*)(0x004D9F02 + 2)
#define pFrameValue2			*(DWORD*)(0x004DA3B2 + 1)
#define pFrameValue3			*(DWORD*)(0x004DA3DD + 3)
#define pFrameValue4			*(BYTE*)(0x004DA3AC + 3)
#define pPlayerState			*(int*)0x0E609E8
#define pFrameLimit				0//need check value inside struct
#define oBattleMapStart			0x0083165E
#define oBattleZoneStart		0x005D3043
#define pMaxBattleZoneCount		*(BYTE*)(0x005D3078 + 3)
#define oIsBattleServer_Call1	0x005D303A
#define oIsBattleServer_Call2	0x00831651
#define pIsMaster				((bool(__cdecl*)(BYTE Class)) 0x5878E0)
#define pIsMaster2				((bool(__cdecl*)(BYTE Class)) 0x5875A0)
#define pGetCharClass			((BYTE(__cdecl*)(BYTE Class)) 0x405230)
#define pInitEventStatus		((void(__cdecl*)(int PreviewStruct)) 0x4EFF70)
#define pEventEffectThis		((LPVOID(__cdecl*)(int Arg1)) 0x9D00C5)
#define pAddEventEffect			((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, bool bFixRotation, float a5, float a6, float a7, float a8, float a9, float a10)) 0x4EFFF0)
#define pAddEventEffect2		((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, int a4, float a5, float a6, float a7)) 0x4F0730)
#define pPShopThis1				((LPVOID(__cdecl*)()) 0x861110)
#define pPShopThis2				((LPVOID(__thiscall*)(LPVOID This)) 0x861400)
#define pPShopSet				((void(__thiscall*)(LPVOID This, BYTE Mode)) 0x840F70)
#define pPShopRefresh			((void(__cdecl*)(int Preview)) 0x6685B0)
#define pMUHelperThis			((LPVOID(__cdecl*)()) 0x4DB240)
#define pMUHelperClass			*(int*)0xE8CB7C
#define pMUHelperClose			((void(__thiscall*)(LPVOID This)) 0x95D450)
#define pMUHelperStart			((void(__thiscall*)(LPVOID This)) 0x95D190)
#define pMUHelperDataSet		((bool(__thiscall*)(LPVOID This, LPBYTE Data)) 0x960C10)
#define pMUIsLoaded				*(DWORD*)0xE60974
#define pWarehouseClass			((int(__cdecl*)()) 0x860FC0)
#define pWarehouseExThis		((int(__thiscall*)(LPVOID This)) 0x861A80)
#define pWarehouseExSet			((void(__thiscall*)(int Pointer, BYTE Status)) 0x856BD0)
#define pGameShopThis			((LPVOID(*)()) 0x93F370)
#define pGameShopGetGP			((double(__thiscall*)(LPVOID This)) 0x9405B0)
#define pUserStat				((LPVOID(*)()) 0x588D70)
#define pUpdateUserStat			((void(__thiscall*)(LPVOID This, int * Value, int Code)) 0x4EA460)
#define pIsButtonPressed		((int(__thiscall*)(int ButtonNumber)) 0x791070)
//--
#define oUserTextObject			*(int*)0x8128AC0 //ITEM.BMD -- CustomPets
#define pGetTextLine_			((char*(__thiscall*)(LPVOID This, int LineNumber)) 0x402320) //CustomPets
// ----------------------------------------------------------------------------------------------

//-> Other
#define oCam_Zoom				0x0D27BFC	//1037DB0
#define oCam_PosZDef			0x0D255AC	// Restore PosZ
#define oCam_PosZ				0x0D255A0	// PosZ
#define oCam_RotZ				0x87933D8	//8B4ACC8
#define oCam_RotZDef			0x0D27B78	//1033AB0
#define oCam_RotY				0x0D27B88	//1033AC0
#define oCam_ClipX				0x0D2C848	//1038D28
#define oCam_ClipY				0x0D2C894	//1033A78
#define oCam_ClipZ				0x0D2C8B8	//1038D78
#define oCam_ClipXCS			0x0D2C898	//1038D58
#define oCam_ClipYCS			0x0D2C8A8	//1038D68
#define oCam_ClipX2				0x0D2C878	//1038D38
#define oCam_ClipY2				0x0D2C880	//1038D40
#define oCam_ClipZ2				0x0D2B94C	//1037DA4
#define oCam_ClipGL				0x0D2570C	//1031BCC
//
#define oCharColor_Loot			(0x0064B6AB + 1)
#define oCharColor_Exp			(0x0064C9A0 + 1)
#define pGetMoneyFormat			((int(__cdecl*)(double Value, char * Buff, int Arg3)) 0x5C1170)
#define pPlayEffectAnimation	((int(__cdecl*)(int EffectIndex, int PreviewStruct)) 0x667130)
#define oVulcanusMove			(0x00831BAC + 2)
#define oShowChatMessage_Call	0x0078B0BC
#define pShowChatMessage		((bool(__thiscall*)(LPVOID This)) 0x00788A80)
#define pSetChatMessageType		((int(__thiscall*)(LPVOID This, int Type)) 0x0078B870)
#define pGetChatMessageType		((int(__thiscall*)(LPVOID This)) 0x0078B870)
#define pChatThis				((LPVOID(__thiscall*)(LPVOID This)) 0x861220)
#define pChatIsClosed			((bool(__thiscall*)(LPVOID This)) 0x786110)
#define pChatCheckLevel			((bool(__cdecl*)(int MinLevel, char * Name)) 0x597E10)
#define pChatWhisperThis		((LPVOID(__thiscall*)(LPVOID This)) 0x861620)
#define pChatWhisperActive		((bool(__thiscall*)(LPVOID This)) 0x849E00)
#define pChatReserveLine		((DWORD(__cdecl*)(DWORD Arg1, DWORD Arg2, DWORD Arg3)) 0x6D6C20)
#define pChatBoxThis			((DWORD(__thiscall*)(LPVOID This)) 0x861180)
#define pChatOutput				((void(__thiscall*)(DWORD This, char * Name, char * Message, DWORD Type, DWORD Arg4)) 0x007894E0)
#define pGetCommandLine			((LPSTR(WINAPI*)()) 0x00D221C8)
#define pFrameSpeed1			*(double*)0x0D27C88
#define	pFrameSpeed2			*(double*)0x0D281C0
#define pIsDisconnect			*(int*)0xE82C24
#define pCreateConnect			((int(__cdecl*)(char * IP, WORD Port)) 0x0063C960)
#define pOnLine					*(DWORD*)0x8793704
#define pMenuExitEvent			((DWORD(__cdecl*)(int Arg1)) 0x7A89D0)
#define pGameWindow				*(HWND*)0x0E8C578
#define pGetMapName				((char*(__cdecl*)(int MapNumber)) 0x5D2C10)
#define pMUCommandLine			(char*)0x0E8C274
#define pGameLoad				((int(__cdecl*)()) 0x004D0FC0)
#define pGameResolutionMode		*(int*)0x0E8C240
#define pMoveListInit			((void(__thiscall*)(LPVOID This, int Arg1, int Arg2)) 0x830C10)
#define pTexEffect                              ((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0) //0x004E2E70
#define pCustomEffGet                   ((int(__thiscall*)(int This, int a2, int *a3, MU3Float *a4, char a5)) 0x00545030) //0x004E171E
#define pCustomEffect                   ((int(__cdecl*)(int a1, MU3Float *a2, float a3,int *Color, int a5, int a6, int a7)) 0x771310) //0x006EC452
#define pCustomEffGet2                  ((int(__thiscall*)(int This, int a2, float a3,int a4,float a5,float a6, float a7, int a8,int a9)) 0x005494C0) //0x004E597C
#define pTextLineThis			((LPVOID(*)()) 0x8128ADC)
#define pGetTextLine			((char*(__thiscall*)(LPVOID This, int LineNumber)) 0x402320)
#define pMapName				((char*(__cdecl*)(signed int mapNumber)) 0x5D2C10)
// ----------------------------------------------------------------------------------------------

//-> Item
#define pGetItemColor			((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5F8C50)
#define pGetItemColor2			((void(__cdecl*)(int ModelID, float Arg2, float Arg3, VAngle * Color, bool BalrogMode)) 0x5FA4A0)
#define pSetItemPrice           ((__int64(__cdecl*)(ObjectItem * lpItem, int Mode)) 0x58E3B0)
#define pIsExpensiveItem		((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C81F0)
#define pIsUpgradeItem			((bool(__thiscall*)(LPVOID This, ObjectItem * lpSource, ObjectItem * lpTarget)) 0x7DDAC0)
#define pAllowRepairWings		((bool(__cdecl*)(ObjectItem * lpItem)) 0x5C9DA0)
#define pSetItemOption			((void(__cdecl*)(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x58B910)
#define pSetItemOptionText		((void(__cdecl*)(int ItemID, int Line, WORD OptionID, bool Arg4, int Arg5)) 0x5C2F70)
#define pSetItemTextLine		((void(__cdecl*)(int Line, LPSTR Text, ...)) 0x9CF6AA)
#define pIsWings				((int(__thiscall*)(LPVOID This, DWORD ItemID)) 0x7E7870)
#define pSetItemEffect			((void(__cdecl*)(int Arg1, int ModelID, VAngle Angle, int Arg4, int ItemLevel, char Arg6, int Arg7, int Arg8, int Arg9)) 0x609E70)
#define pSetItemEffect2			((void(__cdecl*)(float a4, float a5, float a6, lpViewObj Object, float a8, DWORD ModelID, int a10, char a11, char a12, char a13, signed int a14, char a15)) 0x5655C0)
#define pGetMaxDurability		((short(__cdecl*)(ObjectItem * lpItem, int ScriptStruct, int Level)) 0x5C2170)
#define pIsFlyingMauntToMove	((bool(__thiscall*)(LPVOID This, WORD ItemID1, WORD ItemID2)) 0x831B09)
#define pAllowStaticEffect		((void(__thiscall*)(LPVOID This, DWORD * Arg1, DWORD Arg2, int Arg3, int Arg4)) 0x544E60)
#define pPlayStaticEffect		((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, float Scale, float * Color, int Model, float a6, int a7)) 0x771310)
#define pPlayDynamicEffect		((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, int Arg2, float * Color, int Arg4, float Arg5, int Arg6)) 0x74CD30)
#define SetTextColorByHDC            ((int(__thiscall*)(LPVOID a1, int color)) 0x00420080)

#define pItemBmdStruct			*(ItemBmdStruct*)0x8128AC0
#define pGetItemBmdStruct(ItemId)	(ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct) * ItemId)

#define sub_636720_Addr ((int(*)())0x636720)
#define sub_6363D0_Addr ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x6363D0)
#define sub_6358A0_Addr ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x6358A0)
#define sub_635830_Addr ((void(__cdecl*)(LPVOID a1)) 0x635830)
#define sub_635DE0_Addr ((void(*)()) 0x635DE0)
#define sub_635E40_Addr ((void(*)()) 0x635E40) 
#define sub_637770_Addr ((void(*)()) 0x637770)
#define sub_6359B0_Addr ((int(__cdecl*)(int a1, int a2, int a3, char a4)) 0x006359B0)

#define pTest					((float(__cdecl*)(double))0x009CEBF0)

#define sub_5CA0D0_Addr		((void(__cdecl*)(signed int a1, signed int a2, int a3, int a4, int a5, int a6, char a7)) 0x5CA0D0)

// ----------------------------------------------------------------------------------------------
#define pGetAttackSpeed			((void(__thiscall*)()) 0x593B20)
#define Main_PrintGlobal 00597630H

#define pPetCall1				((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x5013B0)
#define pPetCall2				((LPVOID(__cdecl*)(int ID, int PetStruct, int PetObjectView, int Mode, int arg5)) 0x501700)
#define oItemText_Color			0x81C0A68
#define oItemText_Weight		0x81C09F0
#define oItemText_Line			0x81C0AE0
#define oItemText_Index			0x81F6BF0
#define	oItemText_Add			0x9CF6AA

#define oItemTitleColor			0x005C8261
#define oItemTitleColor_Next	(oItemTitleColor+8)
#define oItemTitleColor_Set		0x005A9C00

#define oItemDescriptionText		0x005AE921
#define oItemDescriptionText_Next	0x005AE96C

#define pChatStructure			0x8129540
#define pFpsTime				0x0E8CB30

// custom efectos
#define CreateEffect2				((int(__cdecl*)(int a4, vec3_t Bone1, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)
#define BeginRender					((void(__thiscall*)(float a2)) 0x00546860)
#define RenderMesh					((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
#define EndRender					((void(__cdecl*)()) 0x00546880)
#define TransformPosition			((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define Joint(x)					((0x30 * x) + 0x007BC08A0)
#define CreateSprite				((int(__cdecl*)(int a1, vec3_t Bone1, float size, vec3_t color, int ObjPos, float, int)) 0x00771310)
#define CreateParticle				((int(__cdecl*)(int a1, int a2, int a3, vec3_t color, int a5, float a6, int a7)) 0x0074CD30)
#define CreateParticle2				((int(__cdecl*)(int a1, vec3_t Bone1, int a3, vec3_t color, int a5, float size, int a7)) 0x0074CD30)
#define BoneTransform				*(int*)0x007BC09C0
#define RenderInfomationR			((int(*)()) 0x004D5EC0)
//--
#define pGLSupremo					((void(__cdecl*)())0x00637A30)
#define LoadBitmapA					((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define PlayBuffer					((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define pChaosBoxState				*(BYTE*)(*(DWORD*)(0x98670C4) + 0xC8)
//--
#define pCheckEffectPlayer			((bool(__thiscall*)(void * This,char a2)) 0x004C8640)
#define GetBoneTransform			((int(__thiscall*)(int This, signed int a2)) 0x004CD7F0)
#define ppMousePress				((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define pCheckMouseOver				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)

//-> Monster
#define oNpcName				0x8119F68
#define pSendChatSay			((int(__cdecl*)(char * Name, char * Text, lpViewObj lpObject, int a4, int a5)) 0x5996A0)
#define pShowMonster			((lpViewObj(__cdecl*)(int MonsterID, int a2, int a3, int a4)) 0x580FC0)


#define sub_596AC0   ((void(__thiscall*)(int a1)) 0x00596AC0) //1
#define sub_482B70          ((int(*)()) 0x00482B70)
#define sub_407B20			((int(*)()) 0x00407B20)
#define sub_785870			((void(__thiscall*)(DWORD , int a2, int a3, int a4, int a5)) 0x00785870)
#define sub_861AC0          ((int(__thiscall*) (DWORD)) 0x00861AC0)
#define sub_7F0D40          ((void(__thiscall*) (DWORD)) 0x007F0D40)
#define sub_7F0C80			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x007F0C80)
#define sub_830B70			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x00830B70)
#define dword_81C0380                *(DWORD*)0x81C0380
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594

//-- Control Text
#define pMakeColor					((DWORD(__cdecl*)(BYTE, BYTE, BYTE, BYTE)) 0x00412D20)
#define pTextThis					((LPVOID(*)()) 0x0041FE10)
#define pSetBackgroundTextColor		((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x004200B0)
//-- Control Interface
#define CryingWolf2ndObjectVisual	((void(__cdecl*)(int a1, int a2)) 0x008D1C00)
#define RenderBitmap				((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)) 0x00637C60)
#define EnableAlphaBlend			((void(__cdecl*)()) 0x00636070)
#define EnableAlphaTest				((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
// offset
#define sub_4200F0_Addr				((int(__thiscall*)(LPVOID a1, int a2)) 0x004200F0)

//-- Sombra en pet
#define sub_4DB250					((int(__cdecl*)()) 0x004DB250)
#define sub_4E44A0					((bool(__thiscall*)(int This)) 0x004E44A0)
#define ShadowMaster					((void(__thiscall*)(int JCModel, int a2, int JCLayer, int JCLayerMin, int JCLayerMax)) 0x0054A270)
#define pCheckMap					((bool(__cdecl*)(signed int a1))0x004DB1C0)
#define sub_6D8980					((char(__cdecl*)(int a1, int a2, int a3))0x006D8980)
#define sub_6D6C20					((signed int(__cdecl*)(int a1, int a2, int a3))0x006D6C20)
#define sub_4C8AB0					((int(__thiscall*)(int This, char a2))0x004C8AB0)
#define pRenderRand					((int(*)()) 0x009CFB8D)
#define SetBoundInputField			((int(__thiscall*)(int a1, int a2, int a3)) 0x00417EC0)
//--
#define RenderBitMapColored ((void(__cdecl*)(int a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, int a13))0x00790DF0)








//Cloak
#define pModelThis					((LPVOID(*)())0x004CDA10)
#define pGetModel					((LPVOID(__thiscall*)(LPVOID This, signed int a2)) 0x00969C50)
#define pPlayStaticEffect1			((int(__cdecl*)(int ModelID, vec3_t Bone1, float size, vec3_t Color, int ObjPos, float, int)) 0x771310)

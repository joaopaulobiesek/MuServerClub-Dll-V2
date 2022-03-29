#pragma once

#include "pch.h"

#define MAX_OBJECT			250
#define MAX_WIN_WIDTH		640
#define MAX_WIN_HEIGHT		480

#define pDrawImage              ((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)
#define pGetPosFromAngle		((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x635B00)
#define pDrawToolTip			((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x00597220)
#define pDrawColorText			((int(__cdecl*)(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)) 0x7D04D0)
#define pLoadImage				((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pDrawGUI				((void(__cdecl*)(DWORD, float, float, float, float)) 0x00790B50)
#define pDrawColorButton		((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x00790F20)
#define pCheckWindow			((bool(__thiscall*)(LPVOID This, int Code)) 0x0085EC20)
#define pCloseWindow			((int(__thiscall*)(LPVOID This, int Code)) 0x0085F9A0)
#define pOpenWindow				((int(__thiscall*)(LPVOID This, int Code)) 0x0085EC50)
#define pPreviewThis			((LPVOID(*)()) 0x402BC0)
#define pGetPreviewStruct		((DWORD(__thiscall*)(LPVOID This, int ViewportID)) 0x0096A4C0)
#define pWindowThis				((LPVOID(*)()) 0x861110)
#define oLoadSomeForm_Call		0x007C1D7E
#define pSetCursorFocus			*(DWORD*)0xE8CB3C
#define pCursorX				*(int*)0x879340C
#define pCursorY				*(int*)0x8793410
#define	pViewNPCTargetID		*(int*)0xE6172C
#define	pViewAttackTargetID		*(int*)0xE61730
#define pInitEventStatus		((void(__cdecl*)(int PreviewStruct)) 0x4EFF70)
#define pEventEffectThis		((LPVOID(__cdecl*)(int Arg1)) 0x9D00C5)
#define pAddEventEffect			((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, bool bFixRotation, float a5, float a6, float a7, float a8, float a9, float a10)) 0x4EFFF0)
#define pAddEventEffect2		((LPVOID(__thiscall*)(LPVOID This, int ModelID, int a3, int a4, float a5, float a6, float a7)) 0x4F0730)

enum ObjectID
{
	eFlag01 = 1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_CLOSE,
	eMenu,
	eMenuBG,
	eMenu_MAIN,
	eMenu_TITLE,
	eMenu_FRAME,
	eMenu_FOOTER,
	eMenu_DIV,
	eMenu_CLOSE,
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT20,
	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,

	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,

	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,

	eNextCommand,
	ePrevCommand,

	eNextEvent,
	ePrevEvent,
	eNewInterfaceParty,
	eNewInterfaceCharacter,
	eNewInterfaceInventory,
};

struct InterfaceObject
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
};

class Interface
{
public:
	Interface();
	virtual ~Interface();
public:

	void		Load();
	static void	LoadImages();
	static void	LoadModels();
	static void	Work();

	int teste;

	void		BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void		DrawGUI(short ObjectID, float PosX, float PosY);
	int			DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);

	bool		CheckWindow(int WindowID);
	int			CloseWindow(int WindowID);
	int			OpenWindow(int WindowID);

	bool		IsWorkZone(short ObjectID);
	void		ResetDrawIMG(short ObjectID);
	int			DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float		DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	void		DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void		CloseMenuWindow() { this->Data[eMenu_MAIN].OnShow = false; pSetCursorFocus = false; };


	void		CloseCustomWindow();

	//Mini Map
	void		DrawMiniMap();
	bool		MiniMapCheck();
	bool		CombinedChecks();
	bool		CheckMap();

	int			ConfirmSlot;
	InterfaceObject Data[MAX_OBJECT];

	int			MiniMap;
private:

};
extern Interface gInterface;

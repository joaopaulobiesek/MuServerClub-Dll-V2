#pragma once

struct CAMERA_OFFSET_S1702
{
	float* RotX;
	float* RotY;
	double* PosZ;
	float* Zoom1;
	float* Zoom2;
	float* Zoom3;
	float* Zoom4;
	float* Zoom5;
	float* Zoom6;
	DWORD* ZoomByte;
	BYTE* ArenaCam;
};

struct CAMERA_START_S1702
{
	float Calc;
	DWORD Active;
};

struct CAMERA_INFO_S1702
{
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
};

void Zoom2S1702();

class CCamera3dS1702
{
public:
	CCamera3dS1702();
	virtual ~CCamera3dS1702();
	void Init();
	void Zoom(MOUSEHOOKSTRUCTEX* lpMouse);
	void Move(MOUSEHOOKSTRUCTEX* lpMouse);
	void AutoMove(MOUSEHOOKSTRUCTEX* lpMouse);
	void SetIsMove(BOOL IsMove);
	void SetIsAutoMove(BOOL IsMove);
	void SetCursor(LONG CursorX, LONG CursorY);
	void InitKB(int Parameter);
	void ThreadCamS17();
public:
	CAMERA_OFFSET_S1702 m_OffSet;
	CAMERA_START_S1702 m_Start;
	CAMERA_INFO_S1702 m_Default;
	BOOL m_IsMove;
	BOOL m_IsAutoMove;
	LONG m_CursorX;
	LONG m_CursorY;
	int actualz;
	int width;
	int height;
	int midwidth;
	int midheight;
	int rangewidth;
	int rangeheight;
	int PosX;
	int PosY;
	int PosXC;
	int PosYC;
	int ActiveCamDelay;
	//Novo
	float MinPercent;
	float MaxPercent;
	float MinLimit;
	float MaxLimit;
	float Precision;
};

extern CCamera3dS1702 gCamera3dS1702;
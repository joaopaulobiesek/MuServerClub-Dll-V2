#pragma once

struct CAMERA_OFFSET_S17
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

struct CAMERA_START_S17
{
	float Calc;
	DWORD Active;
};

struct CAMERA_INFO_S17
{
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
};

void Zoom2S17();

class CCamera3dS17
{
public:
	CCamera3dS17();
	virtual ~CCamera3dS17();
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
	CAMERA_OFFSET_S17 m_OffSet;
	CAMERA_START_S17 m_Start;
	CAMERA_INFO_S17 m_Default;
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

extern CCamera3dS17 gCamera3dS17;
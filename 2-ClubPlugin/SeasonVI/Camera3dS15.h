#pragma once

struct CAMERA_OFFSET_S15
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

struct CAMERA_START_S15
{
	float Calc;
	DWORD Active;
};

struct CAMERA_INFO_S15
{
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
};

void Zoom2S15();

class CCamera3dS15
{
public:
	CCamera3dS15();
	virtual ~CCamera3dS15();
	void Init();
	void Zoom(MOUSEHOOKSTRUCTEX* lpMouse);
	void Move(MOUSEHOOKSTRUCTEX* lpMouse);
	void AutoMove(MOUSEHOOKSTRUCTEX* lpMouse);
	void SetIsMove(BOOL IsMove);
	void SetIsAutoMove(BOOL IsMove);
	void SetCursor(LONG CursorX, LONG CursorY);
	void InitKB(int Parameter);
	void ThreadCamS15();
public:
	CAMERA_OFFSET_S15 m_OffSet;
	CAMERA_START_S15 m_Start;
	CAMERA_INFO_S15 m_Default;
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

extern CCamera3dS15 gCamera3dS15;
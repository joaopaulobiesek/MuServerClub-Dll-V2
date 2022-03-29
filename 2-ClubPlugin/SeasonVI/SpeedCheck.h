#pragma once

struct SPEED_MAIN
{
	int Map;
	int X;
	int Y;
};

class CSpeed
{
public:
	CSpeed();
	void CheckLimit(int Map, int X, int Y);
public:
	SPEED_MAIN m_SpeedMain;
	int LimitMoviment;
	int ToleranceLimit;
	int TimeToleranceLimit;
	int CHeckSpeed;
};

extern CSpeed gSpeed;

#pragma once

struct CLOCK_MAIN
{
	DWORD DateHour;
	DWORD DateMinute;
	DWORD DateSecond;
	DWORD DateDay;
	DWORD DateMonth;
	DWORD DateYear;
};

class CClock
{
public:
	CClock();
public:
	int StartClock;
	CLOCK_MAIN m_ClockMain;
};

extern CClock gClock;

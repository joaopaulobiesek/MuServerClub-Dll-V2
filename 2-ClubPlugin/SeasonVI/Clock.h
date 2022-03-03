#pragma once

struct CLOCK_MAIN
{
	DWORD DateHour;
	DWORD DateMinute;
	DWORD DateSecond;
};

class CClock
{
public:
	CClock();
public:
	CLOCK_MAIN m_ClockMain;
};

extern CClock gClock;

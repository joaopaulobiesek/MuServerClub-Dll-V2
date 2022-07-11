#pragma once

#define MAX_EVENT_LIST 20

struct EVENTLIST_DATA
{
	int Id;
	char NameEvent[25];
	int TimeEvent;
};

class CGetSync
{
public:
	CGetSync();
	virtual ~CGetSync();
	void CheckSync();
	void Scan();
	void ResetTimeLeft();
	int ConvertDateToTimeStamp(int year, int month, int day, int hour, int min, int sec);
public:
	EVENTLIST_DATA gCustomEventListInfo[MAX_EVENT_LIST];
private:
	int dow;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int result;
};

extern CGetSync gGetSync;
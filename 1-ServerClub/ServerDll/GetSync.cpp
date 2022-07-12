#include "pch.h"

CGetSync gGetSync;

CGetSync::CGetSync() // OK
{
}

CGetSync::~CGetSync() // OK
{
}

int CGetSync::ConvertDateToTimeStamp(int year, int month, int day, int hour, int min, int sec) // OK
{
	time_t rawtime;

	struct tm* timeinfo;

	time(&rawtime);

	timeinfo = localtime(&rawtime);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	timeinfo->tm_hour = hour;
	timeinfo->tm_min = min;
	timeinfo->tm_sec = sec;

	return (int)mktime(timeinfo);
}

void CGetSync::ResetTimeLeft()
{
	for (int i = 0; i < MAX_EVENT_LIST; i++)
	{
		this->gCustomEventListInfo[i].Id = -1;
		this->gCustomEventListInfo[i].TimeEvent = 99999999;
	}
}

void CGetSync::Scan()
{
	SYSTEMTIME st;

	this->ResetTimeLeft();

	for (std::vector<EVENTNAME_DATA>::iterator itN = gReadFiles.gCustomEVENTListNameInfo.begin(); itN != gReadFiles.gCustomEVENTListNameInfo.end(); itN++)
	{
		for (std::vector<EVENTNAME_HOUR_DATA>::iterator itH = gReadFiles.gCustomEVENTListHourInfo.begin(); itH != gReadFiles.gCustomEVENTListHourInfo.end(); itH++)
		{
			if (itN->Id == itH->Id)
			{
				GetLocalTime(&st);

				this->dow = (itH->DoW == -1) ? st.wDayOfWeek : itH->DoW;

				this->year = (itH->Year == -1) ? st.wYear : itH->Year;

				this->month = (itH->Month == -1) ? st.wMonth : itH->Month;

				this->day = (itH->Day == -1) ? st.wDay : itH->Day;

				this->hour = (itH->Hour == -1) ? st.wHour : itH->Hour;

				this->minute = (itH->Minute == -1) ? st.wMinute : itH->Minute;

				this->second = (itH->Second == -1) ? st.wSecond : itH->Second;

				this->result = this->ConvertDateToTimeStamp(this->year, this->month, this->day, this->hour, this->minute, this->second) - this->ConvertDateToTimeStamp(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

				if (this->result < 0 && itH->Day == -1 && itH->DoW == -1)
				{
					this->result = this->result + 86400;
				}

				if (this->result > 0 && (this->gCustomEventListInfo[itN->Id].Id == -1 || this->gCustomEventListInfo[itN->Id].TimeEvent > this->result))
				{
					this->gCustomEventListInfo[itN->Id].Id = itN->Id;
					this->gCustomEventListInfo[itN->Id].TimeEvent = this->result;
					sprintf(this->gCustomEventListInfo[itN->Id].NameEvent, itN->Name);
				}
			}
		}
	}
}

void CGetSync::CheckSync() // OK
{
	SYSTEMTIME st;

	for (std::vector<EVENTNAME_DATA>::iterator itN = gReadFiles.gCustomEVENTListNameInfo.begin(); itN != gReadFiles.gCustomEVENTListNameInfo.end(); itN++)
	{
		for (std::vector<EVENTNAME_HOUR_DATA>::iterator itH = gReadFiles.gCustomEVENTListHourInfo.begin(); itH != gReadFiles.gCustomEVENTListHourInfo.end(); itH++)
		{
			if (itN->Id == itH->Id)
			{
				GetLocalTime(&st);
				if (itH->DoW == -1 || itH->DoW == st.wDayOfWeek)
				{
					if (itH->Day == -1 || itH->Day == st.wDay)
					{
						if (itH->Month == -1 || itH->Month == st.wMonth)
						{
							if (itH->Year == -1 || itH->Year == st.wYear)
							{
								if (itH->Hour == st.wHour)
								{
									if (itH->Minute == st.wMinute)
									{
										if (itH->Second == st.wSecond)
										{
											LogAdd(LOG_BLUE, "[%s] %d:%d:%d - %d/%d/%d - DayOfWeek: %d", itN->Name, st.wHour, st.wMinute, st.wSecond, st.wDay, st.wMonth, st.wYear, st.wDayOfWeek);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
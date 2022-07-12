#pragma once

#define MAX_EVENT_LIST 20

struct EVENTLIST_DATA
{
    int Id;
    char NameEvent[25];
    int TimeEvent;
};

class CCustomEventTimeDraw
{
public:
    CCustomEventTimeDraw();
    void ResetTimeLeft();
    void DrawEventTimePanelWindow();
    bool EventEventTimeWindow_Close(DWORD Event);
    void OpenWindow();
    bool EventNext(DWORD Event);
    bool EventPrev(DWORD Event);
    void SortEvents();
    void UpdateEventsTime();
public:
    EVENTLIST_DATA gCustomEventListInfo[MAX_EVENT_LIST];

private:
    int count;
    int EventTimeLoad;
    int EventTimeEnable;
    int EventTimeTickCount;
    int Page;
    int Arena;

};
extern CCustomEventTimeDraw gCustomEventTimeDraw;
#include "pch.h"

CCustomEventTimeDraw::CCustomEventTimeDraw()
{
}

CCustomEventTimeDraw gCustomEventTimeDraw;

void CCustomEventTimeDraw::ResetTimeLeft()
{
	for (int i = 0; i < MAX_EVENT_LIST; i++)
	{
		this->gCustomEventListInfo[i].Id = -1;
		this->gCustomEventListInfo[i].TimeEvent = 99999999;
	}
	this->count = 0;
	this->EventTimeEnable = 0;
}

int NextEvent = 0;
int PreventEvent = 0;

void CCustomEventTimeDraw::DrawEventTimePanelWindow()
{
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 240.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	gCustomOptionS6.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.DrawGUI(eEventTime_CLOSE, StartX + MainWidth - 22, 80);

	if (gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eEventTime_CLOSE, gInterface.Data[eEventTime_CLOSE].X, gInterface.Data[eEventTime_CLOSE].Y, Color);
	}

	DWORD Color = eGray100;

	if ((this->Page == 0) || (this->Page == 1 && this->Arena == 1))
	{
		gInterface.DrawGUI(eNextEvent, StartX + MainWidth - 38, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(eNextEvent);
	}

	if (this->Page == 1 || this->Page == 2)
	{
		gInterface.DrawGUI(ePrevEvent, StartX + 10, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(ePrevEvent);
	}

	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 15, 210, 3, "Server Events");

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor


	if (this->EventTimeEnable == 1)
	{

		gInterface.DrawFormat(eGold, StartX + 60, StartBody + 47, 52, 1, "Event:");

		gInterface.DrawFormat(eGold, StartX + 108, StartBody + 47, 52, 1, "Time:");

		if ((GetTickCount() - this->EventTimeTickCount) > 1000)
		{
			for (int i = 0; i < this->count; i++)
			{
				if (this->gCustomEventListInfo[i].TimeEvent > 0)
				{
					this->gCustomEventListInfo[i].TimeEvent = this->gCustomEventListInfo[i].TimeEvent - 1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		this->SortEvents();

		char text1[20];
		char text2[30];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;

		int line = 0;



		for (int i = (12 * Page) + 0; i < (12 * Page) + 12; i++)
		{
			if (this->gCustomEventListInfo[i].Id == -1 || i >= MAX_EVENT_LIST)
			{
				continue;
			}
			if (this->gCustomEventListInfo[i].TimeEvent <= -1)
			{
				continue;
			}
			else if (this->gCustomEventListInfo[i].TimeEvent == 0)
			{
				sprintf(text2, "Online");
			}
			else
			{
				totalseconds = this->gCustomEventListInfo[i].TimeEvent;
				hours = totalseconds / 3600;
				minutes = (totalseconds / 60) % 60;
				seconds = totalseconds % 60;
				sprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours / 24;
					sprintf(text2, "%d day(s)+", days);
				}
				else
				{
					sprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}

			if (this->gCustomEventListInfo[i].TimeEvent <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventListInfo[i].TimeEvent == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventListInfo[i].TimeEvent < 300)
			{
				Color = eExcellent;
			}
			else
			{
				Color = eYellow;
			}

			gInterface.DrawFormat(eWhite, StartX + 40, StartBody + 65 + (line), 70, 1, this->gCustomEventListInfo[i].NameEvent);

			gInterface.DrawFormat(Color, StartX + 108, StartBody + 65 + (line), 52, 1, text2);

			line += 12;
		}
		this->UpdateEventsTime();
	}
	else
	{
		if (this->EventTimeLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, "Loading ..");
			this->EventTimeLoad = 2;
		}
		else if (this->EventTimeLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, "Loading ...");
			this->EventTimeLoad = 3;
		}
		else if (this->EventTimeLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, "Loading ....");
			this->EventTimeLoad = 4;
		}
		else if (this->EventTimeLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, "Loading .....");
			this->EventTimeLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartBody + 120, 52, 1, "Loading .");
			this->EventTimeLoad = 1;
		}
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 210, 200, 1); //-- Divisor

}

void CCustomEventTimeDraw::SortEvents()
{
	//sorting - ASCENDING ORDER
	int i, j, tempIndex, tempTime, tempValue;
	char tempName[30];
	char tempLink[100];

	for (int i = 0; i < MAX_EVENT_LIST; i++)
	{
		for (int j = i + 1; j < MAX_EVENT_LIST; j++)
		{
			if (this->gCustomEventListInfo[i].TimeEvent != -1 && this->gCustomEventListInfo[j].TimeEvent != -1 && this->gCustomEventListInfo[i].TimeEvent > this->gCustomEventListInfo[j].TimeEvent)
			{
				/// CUSTOM_EVENT temp = this->gCustomEventTimeDraw[i];
				tempIndex = this->gCustomEventListInfo[i].Id;
				tempTime = this->gCustomEventListInfo[i].TimeEvent;
				strcpy(tempName, this->gCustomEventListInfo[i].NameEvent);
				/// this->gCustomEventTimeDraw[i] = this->gCustomEventTimeDraw[j];
				this->gCustomEventListInfo[i].Id = this->gCustomEventListInfo[j].Id;
				this->gCustomEventListInfo[i].TimeEvent = this->gCustomEventListInfo[j].TimeEvent;
				strcpy(gCustomEventListInfo[i].NameEvent, this->gCustomEventListInfo[j].NameEvent);
				///this->gCustomEventTimeDraw[j] = temp;
				this->gCustomEventListInfo[j].Id = tempIndex;
				this->gCustomEventListInfo[j].TimeEvent = tempTime;
				strcpy(gCustomEventListInfo[j].NameEvent, tempName);
			}
		}
	}
}

int actualTime = GetTickCount();
void CCustomEventTimeDraw::UpdateEventsTime()
{
	if (GetTickCount() - actualTime > 1000)
	{
		actualTime = GetTickCount();
		for (int i = 0; i < MAX_EVENT_LIST; i++)
		{
			if (this->gCustomEventListInfo[i].TimeEvent != -1)
			{
				this->gCustomEventListInfo[i].TimeEvent--;
			}
		}
	}
}

bool CCustomEventTimeDraw::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

void CCustomEventTimeDraw::OpenWindow()
{
	if (gInterface.CheckWindow(ObjWindow::Inventory) || gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		pSetCursorFocus = false;

		return;
	}

	gInterface.CloseCustomWindow();

	this->ResetTimeLeft();

	gProtocolS6.RequestEventListS6();

	this->EventTimeEnable = 1;

	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	pSetCursorFocus = true;
}

bool CCustomEventTimeDraw::EventNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || NextEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextEvent))
	{
		return false;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextEvent].OnClick = false;

	this->Page++;

	gInterface.Data[eNextEvent].EventTick = GetTickCount();
	return true;
}

bool CCustomEventTimeDraw::EventPrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || PreventEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevEvent))
	{
		return false;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevEvent].OnClick = false;

	gInterface.Data[ePrevEvent].EventTick = GetTickCount();
	this->Page--;
	return true;
}

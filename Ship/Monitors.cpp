#include "stdafx.h"
#include "Monitors.h"
#include <iostream>
Monitor::Monitor(int left, int right, int top, int bottom)
{
	lB = left;
	rB = right;
	tB = top;
	bB = bottom;
	SetSize();
}
Monitor::~Monitor()
{

}
void Monitor::SetSize()
{
	width = rB - lB;
	height = bB - tB;
}

std::vector<Monitor> MonitorList;

BOOL CALLBACK GetMonitors(HMONITOR hMon, HDC hdcMon, LPRECT lprcMon, LPARAM dwData)
{
	dbgmsg("GetMonitors called!",NULL);
	if(hMon)
	{
		MonitorList.push_back(Monitor((*lprcMon).left, (*lprcMon).right, (*lprcMon).top, (*lprcMon).bottom));
		MonitorList.back().SetSize();

		idbgmsg("Monitor %d", MonitorList.size());
		idbgmsg("	Left: %d", MonitorList.back().lB);
		idbgmsg("	Right: %d", MonitorList.back().rB);
		idbgmsg("	Top: %d", MonitorList.back().tB);
		idbgmsg("	Bottom: %d", MonitorList.back().bB);
		idbgmsg("	Width: %d", MonitorList.back().width);
		idbgmsg("	Height: %d", MonitorList.back().height);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SortWindowsToMonitors(std::vector<HWND> &WinList, std::vector<Monitor> &MonList)
{
	RECT rect;
	for(int i = 0; i < WinList.size(); i++)
	{
		GetWindowRect(WinList.at(i), &rect);
		for(int j = 0; j < MonList.size(); j++)
		{
			if((MonList.at(j).lB <= rect.left && rect.left <= MonList.at(j).rB) && (MonList.at(j).tB <= rect.bottom && rect.bottom <= MonList.at(j).bB))
			{
				MonList.at(j).WindowList.push_back(WinList.at(i));
				idbgmsg("Window %d",i);
				idbgmsg(" sent to Monitor %d", j);
				idbgmsg(" Monitor %d", j);
				idbgmsg(" has %d windows", MonList.at(j).WindowList.size());
				break;
			}
		}
	}
}

#include "stdafx.h"
#include "Monitor.h"
#include "Config.h"
#include <iostream>
Monitor::Monitor(int left, int right, int top, int bottom)
{
	lB = left;
	rB = right;
	tB = top;
	bB = bottom;
	uDllName = new char[MAX_PATH];
	SetSize();
}
Monitor::~Monitor()
{

}

void Monitor::SetSize()
{
	width = rB - lB;
	height = bB - tB;
	usableWidth = width - options->TBRSize - options->TBLSize - (2*options->BHor);
	usableHeight = height - options->TBBSize - options->TBTSize - (2*options->BVer);
}

BOOL Monitor::SetFunctions(char dllName[MAX_PATH])
{
	if(!(uDll = LoadLibraryA(dllName)))
	{
		return FALSE;
	}
	uFunc = (updateFunction)GetProcAddress(uDll, "Main_Update");
	rhFunc = (registerHotkeyFunction)GetProcAddress(uDll, "Main_RegisterHotkeys");
	hhFunc = (handleHotkeyFunction)GetProcAddress(uDll, "Main_HandleHotkeys");
	tFunc = (tileFunction)GetProcAddress(uDll,"Main_Tile");

	if((uFunc) &&
		(rhFunc) &&
		(hhFunc) &&
		(tFunc))

	{
		uDllName = dllName;
		return TRUE;
	}
	return FALSE;
}


TILDEAPI BOOL CALLBACK GetMonitors(HMONITOR hMon, HDC hdcMon, LPRECT lprcMon, LPARAM dwData)
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

TILDEAPI BOOL SortWindowsToMonitors(std::vector<HWND> &WinList, std::vector<Monitor> &MonList)
{
	RECT rect;
	for(int i = 0; i < WinList.size(); i++)
	{
		GetWindowRect(WinList.at(i), &rect);
		InflateRect(&rect, -2, -2);
		for(int j = 0; j < MonList.size(); j++)
		{
			if((MonList.at(j).lB <= rect.left && rect.left <= MonList.at(j).rB) && (MonList.at(j).tB <= rect.bottom && rect.bottom <= MonList.at(j).bB))
			{
				MonList.at(j).WindowList.push_back(WinList.at(i));
				idbgmsg("Window %d",i);
				idbgmsg(" sent to Monitor %d", j);
				idbgmsg(" Monitor %d", j);
				idbgmsg(" has %d windows", MonList.at(j).WindowList.size());
				continue;
			}
		}
	}
	return TRUE;
}


TILDEAPI int FindCurrentMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	RECT rect;
	GetWindowRect(hwnd, &rect);
	InflateRect(&rect, -2, -2);
	for(int j = 0; j < MonList.size(); j++)
	{
		if((MonList.at(j).lB <= rect.left && rect.left <= MonList.at(j).rB) && (MonList.at(j).tB <= rect.bottom && rect.bottom <= MonList.at(j).bB))
		{
			return j;
		}
	}
	return FALSE;
}
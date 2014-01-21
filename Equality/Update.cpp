#include "stdafx.h"
#include "Update.h"

extern "C" __declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd)
{
	int CurrentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	if(callCase == 1)
	{
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	else if(callCase == 0)
	{
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	else if(callCase == 2)
	{
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	return FALSE;
}
extern "C" __declspec(dllexport) BOOL Main_HandleHotkeys(int id)
{
	return FALSE;
}
extern "C" __declspec(dllexport) BOOL Main_RegisterHotkeys(HWND hwnd)
{
	return TRUE;
}
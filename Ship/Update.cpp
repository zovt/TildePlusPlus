#include "stdafx.h"
#include "Update.h"

const UINT created = 396850;
const UINT destroyed = 396851;

__declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd)
{
	if(callCase == 1)
	{
		SendToMonitor(hwnd, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	else if(callCase == 0)
	{
		FindDestroyedWindow(hwnd, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	return FALSE;
}

BOOL SendToMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	RECT rect;
	GetWindowRect(hwnd, &rect);
	InflateRect(&rect, -2, -2);
	for(int i = 0; i < MonList.size(); i++)
	{
		if((MonList.at(i).lB <= rect.left && rect.left <= MonList.at(i).rB) && (MonList.at(i).tB <= rect.bottom && rect.bottom <= MonList.at(i).bB))
		{
			MonList.at(i).WindowList.push_back(hwnd);
			return TRUE;
		}
	}
	return FALSE;
}
BOOL FindDestroyedWindow(HWND hwnd, std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			if(MonList.at(i).WindowList.at(j) == hwnd)
			{
				MonList.at(i).WindowList.erase(MonList.at(i).WindowList.begin() + j);
				return TRUE;
			}
		}
	}
	return FALSE;
}
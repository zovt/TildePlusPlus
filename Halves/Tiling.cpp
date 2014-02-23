#include "stdafx.h"
#include "Config.h"
#include "Tiling.h"
#include <math.h>

#define cMon MonitorList.at(currentMonitor);

extern "C" __declspec(dllexport) void Main_Tile(int currentMonitor)
{
	int h = 0, w = 0;
	int x = 0, y = 0;
	int yP = 0;
	int i = 0;
	int j = 0;

	w = MonitorList.at(currentMonitor).usableWidth;
	h = MonitorList.at(currentMonitor).usableHeight;

	for(int k = 0; k < MonitorList.at(currentMonitor).Workspaces[MonitorList[currentMonitor].cWS].size(); k++)
	{
		if(k % 2 == 0)
		{
			i++;
			if(k + 1 == MonitorList.at(currentMonitor).Workspaces[MonitorList[currentMonitor].cWS].size())
			{
				w = w;
			}
			else
			{
				w = (w-options->PHor)/(2);
			}
			if(i-1==0)
			{
				y = 0;
			}
			else
			{
				y = h + y;
			}
		}
		else
		{
			j++;
			if(k + 1 == MonitorList.at(currentMonitor).Workspaces[MonitorList[currentMonitor].cWS].size())
			{
				h = h;
			}
			else
			{
				h = (h-options->PHor)/(2);
			}
			if(j == 0)
			{
				x = 0;
			}
			else
			{
				x = w + x;
			}
		}
		SetWindowPos(MonitorList.at(currentMonitor).Workspaces[MonitorList[currentMonitor].cWS].at(k), HWND_TOP, MonitorList.at(currentMonitor).lB + options->TBLSize + options->BHor + (j)*(options->PHor) + x, MonitorList.at(currentMonitor).tB + options->BVer + options->TBTSize +  (i-1)*(options->PVer) +y, w, h, NULL);
	}
}

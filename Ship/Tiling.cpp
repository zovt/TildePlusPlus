#include "stdafx.h"
#include "Tiling.h"
#include "Config.h"
#include <iostream>
int X=0, Y=0;

std::vector<PortWindowNumber> PortWindowNumberList;
	
void SetPortWindowNumberList()
{
	for(int i = 0; i < MonitorList.size(); i++)
	{
		PortWindowNumberList.push_back(PortWindowNumber(1));
	}
}

extern "C" __declspec(dllexport) void Main_Tile(int currentMonitor)
{
	int PortWindowSizeVertical, PortWindowSizeHorizontal, PortWindowMovementVertical, DeckWindowSizeVertical, DeckWindowSizeHorizontal, DeckWindowMovementVertical, DeckWindowMovementHorizontal;
	if(MonitorList.at(currentMonitor).WindowList.size() == 1)
	{
			SetWindowPos(MonitorList.at(currentMonitor).WindowList.at(0), HWND_TOP, MonitorList.at(currentMonitor).lB + options->BHor, MonitorList.at(currentMonitor).tB + options->TBTSize + options->BVer, MonitorList.at(currentMonitor).usableWidth, MonitorList.at(currentMonitor).usableHeight, NULL);
	}

	PortWindowSizeVertical = (MonitorList.at(currentMonitor).usableHeight-((PortWindowNumberList.at(currentMonitor).value-1)*options->PVer))/PortWindowNumberList.at(currentMonitor).value;
	PortWindowSizeHorizontal = 2*(MonitorList.at(currentMonitor).usableWidth-(options->PHor))/3;
	PortWindowMovementVertical = PortWindowSizeVertical+options->PVer;

	if(MonitorList.at(currentMonitor).WindowList.size() > PortWindowNumberList.at(currentMonitor).value)
	{
		DeckWindowSizeVertical = (MonitorList.at(currentMonitor).usableHeight-((MonitorList.at(currentMonitor).WindowList.size()-1)-PortWindowNumberList.at(currentMonitor).value)*options->PVer)/(MonitorList.at(currentMonitor).WindowList.size()-PortWindowNumberList.at(currentMonitor).value);
		DeckWindowSizeHorizontal = (MonitorList.at(currentMonitor).usableWidth-(options->PHor))/3;
		DeckWindowMovementVertical = DeckWindowSizeVertical + options->PVer;
		DeckWindowMovementHorizontal = PortWindowSizeHorizontal + options->PHor;
	}
	idbgmsg("Monitor %d", currentMonitor);
	idbgmsg(" has %d windows", MonitorList.at(currentMonitor).WindowList.size());
	for(int j = 0; j < MonitorList.at(currentMonitor).WindowList.size(); j++)
	{
		if(j<PortWindowNumberList.at(currentMonitor).value)
		{
			SetWindowPos(MonitorList.at(currentMonitor).WindowList.at(j), HWND_TOP, MonitorList.at(currentMonitor).lB+options->BHor, MonitorList.at(currentMonitor).tB + options->TBTSize + options->BVer + PortWindowMovementVertical*j, PortWindowSizeHorizontal, PortWindowSizeVertical, NULL);
		}
		else
		{
			SetWindowPos(MonitorList.at(currentMonitor).WindowList.at(j), HWND_TOP, MonitorList.at(currentMonitor).lB + options->BHor + DeckWindowMovementHorizontal, MonitorList.at(currentMonitor).tB + options->BVer + options->TBTSize + DeckWindowMovementVertical*(j-PortWindowNumberList.at(currentMonitor).value), DeckWindowSizeHorizontal, DeckWindowSizeVertical, NULL);
		}
	}
}

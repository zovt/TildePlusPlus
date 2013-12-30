#pragma once
#include "stdafx.h"
#include "Tiling.h"
#include <iostream>
int X=0, Y=0;
int i = 0;
void Tile(std::vector<Monitor> MonList)
{
	int PortWindowSizeVertical, PortWindowSizeHorizontal, PortWindowMovementVertical, DeckWindowSizeVertical, DeckWindowSizeHorizontal, DeckWindowMovementVertical, DeckWindowMovementHorizontal;
	for(int i = 0; i < MonList.size(); i++)
	{
		Options &options = MonList.at(i).monOptions;

		if(MonList.at(i).WindowList.size() == 1)
		{
			SetWindowPos(MonList.at(i).WindowList.at(0), HWND_TOP, MonList.at(i).lB + options.BHor, MonList.at(i).tB + options.TBTSize + options.BVer, MonList.at(i).usableWidth, MonList.at(i).usableHeight, NULL);
			if(MonList.size() <= i + 1)
			{
				return;
			}
			i++;
			options = MonList.at(i).monOptions;
		}

		PortWindowSizeVertical = (MonList.at(i).usableHeight-((options.PortWindows-1)*options.PVer))/options.PortWindows;
		PortWindowSizeHorizontal = 2*(MonList.at(i).usableWidth-(options.PHor))/3;
		PortWindowMovementVertical = PortWindowSizeVertical+options.PVer;

		if(MonList.at(i).WindowList.size() > options.PortWindows)
		{
			DeckWindowSizeVertical = (MonList.at(i).usableHeight-((MonList.at(i).WindowList.size()-1)-options.PortWindows)*options.PVer)/(MonList.at(i).WindowList.size()-options.PortWindows);
			DeckWindowSizeHorizontal = (MonList.at(i).usableWidth-(options.PHor))/3;
			DeckWindowMovementVertical = DeckWindowSizeVertical + options.PVer;
			DeckWindowMovementHorizontal = PortWindowSizeHorizontal + options.PHor;
		}

		idbgmsg("Monitor %d", i);
		idbgmsg(" has %d windows", MonList.at(i).WindowList.size());
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			if(j<options.PortWindows)
			{
				SetWindowPos(MonList.at(i).WindowList.at(j), HWND_TOP, MonList.at(i).lB+options.BHor, MonList.at(i).tB + options.TBTSize + options.BVer + PortWindowMovementVertical*j, PortWindowSizeHorizontal, PortWindowSizeVertical, NULL);
			}
			else
			{
				SetWindowPos(MonList.at(i).WindowList.at(j), HWND_TOP, MonList.at(i).lB + options.BHor + DeckWindowMovementHorizontal, MonList.at(i).tB + options.BVer + options.TBTSize + DeckWindowMovementVertical*(j-options.PortWindows), DeckWindowSizeHorizontal, DeckWindowSizeVertical, NULL);
			}
		}
	}
}

int GetCurrentMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			if(hwnd == MonList.at(i).WindowList.at(j))
			{
				return i;
			}
		}
	}
	return 0;
}

BOOL SwapWindows(HWND hwnd, std::vector<Monitor> &MonList, int positionToSwapTo)
{
	int windowLocation = 0;
	HWND middleMan;
	int currentMonitor = GetCurrentMonitor(hwnd, MonList);



	for(int i = 0; i < MonList.at(currentMonitor).WindowList.size(); i++)
	{
		if(hwnd == MonList.at(currentMonitor).WindowList.at(i))
		{
			windowLocation = i;
		}
	}
	
	if(positionToSwapTo > MonList.at(currentMonitor).WindowList.size())
	{
		positionToSwapTo = MonList.at(currentMonitor).WindowList.size();
	}
	middleMan = hwnd;

	MonList.at(currentMonitor).WindowList.at(windowLocation) = MonList.at(currentMonitor).WindowList.at(positionToSwapTo-1);
	MonList.at(currentMonitor).WindowList.at(positionToSwapTo - 1) = middleMan;

	return TRUE;
}

BOOL SendWindowToNextMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	int currentMonitor = GetCurrentMonitor(hwnd, MonList);
	int nextMonitor = currentMonitor + 1;
	for(int i = 0; i < MonList.at(currentMonitor).WindowList.size(); i++)
	{
		if(hwnd == MonList.at(currentMonitor).WindowList.at(i))
		{
			if(currentMonitor + 1 >= MonList.size())
			{
				nextMonitor = 0;
			}
			MonList.at(nextMonitor).WindowList.push_back(MonList.at(currentMonitor).WindowList.at(i));
			MonList.at(currentMonitor).WindowList.erase(MonList.at(currentMonitor).WindowList.begin() + i);
			return TRUE;
		}
	}
	return FALSE;
}

BOOL ForceAddTiling(HWND hwnd, std::vector<Monitor> &MonList)
{
	if(!hwnd)
		return FALSE;

	int currentMonitor = GetCurrentMonitor(hwnd, MonList);
	MonList.at(currentMonitor).WindowList.push_back(hwnd);
	WindowList.push_back(hwnd);

	return TRUE;
}

BOOL RemoveWindowBorders(std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			SetWindowLong(MonList.at(i).WindowList.at(j), GWL_STYLE, GetWindowLong(MonList.at(i).WindowList.at(j), GWL_STYLE) & ~(WS_CAPTION));
			SetWindowPos(MonList.at(i).WindowList.at(j), NULL, NULL, NULL, NULL, NULL, SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
		}
	}
	return TRUE;
}

BOOL RemoveWindowBorders(HWND &hwnd)
{
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_CAPTION));
	SetWindowPos(hwnd, NULL, NULL, NULL, NULL, NULL, SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
	return TRUE;
}

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
		PortWindowSizeVertical = MonList.at(i).height/MAX_PORT_WINDOWS;
		PortWindowSizeHorizontal = 2*(MonList.at(i).width/3);
		PortWindowMovementVertical = PortWindowSizeVertical;

		if(MonList.at(i).WindowList.size() > MAX_PORT_WINDOWS)
		{
			DeckWindowSizeVertical = MonList.at(i).height/(MonList.at(i).WindowList.size()-MAX_PORT_WINDOWS);
			DeckWindowSizeHorizontal = MonList.at(i).width/3;
			DeckWindowMovementVertical = DeckWindowSizeVertical;
			DeckWindowMovementHorizontal = PortWindowSizeHorizontal;
		}

		idbgmsg("Monitor %d", i);
		idbgmsg(" has %d windows", MonList.at(i).WindowList.size());
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			if(j<MAX_PORT_WINDOWS)
			{
				SetWindowPos(MonList.at(i).WindowList.at(j), HWND_BOTTOM, MonList.at(i).lB, MonList.at(i).tB + PortWindowMovementVertical*j, PortWindowSizeHorizontal, PortWindowSizeVertical, NULL);
			}
			else
			{
				SetWindowPos(MonList.at(i).WindowList.at(j), HWND_BOTTOM, MonList.at(i).lB + DeckWindowMovementHorizontal, MonList.at(i).tB + DeckWindowMovementVertical*(j-MAX_PORT_WINDOWS), DeckWindowSizeHorizontal, DeckWindowSizeVertical, NULL);
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

	if(positionToSwapTo > MonList.at(currentMonitor).WindowList.size())
	{
		return FALSE;
	}


	for(int i = 0; i < MonList.at(currentMonitor).WindowList.size(); i++)
	{
		if(hwnd == MonList.at(currentMonitor).WindowList.at(i))
		{
			windowLocation = i;
		}
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
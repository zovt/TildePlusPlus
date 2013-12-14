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
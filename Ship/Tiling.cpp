#include "stdafx.h"
#include "Tiling.h"
#include <iostream>
int X=0, Y=0;
int i = 0;
void Tile()
{
	dbgmsg("Tile() called!",NULL);
	dbgmsg("numWindows: %d", numWindows);
	for(i = 0; i < numWindows; i++){
		dbgmsg("For loop at: %d", i);
		if(i<MAX_PORT_WINDOWS)
		{
			TilePort(WindowArray.at(i), MAX_PORT_WINDOWS);
		}
		else
		{
			TileDeck(WindowArray.at(i));
		}
	}
}

void TilePort(HWND hwnd, int numPortWin)
{
	SetWindowPos(hwnd, HWND_BOTTOM, 0, i*(1080/numPortWin), 1280, (1080/numPortWin), NULL);
}

void TileDeck(HWND hwnd)
{
	SetWindowPos(hwnd, HWND_BOTTOM, 1280, (i-MAX_PORT_WINDOWS)*(1080/(numWindows-MAX_PORT_WINDOWS)), 640, (1080/(numWindows-MAX_PORT_WINDOWS)), NULL);
}
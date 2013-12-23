#pragma once
#include "stdafx.h"
#include "Monitors.h"
#define MAX_PORT_WINDOWS 1
void Tile(std::vector<Monitor> MonList);
void TilePort(HWND hwnd, int numPortWin);
void TileDeck(HWND hwnd);
int GetCurrentMonitor(HWND hwnd, std::vector<Monitor> &MonList);
BOOL SwapWindows(HWND hwnd, std::vector<Monitor> &MonList, int positionToSwapTo);
BOOL SendWindowToNextMonitor(HWND hwnd, std::vector<Monitor> &MonList);
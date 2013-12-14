#pragma once
#include "stdafx.h"
#include "Monitors.h"
#define MAX_PORT_WINDOWS 2
void Tile(std::vector<Monitor> MonList);
void TilePort(HWND hwnd, int numPortWin);
void TileDeck(HWND hwnd);
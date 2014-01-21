#pragma once
#include "stdafx.h"
#include "Monitor.h"
#define MAX_PORT_WINDOWS 1
extern "C" __declspec(dllexport) void Main_Tile(int currentMonitor);
void SetPortWindowNumberList();
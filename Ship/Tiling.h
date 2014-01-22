#pragma once
#include "stdafx.h"
#include "Monitor.h"
#define MAX_PORT_WINDOWS 1

struct PortWindowNumber
{
	PortWindowNumber(int n)
	{
		value = n;
	}
	int value;
};


extern "C" __declspec(dllexport) void Main_Tile(int currentMonitor);
void SetPortWindowNumberList();
extern std::vector<PortWindowNumber> PortWindowNumberList;

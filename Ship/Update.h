#include "stdafx.h"
#include "Window.h"
#include "Tiling.h"



extern "C" __declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd);
BOOL SendToMonitor(HWND hwnd, std::vector<Monitor> &MonList);
BOOL FindDestroyedWindow(HWND hwnd, std::vector<Monitor> &MonList);
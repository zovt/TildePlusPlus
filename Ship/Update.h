#include "stdafx.h"
#include "Window.h"
#include "Tiling.h"

extern "C" __declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd, int curMon);
extern "C" __declspec(dllexport) BOOL Main_HandleHotkeys(int id);
extern "C" __declspec(dllexport) BOOL Main_RegisterHotkeys(HWND hwnd);

BOOL SwapWindows(HWND hwnd, int positionToSwapTo);
BOOL RemoveWindowBorders(std::vector<Monitor> &MonList);
BOOL RemoveWindowBorders(HWND &hwnd);
int SendWindowToNextMonitor(HWND hwnd, std::vector<Monitor> &MonList);
BOOL ChangeMonitorPortWindows(int amount);
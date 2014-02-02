#include "stdafx.h"
#include "Window.h"

TILDEAPI int numWindows = 0;
TILDEAPI std::vector<HWND> tempWindowList;
TILDEAPI std::vector<HWND> WindowList;
TILDEAPI BOOL CALLBACK sendWindowsToTempWindowArray(HWND hwnd, LPARAM lParam)
{
	tempWindowList.resize(numWindows+1);
	tempWindowList[numWindows] = hwnd;
	numWindows += 1;
	return true;
}
int i = 0;
TILDEAPI void sendWindowsToWindowArray(HWND hwnd)
{
	i++;
	WindowList.resize(i+1);
	WindowList[i] = hwnd;
}

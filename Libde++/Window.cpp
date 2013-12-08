#include "stdafx.h"
#include "Window.h"

TILDEAPI int numWindows = 0;
TILDEAPI std::vector<HWND> tempWindowArray;
TILDEAPI std::vector<HWND> WindowArray;
TILDEAPI BOOL CALLBACK sendWindowsToTempWindowArray(HWND hwnd, LPARAM lParam)
{
	tempWindowArray.resize(numWindows+1);
	tempWindowArray[numWindows] = hwnd;
	numWindows += 1;
	return true;
}
int i = 0;
TILDEAPI void sendWindowsToWindowArray(HWND hwnd)
{
	i++;
	WindowArray.resize(i+1);
	WindowArray[i] = hwnd;
}
#include "stdafx.h"
#include <vector>
#include "dbgmsg.h"
extern "C" TILDEAPI std::vector<HWND> WindowList;
extern "C" TILDEAPI int numWindows;
extern "C" TILDEAPI std::vector<HWND> tempWindowList;
TILDEAPI BOOL CALLBACK sendWindowsToTempWindowArray(HWND hwnd, LPARAM lParam);
TILDEAPI void sendWindowsToWindowArray(HWND hwnd);
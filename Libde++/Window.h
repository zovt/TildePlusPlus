#include "stdafx.h"
#include <vector>
#include "dbgmsg.h"
extern TILDEAPI std::vector<HWND> WindowList;
extern TILDEAPI int numWindows;
extern TILDEAPI std::vector<HWND> tempWindowList;
TILDEAPI BOOL CALLBACK sendWindowsToTempWindowArray(HWND hwnd, LPARAM lParam);
TILDEAPI void sendWindowsToWindowArray(HWND hwnd);
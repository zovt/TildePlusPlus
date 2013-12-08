#include "stdafx.h"
#include <vector>
extern TILDEAPI std::vector<HWND> WindowArray;
extern TILDEAPI int numWindows;
extern TILDEAPI std::vector<HWND> tempWindowArray;
TILDEAPI BOOL CALLBACK sendWindowsToTempWindowArray(HWND hwnd, LPARAM lParam);
TILDEAPI void sendWindowsToWindowArray(HWND hwnd);
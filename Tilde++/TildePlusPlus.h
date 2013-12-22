#define WIN32_LEAN_AND_MEAN
#define ENABLEIMPORTS // Enable the necessary variable imports (see stdafx.h of Libde++)
#define DEBUGENABLED
#include <Windows.h>
#include <vector>
#include "dbgmsg.h"
typedef BOOL (*updateFunction)(int, HWND);
BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList, updateFunction (&function));
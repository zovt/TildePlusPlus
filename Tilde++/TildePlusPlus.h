#define WIN32_LEAN_AND_MEAN
#define ENABLEIMPORTS // Enable the necessary variable imports (see stdafx.h of Libde++)
#include <Windows.h>
#include <vector>
#include "dbgmsg.h"
typedef BOOL (*updateFunction)(int, HWND);
typedef BOOL (*registerHotkeyFunction)(HWND(&));
typedef BOOL (*handleHotkeyFunction)(int);
BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList, updateFunction (&function));
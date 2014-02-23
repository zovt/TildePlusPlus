#define WIN32_LEAN_AND_MEAN
#define ENABLEIMPORTS // Enable the necessary variable imports (see stdafx.h of Libde++)
#include <Windows.h>
#include "Vars.h"
#include "dbgmsg.h"
#include "Window.h"
#include "Monitor.h"
#include "Functions.h"

BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList);
int SendWindowToMonitor(HWND &hwnd, std::vector<Monitor> &MonList);
int FindDestroyedWindow(HWND hwnd, std::vector<Monitor> &MonList);

BOOL HandleWorkspaceKey(WPARAM wParam);
BOOL ActivateWorkspace(int Workspace, int cWS);
BOOL SendWindowToWorkspace(int Workspace, int cWS);


BOOL RegisterMainHotkeys(HWND hwnd);
BOOL ChangeDll(int direction);

BOOL UpdateMonitorHotkeys(int Monitor, HWND hwnd);



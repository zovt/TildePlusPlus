#include "stdafx.h"
#include <vector>
#include "Functions.h"

class Monitor{
public:
	int lB, rB, tB, bB;
	int width, height;
	int usableWidth, usableHeight;
	std::vector<std::vector<HWND>> Workspaces;
	int cWS;

	HINSTANCE uDll;
	char *uDllName;

	updateFunction uFunc;
	registerHotkeyFunction rhFunc;
	handleHotkeyFunction hhFunc;
	tileFunction tFunc;

	void SetSize();
	TILDEAPI BOOL SetFunctions(char dllName[MAX_PATH]);


	Monitor(int left, int right, int top, int bottom);
	~Monitor();
};

TILDEAPI BOOL CALLBACK GetMonitors(HMONITOR hMon, HDC hdcMon, LPRECT lprcMon, LPARAM dwData);
TILDEAPI BOOL SortWindowsToMonitors(std::vector<HWND> &WinList, std::vector<Monitor> &MonList);

TILDEAPI std::vector<Monitor> MonitorList;

TILDEAPI int FindCurrentMonitor(HWND hwnd, std::vector<Monitor> &MonList);

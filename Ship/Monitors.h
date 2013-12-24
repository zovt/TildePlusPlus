#include "stdafx.h"
#include <vector>
#include "Config.h"

class Monitor{
public:
	int lB, rB, tB, bB;
	int width, height;
	int usableWidth, usableHeight;
	std::vector<HWND> WindowList;
	Options monOptions;
	void SetSize();
	Monitor(int left, int right, int top, int bottom);
	~Monitor();
};

extern std::vector<Monitor> MonitorList;

BOOL CALLBACK GetMonitors(HMONITOR hMon, HDC hdcMon, LPRECT lprcMon, LPARAM dwData);
void SortWindowsToMonitors(std::vector<HWND> &WinList, std::vector<Monitor> &MonList);


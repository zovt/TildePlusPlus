#include "stdafx.h"
#include "Update.h"

const UINT created = 396850;
const UINT destroyed = 396851;
ATOM nPad1, nPad2, nPad3, nPad4, nPad5, nPad6, nPad7, nPad8, nPad9, nPad0, nPadDot, nPadPlus, nPadMinus, nPadMultiply, nPadDivide, nPadEnter, nPadEnterAlt;

__declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd)
{
	if(callCase == 1)
	{
		SendToMonitor(hwnd, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	else if(callCase == 0)
	{
		FindDestroyedWindow(hwnd, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	return FALSE;
}

extern "C" __declspec(dllexport) BOOL Main_HandleHotkeys(int id)
{
	HWND currentWindow = GetForegroundWindow();
	if(id == nPad1)
	{
		SwapWindows(currentWindow, MonitorList, 1);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad2)
	{
		SwapWindows(currentWindow, MonitorList, 2);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad3)
	{
		SwapWindows(currentWindow, MonitorList, 3);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad4)
	{
		SwapWindows(currentWindow, MonitorList, 4);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad5)
	{
		SwapWindows(currentWindow, MonitorList, 5);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad6)
	{
		SwapWindows(currentWindow, MonitorList, 6);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad7)
	{
		SwapWindows(currentWindow, MonitorList, 7);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad8)
	{
		SwapWindows(currentWindow, MonitorList, 8);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad9)
	{
		SwapWindows(currentWindow, MonitorList, 9);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPad0)
	{
		SendWindowToNextMonitor(currentWindow, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPadDot)
	{
		ForceAddTiling(currentWindow, MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPadPlus)
	{
		ChangeMonitorPortWindows(MonitorList, 1);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPadMinus)
	{
		ChangeMonitorPortWindows(MonitorList, -1);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPadMultiply)
	{
		UpdateMonitorOptions(MonitorList);
		Tile(MonitorList);
		return TRUE;
	}
	if(id == nPadDivide)
	{
		MessageBoxA(NULL, "Quitting Tilde!", "Ship", MB_OK);
		exit(0);
		return TRUE;
	}
	if(id == nPadEnter)
	{
		HWND hwnd = GetForegroundWindow();
		RemoveWindowBorders(hwnd);
		return TRUE;
	}
	if(id == nPadEnterAlt)
	{
		RemoveWindowBorders(MonitorList);
		return TRUE;
	}
	return FALSE;
}

extern "C" __declspec(dllexport) BOOL Main_RegisterHotkeys(HWND &hwnd)
{
	nPad1 = GlobalAddAtomA("nPad1Hotkey");
	nPad2 = GlobalAddAtomA("nPad2Hotkey");
	nPad3 = GlobalAddAtomA("nPad3Hotkey");
	nPad4 = GlobalAddAtomA("nPad4Hotkey");
	nPad5 = GlobalAddAtomA("nPad5Hotkey");
	nPad6 = GlobalAddAtomA("nPad6Hotkey");
	nPad7 = GlobalAddAtomA("nPad7Hotkey");
	nPad8 = GlobalAddAtomA("nPad8Hotkey");
	nPad9 = GlobalAddAtomA("nPad9Hotkey");
	nPad0 = GlobalAddAtomA("nPad0Hotkey");
	nPadDot = GlobalAddAtomA("nPadDotHotkey");
	nPadPlus = GlobalAddAtomA("nPadPlusHotkey");
	nPadMinus = GlobalAddAtomA("nPadMinusHotkey");
	nPadMultiply = GlobalAddAtomA("nPadMultiplyHotkey");
	nPadDivide = GlobalAddAtomA("nPadDivideHotkey");
	nPadEnter = GlobalAddAtomA("nPadEnter");
	nPadEnterAlt = GlobalAddAtomA("nPadEnterAlt");

	RegisterHotKey(hwnd, nPad1, MOD_CONTROL, VK_NUMPAD1);
	RegisterHotKey(hwnd, nPad2, MOD_CONTROL, VK_NUMPAD2);
	RegisterHotKey(hwnd, nPad3, MOD_CONTROL, VK_NUMPAD3);
	RegisterHotKey(hwnd, nPad4, MOD_CONTROL, VK_NUMPAD4);
	RegisterHotKey(hwnd, nPad5, MOD_CONTROL, VK_NUMPAD5);
	RegisterHotKey(hwnd, nPad6, MOD_CONTROL, VK_NUMPAD6);
	RegisterHotKey(hwnd, nPad7, MOD_CONTROL, VK_NUMPAD7);
	RegisterHotKey(hwnd, nPad8, MOD_CONTROL, VK_NUMPAD8);
	RegisterHotKey(hwnd, nPad9, MOD_CONTROL, VK_NUMPAD9);
	RegisterHotKey(hwnd, nPad0, MOD_CONTROL, VK_NUMPAD0);
	RegisterHotKey(hwnd, nPadDot, MOD_CONTROL, VK_DECIMAL);
	RegisterHotKey(hwnd, nPadPlus, MOD_CONTROL, VK_ADD);
	RegisterHotKey(hwnd, nPadMinus, MOD_CONTROL, VK_SUBTRACT);
	RegisterHotKey(hwnd, nPadMultiply, MOD_CONTROL, VK_MULTIPLY);
	RegisterHotKey(hwnd, nPadDivide, MOD_CONTROL, VK_DIVIDE);
	RegisterHotKey(hwnd, nPadEnter, MOD_CONTROL, VK_RETURN);
	RegisterHotKey(hwnd, nPadEnterAlt, MOD_CONTROL | MOD_ALT, VK_RETURN);

	return TRUE;
}

BOOL SendToMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	RECT rect;
	GetWindowRect(hwnd, &rect);
	InflateRect(&rect, -2, -2);
	for(int i = 0; i < MonList.size(); i++)
	{
		if((MonList.at(i).lB <= rect.left && rect.left <= MonList.at(i).rB) && (MonList.at(i).tB <= rect.bottom && rect.bottom <= MonList.at(i).bB))
		{
			MonList.at(i).WindowList.push_back(hwnd);
			return TRUE;
		}
	}
	return FALSE;
}
BOOL FindDestroyedWindow(HWND hwnd, std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			if(MonList.at(i).WindowList.at(j) == hwnd)
			{
				MonList.at(i).WindowList.erase(MonList.at(i).WindowList.begin() + j);
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL ChangeMonitorPortWindows(std::vector<Monitor> &MonList, int amount)
{
	int currentMonitor = GetCurrentMonitor(GetForegroundWindow(), MonitorList);
	MonList.at(currentMonitor).monOptions.PortWindows += amount;
	return TRUE;
}

BOOL UpdateMonitorOptions(std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		MonList.at(i).monOptions.readOptions();
		Options &options = MonList.at(i).monOptions;
		MonList.at(i).usableWidth = MonList.at(i).width - options.TBRSize - options.TBLSize - (2*options.BHor); 
		MonList.at(i).usableHeight = MonList.at(i).height - options.TBBSize - options.TBTSize - (2*options.BVer);
	}
	return TRUE;
}
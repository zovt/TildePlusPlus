#include "stdafx.h"
#include "Update.h"

ATOM nPad1, nPad2, nPad3, nPad4, nPad5, nPad6, nPad7, nPad8, nPad9, nPad0, nPadDot, nPadPlus, nPadMinus, nPadMultiply, nPadDivide, nPadEnter, nPadEnterAlt;

__declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd, int curMon)
{
	if(callCase == 1)
	{
		Main_Tile(curMon);
		return TRUE;
	}
	else if(callCase == 0)
	{
		Main_Tile(curMon);
		return TRUE;
	}
	else if(callCase == 2)
	{
		Main_Tile(curMon);
		return TRUE;
	}
	return FALSE;
}

extern "C" __declspec(dllexport) BOOL Main_HandleHotkeys(int id)
{
	int CurrentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	HWND currentWindow = GetForegroundWindow();
	if(id == nPad1)
	{
		SwapWindows(currentWindow, 1);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad2)
	{
		SwapWindows(currentWindow, 2);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad3)
	{
		SwapWindows(currentWindow, 3);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad4)
	{
		SwapWindows(currentWindow, 4);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad5)
	{
		SwapWindows(currentWindow, 5);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad6)
	{
		SwapWindows(currentWindow, 6);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad7)
	{
		SwapWindows(currentWindow, 7);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad8)
	{
		SwapWindows(currentWindow, 8);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad9)
	{
		SwapWindows(currentWindow, 9);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPad0)
	{
		int nextMonitor = SendWindowToNextMonitor(currentWindow, MonitorList);
		MonitorList.at(nextMonitor).tFunc(nextMonitor);
		MonitorList.at(CurrentMonitor).tFunc(CurrentMonitor);
		return TRUE;
	}
	/*
	if(id == nPadDot)
	{
		ForceAddTiling(currentWindow, MonitorList);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	*/
	if(id == nPadPlus)
	{
		ChangeMonitorPortWindows(1);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	if(id == nPadMinus)
	{
		ChangeMonitorPortWindows(-1);
		Main_Tile(CurrentMonitor);
		return TRUE;
	}
	/*
	if(id == nPadMultiply)
	{
		UpdateMonitorOptions(MonitorList);
		Main_Tile(CurrentMonitor);
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
	*/
	return FALSE;
}

extern "C" __declspec(dllexport) BOOL Main_RegisterHotkeys(HWND hwnd)
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
	
	if(!(
	RegisterHotKey(hwnd, nPad1, MOD_CONTROL, VK_NUMPAD1))||!(
	RegisterHotKey(hwnd, nPad2, MOD_CONTROL, VK_NUMPAD2))||!(
	RegisterHotKey(hwnd, nPad3, MOD_CONTROL, VK_NUMPAD3))||!(
	RegisterHotKey(hwnd, nPad4, MOD_CONTROL, VK_NUMPAD4))||!(
	RegisterHotKey(hwnd, nPad5, MOD_CONTROL, VK_NUMPAD5))||!(
	RegisterHotKey(hwnd, nPad6, MOD_CONTROL, VK_NUMPAD6))||!(
	RegisterHotKey(hwnd, nPad7, MOD_CONTROL, VK_NUMPAD7))||!(
	RegisterHotKey(hwnd, nPad8, MOD_CONTROL, VK_NUMPAD8))||!(
	RegisterHotKey(hwnd, nPad9, MOD_CONTROL, VK_NUMPAD9))||!(
	RegisterHotKey(hwnd, nPad0, MOD_CONTROL, VK_NUMPAD0))||!(
	RegisterHotKey(hwnd, nPadDot, MOD_CONTROL, VK_DECIMAL))||!(
	RegisterHotKey(hwnd, nPadPlus, MOD_CONTROL, VK_ADD))||!(
	RegisterHotKey(hwnd, nPadMinus, MOD_CONTROL, VK_SUBTRACT))||!(
	RegisterHotKey(hwnd, nPadMultiply, MOD_CONTROL, VK_MULTIPLY))||!(
	RegisterHotKey(hwnd, nPadDivide, MOD_CONTROL, VK_DIVIDE))||!(
	RegisterHotKey(hwnd, nPadEnter, MOD_CONTROL, VK_RETURN))||!(
	RegisterHotKey(hwnd, nPadEnterAlt, MOD_CONTROL | MOD_ALT, VK_RETURN)))
	{
		int error = GetLastError();
		error;
		return FALSE;
	}

	return TRUE;
}

BOOL SwapWindows(HWND hwnd, int positionToSwapTo)
{
	int windowLocation = 0;
	int currentMonitor = FindCurrentMonitor(hwnd, MonitorList);
	
	HWND middleMan;



	for(int i = 0; i < MonitorList.at(currentMonitor).WindowList.size(); i++)
	{
		if(hwnd == MonitorList.at(currentMonitor).WindowList.at(i))
		{
			windowLocation = i;
		}
	}
	
	if(positionToSwapTo > MonitorList.at(currentMonitor).WindowList.size())
	{
		positionToSwapTo = MonitorList.at(currentMonitor).WindowList.size();
	}
	middleMan = hwnd;

	MonitorList.at(currentMonitor).WindowList.at(windowLocation) = MonitorList.at(currentMonitor).WindowList.at(positionToSwapTo-1);
	MonitorList.at(currentMonitor).WindowList.at(positionToSwapTo - 1) = middleMan;

	return TRUE;
}

BOOL RemoveWindowBorders(std::vector<Monitor> &MonList)
{
	for(int i = 0; i < MonList.size(); i++)
	{
		for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
		{
			SetWindowLong(MonList.at(i).WindowList.at(j), GWL_STYLE, GetWindowLong(MonList.at(i).WindowList.at(j), GWL_STYLE) & ~(WS_CAPTION));
			SetWindowPos(MonList.at(i).WindowList.at(j), NULL, NULL, NULL, NULL, NULL, SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
		}
	}
	return TRUE;
}


BOOL RemoveWindowBorders(HWND &hwnd)
{
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_CAPTION));
	SetWindowPos(hwnd, NULL, NULL, NULL, NULL, NULL, SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
	return TRUE;
}

int SendWindowToNextMonitor(HWND hwnd, std::vector<Monitor> &MonList)
{
	int NextMonitor;
	int CurrentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	if(CurrentMonitor + 1 >= MonList.size())
	{
		NextMonitor = 0;
	}
	else
	{
		NextMonitor = CurrentMonitor + 1;
	}
	for(int i = 0; i < MonList.at(CurrentMonitor).WindowList.size(); i++)
	{
		if(hwnd == MonList.at(CurrentMonitor).WindowList.at(i))
		{
			MonList.at(NextMonitor).WindowList.push_back(MonList.at(CurrentMonitor).WindowList.at(i));
			MonList.at(CurrentMonitor).WindowList.erase(MonList.at(CurrentMonitor).WindowList.begin() + i);
			return NextMonitor;
		}
	}
	return FALSE;
}

BOOL ChangeMonitorPortWindows(int amount)
{
	PortWindowNumberList.at(FindCurrentMonitor(GetForegroundWindow(), MonitorList)).value += amount;
	return TRUE;
}
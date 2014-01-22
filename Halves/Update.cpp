#include "stdafx.h"
#include "Update.h"

ATOM nPad1, nPad2, nPad3, nPad4, nPad5, nPad6, nPad7, nPad8, nPad9, nPad0, nPadDot, nPadPlus, nPadMinus, nPadMultiply, nPadDivide, nPadEnter, nPadEnterAlt;


extern "C" __declspec(dllexport) BOOL Main_Update(int callCase, HWND hwnd, int curMon)
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
	return FALSE;
}

extern "C" __declspec(dllexport) BOOL Main_RegisterHotkeys(HWND &hwnd)
{
	nPad1 = GlobalAddAtomA("EqualitynPad1Hotkey");
	nPad2 = GlobalAddAtomA("EqualitynPad2Hotkey");
	nPad3 = GlobalAddAtomA("EqualitynPad3Hotkey");
	nPad4 = GlobalAddAtomA("EqualitynPad4Hotkey");
	nPad5 = GlobalAddAtomA("EqualitynPad5Hotkey");
	nPad6 = GlobalAddAtomA("EqualitynPad6Hotkey");
	nPad7 = GlobalAddAtomA("EqualitynPad7Hotkey");
	nPad8 = GlobalAddAtomA("EqualitynPad8Hotkey");
	nPad9 = GlobalAddAtomA("EqualitynPad9Hotkey");
	nPad0 = GlobalAddAtomA("EqualitynPad0Hotkey");
	nPadDot = GlobalAddAtomA("EqualitynPadDotHotkey");
	nPadPlus = GlobalAddAtomA("EqualitynPadPlusHotkey");
	nPadMinus = GlobalAddAtomA("EqualitynPadMinusHotkey");
	nPadMultiply = GlobalAddAtomA("EqualitynPadMultiplyHotkey");
	nPadDivide = GlobalAddAtomA("EqualitynPadDivideHotkey");
	nPadEnter = GlobalAddAtomA("EqualitynPadEnter");
	nPadEnterAlt = GlobalAddAtomA("EqualitynPadEnterAlt");
	
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
		/* If those hotkeys are already registered, this will associate Equality with the hotkeys made by Ship */

		nPad1 = GlobalFindAtomA("nPad1Hotkey");
		nPad2 = GlobalFindAtomA("nPad2Hotkey");
		nPad3 = GlobalFindAtomA("nPad3Hotkey");
		nPad4 = GlobalFindAtomA("nPad4Hotkey");
		nPad5 = GlobalFindAtomA("nPad5Hotkey");
		nPad6 = GlobalFindAtomA("nPad6Hotkey");
		nPad7 = GlobalFindAtomA("nPad7Hotkey");
		nPad8 = GlobalFindAtomA("nPad8Hotkey");
		nPad9 = GlobalFindAtomA("nPad9Hotkey");
		nPad0 = GlobalFindAtomA("nPad0Hotkey");
		nPadDot = GlobalFindAtomA("nPadDotHotkey");
		nPadPlus = GlobalFindAtomA("nPadPlusHotkey");
		nPadMinus = GlobalFindAtomA("nPadMinusHotkey");
		nPadMultiply = GlobalFindAtomA("nPadMultiplyHotkey");
		nPadDivide = GlobalFindAtomA("nPadDivideHotkey");
		nPadEnter = GlobalFindAtomA("nPadEnter");
		nPadEnterAlt = GlobalFindAtomA("nPadEnterAlt");
	
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
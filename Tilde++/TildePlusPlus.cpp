#include "TildePlusPlus.h"



BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList){
	HWND hwndP = reinterpret_cast<HWND>(lParam);
	int CurrentMonitor = 0;


	if(wParam == HSHELL_WINDOWCREATED)
	{
		WinList.push_back(hwndP);
		CurrentMonitor = SendWindowToMonitor(hwndP, MonitorList);
		MonitorList.at(CurrentMonitor).uFunc(1, hwndP);
		//idbgmsg("Window Created: %p", hwndP);
		return TRUE;
	}
	else if(wParam == HSHELL_WINDOWDESTROYED)
	{
		for(int i = 0; i < WinList.size(); i++)
		{
			if(WinList.at(i) == hwndP)
			{
				CurrentMonitor = FindDestroyedWindow(hwndP, MonitorList);
				WinList.erase(WinList.begin() + i);
				WinList.resize(WinList.size());
				MonitorList.at(CurrentMonitor).uFunc(0, hwndP);
				idbgmsg("Window Destroyed: %d", hwndP);
				return TRUE;
			}
		}
	}
	else if(wParam == HSHELL_GETMINRECT)
	{
		for(int i = 0; i < WinList.size(); i++)
		{
			if(WinList.at(i) == hwndP)
			{
				WinList.erase(WinList.begin() + i);
				WinList.resize(WinList.size());
				idbgmsg("Window Minimized: %d", hwndP);
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL RegisterMainHotkeys(HWND &hwnd)
{
	arrowKeyRight = GlobalAddAtomA("arrowKeyRight");
	arrowKeyLeft = GlobalAddAtomA("arrowKeyLeft");

	RegisterHotKey(hwnd, arrowKeyRight, MOD_CONTROL | MOD_WIN, VK_RIGHT);
	RegisterHotKey(hwnd, arrowKeyLeft, MOD_CONTROL | MOD_WIN, VK_LEFT);

	return TRUE;
}


int SendWindowToMonitor(HWND &hwnd, std::vector<Monitor> &MonList)
{
	RECT rect;

	GetWindowRect(hwnd, &rect);
	InflateRect(&rect, -2, -2);
	for(int j = 0; j < MonList.size(); j++)
	{
		if((MonList.at(j).lB <= rect.left && rect.left <= MonList.at(j).rB) && (MonList.at(j).tB <= rect.bottom && rect.bottom <= MonList.at(j).bB))
		{
			MonList.at(j).WindowList.push_back(hwnd);
			idbgmsg("Window %d",NULL);
			idbgmsg(" sent to Monitor %d", j);
			idbgmsg(" Monitor %d", j);
			idbgmsg(" has %d windows", MonList.at(j).WindowList.size());
			return j;
		}
	}
	return FALSE;
}

BOOL ChangeDll(int direction)
{
	int cDll = 0;
	int cMon = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	for(int i = 0; i < dllList.size(); i++)
	{
		if(!(strcmp(MonitorList.at(cMon).uDllName, (char*)dllList.at(i).c_str())))
		{
			cDll = i;
			break;
		}
	}
	if((cDll + direction > dllList.size() - 1)||(cDll + direction < 0))
	{
		return FALSE;
	}
	else
	{
		if(MonitorList.at(FindCurrentMonitor(GetForegroundWindow(), MonitorList)).SetFunctions((char*)dllList.at(cDll + direction).c_str()))
		{
			return TRUE;
		}
		return FALSE;
	}
}


int FindDestroyedWindow(HWND hwnd, std::vector<Monitor> &MonList)
{
        for(int i = 0; i < MonList.size(); i++)
        {
                for(int j = 0; j < MonList.at(i).WindowList.size(); j++)
                {
                        if(MonList.at(i).WindowList.at(j) == hwnd)
                        {
                                MonList.at(i).WindowList.erase(MonList.at(i).WindowList.begin() + j);
                                return i;
                        }
                }
        }
        return 0;
}

BOOL UpdateMonitorHotkeys(int currentMonitor, HWND hwnd)
{
	if(MonitorList.at(currentMonitor).rhFunc(hwnd))
	{
		return TRUE;
	}
	return FALSE;
}

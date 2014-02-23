#include "TildePlusPlus.h"


BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList){
	HWND hwndP = reinterpret_cast<HWND>(lParam);
	int CurrentMonitor = 0;

	if(wParam == HSHELL_WINDOWCREATED)
	{
		WinList.push_back(hwndP);
		CurrentMonitor = SendWindowToMonitor(hwndP, MonitorList);
		MonitorList.at(CurrentMonitor).uFunc(1, hwndP, CurrentMonitor);
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
				MonitorList.at(CurrentMonitor).uFunc(0, hwndP, CurrentMonitor);
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

BOOL RegisterMainHotkeys(HWND hwnd)
{
	int error = GetLastError();
	error;

	arrowKeyRight = 0xA500;
	arrowKeyLeft =  0xA501;
	arrowKeyDown =  0xA502;
	
	numRow1 =  0xA503;
	numRow2 =  0xA504;
	numRow3 =  0xA505;
	numRow4 =  0xA506;
	numRow5 =  0xA507;
	numRow6 =  0xA508;
	numRow7 =  0xA509;
	numRow8 =  0xA510;
	numRow9 =  0xA511;

	numRow1Alt =  0xA512;
	numRow2Alt =  0xA513;
	numRow3Alt =  0xA514;
	numRow4Alt =  0xA515;
	numRow5Alt =  0xA516;
	numRow6Alt =  0xA517;
	numRow7Alt =  0xA518;
	numRow8Alt =  0xA519;
	numRow9Alt =  0xA520;

	RegisterHotKey(hwnd, arrowKeyRight, MOD_CONTROL | MOD_WIN, VK_RIGHT);
	RegisterHotKey(hwnd, arrowKeyLeft, MOD_CONTROL | MOD_WIN, VK_LEFT);
	RegisterHotKey(hwnd, arrowKeyDown, MOD_CONTROL | MOD_WIN, VK_DOWN);

	RegisterHotKey(hwnd, numRow1, MOD_CONTROL |  MOD_WIN, VK_NUMPAD1);
	RegisterHotKey(hwnd, numRow2, MOD_CONTROL |  MOD_WIN, VK_NUMPAD2);
	RegisterHotKey(hwnd, numRow3, MOD_CONTROL |  MOD_WIN, VK_NUMPAD3);
	RegisterHotKey(hwnd, numRow4, MOD_CONTROL |  MOD_WIN, VK_NUMPAD4);
	RegisterHotKey(hwnd, numRow5, MOD_CONTROL |  MOD_WIN, VK_NUMPAD5);
	RegisterHotKey(hwnd, numRow6, MOD_CONTROL |  MOD_WIN, VK_NUMPAD6);
	RegisterHotKey(hwnd, numRow7, MOD_CONTROL |  MOD_WIN, VK_NUMPAD7);
	RegisterHotKey(hwnd, numRow8, MOD_CONTROL |  MOD_WIN, VK_NUMPAD8);
	RegisterHotKey(hwnd, numRow9, MOD_CONTROL |  MOD_WIN, VK_NUMPAD9);

	RegisterHotKey(hwnd, numRow1Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD1);
	RegisterHotKey(hwnd, numRow2Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD2);
	RegisterHotKey(hwnd, numRow3Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD3);
	RegisterHotKey(hwnd, numRow4Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD4);
	RegisterHotKey(hwnd, numRow5Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD5);
	RegisterHotKey(hwnd, numRow6Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD6);
	RegisterHotKey(hwnd, numRow7Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD7);
	RegisterHotKey(hwnd, numRow8Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD8);
	RegisterHotKey(hwnd, numRow9Alt, MOD_CONTROL |  MOD_WIN | MOD_ALT, VK_NUMPAD9);

	error = GetLastError();
	error;
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
			MonList.at(j).Workspaces[MonList[j].cWS].push_back(hwnd);
			idbgmsg("Window %d",NULL);
			idbgmsg(" sent to Monitor %d", j);
			idbgmsg(" Monitor %d", j);
			idbgmsg(" has %d windows", MonList.at(j).Workspaces[MonList[j].cWS].size());
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
                for(int j = 0; j < MonList.at(i).Workspaces[MonList[i].cWS].size(); j++)
                {
                        if(MonList.at(i).Workspaces[MonList[i].cWS].at(j) == hwnd)
                        {
                                MonList.at(i).Workspaces[MonList[i].cWS].erase(MonList.at(i).Workspaces[MonList[i].cWS].begin() + j);
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

BOOL HandleWorkspaceKey(WPARAM wParam)
{
	int currentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	if(wParam == numRow1)
	{
		ActivateWorkspace(0, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow1Alt)
	{
		SendWindowToWorkspace(0, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow2)
	{
		ActivateWorkspace(1, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow2Alt)
	{
		SendWindowToWorkspace(1, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow3)
	{
		ActivateWorkspace(2, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow3Alt)
	{
		SendWindowToWorkspace(2, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow4)
	{
		ActivateWorkspace(3, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow4Alt)
	{
		SendWindowToWorkspace(3, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow5)
	{
		ActivateWorkspace(4, MonitorList[currentMonitor].cWS);
	}
	if(wParam == numRow5Alt)
	{
		SendWindowToWorkspace(4, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow6)
	{
		ActivateWorkspace(5, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow6Alt)
	{
		SendWindowToWorkspace(5, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow7)
	{
		ActivateWorkspace(6, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow7Alt)
	{
		SendWindowToWorkspace(6, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow8)
	{
		ActivateWorkspace(7, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow8Alt)
	{
		SendWindowToWorkspace(7, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow9)
	{
		ActivateWorkspace(8, MonitorList[currentMonitor].cWS);
	}

	if(wParam == numRow9Alt)
	{
		SendWindowToWorkspace(8, MonitorList[currentMonitor].cWS);
	}
	return FALSE;
}

BOOL ActivateWorkspace(int Workspace, int cWS)
{
	int currentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	if(cWS == Workspace)
	{
		return TRUE;
	}

	if(MonitorList[currentMonitor].Workspaces[Workspace].size() == 0)
	{
		return FALSE;
	}

	for(int i = 0; i < MonitorList[currentMonitor].Workspaces[cWS].size(); i++)
	{
		ShowWindow(MonitorList[currentMonitor].Workspaces[cWS][i], SW_MINIMIZE);
	}
	for(int i = 0; i < MonitorList[currentMonitor].Workspaces[Workspace].size(); i++)
	{
		ShowWindow(MonitorList[currentMonitor].Workspaces[Workspace][i], SW_SHOWNORMAL);
	}
	MonitorList[currentMonitor].cWS = Workspace;
	MonitorList[currentMonitor].tFunc(currentMonitor);
	return TRUE;
}

BOOL SendWindowToWorkspace(int Workspace, int cWS)
{
	int currentMonitor = FindCurrentMonitor(GetForegroundWindow(), MonitorList);
	HWND activeWindow = GetForegroundWindow();
	if(cWS == Workspace)
	{
		return TRUE;
	}
	for(int i = 0; i < MonitorList[currentMonitor].Workspaces[cWS].size(); i++)
	{
		if(MonitorList[currentMonitor].Workspaces[cWS][i] == activeWindow)
		{
			MonitorList[currentMonitor].Workspaces[Workspace].push_back(activeWindow);
			ShowWindow(MonitorList[currentMonitor].Workspaces[cWS][i], SW_MINIMIZE);
			MonitorList[currentMonitor].Workspaces[cWS].erase(MonitorList[currentMonitor].Workspaces[cWS].begin() + i);
			if(MonitorList[currentMonitor].Workspaces[cWS].size() == 0)
			{
				MonitorList[currentMonitor].cWS = Workspace;
				for(int i = 0; i < MonitorList[currentMonitor].Workspaces[Workspace].size(); i++)
				{
					ShowWindow(MonitorList[currentMonitor].Workspaces[Workspace][i], SW_SHOWNORMAL);
				}
			}
			MonitorList[currentMonitor].tFunc(currentMonitor);
			return TRUE;
		}
	}
	return FALSE;
}
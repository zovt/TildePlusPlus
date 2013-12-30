#include "TildePlusPlus.h"

BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList, updateFunction (&function)){
	HWND hwndP = reinterpret_cast<HWND>(lParam);
	if(wParam == HSHELL_WINDOWCREATED)
	{
		WinList.push_back(hwndP);
		idbgmsg("Window Created: %d", hwndP);
		function(1,hwndP);
		return TRUE;
	}
	else if(wParam == HSHELL_WINDOWDESTROYED)
	{
		for(int i = 0; i < WinList.size(); i++)
		{
			if(WinList.at(i) == hwndP)
			{
				WinList.erase(WinList.begin() + i);
				WinList.resize(WinList.size());
				idbgmsg("Window Destroyed: %d", hwndP);
				function(0,hwndP);
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
				function(2, hwndP);
				return TRUE;
			}
		}
	}
	return FALSE;
}
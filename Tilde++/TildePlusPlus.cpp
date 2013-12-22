#include "TildePlusPlus.h"

const UINT created = 396850;
const UINT destroyed = 396851;

BOOL UpdateWindowList(WPARAM wParam, LPARAM lParam, std::vector<HWND> &WinList, updateFunction (&function)){
	HWND hwndP = reinterpret_cast<HWND>(lParam);
	if(wParam == HSHELL_WINDOWCREATED)
	{
		WinList.push_back(hwndP);
		idbgmsg("Window Created: %d", hwndP);
		SendMessage(HWND_BROADCAST,created,wParam,lParam);
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
				SendMessage(HWND_BROADCAST,destroyed,wParam,lParam);
				function(0,hwndP);
				return TRUE;
			}
		}
	}
	return FALSE;
}
#include "main.h"
#include "dbgmsg.h"
#include "Window.h"
#include <iostream>
int main()
{
	char buffer[64];
	char dwBuf[128];

	bool fakewindowpassed = FALSE;

	tagWINDOWINFO wi;

	EnumWindows(sendWindowsToTempWindowArray, NULL);

	WindowList.resize(numWindows);

	for(int i = 0; i < numWindows; i++){
		dbgmsg("Window HWND: %p",tempWindowList.at(i));
		dbgmsg("Is Iconic: %d",IsIconic(tempWindowList.at(i)));
		dbgmsg("Is Visible: %d",IsWindowVisible(tempWindowList.at(i)));
		dbgmsg("Is Enabled: %d",IsWindowEnabled(tempWindowList.at(i)));
		if(IsWindowVisible(tempWindowList.at(i)) && GetWindowTextA(tempWindowList.at(i), buffer, 64)!=0 && strcmp(buffer, "Program Manager")!=0 && strcmp(buffer, " ")!=0 && strcmp(buffer,"")!=0)
		{
			if(fakewindowpassed)
			{
				sendWindowsToWindowArray(tempWindowList.at(i));
				idbgmsg("Window sent to array",NULL);
				idbgmsg("Window HWND in array: %p", WindowList.at(WindowList.size()-1));
				idbgmsg("Window Title: %d",buffer);
			}
			{
				fakewindowpassed = TRUE;
			}
		}
	}
	WindowList.erase(WindowList.begin());
	numWindows = WindowList.size();
	for(int i = 0; i < numWindows;i++){
		GetWindowTextA(WindowList.at(i), buffer, 64);
		GetWindowInfo(WindowList.at(i), &wi);
		sprintf(dwBuf, "%d", wi.dwStyle);
		idbgmsg("Window %d name: %p", i, buffer);
		idbgmsg("Window %d style: %p", i, dwBuf);
	}
	dbgmsg("numWindows: %d", numWindows);
	LoadLibrary(L"Ship.dll");
	std::cin.get();
	return 0;
}

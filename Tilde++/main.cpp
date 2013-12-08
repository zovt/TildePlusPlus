#include "main.h"
#include "Window.h"
#include <iostream>
int main()
{
	char buffer[64];
	char dwBuf[128];

	tagWINDOWINFO wi;

	EnumWindows(sendWindowsToTempWindowArray, NULL);

	WindowArray.resize(numWindows);

	for(int i = 0; i < numWindows; i++){
		dbgmsg("Window HWND: %p",tempWindowArray.at(i));
		dbgmsg("Is Iconic: %d",IsIconic(tempWindowArray.at(i)));
		dbgmsg("Is Visible: %d",IsWindowVisible(tempWindowArray.at(i)));
		dbgmsg("Is Enabled: %d",IsWindowEnabled(tempWindowArray.at(i)));
		if(IsWindowVisible(tempWindowArray.at(i)) && GetWindowTextA(tempWindowArray.at(i), buffer, 64)!=0 && strcmp(buffer, "Program Manager")!=0 && strcmp(buffer, " ")!=0)
		{
			sendWindowsToWindowArray(tempWindowArray.at(i));
			idbgmsg("Window sent to array",NULL);
			idbgmsg("Window HWND in array: %p", WindowArray.at(WindowArray.size()-1));
			idbgmsg("Window Title: %d",buffer);
		}
	}
	numWindows = WindowArray.size();
	for(int i = 0; i < numWindows;i++){
		GetWindowTextA(WindowArray.at(i), buffer, 64);
		GetWindowInfo(tempWindowArray.at(i), &wi);
		sprintf(dwBuf, "%d", wi.dwStyle);
		idbgmsg("Window %d name: %p", i, buffer);
		idbgmsg("Window %d style: %p", i, buffer);
	}
	dbgmsg("numWindows: %d", numWindows);
	LoadLibrary(L"Ship.dll");
	idbgmsg("THIS IS IMPORTANT",NULL);
	std::cin.get();
	return 0;
}

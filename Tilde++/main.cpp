#include "main.h"
#include "dbgmsg.h"
#include "Window.h"
#include <iostream>

const PCWSTR g_szClassName = L"myWindowClass";
char hwndow[50];

LRESULT CALLBACK getMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(wParam)
	{
		UpdateWindowList(lParam, WindowList);
	}
	return 0;
}



int main(HINSTANCE hInstance, HINSTANCE hPrevInstance)
{
	UINT hookMsg;
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = getMessage;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

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
	
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed", L"Error!!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		g_szClassName,
		L"Tilde++",
		WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 240,120,
		HWND_MESSAGE, NULL, hInstance, NULL);

	RegisterShellHookWindow(hwnd);
	hookMsg = RegisterWindowMessageA("SHELLHOOK");

	std::cin.get();
	return 0;
}

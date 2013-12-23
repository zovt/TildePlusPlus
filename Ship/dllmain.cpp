// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Tiling.h"
#include "Update.h"
#include "Window.h"

const PCWSTR g_szClassName = L"shipWindow";
UINT shellHookMessage;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("########## Ship loaded! ##########\n");
		EnumDisplayMonitors(NULL, NULL, GetMonitors, NULL);
		SortWindowsToMonitors(WindowList, MonitorList);
		Tile(MonitorList);
		

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


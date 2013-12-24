#include "stdafx.h"
#include "Config.h"

Options::Options() {
	screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor = 0;
	PortWindows = 1;
	
	char locationBuffer[MAX_PATH];
	char dirBuf[MAX_PATH];

	GetCurrentDirectoryA(MAX_PATH, dirBuf);
	GetFullPathNameA("Config.ini",MAX_PATH,locationBuffer,NULL);

	BHor = GetPrivateProfileIntA("Windows","BHor",0,locationBuffer);
	dbgmsg("PrivateError: %d", GetLastError());
	BVer = GetPrivateProfileIntA("Windows","BVer",0,locationBuffer);
	PHor = GetPrivateProfileIntA("Windows","PHor",0,locationBuffer);
	PVer = GetPrivateProfileIntA("Windows","PVer",0,locationBuffer);
	PortWindows = GetPrivateProfileIntA("Windows","PortWindows",1,locationBuffer);

	// Get Settings
	TBLSize = GetPrivateProfileIntA("Settings","TBLSize",0,locationBuffer);
	TBRSize = GetPrivateProfileIntA("Settings","TBRSize",0,locationBuffer);
	TBTSize = GetPrivateProfileIntA("Settings","TBTSize",0,locationBuffer);
	TBBSize = GetPrivateProfileIntA("Settings","TBBSize",0,locationBuffer);
}

Options::~Options() {

}

void Options::readOptions(){
	// Get Window options
	BHor = GetPrivateProfileInt(L"Windows",L"BHor",0,L"Config.ini");
	BVer = GetPrivateProfileInt(L"Windows",L"BVer",0,L"Config.ini");
	PHor = GetPrivateProfileInt(L"Windows",L"PHor",0,L"Config.ini");
	PVer = GetPrivateProfileInt(L"Windows",L"PVer",0,L"Config.ini");

	// Get Settings
	TBLSize = GetPrivateProfileInt(L"Settings",L"TBLSize",0,L"Config.ini");
	TBRSize = GetPrivateProfileInt(L"Settings",L"TBRSize",0,L"Config.ini");
	TBTSize = GetPrivateProfileInt(L"Settings",L"TBTSize",0,L"Config.ini");
	TBBSize = GetPrivateProfileInt(L"Settings",L"TBBSize",0,L"Config.ini");
}

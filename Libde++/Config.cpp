#include "stdafx.h"
#include "Config.h"

Options::Options() {
	screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor = 0;	
	TaskbarEntryFont = new WCHAR[MAX_PATH];
	char locationBuffer[MAX_PATH];
	WCHAR *wLocationBuffer = new WCHAR[MAX_PATH];

	GetFullPathNameA("Config.ini",MAX_PATH,locationBuffer,NULL);
	// Getting Padding Settings
	BHor = GetPrivateProfileIntA("Windows","BHor",0,locationBuffer);
	BVer = GetPrivateProfileIntA("Windows","BVer",0,locationBuffer);
	PHor = GetPrivateProfileIntA("Windows","PHor",0,locationBuffer);
	PVer = GetPrivateProfileIntA("Windows","PVer",0,locationBuffer);

	// Get Taskbar Settings
	TBLSize = GetPrivateProfileIntA("Taskbar","TBLSize",0,locationBuffer);
	TBRSize = GetPrivateProfileIntA("Taskbar","TBRSize",0,locationBuffer);
	TBTSize = GetPrivateProfileIntA("Taskbar","TBTSize",0,locationBuffer);
	TBBSize = GetPrivateProfileIntA("Taskbar","TBBSize",0,locationBuffer);

	GetFullPathNameW(L"Config.ini",MAX_PATH,wLocationBuffer,NULL);
	GetPrivateProfileStringW(L"Taskbar",L"TaskbarEntryFont",L"Arial",TaskbarEntryFont,100,wLocationBuffer);
	TaskbarHeight = GetPrivateProfileIntA("Taskbar","TaskbarHeight", 20, locationBuffer);
	TaskbarEntryFontSize = GetPrivateProfileIntA("Taskbar","TaskbarEntryFontSize",12,locationBuffer);
	TaskbarEnabled = GetPrivateProfileIntA("Taskbar","TaskbarEnabled",0,locationBuffer);
}

Options::~Options() {

}

void Options::readOptions(){
	char locationBuffer[MAX_PATH];
	
	GetFullPathNameA("Config.ini",MAX_PATH,locationBuffer,NULL);

	BHor = GetPrivateProfileIntA("Windows","BHor",0,locationBuffer);
	BVer = GetPrivateProfileIntA("Windows","BVer",0,locationBuffer);
	PHor = GetPrivateProfileIntA("Windows","PHor",0,locationBuffer);
	PVer = GetPrivateProfileIntA("Windows","PVer",0,locationBuffer);

	// Get Settings
	TBLSize = GetPrivateProfileIntA("Settings","TBLSize",0,locationBuffer);
	TBRSize = GetPrivateProfileIntA("Settings","TBRSize",0,locationBuffer);
	TBTSize = GetPrivateProfileIntA("Settings","TBTSize",0,locationBuffer);
	TBBSize = GetPrivateProfileIntA("Settings","TBBSize",0,locationBuffer);
}

TILDEAPI Options * options = new Options(); 
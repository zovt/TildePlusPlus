#include "stdafx.h"
#include "Config.h"

Options::Options() {
	screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor = 0;	
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
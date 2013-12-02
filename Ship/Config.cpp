#include "stdafx.h"
#include "Config.h"

Options::Options() {
	screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor = 0;
}

Options::~Options() {

}

void Options::readOptions(){
	// Get Window options
	BHor = GetPrivateProfileInt(L"Windows",L"BHor",0,L"../Config.ini");
	BVer = GetPrivateProfileInt(L"Windows",L"BVer",0,L"../Config.ini");
	PHor = GetPrivateProfileInt(L"Windows",L"PHor",0,L"../Config.ini");
	PVer = GetPrivateProfileInt(L"Windows",L"PVer",0,L"../Config.ini");

	// Get Settings
	TBLSize = GetPrivateProfileInt(L"Settings",L"TBLSize",0,L"../Config.ini");
	TBRSize = GetPrivateProfileInt(L"Settings",L"TBRSize",0,L"../Config.ini");
	TBTSize = GetPrivateProfileInt(L"Settings",L"TBTSize",0,L"../Config.ini");
	TBBSize = GetPrivateProfileInt(L"Settings",L"TBBSize",0,L"../Config.ini");
}

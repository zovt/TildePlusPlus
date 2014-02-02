#include "TildePlusPlus.h"
// defining an Options class for easy access to options
class Options {
public:
	Options();
	~Options();
	int screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVert, BHor, PVert, PHor;
	void readOptions();
};

Options::Options() {
	screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVert, BHor, PVert, PHor = 0;
}

Options::~Options() {

}

void Options::readOptions(){
	// Get Window options
	BHor = GetPrivateProfileInt(L"Windows",L"BHor",0,L"../Config.ini");
	BVert = GetPrivateProfileInt(L"Windows",L"BVert",0,L"../Config.ini");
	PHor = GetPrivateProfileInt(L"Windows",L"PHor",0,L"../Config.ini");
	PVert = GetPrivateProfileInt(L"Windows",L"PVert",0,L"../Config.ini");

	// Get Settings
	
}
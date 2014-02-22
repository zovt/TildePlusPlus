#include "stdafx.h"

// defining an Options class for easy access to options
class Options {
public:
	int screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor;
	void readOptions();
	Options();
	~Options();
};

extern "C" TILDEAPI Options * options;
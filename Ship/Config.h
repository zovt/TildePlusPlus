#include "stdafx.h"
// defining an Options class for easy access to options
class Options {
public:
	Options();
	~Options();
	int screenWidth, screenHeight, TBLSize, TBRSize, TBTSize, TBBSize, BVer, BHor, PVer, PHor;
	void readOptions();
};


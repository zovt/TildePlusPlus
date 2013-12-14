#include "stdafx.h"
#ifdef DEBUGENABLED
#define dbgmsg(string, vars) printf("!!!!!!!!!!!"##string##"!!!!!!!!!!!\n", vars)
#define idbgmsg(string, vars) printf(string##"\n", vars)
#else
#define dbgmsg(a, b) ""
#define idbgmsg(a, b) ""
#endif

#ifdef ENABLEIMPORTS
#define TILDEAPI __declspec(dllimport)
#else
#define TILDEAPI __declspec(dllexport)
#endif
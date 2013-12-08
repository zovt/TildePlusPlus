// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <Windows.h>


// TODO: reference additional headers your program requires here
#ifdef ENABLEIMPORTS
#define TILDEAPI __declspec(dllimport)
#else
#define TILDEAPI __declspec(dllexport)
#endif

#include <iostream>

//#define DEBUG_ENABLED

#ifdef DEBUG_ENABLED
#define dbgmsg(a, b) printf("!!!!!!!!!!!"##a##"!!!!!!!!!!!\n", b)
#define idbgmsg(a, b) printf(a##"\n", b)
#else
#define dbgmsg(a, b) ""
#define idbgmsg(a, b) ""
#endif
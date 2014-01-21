#include "stdafx.h"
#include <vector>

typedef BOOL (*registerHotkeyFunction)(HWND(&));
typedef BOOL (*handleHotkeyFunction)(int);
typedef BOOL (*updateFunction)(int, HWND);
typedef void  (*tileFunction)(int);
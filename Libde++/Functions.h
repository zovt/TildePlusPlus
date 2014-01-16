#include "stdafx.h"

typedef BOOL (*registerHotkeyFunction)(HWND(&));
typedef BOOL (*handleHotkeyFunction)(int);
typedef BOOL (*updateFunction)(int, HWND, int);

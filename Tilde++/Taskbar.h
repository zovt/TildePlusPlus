#include "TildePlusPlus.h"
#include "../Libde++/Config.h"
#include <ObjIdl.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")
#pragma once
using namespace Gdiplus;

extern WNDCLASSEX gdiWindow;

extern const PCWSTR g_gdiWindowClassName;
extern char gdiWindowChar;

extern GdiplusStartupInput gdiplusStartupInput;
extern ULONG_PTR gdiplusToken;

struct Taskbar
{
public:
	HDC hdc;
	HWND hwnd;
	Graphics *graphics;
	SolidBrush *brush;
	Taskbar();
	VOID Initialize(HDC hdc);
};

extern std::vector<Taskbar> taskbars;

extern Font mFont;
extern FontFamily *mFontFamily;
extern PrivateFontCollection mFontCollection;





LRESULT CALLBACK gdiWindowProc(HWND hwnd, MSG msg, WPARAM wParam, LPARAM lParam);
VOID OnPaint(HDC hdc);
VOID RegisterTaskbar(HINSTANCE hInstance);
VOID UpdateTaskbar(Gdiplus::Graphics *graphics, Gdiplus::SolidBrush *brush,int curMon);
VOID LoadFont();
namespace ns
{
};
using namespace ns;
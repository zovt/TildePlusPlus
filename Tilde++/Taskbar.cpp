#include "Taskbar.h"
using namespace Gdiplus;
int cMon = -1;
HDC mHdc;

Taskbar::Taskbar()
{

};

VOID Taskbar::Initialize(HDC hdc)
{
	graphics = new Graphics(hdc);
	brush = new SolidBrush(Color(255,255,255,255));
}

LRESULT CALLBACK gdiWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC nHdc;
	switch(msg)
	{
	case WM_PAINT:
		nHdc = BeginPaint(hwnd, &ps);
		mHdc = nHdc;
		OnPaint(mHdc);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

VOID OnPaint(HDC hdc)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::SolidBrush colorBrush(Color(255,0,0,0));
	taskbars.at(cMon).brush = &colorBrush;
	taskbars.at(cMon).Initialize(hdc);
	taskbars.at(cMon).hdc = hdc;
	UpdateTaskbar(taskbars.at(cMon).graphics, &colorBrush, FindCurrentMonitor(GetForegroundWindow(), MonitorList));
}

const PCWSTR g_gdiWindowClassName = L"Taskbar";
GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;
char gdiWindowChar;
WNDCLASSEX gdiWindow;
std::vector<Taskbar> taskbars;


VOID RegisterTaskbar(HINSTANCE hInstance)
{
	gdiWindow.cbSize = sizeof(WNDCLASSEX);
	gdiWindow.lpfnWndProc = gdiWindowProc;
	gdiWindow.cbClsExtra = 0;
	gdiWindow.cbWndExtra = 0;
	gdiWindow.hInstance = hInstance;
	gdiWindow.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	gdiWindow.lpszMenuName = NULL;
	gdiWindow.lpszClassName = g_gdiWindowClassName;

	RegisterClassEx(&gdiWindow);
	for(int i = 0; i < MonitorList.size(); i++)
	{
		cMon++;
		taskbars.push_back(Taskbar());
		taskbars.at(i).hwnd = CreateWindow(
			g_gdiWindowClassName,
			NULL,
			WS_CAPTION,
			0,
			0,
			1920,
			30,
			NULL,
			NULL,
			hInstance,
			NULL);
		SetWindowLong(taskbars.at(i).hwnd, GWL_STYLE, GetWindowLong(taskbars.at(i).hwnd, GWL_STYLE) & ~(WS_CAPTION));
		SetWindowPos(taskbars.at(i).hwnd, HWND_TOP, MonitorList.at(i).lB, MonitorList.at(i).tB, MonitorList.at(i).width, options->TaskbarHeight, SWP_FRAMECHANGED);
	
		ShowWindow(taskbars.at(i).hwnd, 5);
		UpdateWindow(taskbars.at(i).hwnd);
	}
}

FontFamily *mFontFamily;
Font mFont(mFontFamily, 10, FontStyleRegular, UnitPixel);
PrivateFontCollection mFontCollection;
int nNumFound = 0;

VOID LoadFont()
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	WCHAR famName[LF_FACESIZE];
	FontFamily nFontFamily[418];
	Status nStat = mFontCollection.AddFontFile(L"C:\\WINNT\\Fonts\\Arial.ttf");
	nStat = mFontCollection.GetFamilies(1, mFontFamily, &nNumFound);
	InstalledFontCollection ifc;
	int count = ifc.GetFamilyCount();
	ifc.GetFamilies(count,nFontFamily,&nNumFound);
	for(int i = 0; i < count; i++)
	{
		nFontFamily[i].GetFamilyName(famName);
		std::wcout << famName << '\n';
		if(!(lstrcmpW(famName, L"HaxrCorp 4089")))
		{
			mFontFamily = &nFontFamily[i];
		}
	}
	idbgmsg("",NULL);
}

VOID UpdateTaskbar(Graphics *graphics, SolidBrush *brush, int curMon)
{
	PointF pointF(30.0f, 10.0f);
	SolidBrush fontBrush(Color(255, 255, 255, 255));
	PWSTR windowTitle;
	Font mmFont(options->TaskbarEntryFont, options->TaskbarEntryFontSize, FontStyleRegular, UnitPixel);

	int w = (MonitorList.at(curMon).width)/MonitorList.at(curMon).WindowList.size();
	int h = options->TaskbarHeight;
	graphics->FillRectangle(brush, 0, 0, MonitorList.at(curMon).width, h);
	for(int i = 0; i < MonitorList.at(curMon).WindowList.size(); i++)
	{
		windowTitle = (PWSTR)VirtualAlloc(NULL, (DWORD)(GetWindowTextLength(MonitorList.at(curMon).WindowList.at(i))+1),MEM_COMMIT, PAGE_READWRITE);
		GetWindowText(MonitorList.at(curMon).WindowList.at(i), windowTitle, MAX_PATH);
		int len = wcslen(windowTitle);
		pointF.X = ((w*i) +3);
		pointF.Y = (h-options->TaskbarEntryFontSize)/2;
		if(graphics->DrawString(windowTitle, -1, &mmFont, pointF, &fontBrush))
		{
			idbgmsg("Updated!",NULL);
		}
		else
		{
			int me = GetLastError();
			GetLastError();
		}
	}
}
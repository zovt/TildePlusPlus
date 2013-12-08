#include "main.h"
#include "Window.h"
#include <iostream>
int main()
{
	EnumWindows(sendWindowsToTempWindowArray, NULL);
	WindowArray.resize(numWindows);
	for(int i = 0; i < numWindows; i++){
		std::cout << "Window HWND: " << tempWindowArray.at(i) << "\n";
		std::cout << "Is iconic: " << IsIconic(tempWindowArray.at(i)) << "\n";
		std::cout << "Is visible: " << IsWindowVisible(tempWindowArray.at(i)) << "\n";
		std::cout << "Is enabled: " << IsWindowEnabled(tempWindowArray.at(i)) << "\n";
		if(IsWindowVisible(tempWindowArray.at(i)))
		{
			sendWindowsToWindowArray(tempWindowArray.at(i));
			std::cout << "!!!!!!!!!!!!!!Window sent to array!!!!!!!!!!!!" << "\n";
			std::cout << "!!!!!!!!!!!!!!Window HWND in array: " << WindowArray.at(WindowArray.size()-1) << "!!!!!!!!!!!\n";
		}
	}
	numWindows = WindowArray.size();
	std::cout << "numWindows: " << numWindows << "\n";
	LoadLibrary(L"Ship.dll");
	std::cin.get();
	return 0;
}
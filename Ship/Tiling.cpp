#include "stdafx.h"
#include "Tiling.h"
#include <iostream>
void Tile()
{
	std::cout << "Tile() called!" << "\n";
	std::cout << "numWindows: " << numWindows << "\n";
	for(int i = 0; i < numWindows; i++){
		std::cout << "For loop at: " << i << "\n";
		MoveWindow(WindowArray.at(i), 0, 0, 1880, 1080, TRUE);
		MessageBox(NULL, L"HE", L"<L", MB_OK);
	}
}
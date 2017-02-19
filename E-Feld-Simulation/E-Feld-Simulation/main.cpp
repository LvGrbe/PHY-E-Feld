#include <iostream>
#include "Renderer.h"
#include <Windows.h>

#include <SFML\Graphics.hpp>


int main()  //Program Einstiegspunkt
{	
#ifndef _DEBUG 
	// Console ausblenden im Release
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_HIDE);
#endif

	Renderer rd;
	rd.run();

	return 0;
}
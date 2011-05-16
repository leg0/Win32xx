///////////////////////////////////////
// main.cpp

#include "stdafx.h"
#include "TextApp.h"


int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		// Start Win32++
		CTextApp theApp;

		// Run the application
		return theApp.Run();
	}
	
	catch (std::exception &e)
	{
		// Process the exception and quit 
		e.what();
		return -1;
	}
}


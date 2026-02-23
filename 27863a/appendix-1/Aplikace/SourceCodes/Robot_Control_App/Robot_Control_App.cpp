// Robot_Control_App.cpp : main project file.

#include "stdafx.h"
#include "IntroWin.h"
#include "DialogWin.h"
#include "ImgWin.h"
#include "MainWin.h"

using namespace Robot_Control_App;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	String ^Version = "2.0.0 /Alpha";
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew IntroWin(Version));
	Application::Run(gcnew MainWin(Version));
	return 0;
}


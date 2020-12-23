#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>


using namespace LVB42; // Название проекта
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	srand(static_cast<unsigned int>(time(0)));
	return 0;
}


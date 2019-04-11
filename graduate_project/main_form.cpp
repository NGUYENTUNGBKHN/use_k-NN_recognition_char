#include "main_form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	graduate_project::main_form form;
	Application::Run(%form);
	return 0;
}


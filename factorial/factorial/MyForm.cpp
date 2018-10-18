#include "MyForm.h"
#include "fact.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	factorial::MyForm form;
	Application::Run(%form);
}
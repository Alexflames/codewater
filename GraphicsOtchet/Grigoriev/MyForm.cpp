#include "Matrix.h"
#include "Transform.h"
#include <vector>
#include "Clip.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Graphics1::MyForm form;
	Application::Run(%form);
}


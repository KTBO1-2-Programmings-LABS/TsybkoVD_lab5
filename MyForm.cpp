#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault;
	Application::EnableVisualStyles;
	lab5_dotnet::MyForm app;
	Application::Run(%app);
}
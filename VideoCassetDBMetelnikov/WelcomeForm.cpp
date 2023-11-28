#include "WelcomeForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	VideoCassetDBMetelnikov::WelcomeForm form;
	Application::Run(% form);
	return 0;
}

System::Void VideoCassetDBMetelnikov::WelcomeForm::WelcomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
}

System::Void VideoCassetDBMetelnikov::WelcomeForm::backButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void VideoCassetDBMetelnikov::WelcomeForm::startBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    StartMenuForm^ form = gcnew StartMenuForm();
    form->Show();
    this->Hide();
}

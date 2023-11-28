#include "StartMenuForm.h"

System::Void VideoCassetDBMetelnikov::StartMenuForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::StartMenuForm::StaffButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LogInForStaffForm^ form = gcnew LogInForStaffForm();
	this->Hide();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::StartMenuForm::LogInButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SignInForm^ form = gcnew SignInForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::StartMenuForm::SignInButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	usersRegisterForm^ form = gcnew usersRegisterForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::StartMenuForm::StartMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}

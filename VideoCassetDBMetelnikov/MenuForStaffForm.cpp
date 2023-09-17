#include "MenuForStaffForm.h"

System::Void VideoCassetDBMetelnikov::MenuForStaffForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::MenuForStaffForm::ToStartButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::MenuForStaffForm::EditAndViewDBButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	EditAndViewDBForm^ form = gcnew EditAndViewDBForm();
	this->Hide();
	form->Show();
}

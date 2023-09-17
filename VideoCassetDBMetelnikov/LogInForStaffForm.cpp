#include "LogInForStaffForm.h"

System::Void VideoCassetDBMetelnikov::LogInForStaffForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::LogInForStaffForm::OkButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MenuForStaffForm^ form = gcnew MenuForStaffForm();
	this->Hide();
	form->Show();
}

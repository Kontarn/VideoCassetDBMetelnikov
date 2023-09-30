#include "HystoryOfBuyForm.h"

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::radioButton1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (radioButton1->Checked == true) {
		
	}
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::radioButton2_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (radioButton2->Checked == true)
		comboBox1->Enabled = "False";
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MenuForStaffForm^ form = gcnew MenuForStaffForm();
	this->Hide();
	form->Show();
}

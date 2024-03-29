#include "SignInForm.h"


System::Void VideoCassetDBMetelnikov::SignInForm::SignInButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	/**/
	
	
	SqlConnection^ sqlConn = gcnew SqlConnection(connString);
	SqlCommand^ sqlCmd = gcnew SqlCommand();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
	sqlCmd->CommandText = "AuthentificationUser";

	sqlCmd->Parameters->Add("@login", SqlDbType::VarChar, 30);
	sqlCmd->Parameters->Add("@pass", SqlDbType::VarChar, 30);

	sqlCmd->Parameters->Add("@user_id", SqlDbType::Int);
	sqlCmd->Parameters["@user_id"]->Direction = ParameterDirection::Output;

	sqlCmd->Parameters["@login"]->Value = usersLoginTxtBx->Text;
	sqlCmd->Parameters["@pass"]->Value = usersPassTxtBx->Text;

	sqlConn->Open();
	sqlCmd->ExecuteNonQuery();
	sqlConn->Close();
	if (sqlCmd->Parameters["@user_id"]->Value->ToString() != "") {
		//int userId = (int)sqlCmd->Parameters["@user_id"]->Value;
		RevievAndViewDBForm^ form = gcnew RevievAndViewDBForm(sqlCmd->Parameters["@user_id"]->Value->ToString());
		form->Show();
		this->Hide();
		//MessageBox::Show(Convert::ToString(userId), "���������");
	}
	else
	{
		MessageBox::Show("������������ �� ������", "������");
	}
		
}

System::Void VideoCassetDBMetelnikov::SignInForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::SignInForm::RegistrationButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	usersRegisterForm^ form = gcnew usersRegisterForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::SignInForm::SignInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}








#include "LogInForStaffForm.h"

System::Void VideoCassetDBMetelnikov::LogInForStaffForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::LogInForStaffForm::OkButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (authCodeTxtBx->Text->Length == 0) {
		MessageBox::Show("Пожалуйста, заполните поле с кодом", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	sqlConn = gcnew SqlConnection(connString);
	SqlCommand^ sqlCmd = gcnew SqlCommand();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
	sqlCmd->CommandText = "staffAuthorization";

	sqlCmd->Parameters->Add("@authCode", SqlDbType::VarChar, 50);
	sqlCmd->Parameters["@authCode"]->Value = authCodeTxtBx->Text;
	sqlCmd->Parameters->Add("@res", SqlDbType::Int);
	sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

	sqlConn->Open();
	sqlCmd->ExecuteNonQuery();
	sqlConn->Close();

	if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "1") {
		EditAndViewDBForm^ form = gcnew EditAndViewDBForm();
		form->Show();
		this->Hide();
	}
	else {
		MessageBox::Show("Неверный код доступа, повторите попытку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

System::Void VideoCassetDBMetelnikov::LogInForStaffForm::LogInForStaffForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}

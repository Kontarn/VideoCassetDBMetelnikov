#include "EditAccessCodeForm.h"

System::Void VideoCassetDBMetelnikov::EditAccessCodeForm::backBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::EditAccessCodeForm::editAcessCodeBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (oldCodeTxtBx->Text->Length == 0 || newCodeTxtBx->Text->Length == 0) {
		MessageBox::Show("Пожалуйста, заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	sqlConn = gcnew SqlConnection(connString);
	SqlCommand^ sqlCmd = gcnew SqlCommand();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
	sqlCmd->CommandText = "editStaffAuthCode";

	sqlCmd->Parameters->Add("@oldAuthCode", SqlDbType::VarChar, 50);
	sqlCmd->Parameters["@oldAuthCode"]->Value = oldCodeTxtBx->Text;
	sqlCmd->Parameters->Add("@newAuthCode", SqlDbType::VarChar, 50);
	sqlCmd->Parameters["@newAuthCode"]->Value = newCodeTxtBx->Text;
	sqlCmd->Parameters->Add("@res", SqlDbType::Int);
	sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

	sqlConn->Open();
	sqlCmd->ExecuteNonQuery();
	sqlConn->Close();

	if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "1") {
		MessageBox::Show("Пароль изменён", "Успешно");
		this->Hide();
	}
	else {
		MessageBox::Show("Старый пароль указан не верно, повторите попытку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

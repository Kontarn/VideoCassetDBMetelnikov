#include "usersRegisterForm.h"

System::Void VideoCassetDBMetelnikov::usersRegisterForm::ExitBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void VideoCassetDBMetelnikov::usersRegisterForm::BackBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    SignInForm^ form = gcnew SignInForm();
    form->Show();
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::usersRegisterForm::usersRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (usersFioTxtBx->Text->Length == 0 && usernameTxtBx->Text->Length == 0 && usersPassTxtBx->Text->Length == 0) {
        MessageBox::Show("Пожалуйста, заполните все обязательные поля(ФИО, логин и пароль)", "Ошибка", MessageBoxButtons::OK,
            MessageBoxIcon::Error);
        return;
    }
    sqlConn = gcnew SqlConnection(connString);
    SqlCommand^ sqlCmd = gcnew SqlCommand();
    sqlCmd->Connection = sqlConn;

    sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
    sqlCmd->CommandText = "insertUsersData";

    sqlCmd->Parameters->Add("@fio", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@fio"]->Value = usersFioTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@login", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@login"]->Value = usernameTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@gender", SqlDbType::VarChar, 1);
    sqlCmd->Parameters["@gender"]->Value = usersGenderCmbBx->Text->ToString();
    sqlCmd->Parameters->Add("@birthD", SqlDbType::SmallDateTime);
    sqlCmd->Parameters["@birthD"]->Value = usersBirthDayDtTmPckr->Text->ToString();
    sqlCmd->Parameters->Add("@phoneNum", SqlDbType::VarChar, 20);
    sqlCmd->Parameters["@phoneNum"]->Value = usersPhoneBTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@pass", SqlDbType::VarChar, 30);
    sqlCmd->Parameters["@pass"]->Value = usersPassTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@res", SqlDbType::Int);
    sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();
    // if the result was executed correctly, then @res is equal to the created userID
    if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) != "0") {
        MessageBox::Show("Данные добавлены", "Успешно", MessageBoxButtons::OK);
        RevievAndViewDBForm^ form = gcnew RevievAndViewDBForm(sqlCmd->Parameters["@res"]->Value->ToString());
        form->Show();
        this->Hide();
    }
    else {
        MessageBox::Show("Такой логин уже существует", "Ошибка", MessageBoxButtons::OK,
            MessageBoxIcon::Error);
        return;
    }
}

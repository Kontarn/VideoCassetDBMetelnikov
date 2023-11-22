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
    if (usersFioTxtBx->Text->Length == 0 || usernameTxtBx->Text->Length == 0 || usersPassTxtBx->Text->Length == 0 
        || usersGenderCmbBx->Text->Length == 0 || usersPhoneBTxtBx->Text->Length == 0 || usersBirthDayDtTmPckr->Text->Length == 0) {
        MessageBox::Show("Пожалуйста, заполните все обязательные поля", "Ошибка", MessageBoxButtons::OK,
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

    if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "0") {
        MessageBox::Show("Такой логин уже существует", "Ошибка", MessageBoxButtons::OK,
            MessageBoxIcon::Error);
        return;
    }
    else if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "-1") {
        MessageBox::Show("Такой номер телефона уже зарегистрирован", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    else {
        MessageBox::Show("Данные добавлены", "Успешно", MessageBoxButtons::OK);
        RevievAndViewDBForm^ form = gcnew RevievAndViewDBForm(sqlCmd->Parameters["@res"]->Value->ToString());
        form->Show();
        this->Hide();
    }
}

System::Void VideoCassetDBMetelnikov::usersRegisterForm::usersRegisterForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    this->usersBirthDayDtTmPckr->MaxDate = DateTime::Now;

}

System::Void VideoCassetDBMetelnikov::usersRegisterForm::usersFioTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127 && e->KeyChar != 32)
        e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::usersRegisterForm::usersPhoneBTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127 && e->KeyChar != 43)
        e->Handled = true;
}

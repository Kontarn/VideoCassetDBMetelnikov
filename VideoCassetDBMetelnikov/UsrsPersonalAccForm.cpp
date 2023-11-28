#include "UsrsPersonalAccForm.h"

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::каталогФильмовToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    RevievAndViewDBForm^ form = gcnew RevievAndViewDBForm(userID);
    form->Show();
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::ExitBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::UsrsPersonalAccForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    sqlConn = gcnew SqlConnection(connString);
    SqlCommand^ sqlCmd = gcnew SqlCommand("SELECT @nickname = usersLogin, @usersFio = FIO, @usersGender = Gender, \
        @usersBirthD = Birthday, @usersPhoneNum = PhoneNum FROM Client c \
        JOIN Passwords p ON c.ClientID = p.ClientID WHERE c.ClientID = @usersID", sqlConn);

    SqlDataAdapter^ sqlDA = gcnew SqlDataAdapter("SELECT f.Name AS Фильм, TransactDate AS Дата_аренды, ReturnDate AS Дата_возврата, \
        IIF(Remark IS NULL, '', Remark) AS Комментарий FROM History h JOIN Film f ON h.FilmID = f.FilmID \
        WHERE ClientID = @userID", sqlConn);
    
    
    sqlCmd->Parameters->Add("@usersID", SqlDbType::Int);
    sqlCmd->Parameters["@usersID"]->Value = Convert::ToInt32(userID);

    sqlCmd->Parameters->Add("@nickname", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@nickname"]->Direction = ParameterDirection::Output;
    sqlCmd->Parameters->Add("@usersFio", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@usersFio"]->Direction = ParameterDirection::Output;
    sqlCmd->Parameters->Add("@usersGender", SqlDbType::VarChar, 1);
    sqlCmd->Parameters["@usersGender"]->Direction = ParameterDirection::Output;
    sqlCmd->Parameters->Add("@usersBirthD", SqlDbType::SmallDateTime);
    sqlCmd->Parameters["@usersBirthD"]->Direction = ParameterDirection::Output;
    sqlCmd->Parameters->Add("@usersPhoneNum", SqlDbType::VarChar, 20);
    sqlCmd->Parameters["@usersPhoneNum"]->Direction = ParameterDirection::Output;

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();

    usernameTxtBx->Text = sqlCmd->Parameters["@nickname"]->Value->ToString();
    usersFioTxtBx->Text = sqlCmd->Parameters["@usersFio"]->Value->ToString();
    genderCmbBx->Text = sqlCmd->Parameters["@usersGender"]->Value->ToString();
    BirthdayfDtTmPckr->Text = sqlCmd->Parameters["@usersBirthD"]->Value->ToString();
    PhnNumMskdTxtBx->Text = sqlCmd->Parameters["@usersPhoneNum"]->Value->ToString();
    loadDataToFavoriteFilmsDtGrd();
    
    SqlParameter^ ClientID = gcnew SqlParameter();
    ClientID->ParameterName = "@userID";
    ClientID->Value = this->userID;
    sqlDA->SelectCommand->Parameters->Add(ClientID);
    DataSet^ dataSet = gcnew DataSet();
    sqlConn->Open();
    sqlDA->Fill(dataSet, "History");
    sqlConn->Close();
    rentFilmsDtGrdView->DataSource = dataSet->Tables["History"];
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::deleteFromFavoritesBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (favoriteMoviesDtGrdView->SelectedRows->Count != 1) {
        MessageBox::Show("Пожалуйста, выделите запись для удаления", "Ошибка");
        return;
    }
    int indexLine = favoriteMoviesDtGrdView->SelectedRows[0]->Index;
    sqlConn = gcnew SqlConnection(connString);
    SqlCommand^ sqlCmd = gcnew SqlCommand();
    sqlCmd->Connection = sqlConn;

    sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
    sqlCmd->CommandText = "delFilmFromSostEzbrannogo";

    
    sqlCmd->Parameters->Add("@filmName", SqlDbType::VarChar, 30);
    sqlCmd->Parameters["@filmName"]->Value = favoriteMoviesDtGrdView->Rows[indexLine]->Cells[0]->Value->ToString();
    sqlCmd->Parameters->Add("@genre", SqlDbType::VarChar, 20);
    sqlCmd->Parameters["@genre"]->Value = favoriteMoviesDtGrdView->Rows[indexLine]->Cells[1]->Value->ToString();
    sqlCmd->Parameters->Add("@yearOfRelease", SqlDbType::Int);
    sqlCmd->Parameters["@yearOfRelease"]->Value = Convert::ToInt32(favoriteMoviesDtGrdView->Rows[indexLine]->Cells[2]->Value->ToString());
    sqlCmd->Parameters->Add("@userID", SqlDbType::Int);
    sqlCmd->Parameters["@userID"]->Value = Convert::ToInt32(userID);

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();

    loadDataToFavoriteFilmsDtGrd();
}

void VideoCassetDBMetelnikov::UsrsPersonalAccForm::loadDataToFavoriteFilmsDtGrd()
{
    SqlDataAdapter^ sqlDA = gcnew SqlDataAdapter("SELECT f.Name AS Фильм, g.Name AS Жанр, YearOfRelease AS Дата_премьеры, Price AS Цена, \
    Availability AS В_наличии FROM Favourites fav JOIN SostavEzbrannogo se ON fav.FavourID = se.FavourID \
    JOIN Film f ON se.FilmID = f.FilmID JOIN Genre g ON f.GenreID = g.GenreID \
    WHERE fav.ClientID = @userID", sqlConn);
    SqlParameter^ ClientID = gcnew SqlParameter();
    ClientID->ParameterName = "@userID";
    ClientID->Value = this->userID;
    sqlDA->SelectCommand->Parameters->Add(ClientID);
    DataSet^ dataSet = gcnew DataSet();
    sqlConn->Open();
    sqlDA->Fill(dataSet, "Favourites");
    sqlConn->Close();
    favoriteMoviesDtGrdView->DataSource = dataSet->Tables["Favourites"];
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::editUsrsDataBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (usersFioTxtBx->Text->Length == 0) {
        MessageBox::Show("Пожалуйста, заполните поле ФИО", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (!PhnNumMskdTxtBx->MaskFull) {
        MessageBox::Show("Пожалуйста, заполните поле номера телефона полностью", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sqlConn = gcnew SqlConnection(connString);

    SqlCommand^ sqlCmd = gcnew SqlCommand();
    sqlCmd->Connection = sqlConn;

    sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
    sqlCmd->CommandText = "updateUsrsPersonalData";

    sqlCmd->Parameters->Add("@login", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@login"]->Value = usernameTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@FIO", SqlDbType::VarChar, 50);
    sqlCmd->Parameters["@FIO"]->Value = usersFioTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@gender", SqlDbType::VarChar, 1);
    sqlCmd->Parameters["@gender"]->Value = genderCmbBx->Text->ToString();
    sqlCmd->Parameters->Add("@birthD", SqlDbType::SmallDateTime);
    sqlCmd->Parameters["@birthD"]->Value = BirthdayfDtTmPckr->Text->ToString();
    sqlCmd->Parameters->Add("@phoneNum", SqlDbType::VarChar, 20);
    sqlCmd->Parameters["@phoneNum"]->Value = PhnNumMskdTxtBx->Text;
    sqlCmd->Parameters->Add("@userID", SqlDbType::Int);
    sqlCmd->Parameters["@userID"]->Value = Convert::ToInt32(userID);
    sqlCmd->Parameters->Add("@res", SqlDbType::Int);
    sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();
    if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "0")
        MessageBox::Show("Такой логин уже занят", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    else
        MessageBox::Show("Данные изменены", "Успешно", MessageBoxButtons::OK);
}
// Prohibition on entering numbers and other symbols except words in the textBox, 'BS', 'DEL', '.' and 'space'
// On ASCII: BS - 8, DEL - 127, point - 46
System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::usersFioTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127 && e->KeyChar != 32)
        e->Handled = true;
}
// Prohibition on entering words in the textBox, 'BS', 'DEL' и '.'
// On ASCII: BS - 8, DEL - 127, point - 46
System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::PhnNumTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127 && e->KeyChar != 43)
        e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::editUsersPassBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    if(usersOldPasTxtBx->Text->Length == 0 && usersNewPassTxtBx->Text->Length == 0) {
        MessageBox::Show("Пожалуйста, заполните укажите старый и новый пароль", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (usersNewPassTxtBx->Text->Length < 4) {
        MessageBox::Show("Пароль должен состоять минимум из 4-х символов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    sqlConn = gcnew SqlConnection(connString);
    SqlCommand^ sqlCmd = gcnew SqlCommand();
    sqlCmd->Connection = sqlConn;

    sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
    sqlCmd->CommandText = "updateUsrsPassword";
    
    sqlCmd->Parameters->Add("@usersID", SqlDbType::Int);
    sqlCmd->Parameters["@usersID"]->Value = Convert::ToInt32(userID);
    sqlCmd->Parameters->Add("@oldPass", SqlDbType::VarChar, 30);
    sqlCmd->Parameters["@oldPass"]->Value = usersOldPasTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@newPass", SqlDbType::VarChar, 30);
    sqlCmd->Parameters["@newPass"]->Value = usersNewPassTxtBx->Text->ToString();
    sqlCmd->Parameters->Add("@res", SqlDbType::Int);
    sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();

    if (Convert::ToString(sqlCmd->Parameters["@res"]->Value) == "1")
        MessageBox::Show("Пароль изменен", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
    else
        MessageBox::Show("Ошибка старый пароль указан не верно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::выходИзАккаунтаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    SignInForm^ form = gcnew SignInForm();
    form->Show();
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::UsrsPersonalAccForm::UsrsPersonalAccForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
}



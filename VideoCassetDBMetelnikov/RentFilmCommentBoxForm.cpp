#include "RentFilmCommentBoxForm.h"

System::Void VideoCassetDBMetelnikov::RentFilmCommentBoxForm::backBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::RentFilmCommentBoxForm::continueBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
    DateTime dt = DateTime(dateTimePicker1->MinDate.Year, dateTimePicker1->MinDate.Month, dateTimePicker1->MinDate.Day);
    DateTime dt1 = DateTime(dateTimePicker1->Value.Year, dateTimePicker1->Value.Month, dateTimePicker1->Value.Day);
    int res = DateTime::Compare(dt, dt1);
    
    if (res == 0) {
        MessageBox::Show("К сожалению, фильм можно арендовать минимум на один день, пожалуйста, укажите дату больше сегодняшей",
            "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    
    sqlConn = gcnew SqlConnection(connString);
    SqlCommand^ sqlCmd = gcnew SqlCommand("INSERT INTO History(ClientID, FilmID, TransactDate, ReturnDate, Remark) VALUES \
        (@userID, @filmID, @transactDate, @returnDate, @remark)", sqlConn);

    sqlCmd->Parameters->Add("@userID", SqlDbType::Int);
    sqlCmd->Parameters["@userID"]->Value = userID;
    sqlCmd->Parameters->Add("@filmID", SqlDbType::Int);
    sqlCmd->Parameters["@filmID"]->Value = filmID;
    sqlCmd->Parameters->Add("@transactDate", SqlDbType::SmallDateTime);
    sqlCmd->Parameters["@transactDate"]->Value = dateTimePicker1->MinDate;
    sqlCmd->Parameters->Add("@returnDate", SqlDbType::SmallDateTime);
    sqlCmd->Parameters["@returnDate"]->Value = dateTimePicker1->Value;
    sqlCmd->Parameters->Add("@remark", SqlDbType::VarChar, 300);
    sqlCmd->Parameters["@remark"]->Value = commentToOrderTxtBx->Text;

    sqlConn->Open();
    sqlCmd->ExecuteNonQuery();
    sqlConn->Close();
    this->Hide();
}

System::Void VideoCassetDBMetelnikov::RentFilmCommentBoxForm::RentFilmCommentBoxForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    this->dateTimePicker1->MinDate = DateTime::Now;
}



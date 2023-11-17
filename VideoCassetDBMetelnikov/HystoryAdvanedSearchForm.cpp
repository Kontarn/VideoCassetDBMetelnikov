#include "HystoryAdvanedSearchForm.h"

System::Void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::findButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int size = 6; // Array of keys and array of values size
	int iKey = 0; // Array of keys index
	int iVal = 0; // Array of value index
	array<String^>^ key = gcnew array<String^>(size); // Stores of column name from the Film table
	array<String^>^ val = gcnew array<String^>(size); //  
	if (FIOClientComboBox->Text->Length != 0) {
		key[iKey++] = "Client.FIO";
		val[iVal++] = "'" + FIOClientComboBox->Text + "'";
	}
	if (FilmIdComboBox->Text->Length != 0) {
		key[iKey++] = "History.FilmID";
		val[iVal++] = FilmIdComboBox->Text;
	}
	if (FilmNameComboBox->Text->Length != 0) {
		key[iKey++] = "Film.Name";
		val[iVal++] = "'"+FilmNameComboBox->Text+"'";
	}
	if (TransactDateTimePicker->Text != "01.01.2020") {
		key[iKey++] = "TransactDate";
		val[iVal++] = "'" + TransactDateTimePicker->Text + "'";
	}
	if (ReturnDateTimePicker->Text != "01.01.2020") {
		key[iKey++] = "ReturnDate";
		val[iVal++] = "'" + ReturnDateTimePicker->Text + "'";
	}

	//int i = 0;
	SqlQuery = "SELECT TransactID AS Заказ, History.ClientID AS КодКлиента, FIO AS ФИО, History.FilmID AS КодФильма, Name AS Фильм,	\
	TransactDate AS ДатаЗаказа, ReturnDate AS ДатаВозврата, Remark AS Комментарий FROM History								\
	JOIN Client ON History.ClientID = Client.ClientID JOIN Film ON History.FilmID = Film.FilmID WHERE ";
	for (int i = 0; key[i] != nullptr && i < size; i++) {
		SqlQuery += " " + key[i] + " = " + val[i] + " and ";
	}
	SqlQuery += ";";
	int sizeStr = SqlQuery->Length;
	SqlQuery = SqlQuery->Remove(sizeStr - 5, 3);
	this->issueEvent1(sender, e);
	this->TransactDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
	this->ReturnDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
	this->Hide();

}

System::Void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::backButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
	this->TransactDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
	this->ReturnDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
}

void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::loadComboBox()
{
	String^ sqlQueryLocal = "SELECT FIO FROM History h JOIN Client c ON h.ClientID = c.ClientID";
	String^ sqlQueryLocal1 = "SELECT DISTINCT h.FilmID, f.Name FROM History h JOIN Film f ON h.FilmID = f.FilmID";
	SqlCommand^ cmdDataBase = gcnew SqlCommand(sqlQueryLocal, sqlConn);
	SqlCommand^ cmdDataBase1 = gcnew SqlCommand(sqlQueryLocal1, sqlConn);
	SqlDataReader^ myReader;
	try
	{
		myReader = cmdDataBase->ExecuteReader();
		FIOClientComboBox->Items->Clear();
		FilmIdComboBox->Items->Clear();
		FilmNameComboBox->Items->Clear();
		while (myReader->Read()) {
			FIOClientComboBox->Items->Add(myReader["FIO"]->ToString());
		}
		myReader->Close();
		myReader = cmdDataBase1->ExecuteReader();
		while (myReader->Read()) {
			FilmIdComboBox->Items->Add(myReader["FilmID"]->ToString());
			FilmNameComboBox->Items->Add(myReader["Name"]->ToString());
		}
		myReader->Close();
	}
	catch (const Exception^ ex)
	{                                                                                                               
		
		MessageBox::Show("Ошибка заполнения значениями", "Ошибка");
	}
}

void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::issueEvent1(System::Object ^ sender, System::EventArgs ^ e)
{
	this->myEvent1(this, e, SqlQuery);
}

System::Void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::HystoryAdvanedSearchForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	loadComboBox();
}
// prohibition - запрет
// Prohibition on entering numbers in the textBox Name, and in the textBox Dir Film, prohibition for Dirfilm you can see in the header, 
// in the corresponding blok
System::Void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::FIOClientComboBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}
// Prohibition on entering words in the textBox, 'BS', 'DEL' и '.'
// On ASCII: BS - 8, DEL - 127, point - 46
System::Void VideoCassetDBMetelnikov::HystoryAdvanedSearchForm::FilmIdComboBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127)
		e->Handled = true;
}

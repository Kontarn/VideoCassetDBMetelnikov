#include "AdvancedSearchForm.h"

System::Void VideoCassetDBMetelnikov::AdvancedSearchForm::backButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::AdvancedSearchForm::AdvancedSearchForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	SqlCommand^ cmdDataBase = gcnew SqlCommand("SELECT Name FROM Genre", sqlConn);
	SqlDataReader^ myReader;
	try
	{
		myReader = cmdDataBase->ExecuteReader();
		while (myReader->Read()) {
			GenreComboBox->Items->Add(myReader["Name"]->ToString());
		}
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка заполнения combobox", "Ошибка");
	}
}
// prohibition - запрет
// Prohibition on entering numbers in the textBox Name, and in the textBox Dir Film, prohibition for Dirfilm you can see in the header, 
// in the corresponding blok
System::Void VideoCassetDBMetelnikov::AdvancedSearchForm::NameTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}
// Prohibition on entering words in the textBox, 'BS', 'DEL' и '.'
// On ASCII: BS - 8, DEL - 127, point - 46
System::Void VideoCassetDBMetelnikov::AdvancedSearchForm::YearOfReleaseTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::AdvancedSearchForm::findButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int size = 7; // Array of keys and array of values size
	int iKey = 0; // Array of keys index
	int iVal = 0; // Array of value index
	array<String^>^ key = gcnew array<String^>(size); // Stores of column name from the Film table
	array<String^>^ val = gcnew array<String^>(size); //  
	if (NameTextBox->Text->Length != 0) {
		key[iKey++] = "Film.Name";
		val[iVal++] = "'" + NameTextBox->Text + "'";
	}
	if (GenreComboBox->Text->Length != 0) {
		key[iKey++] = "Genre.Name";
		val[iVal++] = "'" + GenreComboBox->Text + "'";
	}
	if (YearOfReleaseTextBox->Text->Length != 0) {
		key[iKey++] = "YearOfRelease";
		val[iVal++] = YearOfReleaseTextBox->Text;
	}
	if (DirFilmTextBox->Text->Length != 0) {
		key[iKey++] = "FilmDirector";
		val[iVal++] = "'" + DirFilmTextBox->Text + "'";
	}
	if (AvailBeginTextBox->Text->Length != 0 && AvailEndTextBox->Text->Length != 0) {
		key[iKey++] = "Availability";
		val[iVal++] = "BETWEEN " + AvailBeginTextBox->Text + " AND " + AvailEndTextBox->Text;
	}
	if (PriceBeginTextBox->Text->Length != 0 && PriceBeginTextBox->Text->Length != 0){
		key[iKey++] = "Price";
		val[iVal++] = "BETWEEN " + PriceBeginTextBox->Text + " AND " + PriceEndTextBox->Text;
	}
	int i = 0;
	String^ str = "SELECT FilmID AS Код, Film.Name AS Название, Genre.Name AS Жанр, YearOfRelease AS Премьера, \
			FilmDirector AS Режиссер, Availability AS Наличие,\
			Price AS Цена FROM Film JOIN Genre ON Film.GenreID = Genre.GenreID WHERE ";
	for (int i = 0; key[i] != nullptr && i < size; i++) {
		if (key[i] != "Availability" && key[i] != "Price")
			str += " " + key[i] + " = " + val[i] + ", ";
		else
			str += " " + key[i] + " " + val[i] + ", ";
	}
	str += ";";
	int sizeStr = str->Length;
	str = str->Remove(sizeStr - 3, 1);
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	sqlDA = gcnew SqlDataAdapter(str, sqlConn);
	sqlBuild = gcnew SqlCommandBuilder(sqlDA);
	dataSet = gcnew DataSet();
	dataSet->Tables["Film"]->Clear();
	sqlDA->Fill(dataSet, "Film");
	
	MessageBox::Show(str, "Результат");
	return;

}



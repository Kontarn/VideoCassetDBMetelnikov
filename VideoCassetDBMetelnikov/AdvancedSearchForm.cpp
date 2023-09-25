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

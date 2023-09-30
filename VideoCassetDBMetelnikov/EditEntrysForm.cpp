#include "EditEntrysForm.h"

System::Void VideoCassetDBMetelnikov::EditEntrysForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::EditEntrysForm::EditEntrysForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	SqlCommand^ cmdDB = gcnew SqlCommand("SELECT Name FROM Genre", sqlConn);
	
	try
	{
		SqlDataReader^ myReader = cmdDB->ExecuteReader();
		while (myReader->Read()) {
			genreComboBox->Items->Add(myReader["Name"]->ToString());
		}
	
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка заполнения comboBox\n" + e, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void VideoCassetDBMetelnikov::EditEntrysForm::editButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ titleFilm = nameFilmTextBox->Text;
	String^ genre = genreComboBox->Text;
	String^ yearOfRelease = yearOfReleaseTextBox->Text;
	String^ dirFilm = filmDirTextBox->Text;
	String^ availability = availTextBox->Text;
	String^ price = priceTextBox->Text;

	try
	{
		SqlConnection SqlConn(connString);
		SqlConn.Open();

		String^ sqlQuery = "UPDATE Film SET Name = @titleFilm, GenreID = ( \
			SELECT GenreID FROM Genre WHERE Name = @genre), YearOfRelease = @yearOfRelease, \
			FilmDirector = @dirFilm, Availability = @availability, price = @price WHERE FilmID = " +
			filmID;
		SqlCommand command(sqlQuery, % SqlConn);
		command.Parameters->AddWithValue("@titleFilm", titleFilm);
		command.Parameters->AddWithValue("@genre", genre);
		command.Parameters->AddWithValue("@yearOfRelease", yearOfRelease);
		command.Parameters->AddWithValue("@dirFilm", dirFilm);
		command.Parameters->AddWithValue("@availability", availability);
		command.Parameters->AddWithValue("@price", price);
		

		command.ExecuteNonQuery();
		MessageBox::Show("Запись успешно изменена, для того, что бы увидеть изменения на, \n \
			нажмите кнопку 'Отобразить'", "Успешно", MessageBoxButtons::OK);
		this->Hide();
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка изменения записи\n" + e, "Ошибка", MessageBoxButtons::OK);
	}
	
}

System::Void VideoCassetDBMetelnikov::EditEntrysForm::nameFilmTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::EditEntrysForm::yearOfReleaseTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

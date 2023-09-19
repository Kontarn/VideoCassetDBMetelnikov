#include "AddEntrysForm.h"

System::Void VideoCassetDBMetelnikov::AddEntrysForm::AddEntrysForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	LoadCombo();
}
System::Void VideoCassetDBMetelnikov::AddEntrysForm::LoadCombo() {
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

System::Void VideoCassetDBMetelnikov::AddEntrysForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::AddEntrysForm::AddButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ titleFilm = NameTextBox->Text;
	String^ genre = GenreComboBox->Text;
	String^ dirFilm = DirectorTextBox->Text;
	String^ yearOfRelease = YearOfReleaseTextBox->Text;
	String^ availability = AvailTextBox->Text;
	String^ price = PriceTextBox->Text;

	if (titleFilm->Length == 0 || genre->Length == 0 || 
		dirFilm->Length == 0 || price->Length == 0) {
		MessageBox::Show("Пожалуйста заполните все обязательные поля: Название фильма, жанр, режиссёр и цена", 
			"Внимание", MessageBoxButtons::OK);
		return;
	}
	try
	{
		SqlConnection SqlConn(connString);
		SqlConn.Open();

		String^ sqlQuery = "INSERT INTO Film(Name, GenreID, YearOfRelease, FilmDirector, Availability, Price) " +
			"SELECT @titleFilm, GenreID, @yearOfRelease, @dirFilm, @availability, @price FROM Genre WHERE Name = @genre";
		SqlCommand command(sqlQuery, % SqlConn);
		command.Parameters->AddWithValue("@titleFilm", titleFilm);
		command.Parameters->AddWithValue("@genre", genre);
		command.Parameters->AddWithValue("@dirFilm", dirFilm);
		command.Parameters->AddWithValue("@yearOfRelease", yearOfRelease);
		command.Parameters->AddWithValue("@availability", availability);
		command.Parameters->AddWithValue("@price", price);

		command.ExecuteNonQuery();
		this->Hide();
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка добавления новой записи", "Ошибка", MessageBoxButtons::OK);
	}
}
// Запрещает вводить в TextBox любые симовлы кроме цифр, 'BS', 'DEL' и '.'
// По ASCII: BS - 8, DEL - 127, точка - 46
System::Void VideoCassetDBMetelnikov::AddEntrysForm::KeyNotWordPress(System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::AddEntrysForm::YearOfReleaseTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	KeyNotWordPress(e);
}
// Запрещает ввод цифр в поле Режиссёра
System::Void VideoCassetDBMetelnikov::AddEntrysForm::DirectorTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}














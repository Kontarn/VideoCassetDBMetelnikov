#include "EditEntrysForm.h"

System::Void VideoCassetDBMetelnikov::EditEntrysForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	genreComboBox->Items->Clear();
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
		MessageBox::Show("������ ���������� comboBox\n" + e, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
	// �������� ������� ���
	time_t seconds = time(NULL);
	timeInfo = localtime(&seconds);

	

	int nowYear = timeInfo->tm_year + 1900;

	int yrOfRls = Convert::ToInt64(yearOfRelease);
	if (yrOfRls > nowYear || yrOfRls < 1900) {
		MessageBox::Show("���� �������� ����� ������� �� 1900 �� �������� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
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
		
		try
		{
			command.ExecuteNonQuery();
			/*MessageBox::Show("������ ������� ��������, ��� ����, ��� �� ������� ���������, \n \
			������� ������ '����������'", "�������", MessageBoxButtons::OK, MessageBoxIcon::Information);*/
			this->issueEvent1(sender, e);
			nameFilmTextBox->Clear();
			filmDirTextBox->Clear();
			yearOfReleaseTextBox->Clear();
			genreComboBox->Items->Clear();
			availTextBox->Clear();
			priceTextBox->Clear();
			this->Hide();
		}
		catch (const Exception^ ex)
		{
			MessageBox::Show("������ ��������� ������. \n ����� ���������� �������� ��� �������� � ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Hide();
		}
		
		
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ ��������� ������\n" + e, "������", MessageBoxButtons::OK);
	}
	
}



System::Void VideoCassetDBMetelnikov::EditEntrysForm::yearOfReleaseTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::EditEntrysForm::genreComboBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}

void VideoCassetDBMetelnikov::EditEntrysForm::issueEvent1(System::Object^ sender, System::EventArgs^ e)
{
	this->myEvent1(this, e);
}

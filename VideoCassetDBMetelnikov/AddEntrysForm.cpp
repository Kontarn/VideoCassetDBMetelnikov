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
		MessageBox::Show("������ ���������� combobox", "������");
	}
}

System::Void VideoCassetDBMetelnikov::AddEntrysForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//ClearTxtBxs();
	GenreComboBox->Items->Clear();
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
	//String^ res;
	
	if (titleFilm->Length == 0 || genre->Length == 0 || 
		dirFilm->Length == 0 || price->Length == 0) {
		MessageBox::Show("���������� ��������� ��� ������������ ����: �������� ������, ����, ������� � ����", 
			"��������", MessageBoxButtons::OK);
		return;
	}
	// �������� ������� ���
	time_t seconds = time(NULL);
	timeInfo = localtime(&seconds);
	
	int nowYear = timeInfo->tm_year + 1900;
	
	int yrOfRls = Convert::ToInt64(yearOfRelease);
	if (yrOfRls > nowYear || yrOfRls <= 1900) {
		MessageBox::Show("���� �������� ����� ������� �� 1900 �� �������� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	/*try
	{*/
		sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		
		//String^ sqlQuery1 = "EXEC sp_newFilm @titleFilm, @genre, @yearOfRelease, @dirFilm, @availability, @price, @resInsert = @res OUTPUT";
		String^ sqlQuery = "INSERT INTO Film(Name, GenreID, YearOfRelease, FilmDirector, Availability, Price) " +
			"SELECT @titleFilm, GenreID, @yearOfRelease, @dirFilm, @availability, @price FROM Genre WHERE Name = @genre";
		SqlCommand command(sqlQuery,  sqlConn);
		//command.CommandType = System::Data::CommandType::StoredProcedure;
		command.Parameters->AddWithValue("@titleFilm", titleFilm);
		command.Parameters->AddWithValue("@genre", genre);
		command.Parameters->AddWithValue("@dirFilm", dirFilm);
		command.Parameters->AddWithValue("@yearOfRelease", yearOfRelease);
		command.Parameters->AddWithValue("@availability", availability);
		command.Parameters->AddWithValue("@price", price);
		
		
		
		// command.Parameters->AddWithValue("@res", res);
		try
		{
			command.ExecuteNonQuery();
			/*MessageBox::Show("������ ������� ���������, ��� ����, ��� �� ������� ���������, \
			������� ������ '����������'", "�������", MessageBoxButtons::OK);*/
			this->issueEvent1(sender, e);
			ClearTxtBxs();
			this->Hide();
		}
		catch (const Exception^ ex)
		{
			MessageBox::Show("������ ���������� ������. \n ����� ���������� �������� ��� ���������� � ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Hide();
		}
		
		//if (res = "0") {
		//	MessageBox::Show("������ ������ ��� ���������", "������", MessageBoxButtons::OK);
		//	return;
		//}
		
	/*}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ ���������� ����� ������", "������", MessageBoxButtons::OK);
	}*/
}
// ��������� ������� � TextBox ����� ������� ����� ����, 'BS', 'DEL' � '.'
// �� ASCII: BS - 8, DEL - 127, ����� - 46
System::Void VideoCassetDBMetelnikov::AddEntrysForm::KeyNotWordPress(System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::AddEntrysForm::YearOfReleaseTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	KeyNotWordPress(e);
}
// ��������� ���� ���� � ���� ��������
System::Void VideoCassetDBMetelnikov::AddEntrysForm::DirectorTextBox_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}

void VideoCassetDBMetelnikov::AddEntrysForm::issueEvent1(System::Object^ sender, System::EventArgs^ e)
{
	this->myEvent1(this, e);
}

void VideoCassetDBMetelnikov::AddEntrysForm::ClearTxtBxs()
{
	NameTextBox->Clear();
	DirectorTextBox->Clear();
	YearOfReleaseTextBox->Clear();
	GenreComboBox->Items->Clear();
	AvailTextBox->Clear();
	PriceTextBox->Clear();
}
















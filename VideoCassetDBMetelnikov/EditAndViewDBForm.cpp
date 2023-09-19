#include "EditAndViewDBForm.h"


System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::EditAndViewDBForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
		sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		LoadData();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::LoadData()
{
	
	try
	{
		sqlDA = gcnew SqlDataAdapter("SELECT FilmID AS ���, Film.Name AS ��������, Genre.Name AS ����, \
			yearOfRelease AS ��������, FilmDirector AS ��������, Availability AS �������, Price AS ���� FROM Film	\
		INNER JOIN Genre ON Film.GenreID = Genre.GenreID", sqlConn);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset = gcnew DataSet();
		sqlDA->Fill(dataset, "Film");

		dataGridView1->DataSource = dataset->Tables[0];
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("������ ������ ������", "������");
	}
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::ReloadData()
{
	try
	{
		dataset->Tables["Film"]->Clear();
		sqlDA->Fill(dataset, "Film");
		dataGridView1->DataSource = dataset->Tables["Film"];
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ ����������", "������");
	}
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MenuForStaffForm^ form = gcnew MenuForStaffForm();
	this->Hide();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::UpdateButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	ReloadData();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::AddEntryButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddEntrysForm^ form = gcnew AddEntrysForm();
	form->Show();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::FindButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();
		if (textBox1->Text->Length == 0) {
			MessageBox::Show("����������, ������� �������� ������", "������");
			return;
		}
		sqlDA = gcnew SqlDataAdapter("SELECT FilmID AS ���, Film.Name AS ��������, Genre.Name AS ����, YearOfRelease AS ��������, \
			FilmDirector AS ��������, Availability AS �������, Price AS ���� FROM Film \
			INNER JOIN Genre ON Film.GenreID = Genre.GenreID \
			WHERE Film.Name = @findFilm", sqlConn);
		SqlParameter^ findFilm = gcnew SqlParameter();
		findFilm->ParameterName = "@findFilm";
		findFilm->Value = textBox1->Text;
		sqlDA->SelectCommand->Parameters->Add(findFilm);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset->Tables["Film"]->Clear();
		sqlDA->Fill(dataset, "Film");
		dataGridView1->DataSource = dataset->Tables[0];
		
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ ������ � ��", "������");
	}
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::ShowAllEntrysButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	LoadData();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::DeleteButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		sqlConn = gcnew SqlConnection(connString);
		if (dataGridView1->SelectedRows->Count != 1) {
			MessageBox::Show("����������, �������� ������ ��� ��������", "������");
			return;
		}
		int indexLine = dataGridView1->SelectedRows[0]->Index;
		String^ filmID = dataGridView1->Rows[indexLine]->Cells[0]->Value->ToString();
		sqlConn->Open();
		sqlDA = gcnew SqlDataAdapter("DELETE FROM Film WHERE FilmID = @filmID", sqlConn);
		SqlParameter^ delFilm = gcnew SqlParameter();
		delFilm->ParameterName = "@filmID";
		delFilm->Value = filmID;
		sqlDA->SelectCommand->Parameters->Add(delFilm);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataGridView1->DataSource = dataset->Tables[0];
		ReloadData();
		LoadData();
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ �������� ������", "������");
	}
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::EditEntryButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	try
	{
		sqlConn = gcnew SqlConnection(connString);
		String^ sqlQuery = "";
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ �������� ������", "������");
	}
}

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
		sqlDA = gcnew SqlDataAdapter("SELECT Film.Name AS Название, Genre.Name AS Жанр, \
			yearOfRelease AS Премьера, FilmDirector AS Режиссер, Availability AS Наличие, Price AS Цена FROM Film	\
		INNER JOIN Genre ON Film.GenreID = Genre.GenreID", sqlConn);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset = gcnew DataSet();
		sqlDA->Fill(dataset, "Film");

		dataGridView1->DataSource = dataset->Tables[0];
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка вывода данных", "Ошибка");
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
		MessageBox::Show("Ошибка обновления", "Ошибка");
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
			MessageBox::Show("Пожалуйста, введите название фильма", "Ошибка");
			return;
		}
		sqlDA = gcnew SqlDataAdapter("SELECT Film.Name AS Название, Genre.Name AS Жанр, YearOfRelease AS Премьера, \
			FilmDirector AS Режиссер, Availability AS Наличие, Price AS Цена FROM Film \
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
		MessageBox::Show("Ошибка поиска в БД", "Ошибка");
	}
}



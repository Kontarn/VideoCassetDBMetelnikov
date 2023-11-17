#include "EditAndViewDBForm.h"


System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::EditAndViewDBForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	this->advSearchF = gcnew AdvancedSearchForm();
	this->advSearchF->myEvent1 += gcnew AdvancedSearchForm::EventDelegate1
	(this, &VideoCassetDBMetelnikov::EditAndViewDBForm::mySubscriber);
	this->sortMethF = gcnew SortMethodForm();
	this->sortMethF->myEvent1 += gcnew SortMethodForm::EventDelegate1
	(this, &VideoCassetDBMetelnikov::EditAndViewDBForm::mySubscriber);
	LoadData();
}


System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::LoadData()
{
	try
	{
		sqlDA = gcnew SqlDataAdapter("SELECT FilmID AS Код, Film.Name AS Название, Genre.Name AS Жанр, \
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
//
//System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::LoadData(System::String^ str)
//{
//
//	try
//	{
//		sqlDA = gcnew SqlDataAdapter(str, sqlConn);
//		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
//		dataset = gcnew DataSet();
//		sqlDA->Fill(dataset, "Film");
//		dataGridView1->DataSource = dataset->Tables[0];
//	}
//	catch (Exception^ ex)
//	{
//		MessageBox::Show("Ошибка вывода данных", "Ошибка");
//	}
//}

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



//System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::UpdateButton_Click(System::Object ^ sender, System::EventArgs ^ e)
//{
//	sqlConn = gcnew SqlConnection(connString);
//	sqlConn->Open();
//	ReloadData();
//}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::AddEntryButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddEntrysForm^ form = gcnew AddEntrysForm();
	form->ShowDialog();
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
		sqlDA = gcnew SqlDataAdapter("SELECT FilmID AS Код, Film.Name AS Название, Genre.Name AS Жанр, YearOfRelease AS Премьера, \
			FilmDirector AS Режиссер, Availability AS Наличие, Price AS Цена FROM Film \
			INNER JOIN Genre ON Film.GenreID = Genre.GenreID \
			WHERE Film.Name LIKE CONCAT('%', @findFilm, '%')", sqlConn);
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
			MessageBox::Show("Пожалуйста, выделите запись для удаления", "Ошибка");
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
		MessageBox::Show("Ошибка удаления записи", "Ошибка");
	}
}

//System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::dataGridView1_CellEndEdit(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
//{
//	String^ titleFilm = dataGridView1[1, e->RowIndex]->Value->ToString();
//	String^ genre = dataGridView1[2, e->RowIndex]->Value->ToString();
//	String^ yearOfRelease = dataGridView1[3, e->RowIndex]->Value->ToString();
//	String^ dirFilm = dataGridView1[4, e->RowIndex]->Value->ToString();
//	String^ availability = dataGridView1[5, e->RowIndex]->Value->ToString();
//	String^ price = dataGridView1[6, e->RowIndex]->Value->ToString();
//	try
//	{
//		SqlConnection SqlConn(connString);
//		SqlConn.Open();
//
//		String^ sqlQuery = "UPDATE Film SET Name = @titleFilm, GenreID = ( \
//			SELECT GenreID FROM Genre WHERE Name = @genre), YearOfRelease = @yearOfRelease, \
//			FilmDirector = @dirFilm, Availability = @availability, price = @price WHERE FilmID = " + 
//			dataGridView1[0, e->RowIndex]->Value->ToString();
//		SqlCommand command(sqlQuery, % SqlConn);
//		command.Parameters->AddWithValue("@titleFilm", titleFilm);
//		command.Parameters->AddWithValue("@genre", genre);
//		command.Parameters->AddWithValue("@yearOfRelease", yearOfRelease);
//		command.Parameters->AddWithValue("@dirFilm", dirFilm);
//		command.Parameters->AddWithValue("@availability", availability);
//		command.Parameters->AddWithValue("@price", price);
//
//		command.ExecuteNonQuery();
//	}
//	catch (const Exception^ ex)
//	{
//		MessageBox::Show("Ошибка добавления записи\n" + e, "Ошибка", MessageBoxButtons::OK);
//	}
//}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::EditEntryButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Для редактирования выделите одно поле", "Ошибка", MessageBoxButtons::OK ,MessageBoxIcon::Error);
		return;
	}
	int indexLine = dataGridView1->SelectedRows[0]->Index;
	String^ filmID = dataGridView1->Rows[indexLine]->Cells[0]->Value->ToString();
	String^ titleFilm = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();
	String^ genre = dataGridView1->Rows[indexLine]->Cells[2]->Value->ToString();
	String^ yearOfRelease = dataGridView1->Rows[indexLine]->Cells[3]->Value->ToString();
	String^ filmDir = dataGridView1->Rows[indexLine]->Cells[4]->Value->ToString();
	String^ avail = dataGridView1->Rows[indexLine]->Cells[5]->Value->ToString();
	String^ price = dataGridView1->Rows[indexLine]->Cells[6]->Value->ToString();
	EditEntrysForm^ form = gcnew EditEntrysForm(filmID, titleFilm, genre, yearOfRelease, filmDir,
		avail, price);
	form->ShowDialog();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::AdvancedSearchButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->advSearchF->ShowDialog();

}

void VideoCassetDBMetelnikov::EditAndViewDBForm::mySubscriber(System::Object ^ sender, System::EventArgs ^ e, System::String^ str)
{
	try
	{
		sqlDA = gcnew SqlDataAdapter(str, sqlConn);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset->Tables["Film"]->Clear();
		sqlDA->Fill(dataset, "Film");
		
		dataGridView1->DataSource = dataset->Tables["Film"];
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка многокритериального поиска", "Ошибка");
	}
	
}


System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::SortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->sortMethF->ShowDialog();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::историяЗаказовToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	HystoryOfBuyForm^ form = gcnew HystoryOfBuyForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::EditAndViewDBForm::toStartMenuBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	form->Show();
	this->Hide();
}

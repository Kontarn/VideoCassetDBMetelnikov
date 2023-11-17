#include "RevievAndViewDBForm.h"

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::RevievAndViewDBForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	loadData();
	this->AdvSrchUsrF = gcnew AdvSearchUserForm();
	this->AdvSrchUsrF->myEvent1 += gcnew AdvSearchUserForm::EventDelegate1
	(this, &VideoCassetDBMetelnikov::RevievAndViewDBForm::mySubscriber);
}

void VideoCassetDBMetelnikov::RevievAndViewDBForm::loadData()
{
	//AdvSrchUsrF = gcnew AdvSearchUserForm();
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	try
	{
		sqlDA = gcnew SqlDataAdapter();
		sqlDA->SelectCommand = gcnew SqlCommand("SELECT f.Name AS �����, g.Name AS ����, price AS ���� FROM Film f JOIN Genre g on f.GenreID = g.GenreID", sqlConn);
		dataSet = gcnew DataSet();
		sqlDA->Fill(dataSet, "Film");
		dataGridView1->DataSource = dataSet->Tables[0];
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ �������� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}

void VideoCassetDBMetelnikov::RevievAndViewDBForm::mySubscriber(System::Object ^ sender, System::EventArgs ^ e, System::String ^ str)
{
	
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	try
	{

		sqlDA = gcnew SqlDataAdapter(str, sqlConn);
		sqlCmdBuild = gcnew SqlCommandBuilder(sqlDA);
		DataSet^ dataset = gcnew DataSet;
		sqlDA->Fill(dataset, "Film");
		
		dataGridView1->DataSource = dataset->Tables[0];
		sqlConn->Close();
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("������ ������������������� ������\n", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::FindToDBButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AdvSrchUsrF->ShowDialog();
}

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::MoreInfoAboutFilmButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("����������, ��� ����������� �������������� ���������� � ������, �������� ���� ������", "������", MessageBoxButtons::OK);
		return;
	}
	sqlConn = gcnew SqlConnection(connString);
	int indexLine = dataGridView1->SelectedRows[0]->Index;
	if (dataGridView1->Rows[indexLine]->Cells[0]->Value != nullptr) {
		String^ filmName = dataGridView1->Rows[indexLine]->Cells[0]->Value->ToString();
		//String^ genreID = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();

		SqlCommand^ my_command = gcnew SqlCommand();
		my_command->Connection = sqlConn;
		my_command->CommandType = System::Data::CommandType::Text;
		my_command->CommandText = "SELECT FilmID FROM Film f JOIN Genre g ON f.GenreID = g.GenreID WHERE f.Name = @film AND g.Name = @genre";
		my_command->Parameters->Add("@film", SqlDbType::VarChar, 40);
		my_command->Parameters["@film"]->Value = filmName;
		my_command->Parameters->Add("@genre", SqlDbType::VarChar, 20);
		my_command->Parameters["@genre"]->Value = dataGridView1->Rows[indexLine]->Cells[1]->Value;
		sqlConn->Open();
		String^ filmID = my_command->ExecuteScalar()->ToString();
		sqlConn->Close();


		AdditionalInfoFilmForm^ addtnlInfoFilmF = gcnew AdditionalInfoFilmForm(filmID, userID);
		addtnlInfoFilmF->ShowDialog();
	}
	else {
		MessageBox::Show("����������, �������� ����������� ������", "������",  MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void VideoCassetDBMetelnikov::RevievAndViewDBForm::ShwAllEntrsBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	
	loadData();
}


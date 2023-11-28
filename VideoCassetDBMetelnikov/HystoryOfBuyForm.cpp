#include "HystoryOfBuyForm.h"



System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}



System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::HystoryOfBuyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	sqlConn->Open();
	this->hystSortMethF = gcnew HystorySortMethodForm();
	this->hystSortMethF->myEvent1 += gcnew HystorySortMethodForm::EventDelegate1
	(this, &VideoCassetDBMetelnikov::HystoryOfBuyForm::mySubscriber);
	this->hystAdvSearchF = gcnew HystoryAdvanedSearchForm();
	this->hystAdvSearchF->myEvent1 += gcnew HystoryAdvanedSearchForm::EventDelegate1
	(this, &VideoCassetDBMetelnikov::HystoryOfBuyForm::mySubscriber);
	LoadData();


}

void VideoCassetDBMetelnikov::HystoryOfBuyForm::LoadData()
{
	String^ sqlQuery="SELECT TransactID AS Заказ, History.ClientID AS КодКлиента, FIO AS ФИО, History.FilmID AS КодФильма, Name AS Фильм,	\
	TransactDate AS ДатаЗаказа, ReturnDate AS ДатаВозврата, Remark AS Комментарий FROM History								\
	JOIN Client ON History.ClientID = Client.ClientID JOIN Film ON History.FilmID = Film.FilmID";
	try
	{

		sqlDA = gcnew SqlDataAdapter(sqlQuery, sqlConn);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset = gcnew DataSet();
		sqlDA->Fill(dataset, "History");

		dataGridView1->DataSource = dataset->Tables[0];
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка вывода Истории заказов", "Ошибка");
	}
}

void VideoCassetDBMetelnikov::HystoryOfBuyForm::mySubscriber(System::Object ^ sender, System::EventArgs ^ e, System::String ^ str)
{
	try
	{
		sqlDA = gcnew SqlDataAdapter(str, sqlConn);
		sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		dataset->Tables["History"]->Clear();
		sqlDA->Fill(dataset, "History");

		dataGridView1->DataSource = dataset->Tables["History"];
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка многокритериальной сортировки", "Ошибка");
	}
}



//System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::SortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
//{
//	this->hystSortMethF->ShowDialog();
//}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::AdvancedSearchButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->hystAdvSearchF->ShowDialog();

}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::ShowAllEntrysButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	LoadData();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::toStartMenuBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::редактированиеБДToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	EditAndViewDBForm^ form = gcnew EditAndViewDBForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::выходИзАккаунтаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	LogInForStaffForm^ form = gcnew LogInForStaffForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::изменитьКодДоступаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditAccessCodeForm^ form = gcnew EditAccessCodeForm();
	form->ShowDialog();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::HystoryOfBuyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::редактированиеБДToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	EditAndViewDBForm^ form = gcnew EditAndViewDBForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::изменитьКодДоступаToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditAccessCodeForm^ form = gcnew EditAccessCodeForm();
	form->ShowDialog();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::выходИзАккаунтаToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	LogInForStaffForm^ form = gcnew LogInForStaffForm();
	form->Show();
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::moreAboutUserBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	int indexLine = dataGridView1->CurrentCell->RowIndex;
	if (dataGridView1->Rows[indexLine]->Cells[0]->Value != nullptr) {
		//String^ genreID = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();

		String^ userID = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();
		MoreInfoAboutUserForm^ form = gcnew MoreInfoAboutUserForm(userID);
		form->ShowDialog();
	}
	else {
		MessageBox::Show("Пожалуйста, веберите заполненную строку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

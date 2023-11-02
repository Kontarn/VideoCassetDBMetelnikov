#include "HystoryOfBuyForm.h"



System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::ExitButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Application::Exit();
}

System::Void VideoCassetDBMetelnikov::HystoryOfBuyForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MenuForStaffForm^ form = gcnew MenuForStaffForm();
	form->Show();
	this->Hide();
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
	String^ sqlQuery="SELECT TransactID AS �����, History.ClientID AS ����������, FIO AS ���, History.FilmID AS ���������, Name AS �����,	\
	TransactDate AS ����������, ReturnDate AS ������������, Remark AS ����������� FROM History								\
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
		MessageBox::Show("������ ������ ������� �������", "������");
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
		MessageBox::Show("������ ������������������ ����������", "������");
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

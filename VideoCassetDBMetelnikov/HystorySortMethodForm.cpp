#include "HystorySortMethodForm.h"



System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::ClearSortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox1->Clear();
	for (int j = 0; j < size; j++) {
		sortMass[j] = nullptr;
		indexTextB[j] = nullptr;

	}
	i = 0;
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::AddClientIDButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(i, ClientIDDomainUpDown, "History.ClientID", "КодКлиент");
}

void VideoCassetDBMetelnikov::HystorySortMethodForm::AddToMassSort(int j, System::Windows::Forms::DomainUpDown ^ domainText, 
	System::String ^ nameCol, System::String ^ psevdCol)
{
	if (indexTextB[j] == nullptr) {
		if (domainText->Text == "По возрастанию") {
			sortMass[i] = nameCol + (String^)", ";
			i++;
			textBox1->Text += psevdCol + (String^)" возр.,";
			indexTextB[j] = "*";
		}
		else if (domainText->Text == "По убыванию") {
			sortMass[i] = nameCol + (String^)" DESC, ";
			i++;
			textBox1->Text += psevdCol + (String^)" убыв.,";
			indexTextB[j] = "*";
		}
	}
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::AddClientFIOButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(i, ClientFIODomainUpDown, "FIO", "ФИО");
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::AddTransactDateButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(i, TransactDateDomainUpDown, "TransactDate", "ДатаТранзакции");
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::AddReturnDateButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(i, ReturnDateDomainUpDown, "ReturnDate", "ДатаВозврата");
}

void VideoCassetDBMetelnikov::HystorySortMethodForm::issueEvent1(System::Object ^ sender, System::EventArgs ^ e)
{
	this->myEvent1(this, e, sqlStr);
}

System::Void VideoCassetDBMetelnikov::HystorySortMethodForm::SortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlStr = "SELECT TransactID AS Заказ, History.ClientID AS КодКлиента, FIO AS ФИО, History.FilmID AS КодФильма, Name AS Фильм,	\
			TransactDate AS ДатаЗаказа, ReturnDate AS ДатаВозврата, Remark AS Комментарий FROM History								\
			JOIN Client ON History.ClientID = Client.ClientID JOIN Film ON History.FilmID = Film.FilmID								\
			ORDER BY ";
	for (int i = 0; i < size; i++) {
		if (sortMass[i] != nullptr) {
			sqlStr += sortMass[i];
		}
		else
			break;
	}
	int sizeStr = sqlStr->Length;
	sqlStr = sqlStr->Remove(sizeStr - 2, 1);
	this->issueEvent1(sender, e);
	this->Hide();
}

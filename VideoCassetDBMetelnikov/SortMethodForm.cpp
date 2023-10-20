#include "SortMethodForm.h"

System::Void VideoCassetDBMetelnikov::SortMethodForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Hide();
}

void VideoCassetDBMetelnikov::SortMethodForm::AddToMassSort(int j, System::Windows::Forms::DomainUpDown^ domainText, 
	System::String^ nameCol, System::String^ psevdCol)
{
	if (indexTextB[j] == nullptr) {
		if (domainText->Text == "�� �����������") {
			sortMass[i] = nameCol +(String^)", ";
			i++;
			textBox1->Text += psevdCol+(String^)" ����.,";
			indexTextB[j] = "*";
		}
		else if (domainText->Text == "�� ��������") {
			sortMass[i] = nameCol+(String^)" DESC, ";
			i++;
			textBox1->Text += psevdCol+(String^)" ����.,";
			indexTextB[j] = "*";
		}
	}
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddNameButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "Film.Name";
	buffer1 = "�����";
	AddToMassSort(0, NameDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddGenreButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "Genre.Name";
	buffer1 = "����";
	AddToMassSort(1, GenreDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddYearOfRelButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "YearOfRelease";
	buffer1 = "��������";
	AddToMassSort(2, YearOfRelDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddDirFilmButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "FilmDirector";
	buffer1 = "��������";
	AddToMassSort(3, DirFilmDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddAvailButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "Availability";
	buffer1 = "�������";
	AddToMassSort(4, AvailDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddPriceButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	buffer = "Price";
	buffer1 = "����";
	AddToMassSort(5, PriceDomainUpDown, buffer, buffer1);
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::ClearSortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	textBox1->Clear();
	for (int i = 0; i < size; i++) {
		sortMass[i] = nullptr;
		indexTextB[i] = nullptr;

	}
	i = 0;
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::SortButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlStr = "SELECT FilmID AS ���, Film.Name AS ��������, Genre.Name AS ����, YearOfRelease AS ��������, \
			FilmDirector AS ��������, Availability AS �������,\
			Price AS ���� FROM Film JOIN Genre ON Film.GenreID = Genre.GenreID \
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

void VideoCassetDBMetelnikov::SortMethodForm::issueEvent1(System::Object ^ sender, System::EventArgs ^ e)
{
	this->myEvent1(this, e, sqlStr);
}



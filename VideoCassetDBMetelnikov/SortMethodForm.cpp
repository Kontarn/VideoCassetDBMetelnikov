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
	AddToMassSort(0, NameDomainUpDown, "Film.Name", "�����");
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddGenreButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(1, GenreDomainUpDown, "Genre.Name", "����");
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddYearOfRelButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(2, YearOfRelDomainUpDown, "YearOfRelease", "��������");
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddDirFilmButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(3, DirFilmDomainUpDown, "FilmDirector", "��������");
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddAvailButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(4, AvailDomainUpDown, "Availability", "�������");
}

System::Void VideoCassetDBMetelnikov::SortMethodForm::AddPriceButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddToMassSort(5, PriceDomainUpDown, "Price", "����");
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



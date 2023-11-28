#include "AdvSearchUserForm.h"

System::Void VideoCassetDBMetelnikov::AdvSearchUserForm::AdvSearchUserForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	
	String^ genreQuery = "SELECT Name FROM Genre ORDER BY Name";
	SqlCommand^ cmdDataBase = gcnew SqlCommand(genreQuery, sqlConn);
	SqlDataReader^ myReader;

	//
	try
	{
		sqlConn->Open();
		myReader = cmdDataBase->ExecuteReader();
		filmGnrCmbBx->Items->Clear();
		while (myReader->Read()) {
			filmGnrCmbBx->Items->Add(myReader["Name"]->ToString());
		}
		sqlConn->Close();		
	}
	catch (const Exception^ ex)
	{
		MessageBox::Show("Ошибка заполнения combobox", "Ошибка");
	}
}

void VideoCassetDBMetelnikov::AdvSearchUserForm::issueEvent1(System::Object ^ sender, System::EventArgs ^ e)
{
	this->myEvent1(this, e, query);
}

System::Void VideoCassetDBMetelnikov::AdvSearchUserForm::findBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	int size = 7; // Array of keys and array of values size
	int iKey = 0; // Array of keys index
	int iVal = 0; // Array of value index
	array<String^>^ key = gcnew array<String^>(size); // Stores of column name from the Film table
	array<String^>^ val = gcnew array<String^>(size); //  
	if ((frmPriceTxtBx->Text->Length != 0 && frmPriceTxtBx->Text->Length == 0) ||
		(frmPriceTxtBx->Text->Length == 0 && frmPriceTxtBx->Text->Length != 0)) {
		MessageBox::Show("Пожалуйста, заполните оба поля для цен", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (nameTxtBx->Text->Length != 0) {
		key[iKey++] = "Film.Name";
		val[iVal++] = "'%" + nameTxtBx->Text + "%'";
	}
	if (filmGnrCmbBx->Text->Length != 0) {
		key[iKey++] = "Genre.Name";
		val[iVal++] = "'%" + filmGnrCmbBx->Text + "%'";
	}
	if (frmPriceTxtBx->Text->Length != 0 && toPriceTxtBx->Text->Length != 0) {
		key[iKey++] = "Price";
		val[iVal++] = "BETWEEN " + frmPriceTxtBx->Text + " AND " + toPriceTxtBx->Text;
	}
	//int i = 0;
	query = "SELECT Film.Name AS Название, Genre.Name AS Жанр, \
			Price AS Цена FROM Film JOIN Genre ON Film.GenreID = Genre.GenreID WHERE ";
	for (int i = 0; key[i] != nullptr && i < size; i++) {
		if (key[i] != "Price")
			query += " " + key[i] + " LIKE " + val[i] + " and ";
		else
			query += " " + key[i] + " " + val[i] + " and ";
	}
	query += ";";
	int sizeStr = query->Length;
	query = query->Remove(sizeStr - 5, 3);
	this->issueEvent1(sender, e);
	this->Hide();
}

System::Void VideoCassetDBMetelnikov::AdvSearchUserForm::BackButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

System::Void VideoCassetDBMetelnikov::AdvSearchUserForm::frmPriceTxtBx_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 46 && e->KeyChar != 127)
		e->Handled = true;
}

System::Void VideoCassetDBMetelnikov::AdvSearchUserForm::nameTxtBx_KeyPress(System::Object ^ sender, System::Windows::Forms::KeyPressEventArgs ^ e)
{
	if (Char::IsDigit(e->KeyChar))
		e->Handled = true;
}

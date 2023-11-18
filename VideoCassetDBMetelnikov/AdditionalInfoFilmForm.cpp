#include "AdditionalInfoFilmForm.h"

System::Void VideoCassetDBMetelnikov::AdditionalInfoFilmForm::BackBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

System::Void VideoCassetDBMetelnikov::AdditionalInfoFilmForm::AdditionalInfoFilmForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	//reviewsLstBx->Items->Add(filmID);
	sqlConn = gcnew SqlConnection(connString);
	//SqlCommand^ myCommand = gcnew SqlCommand("SELECT * FROM getFilm(@filmID)", sqlConn);
	//myCommand->Parameters->Add("@filmID", SqlDbType::Int);
	//myCommand->Parameters["@filmID"]->Value = Convert::ToInt32(filmID);
	//DataTable^ dataTable = gcnew DataTable();
	//sqlConn->Open();
	//dataTable->Load(myCommand->ExecuteReader());
	//filmNameLbl->Text = dataTable;



	SqlDataAdapter^ sqlDA = gcnew SqlDataAdapter("SELECT * FROM getFilm(@filmID)", sqlConn);
	SqlCommandBuilder^ sqlCmdBuild = gcnew SqlCommandBuilder(sqlDA);
	dataSet = gcnew DataSet();
	//DataTable^ dataTable = gcnew DataTable();
	SqlParameter^ SqlParFilmID = gcnew SqlParameter();
	SqlParFilmID->ParameterName = "@filmID";
	SqlParFilmID->Value = filmID;
	sqlConn->Open();
	sqlDA->SelectCommand->Parameters->Add(SqlParFilmID);
	sqlDA->Fill(dataSet, "Film");
	filmNameLbl->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[0]->ToString();
	gnrNameLbl->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[1]->ToString();
	yearOfRlslabel->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[2]->ToString();
	dirFlmLabel->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[3]->ToString();
	availLabel->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[4]->ToString();
	priceLabel->Text = dataSet->Tables["Film"]->Rows[0]->ItemArray[5]->ToString();
	sqlConn->Close();
	
	loadReviewData();
}

System::Void VideoCassetDBMetelnikov::AdditionalInfoFilmForm::leaveReviewBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ review = newReviewTxtBx->Text;
	if (review->Length == 0) {
		MessageBox::Show("Пожалуйста, внесите ваш отзыв в соответствующее поле", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	sqlConn = gcnew SqlConnection(connString);
	
	SqlCommand^ SqlCmd = gcnew SqlCommand("INSERT INTO Review VALUES \
		(@userID, @filmID, @reviewTxt, GETDATE())", sqlConn);
	SqlCmd->Parameters->Add("@userID", SqlDbType::Int);
	SqlCmd->Parameters->Add("@filmID", SqlDbType::Int);
	SqlCmd->Parameters->Add("@reviewTxt", SqlDbType::VarChar, 300);

	SqlCmd->Parameters["@userID"]->Value = Convert::ToInt32(userID);
	SqlCmd->Parameters["@filmID"]->Value = Convert::ToInt32(filmID);
	SqlCmd->Parameters["@reviewTxt"]->Value = newReviewTxtBx->Text;
	sqlConn->Open();
	SqlCmd->ExecuteNonQuery();
	sqlConn->Close();
	
	loadReviewData();

}

void VideoCassetDBMetelnikov::AdditionalInfoFilmForm::loadReviewData()
{
	SqlCommand^ myCommand = gcnew SqlCommand("SELECT FIO , DateOfPublic, ReviewText FROM Review r\
		JOIN Client c ON r.ClientID = c.ClientID WHERE FilmID = @FilmID", sqlConn);
	myCommand->Parameters->Add("@filmID", SqlDbType::Int);
	myCommand->Parameters["@filmID"]->Value = Convert::ToInt32(filmID);
	SqlDataReader^ myReader;
	sqlConn->Open();
	myReader = myCommand->ExecuteReader();
	textBox2->Clear();
	while (myReader->Read())
	{
		textBox2->AppendText(myReader["FIO"]->ToString() + "\t" + myReader["DateOfPublic"]->ToString() + 
			"\r\n" + myReader["ReviewText"]->ToString() + "\r\n\r\n");
	}
	sqlConn->Close();
}

System::Void VideoCassetDBMetelnikov::AdditionalInfoFilmForm::toFavorBtn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	sqlConn = gcnew SqlConnection(connString);
	SqlCommand^ sqlCmd = gcnew SqlCommand();
	sqlCmd->Connection = sqlConn;
	
	sqlCmd->CommandType = System::Data::CommandType::StoredProcedure;
	sqlCmd->CommandText = "insertFilmToFavor";

	sqlCmd->Parameters->Add("@clientID", SqlDbType::Int);
	sqlCmd->Parameters->Add("@filmID", SqlDbType::Int);

	sqlCmd->Parameters->Add("@res", SqlDbType::Int);
	sqlCmd->Parameters["@res"]->Direction = ParameterDirection::Output;

	sqlCmd->Parameters["@clientID"]->Value = Convert::ToInt32(userID);
	sqlCmd->Parameters["@filmID"]->Value = Convert::ToInt32(filmID);

	sqlConn->Open();
	sqlCmd->ExecuteNonQuery();
	sqlConn->Close();
	if (sqlCmd->Parameters["@res"]->Value->ToString() == "1")
		MessageBox::Show("Фильм добавлен в избарнное", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Information);
	else
		MessageBox::Show("Фильм уже присутствует в списке", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

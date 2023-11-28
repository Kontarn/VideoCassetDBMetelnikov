#include "MoreInfoAboutUserForm.h"

System::Void VideoCassetDBMetelnikov::MoreInfoAboutUserForm::MoreInfoAboutUserForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    sqlConn = gcnew SqlConnection(connString);
	String^ sqlQuery = "SELECT usersLogin, FIO, Gender, Birthday, PhoneNum FROM Client c JOIN Passwords p ON c.ClientID = p.ClientID \
	WHERE c.ClientID = @userID";
	SqlParameter^ SqlParUserID = gcnew SqlParameter();
	SqlParUserID->ParameterName = "@userID";
	SqlParUserID->Value = userID;
	//try
	//{

		SqlDataAdapter^ sqlDA = gcnew SqlDataAdapter(sqlQuery, sqlConn);
		SqlCommandBuilder^ sqlBuild = gcnew SqlCommandBuilder(sqlDA);
		DataSet^ dataset = gcnew DataSet();
		sqlConn->Open();
		sqlDA->SelectCommand->Parameters->Add(SqlParUserID);
		sqlDA->Fill(dataset, "Client");
		
		
		usrsLoginTxtBx->Text = dataset->Tables["Client"]->Rows[0]->ItemArray[0]->ToString();
		usrsFioTxtBx->Text = dataset->Tables["Client"]->Rows[0]->ItemArray[1]->ToString();
		usrsGenderTxtBx->Text = dataset->Tables["Client"]->Rows[0]->ItemArray[2]->ToString();
		usrsBirthDTxtBx->Text = dataset->Tables["Client"]->Rows[0]->ItemArray[3]->ToString();
		usrsPhonNumTxtBx->Text = dataset->Tables["Client"]->Rows[0]->ItemArray[4]->ToString();
		
		sqlConn->Close();
	/*}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка вывода Истории заказов", "Ошибка");
	}*/
}

System::Void VideoCassetDBMetelnikov::MoreInfoAboutUserForm::closeBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}

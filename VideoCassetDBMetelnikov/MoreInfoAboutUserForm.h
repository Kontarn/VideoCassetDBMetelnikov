#pragma once

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MoreInfoAboutUserForm
	/// </summary>
	public ref class MoreInfoAboutUserForm : public System::Windows::Forms::Form
	{
	private: String^ userID;
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: System::Windows::Forms::TextBox^ usrsLoginTxtBx;
	private: System::Windows::Forms::TextBox^ usrsFioTxtBx;
	private: System::Windows::Forms::TextBox^ usrsGenderTxtBx;
	private: System::Windows::Forms::TextBox^ usrsBirthDTxtBx;
	private: System::Windows::Forms::TextBox^ usrsPhonNumTxtBx;

	private: SqlConnection^ sqlConn;
	public:
		MoreInfoAboutUserForm(String^ userID) : userID(userID)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MoreInfoAboutUserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;


	protected:

	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::Label^ label9;



	private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Button^ closeBtn;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->usrsLoginTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usrsFioTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usrsGenderTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usrsBirthDTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usrsPhonNumTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(24, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Логин:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(24, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"ФИО:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(24, 179);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(146, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Дата рождения:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(24, 144);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Пол:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label9->Location = System::Drawing::Point(24, 217);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(160, 20);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Номер телефона:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label11->Location = System::Drawing::Point(152, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(203, 29);
			this->label11->TabIndex = 10;
			this->label11->Text = L"О пользователе";
			// 
			// closeBtn
			// 
			this->closeBtn->Location = System::Drawing::Point(404, 260);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(88, 31);
			this->closeBtn->TabIndex = 12;
			this->closeBtn->Text = L"Закрыть";
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &MoreInfoAboutUserForm::closeBtn_Click);
			// 
			// usrsLoginTxtBx
			// 
			this->usrsLoginTxtBx->Location = System::Drawing::Point(200, 68);
			this->usrsLoginTxtBx->Name = L"usrsLoginTxtBx";
			this->usrsLoginTxtBx->ReadOnly = true;
			this->usrsLoginTxtBx->Size = System::Drawing::Size(292, 22);
			this->usrsLoginTxtBx->TabIndex = 13;
			// 
			// usrsFioTxtBx
			// 
			this->usrsFioTxtBx->Location = System::Drawing::Point(200, 108);
			this->usrsFioTxtBx->Name = L"usrsFioTxtBx";
			this->usrsFioTxtBx->ReadOnly = true;
			this->usrsFioTxtBx->Size = System::Drawing::Size(292, 22);
			this->usrsFioTxtBx->TabIndex = 14;
			// 
			// usrsGenderTxtBx
			// 
			this->usrsGenderTxtBx->Location = System::Drawing::Point(200, 142);
			this->usrsGenderTxtBx->Name = L"usrsGenderTxtBx";
			this->usrsGenderTxtBx->ReadOnly = true;
			this->usrsGenderTxtBx->Size = System::Drawing::Size(292, 22);
			this->usrsGenderTxtBx->TabIndex = 15;
			// 
			// usrsBirthDTxtBx
			// 
			this->usrsBirthDTxtBx->Location = System::Drawing::Point(200, 179);
			this->usrsBirthDTxtBx->Name = L"usrsBirthDTxtBx";
			this->usrsBirthDTxtBx->ReadOnly = true;
			this->usrsBirthDTxtBx->Size = System::Drawing::Size(292, 22);
			this->usrsBirthDTxtBx->TabIndex = 16;
			// 
			// usrsPhonNumTxtBx
			// 
			this->usrsPhonNumTxtBx->Location = System::Drawing::Point(200, 217);
			this->usrsPhonNumTxtBx->Name = L"usrsPhonNumTxtBx";
			this->usrsPhonNumTxtBx->ReadOnly = true;
			this->usrsPhonNumTxtBx->Size = System::Drawing::Size(292, 22);
			this->usrsPhonNumTxtBx->TabIndex = 17;
			// 
			// MoreInfoAboutUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 303);
			this->Controls->Add(this->usrsPhonNumTxtBx);
			this->Controls->Add(this->usrsBirthDTxtBx);
			this->Controls->Add(this->usrsGenderTxtBx);
			this->Controls->Add(this->usrsFioTxtBx);
			this->Controls->Add(this->usrsLoginTxtBx);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(522, 350);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(522, 350);
			this->Name = L"MoreInfoAboutUserForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &MoreInfoAboutUserForm::MoreInfoAboutUserForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MoreInfoAboutUserForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e);

};
}

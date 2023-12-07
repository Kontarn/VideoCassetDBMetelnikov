#pragma once
#include "SignInForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for usersRegisterForm
	/// </summary>
	public ref class usersRegisterForm : public System::Windows::Forms::Form
	{
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ usersPassTxtBx;

	private: System::Windows::Forms::MaskedTextBox^ usersPhoneMskdTxtBx;



	private: SqlConnection^ sqlConn;
	public:
		usersRegisterForm(void)
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
		~usersRegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ usersFioTxtBx;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ usernameTxtBx;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ usersRegisterBtn;
	private: System::Windows::Forms::Button^ BackBtn;
	private: System::Windows::Forms::Button^ ExitBtn;
	private: System::Windows::Forms::ComboBox^ usersGenderCmbBx;

	private: System::Windows::Forms::DateTimePicker^ usersBirthDayDtTmPckr;






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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->usersFioTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->usernameTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->usersRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->ExitBtn = (gcnew System::Windows::Forms::Button());
			this->usersGenderCmbBx = (gcnew System::Windows::Forms::ComboBox());
			this->usersBirthDayDtTmPckr = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->usersPassTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usersPhoneMskdTxtBx = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label1->Location = System::Drawing::Point(104, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(203, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Регистрация";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ФИО:";
			// 
			// usersFioTxtBx
			// 
			this->usersFioTxtBx->Location = System::Drawing::Point(154, 70);
			this->usersFioTxtBx->Name = L"usersFioTxtBx";
			this->usersFioTxtBx->Size = System::Drawing::Size(216, 22);
			this->usersFioTxtBx->TabIndex = 2;
			this->usersFioTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &usersRegisterForm::usersFioTxtBx_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Пол:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Дата рождения:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Номер телефона:";
			// 
			// usernameTxtBx
			// 
			this->usernameTxtBx->Location = System::Drawing::Point(154, 108);
			this->usernameTxtBx->Name = L"usernameTxtBx";
			this->usernameTxtBx->Size = System::Drawing::Size(216, 22);
			this->usernameTxtBx->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Логин:";
			// 
			// usersRegisterBtn
			// 
			this->usersRegisterBtn->Location = System::Drawing::Point(208, 319);
			this->usersRegisterBtn->Name = L"usersRegisterBtn";
			this->usersRegisterBtn->Size = System::Drawing::Size(161, 38);
			this->usersRegisterBtn->TabIndex = 11;
			this->usersRegisterBtn->Text = L"Зарегистрироваться";
			this->usersRegisterBtn->UseVisualStyleBackColor = true;
			this->usersRegisterBtn->Click += gcnew System::EventHandler(this, &usersRegisterForm::usersRegisterBtn_Click);
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(111, 318);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(73, 38);
			this->BackBtn->TabIndex = 12;
			this->BackBtn->Text = L"Назад";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &usersRegisterForm::BackBtn_Click);
			// 
			// ExitBtn
			// 
			this->ExitBtn->Location = System::Drawing::Point(21, 319);
			this->ExitBtn->Name = L"ExitBtn";
			this->ExitBtn->Size = System::Drawing::Size(84, 37);
			this->ExitBtn->TabIndex = 13;
			this->ExitBtn->Text = L"Выход";
			this->ExitBtn->UseVisualStyleBackColor = true;
			this->ExitBtn->Click += gcnew System::EventHandler(this, &usersRegisterForm::ExitBtn_Click);
			// 
			// usersGenderCmbBx
			// 
			this->usersGenderCmbBx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->usersGenderCmbBx->FormattingEnabled = true;
			this->usersGenderCmbBx->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"М", L"Ж" });
			this->usersGenderCmbBx->Location = System::Drawing::Point(154, 149);
			this->usersGenderCmbBx->Name = L"usersGenderCmbBx";
			this->usersGenderCmbBx->Size = System::Drawing::Size(216, 24);
			this->usersGenderCmbBx->TabIndex = 14;
			// 
			// usersBirthDayDtTmPckr
			// 
			this->usersBirthDayDtTmPckr->Location = System::Drawing::Point(154, 194);
			this->usersBirthDayDtTmPckr->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->usersBirthDayDtTmPckr->Name = L"usersBirthDayDtTmPckr";
			this->usersBirthDayDtTmPckr->Size = System::Drawing::Size(215, 22);
			this->usersBirthDayDtTmPckr->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 281);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 16);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Пароль:";
			// 
			// usersPassTxtBx
			// 
			this->usersPassTxtBx->Location = System::Drawing::Point(154, 278);
			this->usersPassTxtBx->Name = L"usersPassTxtBx";
			this->usersPassTxtBx->Size = System::Drawing::Size(215, 22);
			this->usersPassTxtBx->TabIndex = 17;
			this->usersPassTxtBx->UseSystemPasswordChar = true;
			// 
			// usersPhoneMskdTxtBx
			// 
			this->usersPhoneMskdTxtBx->Location = System::Drawing::Point(154, 237);
			this->usersPhoneMskdTxtBx->Mask = L"+7(999)999-99-99";
			this->usersPhoneMskdTxtBx->Name = L"usersPhoneMskdTxtBx";
			this->usersPhoneMskdTxtBx->Size = System::Drawing::Size(116, 22);
			this->usersPhoneMskdTxtBx->TabIndex = 19;
			// 
			// usersRegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 377);
			this->Controls->Add(this->usersPhoneMskdTxtBx);
			this->Controls->Add(this->usersPassTxtBx);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->usersBirthDayDtTmPckr);
			this->Controls->Add(this->usersGenderCmbBx);
			this->Controls->Add(this->ExitBtn);
			this->Controls->Add(this->BackBtn);
			this->Controls->Add(this->usersRegisterBtn);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->usernameTxtBx);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->usersFioTxtBx);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(413, 424);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(413, 424);
			this->Name = L"usersRegisterForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &usersRegisterForm::usersRegisterForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &usersRegisterForm::usersRegisterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BackBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void usersRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void usersRegisterForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void usersFioTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void usersPhoneBTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void usersRegisterForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}

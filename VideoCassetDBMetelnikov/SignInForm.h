#pragma once
#include "StartMenuForm.h"
#include "RevievAndViewDBForm.h"
#include "UsersRegisterForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for SignInForm
	/// </summary>
	public ref class SignInForm : public System::Windows::Forms::Form
	{
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	public:
		SignInForm(void)
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
		~SignInForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  usersLoginTxtBx;
	private: System::Windows::Forms::TextBox^  usersPassTxtBx;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  SignInButton;

	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::Button^  RegistrationButton;




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
			this->usersLoginTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usersPassTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SignInButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->RegistrationButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(24, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вход в аккаунт";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Логин";
			// 
			// usersLoginTxtBx
			// 
			this->usersLoginTxtBx->Location = System::Drawing::Point(19, 82);
			this->usersLoginTxtBx->Name = L"usersLoginTxtBx";
			this->usersLoginTxtBx->Size = System::Drawing::Size(196, 22);
			this->usersLoginTxtBx->TabIndex = 2;
			// 
			// usersPassTxtBx
			// 
			this->usersPassTxtBx->Location = System::Drawing::Point(19, 128);
			this->usersPassTxtBx->Name = L"usersPassTxtBx";
			this->usersPassTxtBx->Size = System::Drawing::Size(196, 22);
			this->usersPassTxtBx->TabIndex = 4;
			this->usersPassTxtBx->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Пароль";
			// 
			// SignInButton
			// 
			this->SignInButton->Location = System::Drawing::Point(140, 156);
			this->SignInButton->Name = L"SignInButton";
			this->SignInButton->Size = System::Drawing::Size(75, 23);
			this->SignInButton->TabIndex = 15;
			this->SignInButton->Text = L"Войти";
			this->SignInButton->UseVisualStyleBackColor = true;
			this->SignInButton->Click += gcnew System::EventHandler(this, &SignInForm::SignInButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(59, 156);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(75, 23);
			this->BackButton->TabIndex = 16;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &SignInForm::BackButton_Click);
			// 
			// RegistrationButton
			// 
			this->RegistrationButton->Location = System::Drawing::Point(109, 192);
			this->RegistrationButton->Name = L"RegistrationButton";
			this->RegistrationButton->Size = System::Drawing::Size(106, 31);
			this->RegistrationButton->TabIndex = 17;
			this->RegistrationButton->Text = L"Регистрация";
			this->RegistrationButton->UseVisualStyleBackColor = true;
			this->RegistrationButton->Click += gcnew System::EventHandler(this, &SignInForm::RegistrationButton_Click);
			// 
			// SignInForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(236, 235);
			this->Controls->Add(this->RegistrationButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->SignInButton);
			this->Controls->Add(this->usersPassTxtBx);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->usersLoginTxtBx);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"SignInForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SignInForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void SignInButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void RegistrationButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}

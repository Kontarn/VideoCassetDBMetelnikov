#pragma once
#include "LogInForStaffForm.h"
#include "SignInForm.h"
#include "UsersRegisterForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartMenuForm
	/// </summary>
	public ref class StartMenuForm : public System::Windows::Forms::Form
	{
	public:
		StartMenuForm(void)
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
		~StartMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  LogInButton;
	protected:
	private: System::Windows::Forms::Button^  SignInButton;
	private: System::Windows::Forms::Button^  StaffButton;
	private: System::Windows::Forms::Button^  ExitButton;




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
			this->LogInButton = (gcnew System::Windows::Forms::Button());
			this->SignInButton = (gcnew System::Windows::Forms::Button());
			this->StaffButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LogInButton
			// 
			this->LogInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->LogInButton->Location = System::Drawing::Point(70, 19);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(258, 54);
			this->LogInButton->TabIndex = 0;
			this->LogInButton->Text = L"Войти в аккаунт";
			this->LogInButton->UseVisualStyleBackColor = true;
			this->LogInButton->Click += gcnew System::EventHandler(this, &StartMenuForm::LogInButton_Click);
			// 
			// SignInButton
			// 
			this->SignInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->SignInButton->Location = System::Drawing::Point(70, 79);
			this->SignInButton->Name = L"SignInButton";
			this->SignInButton->Size = System::Drawing::Size(258, 52);
			this->SignInButton->TabIndex = 1;
			this->SignInButton->Text = L"Регистрация аккаунта";
			this->SignInButton->UseVisualStyleBackColor = true;
			this->SignInButton->Click += gcnew System::EventHandler(this, &StartMenuForm::SignInButton_Click);
			// 
			// StaffButton
			// 
			this->StaffButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->StaffButton->Location = System::Drawing::Point(17, 138);
			this->StaffButton->Name = L"StaffButton";
			this->StaffButton->Size = System::Drawing::Size(198, 42);
			this->StaffButton->TabIndex = 2;
			this->StaffButton->Text = L"Для сотрудников";
			this->StaffButton->UseVisualStyleBackColor = true;
			this->StaffButton->Click += gcnew System::EventHandler(this, &StartMenuForm::StaffButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->ExitButton->Location = System::Drawing::Point(221, 137);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(158, 43);
			this->ExitButton->TabIndex = 3;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &StartMenuForm::ExitButton_Click);
			// 
			// StartMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 195);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->StaffButton);
			this->Controls->Add(this->SignInButton);
			this->Controls->Add(this->LogInButton);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(409, 242);
			this->MinimumSize = System::Drawing::Size(409, 242);
			this->Name = L"StartMenuForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartMenuForm::StartMenuForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void StaffButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void LogInButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void SignInButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void StartMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}

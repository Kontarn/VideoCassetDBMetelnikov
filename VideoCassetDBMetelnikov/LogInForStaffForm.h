#pragma once
#include "StartMenuForm.h"
#include "EditAndViewDBForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogInForStaffForm
	/// </summary>
	public ref class LogInForStaffForm : public System::Windows::Forms::Form
	{
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: SqlConnection^ sqlConn;
	public:
		LogInForStaffForm(void)
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
		~LogInForStaffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^ authCodeTxtBx;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  BackButton;

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
			this->authCodeTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.8F));
			this->label1->Location = System::Drawing::Point(64, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вход";
			// 
			// authCodeTxtBx
			// 
			this->authCodeTxtBx->Location = System::Drawing::Point(13, 116);
			this->authCodeTxtBx->Name = L"authCodeTxtBx";
			this->authCodeTxtBx->Size = System::Drawing::Size(194, 22);
			this->authCodeTxtBx->TabIndex = 1;
			this->authCodeTxtBx->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label2->Location = System::Drawing::Point(9, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите код доступа:";
			// 
			// OkButton
			// 
			this->OkButton->Location = System::Drawing::Point(131, 160);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(78, 36);
			this->OkButton->TabIndex = 3;
			this->OkButton->Text = L"Ок";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &LogInForStaffForm::OkButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(13, 160);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(93, 36);
			this->BackButton->TabIndex = 4;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &LogInForStaffForm::BackButton_Click);
			// 
			// LogInForStaffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(226, 212);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->OkButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->authCodeTxtBx);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(244, 259);
			this->MinimumSize = System::Drawing::Size(244, 259);
			this->Name = L"LogInForStaffForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LogInForStaffForm::LogInForStaffForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void LogInForStaffForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}

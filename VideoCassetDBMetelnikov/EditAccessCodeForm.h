#pragma once
#include "EditAndViewDBForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditAccessCodeForm
	/// </summary>
	public ref class EditAccessCodeForm : public System::Windows::Forms::Form
	{
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: SqlConnection^ sqlConn;
	public:
		EditAccessCodeForm(void)
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
		~EditAccessCodeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ oldCodeTxtBx;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ newCodeTxtBx;

	private: System::Windows::Forms::Button^ editAcessCodeBtn;
	private: System::Windows::Forms::Button^ backBtn;


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
			this->oldCodeTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->newCodeTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->editAcessCodeBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(29, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(248, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Изменение кода доступа";
			// 
			// oldCodeTxtBx
			// 
			this->oldCodeTxtBx->Location = System::Drawing::Point(112, 60);
			this->oldCodeTxtBx->Name = L"oldCodeTxtBx";
			this->oldCodeTxtBx->Size = System::Drawing::Size(176, 22);
			this->oldCodeTxtBx->TabIndex = 1;
			this->oldCodeTxtBx->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->Location = System::Drawing::Point(13, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Старый код";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label3->Location = System::Drawing::Point(13, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Новый код";
			// 
			// newCodeTxtBx
			// 
			this->newCodeTxtBx->Location = System::Drawing::Point(112, 103);
			this->newCodeTxtBx->Name = L"newCodeTxtBx";
			this->newCodeTxtBx->Size = System::Drawing::Size(176, 22);
			this->newCodeTxtBx->TabIndex = 3;
			this->newCodeTxtBx->UseSystemPasswordChar = true;
			// 
			// editAcessCodeBtn
			// 
			this->editAcessCodeBtn->Location = System::Drawing::Point(152, 150);
			this->editAcessCodeBtn->Name = L"editAcessCodeBtn";
			this->editAcessCodeBtn->Size = System::Drawing::Size(136, 37);
			this->editAcessCodeBtn->TabIndex = 5;
			this->editAcessCodeBtn->Text = L"Изменить";
			this->editAcessCodeBtn->UseVisualStyleBackColor = true;
			this->editAcessCodeBtn->Click += gcnew System::EventHandler(this, &EditAccessCodeForm::editAcessCodeBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->Location = System::Drawing::Point(16, 150);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(89, 37);
			this->backBtn->TabIndex = 6;
			this->backBtn->Text = L"Назад";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &EditAccessCodeForm::backBtn_Click);
			// 
			// EditAccessCodeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 210);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->editAcessCodeBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->newCodeTxtBx);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->oldCodeTxtBx);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(327, 257);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(327, 257);
			this->Name = L"EditAccessCodeForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void editAcessCodeBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

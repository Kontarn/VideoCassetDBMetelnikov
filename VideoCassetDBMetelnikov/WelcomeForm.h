#pragma once
#include "StartMenuForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WelcomeForm
	/// </summary>
	public ref class WelcomeForm : public System::Windows::Forms::Form
	{
	public:
		WelcomeForm(void)
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
		~WelcomeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ startBtn;
	protected:

	private: System::Windows::Forms::Button^ backButton;


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
			this->startBtn = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(46, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(440, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добро пожаловать в нашу видеотеку";
			// 
			// startBtn
			// 
			this->startBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->startBtn->Location = System::Drawing::Point(51, 129);
			this->startBtn->Name = L"startBtn";
			this->startBtn->Size = System::Drawing::Size(175, 47);
			this->startBtn->TabIndex = 1;
			this->startBtn->Text = L"Начать";
			this->startBtn->UseVisualStyleBackColor = true;
			this->startBtn->Click += gcnew System::EventHandler(this, &WelcomeForm::startBtn_Click);
			// 
			// backButton
			// 
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->backButton->Location = System::Drawing::Point(295, 127);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(188, 48);
			this->backButton->TabIndex = 2;
			this->backButton->Text = L"Выход";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &WelcomeForm::backButton_Click);
			// 
			// WelcomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 215);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->startBtn);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(557, 262);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(557, 262);
			this->Name = L"WelcomeForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &WelcomeForm::WelcomeForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void WelcomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void startBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

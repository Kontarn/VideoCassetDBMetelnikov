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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ÔÓÏÓ˘¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÔÓÏÓ˘¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// LogInButton
			// 
			this->LogInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->LogInButton->Location = System::Drawing::Point(67, 43);
			this->LogInButton->Name = L"LogInButton";
			this->LogInButton->Size = System::Drawing::Size(258, 54);
			this->LogInButton->TabIndex = 0;
			this->LogInButton->Text = L"¬ÓÈÚË ‚ ‡ÍÍ‡ÛÌÚ";
			this->LogInButton->UseVisualStyleBackColor = true;
			this->LogInButton->Click += gcnew System::EventHandler(this, &StartMenuForm::LogInButton_Click);
			// 
			// SignInButton
			// 
			this->SignInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->SignInButton->Location = System::Drawing::Point(67, 103);
			this->SignInButton->Name = L"SignInButton";
			this->SignInButton->Size = System::Drawing::Size(258, 52);
			this->SignInButton->TabIndex = 1;
			this->SignInButton->Text = L"–Â„ËÒÚ‡ˆËˇ ‡ÍÍ‡ÛÌÚ‡";
			this->SignInButton->UseVisualStyleBackColor = true;
			this->SignInButton->Click += gcnew System::EventHandler(this, &StartMenuForm::SignInButton_Click);
			// 
			// StaffButton
			// 
			this->StaffButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->StaffButton->Location = System::Drawing::Point(14, 162);
			this->StaffButton->Name = L"StaffButton";
			this->StaffButton->Size = System::Drawing::Size(198, 42);
			this->StaffButton->TabIndex = 2;
			this->StaffButton->Text = L"ƒÎˇ ÒÓÚÛ‰ÌËÍÓ‚";
			this->StaffButton->UseVisualStyleBackColor = true;
			this->StaffButton->Click += gcnew System::EventHandler(this, &StartMenuForm::StaffButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->ExitButton->Location = System::Drawing::Point(218, 161);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(158, 43);
			this->ExitButton->TabIndex = 3;
			this->ExitButton->Text = L"¬˚ıÓ‰";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &StartMenuForm::ExitButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÔÓÏÓ˘¸ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(391, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÔÓÏÓ˘¸ToolStripMenuItem
			// 
			this->ÔÓÏÓ˘¸ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem });
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Name = L"ÔÓÏÓ˘¸ToolStripMenuItem";
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Text = L"œÓÏÓ˘¸";
			// 
			// ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem
			// 
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem->Name = L"ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem";
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem->Size = System::Drawing::Size(270, 26);
			this->ÛÍÓ‚Ó‰ÒÚ‚ÓœÓÎ¸ÁÓ‚ÚÂÎˇToolStripMenuItem->Text = L"–ÛÍÓ‚Ó‰ÒÚ‚Ó ÔÓÎ¸ÁÓ‚ÚÂÎˇ";
			// 
			// StartMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 225);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->StaffButton);
			this->Controls->Add(this->SignInButton);
			this->Controls->Add(this->LogInButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"StartMenuForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartMenuForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void StaffButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void LogInButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void SignInButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}

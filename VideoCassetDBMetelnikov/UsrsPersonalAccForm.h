#pragma once
#include "RevievAndViewDBForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for UsrsPersonalAccForm
	/// </summary>
	public ref class UsrsPersonalAccForm : public System::Windows::Forms::Form
	{
	private: String^ userID;
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ usersPasTxtBx;
	private: System::Windows::Forms::Button^ editUsersPassBtn;
	private: SqlConnection^ sqlConn;
	public:
		UsrsPersonalAccForm(String^ userID) : userID(userID)
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
		~UsrsPersonalAccForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ usernameTxtBx;
	private: System::Windows::Forms::TextBox^ usersFioTxtBx;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ BirthdayfDtTmPckr;
	private: System::Windows::Forms::TextBox^ PhnNumTxtBx;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ComboBox^ genderCmbBx;
	private: System::Windows::Forms::Button^ editUsrsDataBtn;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ deleteFromFavoritesBtn;
	private: System::Windows::Forms::Button^ ExitBtn;




	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÏÂÌ˛ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem;



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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->usernameTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->usersFioTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BirthdayfDtTmPckr = (gcnew System::Windows::Forms::DateTimePicker());
			this->PhnNumTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->genderCmbBx = (gcnew System::Windows::Forms::ComboBox());
			this->editUsrsDataBtn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->deleteFromFavoritesBtn = (gcnew System::Windows::Forms::Button());
			this->ExitBtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÏÂÌ˛ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->usersPasTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->editUsersPassBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(166, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ÀË˜Ì˚È Í‡·ËÌÂÚ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(337, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ÀÓ„ËÌ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"‘»Œ:";
			// 
			// usernameTxtBx
			// 
			this->usernameTxtBx->Location = System::Drawing::Point(340, 104);
			this->usernameTxtBx->Name = L"usernameTxtBx";
			this->usernameTxtBx->Size = System::Drawing::Size(189, 22);
			this->usernameTxtBx->TabIndex = 4;
			// 
			// usersFioTxtBx
			// 
			this->usersFioTxtBx->Location = System::Drawing::Point(147, 70);
			this->usersFioTxtBx->Name = L"usersFioTxtBx";
			this->usersFioTxtBx->Size = System::Drawing::Size(169, 22);
			this->usersFioTxtBx->TabIndex = 5;
			this->usersFioTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UsrsPersonalAccForm::usersFioTxtBx_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"œÓÎ:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"ƒÂÌ¸ ÓÊ‰ÂÌËˇ:";
			// 
			// BirthdayfDtTmPckr
			// 
			this->BirthdayfDtTmPckr->Location = System::Drawing::Point(147, 132);
			this->BirthdayfDtTmPckr->Name = L"BirthdayfDtTmPckr";
			this->BirthdayfDtTmPckr->Size = System::Drawing::Size(169, 22);
			this->BirthdayfDtTmPckr->TabIndex = 9;
			// 
			// PhnNumTxtBx
			// 
			this->PhnNumTxtBx->Location = System::Drawing::Point(147, 164);
			this->PhnNumTxtBx->Name = L"PhnNumTxtBx";
			this->PhnNumTxtBx->Size = System::Drawing::Size(169, 22);
			this->PhnNumTxtBx->TabIndex = 10;
			this->PhnNumTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UsrsPersonalAccForm::PhnNumTxtBx_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 164);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"ÕÓÏÂ ÚÂÎÂÙÓÌ‡:";
			// 
			// genderCmbBx
			// 
			this->genderCmbBx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->genderCmbBx->FormattingEnabled = true;
			this->genderCmbBx->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ã", L"∆" });
			this->genderCmbBx->Location = System::Drawing::Point(147, 102);
			this->genderCmbBx->Name = L"genderCmbBx";
			this->genderCmbBx->Size = System::Drawing::Size(169, 24);
			this->genderCmbBx->TabIndex = 12;
			// 
			// editUsrsDataBtn
			// 
			this->editUsrsDataBtn->Location = System::Drawing::Point(15, 198);
			this->editUsrsDataBtn->Name = L"editUsrsDataBtn";
			this->editUsrsDataBtn->Size = System::Drawing::Size(198, 43);
			this->editUsrsDataBtn->TabIndex = 13;
			this->editUsrsDataBtn->Text = L"»ÁÏÂÌËÚ¸ ÎË˜Ì˚Â ‰‡ÌÌ˚Â";
			this->editUsrsDataBtn->UseVisualStyleBackColor = true;
			this->editUsrsDataBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::editUsrsDataBtn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(12, 257);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(176, 20);
			this->label7->TabIndex = 14;
			this->label7->Text = L"»Á·‡ÌÌ˚Â ÙËÎ¸Ï˚";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(15, 280);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(514, 251);
			this->dataGridView1->TabIndex = 15;
			// 
			// deleteFromFavoritesBtn
			// 
			this->deleteFromFavoritesBtn->Location = System::Drawing::Point(408, 554);
			this->deleteFromFavoritesBtn->Name = L"deleteFromFavoritesBtn";
			this->deleteFromFavoritesBtn->Size = System::Drawing::Size(121, 44);
			this->deleteFromFavoritesBtn->TabIndex = 17;
			this->deleteFromFavoritesBtn->Text = L"”‰‡ÎËÚ¸ Á‡ÔËÒ¸";
			this->deleteFromFavoritesBtn->UseVisualStyleBackColor = true;
			this->deleteFromFavoritesBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::deleteFromFavoritesBtn_Click);
			// 
			// ExitBtn
			// 
			this->ExitBtn->Location = System::Drawing::Point(15, 553);
			this->ExitBtn->Name = L"ExitBtn";
			this->ExitBtn->Size = System::Drawing::Size(141, 45);
			this->ExitBtn->TabIndex = 18;
			this->ExitBtn->Text = L"¬˚ıÓ‰";
			this->ExitBtn->UseVisualStyleBackColor = true;
			this->ExitBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::ExitBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÏÂÌ˛ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(546, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÏÂÌ˛ToolStripMenuItem
			// 
			this->ÏÂÌ˛ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem,
					this->‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem
			});
			this->ÏÂÌ˛ToolStripMenuItem->Name = L"ÏÂÌ˛ToolStripMenuItem";
			this->ÏÂÌ˛ToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ÏÂÌ˛ToolStripMenuItem->Text = L"ÃÂÌ˛";
			// 
			// Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem
			// 
			this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem->Name = L"Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem";
			this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem->Text = L" ‡Ú‡ÎÓ„ ÙËÎ¸ÏÓ‚";
			this->Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem_Click);
			// 
			// ‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem
			// 
			this->‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem->Name = L"‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem";
			this->‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->‚˚ıÓ‰»Á¿ÍÍ‡ÛÌÚ‡ToolStripMenuItem->Text = L"¬˚ıÓ‰ ËÁ ‡ÍÍ‡ÛÌÚ‡";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(337, 145);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(166, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"¬‚Â‰ËÚÂ ÒÚ‡˚È Ô‡ÓÎ¸:";
			// 
			// usersPasTxtBx
			// 
			this->usersPasTxtBx->Location = System::Drawing::Point(340, 164);
			this->usersPasTxtBx->Name = L"usersPasTxtBx";
			this->usersPasTxtBx->Size = System::Drawing::Size(189, 22);
			this->usersPasTxtBx->TabIndex = 21;
			// 
			// editUsersPassBtn
			// 
			this->editUsersPassBtn->Location = System::Drawing::Point(340, 198);
			this->editUsersPassBtn->Name = L"editUsersPassBtn";
			this->editUsersPassBtn->Size = System::Drawing::Size(189, 43);
			this->editUsersPassBtn->TabIndex = 22;
			this->editUsersPassBtn->Text = L"»ÁÏÂÌËÚ¸ ÎÓ„ËÌ ËÎË Ô‡ÓÎ¸";
			this->editUsersPassBtn->UseVisualStyleBackColor = true;
			// 
			// UsrsPersonalAccForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 613);
			this->Controls->Add(this->editUsersPassBtn);
			this->Controls->Add(this->usersPasTxtBx);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ExitBtn);
			this->Controls->Add(this->deleteFromFavoritesBtn);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->editUsrsDataBtn);
			this->Controls->Add(this->genderCmbBx);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->PhnNumTxtBx);
			this->Controls->Add(this->BirthdayfDtTmPckr);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->usersFioTxtBx);
			this->Controls->Add(this->usernameTxtBx);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UsrsPersonalAccForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UsrsPersonalAccForm";
			this->Load += gcnew System::EventHandler(this, &UsrsPersonalAccForm::UsrsPersonalAccForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Í‡Ú‡ÎÓ„‘ËÎ¸ÏÓ‚ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void UsrsPersonalAccForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void deleteFromFavoritesBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: void loadDataToDataGrid();
private: System::Void editUsrsDataBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void usersFioTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void PhnNumTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
};
}

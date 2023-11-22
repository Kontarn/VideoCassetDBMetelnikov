#pragma once
#include "RevievAndViewDBForm.h"
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
	/// Summary for UsrsPersonalAccForm
	/// </summary>
	public ref class UsrsPersonalAccForm : public System::Windows::Forms::Form
	{
	private: String^ userID;
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ usersOldPasTxtBx;

	private: System::Windows::Forms::Button^ editUsersPassBtn;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ usersNewPassTxtBx;
	private: System::Windows::Forms::DataGridView^ rentFilmsDtGrdView;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::MaskedTextBox^ PhnNumTxtBx;

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



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ComboBox^ genderCmbBx;
	private: System::Windows::Forms::Button^ editUsrsDataBtn;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ favoriteMoviesDtGrdView;



	private: System::Windows::Forms::Button^ deleteFromFavoritesBtn;
	private: System::Windows::Forms::Button^ ExitBtn;




	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;



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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->genderCmbBx = (gcnew System::Windows::Forms::ComboBox());
			this->editUsrsDataBtn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->favoriteMoviesDtGrdView = (gcnew System::Windows::Forms::DataGridView());
			this->deleteFromFavoritesBtn = (gcnew System::Windows::Forms::Button());
			this->ExitBtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->usersOldPasTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->editUsersPassBtn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->usersNewPassTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->rentFilmsDtGrdView = (gcnew System::Windows::Forms::DataGridView());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->PhnNumTxtBx = (gcnew System::Windows::Forms::MaskedTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->favoriteMoviesDtGrdView))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rentFilmsDtGrdView))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(168, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������ �������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(342, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"�����";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"���:";
			// 
			// usernameTxtBx
			// 
			this->usernameTxtBx->Location = System::Drawing::Point(345, 73);
			this->usernameTxtBx->Name = L"usernameTxtBx";
			this->usernameTxtBx->Size = System::Drawing::Size(184, 22);
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
			this->label4->Text = L"���:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"���� ��������:";
			// 
			// BirthdayfDtTmPckr
			// 
			this->BirthdayfDtTmPckr->Location = System::Drawing::Point(147, 138);
			this->BirthdayfDtTmPckr->Name = L"BirthdayfDtTmPckr";
			this->BirthdayfDtTmPckr->Size = System::Drawing::Size(169, 22);
			this->BirthdayfDtTmPckr->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 176);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"����� ��������:";
			// 
			// genderCmbBx
			// 
			this->genderCmbBx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->genderCmbBx->FormattingEnabled = true;
			this->genderCmbBx->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�", L"�" });
			this->genderCmbBx->Location = System::Drawing::Point(147, 102);
			this->genderCmbBx->Name = L"genderCmbBx";
			this->genderCmbBx->Size = System::Drawing::Size(169, 24);
			this->genderCmbBx->TabIndex = 12;
			// 
			// editUsrsDataBtn
			// 
			this->editUsrsDataBtn->Location = System::Drawing::Point(16, 214);
			this->editUsrsDataBtn->Name = L"editUsrsDataBtn";
			this->editUsrsDataBtn->Size = System::Drawing::Size(198, 43);
			this->editUsrsDataBtn->TabIndex = 13;
			this->editUsrsDataBtn->Text = L"�������� ������ ������";
			this->editUsrsDataBtn->UseVisualStyleBackColor = true;
			this->editUsrsDataBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::editUsrsDataBtn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(550, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(176, 20);
			this->label7->TabIndex = 14;
			this->label7->Text = L"��������� ������";
			// 
			// favoriteMoviesDtGrdView
			// 
			this->favoriteMoviesDtGrdView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->favoriteMoviesDtGrdView->Location = System::Drawing::Point(553, 73);
			this->favoriteMoviesDtGrdView->Name = L"favoriteMoviesDtGrdView";
			this->favoriteMoviesDtGrdView->RowHeadersWidth = 51;
			this->favoriteMoviesDtGrdView->RowTemplate->Height = 24;
			this->favoriteMoviesDtGrdView->Size = System::Drawing::Size(703, 458);
			this->favoriteMoviesDtGrdView->TabIndex = 15;
			// 
			// deleteFromFavoritesBtn
			// 
			this->deleteFromFavoritesBtn->Location = System::Drawing::Point(1004, 557);
			this->deleteFromFavoritesBtn->Name = L"deleteFromFavoritesBtn";
			this->deleteFromFavoritesBtn->Size = System::Drawing::Size(252, 44);
			this->deleteFromFavoritesBtn->TabIndex = 17;
			this->deleteFromFavoritesBtn->Text = L"������� ����� �� ����������";
			this->deleteFromFavoritesBtn->UseVisualStyleBackColor = true;
			this->deleteFromFavoritesBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::deleteFromFavoritesBtn_Click);
			// 
			// ExitBtn
			// 
			this->ExitBtn->Location = System::Drawing::Point(553, 556);
			this->ExitBtn->Name = L"ExitBtn";
			this->ExitBtn->Size = System::Drawing::Size(141, 45);
			this->ExitBtn->TabIndex = 18;
			this->ExitBtn->Text = L"�����";
			this->ExitBtn->UseVisualStyleBackColor = true;
			this->ExitBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::ExitBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1268, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������������ToolStripMenuItem,
					this->���������������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->��������������ToolStripMenuItem->Text = L"������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::��������������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(220, 26);
			this->���������������ToolStripMenuItem->Text = L"����� �� ��������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::���������������ToolStripMenuItem_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(342, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(166, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"������� ������ ������:";
			// 
			// usersOldPasTxtBx
			// 
			this->usersOldPasTxtBx->Location = System::Drawing::Point(345, 129);
			this->usersOldPasTxtBx->Name = L"usersOldPasTxtBx";
			this->usersOldPasTxtBx->Size = System::Drawing::Size(184, 22);
			this->usersOldPasTxtBx->TabIndex = 21;
			// 
			// editUsersPassBtn
			// 
			this->editUsersPassBtn->Location = System::Drawing::Point(345, 214);
			this->editUsersPassBtn->Name = L"editUsersPassBtn";
			this->editUsersPassBtn->Size = System::Drawing::Size(184, 43);
			this->editUsersPassBtn->TabIndex = 22;
			this->editUsersPassBtn->Text = L"�������� ������";
			this->editUsersPassBtn->UseVisualStyleBackColor = true;
			this->editUsersPassBtn->Click += gcnew System::EventHandler(this, &UsrsPersonalAccForm::editUsersPassBtn_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(342, 154);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(157, 16);
			this->label9->TabIndex = 23;
			this->label9->Text = L"������� ����� ������";
			// 
			// usersNewPassTxtBx
			// 
			this->usersNewPassTxtBx->Location = System::Drawing::Point(345, 173);
			this->usersNewPassTxtBx->Name = L"usersNewPassTxtBx";
			this->usersNewPassTxtBx->Size = System::Drawing::Size(184, 22);
			this->usersNewPassTxtBx->TabIndex = 24;
			// 
			// rentFilmsDtGrdView
			// 
			this->rentFilmsDtGrdView->AllowUserToAddRows = false;
			this->rentFilmsDtGrdView->AllowUserToDeleteRows = false;
			this->rentFilmsDtGrdView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->rentFilmsDtGrdView->Location = System::Drawing::Point(16, 297);
			this->rentFilmsDtGrdView->Name = L"rentFilmsDtGrdView";
			this->rentFilmsDtGrdView->ReadOnly = true;
			this->rentFilmsDtGrdView->RowHeadersWidth = 51;
			this->rentFilmsDtGrdView->RowTemplate->Height = 24;
			this->rentFilmsDtGrdView->Size = System::Drawing::Size(513, 234);
			this->rentFilmsDtGrdView->TabIndex = 25;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label10->Location = System::Drawing::Point(12, 274);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(225, 20);
			this->label10->TabIndex = 26;
			this->label10->Text = L"������ ������ � ������";
			// 
			// PhnNumTxtBx
			// 
			this->PhnNumTxtBx->Location = System::Drawing::Point(147, 170);
			this->PhnNumTxtBx->Mask = L"+9(999)999-99-99";
			this->PhnNumTxtBx->Name = L"PhnNumTxtBx";
			this->PhnNumTxtBx->Size = System::Drawing::Size(120, 22);
			this->PhnNumTxtBx->TabIndex = 27;
			// 
			// UsrsPersonalAccForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1268, 613);
			this->Controls->Add(this->PhnNumTxtBx);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->rentFilmsDtGrdView);
			this->Controls->Add(this->usersNewPassTxtBx);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->editUsersPassBtn);
			this->Controls->Add(this->usersOldPasTxtBx);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ExitBtn);
			this->Controls->Add(this->deleteFromFavoritesBtn);
			this->Controls->Add(this->favoriteMoviesDtGrdView);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->editUsrsDataBtn);
			this->Controls->Add(this->genderCmbBx);
			this->Controls->Add(this->label6);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->favoriteMoviesDtGrdView))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rentFilmsDtGrdView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void UsrsPersonalAccForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void deleteFromFavoritesBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: void loadDataToFavoriteFilmsDtGrd();
private: System::Void editUsrsDataBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void usersFioTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void PhnNumTxtBx_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void editUsersPassBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#pragma once
#include "StartMenuForm.h"
#include "AdvSearchUserForm.h"
#include "AdditionalInfoFilmForm.h"
#include "UsrsPersonalAccForm.h"
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
	/// Summary for RevievAndViewDBForm
	/// </summary>
	public ref class RevievAndViewDBForm : public System::Windows::Forms::Form
	{
	private:
		String^ userID;
		AdvSearchUserForm^ AdvSrchUsrF;
		String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;
		SqlDataAdapter^ sqlDA;
		SqlCommandBuilder^ sqlCmdBuild;
		DataSet^ dataSet;
	private: System::Windows::Forms::Button^  ShwAllEntrsBtn;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem;




	private: System::Windows::Forms::Button^  FindToDBButton;

	public:
		RevievAndViewDBForm(String^ userID) : userID(userID)
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
		~RevievAndViewDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  MoreInfoAboutFilmButton;
	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::Button^  ExitButton;
	protected:




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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->MoreInfoAboutFilmButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->FindToDBButton = (gcnew System::Windows::Forms::Button());
			this->ShwAllEntrsBtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(15, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(400, 460);
			this->dataGridView1->TabIndex = 0;
			// 
			// MoreInfoAboutFilmButton
			// 
			this->MoreInfoAboutFilmButton->Location = System::Drawing::Point(15, 497);
			this->MoreInfoAboutFilmButton->Name = L"MoreInfoAboutFilmButton";
			this->MoreInfoAboutFilmButton->Size = System::Drawing::Size(173, 45);
			this->MoreInfoAboutFilmButton->TabIndex = 1;
			this->MoreInfoAboutFilmButton->Text = L"œÓ‰Ó·ÌÂÂ Ó ÙËÎ¸ÏÂ";
			this->MoreInfoAboutFilmButton->UseVisualStyleBackColor = true;
			this->MoreInfoAboutFilmButton->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::MoreInfoAboutFilmButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(146, 561);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(113, 45);
			this->BackButton->TabIndex = 2;
			this->BackButton->Text = L"Õ‡Á‡‰";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::BackButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(265, 561);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(150, 45);
			this->ExitButton->TabIndex = 3;
			this->ExitButton->Text = L"«‡Í˚Ú¸ ÔÓ„‡ÏÏÛ";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::ExitButton_Click);
			// 
			// FindToDBButton
			// 
			this->FindToDBButton->Location = System::Drawing::Point(265, 497);
			this->FindToDBButton->Name = L"FindToDBButton";
			this->FindToDBButton->Size = System::Drawing::Size(150, 46);
			this->FindToDBButton->TabIndex = 4;
			this->FindToDBButton->Text = L"œÓËÒÍ ÔÓ Í‡Ú‡ÎÓ„Û";
			this->FindToDBButton->UseVisualStyleBackColor = true;
			this->FindToDBButton->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::FindToDBButton_Click);
			// 
			// ShwAllEntrsBtn
			// 
			this->ShwAllEntrsBtn->Location = System::Drawing::Point(15, 561);
			this->ShwAllEntrsBtn->Name = L"ShwAllEntrsBtn";
			this->ShwAllEntrsBtn->Size = System::Drawing::Size(125, 45);
			this->ShwAllEntrsBtn->TabIndex = 5;
			this->ShwAllEntrsBtn->Text = L"œÓÍ‡Á‡Ú¸ ‚ÒÂ";
			this->ShwAllEntrsBtn->UseVisualStyleBackColor = true;
			this->ShwAllEntrsBtn->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::ShwAllEntrsBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem,
					this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(429, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem
			// 
			this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem->Name = L"ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem";
			this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem->Size = System::Drawing::Size(139, 24);
			this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem->Text = L"ÀË˜Ì˚È Í‡·ËÌÂÚ";
			this->ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem_Click_1);
			// 
			// ‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem
			// 
			this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem->Name = L"‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem";
			this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem->Size = System::Drawing::Size(150, 24);
			this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem->Text = L"¬˚ıÓ‰ ËÁ ÒËÒÚÂÏ˚";
			this->‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem->Click += gcnew System::EventHandler(this, &RevievAndViewDBForm::‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem_Click);
			// 
			// RevievAndViewDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 623);
			this->Controls->Add(this->ShwAllEntrsBtn);
			this->Controls->Add(this->FindToDBButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->MoreInfoAboutFilmButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(447, 670);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(447, 670);
			this->Name = L"RevievAndViewDBForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RevievAndViewDBForm::RevievAndViewDBForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RevievAndViewDBForm::RevievAndViewDBForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void RevievAndViewDBForm_Load(System::Object^  sender, System::EventArgs^  e);
private: void loadData();
private: void mySubscriber(System::Object^ sender, System::EventArgs^ e, System::String^ str);
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void FindToDBButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void MoreInfoAboutFilmButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ShwAllEntrsBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void RevievAndViewDBForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void ÎË˜Ì˚È ‡·ËÌÂÚToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void ‚˚ıÓ‰»Á—ËÒÚÂÏ˚ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}

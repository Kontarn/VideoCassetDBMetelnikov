#pragma once

#include "HystorySortMethodForm.h"
#include "HystoryAdvanedSearchForm.h"
#include "StartMenuForm.h"
#include "EditAndViewDBForm.h"
#include "LogInForStaffForm.h"
#include "EditAccessCodeForm.h"
#include "MoreInfoAboutUserForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for HystoryOfBuyForm
	/// </summary>
	public ref class HystoryOfBuyForm : public System::Windows::Forms::Form
	{
	private:
		String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;
		SqlCommandBuilder^ sqlBuild;
		SqlDataAdapter^ sqlDA;
		DataSet^ dataset;
		HystorySortMethodForm^ hystSortMethF;
	private: System::Windows::Forms::Button^  ShowAllEntrysButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;




	private: System::Windows::Forms::Button^ moreAboutUserBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ изменитьКодДоступаToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходИзАккаунтаToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ редактированиеБДToolStripMenuItem;

			 HystoryAdvanedSearchForm^ hystAdvSearchF;
	public:
		HystoryOfBuyForm(void)
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
		~HystoryOfBuyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^  dataGridView1;




	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::Button^  toStartMenuBtn;






	private: System::Windows::Forms::Button^  AdvancedSearchButton;
	private: System::Windows::Forms::Button^  ExitButton;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toStartMenuBtn = (gcnew System::Windows::Forms::Button());
			this->AdvancedSearchButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllEntrysButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->редактированиеБДToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->изменитьКодДоступаToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходИзАккаунтаToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moreAboutUserBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(19, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(829, 551);
			this->dataGridView1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// toStartMenuBtn
			// 
			this->toStartMenuBtn->Location = System::Drawing::Point(718, 588);
			this->toStartMenuBtn->Name = L"toStartMenuBtn";
			this->toStartMenuBtn->Size = System::Drawing::Size(130, 42);
			this->toStartMenuBtn->TabIndex = 8;
			this->toStartMenuBtn->Text = L"В главное меню";
			this->toStartMenuBtn->UseVisualStyleBackColor = true;
			this->toStartMenuBtn->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::toStartMenuBtn_Click);
			// 
			// AdvancedSearchButton
			// 
			this->AdvancedSearchButton->Location = System::Drawing::Point(151, 588);
			this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
			this->AdvancedSearchButton->Size = System::Drawing::Size(194, 42);
			this->AdvancedSearchButton->TabIndex = 10;
			this->AdvancedSearchButton->Text = L"Расширенный поиск";
			this->AdvancedSearchButton->UseVisualStyleBackColor = true;
			this->AdvancedSearchButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::AdvancedSearchButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(566, 589);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(146, 42);
			this->ExitButton->TabIndex = 11;
			this->ExitButton->Text = L"Закрыть программу";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ExitButton_Click);
			// 
			// ShowAllEntrysButton
			// 
			this->ShowAllEntrysButton->Location = System::Drawing::Point(19, 588);
			this->ShowAllEntrysButton->Name = L"ShowAllEntrysButton";
			this->ShowAllEntrysButton->Size = System::Drawing::Size(126, 42);
			this->ShowAllEntrysButton->TabIndex = 12;
			this->ShowAllEntrysButton->Text = L"Отобразить";
			this->ShowAllEntrysButton->UseVisualStyleBackColor = true;
			this->ShowAllEntrysButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ShowAllEntrysButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->редактированиеБДToolStripMenuItem,
					this->изменитьКодДоступаToolStripMenuItem1, this->выходИзАккаунтаToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(860, 28);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// редактированиеБДToolStripMenuItem
			// 
			this->редактированиеБДToolStripMenuItem->Name = L"редактированиеБДToolStripMenuItem";
			this->редактированиеБДToolStripMenuItem->Size = System::Drawing::Size(160, 24);
			this->редактированиеБДToolStripMenuItem->Text = L"Редактирование БД";
			this->редактированиеБДToolStripMenuItem->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::редактированиеБДToolStripMenuItem_Click_1);
			// 
			// изменитьКодДоступаToolStripMenuItem1
			// 
			this->изменитьКодДоступаToolStripMenuItem1->Name = L"изменитьКодДоступаToolStripMenuItem1";
			this->изменитьКодДоступаToolStripMenuItem1->Size = System::Drawing::Size(178, 24);
			this->изменитьКодДоступаToolStripMenuItem1->Text = L"Изменить код доступа";
			this->изменитьКодДоступаToolStripMenuItem1->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::изменитьКодДоступаToolStripMenuItem1_Click);
			// 
			// выходИзАккаунтаToolStripMenuItem1
			// 
			this->выходИзАккаунтаToolStripMenuItem1->Name = L"выходИзАккаунтаToolStripMenuItem1";
			this->выходИзАккаунтаToolStripMenuItem1->Size = System::Drawing::Size(151, 24);
			this->выходИзАккаунтаToolStripMenuItem1->Text = L"Выход из аккаунта";
			this->выходИзАккаунтаToolStripMenuItem1->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::выходИзАккаунтаToolStripMenuItem1_Click);
			// 
			// moreAboutUserBtn
			// 
			this->moreAboutUserBtn->Location = System::Drawing::Point(351, 588);
			this->moreAboutUserBtn->Name = L"moreAboutUserBtn";
			this->moreAboutUserBtn->Size = System::Drawing::Size(209, 43);
			this->moreAboutUserBtn->TabIndex = 14;
			this->moreAboutUserBtn->Text = L"Подробнее о пользователе";
			this->moreAboutUserBtn->UseVisualStyleBackColor = true;
			this->moreAboutUserBtn->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::moreAboutUserBtn_Click);
			// 
			// HystoryOfBuyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 642);
			this->Controls->Add(this->moreAboutUserBtn);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->ShowAllEntrysButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->AdvancedSearchButton);
			this->Controls->Add(this->toStartMenuBtn);
			this->Controls->Add(this->dataGridView1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(878, 689);
			this->MinimumSize = System::Drawing::Size(878, 689);
			this->Name = L"HystoryOfBuyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &HystoryOfBuyForm::HystoryOfBuyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &HystoryOfBuyForm::HystoryOfBuyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void HystoryOfBuyForm_Load(System::Object^  sender, System::EventArgs^  e);
private: void LoadData();
private: void mySubscriber(System::Object^ sender, System::EventArgs^ e, System::String^ str);
private: System::Void AdvancedSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void toStartMenuBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void редактированиеБДToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void выходИзАккаунтаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void изменитьКодДоступаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void HystoryOfBuyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

private: System::Void редактированиеБДToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void изменитьКодДоступаToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void выходИзАккаунтаToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void moreAboutUserBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

#pragma once

#include "HystorySortMethodForm.h"
#include "HystoryAdvanedSearchForm.h"
#include "StartMenuForm.h"
#include "EditAndViewDBForm.h"

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
		String^ connString = "Data Source=LAPTOP-P056EURT;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;
		SqlCommandBuilder^ sqlBuild;
		SqlDataAdapter^ sqlDA;
		DataSet^ dataset;
		HystorySortMethodForm^ hystSortMethF;
	private: System::Windows::Forms::Button^  ShowAllEntrysButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ğåäàêòèğîâàíèåÁÄToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  èçìåíèòüÊîäÄîñòóïàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäÈçÀêêàóíòàToolStripMenuItem;

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
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èçìåíèòüÊîäÄîñòóïàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->toStartMenuBtn->Location = System::Drawing::Point(689, 588);
			this->toStartMenuBtn->Name = L"toStartMenuBtn";
			this->toStartMenuBtn->Size = System::Drawing::Size(156, 42);
			this->toStartMenuBtn->TabIndex = 8;
			this->toStartMenuBtn->Text = L"Â ãëàâíîå ìåíş";
			this->toStartMenuBtn->UseVisualStyleBackColor = true;
			this->toStartMenuBtn->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::toStartMenuBtn_Click);
			// 
			// AdvancedSearchButton
			// 
			this->AdvancedSearchButton->Location = System::Drawing::Point(216, 591);
			this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
			this->AdvancedSearchButton->Size = System::Drawing::Size(194, 39);
			this->AdvancedSearchButton->TabIndex = 10;
			this->AdvancedSearchButton->Text = L"Ğàñøèğåííûé ïîèñê";
			this->AdvancedSearchButton->UseVisualStyleBackColor = true;
			this->AdvancedSearchButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::AdvancedSearchButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(566, 589);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(117, 42);
			this->ExitButton->TabIndex = 11;
			this->ExitButton->Text = L"Âûõîä";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ExitButton_Click);
			// 
			// ShowAllEntrysButton
			// 
			this->ShowAllEntrysButton->Location = System::Drawing::Point(16, 591);
			this->ShowAllEntrysButton->Name = L"ShowAllEntrysButton";
			this->ShowAllEntrysButton->Size = System::Drawing::Size(194, 39);
			this->ShowAllEntrysButton->TabIndex = 12;
			this->ShowAllEntrysButton->Text = L"Îòîáğàçèòü";
			this->ShowAllEntrysButton->UseVisualStyleBackColor = true;
			this->ShowAllEntrysButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ShowAllEntrysButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ìåíşToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(860, 28);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem,
					this->èçìåíèòüÊîäÄîñòóïàToolStripMenuItem, this->âûõîäÈçÀêêàóíòàToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(63, 24);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// ğåäàêòèğîâàíèåÁÄToolStripMenuItem
			// 
			this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem->Name = L"ğåäàêòèğîâàíèåÁÄToolStripMenuItem";
			this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem->Size = System::Drawing::Size(239, 26);
			this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem->Text = L"Ğåäàêòèğîâàíèå ÁÄ";
			this->ğåäàêòèğîâàíèåÁÄToolStripMenuItem->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ğåäàêòèğîâàíèåÁÄToolStripMenuItem_Click);
			// 
			// èçìåíèòüÊîäÄîñòóïàToolStripMenuItem
			// 
			this->èçìåíèòüÊîäÄîñòóïàToolStripMenuItem->Name = L"èçìåíèòüÊîäÄîñòóïàToolStripMenuItem";
			this->èçìåíèòüÊîäÄîñòóïàToolStripMenuItem->Size = System::Drawing::Size(239, 26);
			this->èçìåíèòüÊîäÄîñòóïàToolStripMenuItem->Text = L"Èçìåíèòü êîä äîñòóïà";
			// 
			// âûõîäÈçÀêêàóíòàToolStripMenuItem
			// 
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Name = L"âûõîäÈçÀêêàóíòàToolStripMenuItem";
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Size = System::Drawing::Size(239, 26);
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Text = L"Âûõîä èç àêêàóíòà";
			// 
			// HystoryOfBuyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 642);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->ShowAllEntrysButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->AdvancedSearchButton);
			this->Controls->Add(this->toStartMenuBtn);
			this->Controls->Add(this->dataGridView1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"HystoryOfBuyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HystoryOfBuyForm";
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
private: System::Void ğåäàêòèğîâàíèåÁÄToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}

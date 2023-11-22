#pragma once

#include "AddEntrysForm.h"
#include "EditEntrysForm.h"
#include "AdvancedSearchForm.h"
#include "SortMethodForm.h"
#include "HystoryOfBuyForm.h"
#include "StartMenuForm.h"
#include "LogInForStaffForm.h"
#include "EditAccessCodeForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for EditAndViewDBForm
	/// </summary>
	public ref class EditAndViewDBForm : public System::Windows::Forms::Form
	{
	//public: delegate void EventDelegate1(System::Object^ sender, System::EventArgs^ e, Data);
	//public: event EventDelegate1^ myEvent1;
	public:
		EditAndViewDBForm()
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
		~EditAndViewDBForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::Button^  AddEntryButton;


	private: System::Windows::Forms::Button^  DeleteButton;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  FindButton;
	private: System::Windows::Forms::Button^  AdvancedSearchButton;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  ShowAllEntrysButton;
	

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		SqlConnection^ sqlConn;
		SqlCommandBuilder^ sqlBuild;
		SqlDataAdapter^ sqlDA;
	private: AdvancedSearchForm^ advSearchF;
	private: SortMethodForm^ sortMethF;
		

	private: System::Windows::Forms::Button^  SortButton;
	private: System::Windows::Forms::Button^  toStartMenuBtn;

	private: System::Windows::Forms::Button^  ExitButton;
	private: DataSet^ dataset;
	private: System::Windows::Forms::Button^  EditEntryButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  èñòîğèÿÇàêàçîâToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñìåíèòüÊîäÄîñòóïàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäÈçÀêêàóíòàToolStripMenuItem;
			 String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->AddEntryButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->AdvancedSearchButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllEntrysButton = (gcnew System::Windows::Forms::Button());
			this->toStartMenuBtn = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->EditEntryButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èñòîğèÿÇàêàçîâToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(697, 446);
			this->dataGridView1->TabIndex = 0;
			// 
			// AddEntryButton
			// 
			this->AddEntryButton->Location = System::Drawing::Point(15, 506);
			this->AddEntryButton->Name = L"AddEntryButton";
			this->AddEntryButton->Size = System::Drawing::Size(143, 34);
			this->AddEntryButton->TabIndex = 1;
			this->AddEntryButton->Text = L"Äîáàâèòü çàïèñü";
			this->AddEntryButton->UseVisualStyleBackColor = true;
			this->AddEntryButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::AddEntryButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(15, 570);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(143, 34);
			this->DeleteButton->TabIndex = 3;
			this->DeleteButton->Text = L"Óäàëèòü çàïèñü";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::DeleteButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(164, 506);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(446, 34);
			this->textBox1->TabIndex = 4;
			// 
			// FindButton
			// 
			this->FindButton->Location = System::Drawing::Point(616, 506);
			this->FindButton->Name = L"FindButton";
			this->FindButton->Size = System::Drawing::Size(93, 34);
			this->FindButton->TabIndex = 5;
			this->FindButton->Text = L"Ïîèñê";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::FindButton_Click);
			// 
			// AdvancedSearchButton
			// 
			this->AdvancedSearchButton->Location = System::Drawing::Point(555, 546);
			this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
			this->AdvancedSearchButton->Size = System::Drawing::Size(154, 32);
			this->AdvancedSearchButton->TabIndex = 6;
			this->AdvancedSearchButton->Text = L"Ğàñøèğåííûé ïîèñê";
			this->AdvancedSearchButton->UseVisualStyleBackColor = true;
			this->AdvancedSearchButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::AdvancedSearchButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->SortButton);
			this->groupBox1->Controls->Add(this->ShowAllEntrysButton);
			this->groupBox1->Location = System::Drawing::Point(173, 560);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(206, 102);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Îòîáğàæåíèå âñåõ çàïèñåé";
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(6, 59);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(194, 37);
			this->SortButton->TabIndex = 9;
			this->SortButton->Text = L"Ñîğòèğîâàòü";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::SortButton_Click);
			// 
			// ShowAllEntrysButton
			// 
			this->ShowAllEntrysButton->Location = System::Drawing::Point(6, 21);
			this->ShowAllEntrysButton->Name = L"ShowAllEntrysButton";
			this->ShowAllEntrysButton->Size = System::Drawing::Size(194, 32);
			this->ShowAllEntrysButton->TabIndex = 8;
			this->ShowAllEntrysButton->Text = L"Îòîáğàçèòü";
			this->ShowAllEntrysButton->UseVisualStyleBackColor = true;
			this->ShowAllEntrysButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::ShowAllEntrysButton_Click);
			// 
			// toStartMenuBtn
			// 
			this->toStartMenuBtn->Location = System::Drawing::Point(567, 621);
			this->toStartMenuBtn->Name = L"toStartMenuBtn";
			this->toStartMenuBtn->Size = System::Drawing::Size(142, 41);
			this->toStartMenuBtn->TabIndex = 9;
			this->toStartMenuBtn->Text = L"Â ãëàâíîå ìåíş";
			this->toStartMenuBtn->UseVisualStyleBackColor = true;
			this->toStartMenuBtn->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::toStartMenuBtn_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(456, 621);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(105, 41);
			this->ExitButton->TabIndex = 10;
			this->ExitButton->Text = L"Âûõîä";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::ExitButton_Click);
			// 
			// EditEntryButton
			// 
			this->EditEntryButton->Location = System::Drawing::Point(15, 624);
			this->EditEntryButton->Name = L"EditEntryButton";
			this->EditEntryButton->Size = System::Drawing::Size(143, 34);
			this->EditEntryButton->TabIndex = 11;
			this->EditEntryButton->Text = L"Èçìåíèòü çàïèñü";
			this->EditEntryButton->UseVisualStyleBackColor = true;
			this->EditEntryButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::EditEntryButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ìåíşToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(721, 28);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->èñòîğèÿÇàêàçîâToolStripMenuItem,
					this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem, this->âûõîäÈçÀêêàóíòàToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// èñòîğèÿÇàêàçîâToolStripMenuItem
			// 
			this->èñòîğèÿÇàêàçîâToolStripMenuItem->Name = L"èñòîğèÿÇàêàçîâToolStripMenuItem";
			this->èñòîğèÿÇàêàçîâToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->èñòîğèÿÇàêàçîâToolStripMenuItem->Text = L"Èñòîğèÿ çàêàçîâ";
			this->èñòîğèÿÇàêàçîâToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::èñòîğèÿÇàêàçîâToolStripMenuItem_Click);
			// 
			// ñìåíèòüÊîäÄîñòóïàToolStripMenuItem
			// 
			this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem->Name = L"ñìåíèòüÊîäÄîñòóïàToolStripMenuItem";
			this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem->Text = L"Ñìåíèòü êîä äîñòóïà";
			this->ñìåíèòüÊîäÄîñòóïàToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::ñìåíèòüÊîäÄîñòóïàToolStripMenuItem_Click);
			// 
			// âûõîäÈçÀêêàóíòàToolStripMenuItem
			// 
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Name = L"âûõîäÈçÀêêàóíòàToolStripMenuItem";
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Size = System::Drawing::Size(238, 26);
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Text = L"Âûõîä èç àêêàóíòà";
			this->âûõîäÈçÀêêàóíòàToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::âûõîäÈçÀêêàóíòàToolStripMenuItem_Click);
			// 
			// EditAndViewDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 674);
			this->Controls->Add(this->EditEntryButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->toStartMenuBtn);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->AdvancedSearchButton);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->AddEntryButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(739, 721);
			this->MinimumSize = System::Drawing::Size(739, 721);
			this->Name = L"EditAndViewDBForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &EditAndViewDBForm::EditAndViewDBForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void EditAndViewDBForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void LoadData();
//public: System::Void LoadData(System::String^ str);
private: System::Void ReloadData();
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
//private: System::Void UpdateButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddEntryButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void FindButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e);
// Ğåäàêòèğóåì ÿ÷åéêó, åñëè îíà áûëà èçìåíåíà
//private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
private: System::Void EditEntryButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AdvancedSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
private: void mySubscriber(System::Object^ sender, System::EventArgs^ e, System::String^ str);
private: System::Void SortButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void èñòîğèÿÇàêàçîâToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void toStartMenuBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void âûõîäÈçÀêêàóíòàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ñìåíèòüÊîäÄîñòóïàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}

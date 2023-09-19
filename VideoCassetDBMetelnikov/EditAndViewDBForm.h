#pragma once
#include "MenuForStaffForm.h"
#include "AddEntrysForm.h"

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
	public:
		EditAndViewDBForm(void)
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
	private: System::Windows::Forms::Button^  EditEntryButton;

	private: System::Windows::Forms::Button^  DeleteButton;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  FindButton;
	private: System::Windows::Forms::Button^  AdvancedSearchButton;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  ShowAllEntrysButton;
	private: System::Windows::Forms::Button^  UpdateButton;

	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		SqlConnection^ sqlConn;
		SqlCommandBuilder^ sqlBuild;
		SqlDataAdapter^ sqlDA;
	private: System::Windows::Forms::Button^  SortButton;
	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::Button^  ExitButton;
	private: DataSet^ dataset;
			 String^ connString = "Data Source=LAPTOP-P056EURT;Initial Catalog=VideoCassetDB;Integrated Security=True";


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->AddEntryButton = (gcnew System::Windows::Forms::Button());
			this->EditEntryButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FindButton = (gcnew System::Windows::Forms::Button());
			this->AdvancedSearchButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllEntrysButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 31);
			this->dataGridView1->Name = L"dataGridView1";
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
			this->AddEntryButton->Text = L"Добавить запись";
			this->AddEntryButton->UseVisualStyleBackColor = true;
			this->AddEntryButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::AddEntryButton_Click);
			// 
			// EditEntryButton
			// 
			this->EditEntryButton->Location = System::Drawing::Point(15, 570);
			this->EditEntryButton->Name = L"EditEntryButton";
			this->EditEntryButton->Size = System::Drawing::Size(143, 32);
			this->EditEntryButton->TabIndex = 2;
			this->EditEntryButton->Text = L"Изменить запись";
			this->EditEntryButton->UseVisualStyleBackColor = true;
			this->EditEntryButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::EditEntryButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(15, 628);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(143, 34);
			this->DeleteButton->TabIndex = 3;
			this->DeleteButton->Text = L"Удалить запись";
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
			this->FindButton->Text = L"Поиск";
			this->FindButton->UseVisualStyleBackColor = true;
			this->FindButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::FindButton_Click);
			// 
			// AdvancedSearchButton
			// 
			this->AdvancedSearchButton->Location = System::Drawing::Point(555, 546);
			this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
			this->AdvancedSearchButton->Size = System::Drawing::Size(154, 32);
			this->AdvancedSearchButton->TabIndex = 6;
			this->AdvancedSearchButton->Text = L"Расширенный поиск";
			this->AdvancedSearchButton->UseVisualStyleBackColor = true;
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
			this->groupBox1->Text = L"Отображение всех записей";
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(6, 59);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(194, 37);
			this->SortButton->TabIndex = 9;
			this->SortButton->Text = L"Сортировать";
			this->SortButton->UseVisualStyleBackColor = true;
			// 
			// ShowAllEntrysButton
			// 
			this->ShowAllEntrysButton->Location = System::Drawing::Point(6, 21);
			this->ShowAllEntrysButton->Name = L"ShowAllEntrysButton";
			this->ShowAllEntrysButton->Size = System::Drawing::Size(194, 32);
			this->ShowAllEntrysButton->TabIndex = 8;
			this->ShowAllEntrysButton->Text = L"Отобразить";
			this->ShowAllEntrysButton->UseVisualStyleBackColor = true;
			this->ShowAllEntrysButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::ShowAllEntrysButton_Click);
			// 
			// UpdateButton
			// 
			this->UpdateButton->Location = System::Drawing::Point(385, 560);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(93, 32);
			this->UpdateButton->TabIndex = 8;
			this->UpdateButton->Text = L"Обновить";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::UpdateButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(604, 621);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(105, 41);
			this->BackButton->TabIndex = 9;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::BackButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(493, 621);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(105, 41);
			this->ExitButton->TabIndex = 10;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &EditAndViewDBForm::ExitButton_Click);
			// 
			// EditAndViewDBForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 674);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->AdvancedSearchButton);
			this->Controls->Add(this->FindButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->EditEntryButton);
			this->Controls->Add(this->AddEntryButton);
			this->Controls->Add(this->dataGridView1);
			this->MaximizeBox = false;
			this->Name = L"EditAndViewDBForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditAndViewDBForm";
			this->Load += gcnew System::EventHandler(this, &EditAndViewDBForm::EditAndViewDBForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void EditAndViewDBForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void LoadData();
private: System::Void ReloadData();
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void UpdateButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddEntryButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void FindButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void EditEntryButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}

#pragma once
#include "MenuForStaffForm.h"
#include "HystorySortMethodForm.h"
#include "HystoryAdvanedSearchForm.h"
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

	private: System::Windows::Forms::Button^  BackButton;




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
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->AdvancedSearchButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->ShowAllEntrysButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 16);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(829, 523);
			this->dataGridView1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(728, 551);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(117, 42);
			this->BackButton->TabIndex = 8;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::BackButton_Click);
			// 
			// AdvancedSearchButton
			// 
			this->AdvancedSearchButton->Location = System::Drawing::Point(216, 554);
			this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
			this->AdvancedSearchButton->Size = System::Drawing::Size(194, 39);
			this->AdvancedSearchButton->TabIndex = 10;
			this->AdvancedSearchButton->Text = L"Расширенный поиск";
			this->AdvancedSearchButton->UseVisualStyleBackColor = true;
			this->AdvancedSearchButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::AdvancedSearchButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(602, 552);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(117, 42);
			this->ExitButton->TabIndex = 11;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ExitButton_Click);
			// 
			// ShowAllEntrysButton
			// 
			this->ShowAllEntrysButton->Location = System::Drawing::Point(16, 554);
			this->ShowAllEntrysButton->Name = L"ShowAllEntrysButton";
			this->ShowAllEntrysButton->Size = System::Drawing::Size(194, 39);
			this->ShowAllEntrysButton->TabIndex = 12;
			this->ShowAllEntrysButton->Text = L"Отобразить";
			this->ShowAllEntrysButton->UseVisualStyleBackColor = true;
			this->ShowAllEntrysButton->Click += gcnew System::EventHandler(this, &HystoryOfBuyForm::ShowAllEntrysButton_Click);
			// 
			// HystoryOfBuyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 671);
			this->Controls->Add(this->ShowAllEntrysButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->AdvancedSearchButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->dataGridView1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(878, 718);
			this->MinimumSize = System::Drawing::Size(878, 718);
			this->Name = L"HystoryOfBuyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HystoryOfBuyForm";
			this->Load += gcnew System::EventHandler(this, &HystoryOfBuyForm::HystoryOfBuyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void HystoryOfBuyForm_Load(System::Object^  sender, System::EventArgs^  e);
private: void LoadData();
private: void mySubscriber(System::Object^ sender, System::EventArgs^ e, System::String^ str);
private: System::Void AdvancedSearchButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ShowAllEntrysButton_Click(System::Object^  sender, System::EventArgs^  e);

};
}

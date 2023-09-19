#pragma once


namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AddEntrysForm
	/// </summary>
	public ref class AddEntrysForm : public System::Windows::Forms::Form
	{
	public:
		AddEntrysForm(void)
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
		~AddEntrysForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::TextBox^  NameTextBox;
	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  YearOfReleaseTextBox;






	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  DirectorTextBox;
	private: System::Windows::Forms::TextBox^  AvailTextBox;
	private: System::Windows::Forms::TextBox^  PriceTextBox;




	private: System::Windows::Forms::Button^  AddButton;
	private: System::Windows::Forms::ComboBox^  GenreComboBox;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: SqlConnection^ sqlConn;
	private: SqlCommandBuilder^ sqlBuild;
	private: SqlDataAdapter^ sqlDA;
	private: DataSet^ dataset;
	private: String^ connString = "Data Source=LAPTOP-P056EURT;Initial Catalog=VideoCassetDB;Integrated Security=True";

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->YearOfReleaseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->DirectorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AvailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PriceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->GenreComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название фильма";
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(178, 215);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(93, 33);
			this->BackButton->TabIndex = 1;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &AddEntrysForm::BackButton_Click);
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(16, 95);
			this->NameTextBox->Multiline = true;
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(353, 22);
			this->NameTextBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Добавление записи";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Жанр";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(267, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Год премьеры";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(125, 119);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Режиссёр";
			// 
			// YearOfReleaseTextBox
			// 
			this->YearOfReleaseTextBox->Location = System::Drawing::Point(270, 139);
			this->YearOfReleaseTextBox->Multiline = true;
			this->YearOfReleaseTextBox->Name = L"YearOfReleaseTextBox";
			this->YearOfReleaseTextBox->Size = System::Drawing::Size(99, 22);
			this->YearOfReleaseTextBox->TabIndex = 13;
			this->YearOfReleaseTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddEntrysForm::YearOfReleaseTextBox_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 167);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Наличие на складе";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(160, 167);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 17);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Цена";
			// 
			// DirectorTextBox
			// 
			this->DirectorTextBox->Location = System::Drawing::Point(128, 139);
			this->DirectorTextBox->Multiline = true;
			this->DirectorTextBox->Name = L"DirectorTextBox";
			this->DirectorTextBox->Size = System::Drawing::Size(130, 22);
			this->DirectorTextBox->TabIndex = 16;
			this->DirectorTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddEntrysForm::DirectorTextBox_KeyPress);
			// 
			// AvailTextBox
			// 
			this->AvailTextBox->Location = System::Drawing::Point(16, 187);
			this->AvailTextBox->Multiline = true;
			this->AvailTextBox->Name = L"AvailTextBox";
			this->AvailTextBox->Size = System::Drawing::Size(141, 22);
			this->AvailTextBox->TabIndex = 17;
			this->AvailTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddEntrysForm::YearOfReleaseTextBox_KeyPress);
			// 
			// PriceTextBox
			// 
			this->PriceTextBox->Location = System::Drawing::Point(163, 187);
			this->PriceTextBox->Multiline = true;
			this->PriceTextBox->Name = L"PriceTextBox";
			this->PriceTextBox->Size = System::Drawing::Size(95, 22);
			this->PriceTextBox->TabIndex = 18;
			this->PriceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddEntrysForm::YearOfReleaseTextBox_KeyPress);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(277, 215);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(92, 33);
			this->AddButton->TabIndex = 19;
			this->AddButton->Text = L"Добавить";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &AddEntrysForm::AddButton_Click);
			// 
			// GenreComboBox
			// 
			this->GenreComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GenreComboBox->FormattingEnabled = true;
			this->GenreComboBox->Location = System::Drawing::Point(17, 137);
			this->GenreComboBox->Name = L"GenreComboBox";
			this->GenreComboBox->Size = System::Drawing::Size(106, 24);
			this->GenreComboBox->TabIndex = 20;
			// 
			// AddEntrysForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 260);
			this->Controls->Add(this->GenreComboBox);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->PriceTextBox);
			this->Controls->Add(this->AvailTextBox);
			this->Controls->Add(this->DirectorTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->YearOfReleaseTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(403, 307);
			this->MinimumSize = System::Drawing::Size(403, 307);
			this->Name = L"AddEntrysForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddEntrysForm";
			this->Load += gcnew System::EventHandler(this, &AddEntrysForm::AddEntrysForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddEntrysForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void LoadCombo(); // Функция заполнения comboBox значениями таблицы Genre
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void KeyNotWordPress(System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void YearOfReleaseTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void DirectorTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
};
}

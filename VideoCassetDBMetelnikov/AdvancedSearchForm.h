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
	/// Summary for AdvancedSearchForm
	/// </summary>
	public ref class AdvancedSearchForm : public System::Windows::Forms::Form
	{
	public:
		AdvancedSearchForm(void)
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
		~AdvancedSearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label9;
	protected:
	private: System::Windows::Forms::Button^  backButton;
	private: System::Windows::Forms::Button^  findButton;
	private: System::Windows::Forms::TextBox^  PriceEndTextBox;

	private: System::Windows::Forms::TextBox^  PriceBeginTextBox;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  AvailEndTextBox;

	private: System::Windows::Forms::TextBox^  AvailBeginTextBox;

	private: System::Windows::Forms::ComboBox^  GenreComboBox;
	private: System::Windows::Forms::TextBox^  YearOfReleaseTextBox;
	private: System::Windows::Forms::TextBox^  DirFilmTextBox;



	private: System::Windows::Forms::TextBox^  NameTextBox;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		SqlConnection^ sqlConn;
		String^ connString = "Data Source=LAPTOP-P056EURT;Initial Catalog=VideoCassetDB;Integrated Security=True";

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->findButton = (gcnew System::Windows::Forms::Button());
			this->PriceEndTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PriceBeginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->AvailEndTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AvailBeginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GenreComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->YearOfReleaseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DirFilmTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->label9->Location = System::Drawing::Point(39, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(272, 31);
			this->label9->TabIndex = 40;
			this->label9->Text = L"Расширенный поиск";
			// 
			// backButton
			// 
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->backButton->Location = System::Drawing::Point(153, 261);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(88, 34);
			this->backButton->TabIndex = 39;
			this->backButton->Text = L"Назад";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &AdvancedSearchForm::backButton_Click);
			// 
			// findButton
			// 
			this->findButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->findButton->Location = System::Drawing::Point(247, 261);
			this->findButton->Name = L"findButton";
			this->findButton->Size = System::Drawing::Size(83, 34);
			this->findButton->TabIndex = 38;
			this->findButton->Text = L"Поиск";
			this->findButton->UseVisualStyleBackColor = true;
			// 
			// PriceEndTextBox
			// 
			this->PriceEndTextBox->Location = System::Drawing::Point(175, 203);
			this->PriceEndTextBox->Name = L"PriceEndTextBox";
			this->PriceEndTextBox->Size = System::Drawing::Size(41, 22);
			this->PriceEndTextBox->TabIndex = 37;
			this->PriceEndTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::YearOfReleaseTextBox_KeyPress);
			// 
			// PriceBeginTextBox
			// 
			this->PriceBeginTextBox->Location = System::Drawing::Point(91, 201);
			this->PriceBeginTextBox->Name = L"PriceBeginTextBox";
			this->PriceBeginTextBox->Size = System::Drawing::Size(41, 22);
			this->PriceBeginTextBox->TabIndex = 36;
			this->PriceBeginTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::YearOfReleaseTextBox_KeyPress);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label8->Location = System::Drawing::Point(138, 203);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 20);
			this->label8->TabIndex = 35;
			this->label8->Text = L"до";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->checkBox1->Location = System::Drawing::Point(16, 238);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(118, 24);
			this->checkBox1->TabIndex = 34;
			this->checkBox1->Text = L"В наличии";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label7->Location = System::Drawing::Point(12, 203);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 20);
			this->label7->TabIndex = 33;
			this->label7->Text = L"Цена от";
			// 
			// AvailEndTextBox
			// 
			this->AvailEndTextBox->Location = System::Drawing::Point(289, 167);
			this->AvailEndTextBox->Name = L"AvailEndTextBox";
			this->AvailEndTextBox->Size = System::Drawing::Size(41, 22);
			this->AvailEndTextBox->TabIndex = 32;
			this->AvailEndTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::YearOfReleaseTextBox_KeyPress);
			// 
			// AvailBeginTextBox
			// 
			this->AvailBeginTextBox->Location = System::Drawing::Point(216, 167);
			this->AvailBeginTextBox->Name = L"AvailBeginTextBox";
			this->AvailBeginTextBox->Size = System::Drawing::Size(35, 22);
			this->AvailBeginTextBox->TabIndex = 31;
			this->AvailBeginTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::YearOfReleaseTextBox_KeyPress);
			// 
			// GenreComboBox
			// 
			this->GenreComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GenreComboBox->FormattingEnabled = true;
			this->GenreComboBox->Location = System::Drawing::Point(159, 81);
			this->GenreComboBox->Name = L"GenreComboBox";
			this->GenreComboBox->Size = System::Drawing::Size(171, 24);
			this->GenreComboBox->TabIndex = 30;
			// 
			// YearOfReleaseTextBox
			// 
			this->YearOfReleaseTextBox->Location = System::Drawing::Point(159, 111);
			this->YearOfReleaseTextBox->Name = L"YearOfReleaseTextBox";
			this->YearOfReleaseTextBox->Size = System::Drawing::Size(171, 22);
			this->YearOfReleaseTextBox->TabIndex = 29;
			this->YearOfReleaseTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::YearOfReleaseTextBox_KeyPress);
			// 
			// DirFilmTextBox
			// 
			this->DirFilmTextBox->Location = System::Drawing::Point(159, 139);
			this->DirFilmTextBox->Name = L"DirFilmTextBox";
			this->DirFilmTextBox->Size = System::Drawing::Size(171, 22);
			this->DirFilmTextBox->TabIndex = 28;
			this->DirFilmTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::NameTextBox_KeyPress);
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point(159, 53);
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(171, 22);
			this->NameTextBox->TabIndex = 27;
			this->NameTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvancedSearchForm::NameTextBox_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label6->Location = System::Drawing::Point(12, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 20);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Дата премьеры";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label5->Location = System::Drawing::Point(12, 141);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 20);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Режиссёр";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label4->Location = System::Drawing::Point(11, 167);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(199, 20);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Количество в наличии";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label3->Location = System::Drawing::Point(257, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 20);
			this->label3->TabIndex = 23;
			this->label3->Text = L"до";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label2->Location = System::Drawing::Point(12, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 20);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Жанр";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label1->Location = System::Drawing::Point(12, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 20);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Название";
			// 
			// AdvancedSearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 304);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->findButton);
			this->Controls->Add(this->PriceEndTextBox);
			this->Controls->Add(this->PriceBeginTextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->AvailEndTextBox);
			this->Controls->Add(this->AvailBeginTextBox);
			this->Controls->Add(this->GenreComboBox);
			this->Controls->Add(this->YearOfReleaseTextBox);
			this->Controls->Add(this->DirFilmTextBox);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(356, 351);
			this->MinimumSize = System::Drawing::Size(356, 351);
			this->Name = L"AdvancedSearchForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &AdvancedSearchForm::AdvancedSearchForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AdvancedSearchForm_Load(System::Object^  sender, System::EventArgs^  e);

private: System::Void NameTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void YearOfReleaseTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
};
}

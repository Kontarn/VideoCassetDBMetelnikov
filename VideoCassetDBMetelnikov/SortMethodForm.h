#pragma once

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SortMethodForm
	/// </summary>
	public ref class SortMethodForm : public System::Windows::Forms::Form
	{
	public: delegate void EventDelegate1(System::Object^ sender,
		System::EventArgs^ e, System::String^ str);
	public: event EventDelegate1^ myEvent1;
	public:
		SortMethodForm(void)
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
		~SortMethodForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  SortButton;

	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::DomainUpDown^  NameDomainUpDown;
	private: System::Windows::Forms::DomainUpDown^  GenreDomainUpDown;
	private: System::Windows::Forms::DomainUpDown^  YearOfRelDomainUpDown;
	private: System::Windows::Forms::DomainUpDown^  DirFilmDomainUpDown;
	private: System::Windows::Forms::DomainUpDown^  AvailDomainUpDown;
	private: System::Windows::Forms::DomainUpDown^  PriceDomainUpDown;

	private: System::Windows::Forms::Button^  AddNameButton;
	private: System::Windows::Forms::Button^  AddGenreButton;
	private: System::Windows::Forms::Button^  AddYearOfRelButton;
	private: System::Windows::Forms::Button^  AddDirFilmButton;
	private: System::Windows::Forms::Button^  AddAvailButton;
	private: System::Windows::Forms::Button^  AddPriceButton;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  ClearSortButton;

	private: System::Windows::Forms::Label^  label8;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		int size = 7;	// The Size corresponds to the number of columns in the Film table
		int i = 0;		// Index for counting the number of selected columns
		bool flagName, flagGenre; 
	private: System::Windows::Forms::TextBox^  textBox1;
			 array<String^>^ sortMass = gcnew array<String^>(size);
			 // Хранит номер текстбокса и если ячейка заполнена, то добавление не срабатывает
			 array<String^>^ indexTextB = gcnew array<String^>(size);
			 String^ buffer;
			 String^ buffer1;
			 String^ sqlStr;
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->NameDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->GenreDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->YearOfRelDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->DirFilmDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->AvailDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->PriceDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->AddNameButton = (gcnew System::Windows::Forms::Button());
			this->AddGenreButton = (gcnew System::Windows::Forms::Button());
			this->AddYearOfRelButton = (gcnew System::Windows::Forms::Button());
			this->AddDirFilmButton = (gcnew System::Windows::Forms::Button());
			this->AddAvailButton = (gcnew System::Windows::Forms::Button());
			this->AddPriceButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ClearSortButton = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"По названию";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"По жанру";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"По дате премьеры";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"По режиссёру";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 254);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"По наличию";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 301);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"По цене";
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(188, 397);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(116, 31);
			this->SortButton->TabIndex = 13;
			this->SortButton->Text = L"Отобразить";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &SortMethodForm::SortButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(115, 397);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(67, 31);
			this->BackButton->TabIndex = 14;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &SortMethodForm::BackButton_Click);
			// 
			// NameDomainUpDown
			// 
			this->NameDomainUpDown->Items->Add(L"По возрастанию");
			this->NameDomainUpDown->Items->Add(L"По убыванию");
			this->NameDomainUpDown->Location = System::Drawing::Point(24, 90);
			this->NameDomainUpDown->Name = L"NameDomainUpDown";
			this->NameDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->NameDomainUpDown->TabIndex = 15;
			this->NameDomainUpDown->Wrap = true;
			// 
			// GenreDomainUpDown
			// 
			this->GenreDomainUpDown->Items->Add(L"По возрастанию");
			this->GenreDomainUpDown->Items->Add(L"По убыванию");
			this->GenreDomainUpDown->Location = System::Drawing::Point(24, 137);
			this->GenreDomainUpDown->Name = L"GenreDomainUpDown";
			this->GenreDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->GenreDomainUpDown->TabIndex = 16;
			this->GenreDomainUpDown->Wrap = true;
			// 
			// YearOfRelDomainUpDown
			// 
			this->YearOfRelDomainUpDown->Items->Add(L"По возрастанию");
			this->YearOfRelDomainUpDown->Items->Add(L"По убыванию");
			this->YearOfRelDomainUpDown->Location = System::Drawing::Point(24, 183);
			this->YearOfRelDomainUpDown->Name = L"YearOfRelDomainUpDown";
			this->YearOfRelDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->YearOfRelDomainUpDown->TabIndex = 17;
			this->YearOfRelDomainUpDown->Wrap = true;
			// 
			// DirFilmDomainUpDown
			// 
			this->DirFilmDomainUpDown->Items->Add(L"По возрастанию");
			this->DirFilmDomainUpDown->Items->Add(L"По убыванию");
			this->DirFilmDomainUpDown->Location = System::Drawing::Point(24, 229);
			this->DirFilmDomainUpDown->Name = L"DirFilmDomainUpDown";
			this->DirFilmDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->DirFilmDomainUpDown->TabIndex = 18;
			this->DirFilmDomainUpDown->Wrap = true;
			// 
			// AvailDomainUpDown
			// 
			this->AvailDomainUpDown->Items->Add(L"По возрастанию");
			this->AvailDomainUpDown->Items->Add(L"По убыванию");
			this->AvailDomainUpDown->Location = System::Drawing::Point(24, 276);
			this->AvailDomainUpDown->Name = L"AvailDomainUpDown";
			this->AvailDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->AvailDomainUpDown->TabIndex = 19;
			this->AvailDomainUpDown->Wrap = true;
			// 
			// PriceDomainUpDown
			// 
			this->PriceDomainUpDown->Items->Add(L"По возрастанию");
			this->PriceDomainUpDown->Items->Add(L"По убыванию");
			this->PriceDomainUpDown->Location = System::Drawing::Point(24, 321);
			this->PriceDomainUpDown->Name = L"PriceDomainUpDown";
			this->PriceDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->PriceDomainUpDown->TabIndex = 20;
			this->PriceDomainUpDown->Wrap = true;
			// 
			// AddNameButton
			// 
			this->AddNameButton->Location = System::Drawing::Point(219, 84);
			this->AddNameButton->Name = L"AddNameButton";
			this->AddNameButton->Size = System::Drawing::Size(85, 32);
			this->AddNameButton->TabIndex = 22;
			this->AddNameButton->Text = L"Добавить";
			this->AddNameButton->UseVisualStyleBackColor = true;
			this->AddNameButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddNameButton_Click);
			// 
			// AddGenreButton
			// 
			this->AddGenreButton->Location = System::Drawing::Point(219, 133);
			this->AddGenreButton->Name = L"AddGenreButton";
			this->AddGenreButton->Size = System::Drawing::Size(85, 29);
			this->AddGenreButton->TabIndex = 23;
			this->AddGenreButton->Text = L"Добавить";
			this->AddGenreButton->UseVisualStyleBackColor = true;
			this->AddGenreButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddGenreButton_Click);
			// 
			// AddYearOfRelButton
			// 
			this->AddYearOfRelButton->Location = System::Drawing::Point(219, 178);
			this->AddYearOfRelButton->Name = L"AddYearOfRelButton";
			this->AddYearOfRelButton->Size = System::Drawing::Size(85, 30);
			this->AddYearOfRelButton->TabIndex = 24;
			this->AddYearOfRelButton->Text = L"Добавить";
			this->AddYearOfRelButton->UseVisualStyleBackColor = true;
			this->AddYearOfRelButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddYearOfRelButton_Click);
			// 
			// AddDirFilmButton
			// 
			this->AddDirFilmButton->Location = System::Drawing::Point(219, 224);
			this->AddDirFilmButton->Name = L"AddDirFilmButton";
			this->AddDirFilmButton->Size = System::Drawing::Size(85, 30);
			this->AddDirFilmButton->TabIndex = 25;
			this->AddDirFilmButton->Text = L"Добавить";
			this->AddDirFilmButton->UseVisualStyleBackColor = true;
			this->AddDirFilmButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddDirFilmButton_Click);
			// 
			// AddAvailButton
			// 
			this->AddAvailButton->Location = System::Drawing::Point(219, 271);
			this->AddAvailButton->Name = L"AddAvailButton";
			this->AddAvailButton->Size = System::Drawing::Size(85, 30);
			this->AddAvailButton->TabIndex = 26;
			this->AddAvailButton->Text = L"Добавить";
			this->AddAvailButton->UseVisualStyleBackColor = true;
			this->AddAvailButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddAvailButton_Click);
			// 
			// AddPriceButton
			// 
			this->AddPriceButton->Location = System::Drawing::Point(219, 316);
			this->AddPriceButton->Name = L"AddPriceButton";
			this->AddPriceButton->Size = System::Drawing::Size(85, 30);
			this->AddPriceButton->TabIndex = 27;
			this->AddPriceButton->Text = L"Добавить";
			this->AddPriceButton->UseVisualStyleBackColor = true;
			this->AddPriceButton->Click += gcnew System::EventHandler(this, &SortMethodForm::AddPriceButton_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 355);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 28;
			// 
			// ClearSortButton
			// 
			this->ClearSortButton->Location = System::Drawing::Point(85, 360);
			this->ClearSortButton->Name = L"ClearSortButton";
			this->ClearSortButton->Size = System::Drawing::Size(219, 31);
			this->ClearSortButton->TabIndex = 29;
			this->ClearSortButton->Text = L"Очистить список сортировки";
			this->ClearSortButton->UseVisualStyleBackColor = true;
			this->ClearSortButton->Click += gcnew System::EventHandler(this, &SortMethodForm::ClearSortButton_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 11);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(231, 17);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Последовательность сортировки:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 22);
			this->textBox1->TabIndex = 31;
			// 
			// SortMethodForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 433);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ClearSortButton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->AddPriceButton);
			this->Controls->Add(this->AddAvailButton);
			this->Controls->Add(this->AddDirFilmButton);
			this->Controls->Add(this->AddYearOfRelButton);
			this->Controls->Add(this->AddGenreButton);
			this->Controls->Add(this->AddNameButton);
			this->Controls->Add(this->PriceDomainUpDown);
			this->Controls->Add(this->AvailDomainUpDown);
			this->Controls->Add(this->DirFilmDomainUpDown);
			this->Controls->Add(this->YearOfRelDomainUpDown);
			this->Controls->Add(this->GenreDomainUpDown);
			this->Controls->Add(this->NameDomainUpDown);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->SortButton);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"SortMethodForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: void AddToMassSort(int j, System::Windows::Forms::DomainUpDown^ domainText, System::String^ nameCol, System::String^ psevdCol);
private: System::Void AddNameButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddGenreButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddYearOfRelButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddDirFilmButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddAvailButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddPriceButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ClearSortButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void SortButton_Click(System::Object^  sender, System::EventArgs^  e);
public:  void issueEvent1(System::Object^ sender, System::EventArgs^ e);
};
}

#pragma once


namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HystorySortMethodForm
	/// </summary>
	public ref class HystorySortMethodForm : public System::Windows::Forms::Form
	{
	public: delegate void EventDelegate1(System::Object^ sender,
		System::EventArgs^ e, System::String^ str);
	public: event EventDelegate1^ myEvent1;
	private:
		int i = 0; // индексирует добавляемые значения для сортировки в sortMass
		int size = 5;
		String^ sqlStr;
		// Stores data for forming an sql query
		array<String^>^ sortMass = gcnew array<String^>(size);
		// Хранит номер текстбокса и если ячейка заполнена, то добавление не срабатывает
		array<String^>^ indexTextB = gcnew array<String^>(size);
	public:
		HystorySortMethodForm(void)
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
		~HystorySortMethodForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  ClearSortButton;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  AddReturnDateButton;



	private: System::Windows::Forms::Button^  AddTransactDateButton;

	private: System::Windows::Forms::Button^  AddClientFIOButton;

	private: System::Windows::Forms::Button^  AddClientIDButton;

	private: System::Windows::Forms::DomainUpDown^  ReturnDateDomainUpDown;



	private: System::Windows::Forms::DomainUpDown^  TransactDateDomainUpDown;


	private: System::Windows::Forms::DomainUpDown^  ClientFIODomainUpDown;

	private: System::Windows::Forms::DomainUpDown^  ClientIDDomainUpDown;

	private: System::Windows::Forms::Button^  BackButton;
	private: System::Windows::Forms::Button^  SortButton;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ClearSortButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->AddReturnDateButton = (gcnew System::Windows::Forms::Button());
			this->AddTransactDateButton = (gcnew System::Windows::Forms::Button());
			this->AddClientFIOButton = (gcnew System::Windows::Forms::Button());
			this->AddClientIDButton = (gcnew System::Windows::Forms::Button());
			this->ReturnDateDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->TransactDateDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->ClientFIODomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->ClientIDDomainUpDown = (gcnew System::Windows::Forms::DomainUpDown());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 22);
			this->textBox1->TabIndex = 55;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(231, 17);
			this->label8->TabIndex = 54;
			this->label8->Text = L"Последовательность сортировки:";
			// 
			// ClearSortButton
			// 
			this->ClearSortButton->Location = System::Drawing::Point(73, 260);
			this->ClearSortButton->Name = L"ClearSortButton";
			this->ClearSortButton->Size = System::Drawing::Size(219, 31);
			this->ClearSortButton->TabIndex = 53;
			this->ClearSortButton->Text = L"Очистить список сортировки";
			this->ClearSortButton->UseVisualStyleBackColor = true;
			this->ClearSortButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::ClearSortButton_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 352);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 52;
			// 
			// AddReturnDateButton
			// 
			this->AddReturnDateButton->Location = System::Drawing::Point(207, 221);
			this->AddReturnDateButton->Name = L"AddReturnDateButton";
			this->AddReturnDateButton->Size = System::Drawing::Size(85, 30);
			this->AddReturnDateButton->TabIndex = 49;
			this->AddReturnDateButton->Text = L"Добавить";
			this->AddReturnDateButton->UseVisualStyleBackColor = true;
			this->AddReturnDateButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::AddReturnDateButton_Click);
			// 
			// AddTransactDateButton
			// 
			this->AddTransactDateButton->Location = System::Drawing::Point(207, 175);
			this->AddTransactDateButton->Name = L"AddTransactDateButton";
			this->AddTransactDateButton->Size = System::Drawing::Size(85, 30);
			this->AddTransactDateButton->TabIndex = 48;
			this->AddTransactDateButton->Text = L"Добавить";
			this->AddTransactDateButton->UseVisualStyleBackColor = true;
			this->AddTransactDateButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::AddTransactDateButton_Click);
			// 
			// AddClientFIOButton
			// 
			this->AddClientFIOButton->Location = System::Drawing::Point(207, 130);
			this->AddClientFIOButton->Name = L"AddClientFIOButton";
			this->AddClientFIOButton->Size = System::Drawing::Size(85, 29);
			this->AddClientFIOButton->TabIndex = 47;
			this->AddClientFIOButton->Text = L"Добавить";
			this->AddClientFIOButton->UseVisualStyleBackColor = true;
			this->AddClientFIOButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::AddClientFIOButton_Click);
			// 
			// AddClientIDButton
			// 
			this->AddClientIDButton->Location = System::Drawing::Point(207, 81);
			this->AddClientIDButton->Name = L"AddClientIDButton";
			this->AddClientIDButton->Size = System::Drawing::Size(85, 32);
			this->AddClientIDButton->TabIndex = 46;
			this->AddClientIDButton->Text = L"Добавить";
			this->AddClientIDButton->UseVisualStyleBackColor = true;
			this->AddClientIDButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::AddClientIDButton_Click);
			// 
			// ReturnDateDomainUpDown
			// 
			this->ReturnDateDomainUpDown->Items->Add(L"По возрастанию");
			this->ReturnDateDomainUpDown->Items->Add(L"По убыванию");
			this->ReturnDateDomainUpDown->Location = System::Drawing::Point(12, 226);
			this->ReturnDateDomainUpDown->Name = L"ReturnDateDomainUpDown";
			this->ReturnDateDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->ReturnDateDomainUpDown->TabIndex = 43;
			this->ReturnDateDomainUpDown->Wrap = true;
			// 
			// TransactDateDomainUpDown
			// 
			this->TransactDateDomainUpDown->Items->Add(L"По возрастанию");
			this->TransactDateDomainUpDown->Items->Add(L"По убыванию");
			this->TransactDateDomainUpDown->Location = System::Drawing::Point(12, 180);
			this->TransactDateDomainUpDown->Name = L"TransactDateDomainUpDown";
			this->TransactDateDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->TransactDateDomainUpDown->TabIndex = 42;
			this->TransactDateDomainUpDown->Wrap = true;
			// 
			// ClientFIODomainUpDown
			// 
			this->ClientFIODomainUpDown->Items->Add(L"По возрастанию");
			this->ClientFIODomainUpDown->Items->Add(L"По убыванию");
			this->ClientFIODomainUpDown->Location = System::Drawing::Point(12, 134);
			this->ClientFIODomainUpDown->Name = L"ClientFIODomainUpDown";
			this->ClientFIODomainUpDown->Size = System::Drawing::Size(189, 22);
			this->ClientFIODomainUpDown->TabIndex = 41;
			this->ClientFIODomainUpDown->Wrap = true;
			// 
			// ClientIDDomainUpDown
			// 
			this->ClientIDDomainUpDown->Items->Add(L"По возрастанию");
			this->ClientIDDomainUpDown->Items->Add(L"По убыванию");
			this->ClientIDDomainUpDown->Location = System::Drawing::Point(12, 87);
			this->ClientIDDomainUpDown->Name = L"ClientIDDomainUpDown";
			this->ClientIDDomainUpDown->Size = System::Drawing::Size(189, 22);
			this->ClientIDDomainUpDown->TabIndex = 40;
			this->ClientIDDomainUpDown->Wrap = true;
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(103, 297);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(67, 31);
			this->BackButton->TabIndex = 39;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::BackButton_Click);
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(176, 297);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(116, 31);
			this->SortButton->TabIndex = 38;
			this->SortButton->Text = L"Отобразить";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &HystorySortMethodForm::SortButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 17);
			this->label4->TabIndex = 35;
			this->label4->Text = L"По дате возврта";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 160);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 17);
			this->label3->TabIndex = 34;
			this->label3->Text = L"По дате заказа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 17);
			this->label2->TabIndex = 33;
			this->label2->Text = L"По ФИО";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 17);
			this->label1->TabIndex = 32;
			this->label1->Text = L"По коду клиента";
			// 
			// HystorySortMethodForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(303, 337);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ClearSortButton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->AddReturnDateButton);
			this->Controls->Add(this->AddTransactDateButton);
			this->Controls->Add(this->AddClientFIOButton);
			this->Controls->Add(this->AddClientIDButton);
			this->Controls->Add(this->ReturnDateDomainUpDown);
			this->Controls->Add(this->TransactDateDomainUpDown);
			this->Controls->Add(this->ClientFIODomainUpDown);
			this->Controls->Add(this->ClientIDDomainUpDown);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->SortButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(321, 384);
			this->MinimumSize = System::Drawing::Size(321, 384);
			this->Name = L"HystorySortMethodForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HystorySortMethodForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ClearSortButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddClientIDButton_Click(System::Object^  sender, System::EventArgs^  e);
private: void AddToMassSort(int j, System::Windows::Forms::DomainUpDown^ domainText, System::String^ nameCol, System::String^ psevdCol);
private: System::Void AddClientFIOButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddTransactDateButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddReturnDateButton_Click(System::Object^  sender, System::EventArgs^  e);
public:  void issueEvent1(System::Object^ sender, System::EventArgs^ e);
private: System::Void SortButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}

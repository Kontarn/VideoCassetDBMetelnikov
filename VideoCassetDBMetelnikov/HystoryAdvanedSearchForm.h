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
	/// Summary for HystoryAdvanedSearchForm
	/// </summary>
	public ref class HystoryAdvanedSearchForm : public System::Windows::Forms::Form
	{
	private:
		String^ connString = "Data Source =DESKTOP-LSHR1L6; Initial Catalog = VideoCassetDB; Integrated Security = True";
		SqlConnection^ sqlConn;
		String^ SqlQuery;
	public: delegate void EventDelegate1(System::Object^ sender,
		System::EventArgs^ e, System::String^ str);
	public: event EventDelegate1^ myEvent1;
	public:
		HystoryAdvanedSearchForm(void)
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
		~HystoryAdvanedSearchForm()
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
	private: System::Windows::Forms::ComboBox^  FIOClientComboBox;











	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  TransactDateTimePicker;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DateTimePicker^  ReturnDateTimePicker;

	private: System::Windows::Forms::ComboBox^  FilmIdComboBox;


	private: System::Windows::Forms::ComboBox^  FilmNameComboBox;


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
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->findButton = (gcnew System::Windows::Forms::Button());
			this->FIOClientComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TransactDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ReturnDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->FilmIdComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FilmNameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->label9->Location = System::Drawing::Point(33, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(272, 31);
			this->label9->TabIndex = 60;
			this->label9->Text = L"Расширенный поиск";
			// 
			// backButton
			// 
			this->backButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->backButton->Location = System::Drawing::Point(161, 222);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(88, 34);
			this->backButton->TabIndex = 59;
			this->backButton->Text = L"Назад";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &HystoryAdvanedSearchForm::backButton_Click);
			// 
			// findButton
			// 
			this->findButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->findButton->Location = System::Drawing::Point(255, 222);
			this->findButton->Name = L"findButton";
			this->findButton->Size = System::Drawing::Size(83, 34);
			this->findButton->TabIndex = 58;
			this->findButton->Text = L"Поиск";
			this->findButton->UseVisualStyleBackColor = true;
			this->findButton->Click += gcnew System::EventHandler(this, &HystoryAdvanedSearchForm::findButton_Click);
			// 
			// FIOClientComboBox
			// 
			this->FIOClientComboBox->FormattingEnabled = true;
			this->FIOClientComboBox->Location = System::Drawing::Point(167, 56);
			this->FIOClientComboBox->Name = L"FIOClientComboBox";
			this->FIOClientComboBox->Size = System::Drawing::Size(171, 24);
			this->FIOClientComboBox->TabIndex = 50;
			this->FIOClientComboBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &HystoryAdvanedSearchForm::FIOClientComboBox_KeyPress);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label6->Location = System::Drawing::Point(4, 84);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 20);
			this->label6->TabIndex = 46;
			this->label6->Text = L"Код фильма";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label5->Location = System::Drawing::Point(4, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 20);
			this->label5->TabIndex = 45;
			this->label5->Text = L"Название фильма";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label2->Location = System::Drawing::Point(4, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 20);
			this->label2->TabIndex = 42;
			this->label2->Text = L"ФИО клиента";
			// 
			// TransactDateTimePicker
			// 
			this->TransactDateTimePicker->CustomFormat = L"";
			this->TransactDateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->TransactDateTimePicker->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->TransactDateTimePicker->Location = System::Drawing::Point(167, 152);
			this->TransactDateTimePicker->MinDate = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			this->TransactDateTimePicker->Name = L"TransactDateTimePicker";
			this->TransactDateTimePicker->Size = System::Drawing::Size(171, 22);
			this->TransactDateTimePicker->TabIndex = 61;
			this->TransactDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label3->Location = System::Drawing::Point(4, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 20);
			this->label3->TabIndex = 62;
			this->label3->Text = L"Дата заказа";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.8F));
			this->label4->Location = System::Drawing::Point(4, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 20);
			this->label4->TabIndex = 64;
			this->label4->Text = L"Дата возврата";
			// 
			// ReturnDateTimePicker
			// 
			this->ReturnDateTimePicker->CustomFormat = L"";
			this->ReturnDateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->ReturnDateTimePicker->Location = System::Drawing::Point(167, 180);
			this->ReturnDateTimePicker->MinDate = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			this->ReturnDateTimePicker->Name = L"ReturnDateTimePicker";
			this->ReturnDateTimePicker->Size = System::Drawing::Size(171, 22);
			this->ReturnDateTimePicker->TabIndex = 63;
			this->ReturnDateTimePicker->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			// 
			// FilmIdComboBox
			// 
			this->FilmIdComboBox->FormattingEnabled = true;
			this->FilmIdComboBox->Location = System::Drawing::Point(167, 86);
			this->FilmIdComboBox->Name = L"FilmIdComboBox";
			this->FilmIdComboBox->Size = System::Drawing::Size(171, 24);
			this->FilmIdComboBox->TabIndex = 66;
			this->FilmIdComboBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &HystoryAdvanedSearchForm::FilmIdComboBox_KeyPress);
			// 
			// FilmNameComboBox
			// 
			this->FilmNameComboBox->FormattingEnabled = true;
			this->FilmNameComboBox->Location = System::Drawing::Point(167, 116);
			this->FilmNameComboBox->Name = L"FilmNameComboBox";
			this->FilmNameComboBox->Size = System::Drawing::Size(171, 24);
			this->FilmNameComboBox->TabIndex = 67;
			this->FilmNameComboBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &HystoryAdvanedSearchForm::FIOClientComboBox_KeyPress);
			// 
			// HystoryAdvanedSearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(350, 267);
			this->Controls->Add(this->FilmNameComboBox);
			this->Controls->Add(this->FilmIdComboBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->ReturnDateTimePicker);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TransactDateTimePicker);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->findButton);
			this->Controls->Add(this->FIOClientComboBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(368, 314);
			this->MinimumSize = System::Drawing::Size(368, 314);
			this->Name = L"HystoryAdvanedSearchForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &HystoryAdvanedSearchForm::HystoryAdvanedSearchForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void findButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e);
private: void loadComboBox();
public:  void issueEvent1(System::Object^ sender, System::EventArgs^ e);
private: System::Void HystoryAdvanedSearchForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void FIOClientComboBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void FilmIdComboBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
};
}

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
	/// Summary for AdvSearchUserForm
	/// </summary>
	public ref class AdvSearchUserForm : public System::Windows::Forms::Form
	{
	// Required to communicate with the form ReviewAndViewDBForm
	// ---------
	public: delegate void EventDelegate1(System::Object^ sender,
		System::EventArgs^ e, System::String^ str);
	public: event EventDelegate1^ myEvent1;
	// ---------
	private:
		String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;
	private: System::Windows::Forms::TextBox^  nameTxtBx;
	private: System::Windows::Forms::Button^  BackButton;

			 String^ query;
	public:
		AdvSearchUserForm(void)
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
		~AdvSearchUserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  findBtn;
	protected:

	private: System::Windows::Forms::ComboBox^  filmGnrCmbBx;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  frmPriceTxtBx;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  toPriceTxtBx;

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
			this->findBtn = (gcnew System::Windows::Forms::Button());
			this->filmGnrCmbBx = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->frmPriceTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->toPriceTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->nameTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// findBtn
			// 
			this->findBtn->Location = System::Drawing::Point(105, 178);
			this->findBtn->Name = L"findBtn";
			this->findBtn->Size = System::Drawing::Size(90, 37);
			this->findBtn->TabIndex = 0;
			this->findBtn->Text = L"Поиск";
			this->findBtn->UseVisualStyleBackColor = true;
			this->findBtn->Click += gcnew System::EventHandler(this, &AdvSearchUserForm::findBtn_Click);
			// 
			// filmGnrCmbBx
			// 
			this->filmGnrCmbBx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->filmGnrCmbBx->FormattingEnabled = true;
			this->filmGnrCmbBx->Location = System::Drawing::Point(15, 88);
			this->filmGnrCmbBx->Name = L"filmGnrCmbBx";
			this->filmGnrCmbBx->Size = System::Drawing::Size(180, 24);
			this->filmGnrCmbBx->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Фильм";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Жанр";
			// 
			// frmPriceTxtBx
			// 
			this->frmPriceTxtBx->Location = System::Drawing::Point(48, 141);
			this->frmPriceTxtBx->Name = L"frmPriceTxtBx";
			this->frmPriceTxtBx->Size = System::Drawing::Size(43, 22);
			this->frmPriceTxtBx->TabIndex = 5;
			this->frmPriceTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvSearchUserForm::frmPriceTxtBx_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"От:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Цена";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(102, 144);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"До:";
			// 
			// toPriceTxtBx
			// 
			this->toPriceTxtBx->Location = System::Drawing::Point(152, 141);
			this->toPriceTxtBx->Name = L"toPriceTxtBx";
			this->toPriceTxtBx->Size = System::Drawing::Size(43, 22);
			this->toPriceTxtBx->TabIndex = 8;
			this->toPriceTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvSearchUserForm::frmPriceTxtBx_KeyPress);
			// 
			// nameTxtBx
			// 
			this->nameTxtBx->Location = System::Drawing::Point(15, 37);
			this->nameTxtBx->Name = L"nameTxtBx";
			this->nameTxtBx->Size = System::Drawing::Size(180, 22);
			this->nameTxtBx->TabIndex = 10;
			this->nameTxtBx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AdvSearchUserForm::nameTxtBx_KeyPress);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(15, 178);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(84, 37);
			this->BackButton->TabIndex = 11;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &AdvSearchUserForm::BackButton_Click);
			// 
			// AdvSearchUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(212, 227);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->nameTxtBx);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->toPriceTxtBx);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->frmPriceTxtBx);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->filmGnrCmbBx);
			this->Controls->Add(this->findBtn);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AdvSearchUserForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdvSearchUserForm";
			this->Load += gcnew System::EventHandler(this, &AdvSearchUserForm::AdvSearchUserForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void AdvSearchUserForm_Load(System::Object^  sender, System::EventArgs^  e);
// Required to communicate with the form ReviewAndViewDBForm
public:  void issueEvent1(System::Object^ sender, System::EventArgs^ e);
private: System::Void findBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
// Prohibits entering any characters other than numbers into the TextBox fromPriceTxtBx and toPriceTxtBsx, 'BS', 'DEL' и '.'
// По ASCII: BS - 8, DEL - 127, точка - 46
private: System::Void frmPriceTxtBx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
// Prohibits entering numbers in the textBox filmName
private: System::Void nameTxtBx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
};
}

#pragma once
#include "AdditionalInfoFilmForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RentFilmCommentBoxForm
	/// </summary>
	public ref class RentFilmCommentBoxForm : public System::Windows::Forms::Form
	{
	private: String^ userID;
	private: String^ filmID;
	private: String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label2;
	private: SqlConnection^ sqlConn;
	public:
		RentFilmCommentBoxForm(String^ userID, String^ filmID) : userID(userID), filmID(filmID)
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
		~RentFilmCommentBoxForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ commentToOrderTxtBx;
	private: System::Windows::Forms::Button^ continueBtn;
	private: System::Windows::Forms::Button^ backBtn;
	protected:


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->commentToOrderTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->continueBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(12, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(367, 49);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Есть ли у вас комментарий к заказу\? Если нет, то оставьте поле пустым";
			// 
			// commentToOrderTxtBx
			// 
			this->commentToOrderTxtBx->Location = System::Drawing::Point(12, 136);
			this->commentToOrderTxtBx->Multiline = true;
			this->commentToOrderTxtBx->Name = L"commentToOrderTxtBx";
			this->commentToOrderTxtBx->Size = System::Drawing::Size(367, 97);
			this->commentToOrderTxtBx->TabIndex = 1;
			// 
			// continueBtn
			// 
			this->continueBtn->Location = System::Drawing::Point(215, 246);
			this->continueBtn->Name = L"continueBtn";
			this->continueBtn->Size = System::Drawing::Size(164, 45);
			this->continueBtn->TabIndex = 2;
			this->continueBtn->Text = L"Продолжить";
			this->continueBtn->UseVisualStyleBackColor = true;
			this->continueBtn->Click += gcnew System::EventHandler(this, &RentFilmCommentBoxForm::continueBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->Location = System::Drawing::Point(13, 246);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(159, 45);
			this->backBtn->TabIndex = 3;
			this->backBtn->Text = L"Назад";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &RentFilmCommentBoxForm::backBtn_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(16, 59);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(13, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(366, 47);
			this->label2->TabIndex = 5;
			this->label2->Text = L"До какой даты вы хотите арендовать фильм\?";
			// 
			// RentFilmCommentBoxForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(392, 306);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->continueBtn);
			this->Controls->Add(this->commentToOrderTxtBx);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RentFilmCommentBoxForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RentFilmCommentBoxForm";
			this->Load += gcnew System::EventHandler(this, &RentFilmCommentBoxForm::RentFilmCommentBoxForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void continueBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void RentFilmCommentBoxForm_Load(System::Object^ sender, System::EventArgs^ e);
};
}

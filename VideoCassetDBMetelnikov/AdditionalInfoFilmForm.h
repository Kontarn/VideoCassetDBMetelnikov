#pragma once
#include "AdvSearchUserForm.h"
#include "RentFilmCommentBoxForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

	/// <summary>
	/// Summary for AdditionalInfoFilmForm
	/// </summary>
	public ref class AdditionalInfoFilmForm : public System::Windows::Forms::Form
	{
	private:
		String^ filmID;
		String^ userID;
		String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;
	private: System::Windows::Forms::Button^  leaveReviewBtn;
	private: System::Windows::Forms::TextBox^  newReviewTxtBx;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox2;





			 DataSet^ dataSet;
	public:
		AdditionalInfoFilmForm(String^ filmID, String^ userID) : filmID(filmID), userID(userID)
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
		~AdditionalInfoFilmForm()
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
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  BackBtn;
	private: System::Windows::Forms::Button^  rentFilmBtn;
	private: System::Windows::Forms::Button^  toFavorBtn;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  filmNameLbl;
	private: System::Windows::Forms::Label^  gnrNameLbl;
	private: System::Windows::Forms::Label^  yearOfRlslabel;
	private: System::Windows::Forms::Label^  dirFlmLabel;
	private: System::Windows::Forms::Label^  availLabel;
	private: System::Windows::Forms::Label^  priceLabel;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->BackBtn = (gcnew System::Windows::Forms::Button());
			this->rentFilmBtn = (gcnew System::Windows::Forms::Button());
			this->toFavorBtn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->filmNameLbl = (gcnew System::Windows::Forms::Label());
			this->gnrNameLbl = (gcnew System::Windows::Forms::Label());
			this->yearOfRlslabel = (gcnew System::Windows::Forms::Label());
			this->dirFlmLabel = (gcnew System::Windows::Forms::Label());
			this->availLabel = (gcnew System::Windows::Forms::Label());
			this->priceLabel = (gcnew System::Windows::Forms::Label());
			this->leaveReviewBtn = (gcnew System::Windows::Forms::Button());
			this->newReviewTxtBx = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(116, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Информация о фильме";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Название:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Жанр:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Дата премьеры:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Режиссёр:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 193);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 16);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Наличие на складе:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(24, 229);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 16);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Цена:";
			// 
			// BackBtn
			// 
			this->BackBtn->Location = System::Drawing::Point(27, 272);
			this->BackBtn->Name = L"BackBtn";
			this->BackBtn->Size = System::Drawing::Size(116, 37);
			this->BackBtn->TabIndex = 8;
			this->BackBtn->Text = L"Назад";
			this->BackBtn->UseVisualStyleBackColor = true;
			this->BackBtn->Click += gcnew System::EventHandler(this, &AdditionalInfoFilmForm::BackBtn_Click);
			// 
			// rentFilmBtn
			// 
			this->rentFilmBtn->Location = System::Drawing::Point(171, 272);
			this->rentFilmBtn->Name = L"rentFilmBtn";
			this->rentFilmBtn->Size = System::Drawing::Size(120, 37);
			this->rentFilmBtn->TabIndex = 9;
			this->rentFilmBtn->Text = L"Арендовать";
			this->rentFilmBtn->UseVisualStyleBackColor = true;
			this->rentFilmBtn->Click += gcnew System::EventHandler(this, &AdditionalInfoFilmForm::rentFilmBtn_Click);
			// 
			// toFavorBtn
			// 
			this->toFavorBtn->Location = System::Drawing::Point(316, 272);
			this->toFavorBtn->Name = L"toFavorBtn";
			this->toFavorBtn->Size = System::Drawing::Size(126, 37);
			this->toFavorBtn->TabIndex = 10;
			this->toFavorBtn->Text = L"В избранное";
			this->toFavorBtn->UseVisualStyleBackColor = true;
			this->toFavorBtn->Click += gcnew System::EventHandler(this, &AdditionalInfoFilmForm::toFavorBtn_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label8->Location = System::Drawing::Point(24, 459);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 20);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Отзывы:";
			// 
			// filmNameLbl
			// 
			this->filmNameLbl->AutoSize = true;
			this->filmNameLbl->Location = System::Drawing::Point(179, 59);
			this->filmNameLbl->Name = L"filmNameLbl";
			this->filmNameLbl->Size = System::Drawing::Size(11, 16);
			this->filmNameLbl->TabIndex = 12;
			this->filmNameLbl->Text = L"-";
			// 
			// gnrNameLbl
			// 
			this->gnrNameLbl->AutoSize = true;
			this->gnrNameLbl->Location = System::Drawing::Point(179, 91);
			this->gnrNameLbl->Name = L"gnrNameLbl";
			this->gnrNameLbl->Size = System::Drawing::Size(11, 16);
			this->gnrNameLbl->TabIndex = 13;
			this->gnrNameLbl->Text = L"-";
			// 
			// yearOfRlslabel
			// 
			this->yearOfRlslabel->AutoSize = true;
			this->yearOfRlslabel->Location = System::Drawing::Point(179, 121);
			this->yearOfRlslabel->Name = L"yearOfRlslabel";
			this->yearOfRlslabel->Size = System::Drawing::Size(11, 16);
			this->yearOfRlslabel->TabIndex = 14;
			this->yearOfRlslabel->Text = L"-";
			// 
			// dirFlmLabel
			// 
			this->dirFlmLabel->AutoSize = true;
			this->dirFlmLabel->Location = System::Drawing::Point(179, 155);
			this->dirFlmLabel->Name = L"dirFlmLabel";
			this->dirFlmLabel->Size = System::Drawing::Size(11, 16);
			this->dirFlmLabel->TabIndex = 15;
			this->dirFlmLabel->Text = L"-";
			// 
			// availLabel
			// 
			this->availLabel->AutoSize = true;
			this->availLabel->Location = System::Drawing::Point(179, 193);
			this->availLabel->Name = L"availLabel";
			this->availLabel->Size = System::Drawing::Size(11, 16);
			this->availLabel->TabIndex = 16;
			this->availLabel->Text = L"-";
			// 
			// priceLabel
			// 
			this->priceLabel->AutoSize = true;
			this->priceLabel->Location = System::Drawing::Point(179, 229);
			this->priceLabel->Name = L"priceLabel";
			this->priceLabel->Size = System::Drawing::Size(11, 16);
			this->priceLabel->TabIndex = 17;
			this->priceLabel->Text = L"-";
			// 
			// leaveReviewBtn
			// 
			this->leaveReviewBtn->Location = System::Drawing::Point(320, 440);
			this->leaveReviewBtn->Name = L"leaveReviewBtn";
			this->leaveReviewBtn->Size = System::Drawing::Size(122, 29);
			this->leaveReviewBtn->TabIndex = 19;
			this->leaveReviewBtn->Text = L"Отправить";
			this->leaveReviewBtn->UseVisualStyleBackColor = true;
			this->leaveReviewBtn->Click += gcnew System::EventHandler(this, &AdditionalInfoFilmForm::leaveReviewBtn_Click);
			// 
			// newReviewTxtBx
			// 
			this->newReviewTxtBx->Location = System::Drawing::Point(27, 348);
			this->newReviewTxtBx->Multiline = true;
			this->newReviewTxtBx->Name = L"newReviewTxtBx";
			this->newReviewTxtBx->Size = System::Drawing::Size(415, 86);
			this->newReviewTxtBx->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label9->Location = System::Drawing::Point(24, 325);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(152, 20);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Оставьте отзыв:";
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(27, 495);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(413, 216);
			this->textBox2->TabIndex = 22;
			// 
			// AdditionalInfoFilmForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(459, 723);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->newReviewTxtBx);
			this->Controls->Add(this->leaveReviewBtn);
			this->Controls->Add(this->priceLabel);
			this->Controls->Add(this->availLabel);
			this->Controls->Add(this->dirFlmLabel);
			this->Controls->Add(this->yearOfRlslabel);
			this->Controls->Add(this->gnrNameLbl);
			this->Controls->Add(this->filmNameLbl);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->toFavorBtn);
			this->Controls->Add(this->rentFilmBtn);
			this->Controls->Add(this->BackBtn);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AdditionalInfoFilmForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdditionalInfoFilmForm";
			this->Load += gcnew System::EventHandler(this, &AdditionalInfoFilmForm::AdditionalInfoFilmForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BackBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AdditionalInfoFilmForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void leaveReviewBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: void loadReviewData();

private: System::Void toFavorBtn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void rentFilmBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

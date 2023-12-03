#pragma once
#include <ctime>
//#include "EditAndViewDBForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace std;

	/// <summary>
	/// Summary for EditEntrysForm
	/// </summary>
	public ref class EditEntrysForm : public System::Windows::Forms::Form
	{
	//private:
	//	String^ nameFilm, nameGenre, yearOfRelease,
	//		filmDir, availability, price;
	private:String^ filmID;
	private: tm* timeInfo;
	public: delegate void EventDelegate1(System::Object^ sender,
		System::EventArgs^ e);
	public: event EventDelegate1^ myEvent1;
	public:
		EditEntrysForm(String^ filmID, String^ nameFilm, String^ nameGenre, String^ yearOfRelease,
			String^ filmDir, String^ availability, String^ price)
		{
			InitializeComponent();
			this->filmID = filmID;
			genreComboBox->Text = nameGenre;
			nameFilmTextBox->Text = nameFilm;
			yearOfReleaseTextBox->Text = yearOfRelease;
			filmDirTextBox->Text = filmDir;
			availTextBox->Text = availability;
			priceTextBox->Text = price;
		}
		EditEntrysForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditEntrysForm()
		{
			if (components)
			{
				delete components;
			}
			delete timeInfo;
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  nameFilmTextBox;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  availTextBox;



	private: System::Windows::Forms::TextBox^  filmDirTextBox;

	private: System::Windows::Forms::TextBox^  yearOfReleaseTextBox;
	private: System::Windows::Forms::TextBox^  priceTextBox;
	private: System::Windows::Forms::ComboBox^  genreComboBox;





	private: System::Windows::Forms::Button^  editButton;
	private: System::Windows::Forms::Button^  BackButton;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String^ connString = "Data Source=DESKTOP-LSHR1L6;Initial Catalog=VideoCassetDB;Integrated Security=True";
		SqlConnection^ sqlConn;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameFilmTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->availTextBox = (gcnew System::Windows::Forms::TextBox());
			this->filmDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->yearOfReleaseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->genreComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.8F));
			this->label1->Location = System::Drawing::Point(83, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Изменение записи";
			// 
			// nameFilmTextBox
			// 
			this->nameFilmTextBox->Location = System::Drawing::Point(14, 72);
			this->nameFilmTextBox->Name = L"nameFilmTextBox";
			this->nameFilmTextBox->Size = System::Drawing::Size(306, 22);
			this->nameFilmTextBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Название";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 164);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Цена";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(347, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Количество";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(122, 112);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Режиссёр";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 112);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 16);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Год премьеры";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(323, 52);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 16);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Жанр";
			// 
			// availTextBox
			// 
			this->availTextBox->Location = System::Drawing::Point(350, 132);
			this->availTextBox->Name = L"availTextBox";
			this->availTextBox->Size = System::Drawing::Size(83, 22);
			this->availTextBox->TabIndex = 8;
			this->availTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::yearOfReleaseTextBox_KeyPress);
			// 
			// filmDirTextBox
			// 
			this->filmDirTextBox->Location = System::Drawing::Point(125, 132);
			this->filmDirTextBox->Name = L"filmDirTextBox";
			this->filmDirTextBox->Size = System::Drawing::Size(210, 22);
			this->filmDirTextBox->TabIndex = 9;
			this->filmDirTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::genreComboBox_KeyPress);
			// 
			// yearOfReleaseTextBox
			// 
			this->yearOfReleaseTextBox->Location = System::Drawing::Point(14, 132);
			this->yearOfReleaseTextBox->Name = L"yearOfReleaseTextBox";
			this->yearOfReleaseTextBox->Size = System::Drawing::Size(100, 22);
			this->yearOfReleaseTextBox->TabIndex = 10;
			this->yearOfReleaseTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::yearOfReleaseTextBox_KeyPress);
			// 
			// priceTextBox
			// 
			this->priceTextBox->Location = System::Drawing::Point(14, 184);
			this->priceTextBox->Name = L"priceTextBox";
			this->priceTextBox->Size = System::Drawing::Size(100, 22);
			this->priceTextBox->TabIndex = 12;
			this->priceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::yearOfReleaseTextBox_KeyPress);
			// 
			// genreComboBox
			// 
			this->genreComboBox->FormattingEnabled = true;
			this->genreComboBox->Location = System::Drawing::Point(326, 72);
			this->genreComboBox->Name = L"genreComboBox";
			this->genreComboBox->Size = System::Drawing::Size(107, 24);
			this->genreComboBox->TabIndex = 13;
			this->genreComboBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::genreComboBox_KeyPress);
			// 
			// editButton
			// 
			this->editButton->Location = System::Drawing::Point(326, 219);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(107, 36);
			this->editButton->TabIndex = 14;
			this->editButton->Text = L"Изменить";
			this->editButton->UseVisualStyleBackColor = true;
			this->editButton->Click += gcnew System::EventHandler(this, &EditEntrysForm::editButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(202, 219);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(101, 36);
			this->BackButton->TabIndex = 15;
			this->BackButton->Text = L"Назад";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &EditEntrysForm::BackButton_Click);
			// 
			// EditEntrysForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 268);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->genreComboBox);
			this->Controls->Add(this->priceTextBox);
			this->Controls->Add(this->yearOfReleaseTextBox);
			this->Controls->Add(this->filmDirTextBox);
			this->Controls->Add(this->availTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nameFilmTextBox);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(464, 315);
			this->MinimumSize = System::Drawing::Size(464, 315);
			this->Name = L"EditEntrysForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &EditEntrysForm::EditEntrysForm_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditEntrysForm::genreComboBox_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void EditEntrysForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void editButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void yearOfReleaseTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void genreComboBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
public:  void issueEvent1(System::Object^ sender, System::EventArgs^ e);
};
}

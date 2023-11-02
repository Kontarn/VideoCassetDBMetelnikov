#pragma once
#include "StartMenuForm.h"
#include "EditAndViewDBForm.h"
#include "HystoryOfBuyForm.h"

namespace VideoCassetDBMetelnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForStaffForm
	/// </summary>
	public ref class MenuForStaffForm : public System::Windows::Forms::Form
	{
	public:
		MenuForStaffForm(void)
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
		~MenuForStaffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ExitButton;
	protected:
	private: System::Windows::Forms::Button^  ToStartButton;
	private: System::Windows::Forms::Button^  EditPassButton;
	private: System::Windows::Forms::Button^  HystoryOfBuy;

	private: System::Windows::Forms::Button^  EditAndViewDBButton;

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
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->ToStartButton = (gcnew System::Windows::Forms::Button());
			this->EditPassButton = (gcnew System::Windows::Forms::Button());
			this->HystoryOfBuy = (gcnew System::Windows::Forms::Button());
			this->EditAndViewDBButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ExitButton
			// 
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->ExitButton->Location = System::Drawing::Point(169, 184);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(124, 42);
			this->ExitButton->TabIndex = 9;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MenuForStaffForm::ExitButton_Click);
			// 
			// ToStartButton
			// 
			this->ToStartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->ToStartButton->Location = System::Drawing::Point(12, 184);
			this->ToStartButton->Name = L"ToStartButton";
			this->ToStartButton->Size = System::Drawing::Size(147, 42);
			this->ToStartButton->TabIndex = 8;
			this->ToStartButton->Text = L"В начало";
			this->ToStartButton->UseVisualStyleBackColor = true;
			this->ToStartButton->Click += gcnew System::EventHandler(this, &MenuForStaffForm::ToStartButton_Click);
			// 
			// EditPassButton
			// 
			this->EditPassButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->EditPassButton->Location = System::Drawing::Point(26, 132);
			this->EditPassButton->Name = L"EditPassButton";
			this->EditPassButton->Size = System::Drawing::Size(249, 46);
			this->EditPassButton->TabIndex = 7;
			this->EditPassButton->Text = L"Изменить код доступа";
			this->EditPassButton->UseVisualStyleBackColor = true;
			// 
			// HystoryOfBuy
			// 
			this->HystoryOfBuy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->HystoryOfBuy->Location = System::Drawing::Point(26, 80);
			this->HystoryOfBuy->Name = L"HystoryOfBuy";
			this->HystoryOfBuy->Size = System::Drawing::Size(249, 46);
			this->HystoryOfBuy->TabIndex = 6;
			this->HystoryOfBuy->Text = L"История покупок";
			this->HystoryOfBuy->UseVisualStyleBackColor = true;
			this->HystoryOfBuy->Click += gcnew System::EventHandler(this, &MenuForStaffForm::HystoryOfBuy_Click);
			// 
			// EditAndViewDBButton
			// 
			this->EditAndViewDBButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->EditAndViewDBButton->Location = System::Drawing::Point(26, 12);
			this->EditAndViewDBButton->Name = L"EditAndViewDBButton";
			this->EditAndViewDBButton->Size = System::Drawing::Size(249, 62);
			this->EditAndViewDBButton->TabIndex = 5;
			this->EditAndViewDBButton->Text = L"Редактирование и просмотр БД";
			this->EditAndViewDBButton->UseVisualStyleBackColor = true;
			this->EditAndViewDBButton->Click += gcnew System::EventHandler(this, &MenuForStaffForm::EditAndViewDBButton_Click);
			// 
			// MenuForStaffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 240);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ToStartButton);
			this->Controls->Add(this->EditPassButton);
			this->Controls->Add(this->HystoryOfBuy);
			this->Controls->Add(this->EditAndViewDBButton);
			this->MaximizeBox = false;
			this->Name = L"MenuForStaffForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuForStaffForm";
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ToStartButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void EditAndViewDBButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void HystoryOfBuy_Click(System::Object^  sender, System::EventArgs^  e);
};
}

#pragma once

#include <stdio.h>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Robot_Control_App {

	/// <summary>
	/// Summary for OnlineBlock
	/// </summary>
	public ref class OnlineBlock : public System::Windows::Forms::UserControl
	{
	public:
		OnlineBlock(void)
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
		~OnlineBlock()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  BlockImage;
	protected: 

	protected: 

	protected: 
	public: System::Windows::Forms::Label^  BlockName;
	public: System::Windows::Forms::TrackBar^  trackBar;
	public: System::Windows::Forms::Label^  Max;
	private: 


	private: System::Windows::Forms::Label^  Min;
	public: System::Windows::Forms::Label^  ActualValue;
	public: System::Windows::Forms::Panel^  colorStrip;

	public: 

	public: 
	private: 

	private: 
	public: 

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
			this->BlockImage = (gcnew System::Windows::Forms::PictureBox());
			this->BlockName = (gcnew System::Windows::Forms::Label());
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->Max = (gcnew System::Windows::Forms::Label());
			this->Min = (gcnew System::Windows::Forms::Label());
			this->ActualValue = (gcnew System::Windows::Forms::Label());
			this->colorStrip = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// BlockImage
			// 
			this->BlockImage->Location = System::Drawing::Point(95, 3);
			this->BlockImage->Name = L"BlockImage";
			this->BlockImage->Size = System::Drawing::Size(70, 70);
			this->BlockImage->TabIndex = 0;
			this->BlockImage->TabStop = false;
			// 
			// BlockName
			// 
			this->BlockName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->BlockName->ForeColor = System::Drawing::Color::White;
			this->BlockName->Location = System::Drawing::Point(-1, 50);
			this->BlockName->Name = L"BlockName";
			this->BlockName->Size = System::Drawing::Size(90, 23);
			this->BlockName->TabIndex = 3;
			this->BlockName->Text = L"ACTUATOR_X";
			this->BlockName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// trackBar
			// 
			this->trackBar->Location = System::Drawing::Point(3, 120);
			this->trackBar->Maximum = 36;
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(162, 45);
			this->trackBar->TabIndex = 4;
			this->trackBar->TickFrequency = 2;
			this->trackBar->Value = 18;
			this->trackBar->ValueChanged += gcnew System::EventHandler(this, &OnlineBlock::trackBar_ValueChanged);
			// 
			// Max
			// 
			this->Max->AutoSize = true;
			this->Max->ForeColor = System::Drawing::Color::White;
			this->Max->Location = System::Drawing::Point(140, 104);
			this->Max->Name = L"Max";
			this->Max->Size = System::Drawing::Size(25, 13);
			this->Max->TabIndex = 5;
			this->Max->Text = L"180";
			// 
			// Min
			// 
			this->Min->AutoSize = true;
			this->Min->ForeColor = System::Drawing::Color::White;
			this->Min->Location = System::Drawing::Point(3, 104);
			this->Min->Name = L"Min";
			this->Min->Size = System::Drawing::Size(13, 13);
			this->Min->TabIndex = 6;
			this->Min->Text = L"0";
			// 
			// ActualValue
			// 
			this->ActualValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->ActualValue->ForeColor = System::Drawing::Color::White;
			this->ActualValue->Location = System::Drawing::Point(3, 73);
			this->ActualValue->Name = L"ActualValue";
			this->ActualValue->Size = System::Drawing::Size(86, 23);
			this->ActualValue->TabIndex = 7;
			this->ActualValue->Text = L"90";
			this->ActualValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// colorStrip
			// 
			this->colorStrip->BackColor = System::Drawing::SystemColors::Control;
			this->colorStrip->Location = System::Drawing::Point(0, 120);
			this->colorStrip->Name = L"colorStrip";
			this->colorStrip->Size = System::Drawing::Size(169, 49);
			this->colorStrip->TabIndex = 8;
			// 
			// OnlineBlock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->ActualValue);
			this->Controls->Add(this->Min);
			this->Controls->Add(this->Max);
			this->Controls->Add(this->trackBar);
			this->Controls->Add(this->BlockName);
			this->Controls->Add(this->BlockImage);
			this->Controls->Add(this->colorStrip);
			this->Name = L"OnlineBlock";
			this->Size = System::Drawing::Size(168, 168);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void trackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(this->BlockName->Text == "SPEED_")
				 {
				 int num = (this->trackBar->Value);
				 char str[12];
				 num = num;
				 sprintf(str, "%d", num);
				 String^ buffer = gcnew String(str);
				 this->ActualValue->Text = buffer;
				 }
				 else
				 {
				 int num = (this->trackBar->Value)*5;
				 char str[12];
				 num = num;
				 sprintf(str, "%d", num);
				 String^ buffer = gcnew String(str);
				 this->ActualValue->Text = buffer;
				 }
			 }
		 

};
}

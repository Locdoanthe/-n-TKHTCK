#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Robot_Control_App {

	/// <summary>
	/// Summary for BeginBlock
	/// </summary>
	public ref class BeginBlock : public System::Windows::Forms::UserControl
	{
	public:
		BeginBlock(void)
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
		~BeginBlock()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  BlockIndex;
	public: System::Windows::Forms::Label^  BlockName;
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
			this->BlockIndex = (gcnew System::Windows::Forms::Label());
			this->BlockName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// BlockIndex
			// 
			this->BlockIndex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->BlockIndex->Location = System::Drawing::Point(3, 0);
			this->BlockIndex->Name = L"BlockIndex";
			this->BlockIndex->Size = System::Drawing::Size(28, 23);
			this->BlockIndex->TabIndex = 1;
			this->BlockIndex->Text = L"0";
			this->BlockIndex->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// BlockName
			// 
			this->BlockName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->BlockName->Location = System::Drawing::Point(3, 50);
			this->BlockName->Name = L"BlockName";
			this->BlockName->Size = System::Drawing::Size(66, 23);
			this->BlockName->TabIndex = 3;
			this->BlockName->Text = L"BEGIN";
			this->BlockName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// BeginBlock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->BlockName);
			this->Controls->Add(this->BlockIndex);
			this->Name = L"BeginBlock";
			this->Size = System::Drawing::Size(148, 148);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

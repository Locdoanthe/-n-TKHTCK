#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Robot_Control_App {

	/// <summary>
	/// Summary for GraphicBlock
	/// </summary>
	public ref class GraphicBlock : public System::Windows::Forms::UserControl
	{
	public:
		GraphicBlock(void)
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
		~GraphicBlock()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  BlockIndex;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	public: System::Windows::Forms::Label^  BlockName;
	public: System::Windows::Forms::NumericUpDown^  BlockValue;
	public: System::Windows::Forms::Panel^  colorStrip;

	public: 

	public: 

	public: 
	protected: 

	protected: 

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->BlockName = (gcnew System::Windows::Forms::Label());
			this->BlockValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->colorStrip = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockValue))->BeginInit();
			this->colorStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// BlockIndex
			// 
			this->BlockIndex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->BlockIndex->ForeColor = System::Drawing::Color::White;
			this->BlockIndex->Location = System::Drawing::Point(3, 0);
			this->BlockIndex->Name = L"BlockIndex";
			this->BlockIndex->Size = System::Drawing::Size(28, 23);
			this->BlockIndex->TabIndex = 0;
			this->BlockIndex->Text = L"IDX";
			this->BlockIndex->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(75, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(70, 70);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// BlockName
			// 
			this->BlockName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->BlockName->ForeColor = System::Drawing::Color::White;
			this->BlockName->Location = System::Drawing::Point(3, 76);
			this->BlockName->Name = L"BlockName";
			this->BlockName->Size = System::Drawing::Size(127, 15);
			this->BlockName->TabIndex = 2;
			this->BlockName->Text = L"ACTUATOR";
			this->BlockName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BlockValue
			// 
			this->BlockValue->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->BlockValue->Location = System::Drawing::Point(24, 18);
			this->BlockValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->BlockValue->Name = L"BlockValue";
			this->BlockValue->Size = System::Drawing::Size(106, 20);
			this->BlockValue->TabIndex = 3;
			// 
			// colorStrip
			// 
			this->colorStrip->Controls->Add(this->BlockValue);
			this->colorStrip->Location = System::Drawing::Point(0, 94);
			this->colorStrip->Name = L"colorStrip";
			this->colorStrip->Size = System::Drawing::Size(148, 54);
			this->colorStrip->TabIndex = 4;
			// 
			// GraphicBlock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->colorStrip);
			this->Controls->Add(this->BlockName);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->BlockIndex);
			this->Name = L"GraphicBlock";
			this->Size = System::Drawing::Size(148, 148);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlockValue))->EndInit();
			this->colorStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

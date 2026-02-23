#pragma once

namespace Robot_Control_App {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DialogWin
	/// </summary>
	public ref class DialogWin : public System::Windows::Forms::Form
	{
	public:
		DialogWin(void)
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
		~DialogWin()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  Continue;
	protected: 

	public: System::Windows::Forms::Label^  DialogText;
	private: 
	public: System::Windows::Forms::Label^  DialogTitle;
	public: System::Windows::Forms::Button^  Yes;
	public: System::Windows::Forms::Button^  No;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DialogWin::typeid));
			this->Continue = (gcnew System::Windows::Forms::Button());
			this->DialogText = (gcnew System::Windows::Forms::Label());
			this->DialogTitle = (gcnew System::Windows::Forms::Label());
			this->Yes = (gcnew System::Windows::Forms::Button());
			this->No = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Continue
			// 
			this->Continue->AutoSize = true;
			this->Continue->Font = (gcnew System::Drawing::Font(L"Vafle VUT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Continue->Location = System::Drawing::Point(152, 244);
			this->Continue->Name = L"Continue";
			this->Continue->Size = System::Drawing::Size(92, 29);
			this->Continue->TabIndex = 0;
			this->Continue->Text = L"Pokraèovat";
			this->Continue->UseVisualStyleBackColor = true;
			this->Continue->Visible = false;
			this->Continue->Click += gcnew System::EventHandler(this, &DialogWin::Continue_Click);
			// 
			// DialogText
			// 
			this->DialogText->BackColor = System::Drawing::Color::Transparent;
			this->DialogText->Font = (gcnew System::Drawing::Font(L"Vafle VUT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->DialogText->ForeColor = System::Drawing::SystemColors::Info;
			this->DialogText->Location = System::Drawing::Point(12, 55);
			this->DialogText->Name = L"DialogText";
			this->DialogText->Size = System::Drawing::Size(376, 186);
			this->DialogText->TabIndex = 1;
			this->DialogText->Text = L"DialogText";
			this->DialogText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DialogTitle
			// 
			this->DialogTitle->BackColor = System::Drawing::Color::Transparent;
			this->DialogTitle->Font = (gcnew System::Drawing::Font(L"Vafle VUT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->DialogTitle->ForeColor = System::Drawing::Color::Red;
			this->DialogTitle->Location = System::Drawing::Point(16, 9);
			this->DialogTitle->Name = L"DialogTitle";
			this->DialogTitle->Size = System::Drawing::Size(372, 46);
			this->DialogTitle->TabIndex = 2;
			this->DialogTitle->Text = L"DialogTitle";
			this->DialogTitle->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Yes
			// 
			this->Yes->DialogResult = System::Windows::Forms::DialogResult::Yes;
			this->Yes->Font = (gcnew System::Drawing::Font(L"Vafle VUT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Yes->Location = System::Drawing::Point(54, 244);
			this->Yes->Name = L"Yes";
			this->Yes->Size = System::Drawing::Size(92, 29);
			this->Yes->TabIndex = 0;
			this->Yes->Text = L"Ano";
			this->Yes->UseVisualStyleBackColor = true;
			this->Yes->Visible = false;
			// 
			// No
			// 
			this->No->AutoSize = true;
			this->No->DialogResult = System::Windows::Forms::DialogResult::No;
			this->No->Font = (gcnew System::Drawing::Font(L"Vafle VUT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->No->Location = System::Drawing::Point(250, 244);
			this->No->Name = L"No";
			this->No->Size = System::Drawing::Size(92, 29);
			this->No->TabIndex = 0;
			this->No->Text = L"Ne";
			this->No->UseVisualStyleBackColor = true;
			this->No->Visible = false;
			this->No->Click += gcnew System::EventHandler(this, &DialogWin::Continue_Click);
			// 
			// DialogWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(400, 300);
			this->Controls->Add(this->DialogTitle);
			this->Controls->Add(this->DialogText);
			this->Controls->Add(this->No);
			this->Controls->Add(this->Yes);
			this->Controls->Add(this->Continue);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"DialogWin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"DialogWin";
			this->TransparencyKey = System::Drawing::SystemColors::Control;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Continue_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
};
}

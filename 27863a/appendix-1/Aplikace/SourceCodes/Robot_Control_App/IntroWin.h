#pragma once

#include <WindowsX.h>
//#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

#include "errno.h"

namespace Robot_Control_App {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for IntroWin
	/// </summary>
	public ref class IntroWin : public System::Windows::Forms::Form
	{
	public:
		IntroWin(String ^Version)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->IntroVersion->Text = Version;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IntroWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  TimerIntro;
	private: System::Windows::Forms::Label^  IntroVersion;

	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(IntroWin::typeid));
			this->TimerIntro = (gcnew System::Windows::Forms::Timer(this->components));
			this->IntroVersion = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TimerIntro
			// 
			this->TimerIntro->Enabled = true;
			this->TimerIntro->Interval = 7000;
			this->TimerIntro->Tick += gcnew System::EventHandler(this, &IntroWin::TimerIntro_Tick);
			// 
			// IntroVersion
			// 
			this->IntroVersion->AutoSize = true;
			this->IntroVersion->BackColor = System::Drawing::Color::Transparent;
			this->IntroVersion->Location = System::Drawing::Point(12, 378);
			this->IntroVersion->Name = L"IntroVersion";
			this->IntroVersion->Size = System::Drawing::Size(34, 13);
			this->IntroVersion->TabIndex = 0;
			this->IntroVersion->Text = L"Verze";
			// 
			// IntroWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(533, 400);
			this->Controls->Add(this->IntroVersion);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"IntroWin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Robot Control App";
			this->TransparencyKey = System::Drawing::SystemColors::Control;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TimerIntro_Tick(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	};
}

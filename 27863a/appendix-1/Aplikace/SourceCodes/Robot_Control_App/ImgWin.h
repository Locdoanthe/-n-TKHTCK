#pragma once

namespace Robot_Control_App {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImgWin
	/// </summary>
	public ref class ImgWin : public System::Windows::Forms::Form
	{
	public:
		ImgWin(void)
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
		~ImgWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  vždyNahoøeToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ImgWin::typeid));
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->vždyNahoøeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->vždyNahoøeToolStripMenuItem});
			this->contextMenuStrip->Name = L"contextMenuStrip";
			this->contextMenuStrip->Size = System::Drawing::Size(140, 26);
			// 
			// vždyNahoøeToolStripMenuItem
			// 
			this->vždyNahoøeToolStripMenuItem->Checked = true;
			this->vždyNahoøeToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->vždyNahoøeToolStripMenuItem->Name = L"vždyNahoøeToolStripMenuItem";
			this->vždyNahoøeToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->vždyNahoøeToolStripMenuItem->Text = L"Vždy nahoøe";
			this->vždyNahoøeToolStripMenuItem->Click += gcnew System::EventHandler(this, &ImgWin::vždyNahoøeToolStripMenuItem_Click);
			// 
			// ImgWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(634, 396);
			this->ContextMenuStrip = this->contextMenuStrip;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ImgWin";
			this->Text = L"Rozvržení kloubù";
			this->TopMost = true;
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void vždyNahoøeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->vždyNahoøeToolStripMenuItem->Checked == true)
				 {
					 this->vždyNahoøeToolStripMenuItem->Checked = false;
					this->TopMost = false;
				 }
				 else
				 {
					 this->vždyNahoøeToolStripMenuItem->Checked = true;
					this->TopMost = true;
				 }
			 }
	};
}

#pragma once

#include <WindowsX.h>
#include <Windows.h>
#include <vcclr.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <excpt.h>
#include <ShellAPI.h>
//#include <Shlwapi.h>

#include "errno.h"
#include "OnlineBlock.h"
#include "BeginBlock.h"
#include "GraphicBlock.h"
#include "EndBlock.h"

#pragma comment(lib,"shell32.lib")
static HWND hBut;

#include <cstdlib>
	using namespace std;


namespace Robot_Control_App {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;

	using namespace System::Runtime::InteropServices;

	int i = 0;
	int ErrorCode = 0;
	int ErrorCount = 0;
	int CheckCount = 1;
	char ActualFile;
	int ReceivedFlg=0;

	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class MainWin : public System::Windows::Forms::Form
	{
	public:
		MainWin(String ^Version)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Text = this->Text + Version;
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStripSerial->Location = System::Drawing::Point(212, 0);
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStripCode->Location = System::Drawing::Point(534, 0);
			this->toolStripStartnStop->Location = System::Drawing::Point(3, 25);
			this->toolStripSerialCommand->Location = System::Drawing::Point(86, 25);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStripTop;
	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  souborToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStripBotttom;

	private: System::Windows::Forms::ToolStripContainer^  toolStripContainer1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::TabControl^  tabControlMode;
	private: System::Windows::Forms::TabPage^  tabOnlineMode;


	private: System::Windows::Forms::TabPage^  tabTextMode;

	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  printToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripButton^  cutToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  copyToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  pasteToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  helpToolStripButton;
	private: System::Windows::Forms::ToolStripMenuItem^  novýToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  otevřítToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  uložitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  uložitJakoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zavřítToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  ConsoleOutput;


	private: System::Windows::Forms::TextBox^  CommandBox;
	private: System::Windows::Forms::ToolStripMenuItem^  zobrazeníToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  informačníPanelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverzeBarevToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pracovníPlochaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverzeBarevToolStripMenuItem1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  inverzeBarevToolStripMenuItem2;
	private: System::Windows::Forms::ContextMenuStrip^  contextConsoleOutput;

	private: System::Windows::Forms::ToolStripMenuItem^  inverzeBarevToolStripMenuItem3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^  nápovědaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oProgramuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fontToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lucidaConsoleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  courierNewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  arialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  velikostToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  size8toolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  size10toolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  size9toolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  size11toolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  microsoftSansSerifToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lastOpenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  žádnéPosledníSouboryToolStripMenuItem;
	private: System::Windows::Forms::Panel^  ActualFilePanel;

	private: System::Windows::Forms::Label^  ActualFileLabel;
	private: System::Windows::Forms::ToolTip^  ActualFileToolTip;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	public: System::Windows::Forms::PrintDialog^  printDialog;
	private: 

	private: System::Drawing::Printing::PrintDocument^  printDocument;
	private: System::Windows::Forms::ToolStripMenuItem^  size13toolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  panelyNástrojůToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStripSerial;

	private: System::IO::Ports::SerialPort^  mainSerialPort;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripSerialDropDown;
	private: System::Windows::Forms::ToolStripButton^  toolStripRefreshButton;
	private: System::Windows::Forms::ToolStripMenuItem^  připojeníToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  žádnéPortyToolStripMenuItem;
	private: System::Windows::Forms::Panel^  ActualPortPanel;

	private: System::Windows::Forms::Label^  SelectedPort;
private: System::Windows::Forms::ToolTip^  ActualPortToolTip;
private: System::Windows::Forms::Panel^  ConnectedPanel;

private: System::Windows::Forms::Label^  Connected;
private: System::Windows::Forms::ToolTip^  ConnectedToolTip;
private: System::Windows::Forms::ProgressBar^  statusProgressBar;
private: System::Windows::Forms::Panel^  FirmWarePanel;


private: System::Windows::Forms::ContextMenuStrip^  contextTools;
private: System::Windows::Forms::ToolStripMenuItem^  připojeníToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^  panelyNástrojůToolStripMenuItem1;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
private: System::Windows::Forms::ToolStripButton^  toolStripOpenPortButton;
private: System::Windows::Forms::ToolStripButton^  toolStripClosePortButton;
private: System::Windows::Forms::Timer^  IsConnectedTimer;
private: System::Windows::Forms::Label^  firmWareVersion;

private: System::Windows::Forms::Label^  FirmWare;
private: System::Windows::Forms::Panel^  firmWareVersionPanel;
private: System::Windows::Forms::ToolStrip^  toolStripCode;

private: System::Windows::Forms::ToolStripButton^  toolStripCheckCodeButton;
private: System::Windows::Forms::ToolStripMenuItem^  vyčistitOknoToolStripMenuItem;
private: System::Windows::Forms::Panel^  LineNumberPanel;
private: System::Windows::Forms::Label^  LineNumber;
private: System::Windows::Forms::Timer^  LineNumberTimer;
private: System::Windows::Forms::Label^  LineNumberLabel;
private: System::Windows::Forms::ToolStripMenuItem^  kompilaceToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  serialPříkazyToolStripMenuItem;
private: System::Windows::Forms::ToolStrip^  toolStripSerialCommand;
private: System::Windows::Forms::ToolStripTextBox^  toolStripCommandLine;
private: System::Windows::Forms::ToolStripButton^  toolStripPoslatCommand;
private: System::Windows::Forms::ToolStripMenuItem^  kompilaceToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^  serialPříkazyToolStripMenuItem1;
private: System::Windows::Forms::Timer^  ReceivedTimer;
private: System::Windows::Forms::TabPage^  tabGraphicMode;
private: System::Windows::Forms::SplitContainer^  splitContainer2;
private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutToolPanel;

private: System::Windows::Forms::PictureBox^  BaseAroundBlock;







		 
	private: System::Drawing::Rectangle dragBoxFromMouseDown;
    private: Point screenOffset;
    private: System::Windows::Forms::Cursor^ MyNormalCursor;
	private: System::Drawing::Image^ BlockBG;
private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutWorkSpace;
private: System::Windows::Forms::PictureBox^  DeleteBlock;
private: System::Windows::Forms::PictureBox^  MoveLeftBlock;


private: System::Windows::Forms::PictureBox^  MoveRightBlock;
private: System::Windows::Forms::PictureBox^  BaseUpDownBlock;
private: System::Windows::Forms::SplitContainer^  splitContainer3;
private: System::Windows::Forms::ListBox^  GraphicOutput;

private: Robot_Control_App::BeginBlock^  beginBlock1;
private: Robot_Control_App::EndBlock^  endBlock;
private: System::Windows::Forms::ToolStripButton^  toolStripGrafToTextButton;

private: System::Windows::Forms::ToolTip^  ServoToolTip;
private: System::Windows::Forms::PictureBox^  HandleUpDownBlock;
private: System::Windows::Forms::PictureBox^  HandleRotateBlock;
private: System::Windows::Forms::PictureBox^  JawUpDownBlock;
private: System::Windows::Forms::PictureBox^  JawRotateBlock;
private: System::Windows::Forms::PictureBox^  JawOpenCloseBlock;
private: System::Windows::Forms::PictureBox^  SpeedBlock;
private: System::Windows::Forms::PictureBox^  DelayBlock;

private: System::Windows::Forms::ToolStripButton^  toolStripInitButton;
private: System::Windows::Forms::ToolStripButton^  toolStripCompileButton;
private: System::Windows::Forms::ToolStripMenuItem^  rozvrženíKloubůToolStripMenuItem;
private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo1;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo2;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo3;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo4;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo5;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo6;
private: Robot_Control_App::OnlineBlock^  onlineBlockServo7;
private: Robot_Control_App::OnlineBlock^  onlineBlockSpeed;
private: System::Windows::Forms::ToolStrip^  toolStripStartnStop;

private: System::Windows::Forms::ToolStripButton^  toolStripStartButton;
private: System::Windows::Forms::ToolStripButton^  toolStripStopButton;
private: System::Windows::Forms::ToolStripMenuItem^  ovládáníArduinaToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ovládáníArduinaToolStripMenuItem1;
private: System::Windows::Forms::ToolStripButton^  toolStripTextToGrafButton;
private: System::Windows::Forms::ToolTip^  VersionToolTip;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
private: System::Windows::Forms::ToolStripMenuItem^  stránkyAplikaceToolStripMenuItem;























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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWin::typeid));
			this->menuStripTop = (gcnew System::Windows::Forms::MenuStrip());
			this->contextTools = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->panelyNástrojůToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->připojeníToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kompilaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ovládáníArduinaToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serialPříkazyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->souborToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novýToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->otevřítToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uložitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uložitJakoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lastOpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->žádnéPosledníSouboryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->zavřítToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zobrazeníToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informačníPanelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverzeBarevToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pracovníPlochaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverzeBarevToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelyNástrojůToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->připojeníToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kompilaceToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ovládáníArduinaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serialPříkazyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nápovědaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rozvrženíKloubůToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->oProgramuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stránkyAplikaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStripBotttom = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->tabControlMode = (gcnew System::Windows::Forms::TabControl());
			this->tabOnlineMode = (gcnew System::Windows::Forms::TabPage());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->onlineBlockServo1 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo2 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo3 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo4 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo5 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo6 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockServo7 = (gcnew Robot_Control_App::OnlineBlock());
			this->onlineBlockSpeed = (gcnew Robot_Control_App::OnlineBlock());
			this->tabTextMode = (gcnew System::Windows::Forms::TabPage());
			this->CommandBox = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->inverzeBarevToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fontToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courierNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lucidaConsoleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->microsoftSansSerifToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->velikostToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->size8toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->size9toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->size10toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->size11toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->size13toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabGraphicMode = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->flowLayoutToolPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->BaseAroundBlock = (gcnew System::Windows::Forms::PictureBox());
			this->BaseUpDownBlock = (gcnew System::Windows::Forms::PictureBox());
			this->HandleUpDownBlock = (gcnew System::Windows::Forms::PictureBox());
			this->HandleRotateBlock = (gcnew System::Windows::Forms::PictureBox());
			this->JawUpDownBlock = (gcnew System::Windows::Forms::PictureBox());
			this->JawRotateBlock = (gcnew System::Windows::Forms::PictureBox());
			this->JawOpenCloseBlock = (gcnew System::Windows::Forms::PictureBox());
			this->SpeedBlock = (gcnew System::Windows::Forms::PictureBox());
			this->DelayBlock = (gcnew System::Windows::Forms::PictureBox());
			this->MoveLeftBlock = (gcnew System::Windows::Forms::PictureBox());
			this->MoveRightBlock = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteBlock = (gcnew System::Windows::Forms::PictureBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->flowLayoutWorkSpace = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->beginBlock1 = (gcnew Robot_Control_App::BeginBlock());
			this->endBlock = (gcnew Robot_Control_App::EndBlock());
			this->GraphicOutput = (gcnew System::Windows::Forms::ListBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->printToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cutToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->copyToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->pasteToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->helpToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCode = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripGrafToTextButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCheckCodeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripTextToGrafButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCompileButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSerial = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSerialDropDown = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->žádnéPortyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripRefreshButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripOpenPortButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripClosePortButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripInitButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripStartnStop = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripStartButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripStopButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSerialCommand = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripCommandLine = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripPoslatCommand = (gcnew System::Windows::Forms::ToolStripButton());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->ConsoleOutput = (gcnew System::Windows::Forms::ListBox());
			this->contextConsoleOutput = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->inverzeBarevToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vyčistitOknoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ActualFilePanel = (gcnew System::Windows::Forms::Panel());
			this->ActualFileLabel = (gcnew System::Windows::Forms::Label());
			this->ActualFileToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SelectedPort = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->printDialog = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument = (gcnew System::Drawing::Printing::PrintDocument());
			this->mainSerialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->ActualPortPanel = (gcnew System::Windows::Forms::Panel());
			this->ActualPortToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->ConnectedPanel = (gcnew System::Windows::Forms::Panel());
			this->Connected = (gcnew System::Windows::Forms::Label());
			this->ConnectedToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->statusProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->FirmWarePanel = (gcnew System::Windows::Forms::Panel());
			this->FirmWare = (gcnew System::Windows::Forms::Label());
			this->firmWareVersion = (gcnew System::Windows::Forms::Label());
			this->IsConnectedTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->firmWareVersionPanel = (gcnew System::Windows::Forms::Panel());
			this->LineNumberPanel = (gcnew System::Windows::Forms::Panel());
			this->LineNumber = (gcnew System::Windows::Forms::Label());
			this->LineNumberTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->LineNumberLabel = (gcnew System::Windows::Forms::Label());
			this->ReceivedTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->ServoToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->VersionToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->menuStripTop->SuspendLayout();
			this->contextTools->SuspendLayout();
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->tabControlMode->SuspendLayout();
			this->tabOnlineMode->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->tabTextMode->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->tabGraphicMode->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->flowLayoutToolPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BaseAroundBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BaseUpDownBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HandleUpDownBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HandleRotateBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawUpDownBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawRotateBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawOpenCloseBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SpeedBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DelayBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveLeftBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveRightBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DeleteBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->flowLayoutWorkSpace->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->toolStripCode->SuspendLayout();
			this->toolStripSerial->SuspendLayout();
			this->toolStripStartnStop->SuspendLayout();
			this->toolStripSerialCommand->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->contextConsoleOutput->SuspendLayout();
			this->ActualFilePanel->SuspendLayout();
			this->ActualPortPanel->SuspendLayout();
			this->ConnectedPanel->SuspendLayout();
			this->FirmWarePanel->SuspendLayout();
			this->firmWareVersionPanel->SuspendLayout();
			this->LineNumberPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStripTop
			// 
			this->menuStripTop->BackColor = System::Drawing::Color::Gray;
			this->menuStripTop->ContextMenuStrip = this->contextTools;
			this->menuStripTop->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->souborToolStripMenuItem, 
				this->zobrazeníToolStripMenuItem, this->nápovědaToolStripMenuItem});
			this->menuStripTop->Location = System::Drawing::Point(0, 0);
			this->menuStripTop->Name = L"menuStripTop";
			this->menuStripTop->ShowItemToolTips = true;
			this->menuStripTop->Size = System::Drawing::Size(784, 24);
			this->menuStripTop->TabIndex = 0;
			this->menuStripTop->Text = L"menuStrip";
			// 
			// contextTools
			// 
			this->contextTools->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->panelyNástrojůToolStripMenuItem1, 
				this->toolStripSeparator3, this->připojeníToolStripMenuItem1, this->kompilaceToolStripMenuItem, this->ovládáníArduinaToolStripMenuItem1, 
				this->serialPříkazyToolStripMenuItem});
			this->contextTools->Name = L"contextTools";
			this->contextTools->Size = System::Drawing::Size(167, 120);
			// 
			// panelyNástrojůToolStripMenuItem1
			// 
			this->panelyNástrojůToolStripMenuItem1->Name = L"panelyNástrojůToolStripMenuItem1";
			this->panelyNástrojůToolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->panelyNástrojůToolStripMenuItem1->Text = L"Panely nástrojů";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(163, 6);
			// 
			// připojeníToolStripMenuItem1
			// 
			this->připojeníToolStripMenuItem1->Checked = true;
			this->připojeníToolStripMenuItem1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->připojeníToolStripMenuItem1->Name = L"připojeníToolStripMenuItem1";
			this->připojeníToolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->připojeníToolStripMenuItem1->Text = L"Připojení";
			this->připojeníToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWin::toolStripSerialVisible);
			// 
			// kompilaceToolStripMenuItem
			// 
			this->kompilaceToolStripMenuItem->Checked = true;
			this->kompilaceToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->kompilaceToolStripMenuItem->Name = L"kompilaceToolStripMenuItem";
			this->kompilaceToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->kompilaceToolStripMenuItem->Text = L"Kompilace";
			this->kompilaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::toolStripCodeVisible);
			// 
			// ovládáníArduinaToolStripMenuItem1
			// 
			this->ovládáníArduinaToolStripMenuItem1->Checked = true;
			this->ovládáníArduinaToolStripMenuItem1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ovládáníArduinaToolStripMenuItem1->Name = L"ovládáníArduinaToolStripMenuItem1";
			this->ovládáníArduinaToolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->ovládáníArduinaToolStripMenuItem1->Text = L"Ovládání Arduina";
			this->ovládáníArduinaToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWin::ovládáníArduinaToolStripMenuItem_Click);
			// 
			// serialPříkazyToolStripMenuItem
			// 
			this->serialPříkazyToolStripMenuItem->Name = L"serialPříkazyToolStripMenuItem";
			this->serialPříkazyToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->serialPříkazyToolStripMenuItem->Text = L"Serial příkazy";
			this->serialPříkazyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::toolStripSerialCommandVisible);
			// 
			// souborToolStripMenuItem
			// 
			this->souborToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->novýToolStripMenuItem, 
				this->otevřítToolStripMenuItem, this->uložitToolStripMenuItem, this->uložitJakoToolStripMenuItem, this->lastOpenToolStripMenuItem, 
				this->toolStripSeparator2, this->zavřítToolStripMenuItem});
			this->souborToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->souborToolStripMenuItem->Name = L"souborToolStripMenuItem";
			this->souborToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->souborToolStripMenuItem->Text = L"Soubor";
			this->souborToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::LastOpenRefresh);
			// 
			// novýToolStripMenuItem
			// 
			this->novýToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"novýToolStripMenuItem.Image")));
			this->novýToolStripMenuItem->Name = L"novýToolStripMenuItem";
			this->novýToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->novýToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->novýToolStripMenuItem->Text = L"Nový";
			this->novýToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::NewFile);
			// 
			// otevřítToolStripMenuItem
			// 
			this->otevřítToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"otevřítToolStripMenuItem.Image")));
			this->otevřítToolStripMenuItem->Name = L"otevřítToolStripMenuItem";
			this->otevřítToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->otevřítToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->otevřítToolStripMenuItem->Text = L"Otevřít";
			this->otevřítToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::OpenFileClick);
			// 
			// uložitToolStripMenuItem
			// 
			this->uložitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"uložitToolStripMenuItem.Image")));
			this->uložitToolStripMenuItem->Name = L"uložitToolStripMenuItem";
			this->uložitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->uložitToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->uložitToolStripMenuItem->Text = L"Uložit";
			this->uložitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::SaveFile);
			// 
			// uložitJakoToolStripMenuItem
			// 
			this->uložitJakoToolStripMenuItem->Name = L"uložitJakoToolStripMenuItem";
			this->uložitJakoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->uložitJakoToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->uložitJakoToolStripMenuItem->Text = L"Uložit jako";
			this->uložitJakoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::SaveFileAs);
			// 
			// lastOpenToolStripMenuItem
			// 
			this->lastOpenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->žádnéPosledníSouboryToolStripMenuItem});
			this->lastOpenToolStripMenuItem->Name = L"lastOpenToolStripMenuItem";
			this->lastOpenToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->lastOpenToolStripMenuItem->Text = L"Poslední otevřené";
			// 
			// žádnéPosledníSouboryToolStripMenuItem
			// 
			this->žádnéPosledníSouboryToolStripMenuItem->Enabled = false;
			this->žádnéPosledníSouboryToolStripMenuItem->Name = L"žádnéPosledníSouboryToolStripMenuItem";
			this->žádnéPosledníSouboryToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->žádnéPosledníSouboryToolStripMenuItem->Text = L"Žádné poslední soubory";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(198, 6);
			// 
			// zavřítToolStripMenuItem
			// 
			this->zavřítToolStripMenuItem->Name = L"zavřítToolStripMenuItem";
			this->zavřítToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->zavřítToolStripMenuItem->Size = System::Drawing::Size(201, 22);
			this->zavřítToolStripMenuItem->Text = L"Zavřít";
			this->zavřítToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::CloseApp);
			// 
			// zobrazeníToolStripMenuItem
			// 
			this->zobrazeníToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->informačníPanelToolStripMenuItem, 
				this->pracovníPlochaToolStripMenuItem, this->panelyNástrojůToolStripMenuItem});
			this->zobrazeníToolStripMenuItem->Name = L"zobrazeníToolStripMenuItem";
			this->zobrazeníToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->zobrazeníToolStripMenuItem->Text = L"Zobrazení";
			// 
			// informačníPanelToolStripMenuItem
			// 
			this->informačníPanelToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->inverzeBarevToolStripMenuItem});
			this->informačníPanelToolStripMenuItem->Name = L"informačníPanelToolStripMenuItem";
			this->informačníPanelToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->informačníPanelToolStripMenuItem->Text = L"Informační panel";
			// 
			// inverzeBarevToolStripMenuItem
			// 
			this->inverzeBarevToolStripMenuItem->Name = L"inverzeBarevToolStripMenuItem";
			this->inverzeBarevToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->inverzeBarevToolStripMenuItem->Text = L"Inverze barev";
			this->inverzeBarevToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::inverzeBarevOutput);
			// 
			// pracovníPlochaToolStripMenuItem
			// 
			this->pracovníPlochaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->inverzeBarevToolStripMenuItem1});
			this->pracovníPlochaToolStripMenuItem->Name = L"pracovníPlochaToolStripMenuItem";
			this->pracovníPlochaToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->pracovníPlochaToolStripMenuItem->Text = L"Pracovní plocha";
			// 
			// inverzeBarevToolStripMenuItem1
			// 
			this->inverzeBarevToolStripMenuItem1->Name = L"inverzeBarevToolStripMenuItem1";
			this->inverzeBarevToolStripMenuItem1->Size = System::Drawing::Size(143, 22);
			this->inverzeBarevToolStripMenuItem1->Text = L"Inverze barev";
			this->inverzeBarevToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWin::inverzeBarevCommandBox);
			// 
			// panelyNástrojůToolStripMenuItem
			// 
			this->panelyNástrojůToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->připojeníToolStripMenuItem, 
				this->kompilaceToolStripMenuItem1, this->ovládáníArduinaToolStripMenuItem, this->serialPříkazyToolStripMenuItem1});
			this->panelyNástrojůToolStripMenuItem->Name = L"panelyNástrojůToolStripMenuItem";
			this->panelyNástrojůToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->panelyNástrojůToolStripMenuItem->Text = L"Panely nástrojů";
			// 
			// připojeníToolStripMenuItem
			// 
			this->připojeníToolStripMenuItem->Checked = true;
			this->připojeníToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->připojeníToolStripMenuItem->Name = L"připojeníToolStripMenuItem";
			this->připojeníToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->připojeníToolStripMenuItem->Text = L"Připojení";
			this->připojeníToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::toolStripSerialVisible);
			// 
			// kompilaceToolStripMenuItem1
			// 
			this->kompilaceToolStripMenuItem1->Checked = true;
			this->kompilaceToolStripMenuItem1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->kompilaceToolStripMenuItem1->Name = L"kompilaceToolStripMenuItem1";
			this->kompilaceToolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->kompilaceToolStripMenuItem1->Text = L"Kompilace";
			this->kompilaceToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWin::toolStripCodeVisible);
			// 
			// ovládáníArduinaToolStripMenuItem
			// 
			this->ovládáníArduinaToolStripMenuItem->Checked = true;
			this->ovládáníArduinaToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ovládáníArduinaToolStripMenuItem->Name = L"ovládáníArduinaToolStripMenuItem";
			this->ovládáníArduinaToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ovládáníArduinaToolStripMenuItem->Text = L"Ovládání Arduina";
			this->ovládáníArduinaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::ovládáníArduinaToolStripMenuItem_Click);
			// 
			// serialPříkazyToolStripMenuItem1
			// 
			this->serialPříkazyToolStripMenuItem1->Name = L"serialPříkazyToolStripMenuItem1";
			this->serialPříkazyToolStripMenuItem1->Size = System::Drawing::Size(166, 22);
			this->serialPříkazyToolStripMenuItem1->Text = L"Serial příkazy";
			this->serialPříkazyToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWin::toolStripSerialCommandVisible);
			// 
			// nápovědaToolStripMenuItem
			// 
			this->nápovědaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->rozvrženíKloubůToolStripMenuItem, 
				this->toolStripSeparator4, this->oProgramuToolStripMenuItem, this->stránkyAplikaceToolStripMenuItem});
			this->nápovědaToolStripMenuItem->Name = L"nápovědaToolStripMenuItem";
			this->nápovědaToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->nápovědaToolStripMenuItem->Text = L"Nápověda";
			// 
			// rozvrženíKloubůToolStripMenuItem
			// 
			this->rozvrženíKloubůToolStripMenuItem->Enabled = false;
			this->rozvrženíKloubůToolStripMenuItem->Name = L"rozvrženíKloubůToolStripMenuItem";
			this->rozvrženíKloubůToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->rozvrženíKloubůToolStripMenuItem->Text = L"Rozvržení kloubů";
			this->rozvrženíKloubůToolStripMenuItem->ToolTipText = L"Schéma s rozveržením kloubů";
			this->rozvrženíKloubůToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::rozvrženíKloubůToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(161, 6);
			// 
			// oProgramuToolStripMenuItem
			// 
			this->oProgramuToolStripMenuItem->Name = L"oProgramuToolStripMenuItem";
			this->oProgramuToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->oProgramuToolStripMenuItem->Text = L"O programu";
			this->oProgramuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::AboutClick);
			// 
			// stránkyAplikaceToolStripMenuItem
			// 
			this->stránkyAplikaceToolStripMenuItem->Name = L"stránkyAplikaceToolStripMenuItem";
			this->stránkyAplikaceToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->stránkyAplikaceToolStripMenuItem->Text = L"Stránky aplikace";
			this->stránkyAplikaceToolStripMenuItem->ToolTipText = L"Stránky aplikace s informacemi a možností stažení aktualizace";
			this->stránkyAplikaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::stránkyAplikaceToolStripMenuItem_Click);
			// 
			// statusStripBotttom
			// 
			this->statusStripBotttom->AutoSize = false;
			this->statusStripBotttom->Location = System::Drawing::Point(0, 413);
			this->statusStripBotttom->Name = L"statusStripBotttom";
			this->statusStripBotttom->Size = System::Drawing::Size(784, 47);
			this->statusStripBotttom->TabIndex = 1;
			this->statusStripBotttom->Text = L"statusStrip";
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->tabControlMode);
			this->toolStripContainer1->ContentPanel->Margin = System::Windows::Forms::Padding(0);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(784, 179);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Margin = System::Windows::Forms::Padding(0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(784, 279);
			this->toolStripContainer1->TabIndex = 2;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->ContextMenuStrip = this->contextTools;
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip1);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStripCode);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStripSerial);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStripStartnStop);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStripSerialCommand);
			// 
			// tabControlMode
			// 
			this->tabControlMode->Controls->Add(this->tabOnlineMode);
			this->tabControlMode->Controls->Add(this->tabTextMode);
			this->tabControlMode->Controls->Add(this->tabGraphicMode);
			this->tabControlMode->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlMode->Location = System::Drawing::Point(0, 0);
			this->tabControlMode->Margin = System::Windows::Forms::Padding(0);
			this->tabControlMode->Name = L"tabControlMode";
			this->tabControlMode->SelectedIndex = 0;
			this->tabControlMode->Size = System::Drawing::Size(784, 179);
			this->tabControlMode->TabIndex = 0;
			// 
			// tabOnlineMode
			// 
			this->tabOnlineMode->Controls->Add(this->flowLayoutPanel1);
			this->tabOnlineMode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->tabOnlineMode->Location = System::Drawing::Point(4, 22);
			this->tabOnlineMode->Margin = System::Windows::Forms::Padding(0);
			this->tabOnlineMode->Name = L"tabOnlineMode";
			this->tabOnlineMode->Padding = System::Windows::Forms::Padding(1);
			this->tabOnlineMode->Size = System::Drawing::Size(776, 153);
			this->tabOnlineMode->TabIndex = 0;
			this->tabOnlineMode->Text = L"Online režim";
			this->tabOnlineMode->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo1);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo2);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo3);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo4);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo5);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo6);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockServo7);
			this->flowLayoutPanel1->Controls->Add(this->onlineBlockSpeed);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(1, 1);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(774, 151);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// onlineBlockServo1
			// 
			this->onlineBlockServo1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo1->Location = System::Drawing::Point(3, 3);
			this->onlineBlockServo1->Name = L"onlineBlockServo1";
			this->onlineBlockServo1->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo1->TabIndex = 0;
			// 
			// onlineBlockServo2
			// 
			this->onlineBlockServo2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo2->Location = System::Drawing::Point(177, 3);
			this->onlineBlockServo2->Name = L"onlineBlockServo2";
			this->onlineBlockServo2->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo2->TabIndex = 1;
			// 
			// onlineBlockServo3
			// 
			this->onlineBlockServo3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo3->Location = System::Drawing::Point(351, 3);
			this->onlineBlockServo3->Name = L"onlineBlockServo3";
			this->onlineBlockServo3->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo3->TabIndex = 2;
			// 
			// onlineBlockServo4
			// 
			this->onlineBlockServo4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo4->Location = System::Drawing::Point(525, 3);
			this->onlineBlockServo4->Name = L"onlineBlockServo4";
			this->onlineBlockServo4->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo4->TabIndex = 3;
			// 
			// onlineBlockServo5
			// 
			this->onlineBlockServo5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo5->Location = System::Drawing::Point(3, 177);
			this->onlineBlockServo5->Name = L"onlineBlockServo5";
			this->onlineBlockServo5->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo5->TabIndex = 4;
			// 
			// onlineBlockServo6
			// 
			this->onlineBlockServo6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo6->Location = System::Drawing::Point(177, 177);
			this->onlineBlockServo6->Name = L"onlineBlockServo6";
			this->onlineBlockServo6->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo6->TabIndex = 5;
			// 
			// onlineBlockServo7
			// 
			this->onlineBlockServo7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockServo7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockServo7->Location = System::Drawing::Point(351, 177);
			this->onlineBlockServo7->Name = L"onlineBlockServo7";
			this->onlineBlockServo7->Size = System::Drawing::Size(168, 168);
			this->onlineBlockServo7->TabIndex = 6;
			// 
			// onlineBlockSpeed
			// 
			this->onlineBlockSpeed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(61)), 
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->onlineBlockSpeed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->onlineBlockSpeed->Location = System::Drawing::Point(525, 177);
			this->onlineBlockSpeed->Name = L"onlineBlockSpeed";
			this->onlineBlockSpeed->Size = System::Drawing::Size(168, 168);
			this->onlineBlockSpeed->TabIndex = 7;
			// 
			// tabTextMode
			// 
			this->tabTextMode->AutoScroll = true;
			this->tabTextMode->Controls->Add(this->CommandBox);
			this->tabTextMode->Location = System::Drawing::Point(4, 22);
			this->tabTextMode->Margin = System::Windows::Forms::Padding(0);
			this->tabTextMode->Name = L"tabTextMode";
			this->tabTextMode->Size = System::Drawing::Size(776, 153);
			this->tabTextMode->TabIndex = 1;
			this->tabTextMode->Text = L"Textový režim";
			this->tabTextMode->UseVisualStyleBackColor = true;
			// 
			// CommandBox
			// 
			this->CommandBox->ContextMenuStrip = this->contextMenuStrip1;
			this->CommandBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CommandBox->Enabled = false;
			this->CommandBox->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->CommandBox->Location = System::Drawing::Point(0, 0);
			this->CommandBox->Margin = System::Windows::Forms::Padding(0);
			this->CommandBox->Multiline = true;
			this->CommandBox->Name = L"CommandBox";
			this->CommandBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->CommandBox->Size = System::Drawing::Size(776, 153);
			this->CommandBox->TabIndex = 0;
			this->CommandBox->Text = L"Založte nový projekt nebo otevřete již existující.";
			this->CommandBox->WordWrap = false;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->inverzeBarevToolStripMenuItem2, 
				this->fontToolStripMenuItem, this->velikostToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(144, 70);
			// 
			// inverzeBarevToolStripMenuItem2
			// 
			this->inverzeBarevToolStripMenuItem2->Name = L"inverzeBarevToolStripMenuItem2";
			this->inverzeBarevToolStripMenuItem2->Size = System::Drawing::Size(143, 22);
			this->inverzeBarevToolStripMenuItem2->Text = L"Inverze barev";
			this->inverzeBarevToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWin::inverzeBarevCommandBox);
			// 
			// fontToolStripMenuItem
			// 
			this->fontToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->arialToolStripMenuItem, 
				this->courierNewToolStripMenuItem, this->lucidaConsoleToolStripMenuItem, this->microsoftSansSerifToolStripMenuItem});
			this->fontToolStripMenuItem->Name = L"fontToolStripMenuItem";
			this->fontToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->fontToolStripMenuItem->Text = L"Font";
			// 
			// arialToolStripMenuItem
			// 
			this->arialToolStripMenuItem->Name = L"arialToolStripMenuItem";
			this->arialToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->arialToolStripMenuItem->Text = L"Arial";
			this->arialToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::fontArialCommandBox);
			// 
			// courierNewToolStripMenuItem
			// 
			this->courierNewToolStripMenuItem->Name = L"courierNewToolStripMenuItem";
			this->courierNewToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->courierNewToolStripMenuItem->Text = L"Courier New";
			this->courierNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::fontCourierCommandBox);
			// 
			// lucidaConsoleToolStripMenuItem
			// 
			this->lucidaConsoleToolStripMenuItem->Checked = true;
			this->lucidaConsoleToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->lucidaConsoleToolStripMenuItem->Name = L"lucidaConsoleToolStripMenuItem";
			this->lucidaConsoleToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->lucidaConsoleToolStripMenuItem->Text = L"Lucida Console";
			this->lucidaConsoleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::fontLucidaCommandBox);
			// 
			// microsoftSansSerifToolStripMenuItem
			// 
			this->microsoftSansSerifToolStripMenuItem->Name = L"microsoftSansSerifToolStripMenuItem";
			this->microsoftSansSerifToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->microsoftSansSerifToolStripMenuItem->Text = L"Microsoft Sans Serif";
			this->microsoftSansSerifToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::fontMSCommandBox);
			// 
			// velikostToolStripMenuItem
			// 
			this->velikostToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->size8toolStripMenuItem, 
				this->size9toolStripMenuItem, this->size10toolStripMenuItem, this->size11toolStripMenuItem, this->size13toolStripMenuItem});
			this->velikostToolStripMenuItem->Name = L"velikostToolStripMenuItem";
			this->velikostToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->velikostToolStripMenuItem->Text = L"Velikost";
			// 
			// size8toolStripMenuItem
			// 
			this->size8toolStripMenuItem->Checked = true;
			this->size8toolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->size8toolStripMenuItem->Name = L"size8toolStripMenuItem";
			this->size8toolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->size8toolStripMenuItem->Text = L"8";
			this->size8toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::size8CommandBox);
			// 
			// size9toolStripMenuItem
			// 
			this->size9toolStripMenuItem->Name = L"size9toolStripMenuItem";
			this->size9toolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->size9toolStripMenuItem->Text = L"9";
			this->size9toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::size9CommandBox);
			// 
			// size10toolStripMenuItem
			// 
			this->size10toolStripMenuItem->Name = L"size10toolStripMenuItem";
			this->size10toolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->size10toolStripMenuItem->Text = L"10";
			this->size10toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::size10CommandBox);
			// 
			// size11toolStripMenuItem
			// 
			this->size11toolStripMenuItem->Name = L"size11toolStripMenuItem";
			this->size11toolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->size11toolStripMenuItem->Text = L"11";
			this->size11toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::size11CommandBox);
			// 
			// size13toolStripMenuItem
			// 
			this->size13toolStripMenuItem->Name = L"size13toolStripMenuItem";
			this->size13toolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->size13toolStripMenuItem->Text = L"13";
			this->size13toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::size13CommandBox);
			// 
			// tabGraphicMode
			// 
			this->tabGraphicMode->Controls->Add(this->splitContainer2);
			this->tabGraphicMode->Location = System::Drawing::Point(4, 22);
			this->tabGraphicMode->Name = L"tabGraphicMode";
			this->tabGraphicMode->Padding = System::Windows::Forms::Padding(3);
			this->tabGraphicMode->Size = System::Drawing::Size(776, 153);
			this->tabGraphicMode->TabIndex = 2;
			this->tabGraphicMode->Text = L"Grafický režim";
			this->tabGraphicMode->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->flowLayoutToolPanel);
			this->splitContainer2->Panel1MinSize = 77;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(770, 147);
			this->splitContainer2->SplitterDistance = 77;
			this->splitContainer2->TabIndex = 0;
			// 
			// flowLayoutToolPanel
			// 
			this->flowLayoutToolPanel->AutoScroll = true;
			this->flowLayoutToolPanel->BackColor = System::Drawing::SystemColors::Control;
			this->flowLayoutToolPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutToolPanel->Controls->Add(this->BaseAroundBlock);
			this->flowLayoutToolPanel->Controls->Add(this->BaseUpDownBlock);
			this->flowLayoutToolPanel->Controls->Add(this->HandleUpDownBlock);
			this->flowLayoutToolPanel->Controls->Add(this->HandleRotateBlock);
			this->flowLayoutToolPanel->Controls->Add(this->JawUpDownBlock);
			this->flowLayoutToolPanel->Controls->Add(this->JawRotateBlock);
			this->flowLayoutToolPanel->Controls->Add(this->JawOpenCloseBlock);
			this->flowLayoutToolPanel->Controls->Add(this->SpeedBlock);
			this->flowLayoutToolPanel->Controls->Add(this->DelayBlock);
			this->flowLayoutToolPanel->Controls->Add(this->MoveLeftBlock);
			this->flowLayoutToolPanel->Controls->Add(this->MoveRightBlock);
			this->flowLayoutToolPanel->Controls->Add(this->DeleteBlock);
			this->flowLayoutToolPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutToolPanel->Location = System::Drawing::Point(0, 0);
			this->flowLayoutToolPanel->Name = L"flowLayoutToolPanel";
			this->flowLayoutToolPanel->Size = System::Drawing::Size(770, 77);
			this->flowLayoutToolPanel->TabIndex = 0;
			// 
			// BaseAroundBlock
			// 
			this->BaseAroundBlock->BackColor = System::Drawing::Color::DarkGray;
			this->BaseAroundBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BaseAroundBlock.BackgroundImage")));
			this->BaseAroundBlock->Location = System::Drawing::Point(3, 2);
			this->BaseAroundBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->BaseAroundBlock->Name = L"BaseAroundBlock";
			this->BaseAroundBlock->Size = System::Drawing::Size(70, 70);
			this->BaseAroundBlock->TabIndex = 0;
			this->BaseAroundBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->BaseAroundBlock, L"ACTUATOR_1 - Otočení v základně");
			this->BaseAroundBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->BaseAroundBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::BaseAroundBlock_MouseMove);
			// 
			// BaseUpDownBlock
			// 
			this->BaseUpDownBlock->BackColor = System::Drawing::Color::DarkOrange;
			this->BaseUpDownBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BaseUpDownBlock.BackgroundImage")));
			this->BaseUpDownBlock->Location = System::Drawing::Point(76, 2);
			this->BaseUpDownBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->BaseUpDownBlock->Name = L"BaseUpDownBlock";
			this->BaseUpDownBlock->Size = System::Drawing::Size(70, 70);
			this->BaseUpDownBlock->TabIndex = 4;
			this->BaseUpDownBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->BaseUpDownBlock, L"ACTUATOR_2 - Kloub zdvihu u základny");
			this->BaseUpDownBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->BaseUpDownBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::BaseUpDownBlock_MouseMove);
			// 
			// HandleUpDownBlock
			// 
			this->HandleUpDownBlock->BackColor = System::Drawing::Color::Goldenrod;
			this->HandleUpDownBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"HandleUpDownBlock.BackgroundImage")));
			this->HandleUpDownBlock->Location = System::Drawing::Point(149, 2);
			this->HandleUpDownBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->HandleUpDownBlock->Name = L"HandleUpDownBlock";
			this->HandleUpDownBlock->Size = System::Drawing::Size(70, 70);
			this->HandleUpDownBlock->TabIndex = 5;
			this->HandleUpDownBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->HandleUpDownBlock, L"ACTUATOR_3 - Kloub zdvihu v ramenu");
			this->HandleUpDownBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->HandleUpDownBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::HandleUpDownBlock_MouseMove);
			// 
			// HandleRotateBlock
			// 
			this->HandleRotateBlock->BackColor = System::Drawing::Color::YellowGreen;
			this->HandleRotateBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"HandleRotateBlock.BackgroundImage")));
			this->HandleRotateBlock->Location = System::Drawing::Point(222, 2);
			this->HandleRotateBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->HandleRotateBlock->Name = L"HandleRotateBlock";
			this->HandleRotateBlock->Size = System::Drawing::Size(70, 70);
			this->HandleRotateBlock->TabIndex = 6;
			this->HandleRotateBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->HandleRotateBlock, L"ACTUATOR_4 - Otočení v remenu");
			this->HandleRotateBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->HandleRotateBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::HandleRotateBlock_MouseMove);
			// 
			// JawUpDownBlock
			// 
			this->JawUpDownBlock->BackColor = System::Drawing::Color::Turquoise;
			this->JawUpDownBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"JawUpDownBlock.BackgroundImage")));
			this->JawUpDownBlock->Location = System::Drawing::Point(295, 2);
			this->JawUpDownBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->JawUpDownBlock->Name = L"JawUpDownBlock";
			this->JawUpDownBlock->Size = System::Drawing::Size(70, 70);
			this->JawUpDownBlock->TabIndex = 7;
			this->JawUpDownBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->JawUpDownBlock, L"ACTUATOR_5 - Kloub zdvihu u čelisti");
			this->JawUpDownBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->JawUpDownBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::JawUpDownBlock_MouseMove);
			// 
			// JawRotateBlock
			// 
			this->JawRotateBlock->BackColor = System::Drawing::Color::SteelBlue;
			this->JawRotateBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"JawRotateBlock.BackgroundImage")));
			this->JawRotateBlock->Location = System::Drawing::Point(368, 2);
			this->JawRotateBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->JawRotateBlock->Name = L"JawRotateBlock";
			this->JawRotateBlock->Size = System::Drawing::Size(70, 70);
			this->JawRotateBlock->TabIndex = 8;
			this->JawRotateBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->JawRotateBlock, L"ACTUATOR_6 - Kloub otočení u čelisti");
			this->JawRotateBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->JawRotateBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::JawRotateBlock_MouseMove);
			// 
			// JawOpenCloseBlock
			// 
			this->JawOpenCloseBlock->BackColor = System::Drawing::Color::Violet;
			this->JawOpenCloseBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"JawOpenCloseBlock.BackgroundImage")));
			this->JawOpenCloseBlock->Location = System::Drawing::Point(441, 2);
			this->JawOpenCloseBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->JawOpenCloseBlock->Name = L"JawOpenCloseBlock";
			this->JawOpenCloseBlock->Size = System::Drawing::Size(70, 70);
			this->JawOpenCloseBlock->TabIndex = 9;
			this->JawOpenCloseBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->JawOpenCloseBlock, L"ACTUATOR_7 - Otevření a zavření čelisti");
			this->JawOpenCloseBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->JawOpenCloseBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::JawOpenCloseBlock_MouseMove);
			// 
			// SpeedBlock
			// 
			this->SpeedBlock->BackColor = System::Drawing::Color::Yellow;
			this->SpeedBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SpeedBlock.BackgroundImage")));
			this->SpeedBlock->Location = System::Drawing::Point(514, 2);
			this->SpeedBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->SpeedBlock->Name = L"SpeedBlock";
			this->SpeedBlock->Size = System::Drawing::Size(70, 70);
			this->SpeedBlock->TabIndex = 10;
			this->SpeedBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->SpeedBlock, L"SPEED_ - Nastavení rychlosti pohybu");
			this->SpeedBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->SpeedBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::SpeedBlock_MouseMove);
			// 
			// DelayBlock
			// 
			this->DelayBlock->BackColor = System::Drawing::Color::Teal;
			this->DelayBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DelayBlock.BackgroundImage")));
			this->DelayBlock->Location = System::Drawing::Point(587, 2);
			this->DelayBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->DelayBlock->Name = L"DelayBlock";
			this->DelayBlock->Size = System::Drawing::Size(70, 70);
			this->DelayBlock->TabIndex = 11;
			this->DelayBlock->TabStop = false;
			this->ServoToolTip->SetToolTip(this->DelayBlock, L"DELAY_ - Pauza, čekání na další událost");
			this->DelayBlock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::AnyBlock_MouseDown);
			this->DelayBlock->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::DelayBlock_MouseMove);
			// 
			// MoveLeftBlock
			// 
			this->MoveLeftBlock->BackColor = System::Drawing::Color::LightBlue;
			this->MoveLeftBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MoveLeftBlock.BackgroundImage")));
			this->MoveLeftBlock->Location = System::Drawing::Point(660, 2);
			this->MoveLeftBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->MoveLeftBlock->Name = L"MoveLeftBlock";
			this->MoveLeftBlock->Size = System::Drawing::Size(70, 70);
			this->MoveLeftBlock->TabIndex = 2;
			this->MoveLeftBlock->TabStop = false;
			this->MoveLeftBlock->Click += gcnew System::EventHandler(this, &MainWin::MoveLeftBlock_Click);
			// 
			// MoveRightBlock
			// 
			this->MoveRightBlock->BackColor = System::Drawing::Color::LightBlue;
			this->MoveRightBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"MoveRightBlock.BackgroundImage")));
			this->MoveRightBlock->Location = System::Drawing::Point(3, 76);
			this->MoveRightBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->MoveRightBlock->Name = L"MoveRightBlock";
			this->MoveRightBlock->Size = System::Drawing::Size(70, 70);
			this->MoveRightBlock->TabIndex = 3;
			this->MoveRightBlock->TabStop = false;
			this->MoveRightBlock->Click += gcnew System::EventHandler(this, &MainWin::MoveRightBlock_Click);
			// 
			// DeleteBlock
			// 
			this->DeleteBlock->BackColor = System::Drawing::Color::LightBlue;
			this->DeleteBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DeleteBlock.BackgroundImage")));
			this->DeleteBlock->Location = System::Drawing::Point(76, 76);
			this->DeleteBlock->Margin = System::Windows::Forms::Padding(3, 2, 0, 2);
			this->DeleteBlock->Name = L"DeleteBlock";
			this->DeleteBlock->Size = System::Drawing::Size(70, 70);
			this->DeleteBlock->TabIndex = 1;
			this->DeleteBlock->TabStop = false;
			this->DeleteBlock->Click += gcnew System::EventHandler(this, &MainWin::DeleteBlock_Click);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer3->IsSplitterFixed = true;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->flowLayoutWorkSpace);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->GraphicOutput);
			this->splitContainer3->Panel2MinSize = 200;
			this->splitContainer3->Size = System::Drawing::Size(770, 66);
			this->splitContainer3->SplitterDistance = 566;
			this->splitContainer3->TabIndex = 1;
			// 
			// flowLayoutWorkSpace
			// 
			this->flowLayoutWorkSpace->AllowDrop = true;
			this->flowLayoutWorkSpace->AutoScroll = true;
			this->flowLayoutWorkSpace->BackColor = System::Drawing::Color::Gray;
			this->flowLayoutWorkSpace->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutWorkSpace->Controls->Add(this->beginBlock1);
			this->flowLayoutWorkSpace->Controls->Add(this->endBlock);
			this->flowLayoutWorkSpace->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutWorkSpace->Enabled = false;
			this->flowLayoutWorkSpace->Location = System::Drawing::Point(0, 0);
			this->flowLayoutWorkSpace->Name = L"flowLayoutWorkSpace";
			this->flowLayoutWorkSpace->Size = System::Drawing::Size(566, 66);
			this->flowLayoutWorkSpace->TabIndex = 0;
			this->flowLayoutWorkSpace->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainWin::flowLayoutWorkSpace_DragDrop);
			this->flowLayoutWorkSpace->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainWin::flowLayoutWorkSpace_DragEnter);
			this->flowLayoutWorkSpace->DragLeave += gcnew System::EventHandler(this, &MainWin::flowLayoutWorkSpace_DragLeave);
			// 
			// beginBlock1
			// 
			this->beginBlock1->BackColor = System::Drawing::Color::LightGray;
			this->beginBlock1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->beginBlock1->Location = System::Drawing::Point(3, 3);
			this->beginBlock1->Name = L"beginBlock1";
			this->beginBlock1->Size = System::Drawing::Size(148, 148);
			this->beginBlock1->TabIndex = 11;
			// 
			// endBlock
			// 
			this->endBlock->BackColor = System::Drawing::Color::LightGray;
			this->endBlock->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->endBlock->Location = System::Drawing::Point(157, 3);
			this->endBlock->Name = L"endBlock";
			this->endBlock->Size = System::Drawing::Size(148, 148);
			this->endBlock->TabIndex = 12;
			this->endBlock->LocationChanged += gcnew System::EventHandler(this, &MainWin::endBlock_LocationChanged);
			// 
			// GraphicOutput
			// 
			this->GraphicOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GraphicOutput->FormattingEnabled = true;
			this->GraphicOutput->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"begin ROBO;\r\n", L"end;"});
			this->GraphicOutput->Location = System::Drawing::Point(0, 0);
			this->GraphicOutput->Name = L"GraphicOutput";
			this->GraphicOutput->Size = System::Drawing::Size(200, 66);
			this->GraphicOutput->TabIndex = 0;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ContextMenuStrip = this->contextTools;
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->newToolStripButton, 
				this->openToolStripButton, this->saveToolStripButton, this->printToolStripButton, this->toolStripSeparator, this->cutToolStripButton, 
				this->copyToolStripButton, this->pasteToolStripButton, this->toolStripSeparator1, this->helpToolStripButton});
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(208, 25);
			this->toolStrip1->TabIndex = 0;
			// 
			// newToolStripButton
			// 
			this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripButton.Image")));
			this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripButton->Name = L"newToolStripButton";
			this->newToolStripButton->Size = System::Drawing::Size(23, 22);
			this->newToolStripButton->Text = L"&New";
			this->newToolStripButton->ToolTipText = L"Nový projekt";
			this->newToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::NewFile);
			// 
			// openToolStripButton
			// 
			this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripButton.Image")));
			this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripButton->Name = L"openToolStripButton";
			this->openToolStripButton->Size = System::Drawing::Size(23, 22);
			this->openToolStripButton->Text = L"&Open";
			this->openToolStripButton->ToolTipText = L"Otevřít";
			this->openToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::OpenFileClick);
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
			this->saveToolStripButton->Text = L"&Save";
			this->saveToolStripButton->ToolTipText = L"Uložit";
			this->saveToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::SaveFile);
			// 
			// printToolStripButton
			// 
			this->printToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->printToolStripButton->Enabled = false;
			this->printToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripButton.Image")));
			this->printToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->printToolStripButton->Name = L"printToolStripButton";
			this->printToolStripButton->Size = System::Drawing::Size(23, 22);
			this->printToolStripButton->Text = L"&Print";
			this->printToolStripButton->ToolTipText = L"Tisk";
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(6, 25);
			// 
			// cutToolStripButton
			// 
			this->cutToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->cutToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cutToolStripButton.Image")));
			this->cutToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cutToolStripButton->Name = L"cutToolStripButton";
			this->cutToolStripButton->Size = System::Drawing::Size(23, 22);
			this->cutToolStripButton->Text = L"C&ut";
			this->cutToolStripButton->ToolTipText = L"Vyjmout";
			this->cutToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::cutToolStripButton_Click);
			// 
			// copyToolStripButton
			// 
			this->copyToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->copyToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyToolStripButton.Image")));
			this->copyToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copyToolStripButton->Name = L"copyToolStripButton";
			this->copyToolStripButton->Size = System::Drawing::Size(23, 22);
			this->copyToolStripButton->Text = L"&Copy";
			this->copyToolStripButton->ToolTipText = L"Kopírovat";
			this->copyToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::copyToolStripButton_Click);
			// 
			// pasteToolStripButton
			// 
			this->pasteToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->pasteToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pasteToolStripButton.Image")));
			this->pasteToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pasteToolStripButton->Name = L"pasteToolStripButton";
			this->pasteToolStripButton->Size = System::Drawing::Size(23, 22);
			this->pasteToolStripButton->Text = L"&Paste";
			this->pasteToolStripButton->ToolTipText = L"Vložit";
			this->pasteToolStripButton->Click += gcnew System::EventHandler(this, &MainWin::pasteToolStripButton_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// helpToolStripButton
			// 
			this->helpToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->helpToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"helpToolStripButton.Image")));
			this->helpToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->helpToolStripButton->Name = L"helpToolStripButton";
			this->helpToolStripButton->Size = System::Drawing::Size(23, 22);
			this->helpToolStripButton->Text = L"He&lp";
			// 
			// toolStripCode
			// 
			this->toolStripCode->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStripCode->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripGrafToTextButton, 
				this->toolStripCheckCodeButton, this->toolStripTextToGrafButton, this->toolStripCompileButton});
			this->toolStripCode->Location = System::Drawing::Point(3, 25);
			this->toolStripCode->Name = L"toolStripCode";
			this->toolStripCode->Size = System::Drawing::Size(393, 25);
			this->toolStripCode->TabIndex = 2;
			// 
			// toolStripGrafToTextButton
			// 
			this->toolStripGrafToTextButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripGrafToTextButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripGrafToTextButton.Image")));
			this->toolStripGrafToTextButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripGrafToTextButton->Name = L"toolStripGrafToTextButton";
			this->toolStripGrafToTextButton->Size = System::Drawing::Size(92, 22);
			this->toolStripGrafToTextButton->Text = L"GRAF. -> TEXT.";
			this->toolStripGrafToTextButton->ToolTipText = L"Grafický režim -> Textový režim";
			this->toolStripGrafToTextButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripGraphToTextButton_Click);
			// 
			// toolStripCheckCodeButton
			// 
			this->toolStripCheckCodeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripCheckCodeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripCheckCodeButton.Image")));
			this->toolStripCheckCodeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripCheckCodeButton->Name = L"toolStripCheckCodeButton";
			this->toolStripCheckCodeButton->Size = System::Drawing::Size(79, 22);
			this->toolStripCheckCodeButton->Text = L"Zkontrolovat";
			this->toolStripCheckCodeButton->Click += gcnew System::EventHandler(this, &MainWin::CheckCode_Click);
			// 
			// toolStripTextToGrafButton
			// 
			this->toolStripTextToGrafButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripTextToGrafButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripTextToGrafButton.Image")));
			this->toolStripTextToGrafButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripTextToGrafButton->Name = L"toolStripTextToGrafButton";
			this->toolStripTextToGrafButton->Size = System::Drawing::Size(92, 22);
			this->toolStripTextToGrafButton->Text = L"TEXT. -> GRAF.";
			this->toolStripTextToGrafButton->ToolTipText = L"Textový režim -> Grafický režim";
			this->toolStripTextToGrafButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripTextToGrafButton_Click);
			// 
			// toolStripCompileButton
			// 
			this->toolStripCompileButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripCompileButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripCompileButton.Image")));
			this->toolStripCompileButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripCompileButton->Name = L"toolStripCompileButton";
			this->toolStripCompileButton->Size = System::Drawing::Size(118, 22);
			this->toolStripCompileButton->Text = L"Kompilovat a nahrát";
			this->toolStripCompileButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripCompileButton_Click);
			// 
			// toolStripSerial
			// 
			this->toolStripSerial->ContextMenuStrip = this->contextTools;
			this->toolStripSerial->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStripSerial->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripSerialDropDown, 
				this->toolStripRefreshButton, this->toolStripOpenPortButton, this->toolStripClosePortButton, this->toolStripInitButton});
			this->toolStripSerial->Location = System::Drawing::Point(3, 50);
			this->toolStripSerial->Name = L"toolStripSerial";
			this->toolStripSerial->Size = System::Drawing::Size(322, 25);
			this->toolStripSerial->TabIndex = 1;
			// 
			// toolStripSerialDropDown
			// 
			this->toolStripSerialDropDown->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripSerialDropDown->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->žádnéPortyToolStripMenuItem});
			this->toolStripSerialDropDown->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripSerialDropDown.Image")));
			this->toolStripSerialDropDown->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSerialDropDown->Name = L"toolStripSerialDropDown";
			this->toolStripSerialDropDown->Size = System::Drawing::Size(48, 22);
			this->toolStripSerialDropDown->Text = L"Porty";
			// 
			// žádnéPortyToolStripMenuItem
			// 
			this->žádnéPortyToolStripMenuItem->Name = L"žádnéPortyToolStripMenuItem";
			this->žádnéPortyToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->žádnéPortyToolStripMenuItem->Text = L"Žádné porty";
			// 
			// toolStripRefreshButton
			// 
			this->toolStripRefreshButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripRefreshButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripRefreshButton.Image")));
			this->toolStripRefreshButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripRefreshButton->Name = L"toolStripRefreshButton";
			this->toolStripRefreshButton->Size = System::Drawing::Size(76, 22);
			this->toolStripRefreshButton->Text = L"Aktualizovat";
			this->toolStripRefreshButton->Click += gcnew System::EventHandler(this, &MainWin::RefreshPortsClick);
			// 
			// toolStripOpenPortButton
			// 
			this->toolStripOpenPortButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripOpenPortButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripOpenPortButton.Image")));
			this->toolStripOpenPortButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripOpenPortButton->Name = L"toolStripOpenPortButton";
			this->toolStripOpenPortButton->Size = System::Drawing::Size(47, 22);
			this->toolStripOpenPortButton->Text = L"Otevřít";
			this->toolStripOpenPortButton->Click += gcnew System::EventHandler(this, &MainWin::OpenPortClick);
			// 
			// toolStripClosePortButton
			// 
			this->toolStripClosePortButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripClosePortButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripClosePortButton.Image")));
			this->toolStripClosePortButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripClosePortButton->Name = L"toolStripClosePortButton";
			this->toolStripClosePortButton->Size = System::Drawing::Size(41, 22);
			this->toolStripClosePortButton->Text = L"Zavřít";
			this->toolStripClosePortButton->Click += gcnew System::EventHandler(this, &MainWin::ClosePortClick);
			// 
			// toolStripInitButton
			// 
			this->toolStripInitButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripInitButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripInitButton.Image")));
			this->toolStripInitButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripInitButton->Name = L"toolStripInitButton";
			this->toolStripInitButton->Size = System::Drawing::Size(98, 22);
			this->toolStripInitButton->Text = L"Inicializovat port";
			this->toolStripInitButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripInitButton_Click);
			// 
			// toolStripStartnStop
			// 
			this->toolStripStartnStop->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStripStartnStop->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStartButton, 
				this->toolStripStopButton});
			this->toolStripStartnStop->Location = System::Drawing::Point(3, 75);
			this->toolStripStartnStop->Name = L"toolStripStartnStop";
			this->toolStripStartnStop->Size = System::Drawing::Size(82, 25);
			this->toolStripStartnStop->TabIndex = 3;
			// 
			// toolStripStartButton
			// 
			this->toolStripStartButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStartButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripStartButton.Image")));
			this->toolStripStartButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripStartButton->Name = L"toolStripStartButton";
			this->toolStripStartButton->Size = System::Drawing::Size(35, 22);
			this->toolStripStartButton->Text = L"Start";
			this->toolStripStartButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripStartButton_Click);
			// 
			// toolStripStopButton
			// 
			this->toolStripStopButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStopButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripStopButton.Image")));
			this->toolStripStopButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripStopButton->Name = L"toolStripStopButton";
			this->toolStripStopButton->Size = System::Drawing::Size(35, 22);
			this->toolStripStopButton->Text = L"Stop";
			this->toolStripStopButton->Click += gcnew System::EventHandler(this, &MainWin::toolStripStopButton_Click);
			// 
			// toolStripSerialCommand
			// 
			this->toolStripSerialCommand->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStripSerialCommand->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripCommandLine, 
				this->toolStripPoslatCommand});
			this->toolStripSerialCommand->Location = System::Drawing::Point(348, 75);
			this->toolStripSerialCommand->Name = L"toolStripSerialCommand";
			this->toolStripSerialCommand->Size = System::Drawing::Size(157, 25);
			this->toolStripSerialCommand->TabIndex = 1;
			this->toolStripSerialCommand->Visible = false;
			// 
			// toolStripCommandLine
			// 
			this->toolStripCommandLine->Name = L"toolStripCommandLine";
			this->toolStripCommandLine->Size = System::Drawing::Size(100, 25);
			this->toolStripCommandLine->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainWin::CommandPrompt_KeyDown);
			// 
			// toolStripPoslatCommand
			// 
			this->toolStripPoslatCommand->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripPoslatCommand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripPoslatCommand.Image")));
			this->toolStripPoslatCommand->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripPoslatCommand->Name = L"toolStripPoslatCommand";
			this->toolStripPoslatCommand->Size = System::Drawing::Size(43, 22);
			this->toolStripPoslatCommand->Text = L"Poslat";
			this->toolStripPoslatCommand->Click += gcnew System::EventHandler(this, &MainWin::CommandPrompt_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->toolStripContainer1);
			this->splitContainer1->Panel1MinSize = 72;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->ConsoleOutput);
			this->splitContainer1->Panel2MinSize = 27;
			this->splitContainer1->Size = System::Drawing::Size(784, 389);
			this->splitContainer1->SplitterDistance = 279;
			this->splitContainer1->TabIndex = 3;
			// 
			// ConsoleOutput
			// 
			this->ConsoleOutput->ContextMenuStrip = this->contextConsoleOutput;
			this->ConsoleOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ConsoleOutput->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->ConsoleOutput->FormattingEnabled = true;
			this->ConsoleOutput->ItemHeight = 11;
			this->ConsoleOutput->Location = System::Drawing::Point(0, 0);
			this->ConsoleOutput->Margin = System::Windows::Forms::Padding(0);
			this->ConsoleOutput->Name = L"ConsoleOutput";
			this->ConsoleOutput->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->ConsoleOutput->Size = System::Drawing::Size(784, 106);
			this->ConsoleOutput->TabIndex = 0;
			// 
			// contextConsoleOutput
			// 
			this->contextConsoleOutput->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->inverzeBarevToolStripMenuItem3, 
				this->vyčistitOknoToolStripMenuItem});
			this->contextConsoleOutput->Name = L"contextMenuStrip2";
			this->contextConsoleOutput->Size = System::Drawing::Size(144, 48);
			// 
			// inverzeBarevToolStripMenuItem3
			// 
			this->inverzeBarevToolStripMenuItem3->Name = L"inverzeBarevToolStripMenuItem3";
			this->inverzeBarevToolStripMenuItem3->Size = System::Drawing::Size(143, 22);
			this->inverzeBarevToolStripMenuItem3->Text = L"Inverze barev";
			this->inverzeBarevToolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainWin::inverzeBarevOutput);
			// 
			// vyčistitOknoToolStripMenuItem
			// 
			this->vyčistitOknoToolStripMenuItem->Name = L"vyčistitOknoToolStripMenuItem";
			this->vyčistitOknoToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->vyčistitOknoToolStripMenuItem->Text = L"Vyčistit okno";
			this->vyčistitOknoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::ClearConsoleOutput);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"NewFile.robo";
			this->openFileDialog->Filter = L"Robot Control files (*.robo)|*.robo|Text files (*.txt)|*.txt|All files (*.*)|*.*";
			// 
			// ActualFilePanel
			// 
			this->ActualFilePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ActualFilePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ActualFilePanel->Controls->Add(this->ActualFileLabel);
			this->ActualFilePanel->Location = System::Drawing::Point(200, 441);
			this->ActualFilePanel->Name = L"ActualFilePanel";
			this->ActualFilePanel->Size = System::Drawing::Size(322, 17);
			this->ActualFilePanel->TabIndex = 4;
			this->ActualFileToolTip->SetToolTip(this->ActualFilePanel, L"Adresa aktuálně otevřeného projektu");
			// 
			// ActualFileLabel
			// 
			this->ActualFileLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ActualFileLabel->Location = System::Drawing::Point(-160, 0);
			this->ActualFileLabel->Name = L"ActualFileLabel";
			this->ActualFileLabel->Size = System::Drawing::Size(480, 13);
			this->ActualFileLabel->TabIndex = 0;
			this->ActualFileLabel->Text = L"Projekt neotevřen";
			this->ActualFileLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ActualFileToolTip->SetToolTip(this->ActualFileLabel, L"Adresa aktuálně otevřeného projektu");
			// 
			// ActualFileToolTip
			// 
			this->ActualFileToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->ActualFileToolTip->ToolTipTitle = L"NA - Nedostupné";
			// 
			// SelectedPort
			// 
			this->SelectedPort->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SelectedPort->Location = System::Drawing::Point(0, 0);
			this->SelectedPort->Name = L"SelectedPort";
			this->SelectedPort->Size = System::Drawing::Size(90, 13);
			this->SelectedPort->TabIndex = 6;
			this->SelectedPort->Text = L"NA";
			this->SelectedPort->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ActualPortToolTip->SetToolTip(this->SelectedPort, L"Zvolený port");
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->FileName = L"NewFile.robo";
			this->saveFileDialog->Filter = L"Robot Control files (*.robo)|*.robo";
			// 
			// printDialog
			// 
			this->printDialog->Document = this->printDocument;
			// 
			// mainSerialPort
			// 
			this->mainSerialPort->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &MainWin::mainSerialPort_ErrorReceived);
			this->mainSerialPort->PinChanged += gcnew System::IO::Ports::SerialPinChangedEventHandler(this, &MainWin::mainSerialPort_PinChanged);
			this->mainSerialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainWin::mainSerialPort_DataReceived);
			// 
			// ActualPortPanel
			// 
			this->ActualPortPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ActualPortPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ActualPortPanel->Controls->Add(this->SelectedPort);
			this->ActualPortPanel->Location = System::Drawing::Point(4, 441);
			this->ActualPortPanel->Name = L"ActualPortPanel";
			this->ActualPortPanel->Size = System::Drawing::Size(94, 17);
			this->ActualPortPanel->TabIndex = 5;
			// 
			// ActualPortToolTip
			// 
			this->ActualPortToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->ActualPortToolTip->ToolTipTitle = L"NA - Zvolte port";
			// 
			// ConnectedPanel
			// 
			this->ConnectedPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ConnectedPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ConnectedPanel->Controls->Add(this->Connected);
			this->ConnectedPanel->Location = System::Drawing::Point(102, 441);
			this->ConnectedPanel->Name = L"ConnectedPanel";
			this->ConnectedPanel->Size = System::Drawing::Size(94, 17);
			this->ConnectedPanel->TabIndex = 7;
			// 
			// Connected
			// 
			this->Connected->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Connected->ForeColor = System::Drawing::Color::DarkRed;
			this->Connected->Location = System::Drawing::Point(0, 0);
			this->Connected->Name = L"Connected";
			this->Connected->Size = System::Drawing::Size(90, 13);
			this->Connected->TabIndex = 6;
			this->Connected->Text = L"Nepřipojeno";
			this->Connected->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ConnectedToolTip->SetToolTip(this->Connected, L"Stav připojení portu");
			// 
			// ConnectedToolTip
			// 
			this->ConnectedToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->ConnectedToolTip->ToolTipTitle = L"Nepřipojeno";
			// 
			// statusProgressBar
			// 
			this->statusProgressBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->statusProgressBar->Location = System::Drawing::Point(4, 418);
			this->statusProgressBar->Name = L"statusProgressBar";
			this->statusProgressBar->Size = System::Drawing::Size(192, 17);
			this->statusProgressBar->TabIndex = 8;
			// 
			// FirmWarePanel
			// 
			this->FirmWarePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->FirmWarePanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->FirmWarePanel->Controls->Add(this->FirmWare);
			this->FirmWarePanel->Location = System::Drawing::Point(526, 441);
			this->FirmWarePanel->MinimumSize = System::Drawing::Size(70, 17);
			this->FirmWarePanel->Name = L"FirmWarePanel";
			this->FirmWarePanel->Size = System::Drawing::Size(170, 17);
			this->FirmWarePanel->TabIndex = 9;
			// 
			// FirmWare
			// 
			this->FirmWare->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FirmWare->Location = System::Drawing::Point(0, 0);
			this->FirmWare->Name = L"FirmWare";
			this->FirmWare->Size = System::Drawing::Size(166, 13);
			this->FirmWare->TabIndex = 0;
			this->FirmWare->Text = L"Zvolte port";
			// 
			// firmWareVersion
			// 
			this->firmWareVersion->Dock = System::Windows::Forms::DockStyle::Fill;
			this->firmWareVersion->Location = System::Drawing::Point(0, 0);
			this->firmWareVersion->Name = L"firmWareVersion";
			this->firmWareVersion->Size = System::Drawing::Size(66, 13);
			this->firmWareVersion->TabIndex = 1;
			this->firmWareVersion->Text = L"...";
			this->VersionToolTip->SetToolTip(this->firmWareVersion, L"Verze firmwaru");
			// 
			// IsConnectedTimer
			// 
			this->IsConnectedTimer->Interval = 170;
			this->IsConnectedTimer->Tick += gcnew System::EventHandler(this, &MainWin::IsConnectedTimerTick);
			// 
			// firmWareVersionPanel
			// 
			this->firmWareVersionPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->firmWareVersionPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->firmWareVersionPanel->Controls->Add(this->firmWareVersion);
			this->firmWareVersionPanel->Location = System::Drawing::Point(700, 441);
			this->firmWareVersionPanel->MaximumSize = System::Drawing::Size(70, 17);
			this->firmWareVersionPanel->MinimumSize = System::Drawing::Size(70, 17);
			this->firmWareVersionPanel->Name = L"firmWareVersionPanel";
			this->firmWareVersionPanel->Size = System::Drawing::Size(70, 17);
			this->firmWareVersionPanel->TabIndex = 3;
			// 
			// LineNumberPanel
			// 
			this->LineNumberPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->LineNumberPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->LineNumberPanel->Controls->Add(this->LineNumber);
			this->LineNumberPanel->Location = System::Drawing::Point(700, 418);
			this->LineNumberPanel->Name = L"LineNumberPanel";
			this->LineNumberPanel->Size = System::Drawing::Size(70, 17);
			this->LineNumberPanel->TabIndex = 4;
			// 
			// LineNumber
			// 
			this->LineNumber->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LineNumber->Location = System::Drawing::Point(0, 0);
			this->LineNumber->Name = L"LineNumber";
			this->LineNumber->Size = System::Drawing::Size(66, 13);
			this->LineNumber->TabIndex = 1;
			this->LineNumber->Text = L"0";
			this->LineNumber->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// LineNumberTimer
			// 
			this->LineNumberTimer->Enabled = true;
			this->LineNumberTimer->Tick += gcnew System::EventHandler(this, &MainWin::LineNumber_Tick);
			// 
			// LineNumberLabel
			// 
			this->LineNumberLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->LineNumberLabel->AutoSize = true;
			this->LineNumberLabel->Location = System::Drawing::Point(654, 420);
			this->LineNumberLabel->Name = L"LineNumberLabel";
			this->LineNumberLabel->Size = System::Drawing::Size(42, 13);
			this->LineNumberLabel->TabIndex = 10;
			this->LineNumberLabel->Text = L"Řádek:";
			// 
			// ReceivedTimer
			// 
			this->ReceivedTimer->Interval = 170;
			this->ReceivedTimer->Tick += gcnew System::EventHandler(this, &MainWin::ReceivedTimer_Tick);
			// 
			// VersionToolTip
			// 
			this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->VersionToolTip->ToolTipTitle = L"NA - Nepřipojeno";
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 460);
			this->Controls->Add(this->LineNumberLabel);
			this->Controls->Add(this->LineNumberPanel);
			this->Controls->Add(this->firmWareVersionPanel);
			this->Controls->Add(this->FirmWarePanel);
			this->Controls->Add(this->statusProgressBar);
			this->Controls->Add(this->ConnectedPanel);
			this->Controls->Add(this->ActualPortPanel);
			this->Controls->Add(this->ActualFilePanel);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->statusStripBotttom);
			this->Controls->Add(this->menuStripTop);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStripTop;
			this->MinimumSize = System::Drawing::Size(700, 450);
			this->Name = L"MainWin";
			this->Text = L"Robot Control App - ";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainWin::MainWin_Closed);
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);
			this->menuStripTop->ResumeLayout(false);
			this->menuStripTop->PerformLayout();
			this->contextTools->ResumeLayout(false);
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->tabControlMode->ResumeLayout(false);
			this->tabOnlineMode->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->tabTextMode->ResumeLayout(false);
			this->tabTextMode->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->tabGraphicMode->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->flowLayoutToolPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BaseAroundBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BaseUpDownBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HandleUpDownBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HandleRotateBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawUpDownBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawRotateBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->JawOpenCloseBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SpeedBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DelayBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveLeftBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MoveRightBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->DeleteBlock))->EndInit();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->flowLayoutWorkSpace->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->toolStripCode->ResumeLayout(false);
			this->toolStripCode->PerformLayout();
			this->toolStripSerial->ResumeLayout(false);
			this->toolStripSerial->PerformLayout();
			this->toolStripStartnStop->ResumeLayout(false);
			this->toolStripStartnStop->PerformLayout();
			this->toolStripSerialCommand->ResumeLayout(false);
			this->toolStripSerialCommand->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->contextConsoleOutput->ResumeLayout(false);
			this->ActualFilePanel->ResumeLayout(false);
			this->ActualPortPanel->ResumeLayout(false);
			this->ConnectedPanel->ResumeLayout(false);
			this->FirmWarePanel->ResumeLayout(false);
			this->firmWareVersionPanel->ResumeLayout(false);
			this->LineNumberPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//Zavření aplikace
private: System::Void CloseApp(System::Object^  sender, System::EventArgs^  e)
{
	closeSerial();
	Application::Exit();
}


////////////////////////////////////////////////////////////////////////////
//				Funkce pro správu souborů
////////////////////////////////////////////////////////////////////////////

//Nový projekt
private: System::Void NewFile(System::Object^  sender, System::EventArgs^  e) 
{
	if(this->ActualFileToolTip->ToolTipTitle != "NA - Nedostupné")
	{
		//Zjistí zda je otevřen nebo založen projekt
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Pokud nebyly změny v aktuálně otevřeném projektu uloženy, budou ztraceny. Přesto pokračovat?";
		String ^ActualDiagTit = "Nový projekt";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = true;
		Dialog->Continue->Visible = false;
		Dialog->No->Visible = true;
		if(Dialog->ShowDialog() == System::Windows::Forms::DialogResult::Yes)
		{
			//Zjistí zda uživatel souhlasí s případnou ztrátou dat a založí projekt
			this->CommandBox->Text = "begin ROBO;\r\n//Zde pis prikazy ukoncene strednikem\r\n//Seznam prikazu naleznes v napovede\r\nend;";
			this->ActualFileLabel->Text = "Nový; Projekt není uložen";
			this->ActualFileToolTip->ToolTipTitle = "NA - Neuloženo";
			this->ActualFileToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->flowLayoutWorkSpace->Controls->Clear();
			this->flowLayoutWorkSpace->Controls->Add(this->beginBlock1);
			this->flowLayoutWorkSpace->Controls->Add(this->endBlock);
			this->GraphicOutput->Items->Clear();
			this->GraphicOutput->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"begin ROBO;\r\n", L"end;"});
			this->ConsoleOutput->Items->Insert(0,"");
			this->ConsoleOutput->Items->Insert(0,"");
			this->ConsoleOutput->Items->Insert(0,"   INFO - Založení nového projektu.");// [" + CheckCount + "]");
			this->ConsoleOutput->Items->Insert(0,"");
			this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
		}
	}
	else
	{
		//Založí projekt
		this->CommandBox->Enabled = true;
		this->flowLayoutWorkSpace->Enabled = true;
		this->flowLayoutWorkSpace->BackColor = Color::Gray;
		this->CommandBox->Text = "begin ROBO;\r\n//Zde pis prikazy ukoncene strednikem\r\n//Seznam prikazu naleznes v napovede\r\nend;";
		this->ActualFileLabel->Text = "Nový; Projekt není uložen";
		this->ActualFileToolTip->ToolTipTitle = "NA - Neuloženo";
		this->ActualFileToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
		this->flowLayoutWorkSpace->Controls->Clear();
		this->flowLayoutWorkSpace->Controls->Add(this->beginBlock1);
		this->flowLayoutWorkSpace->Controls->Add(this->endBlock);
		this->GraphicOutput->Items->Clear();
		this->GraphicOutput->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"begin ROBO;\r\n", L"end;"});
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"   INFO - Založení nového projektu.");// [" + CheckCount + "]");
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
	}
}

//Otevření souboru - Fce click
private: System::Void OpenFileClick(System::Object^  sender, System::EventArgs^  e) 
{
	if(this->ActualFileToolTip->ToolTipTitle != "NA - Nedostupné")
	{
		//Zjistí zda je otevřen nebo založen projekt
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Pokud nebyly změny v aktuálně otevřeném projektu uloženy, budou ztraceny. Přesto pokračovat?";
		String ^ActualDiagTit = "Otevřít projekt";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = true;
		Dialog->Continue->Visible = false;
		Dialog->No->Visible = true;
		if(Dialog->ShowDialog() == System::Windows::Forms::DialogResult::Yes)
		{
			//Zjistí zda uživatel souhlasí s případnou ztrátou dat a otevře opendialog
			 if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 OpenFile();
			 }
		}
	}
	else
	{
		if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//Otevře opendialog
			OpenFile();
		}
	}
}

//Otevření souboru
void OpenFile()
{
	//Otevření souborů a naplnění CommandBoxu
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(openFileDialog->FileName);
	this->CommandBox->Enabled = true;
	this->flowLayoutWorkSpace->Enabled = true;
	this->flowLayoutWorkSpace->BackColor = Color::Transparent;
	this->CommandBox->Text = gcnew String(sr->ReadToEnd());
	sr->Close();
	this->ActualFileLabel->Text = openFileDialog->FileName;
	this->ActualFileToolTip->ToolTipTitle = System::Convert::ToString(openFileDialog->FileName);
	this->ActualFileToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;

	//Otevření seznamu posledních otevřených souborů
	int			lastCounter1=0,n=0, test;
	char		ToReadChar[100];
	String		^LastFile1,^LastFile2,^LastFile3,^LastFile4,^LastFile5;
	char		*lastopen_filename;

	lastopen_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

	FILE *ptrfilea;
	ptrfilea=fopen(lastopen_filename,"r");
	if (ptrfilea != NULL)
	{
		while(fgets(ToReadChar,100,ptrfilea)!=NULL)
		{
			lastCounter1++;
			std::string	buffera(ToReadChar);
			buffera = buffera.substr(0,buffera.size()-1);
			String^ buffer = gcnew String(buffera.c_str());
			switch(lastCounter1)
			{
				case(1)	: LastFile1 = buffer;
				case(2) : LastFile2 = buffer;
				case(3) : LastFile3 = buffer;
				case(4) : LastFile4 = buffer;
				case(5) : LastFile5 = buffer;
			}
		}
		fclose(ptrfilea);
	}
	else
	{
	//this->ConsolePrint->Items->Insert(0,"Nečtu");
	}

	String^ buffer = gcnew String(openFileDialog->FileName);
	ToolStripMenuItem^ item = gcnew ToolStripMenuItem(buffer);
	item->Name = buffer;
	this->lastOpenToolStripMenuItem->DropDownItems->Add(item);

	
	//Uložení seznamu posledních otevřených souborů
	char		*lastsave_filename;

	lastsave_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

	FILE *ptrfile;
	ptrfile=fopen(lastsave_filename,"w");
	if (ptrfile != NULL)
	{
		//if((openFileDialog->FileName != LastFile1)&&(openFileDialog->FileName != LastFile2)&&(openFileDialog->FileName != LastFile3)&&(openFileDialog->FileName != LastFile4)&&(openFileDialog->FileName != LastFile5))
			fprintf(ptrfile,"%s\n", openFileDialog->FileName);
		if((lastCounter1>0)&&((openFileDialog->FileName)!=LastFile1))fprintf(ptrfile,"%s\n", LastFile1);
		if((lastCounter1>1)&&((openFileDialog->FileName)!=LastFile2))fprintf(ptrfile,"%s\n", LastFile2);
		if((lastCounter1>2)&&((openFileDialog->FileName)!=LastFile3))fprintf(ptrfile,"%s\n", LastFile3);
		if((lastCounter1>3)&&((openFileDialog->FileName)!=LastFile4))fprintf(ptrfile,"%s\n", LastFile4);
		if((lastCounter1>4)&&((openFileDialog->FileName)!=LastFile5))fprintf(ptrfile,"%s\n", LastFile5);												//fgets kvuli mezeram mezi slovy
		fclose(ptrfile);
	}
	else
	{
	//this->ConsolePrint->Items->Insert(0,"Nepíšu");
	}
}

//Uložení souboru
private: System::Void SaveFile(System::Object^  sender, System::EventArgs^  e)
{
	int			SaveIndex = 0;
	String		^ToSaveStr;
	char		*save_filename;
	FILE		*ptrfile;

	if(this->ActualFileToolTip->ToolTipTitle != "NA - Neuloženo")
	{
		//Pokud byl projekt otevřen
		save_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString(this->ActualFileToolTip->ToolTipTitle)).ToPointer();
		try
		{
			//Pokusí se uložit projekt
			ptrfile=fopen(save_filename,"w");
			if (ptrfile != NULL)
			{
				ToSaveStr = this->CommandBox->Text;
				array<Char>^ ToSaveArray = gcnew array<Char>(ToSaveStr->Length);
				StringReader^ sr = gcnew StringReader(ToSaveStr);
				sr->Read(ToSaveArray, 0, (ToSaveStr->Length));
				int ToSaveStrLength = (ToSaveStr->Length);
				ToSaveStr = "";
				while(SaveIndex < ToSaveStrLength)
				{
					if((ToSaveArray[SaveIndex]!='\r'))
					fprintf(ptrfile,"%c", ToSaveArray[SaveIndex]);
					SaveIndex++;
				}
				fclose(ptrfile);
			}
			else
			{
				//this->ConsolePrint->Items->Insert(0,"Nepíšu");
			}
		}
		catch (Exception ^)
		{
			//Dialogové okno chyby ukládání
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba při ukládání do souboru. Zkuste zavřít všechny ostatní instance cílového souboru.";
			String ^ActualDiagTit = "Chyba ukládání do souboru";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
		}
	}
	else
	{
		//Pokud byl projekt vytvořen jako nový
		if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//Otevření savedialogu pro uložení souboru
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(saveFileDialog->OpenFile());
			sr->Close();
			save_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString(this->saveFileDialog->FileName)).ToPointer();
			ptrfile=fopen(save_filename,"w");
			if (ptrfile != NULL)
			{
				ToSaveStr = this->CommandBox->Text;
				array<Char>^ ToSaveArray = gcnew array<Char>(ToSaveStr->Length);
				StringReader^ sr = gcnew StringReader(ToSaveStr);
				sr->Read(ToSaveArray, 0, (ToSaveStr->Length));
				int ToSaveStrLength = (ToSaveStr->Length);
				ToSaveStr = "";
				while(SaveIndex < ToSaveStrLength)
				{
					if((ToSaveArray[SaveIndex]!='\r'))
					fprintf(ptrfile,"%c", ToSaveArray[SaveIndex]);
					SaveIndex++;
				}
				fclose(ptrfile);
			}
			else
			{
				//this->ConsolePrint->Items->Insert(0,"Nepíšu");
			}
			
			//Otevření seznamu posledních otevřených souborů
			int			lastCounter1=0,n=0, test;
			char		ToReadChar[100];
			String		^LastFile1,^LastFile2,^LastFile3,^LastFile4,^LastFile5,^LastFile6;
			char		*lastopen_filename;

			lastopen_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

			FILE *ptrfilea;
			ptrfilea=fopen(lastopen_filename,"r");
			if (ptrfilea != NULL)
			{
				while(fgets(ToReadChar,100,ptrfilea)!=NULL)
				{
					lastCounter1++;
					std::string	buffera(ToReadChar);
					buffera = buffera.substr(0,buffera.size()-1);
					String^ buffer = gcnew String(buffera.c_str());
					switch(lastCounter1)
					{
						case(1)	: LastFile1 = buffer;
						case(2) : LastFile2 = buffer;
						case(3) : LastFile3 = buffer;
						case(4) : LastFile4 = buffer;
						case(5) : LastFile5 = buffer;
					}
				}
				fclose(ptrfilea);
			}
			else
			{
				//this->ConsolePrint->Items->Insert(0,"Nečtu");
			}

			//String^ buffer = System::Convert::ToString(ActualFileStr);//gcnew String(openFileDialog->FileName);
			//ToolStripMenuItem^ item2 = gcnew ToolStripMenuItem(buffer);
			//item2->Name = buffer;
			//this->lastOpenToolStripMenuItem->DropDownItems->Add(item2);

	
			//Uložení seznamu posledních otevřených souborů
			char		*lastsave_filename;

			lastsave_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

			FILE *ptrfile;
			ptrfile=fopen(lastsave_filename,"w");
			if (ptrfile != NULL)
			{
				//if((openFileDialog->FileName != LastFile1)&&(openFileDialog->FileName != LastFile2)&&(openFileDialog->FileName != LastFile3)&&(openFileDialog->FileName != LastFile4)&&(openFileDialog->FileName != LastFile5))
				fprintf(ptrfile,"%s\n", this->saveFileDialog->FileName);
				if((lastCounter1>0)&&((this->saveFileDialog->FileName)!=LastFile1))fprintf(ptrfile,"%s\n", LastFile1);
				if((lastCounter1>1)&&((this->saveFileDialog->FileName)!=LastFile2))fprintf(ptrfile,"%s\n", LastFile2);
				if((lastCounter1>2)&&((this->saveFileDialog->FileName)!=LastFile3))fprintf(ptrfile,"%s\n", LastFile3);
				if((lastCounter1>3)&&((this->saveFileDialog->FileName)!=LastFile4))fprintf(ptrfile,"%s\n", LastFile4);
				if((lastCounter1>4)&&((this->saveFileDialog->FileName)!=LastFile5))fprintf(ptrfile,"%s\n", LastFile5);											//fgets kvuli mezeram mezi slovy
				fclose(ptrfile);
			}
			else
			{
				//this->ConsolePrint->Items->Insert(0,"Nepíšu");
			}
		}
	}
}

//Uložení souboru jako
private: System::Void SaveFileAs(System::Object^  sender, System::EventArgs^  e)
{
	int			SaveIndex = 0;
	String		^ToSaveStr;
	char		*saveas_filename;
	FILE		*ptrfile;

	if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//Vždy otevře savedialog
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(saveFileDialog->OpenFile());
		sr->Close();
		saveas_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString(this->saveFileDialog->FileName)).ToPointer();
		ptrfile=fopen(saveas_filename,"w");
		if (ptrfile != NULL)
		{
			ToSaveStr = this->CommandBox->Text;
			array<Char>^ ToSaveArray = gcnew array<Char>(ToSaveStr->Length);
			StringReader^ sr = gcnew StringReader(ToSaveStr);
			sr->Read(ToSaveArray, 0, (ToSaveStr->Length));
			int ToSaveStrLength = (ToSaveStr->Length);
			ToSaveStr = "";
			while(SaveIndex < ToSaveStrLength)
			{
				if((ToSaveArray[SaveIndex]!='\r'))
				fprintf(ptrfile,"%c", ToSaveArray[SaveIndex]);
				SaveIndex++;
			}
			fclose(ptrfile);
		}
		else
		{
			//this->ConsolePrint->Items->Insert(0,"Nepíšu");
		}
		

		//Otevření seznamu posledních otevřených souborů
		int			lastCounter1=0,n=0, test;
		char		ToReadChar[100];
		String		^LastFile1,^LastFile2,^LastFile3,^LastFile4,^LastFile5,^LastFile6;
		char		*lastopen_filename;

		lastopen_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

		FILE *ptrfilea;
		ptrfilea=fopen(lastopen_filename,"r");
		if (ptrfilea != NULL)
		{
			while(fgets(ToReadChar,100,ptrfilea)!=NULL)
			{
				lastCounter1++;
				std::string	buffera(ToReadChar);
				buffera = buffera.substr(0,buffera.size()-1);
				String^ buffer = gcnew String(buffera.c_str());
				switch(lastCounter1)
				{
					case(1)	: LastFile1 = buffer;
					case(2) : LastFile2 = buffer;
					case(3) : LastFile3 = buffer;
					case(4) : LastFile4 = buffer;
					case(5) : LastFile5 = buffer;
				}
			}
			fclose(ptrfilea);
		}
		else
		{
		//this->ConsolePrint->Items->Insert(0,"Nečtu");
		}
	
		//String^ buffer = System::Convert::ToString(ActualFileStr);//gcnew String(openFileDialog->FileName);
		//ToolStripMenuItem^ item2 = gcnew ToolStripMenuItem(buffer);
		//item2->Name = buffer;
		//this->lastOpenToolStripMenuItem->DropDownItems->Add(item2);
	
		
		//Uložení seznamu posledních otevřených souborů
		char		*lastsave_filename;
	
		lastsave_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();
	
		FILE *ptrfile;
		ptrfile=fopen(lastsave_filename,"w");
		if (ptrfile != NULL)
		{
			//if((openFileDialog->FileName != LastFile1)&&(openFileDialog->FileName != LastFile2)&&(openFileDialog->FileName != LastFile3)&&(openFileDialog->FileName != LastFile4)&&(openFileDialog->FileName != LastFile5))
			fprintf(ptrfile,"%s\n", this->saveFileDialog->FileName);
			if((lastCounter1>0)&&((this->saveFileDialog->FileName)!=LastFile1))fprintf(ptrfile,"%s\n", LastFile1);
			if((lastCounter1>1)&&((this->saveFileDialog->FileName)!=LastFile2))fprintf(ptrfile,"%s\n", LastFile2);
			if((lastCounter1>2)&&((this->saveFileDialog->FileName)!=LastFile3))fprintf(ptrfile,"%s\n", LastFile3);
			if((lastCounter1>3)&&((this->saveFileDialog->FileName)!=LastFile4))fprintf(ptrfile,"%s\n", LastFile4);
			if((lastCounter1>4)&&((this->saveFileDialog->FileName)!=LastFile5))fprintf(ptrfile,"%s\n", LastFile5);											//fgets kvuli mezeram mezi slovy
			fclose(ptrfile);
		}
		else
		{
			//this->ConsolePrint->Items->Insert(0,"Nepíšu");
		}
	}
}

//Funkce pro obnovení seznamu posledních souborů
private: System::Void LastOpenRefresh(System::Object^  sender, System::EventArgs^  e) 
{
	//Vymaže stripMenu, načte seznam ze souboru a vygeneruje aktualizované stripMenu
	this->lastOpenToolStripMenuItem->DropDownItems->Clear();

	int			n=0, test;
	char		ToReadChar[100];
	//String		^ToSendCommandS;
	char		*lastopen_filename;

	lastopen_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

	FILE *ptrfile;
	ptrfile=fopen(lastopen_filename,"r");
	if (ptrfile != NULL)
	{
		while(fgets(ToReadChar,100,ptrfile)!=NULL)
		{
			std::string	buffera(ToReadChar);
			buffera = buffera.substr(0,buffera.size()-1);
			String^ buffer = gcnew String(buffera.c_str());

			ToolStripMenuItem^ item = gcnew ToolStripMenuItem(buffer);
			item->Name = buffer;
			item->Click += gcnew EventHandler(this, &MainWin::clickHanderLastOpen);
			this->lastOpenToolStripMenuItem->DropDownItems->Add(item);
		}
		fclose(ptrfile);
	}
	else
	{
	//this->ConsolePrint->Items->Insert(0,"Nečtu");
	}
}

//Funkce pro generování události do seznamu posledních souborů
void clickHanderLastOpen(Object^ sender, EventArgs^ e)
{
	//Vytvoření položky
    ToolStripItem^ item = (ToolStripItem^) sender;
	//Funkce položky
    System::String^ grupesName = item->Text;
	String ^ActualFileStr = item->Text;
	ActualFile = (char)Marshal::StringToHGlobalAnsi(System::Convert::ToString(ActualFileStr)).ToPointer();
	try
	{
		//Pokusí se otevřít zvolený posledně otevřený soubor
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(ActualFileStr);
		this->CommandBox->Enabled = true;
		this->flowLayoutWorkSpace->Enabled = true;
		this->flowLayoutWorkSpace->BackColor = Color::Transparent;
		this->CommandBox->Text = gcnew String(sr->ReadToEnd());
		sr->Close();
		this->ActualFileLabel->Text = System::Convert::ToString(ActualFileStr);
		this->ActualFileToolTip->ToolTipTitle = System::Convert::ToString(ActualFileStr);
		this->ActualFileToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
	}
	catch (Exception ^)
	{
		//Soubor nebyl v posledním umístnění nalezen, dialogové okno chyby
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Chyba při otevírání posledního souboru. Soubor byl od posledního použití přesunut nebo vymazán.";
		String ^ActualDiagTit = "Soubor již není dostupný";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = false;
		Dialog->Continue->Visible = true;
		Dialog->No->Visible = false;
		Dialog->ShowDialog();
	}

	//Otevření seznamu posledních otevřených souborů
	int			lastCounter1=0,n=0, test;
	char		ToReadChar[100];
	String		^LastFile1,^LastFile2,^LastFile3,^LastFile4,^LastFile5,^LastFile6;
	char		*lastopen_filename;

	lastopen_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

	FILE *ptrfilea;
	ptrfilea=fopen(lastopen_filename,"r");
	if (ptrfilea != NULL)
	{
		while(fgets(ToReadChar,100,ptrfilea)!=NULL)
		{
			lastCounter1++;
			std::string	buffera(ToReadChar);
			buffera = buffera.substr(0,buffera.size()-1);
			String^ buffer = gcnew String(buffera.c_str());
			switch(lastCounter1)
			{
				case(1)	: LastFile1 = buffer;
				case(2) : LastFile2 = buffer;
				case(3) : LastFile3 = buffer;
				case(4) : LastFile4 = buffer;
				case(5) : LastFile5 = buffer;
				case(6) : LastFile6 = buffer;
			}
		}
		fclose(ptrfilea);
	}
	else
	{
	//this->ConsolePrint->Items->Insert(0,"Nečtu");
	}

	String^ buffer = System::Convert::ToString(ActualFileStr);//gcnew String(openFileDialog->FileName);
	//ToolStripMenuItem^ item2 = gcnew ToolStripMenuItem(buffer);
	//item2->Name = buffer;
	//this->lastOpenToolStripMenuItem->DropDownItems->Add(item2);

	
	//Uložení seznamu posledních otevřených souborů
	char		*lastsave_filename;

	lastsave_filename = (char*)Marshal::StringToHGlobalAnsi( System::Convert::ToString("AppData\\RecentlyOpen.roboconfig")).ToPointer();

	FILE *ptrfile;
	ptrfile=fopen(lastsave_filename,"w");
	if (ptrfile != NULL)
	{
		//if((openFileDialog->FileName != LastFile1)&&(openFileDialog->FileName != LastFile2)&&(openFileDialog->FileName != LastFile3)&&(openFileDialog->FileName != LastFile4)&&(openFileDialog->FileName != LastFile5))
			fprintf(ptrfile,"%s\n", buffer);
		if((lastCounter1>0)&&((buffer)!=LastFile1))fprintf(ptrfile,"%s\n", LastFile1);
		if((lastCounter1>1)&&((buffer)!=LastFile2))fprintf(ptrfile,"%s\n", LastFile2);
		if((lastCounter1>2)&&((buffer)!=LastFile3))fprintf(ptrfile,"%s\n", LastFile3);
		if((lastCounter1>3)&&((buffer)!=LastFile4))fprintf(ptrfile,"%s\n", LastFile4);
		if((lastCounter1>4)&&((buffer)!=LastFile5))fprintf(ptrfile,"%s\n", LastFile5);
		if((lastCounter1>5)&&((buffer)!=LastFile6))fprintf(ptrfile,"%s\n", LastFile6);												//fgets kvuli mezeram mezi slovy
		fclose(ptrfile);
	}
	else
	{
	//this->ConsolePrint->Items->Insert(0,"Nepíšu");
	}
}


////////////////////////////////////////////////////////////////////////////
//				Funkce pro práci s textem
////////////////////////////////////////////////////////////////////////////

//Vyjmout
private: System::Void cutToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Clipboard::SetDataObject(this->CommandBox->SelectedText);
	this->CommandBox->SelectedText = "";
}

//Kopírovat
private: System::Void copyToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Clipboard::SetDataObject(this->CommandBox->SelectedText);
}

//Vložit
private: System::Void pasteToolStripButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::IDataObject^ data = Clipboard::GetDataObject();
	if(data)
	{
		if(data->GetDataPresent(DataFormats::Text))
		{
			String^ text = static_cast<String^>
				(data->GetData(DataFormats::Text));
			this->CommandBox->SelectedText = text;
		}
	}
}


////////////////////////////////////////////////////////////////////////////
//				Funkce pro správu komunikace s Arduinem
////////////////////////////////////////////////////////////////////////////

//Aktualizace seznamu dostupných portů
private: System::Void RefreshPortsClick(System::Object^  sender, System::EventArgs^  e)
{
	if(mainSerialPort->IsOpen == 0)
	{
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"   INFO - Zahájení hledání dostupných portů.");
		this->ConsoleOutput->Items->Insert(0,"");
		this->toolStripSerialDropDown->DropDownItems->Clear();
		array<String^>^ s = this->mainSerialPort->GetPortNames();
		String ^buffer = "";
		for each (String^ r in s)
		{
			//i++;
			ToolStripMenuItem^ item = gcnew ToolStripMenuItem(r);
			item->Name = r;
			
			this->mainSerialPort->PortName  = item->Name;
			this->mainSerialPort->BaudRate = 9600;
			try
			{
				this->mainSerialPort->Open();
				try
				{
					this->mainSerialPort->Write("scan");
					_sleep(1100);
					buffer = this->mainSerialPort->ReadExisting();
				}
				catch (Exception ^)
				{
					buffer = " - Error";
				}
				//this->ConsoleOutput->Items->Insert(0,buffer);
				//this->ConsoleOutput->Items->Insert(0,GetExceptionCode());
				//this->ConsoleOutput->Items->Insert(0,GetExceptionInformation());
				this->mainSerialPort->Close();
			}
			catch (Exception ^)
			{
				DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Zařízení na portu je využíváno jinou aplikací nebo je poškozeno.";
				String ^ActualDiagTit = "Chyba - Nevhodné zařízení na portu";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();
				buffer = " - Error";
				this->mainSerialPort->Close();
			}
			
			if(buffer == "Arduino UNO\n")
			{
				item->Enabled=true;
				item->BackColor = Color::SkyBlue;
				item->Text = item->Name + " - Arduino UNO";
				this->ConsoleOutput->Items->Insert(0,item->Name + " - " + buffer);
			}
			else if(buffer == "Arduino Mega\n")
			{
				item->Enabled=true;
				//item->BackColor = Color::MediumSeaGreen;
				item->BackColor = Color::MediumAquamarine;
				item->Text = item->Name + " - Arduino Mega";
				this->ConsoleOutput->Items->Insert(0,item->Name + " - " + buffer);
			}
			else
			{
				if(buffer == "scan");
					buffer = "";
				item->Enabled=false;
				this->ConsoleOutput->Items->Insert(0,item->Name + buffer);
			}			
			buffer = "";
			item->Click += gcnew EventHandler(this, &MainWin::clickHanderRefreshPort);
			this->toolStripSerialDropDown->DropDownItems->Add(item);
		}
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"   INFO - Hledání dostupných portů dokončeno.");
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
	}
	else
	{
		array<String^>^ s = this->mainSerialPort->GetPortNames();


		for each (String^ r in s)
		{
			this->ConsoleOutput->Items->Insert(0,r);
		}


		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"   CHYBA - K aplikaci je již jedno zařízení připojeno.");
		this->ConsoleOutput->Items->Insert(0,"");
	}
}

//Funkce pro generování události do seznamu portů
void clickHanderRefreshPort(Object^ sender, EventArgs^ e)
{
	ToolStripItem^ item = (ToolStripItem^) sender;
	System::String^ grupesName = item->Name;
	if(mainSerialPort->IsOpen == 0)
	{
		this->SelectedPort->Text = item->Name;
		this->ActualPortToolTip->ToolTipTitle = item->Name;
		this->ActualPortToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
		this->FirmWare->Text = "Připraven";
	}
	else
	{
		this->ActualPortToolTip->ToolTipTitle = this->SelectedPort->Text + "Port je již otevřen";
		this->ActualPortToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
	}
}

//Otevření portu, načtení verze firmwaru
private: System::Void OpenPortClick(System::Object^  sender, System::EventArgs^  e)
{
	int ErrorOpen = 0;

	this->IsConnectedTimer->Stop();
	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"   INFO - Zahájení otevření portu. [" + "]");
	this->ConsoleOutput->Items->Insert(0,"");
	if((mainSerialPort->IsOpen == 0)&&(this->SelectedPort->Text != "NA"))
	{
		this->IsConnectedTimer->Stop();
		this->mainSerialPort->PortName  = this->SelectedPort->Text;
		this->mainSerialPort->BaudRate = 9600;
		try
		{
			this->mainSerialPort->Open();
			this->mainSerialPort->DiscardInBuffer();
			this->statusProgressBar->Maximum = 100;
			this->statusProgressBar->Value = 0;
			for(int j=0;j<=100;j++)
			{
				this->statusProgressBar->Increment(1);
				_sleep(20);
			}
			this->mainSerialPort->Write("connect");
			this->mainSerialPort->DiscardInBuffer();
			_sleep(100);
			try
			{
				this->ConsoleOutput->Items->Insert(0,(this->mainSerialPort->ReadLine()));
				String^ FirmWare = this->mainSerialPort->ReadLine();
				String^ Compatible = this->mainSerialPort->ReadLine();
				this->ConsoleOutput->Items->Insert(0,FirmWare);
				this->FirmWare->Text = FirmWare;
				if((Compatible == "1.0.1 /Charlie")||(Compatible == "1.0.1 /Delta"))
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje Robot Control ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   INFO Připojené Arduino obsahuje poslední verzi firmwaru podporovanou aplikací.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if((Compatible == "1.0.0 /Echo")||(Compatible == "1.0.0 /Foxtrot")||(Compatible == "1.0.0 /Golf"))
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje Robot Control ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   INFO Připojené Arduino obsahuje vyšší verzi firmwaru.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if((Compatible == "1.0.1 /Alpha")||(Compatible == "1.0.0 /Beta"))
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje Robot Control ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   INFO Připojené Arduino obsahuje verzi firmwaru podporovanou aplikací.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if(((Compatible == "1.0.0 /Alpha")||(Compatible == "1.0.0 /Beta")||(Compatible == "1.0.0 /Charlie")||(Compatible == "1.0.0 /Delta")||(Compatible == "1.0.0 /Foxtrot")||(Compatible == "1.0.0 /Echo"))&&(FirmWare == "Arduino UNO Rev.3 - LCD Driver"))
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje vývojovou verzi LCD ovladače. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   POZOR Připojené Arduino obsahuje beta verzi firmwaru pro LCD display.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if((Compatible == "1.0.0 beta C")||(Compatible == "1.0.0 beta D")||(Compatible == "1.0.0 beta E"))
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje Robot Control ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   POZOR Připojené Arduino obsahuje beta verzi firmwaru pro robotický manipulátor.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if(Compatible == "160316A")
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje servo ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"CHYBA Připojené Arduino neobsahuje firmware pro robotický manipulátor.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   CHYBA - Robotický manipulátor není dostupný.");
					this->firmWareVersion->Text = "[160316A]";
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else if(Compatible == "160315A")
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,">>> Zařízení obsahuje servo ovladač. Verze: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"CHYBA Připojené Arduino neobsahuje firmware pro robotický manipulátor.");
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   CHYBA - Robotický manipulátor není dostupný.");
					this->firmWareVersion->Text = "[160315A]";
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				else
				{
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"Unknown firmware version. Version: " + Compatible);
					this->ConsoleOutput->Items->Insert(0,"Servo position: Enable");
					this->ConsoleOutput->Items->Insert(0,"Servo speed: Disable");
					this->ConsoleOutput->Items->Insert(0,"Servo Sequence: Disable");
					this->ConsoleOutput->Items->Insert(0,"");
					this->ConsoleOutput->Items->Insert(0,"   CHYBA - Robotický manipulátor není dostupný.");
					this->firmWareVersion->Text = Compatible;
					this->VersionToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
					this->VersionToolTip->ToolTipTitle = Compatible;
				}
				this->mainSerialPort->DiscardInBuffer();
			}
			catch (Exception ^)
			{
				this->FirmWare->Text = "Arduino není dostupné";
				DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Zařízení na portu neobsahuje vhodný program, není možné ho použít pro Robot Control";
				String ^ActualDiagTit = "Chyba - Nevhodné zařízení na portu";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();
				this->ConsoleOutput->Items->Insert(0,"Connected to unknown device..");
			}
		}
		catch (Exception ^)
		{
			this->FirmWare->Text = "Arduino není dostupné";
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Port je momentálně používán jinou aplikací nebo zařízení na portu bylo odpojeno.";
			String ^ActualDiagTit = "Chyba - Port je nedostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
			this->ConsoleOutput->Items->Insert(0,"   CHYBA K zařízení se nepovedlo připojit.");
		}
		/*catch (TimeoutException^ ex)
		{
			DialogWin^ form = gcnew DialogWin();
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Port již není dostupný, není možné ho otevřít znovu "+ex;
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
			form->ShowDialog();
		}*/
	}
	else if(mainSerialPort->IsOpen == 1)
	{
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Port je již otevřen, není možné ho otevřít znovu";
		String ^ActualDiagTit = "Chyba - Port již otevřen";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = false;
		Dialog->Continue->Visible = true;
		Dialog->No->Visible = false;
		Dialog->ShowDialog();
	}
	else
	{
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Není vybrán žádný seriový port, vyberte port na kterém se nachází zařízení";
		String ^ActualDiagTit = "Chyba - Žádný port";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = false;
		Dialog->Continue->Visible = true;
		Dialog->No->Visible = false;
		Dialog->ShowDialog();
	}
	this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
	ReceivedFlg=0;
	this->IsConnectedTimer->Start();
	this->ReceivedTimer->Start();
}

//Zavření portu - Klik
private: System::Void ClosePortClick(System::Object^  sender, System::EventArgs^  e)
{
	closeSerial();
}

//Funkce zavření portu
private: System::Void closeSerial()
{
	if(mainSerialPort->IsOpen == 1)
	{
		this->ReceivedTimer->Stop();
		try
		{
			try
			{
				this->mainSerialPort->Write("disconnect");
			}
			catch (Exception ^)
			{
				DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Zařízení na portu bylo nedostupné již před zavřením portu.";
				String ^ActualDiagTit = "Chyba při zavírání portu";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();
			}
			this->mainSerialPort->Close();
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Aktuálně otevřený port se nepovedlo zavřít";
			String ^ActualDiagTit = "Chyba při zavírání portu";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
		}
		if((this->mainSerialPort->IsOpen) == 0)
		{
			this->statusProgressBar->Maximum = 100;
			this->statusProgressBar->Value = 0;
			this->FirmWare->Text = "Arduino není dostupné";
			this->ConsoleOutput->Items->Insert(0,"Disconnected..");
			this->firmWareVersion->Text = "[NA]";
		}
	}
}

//Obnovení stavu portu
private: System::Void IsConnectedTimerTick(System::Object^  sender, System::EventArgs^  e)
{
	if(mainSerialPort->IsOpen == 0)
	{
		this->Connected->Text = "Nepřipojeno";
		this->Connected->ForeColor = Color::FromName( "DarkRed" );
		this->ConnectedToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
		this->ConnectedToolTip->ToolTipTitle = L"Nepřipojeno";
	}
	else if(mainSerialPort->IsOpen == 1)
	{
		this->Connected->Text = "Připojeno";
		this->Connected->ForeColor = Color::FromName( "DarkGreen" );
		this->ConnectedToolTip->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
		this->ConnectedToolTip->ToolTipTitle = L"Připojeno";
	}
	else
		this->Connected->Text = "JedeTimer";
}

//Inicializace spojení
private: System::Void toolStripInitButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		try
		{
			this->statusProgressBar->Maximum = 100;
			this->statusProgressBar->Value = 0;
			this->mainSerialPort->DtrEnable = true;
			for(int j=0;j<=100;j++)
			{
				this->statusProgressBar->Increment(1);
				_sleep(20);
			}
			this->mainSerialPort->DtrEnable = false;
			_sleep(200);
			//this->mainSerialPort->Write("reconnect");
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Zařízení na portu bylo pravděpodobně odpojeno, není možné inicializovat.";
			String ^ActualDiagTit = "Chyba - Zařízení není připojeno";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
	else
	{
		DialogWin^ Dialog = gcnew DialogWin();
		Dialog->DialogText->Text = "Na portu není připojeno žádné zařízení, není možné inicializovat.";
		String ^ActualDiagTit = "Chyba - Zařízení není připojeno";
		Dialog->Text = ActualDiagTit;
		Dialog->DialogTitle->Text = ActualDiagTit;
		Dialog->Yes->Visible = false;
		Dialog->Continue->Visible = true;
		Dialog->No->Visible = false;
		Dialog->ShowDialog();
	}
}

//DataReceived funkce
private: System::Void mainSerialPort_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			 ReceivedFlg = 1;
		 }

private: System::Void ReceivedTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 this->IsConnectedTimer->Stop();
			 if(ReceivedFlg>0)
			 {
				 try
				 {
					 String^ buffer = this->mainSerialPort->ReadLine();
					 String^ Rcv = "Received:  ";
					 if(buffer == "Init Complete..")
					 {
						this->mainSerialPort->Write("reconnect");
					 }
					 buffer = Rcv + buffer;
					 //ConsolePrint->BeginUpdate();
					 this->ConsoleOutput->Items->Insert(0,buffer);
					 //ConsolePrint->EndUpdate();
					 ReceivedFlg=0;
				 }
				catch (Exception ^)
				{
					
					this->ReceivedTimer->Stop();
					DialogWin^ Dialog = gcnew DialogWin();
					Dialog->DialogText->Text = "Chyba ve čtení seriového portu. Zařízení je již pravděpodobně nedostupné. Přesto pokračovat ve čtení?";
					String ^ActualDiagTit = "Chyba - Port není dostupný";
					Dialog->Text = ActualDiagTit;
					Dialog->DialogTitle->Text = ActualDiagTit;
					Dialog->Yes->Visible = true;
					Dialog->Continue->Visible = false;
					Dialog->No->Visible = true;
					if(Dialog->ShowDialog() == System::Windows::Forms::DialogResult::No)
					{
						ReceivedFlg=0;
						closeSerial();
					}
			else if(Dialog->ShowDialog() == System::Windows::Forms::DialogResult::Yes)
			{
					
					this->ReceivedTimer->Start();
			}
					ReceivedFlg=0;
				}
			 }
			 this->IsConnectedTimer->Start();
		 }

//Funkce příkazové řákdy pro Arduino
private: System::Void CommandPrompt_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		try
		{
			this->mainSerialPort->Write(this->toolStripCommandLine->Text);
			String^ buffer = this->toolStripCommandLine->Text;
			String^ Snd = "Send:  ";
			buffer = Snd + buffer;
			this->ConsoleOutput->Items->Insert(0,buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
			ReceivedFlg=0;
			closeSerial();
		}
		this->toolStripCommandLine->Text = "";
	}
}


////////////////////////////////////////////////////////////////////////////
//				Funkce změny zobrazení
////////////////////////////////////////////////////////////////////////////

private: System::Void inverzeBarevOutput(System::Object^  sender, System::EventArgs^  e)
{
	if(inverzeBarevToolStripMenuItem->Checked)
	{
		this->ConsoleOutput->ForeColor = Color::FromName( "Windowtext" );
		this->ConsoleOutput->BackColor = Color::FromName( "Window" );
		this->inverzeBarevToolStripMenuItem->Checked = false;
		this->inverzeBarevToolStripMenuItem3->Checked = false;
	}
	else
	{
		this->ConsoleOutput->ForeColor = Color::FromName( "Window" );
		this->ConsoleOutput->BackColor = Color::FromName( "Windowtext" );
		this->inverzeBarevToolStripMenuItem->Checked = true;
		this->inverzeBarevToolStripMenuItem3->Checked = true;
	}
}

private: System::Void inverzeBarevCommandBox(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(inverzeBarevToolStripMenuItem1->Checked)
			 {
				 this->CommandBox->ForeColor = Color::FromName( "Windowtext" );
				 this->CommandBox->BackColor = Color::FromName( "Window" );
				 this->inverzeBarevToolStripMenuItem1->Checked = false;
				 this->inverzeBarevToolStripMenuItem2->Checked = false;
			 }
			 else
			 {
				 this->CommandBox->ForeColor = Color::FromName( "Window" );
				 this->CommandBox->BackColor = Color::FromName( "Windowtext" );
				 this->inverzeBarevToolStripMenuItem1->Checked = true;
				 this->inverzeBarevToolStripMenuItem2->Checked = true;
			 }
		 }


private: System::Void fontLucidaCommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(L"Lucida Console", this->CommandBox->Font->Size, System::Drawing::FontStyle::Regular));
			 this->arialToolStripMenuItem->Checked = false;
			 this->courierNewToolStripMenuItem->Checked = false;
			 this->lucidaConsoleToolStripMenuItem->Checked = true;
			 this->microsoftSansSerifToolStripMenuItem->Checked = false;
		 }
private: System::Void fontCourierCommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(L"Courier New", this->CommandBox->Font->Size, System::Drawing::FontStyle::Regular));
			 this->arialToolStripMenuItem->Checked = false;
			 this->courierNewToolStripMenuItem->Checked = true;
			 this->lucidaConsoleToolStripMenuItem->Checked = false;
			 this->microsoftSansSerifToolStripMenuItem->Checked = false;

		 }
private: System::Void fontArialCommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(L"Arial", this->CommandBox->Font->Size, System::Drawing::FontStyle::Regular));
			 this->arialToolStripMenuItem->Checked = true;
			 this->courierNewToolStripMenuItem->Checked = false;
			 this->lucidaConsoleToolStripMenuItem->Checked = false;
			 this->microsoftSansSerifToolStripMenuItem->Checked = false;
		 }

//Změna velikosti fontu CommandBoxu
private: System::Void size8CommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(this->CommandBox->Font->Name, 8.25F, System::Drawing::FontStyle::Regular));
			 this->size8toolStripMenuItem->Checked = true;
			 this->size9toolStripMenuItem->Checked = false;
			 this->size10toolStripMenuItem->Checked = false;
			 this->size11toolStripMenuItem->Checked = false;
			 this->size13toolStripMenuItem->Checked = false;
		 }
private: System::Void size9CommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(this->CommandBox->Font->Name, 9, System::Drawing::FontStyle::Regular));
			 this->size8toolStripMenuItem->Checked = false;
			 this->size9toolStripMenuItem->Checked = true;
			 this->size10toolStripMenuItem->Checked = false;
			 this->size11toolStripMenuItem->Checked = false;
			 this->size13toolStripMenuItem->Checked = false;
		 }
private: System::Void size10CommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(this->CommandBox->Font->Name, 9.75F, System::Drawing::FontStyle::Regular));
			 this->size8toolStripMenuItem->Checked = false;
			 this->size9toolStripMenuItem->Checked = false;
			 this->size10toolStripMenuItem->Checked = true;
			 this->size11toolStripMenuItem->Checked = false;
			 this->size13toolStripMenuItem->Checked = false;
		 }
private: System::Void size11CommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(this->CommandBox->Font->Name, 11.25F, System::Drawing::FontStyle::Regular));
			 this->size8toolStripMenuItem->Checked = false;
			 this->size9toolStripMenuItem->Checked = false;
			 this->size10toolStripMenuItem->Checked = false;
			 this->size11toolStripMenuItem->Checked = true;
			 this->size13toolStripMenuItem->Checked = false;
		 }
private: System::Void size13CommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(this->CommandBox->Font->Name, 12.75F, System::Drawing::FontStyle::Regular));
			 this->size8toolStripMenuItem->Checked = false;
			 this->size9toolStripMenuItem->Checked = false;
			 this->size10toolStripMenuItem->Checked = false;
			 this->size11toolStripMenuItem->Checked = false;
			 this->size13toolStripMenuItem->Checked = true;
		 }

private: System::Void fontMSCommandBox(System::Object^  sender, System::EventArgs^  e) {
			 this->CommandBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", this->CommandBox->Font->Size, System::Drawing::FontStyle::Regular));
			 this->arialToolStripMenuItem->Checked = false;
			 this->courierNewToolStripMenuItem->Checked = false;
			 this->lucidaConsoleToolStripMenuItem->Checked = false;
			 this->microsoftSansSerifToolStripMenuItem->Checked = true;
		 }


////////////////////////////////////////////////////////////////////////////
//				Funkce grafického režimu
////////////////////////////////////////////////////////////////////////////

//Spuštění Drag'n'Drop
private: System::Void AnyBlock_MouseDown(System::Object^  /*sender*/, System::Windows::Forms::MouseEventArgs^  e)
{
	// Započetí akce Drag'n'Drop
    System::Drawing::Size dragSize = SystemInformation::DragSize;
    dragBoxFromMouseDown = System::Drawing::Rectangle(Point(e->X - (dragSize.Width / 2),e->Y - (dragSize.Height / 2)),dragSize);

	// Zrušení akcí mazání a přesun		
	this->DeleteBlock->BackColor = Color::LightBlue;
	this->MoveLeftBlock->BackColor = Color::LightBlue;
	this->MoveRightBlock->BackColor = Color::LightBlue;
	delete MyNormalCursor;
	this->flowLayoutWorkSpace->Cursor = System::Windows::Forms::Cursors::Arrow;
}

//Provádění Drag'n'Drop pro ACTUATOR_1
private: System::Void BaseAroundBlock_MouseMove(System::Object^  /*sender*/, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		// Pokud myš opustí objekt, změní se kurzor
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
		{
            // Předá název přetahovaného prvku cílovému prvku
			DragDropEffects dropEffect = this->BaseAroundBlock->DoDragDrop( this->BaseAroundBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro ACTUATOR_2
private: System::Void BaseUpDownBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->BaseUpDownBlock->DoDragDrop( this->BaseUpDownBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro ACTUATOR_3
private: System::Void HandleUpDownBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->HandleUpDownBlock->DoDragDrop( this->HandleUpDownBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro ACTUATOR_4
private: System::Void HandleRotateBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->HandleRotateBlock->DoDragDrop( this->HandleRotateBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro ACTUATOR_5
private: System::Void JawUpDownBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->JawUpDownBlock->DoDragDrop( this->JawUpDownBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
        }
	}
}
		 
//Provádění Drag'n'Drop pro ACTUATOR_6
private: System::Void JawRotateBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->JawRotateBlock->DoDragDrop( this->JawRotateBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
 
//Provádění Drag'n'Drop pro ACTUATOR_7
private: System::Void JawOpenCloseBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->JawOpenCloseBlock->DoDragDrop( this->JawOpenCloseBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro SPEED_
private: System::Void SpeedBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->SpeedBlock->DoDragDrop( this->SpeedBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}
		 
//Provádění Drag'n'Drop pro DELAY_
private: System::Void DelayBlock_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if ( (e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left )
    {
		if ( dragBoxFromMouseDown != Rectangle::Empty &&  !dragBoxFromMouseDown.Contains( e->X, e->Y ) )
        {
			DragDropEffects dropEffect = this->DelayBlock->DoDragDrop( this->DelayBlock->Name, static_cast<DragDropEffects>(DragDropEffects::All | DragDropEffects::Link) );
		}
	}
}

//Zapnutí/vypnutí mazání
private: System::Void DeleteBlock_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(this->DeleteBlock->BackColor != Color::Coral)
	{
		this->DeleteBlock->BackColor = Color::Coral;
		this->MoveLeftBlock->BackColor = Color::LightBlue;
		this->MoveRightBlock->BackColor = Color::LightBlue;
		MyNormalCursor = gcnew System::Windows::Forms::Cursor( "AppData\\DeleteCursor.cur" );
		this->flowLayoutWorkSpace->Cursor = MyNormalCursor;
	}
	else
	{
		this->DeleteBlock->BackColor = Color::LightBlue;
		delete MyNormalCursor;
		this->flowLayoutWorkSpace->Cursor = System::Windows::Forms::Cursors::Arrow;
	}
}

//Zapnutí/vypnutí přesunu vlevo
private: System::Void MoveLeftBlock_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(this->MoveLeftBlock->BackColor != Color::Coral)
	{
		this->MoveLeftBlock->BackColor = Color::Coral;
		this->DeleteBlock->BackColor = Color::LightBlue;
		this->MoveRightBlock->BackColor = Color::LightBlue;
		MyNormalCursor = gcnew System::Windows::Forms::Cursor( "AppData\\LeftCursor.cur" );
		this->flowLayoutWorkSpace->Cursor = MyNormalCursor;
	}
	else
	{
		this->MoveLeftBlock->BackColor = Color::LightBlue;
		delete MyNormalCursor;
		this->flowLayoutWorkSpace->Cursor = System::Windows::Forms::Cursors::Arrow;
	}
}

//Zapnutí/vypnutí přesunu vpravo
private: System::Void MoveRightBlock_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(this->MoveRightBlock->BackColor != Color::Coral)
	{
		this->MoveRightBlock->BackColor = Color::Coral;
		this->DeleteBlock->BackColor = Color::LightBlue;
		this->MoveLeftBlock->BackColor = Color::LightBlue;
		MyNormalCursor = gcnew System::Windows::Forms::Cursor( "AppData\\RightCursor.cur" );
		this->flowLayoutWorkSpace->Cursor = MyNormalCursor;
	}
	else
	{
		this->MoveRightBlock->BackColor = Color::LightBlue;
		delete MyNormalCursor;
		this->flowLayoutWorkSpace->Cursor = System::Windows::Forms::Cursors::Arrow;
	}
}
		 
//Indikace Drag'n'Drop při vstupu do pracovního prostoru (cíle)
private: System::Void flowLayoutWorkSpace_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	// Jsou-li vstupní data text (z bloku)
	if (e->Data->GetDataPresent(DataFormats::Text))
    {
		// Ikona kopírování
		e->Effect = DragDropEffects::Copy;
		String ^test = e->Data->GetData( DataFormats::Text )->ToString();
        this->flowLayoutWorkSpace->BackColor = Color::DimGray;
	}
	else
    {
		e->Effect = DragDropEffects::None;
    }
}
		 
//Indikace Drag'n'Drop při vstupu do pracovního prostoru (cíle) 
private: System::Void flowLayoutWorkSpace_DragLeave(System::Object^  sender, System::EventArgs^  e)
{
	// Obnovení barvy pozadí
	this->flowLayoutWorkSpace->BackColor = Color::Gray;
}
		 
//Akce po upustění objektu v cílovém prostoru
private: System::Void flowLayoutWorkSpace_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	this->flowLayoutWorkSpace->BackColor = Color::Gray;
	// Vytvoření objektu typu GraphicBlock
	GraphicBlock ^novy = gcnew GraphicBlock();
	long FlowEndLocal = this->flowLayoutWorkSpace->Controls->IndexOf(this->endBlock);
	novy->Click += gcnew EventHandler(this, &MainWin::GraphicBlock_Click);
	novy->LocationChanged += gcnew EventHandler(this, &MainWin::GraphicBlock_LocationChange);
	// Konfigurace bloku typu ACTUATOR_1 a jiné
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "BaseAroundBlock")
	{
		// Konfigurace názvu, barvy, ikony a přidání řádku do náhledu kódu
		novy->BlockName->Text = "ACTUATOR_1";
		novy->colorStrip->BackColor = Color::DarkGray;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseAroundBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_1(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "BaseUpDownBlock")
	{
		novy->BlockName->Text = "ACTUATOR_2";
		novy->colorStrip->BackColor = Color::DarkOrange;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseUpDownBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_2(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "HandleUpDownBlock")
	{
		novy->BlockName->Text = "ACTUATOR_3";
		novy->colorStrip->BackColor = Color::Goldenrod;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleUpDownBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_3(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "HandleRotateBlock")
	{
		novy->BlockName->Text = "ACTUATOR_4";
		novy->colorStrip->BackColor = Color::YellowGreen;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleRotateBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_4(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "JawUpDownBlock")
	{
		novy->BlockName->Text = "ACTUATOR_5";
		novy->colorStrip->BackColor = Color::Turquoise;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawUpDownBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_5(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "JawRotateBlock")
	{
		novy->BlockName->Text = "ACTUATOR_6";
		novy->colorStrip->BackColor = Color::SteelBlue;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawRotateBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_6(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "JawOpenCloseBlock")
	{
		novy->BlockName->Text = "ACTUATOR_7";
		novy->colorStrip->BackColor = Color::Violet;
		novy->BlockValue->Value = 90;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawOpenCloseBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_7(90);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "SpeedBlock")
	{
		novy->BlockName->Text = "SPEED_";
		novy->colorStrip->BackColor = Color::Yellow;
		novy->BlockValue->Value = 15;
		novy->BlockValue->Increment = 1;
		novy->BlockValue->Minimum = 1;
		novy->BlockValue->Maximum = 20;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\SpeedBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"SPEED_(15);\r\n");
	}
	if((e->Data->GetData( DataFormats::Text )->ToString()) == "DelayBlock")
	{
		novy->BlockName->Text = "DELAY_";
		novy->colorStrip->BackColor = Color::Teal;
		novy->BlockValue->Value = 100;
		novy->BlockValue->Increment = 50;
		novy->BlockValue->Minimum = 0;
		novy->BlockValue->Maximum = 1000;
		novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\DelayBlock.png");
		this->GraphicOutput->Items->Insert(FlowEndLocal,"DELAY_(100);\r\n");
	}
			 
	// Přidání bloku, posun bloku před END
	novy->BlockValue->ValueChanged += gcnew EventHandler(this, &MainWin::BlockValueChanged);
	this->flowLayoutWorkSpace->Controls->Add(novy);
	this->flowLayoutWorkSpace->Controls->SetChildIndex(novy, FlowEndLocal);
	long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(novy);
}
		 
//Funkce kliknutí na blok
void GraphicBlock_Click(Object^ sender, EventArgs^ e)
{
	// Přiřazení Bloku do objektu
	GraphicBlock^ ActualBlock = (GraphicBlock^) sender;
	long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(ActualBlock);
	long FlowEndLocal = this->flowLayoutWorkSpace->Controls->IndexOf(this->endBlock);
	// Mazání bloku
	if(this->DeleteBlock->BackColor == Color::Coral)
	{
		Object^ bla;
		this->flowLayoutWorkSpace->Controls->RemoveAt(FlowIndexLocal);
		bla = (this->GraphicOutput->Items[1]);
		this->GraphicOutput->Items->RemoveAt(FlowIndexLocal);
	}
	// Posun bloku vlevo
	if((this->MoveLeftBlock->BackColor == Color::Coral)&&(FlowIndexLocal>1))
	{
		this->flowLayoutWorkSpace->Controls->SetChildIndex(ActualBlock, FlowIndexLocal-1);
		String^ buffer = this->GraphicOutput->GetItemText(this->GraphicOutput->Items[FlowIndexLocal]);
		this->GraphicOutput->Items->RemoveAt(FlowIndexLocal);
		this->GraphicOutput->Items->Insert(FlowIndexLocal-1, buffer);
	}
	//Posun bloku vpravo
	if((this->MoveRightBlock->BackColor == Color::Coral)&&(FlowIndexLocal<(FlowEndLocal-1)))
	{
		this->flowLayoutWorkSpace->Controls->SetChildIndex(ActualBlock, FlowIndexLocal+1);
		String^ buffer = this->GraphicOutput->GetItemText(this->GraphicOutput->Items[FlowIndexLocal]);
		this->GraphicOutput->Items->RemoveAt(FlowIndexLocal);
		this->GraphicOutput->Items->Insert(FlowIndexLocal+1, buffer);
	}
}

//Funkce změny hodnoty bloku - změní hodnotu v náhledu
void BlockValueChanged(Object^ sender, EventArgs^ e)
{
	NumericUpDown^ test = (NumericUpDown^) sender;
	Control^ parent = test->Parent;
	long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(parent);

	int num = System::Convert::ToInt32(test->Value);
	char str[12];
	num = num;
	sprintf(str, "%d", num);
	String^ buffer = gcnew String(str);
	
	String^ buffera = this->GraphicOutput->GetItemText(this->GraphicOutput->Items[FlowIndexLocal]);
	buffera = buffera->Substring(0,6);
	buffera = buffera + "(" + buffer + ");\r\n";
	this->GraphicOutput->Items->RemoveAt(FlowIndexLocal);
	this->GraphicOutput->Items->Insert(FlowIndexLocal, buffera);
}

//Funkce změny polohy bloku - změní index bloku a řádek odpovídajícího příkazu v náhledu
private: System::Void GraphicBlock_LocationChange(System::Object^ sender, System::EventArgs^ e)
{
	GraphicBlock^ ActualBlock = (GraphicBlock^) sender;
	long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(ActualBlock);
	char FlowIndexLocalChar[12];
	sprintf(FlowIndexLocalChar, "%d", FlowIndexLocal);
	String^ buffer = gcnew String(FlowIndexLocalChar);
	ActualBlock->BlockIndex->Text = buffer;
}
		 
//Funkce změny polohy bloku END - změní index bloku a posune příkaz v náhledu na poslední místo
private: System::Void endBlock_LocationChanged(System::Object^  sender, System::EventArgs^  e)
{
	long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(this->endBlock);
	char FlowIndexLocalChar[12];
	sprintf(FlowIndexLocalChar, "%d", FlowIndexLocal);
	String^ buffer = gcnew String(FlowIndexLocalChar);
	this->endBlock->BlockIndex->Text = buffer;
}



////////////////////////////////////////////////////////////////////////////
//				Funkce - Jiné
////////////////////////////////////////////////////////////////////////////

//Zobrazení dialogu "O programu"
private: System::Void AboutClick(System::Object^  sender, System::EventArgs^  e)
{
	DialogWin^ Dialog = gcnew DialogWin();
	Dialog->DialogText->Text = "Program je vyvíjen především jako softwarová část diplomové práce:\n Model průmyslového robotického ramene.\n\n FEKT VUT v Brně, Ústav mikroelektroniky.\n\nVedoucí: Ing.Petr Vyroubal, Ph.D.\n\nAutor: Bc.David Sobota";
	String ^ActualDiagTit = "O programu";
	Dialog->Text = ActualDiagTit;
	Dialog->DialogTitle->Text = ActualDiagTit;
	Dialog->Yes->Visible = false;
	Dialog->Continue->Visible = true;
	Dialog->No->Visible = false;
	Dialog->ShowDialog();
}

		

////////////////////////////////////////////////////////////////////////////
//				Funkce - Nástrojové lišty
////////////////////////////////////////////////////////////////////////////

//Zobrazení nástrojů připojení
private: System::Void toolStripSerialVisible(System::Object^  sender, System::EventArgs^  e)
{
	if(this->toolStripSerial->Visible == true)
	{
		this->toolStripSerial->Visible = false;
		this->připojeníToolStripMenuItem->Checked = false;
		this->připojeníToolStripMenuItem1->Checked = false;
	}
	else
	{
		this->toolStripSerial->Visible = true;
		this->připojeníToolStripMenuItem->Checked = true;
		this->připojeníToolStripMenuItem1->Checked = true;
	}
}

//Zobrazení lišty práce s kodem
private: System::Void toolStripCodeVisible(System::Object^  sender, System::EventArgs^  e)
{
	if(this->toolStripCode->Visible == true)
	{
		this->toolStripCode->Visible = false;
		this->kompilaceToolStripMenuItem->Checked = false;
		this->kompilaceToolStripMenuItem1->Checked = false;
	}
	else
	{
		this->toolStripCode->Visible = true;
		this->kompilaceToolStripMenuItem->Checked = true;
		this->kompilaceToolStripMenuItem1->Checked = true;
	}
}

//Zobrazení lišty příkazovéhho řádku pro COM
private: System::Void toolStripSerialCommandVisible(System::Object^  sender, System::EventArgs^  e)
{
	if(this->toolStripSerialCommand->Visible == true)
	{
		this->toolStripSerialCommand->Visible = false;
		this->serialPříkazyToolStripMenuItem->Checked = false;
		this->serialPříkazyToolStripMenuItem1->Checked = false;
	}
	else
	{
		this->toolStripSerialCommand->Visible = true;
		this->serialPříkazyToolStripMenuItem->Checked = true;
		this->serialPříkazyToolStripMenuItem1->Checked = true;
	}
}

//Zobrazení lišty start'n'stop
private: System::Void ovládáníArduinaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
	if(this->toolStripStartnStop->Visible == true)
	{
		this->toolStripStartnStop->Visible = false;
		this->ovládáníArduinaToolStripMenuItem->Checked = false;
		this->ovládáníArduinaToolStripMenuItem1->Checked = false;
	}
	else
	{
		this->toolStripStartnStop->Visible = true;
		this->ovládáníArduinaToolStripMenuItem->Checked = true;
		this->ovládáníArduinaToolStripMenuItem1->Checked = true;
	}
		 }
		 
		 

		 
////////////////////////////////////////////////////////////////////////////
//				Funkce - Kontrola a kompilace
////////////////////////////////////////////////////////////////////////////

//Funkce kontroly kódu
private: System::Void CheckCode_Click(System::Object^  sender, System::EventArgs^  e)
{
	ErrorCode = 0;
	ErrorCount = 0;
	int CheckIndex = 0;
	int LineIndex = 0;
	int NotEnd = 0;
	int NotCode = 0;
	int StartValue = 0;

	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"   INFO - Zahájení kontroly zdrojového kódu. [" + CheckCount + "]");
	this->ConsoleOutput->Items->Insert(0,"");

	String^ ToCheckString = this->CommandBox->Text;
	array<Char>^ ToCheckArray = gcnew array<Char>(ToCheckString->Length);
	StringReader^ sr = gcnew StringReader(ToCheckString);
	sr->Read(ToCheckArray, 0, (ToCheckString->Length));
	String^ ToCheckCommand = "";
	String^ ToCheckValue = "";
	String^ CodeStream = "<";
	try
	{
		for(CheckIndex;((ToCheckArray[CheckIndex]) != ';');CheckIndex++)
		{
			ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
			if(ToCheckArray[CheckIndex] == '\r')
			{
				this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
				ErrorCode = 1;
				ErrorCount++;
				break;
			}
		}
		if(ToCheckArray[CheckIndex] == ';')
		{
			ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
			CheckIndex = CheckIndex + 3;
		}
		else
		{
			CheckIndex = CheckIndex + 2;
		}
		if((ToCheckCommand != "begin ROBO;")&&(ToCheckCommand != "begin ROBO\r"))
		{
			this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí hlavička souboru .ROBO");
			ErrorCode = 1;
			ErrorCount++;
		}
		while(NotEnd == 0)
		{
			LineIndex++;
			ToCheckCommand = "";
			ToCheckValue = "";
			NotCode = 0;
			for(CheckIndex;((ToCheckArray[CheckIndex]) != ';')&&(NotEnd == 0);CheckIndex++)
			{
				if(ToCheckArray[CheckIndex] == ')')
				{
					StartValue = 0;
				}
				if(StartValue == 1)
				{
					ToCheckValue = ToCheckValue + ToCheckArray[CheckIndex];
				}
				if(ToCheckArray[CheckIndex] == '(')
				{
					StartValue = 1;
				}
				if((StartValue == 0)&&(ToCheckArray[CheckIndex] != ')')&&(ToCheckArray[CheckIndex] != '('))
				{
					ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
				}
				if(ToCheckCommand == "//")
				{
					NotCode = 1;
				}
				if(((ToCheckArray[CheckIndex]) != '/')&&((ToCheckArray[CheckIndex-1]) == '/')&&((ToCheckArray[CheckIndex-2]) == '\n'))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Pokud se jedná o komentář, doplňte jeho uvození.");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý symbol '/' na začátku řádku.");
					ErrorCode = 1;
					ErrorCount++;
					NotCode = 1;
				}
				if((ToCheckArray[CheckIndex] == '\r'))
				{
					if(NotCode == 0)
					{
						this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
						ErrorCode = 1;
						ErrorCount++;
					}
					break;
				}
				if(ToCheckCommand == "end")
				{
					NotEnd = 1;
					break;
				}
			}
			if(ToCheckArray[CheckIndex] == ';')
			{
				if((CheckingCommand(ToCheckCommand) == 1)&&(NotCode == 0))
				{
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý příkaz.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingServoValue(ToCheckValue) == 1)&&(NotCode == 0)&&((ToCheckCommand=="ACTUATOR_1")||(ToCheckCommand=="ACTUATOR_2")||(ToCheckCommand=="ACTUATOR_3")||(ToCheckCommand=="ACTUATOR_4")||(ToCheckCommand=="ACTUATOR_5")||(ToCheckCommand=="ACTUATOR_6")||(ToCheckCommand=="ACTUATOR_7")))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 5 v rozsahu 0 - 180");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingSpeedValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="SPEED_"))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty v rozsahu 0 - 20");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingDelayValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="DELAY_"))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 50 v rozsahu 0 - 1000");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
				CheckIndex = CheckIndex + 3;
			}
			else
			{
				CheckIndex = CheckIndex + 2;
			}
		}

		sr->Close();
	}
	catch (Exception ^)
	{
		this->ConsoleOutput->Items->Insert(0,">>> Ujistěte se, že nechybí hlavička a ukončení souboru.");
		this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU - kód neodpovídá souboru .ROBO");
		ErrorCode = 1;
		ErrorCount++;
	}
	this->ConsoleOutput->Items->Insert(0,"");
	if(!ErrorCode)
	{
		this->ConsoleOutput->Items->Insert(0,"   INFO - Kontrola kódu ukončena úspěšně.");
	}
	else
	{
		this->ConsoleOutput->Items->Insert(0,"   CHYBA - Kontrola kódu ukončena s počtem chyb [" + ErrorCount + "].");
	}
	this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
	
	CheckCount++;
	
}


//Kontrola syntaxe příkazu
int CheckingCommand (System::String ^ToCheckCommand)
{
	if(ToCheckCommand == "ACTUATOR_1")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_2")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_3")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_4")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_5")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_6")
	{
		return 0;
	}
	else if(ToCheckCommand == "ACTUATOR_7")
	{
		return 0;
	}
	else if(ToCheckCommand == "SPEED_")
	{
		return 0;
	}
	else if(ToCheckCommand == "DELAY_")
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Kontrola hodnoty příkazu u serva
int CheckingServoValue (System::String ^ToCheckValue)
{
	if(ToCheckValue == "0")
	{
		return 0;
	}
	else if(ToCheckValue == "5")
	{
		return 0;
	}
	else if(ToCheckValue == "10")
	{
		return 0;
	}
	else if(ToCheckValue == "15")
	{
		return 0;
	}
	else if(ToCheckValue == "20")
	{
		return 0;
	}
	else if(ToCheckValue == "25")
	{
		return 0;
	}
	else if(ToCheckValue == "30")
	{
		return 0;
	}
	else if(ToCheckValue == "35")
	{
		return 0;
	}
	else if(ToCheckValue == "40")
	{
		return 0;
	}
	else if(ToCheckValue == "45")
	{
		return 0;
	}
	else if(ToCheckValue == "50")
	{
		return 0;
	}
	else if(ToCheckValue == "55")
	{
		return 0;
	}
	else if(ToCheckValue == "60")
	{
		return 0;
	}
	else if(ToCheckValue == "65")
	{
		return 0;
	}
	else if(ToCheckValue == "70")
	{
		return 0;
	}
	else if(ToCheckValue == "75")
	{
		return 0;
	}
	else if(ToCheckValue == "80")
	{
		return 0;
	}
	else if(ToCheckValue == "85")
	{
		return 0;
	}
	else if(ToCheckValue == "90")
	{
		return 0;
	}
	else if(ToCheckValue == "95")
	{
		return 0;
	}
	else if(ToCheckValue == "100")
	{
		return 0;
	}
	else if(ToCheckValue == "105")
	{
		return 0;
	}
	else if(ToCheckValue == "110")
	{
		return 0;
	}
	else if(ToCheckValue == "115")
	{
		return 0;
	}
	else if(ToCheckValue == "120")
	{
		return 0;
	}
	else if(ToCheckValue == "125")
	{
		return 0;
	}
	else if(ToCheckValue == "130")
	{
		return 0;
	}
	else if(ToCheckValue == "135")
	{
		return 0;
	}
	else if(ToCheckValue == "140")
	{
		return 0;
	}
	else if(ToCheckValue == "145")
	{
		return 0;
	}
	else if(ToCheckValue == "150")
	{
		return 0;
	}
	else if(ToCheckValue == "155")
	{
		return 0;
	}
	else if(ToCheckValue == "160")
	{
		return 0;
	}
	else if(ToCheckValue == "165")
	{
		return 0;
	}
	else if(ToCheckValue == "170")
	{
		return 0;
	}
	else if(ToCheckValue == "175")
	{
		return 0;
	}
	else if(ToCheckValue == "180")
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Kontrola hodnoty příkazu u rychlosti
int CheckingSpeedValue (System::String ^ToCheckValue)
{
	if(ToCheckValue == "0")
	{
		return 0;
	}
	if(ToCheckValue == "1")
	{
		return 0;
	}
	if(ToCheckValue == "2")
	{
		return 0;
	}
	if(ToCheckValue == "3")
	{
		return 0;
	}
	if(ToCheckValue == "4")
	{
		return 0;
	}
	if(ToCheckValue == "5")
	{
		return 0;
	}
	if(ToCheckValue == "6")
	{
		return 0;
	}
	if(ToCheckValue == "7")
	{
		return 0;
	}
	if(ToCheckValue == "8")
	{
		return 0;
	}
	if(ToCheckValue == "9")
	{
		return 0;
	}
	if(ToCheckValue == "10")
	{
		return 0;
	}
	if(ToCheckValue == "11")
	{
		return 0;
	}
	if(ToCheckValue == "12")
	{
		return 0;
	}
	if(ToCheckValue == "13")
	{
		return 0;
	}
	if(ToCheckValue == "14")
	{
		return 0;
	}
	if(ToCheckValue == "15")
	{
		return 0;
	}
	if(ToCheckValue == "16")
	{
		return 0;
	}
	if(ToCheckValue == "17")
	{
		return 0;
	}
	if(ToCheckValue == "18")
	{
		return 0;
	}
	if(ToCheckValue == "19")
	{
		return 0;
	}
	if(ToCheckValue == "20")
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


//Kontrola hodnoty příkazu u prodlevy
int CheckingDelayValue (System::String ^ToCheckValue)
{
	if(ToCheckValue == "0")
	{
		return 0;
	}
	if(ToCheckValue == "50")
	{
		return 0;
	}
	if(ToCheckValue == "100")
	{
		return 0;
	}
	if(ToCheckValue == "150")
	{
		return 0;
	}
	if(ToCheckValue == "200")
	{
		return 0;
	}
	if(ToCheckValue == "250")
	{
		return 0;
	}
	if(ToCheckValue == "300")
	{
		return 0;
	}
	if(ToCheckValue == "350")
	{
		return 0;
	}
	if(ToCheckValue == "400")
	{
		return 0;
	}
	if(ToCheckValue == "450")
	{
		return 0;
	}
	if(ToCheckValue == "500")
	{
		return 0;
	}
	if(ToCheckValue == "550")
	{
		return 0;
	}
	if(ToCheckValue == "600")
	{
		return 0;
	}
	if(ToCheckValue == "650")
	{
		return 0;
	}
	if(ToCheckValue == "700")
	{
		return 0;
	}
	if(ToCheckValue == "750")
	{
		return 0;
	}
	if(ToCheckValue == "800")
	{
		return 0;
	}
	if(ToCheckValue == "850")
	{
		return 0;
	}
	if(ToCheckValue == "900")
	{
		return 0;
	}
	if(ToCheckValue == "950")
	{
		return 0;
	}
	if(ToCheckValue == "1000")
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Kompilace příkazu
String ^CompilationCommand (System::String ^ToCheckCommand)
{
	char CommandBufferChar = '0';
	String ^CommandBufferStr = "";

	if(ToCheckCommand == "ACTUATOR_1")
	{
		return "A";
	}
	else if(ToCheckCommand == "ACTUATOR_2")
	{
		return "B";
	}
	else if(ToCheckCommand == "ACTUATOR_3")
	{
		return "C";
	}
	else if(ToCheckCommand == "ACTUATOR_4")
	{
		return "D";
	}
	else if(ToCheckCommand == "ACTUATOR_5")
	{
		return "E";
	}
	else if(ToCheckCommand == "ACTUATOR_6")
	{
		return "F";
	}
	else if(ToCheckCommand == "ACTUATOR_7")
	{
		return "G";
	}
	else if(ToCheckCommand == "SPEED_")
	{
		return "Z";
	}
	else if(ToCheckCommand == "DELAY_")
	{
		return "Y";
	}
	else
	{
		return "!";
	}

}

//Kompilace hodnoty příkazu u serva
String ^CompilationServoValue (System::String ^ToCheckValue)
{
	char CommandBufferChar = '0';
	String ^CommandBufferStr = "";
	
	if(ToCheckValue == "0")
	{
		return "a";
	}
	if(ToCheckValue == "5")
	{
		return "b";
	}
	if(ToCheckValue == "10")
	{
		return "c";
	}
	if(ToCheckValue == "15")
	{
		return "d";
	}
	if(ToCheckValue == "20")
	{
		return "e";
	}
	if(ToCheckValue == "25")
	{
		return "f";
	}
	if(ToCheckValue == "30")
	{
		return "g";
	}
	if(ToCheckValue == "35")
	{
		return "h";
	}
	if(ToCheckValue == "40")
	{
		return "i";
	}
	if(ToCheckValue == "45")
	{
		return "j";
	}
	if(ToCheckValue == "50")
	{
		return "k";
	}
	if(ToCheckValue == "55")
	{
		return "l";
	}
	if(ToCheckValue == "60")
	{
		return "m";
	}
	if(ToCheckValue == "65")
	{
		return "n";
	}
	if(ToCheckValue == "70")
	{
		return "o";
	}
	if(ToCheckValue == "75")
	{
		return "p";
	}
	if(ToCheckValue == "80")
	{
		return "q";
	}
	if(ToCheckValue == "85")
	{
		return "r";
	}
	if(ToCheckValue == "90")
	{
		return "s";
	}
	if(ToCheckValue == "95")
	{
		return "t";
	}
	if(ToCheckValue == "100")
	{
		return "u";
	}
	if(ToCheckValue == "105")
	{
		return "v";
	}
	if(ToCheckValue == "110")
	{
		return "w";
	}
	if(ToCheckValue == "115")
	{
		return "x";
	}
	if(ToCheckValue == "120")
	{
		return "y";
	}
	if(ToCheckValue == "125")
	{
		return "z";
	}
	if(ToCheckValue == "130")
	{
		return "0";
	}
	if(ToCheckValue == "135")
	{
		return "1";
	}
	if(ToCheckValue == "140")
	{
		return "2";
	}
	if(ToCheckValue == "145")
	{
		return "3";
	}
	if(ToCheckValue == "150")
	{
		return "4";
	}
	if(ToCheckValue == "155")
	{
		return "5";
	}
	if(ToCheckValue == "160")
	{
		return "6";
	}
	if(ToCheckValue == "165")
	{
		return "7";
	}
	if(ToCheckValue == "170")
	{
		return "8";
	}
	if(ToCheckValue == "175")
	{
		return "9";
	}
	if(ToCheckValue == "180")
	{
		return "@";
	}
	else
	{
		return "!";
	}

}

//Kompilace hodnoty příkazu u rychlosti
String ^CompilationSpeedValue (System::String ^ToCheckValue)
{
	char CommandBufferChar = '0';
	String ^CommandBufferStr = "";
	
	if(ToCheckValue == "0")
	{
		return "a";
	}
	if(ToCheckValue == "1")
	{
		return "b";
	}
	if(ToCheckValue == "2")
	{
		return "c";
	}
	if(ToCheckValue == "3")
	{
		return "d";
	}
	if(ToCheckValue == "4")
	{
		return "e";
	}
	if(ToCheckValue == "5")
	{
		return "f";
	}
	if(ToCheckValue == "6")
	{
		return "g";
	}
	if(ToCheckValue == "7")
	{
		return "h";
	}
	if(ToCheckValue == "8")
	{
		return "i";
	}
	if(ToCheckValue == "9")
	{
		return "j";
	}
	if(ToCheckValue == "10")
	{
		return "k";
	}
	if(ToCheckValue == "11")
	{
		return "l";
	}
	if(ToCheckValue == "12")
	{
		return "m";
	}
	if(ToCheckValue == "13")
	{
		return "n";
	}
	if(ToCheckValue == "14")
	{
		return "o";
	}
	if(ToCheckValue == "15")
	{
		return "p";
	}
	if(ToCheckValue == "16")
	{
		return "q";
	}
	if(ToCheckValue == "17")
	{
		return "r";
	}
	if(ToCheckValue == "18")
	{
		return "s";
	}
	if(ToCheckValue == "19")
	{
		return "t";
	}
	if(ToCheckValue == "20")
	{
		return "u";
	}
	else
	{
		return "!";
	}

}

//Kontrola hodnoty příkazu u prodlevy
String ^CompilationDelayValue (System::String ^ToCheckValue)
{
	char CommandBufferChar = '0';
	String ^CommandBufferStr = "";
	
	if(ToCheckValue == "0")
	{
		return "a";
	}
	if(ToCheckValue == "50")
	{
		return "b";
	}
	if(ToCheckValue == "100")
	{
		return "c";
	}
	if(ToCheckValue == "150")
	{
		return "d";
	}
	if(ToCheckValue == "200")
	{
		return "e";
	}
	if(ToCheckValue == "250")
	{
		return "f";
	}
	if(ToCheckValue == "300")
	{
		return "g";
	}
	if(ToCheckValue == "350")
	{
		return "h";
	}
	if(ToCheckValue == "400")
	{
		return "i";
	}
	if(ToCheckValue == "450")
	{
		return "j";
	}
	if(ToCheckValue == "500")
	{
		return "k";
	}
	if(ToCheckValue == "550")
	{
		return "l";
	}
	if(ToCheckValue == "600")
	{
		return "m";
	}
	if(ToCheckValue == "650")
	{
		return "n";
	}
	if(ToCheckValue == "700")
	{
		return "o";
	}
	if(ToCheckValue == "750")
	{
		return "p";
	}
	if(ToCheckValue == "800")
	{
		return "q";
	}
	if(ToCheckValue == "850")
	{
		return "r";
	}
	if(ToCheckValue == "900")
	{
		return "s";
	}
	if(ToCheckValue == "950")
	{
		return "t";
	}
	if(ToCheckValue == "1000")
	{
		return "u";
	}
	else
	{
		return "!";
	}

}

//Funkce pro kontrolu, kompilaci a poslání kódu
private: System::Void toolStripCompileButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
	if(mainSerialPort->IsOpen == 1)
	{
		ErrorCode = 0;
		ErrorCount = 0;
		int CheckIndex = 0;
		int LineIndex = 0;
		int NotEnd = 0;
		int NotCode = 0;
		int StartValue = 0;

		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"");
		this->ConsoleOutput->Items->Insert(0,"   INFO - Zahájení kontroly zdrojového kódu. [" + CheckCount + "]");
		this->ConsoleOutput->Items->Insert(0,"");

		String^ ToCheckString = this->CommandBox->Text;
		array<Char>^ ToCheckArray = gcnew array<Char>(ToCheckString->Length);
		StringReader^ sr = gcnew StringReader(ToCheckString);
		sr->Read(ToCheckArray, 0, (ToCheckString->Length));
		String^ ToCheckCommand = "";
		String^ ToCheckValue = "";
		String^ CodeStream = "<";
		try
		{
			for(CheckIndex;((ToCheckArray[CheckIndex]) != ';');CheckIndex++)
			{
				ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
		
				if(ToCheckArray[CheckIndex] == '\r')
				{
					this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
					ErrorCode = 1;
					ErrorCount++;
					break;
				}
			}
			if(ToCheckArray[CheckIndex] == ';')
			{
				ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
				CheckIndex = CheckIndex + 3;
			}
			else
			{
				CheckIndex = CheckIndex + 2;
			}
	
			if((ToCheckCommand != "begin ROBO;")&&(ToCheckCommand != "begin ROBO\r"))
			{
				this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí hlavička souboru .ROBO");
				ErrorCode = 1;
				ErrorCount++;
			}
	
			while(NotEnd == 0)
			{
				LineIndex++;
				ToCheckCommand = "";
				ToCheckValue = "";
				NotCode = 0;
				for(CheckIndex;((ToCheckArray[CheckIndex]) != ';')&&(NotEnd == 0);CheckIndex++)
				{
					if(ToCheckArray[CheckIndex] == ')')
					{
						StartValue = 0;
					}
	
					if(StartValue == 1)
					{
						ToCheckValue = ToCheckValue + ToCheckArray[CheckIndex];
					}

					if(ToCheckArray[CheckIndex] == '(')
					{
						StartValue = 1;
					}
	
					if((StartValue == 0)&&(ToCheckArray[CheckIndex] != ')')&&(ToCheckArray[CheckIndex] != '('))
					{
						ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
					}

		
					if(ToCheckCommand == "//")
					{
						NotCode = 1;
					}
					if(((ToCheckArray[CheckIndex]) != '/')&&((ToCheckArray[CheckIndex-1]) == '/')&&((ToCheckArray[CheckIndex-2]) == '\n'))
					{
						this->ConsoleOutput->Items->Insert(0,">>> Pokud se jedná o komentář, doplňte jeho uvození.");
						this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý symbol '/' na začátku řádku.");
						ErrorCode = 1;
						ErrorCount++;
						NotCode = 1;
					}
					if((ToCheckArray[CheckIndex] == '\r'))
					{
						if(NotCode == 0)
						{
							this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
							ErrorCode = 1;
							ErrorCount++;
						}
						break;
					}
					if(ToCheckCommand == "end")
					{
						NotEnd = 1;
						break;
					}
				}
				if(ToCheckArray[CheckIndex] == ';')
				{
					if((CheckingCommand(ToCheckCommand) == 1)&&(NotCode == 0))
					{
						this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý příkaz.");
						ErrorCode = 1;
						ErrorCount++;
					}
					if((CheckingServoValue(ToCheckValue) == 1)&&(NotCode == 0)&&((ToCheckCommand=="ACTUATOR_1")||(ToCheckCommand=="ACTUATOR_2")||(ToCheckCommand=="ACTUATOR_3")||(ToCheckCommand=="ACTUATOR_4")||(ToCheckCommand=="ACTUATOR_5")||(ToCheckCommand=="ACTUATOR_6")||(ToCheckCommand=="ACTUATOR_7")))
					{
						this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 5 v rozsahu 0 - 180");
						this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
						ErrorCode = 1;
						ErrorCount++;
					}
					if((CheckingSpeedValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="SPEED_"))
					{
						this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty v rozsahu 0 - 20");
						this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
						ErrorCode = 1;
						ErrorCount++;
					}
					if((CheckingDelayValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="DELAY_"))
					{
						this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 50 v rozsahu 0 - 1000");
						this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
						ErrorCode = 1;
						ErrorCount++;
					}
					if((CheckingCommand(ToCheckCommand) == 0)&&(NotCode == 0))
					{
						CodeStream = CodeStream + CompilationCommand(ToCheckCommand);
						if((ToCheckCommand=="ACTUATOR_1")||(ToCheckCommand=="ACTUATOR_2")||(ToCheckCommand=="ACTUATOR_3")||(ToCheckCommand=="ACTUATOR_4")||(ToCheckCommand=="ACTUATOR_5")||(ToCheckCommand=="ACTUATOR_6")||(ToCheckCommand=="ACTUATOR_7"))
						{
							CodeStream = CodeStream + CompilationServoValue(ToCheckValue);
						}
						if(ToCheckCommand=="SPEED_")
						{
							CodeStream = CodeStream + CompilationSpeedValue(ToCheckValue);
						}
						if(ToCheckCommand=="DELAY_")
						{
							CodeStream = CodeStream + CompilationDelayValue(ToCheckValue);
						}
					}
					ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
					CheckIndex = CheckIndex + 3;
				}
				else
				{
					CheckIndex = CheckIndex + 2;
				}
				
			//this->ConsoleOutput->Items->Insert(0,"Value = " + ToCheckValue);
			//this->ConsoleOutput->Items->Insert(0,"Code = " + CodeStream);
			}

			sr->Close();
		}
		catch (Exception ^)
		{
			this->ConsoleOutput->Items->Insert(0,">>> Ujistěte se, že nechybí hlavička a ukončení souboru.");
			this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU - kód neodpovídá souboru .ROBO");
			ErrorCode = 1;
			ErrorCount++;
		}
		this->ConsoleOutput->Items->Insert(0,"");
		if(!ErrorCode)
		{
			this->ConsoleOutput->Items->Insert(0,"   INFO - Kontrola kódu ukončena úspěšně.");
			this->ConsoleOutput->Items->Insert(0,"   INFO - Kompilace kódu ukončena úspěšně.");
			CodeStream = CodeStream + ">";
			try
			{
				this->mainSerialPort->Write(CodeStream);
			}
			catch (Exception ^)
			{
				DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
				String ^ActualDiagTit = "Chyba - Port není dostupný";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();
				ReceivedFlg=0;
				closeSerial();
			}
		}
		else
		{
			this->ConsoleOutput->Items->Insert(0,"   CHYBA - Kontrola kódu ukončena s počtem chyb [" + ErrorCount + "].");
			this->ConsoleOutput->Items->Insert(0,"   CHYBA - Program nebyl poslán na port kvůli chybám v kódu.");
		}
		this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
		
		CheckCount++;
	}
	else
	{
		this->ConsoleOutput->Items->Insert(0,"   CHYBA - Zařízení není připojeno. Připojte ho a opakujte znovu.");
	}	
}





private: System::Void ClearConsoleOutput(System::Object^  sender, System::EventArgs^  e)
{
	this->ConsoleOutput->Items->Clear();
}


//Číslo řádku dle polohy kurzoru
private: System::Void LineNumber_Tick(System::Object^  sender, System::EventArgs^  e)
{
	int LineNumberInt = (this->CommandBox->GetLineFromCharIndex(this->CommandBox->SelectionStart));
	char LineNumberChar[12];
	sprintf(LineNumberChar, "%d", LineNumberInt);
	String^ buffer = gcnew String(LineNumberChar);
	this->LineNumber->Text = buffer;
}




		 


private: System::Void toolStripGraphToTextButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
	long FlowEndLocal = this->flowLayoutWorkSpace->Controls->IndexOf(this->endBlock);
	long FlowIndexLocal = 0;
	String^ buffera = "";
			 for(FlowIndexLocal; FlowIndexLocal<=FlowEndLocal; FlowIndexLocal++)
			 {
				 buffera = buffera + this->GraphicOutput->GetItemText(this->GraphicOutput->Items[FlowIndexLocal]);
				 this->CommandBox->Text = buffera;
			 }

		 }


private: System::Void rozvrženíKloubůToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ImgWin^ Img = gcnew ImgWin();
	Img->Show();
		 }


private: System::Void MainWin_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->onlineBlockServo1->BlockName->Text = "ACTUATOR_1";
			 this->onlineBlockServo1->trackBar->BackColor = System::Drawing::Color::DarkGray;
			 this->onlineBlockServo1->colorStrip->BackColor = System::Drawing::Color::DarkGray;
			 this->onlineBlockServo2->BlockName->Text = "ACTUATOR_2";
			 this->onlineBlockServo2->trackBar->BackColor = System::Drawing::Color::DarkOrange;
			 this->onlineBlockServo2->colorStrip->BackColor = System::Drawing::Color::DarkOrange;
			 this->onlineBlockServo3->BlockName->Text = "ACTUATOR_3";
			 this->onlineBlockServo3->trackBar->BackColor = System::Drawing::Color::Goldenrod;
			 this->onlineBlockServo3->colorStrip->BackColor = System::Drawing::Color::Goldenrod;
			 this->onlineBlockServo4->BlockName->Text = "ACTUATOR_4";
			 this->onlineBlockServo4->trackBar->BackColor = System::Drawing::Color::YellowGreen;
			 this->onlineBlockServo4->colorStrip->BackColor = System::Drawing::Color::YellowGreen;
			 this->onlineBlockServo5->BlockName->Text = "ACTUATOR_5";
			 this->onlineBlockServo5->trackBar->BackColor = System::Drawing::Color::Turquoise;
			 this->onlineBlockServo5->colorStrip->BackColor = System::Drawing::Color::Turquoise;
			 this->onlineBlockServo6->BlockName->Text = "ACTUATOR_6";
			 this->onlineBlockServo6->trackBar->BackColor = System::Drawing::Color::SteelBlue;
			 this->onlineBlockServo6->colorStrip->BackColor = System::Drawing::Color::SteelBlue;
			 this->onlineBlockServo7->BlockName->Text = "ACTUATOR_7";
			 this->onlineBlockServo7->trackBar->BackColor = System::Drawing::Color::Violet;
			 this->onlineBlockServo7->colorStrip->BackColor = System::Drawing::Color::Violet;
			 this->onlineBlockSpeed->BlockName->Text = "SPEED_";
			 this->onlineBlockSpeed->trackBar->BackColor = System::Drawing::Color::Yellow;
			 this->onlineBlockSpeed->colorStrip->BackColor = System::Drawing::Color::Yellow;

			 try
			 {
				this->onlineBlockServo1->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseAroundBlock.png");
				this->onlineBlockServo2->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseUpDownBlock.png");
				 this->onlineBlockServo3->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleUpDownBlock.png");
				 this->onlineBlockServo4->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleRotateBlock.png");
				 this->onlineBlockServo5->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawUpDownBlock.png");
				 this->onlineBlockServo6->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawRotateBlock.png");
				 this->onlineBlockServo7->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawOpenCloseBlock.png");
				 this->onlineBlockSpeed->BlockImage->BackgroundImage = System::Drawing::Image::FromFile("AppData\\SpeedBlock.png");
			 }
			catch (Exception ^)
			{
				DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Chyba v načítání grafiky aplikace. Chyba je pravděpodobně způsobena nenalezením adresáře AppData nebo některého jejího obsahu. Nakopírujte ze zálohy adresář do umístnění souboru aplikace.";
				String ^ActualDiagTit = "Chyba - Chyba souborů aplikace";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				ReceivedFlg=0;
				Dialog->ShowDialog();
			}


			 this->onlineBlockServo1->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo1_MouseUp);
			 this->onlineBlockServo2->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo2_MouseUp);
			 this->onlineBlockServo3->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo3_MouseUp);
			 this->onlineBlockServo4->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo4_MouseUp);
			 this->onlineBlockServo5->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo5_MouseUp);
			 this->onlineBlockServo6->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo6_MouseUp);
			 this->onlineBlockServo7->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Servo7_MouseUp);
			 this->onlineBlockSpeed->trackBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWin::Speed_MouseUp);

			 this->onlineBlockSpeed->trackBar->Value = 15;
			 this->onlineBlockSpeed->trackBar->Maximum = 20;
			 this->onlineBlockSpeed->Max->Text = "20";
			 
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStripSerial->Location = System::Drawing::Point(212, 0);
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStripCode->Location = System::Drawing::Point(534, 0);
			this->toolStripStartnStop->Location = System::Drawing::Point(3, 25);
			this->toolStripSerialCommand->Location = System::Drawing::Point(86, 25);
		 }
		 
private: System::Void Servo1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_1" + this->onlineBlockServo1->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}

		 
private: System::Void Servo2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_2" + this->onlineBlockServo2->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
private: System::Void Servo3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_3" + this->onlineBlockServo3->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
private: System::Void Servo4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_4" + this->onlineBlockServo4->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
private: System::Void Servo5_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_5" + this->onlineBlockServo5->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
private: System::Void Servo6_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_6" + this->onlineBlockServo6->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
private: System::Void Servo7_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		String^ buffer;
		buffer = "ACTUATOR_7" + this->onlineBlockServo7->ActualValue->Text;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}
		 
		 
private: System::Void Speed_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(mainSerialPort->IsOpen == 1)
	{
		int num = 20-(this->onlineBlockSpeed->trackBar->Value);
		char str[12];
		num = num;
		sprintf(str, "%d", num);
		String^ buffer = gcnew String(str);
		buffer = "SPEED_" + buffer;
		try
		{
			this->mainSerialPort->Write(buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
}

private: System::Void toolStripStartButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
	if(mainSerialPort->IsOpen == 1)
	{
		try
		{
			this->mainSerialPort->Write("start");
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
	}
		 }
private: System::Void toolStripStopButton_Click(System::Object^  sender, System::EventArgs^  e) {
 
	if(mainSerialPort->IsOpen == 1)
	{
		try
		{
			this->mainSerialPort->Write("stop");
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			ReceivedFlg=0;
			Dialog->ShowDialog();
			closeSerial();
		}
		 }
		 }
private: System::Void toolStripTextToGrafButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	ErrorCode = 0;
	ErrorCount = 0;
	int CheckIndex = 0;
	int LineIndex = 0;
	int NotEnd = 0;
	int NotCode = 0;
	int StartValue = 0;

	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"");
	this->ConsoleOutput->Items->Insert(0,"   INFO - Zahájení kontroly zdrojového kódu. [" + CheckCount + "]");
	this->ConsoleOutput->Items->Insert(0,"");

	String^ ToCheckString = this->CommandBox->Text;
	array<Char>^ ToCheckArray = gcnew array<Char>(ToCheckString->Length);
	StringReader^ sr = gcnew StringReader(ToCheckString);
	sr->Read(ToCheckArray, 0, (ToCheckString->Length));
	String^ ToCheckCommand = "";
	String^ ToCheckValue = "";
	String^ CodeStream = "<";
	try
	{
		for(CheckIndex;((ToCheckArray[CheckIndex]) != ';');CheckIndex++)
		{
			ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
			if(ToCheckArray[CheckIndex] == '\r')
			{
				this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
				ErrorCode = 1;
				ErrorCount++;
				break;
			}
		}
		if(ToCheckArray[CheckIndex] == ';')
		{
			ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
			CheckIndex = CheckIndex + 3;
		}
		else
		{
			CheckIndex = CheckIndex + 2;
		}
		if((ToCheckCommand != "begin ROBO;")&&(ToCheckCommand != "begin ROBO\r"))
		{
			this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí hlavička souboru .ROBO");
			ErrorCode = 1;
			ErrorCount++;
		}
		while(NotEnd == 0)
		{
			LineIndex++;
			ToCheckCommand = "";
			ToCheckValue = "";
			NotCode = 0;
			for(CheckIndex;((ToCheckArray[CheckIndex]) != ';')&&(NotEnd == 0);CheckIndex++)
			{
				if(ToCheckArray[CheckIndex] == ')')
				{
					StartValue = 0;
				}
				if(StartValue == 1)
				{
					ToCheckValue = ToCheckValue + ToCheckArray[CheckIndex];
				}
				if(ToCheckArray[CheckIndex] == '(')
				{
					StartValue = 1;
				}
				if((StartValue == 0)&&(ToCheckArray[CheckIndex] != ')')&&(ToCheckArray[CheckIndex] != '('))
				{
					ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
				}
				if(ToCheckCommand == "//")
				{
					NotCode = 1;
				}
				if(((ToCheckArray[CheckIndex]) != '/')&&((ToCheckArray[CheckIndex-1]) == '/')&&((ToCheckArray[CheckIndex-2]) == '\n'))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Pokud se jedná o komentář, doplňte jeho uvození.");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý symbol '/' na začátku řádku.");
					ErrorCode = 1;
					ErrorCount++;
					NotCode = 1;
				}
				if((ToCheckArray[CheckIndex] == '\r'))
				{
					if(NotCode == 0)
					{
						this->ConsoleOutput->Items->Insert(0,"CHYBA KÓDU na řádku [" + LineIndex + "] - chybí ukončení příkazu ';'.");
						ErrorCode = 1;
						ErrorCount++;
					}
					break;
				}
				if(ToCheckCommand == "end")
				{
					NotEnd = 1;
					break;
				}
			}
			if(ToCheckArray[CheckIndex] == ';')
			{
				if((CheckingCommand(ToCheckCommand) == 1)&&(NotCode == 0))
				{
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba syntaxe, neznámý příkaz.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingServoValue(ToCheckValue) == 1)&&(NotCode == 0)&&((ToCheckCommand=="ACTUATOR_1")||(ToCheckCommand=="ACTUATOR_2")||(ToCheckCommand=="ACTUATOR_3")||(ToCheckCommand=="ACTUATOR_4")||(ToCheckCommand=="ACTUATOR_5")||(ToCheckCommand=="ACTUATOR_6")||(ToCheckCommand=="ACTUATOR_7")))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 5 v rozsahu 0 - 180");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingSpeedValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="SPEED_"))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty v rozsahu 0 - 20");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if((CheckingDelayValue(ToCheckValue) == 1)&&(NotCode == 0)&&(ToCheckCommand=="DELAY_"))
				{
					this->ConsoleOutput->Items->Insert(0,">>> Zvolte hodnoty dělitelné číslem 50 v rozsahu 0 - 1000");
					this->ConsoleOutput->Items->Insert(0,"CHYBA na řádku [" + LineIndex + "] - chyba rozsahu.");
					ErrorCode = 1;
					ErrorCount++;
				}
				if(ErrorCode == 0)
				{
					GraphicBlock ^novy = gcnew GraphicBlock();
					long FlowEndLocal = this->flowLayoutWorkSpace->Controls->IndexOf(this->endBlock);
					novy->Click += gcnew EventHandler(this, &MainWin::GraphicBlock_Click);
					novy->LocationChanged += gcnew EventHandler(this, &MainWin::GraphicBlock_LocationChange);
					// Konfigurace bloku typu ACTUATOR_1 a jiné
					if(ToCheckCommand == "ACTUATOR_1")
					{
						// Konfigurace názvu, barvy, ikony a přidání řádku do náhledu kódu
						novy->BlockName->Text = "ACTUATOR_1";
						novy->BackColor = Color::DarkGray;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseAroundBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_1("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_2")
					{
						novy->BlockName->Text = "ACTUATOR_2";
						novy->BackColor = Color::DarkOrange;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\BaseUpDownBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_2("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_3")
					{
						novy->BlockName->Text = "ACTUATOR_3";
						novy->BackColor = Color::Goldenrod;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleUpDownBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_3("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_4")
					{
						novy->BlockName->Text = "ACTUATOR_4";
						novy->BackColor = Color::YellowGreen;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\HandleRotateBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_4("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_5")
					{
						novy->BlockName->Text = "ACTUATOR_5";
						novy->BackColor = Color::Turquoise;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawUpDownBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_5("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_6")
					{
						novy->BlockName->Text = "ACTUATOR_6";
						novy->BackColor = Color::SteelBlue;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawRotateBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_6("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "ACTUATOR_7")
					{
						novy->BlockName->Text = "ACTUATOR_7";
						novy->BackColor = Color::Violet;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\JawOpenCloseBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"ACTUATOR_7("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "SPEED_")
					{
						novy->BlockName->Text = "SPEED_";
						novy->BackColor = Color::Yellow;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->BlockValue->Increment = 1;
						novy->BlockValue->Minimum = 1;
						novy->BlockValue->Maximum = 20;
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\SpeedBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"SPEED_("+ToCheckValue+");\r\n");
					}
					if(ToCheckCommand == "DELAY_")
					{
						novy->BlockName->Text = "DELAY_";
						novy->BackColor = Color::Teal;
						novy->BlockValue->Increment = 50;
						novy->BlockValue->Minimum = 0;
						novy->BlockValue->Maximum = 1000;
						novy->BlockValue->Value = System::Convert::ToDecimal(ToCheckValue);
						novy->pictureBox1->BackgroundImage = System::Drawing::Image::FromFile("AppData\\DelayBlock.png");
						this->GraphicOutput->Items->Insert(FlowEndLocal,"DELAY_("+ToCheckValue+");\r\n");
					}
					// Přidání bloku, posun bloku před END
					novy->BlockValue->ValueChanged += gcnew EventHandler(this, &MainWin::BlockValueChanged);
					this->flowLayoutWorkSpace->Controls->Add(novy);
					this->flowLayoutWorkSpace->Controls->SetChildIndex(novy, FlowEndLocal);
					long FlowIndexLocal = this->flowLayoutWorkSpace->Controls->IndexOf(novy);
				}
				ToCheckCommand = ToCheckCommand + ToCheckArray[CheckIndex];
				CheckIndex = CheckIndex + 3;
			}
			else
			{
				CheckIndex = CheckIndex + 2;
			}
		}

		sr->Close();
	}
	catch (Exception ^)
	{
		this->ConsoleOutput->Items->Insert(0,">>> Pokud problém přetrvává, nahlašte to.");
		this->ConsoleOutput->Items->Insert(0,">>> Ujistěte se, že nechybí hlavička a ukončení souboru.");
		this->ConsoleOutput->Items->Insert(0,"CHYBA KOMPILACE - kód neodpovídá souboru .ROBO");
		ErrorCode = 1;
		ErrorCount++;
	}
	this->ConsoleOutput->Items->Insert(0,"");
	if(!ErrorCode)
	{
		this->ConsoleOutput->Items->Insert(0,"   INFO - Kontrola kódu ukončena úspěšně.");
		this->ConsoleOutput->Items->Insert(0,"   INFO - Kód byl úspěšně převeden do grafického režimu.");
	}
	else
	{
		this->ConsoleOutput->Items->Insert(0,"   CHYBA - Kontrola kódu ukončena s počtem chyb [" + ErrorCount + "].");
		this->ConsoleOutput->Items->Insert(0,"   CHYBA - Převedený kód není kompletní. Opravte chybu v text. nebo graf. režimu.");
	}
	this->ConsoleOutput->Items->Insert(0,"-------------------------------------------------------");
	
	CheckCount++;

}
private: System::Void mainSerialPort_ErrorReceived(System::Object^  sender, System::IO::Ports::SerialErrorReceivedEventArgs^  e) {
			 DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Neznámá chyba portu.";
				String ^ActualDiagTit = "Chyba - Error Received";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();
		 }
private: System::Void mainSerialPort_PinChanged(System::Object^  sender, System::IO::Ports::SerialPinChangedEventArgs^  e) {
			 /*DialogWin^ Dialog = gcnew DialogWin();
				Dialog->DialogText->Text = "Develop";
				String ^ActualDiagTit = "Info - Pin Changed";
				Dialog->Text = ActualDiagTit;
				Dialog->DialogTitle->Text = ActualDiagTit;
				Dialog->Yes->Visible = false;
				Dialog->Continue->Visible = true;
				Dialog->No->Visible = false;
				Dialog->ShowDialog();*/
		 }


private: System::Void CommandPrompt_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if((mainSerialPort->IsOpen == 1)&&(e->KeyCode == Keys::Enter))
	{
		try
		{
			this->mainSerialPort->Write(this->toolStripCommandLine->Text);
			String^ buffer = this->toolStripCommandLine->Text;
			String^ Snd = "Send:  ";
			buffer = Snd + buffer;
			this->ConsoleOutput->Items->Insert(0,buffer);
		}
		catch (Exception ^)
		{
			DialogWin^ Dialog = gcnew DialogWin();
			Dialog->DialogText->Text = "Chyba v zápisu do seriového portu. Zařízení bylo pravděpodobně odpojeno";
			String ^ActualDiagTit = "Chyba - Port není dostupný";
			Dialog->Text = ActualDiagTit;
			Dialog->DialogTitle->Text = ActualDiagTit;
			Dialog->Yes->Visible = false;
			Dialog->Continue->Visible = true;
			Dialog->No->Visible = false;
			Dialog->ShowDialog();
			ReceivedFlg=0;
			closeSerial();
		}
		this->toolStripCommandLine->Text = "";
	}
}

private: System::Void stránkyAplikaceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ShellExecuteA(NULL, "open", "WebBrowser.exe", NULL, NULL, SW_SHOWNORMAL);
		 }

private: System::Void MainWin_Closed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 closeSerial();
		 }
};
}


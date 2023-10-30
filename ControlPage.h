/*
	Copyrignt (C) 2007 Piotr J. Socko (psocko@gmail.com)

	This file is part of PassPort.

    PassPort is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    PassPort is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PassPort; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::ServiceProcess;
using namespace System::Threading;


namespace PassPort {

	/// <summary>
	/// Summary for ControlPage
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ControlPage : public System::Windows::Forms::Form
	{
	public:
		ControlPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		System::Void WaitForDialogClose();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ControlPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  stoppedRadio;

	private: System::Windows::Forms::RadioButton^  startedRadio;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  defineViewForwards;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  stopButton;

	private: System::Windows::Forms::Button^  restartButton;

	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::ListBox^  eventLog;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  refreshLog;
	private: System::Windows::Forms::NotifyIcon^  PassPortTrayIcon;
	private: System::Windows::Forms::ContextMenuStrip^  ContextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RestoreToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  ApplicationMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  ApplicationMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  ExitItem;


	private: System::Windows::Forms::ToolStripMenuItem^  AboutMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  ServiceMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  ServiceMenuItem;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ControlPage::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->stoppedRadio = (gcnew System::Windows::Forms::RadioButton());
			this->startedRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->defineViewForwards = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->restartButton = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->eventLog = (gcnew System::Windows::Forms::ListBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->refreshLog = (gcnew System::Windows::Forms::Button());
			this->PassPortTrayIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->ContextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->RestoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ApplicationMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->ApplicationMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ServiceMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ServiceMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->ContextMenuStrip->SuspendLayout();
			this->ApplicationMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->stoppedRadio);
			this->groupBox1->Controls->Add(this->startedRadio);
			this->groupBox1->Location = System::Drawing::Point(12, 33);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(139, 71);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Service status";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &ControlPage::groupBox1_Enter);
			// 
			// stoppedRadio
			// 
			this->stoppedRadio->AutoCheck = false;
			this->stoppedRadio->AutoSize = true;
			this->stoppedRadio->Location = System::Drawing::Point(29, 42);
			this->stoppedRadio->Name = L"stoppedRadio";
			this->stoppedRadio->Size = System::Drawing::Size(65, 17);
			this->stoppedRadio->TabIndex = 1;
			this->stoppedRadio->Text = L"Stopped";
			this->stoppedRadio->UseVisualStyleBackColor = true;
			this->stoppedRadio->CheckedChanged += gcnew System::EventHandler(this, &ControlPage::radioButton2_CheckedChanged);
			// 
			// startedRadio
			// 
			this->startedRadio->AutoCheck = false;
			this->startedRadio->AutoSize = true;
			this->startedRadio->Location = System::Drawing::Point(29, 19);
			this->startedRadio->Name = L"startedRadio";
			this->startedRadio->Size = System::Drawing::Size(59, 17);
			this->startedRadio->TabIndex = 0;
			this->startedRadio->Text = L"Started";
			this->startedRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->defineViewForwards);
			this->groupBox2->Location = System::Drawing::Point(167, 34);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(169, 70);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Forwards configuration";
			// 
			// defineViewForwards
			// 
			this->defineViewForwards->Location = System::Drawing::Point(15, 27);
			this->defineViewForwards->Name = L"defineViewForwards";
			this->defineViewForwards->Size = System::Drawing::Size(137, 31);
			this->defineViewForwards->TabIndex = 0;
			this->defineViewForwards->Text = L"Define/View forwards";
			this->defineViewForwards->UseVisualStyleBackColor = true;
			this->defineViewForwards->Click += gcnew System::EventHandler(this, &ControlPage::openConfigPage);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->restartButton);
			this->groupBox3->Controls->Add(this->startButton);
			this->groupBox3->Controls->Add(this->stopButton);
			this->groupBox3->Location = System::Drawing::Point(12, 110);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(324, 66);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Control service";
			// 
			// restartButton
			// 
			this->restartButton->Location = System::Drawing::Point(220, 27);
			this->restartButton->Name = L"restartButton";
			this->restartButton->Size = System::Drawing::Size(98, 24);
			this->restartButton->TabIndex = 2;
			this->restartButton->Text = L"Restart";
			this->restartButton->UseVisualStyleBackColor = true;
			this->restartButton->Click += gcnew System::EventHandler(this, &ControlPage::restartService);
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(119, 27);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(85, 24);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &ControlPage::startService);
			// 
			// stopButton
			// 
			this->stopButton->Location = System::Drawing::Point(15, 27);
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(88, 24);
			this->stopButton->TabIndex = 0;
			this->stopButton->Text = L"Stop";
			this->stopButton->UseVisualStyleBackColor = true;
			this->stopButton->Click += gcnew System::EventHandler(this, &ControlPage::stopService);
			// 
			// eventLog
			// 
			this->eventLog->FormattingEnabled = true;
			this->eventLog->Location = System::Drawing::Point(11, 19);
			this->eventLog->Name = L"eventLog";
			this->eventLog->Size = System::Drawing::Size(303, 134);
			this->eventLog->TabIndex = 3;
			this->eventLog->DoubleClick += gcnew System::EventHandler(this, &ControlPage::eventLog_DoubleClick);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->refreshLog);
			this->groupBox4->Controls->Add(this->eventLog);
			this->groupBox4->Location = System::Drawing::Point(12, 182);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(326, 202);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Event log";
			// 
			// refreshLog
			// 
			this->refreshLog->Location = System::Drawing::Point(228, 163);
			this->refreshLog->Name = L"refreshLog";
			this->refreshLog->Size = System::Drawing::Size(85, 29);
			this->refreshLog->TabIndex = 4;
			this->refreshLog->Text = L"Refresh";
			this->refreshLog->UseVisualStyleBackColor = true;
			this->refreshLog->Click += gcnew System::EventHandler(this, &ControlPage::refreshLog_Click);
			// 
			// PassPortTrayIcon
			// 
			this->PassPortTrayIcon->BalloonTipText = L"PassPort port forwarder console";
			this->PassPortTrayIcon->ContextMenuStrip = this->ContextMenuStrip;
			this->PassPortTrayIcon->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"PassPortTrayIcon.Icon")));
			this->PassPortTrayIcon->Text = L"PassPort Console";
			this->PassPortTrayIcon->DoubleClick += gcnew System::EventHandler(this, &ControlPage::trayIconDoubleClicked);
			// 
			// ContextMenuStrip
			// 
			this->ContextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->RestoreToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->ContextMenuStrip->Name = L"ContextMenuStrip";
			this->ContextMenuStrip->ShowImageMargin = false;
			this->ContextMenuStrip->Size = System::Drawing::Size(99, 48);
			this->ContextMenuStrip->Text = L"Application";
			this->ContextMenuStrip->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &ControlPage::ContextMenuStrip_ItemClicked);
			// 
			// RestoreToolStripMenuItem
			// 
			this->RestoreToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->RestoreToolStripMenuItem->Name = L"RestoreToolStripMenuItem";
			this->RestoreToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->RestoreToolStripMenuItem->Text = L"Restore";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// ApplicationMenuStrip
			// 
			this->ApplicationMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ApplicationMenu, 
				this->ServiceMenu, this->AboutMenu});
			this->ApplicationMenuStrip->Location = System::Drawing::Point(0, 0);
			this->ApplicationMenuStrip->Name = L"ApplicationMenuStrip";
			this->ApplicationMenuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->ApplicationMenuStrip->Size = System::Drawing::Size(351, 24);
			this->ApplicationMenuStrip->TabIndex = 5;
			this->ApplicationMenuStrip->Text = L"Application";
			this->ApplicationMenuStrip->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &ControlPage::ApplicationMenuStrip_ItemClicked);
			// 
			// ApplicationMenu
			// 
			this->ApplicationMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ExitItem});
			this->ApplicationMenu->Name = L"ApplicationMenu";
			this->ApplicationMenu->Size = System::Drawing::Size(71, 20);
			this->ApplicationMenu->Text = L"Application";
			// 
			// ExitItem
			// 
			this->ExitItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ExitItem.Image")));
			this->ExitItem->Name = L"ExitItem";
			this->ExitItem->Size = System::Drawing::Size(103, 22);
			this->ExitItem->Text = L"Exit";
			this->ExitItem->Click += gcnew System::EventHandler(this, &ControlPage::ExitItem_Click);
			// 
			// ServiceMenu
			// 
			this->ServiceMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ServiceMenuItem});
			this->ServiceMenu->Name = L"ServiceMenu";
			this->ServiceMenu->Size = System::Drawing::Size(54, 20);
			this->ServiceMenu->Text = L"Service";
			// 
			// ServiceMenuItem
			// 
			this->ServiceMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ServiceMenuItem.Image")));
			this->ServiceMenuItem->Name = L"ServiceMenuItem";
			this->ServiceMenuItem->Size = System::Drawing::Size(114, 22);
			this->ServiceMenuItem->Text = L"Install";
			this->ServiceMenuItem->Click += gcnew System::EventHandler(this, &ControlPage::ServiceMenuItem_Click);
			// 
			// AboutMenu
			// 
			this->AboutMenu->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->AboutMenu->Name = L"AboutMenu";
			this->AboutMenu->Size = System::Drawing::Size(48, 20);
			this->AboutMenu->Text = L"About";
			this->AboutMenu->Click += gcnew System::EventHandler(this, &ControlPage::AboutMenu_Click);
			// 
			// ControlPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(351, 394);
			this->Controls->Add(this->ApplicationMenuStrip);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->ApplicationMenuStrip;
			this->MaximizeBox = false;
			this->Name = L"ControlPage";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"PassPort Control";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ControlPage::ControlPage_Closed);
			this->Resize += gcnew System::EventHandler(this, &ControlPage::Resized);
			this->VisibleChanged += gcnew System::EventHandler(this, &ControlPage::visibilityChanged);
			this->Load += gcnew System::EventHandler(this, &ControlPage::ControlPage_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->ContextMenuStrip->ResumeLayout(false);
			this->ApplicationMenuStrip->ResumeLayout(false);
			this->ApplicationMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void ControlPage_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void openConfigPage(System::Object^  sender, System::EventArgs^  e);
private: System::Void stopService(System::Object^  sender, System::EventArgs^  e);
private: System::Void startService(System::Object^  sender, System::EventArgs^  e);
private: System::Void restartService(System::Object^  sender, System::EventArgs^  e);
		 System::Void ShowStatus();
		 System::Void printLog();

		 System::ServiceProcess::ServiceController ^sc;

private: System::Void refreshLog_Click(System::Object^  sender, System::EventArgs^  e);


private: System::Void trayIconDoubleClicked(System::Object^  sender, System::EventArgs^  e);

private: System::Void Resized(System::Object^  sender, System::EventArgs^  e);
private: System::Void visibilityChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void ControlPage_Closed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
private: System::Void ContextMenuStrip_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e);
private: System::Void AboutMenu_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ExitItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ApplicationMenuStrip_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void InstallService();
private: System::Void UninstallService();
private: System::Void ServiceMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void eventLog_DoubleClick(System::Object^  sender, System::EventArgs^  e);
};
}

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


#include "StdAfx.h"
#include "constants.h"
#include "ControlPage.h"
#include "ConfigPage.h"
#include "AboutDialog.h"
#include "LogDetail.h"


#define noServiceMessage "Check if the PassPort service is installed (ControlPanel->AdminstrativeTools->Services)! \n" \
	"If service was not installed select 'Service/Install' menu item or (if earlier didn't work) \n" \
	"run 'PassPort.exe -Install' command."
#define noServiceTitle "Is PassPort Service Installed?"

using namespace System::Diagnostics;

namespace PassPort {


	System::Void ControlPage::ControlPage_Load(System::Object^  sender, System::EventArgs^  e) {
		try {
			//Read status of the service from the system
			sc = gcnew ServiceController(SRV_NAME);	
			ShowStatus();
			this->ServiceMenuItem->Text = "Uninstall";
		} catch (System::InvalidOperationException ^e) {
			this->ServiceMenuItem->Text = "Install";
			this->startButton->Enabled = false;
			this->stopButton->Enabled = false;
			this->restartButton->Enabled = false;
			MessageBox::Show(this, noServiceMessage, noServiceTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		printLog();
	};

	System::Void ControlPage::ShowStatus() {	
		switch (sc->Status) {
			case ServiceControllerStatus::ContinuePending: 
				this->stoppedRadio->Checked = false;
				this->startedRadio->Checked = true;
				break;
			case ServiceControllerStatus::Paused:	
				this->stoppedRadio->Checked = true;
				this->startedRadio->Checked = false;
				break;
			case ServiceControllerStatus::PausePending:
				this->stoppedRadio->Checked = true;
				this->startedRadio->Checked = false;
				break;
			case ServiceControllerStatus::Running:
				this->stoppedRadio->Checked = false;
				this->startedRadio->Checked = true;
				break;
			case ServiceControllerStatus::StartPending:
				this->stoppedRadio->Checked = false;
				this->startedRadio->Checked = true;
				break;
			case ServiceControllerStatus::Stopped:
				this->stoppedRadio->Checked = true;
				this->startedRadio->Checked = false;
				break;
			case ServiceControllerStatus::StopPending:
				this->stoppedRadio->Checked = true;
				this->startedRadio->Checked = false;
				break;			
		}

		if (this->stoppedRadio->Checked) {
			this->startButton->Enabled = true;
			this->stopButton->Enabled = false;
			this->restartButton->Enabled = false;
		}
		if (this->startedRadio->Checked) {
			this->startButton->Enabled = false;
			this->stopButton->Enabled = true;
			this->restartButton->Enabled = true;
		}
	}

	System::Void ControlPage::openConfigPage(System::Object^  sender, System::EventArgs^  e) {
		PassPort::ConfigPage ^cp = gcnew PassPort::ConfigPage();				
		cp->ShowDialog(this);				
	}
	System::Void ControlPage::stopService(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::Cursor ^cur = this->Cursor;
		try {			
			this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->sc->Stop();
			sc->WaitForStatus(ServiceControllerStatus::Stopped);		
			ShowStatus();
			this->ServiceMenuItem->Text = "Uninstall";
		} catch (Exception ^e) {
			this->ServiceMenuItem->Text = "Install";
			this->startButton->Enabled = false;
			this->stopButton->Enabled = false;
			this->restartButton->Enabled = false;
			MessageBox::Show(this, noServiceMessage, noServiceTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}		
		this->Cursor = cur;		
		printLog();
	}
	System::Void ControlPage::startService(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::Cursor ^cur = this->Cursor;
		try {
			this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->sc->Start();
			sc->WaitForStatus(ServiceControllerStatus::Running);		
			ShowStatus();		
			this->ServiceMenuItem->Text = "Uninstall";
		} catch (Exception ^e) {
			this->ServiceMenuItem->Text = "Install";
			this->startButton->Enabled = false;
			this->stopButton->Enabled = false;
			this->restartButton->Enabled = false;
			MessageBox::Show(this, noServiceMessage, noServiceTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Cursor = cur;
		printLog();
	}
	System::Void ControlPage::restartService(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::Cursor ^cur = this->Cursor;
		try {			
			this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->sc->Stop();
			sc->WaitForStatus(ServiceControllerStatus::Stopped);
			this->sc->Start();		
			sc->WaitForStatus(ServiceControllerStatus::Running);
			ShowStatus();			
			this->ServiceMenuItem->Text = "Uninstall";
		} catch (Exception ^e) {
			this->ServiceMenuItem->Text = "Install";
			this->startButton->Enabled = false;
			this->stopButton->Enabled = false;
			this->restartButton->Enabled = false;
			MessageBox::Show(this, noServiceMessage, noServiceTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Cursor = cur;
		printLog();
	 }
	System::Void ControlPage::refreshLog_Click(System::Object^  sender, System::EventArgs^  e){
		printLog();
	}

	System::Void ControlPage::printLog() {
		EventLog ^log = gcnew EventLog("Application");
		
		int newSize = log->Entries->Count;
		static int lastSize = newSize;
		
		for (int i = lastSize; i < newSize; i++) {
			EventLogEntry ^entry = log->Entries[i];
			if (entry->Source == LOG_SOURCE) {
				this->eventLog->Items->Insert(0, entry->TimeWritten + ":  " + entry->Message);		
			}
		}
		lastSize = newSize;		
	}

	System::Void ControlPage::trayIconDoubleClicked(System::Object^  sender, System::EventArgs^  e){
		Show();
		WindowState = FormWindowState::Normal;
	}

	System::Void ControlPage::Resized(System::Object^  sender, System::EventArgs^  e) {
		if (FormWindowState::Minimized == WindowState) {
			this->Hide();
		}
		if (FormWindowState::Normal == WindowState) {
			this->Show();
		}
	}

	System::Void ControlPage::visibilityChanged(System::Object^  sender, System::EventArgs^  e) {
		this->PassPortTrayIcon->Visible = !this->Visible;
	}

	System::Void ControlPage::WaitForDialogClose() {
	}

	System::Void ControlPage::ControlPage_Closed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	}
	System::Void ControlPage::ContextMenuStrip_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		if (e->ClickedItem->Text == "Exit") {
			Application::Exit();
		}
		if (e->ClickedItem->Text == "Restore") {
			Show();
			WindowState = FormWindowState::Normal;
		}
	}

	System::Void ControlPage::AboutMenu_Click(System::Object^  sender, System::EventArgs^  e) {
		AboutDialog ^ad = gcnew AboutDialog();
		ad->ShowDialog(this);
	}

	System::Void ControlPage::ExitItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	System::Void ControlPage::ServiceMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->ServiceMenuItem->Text == "Install") {
			InstallService();			
		} else {
			UninstallService();			
		}
	}

	System::Void ControlPage::eventLog_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		LogDetail ^ ld = gcnew LogDetail((String ^)this->eventLog->Items[this->eventLog->SelectedIndex]);
		ld->ShowDialog(this);
	}

	System::Void ControlPage::InstallService() {
		System::Windows::Forms::Cursor ^cur = this->Cursor;
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		AppDomain^ dom = AppDomain::CreateDomain("execDom");
		array<String^> ^args = gcnew array<String^>(1);
		args[0] = "-Install";
		dom->ExecuteAssembly(System::Environment::GetCommandLineArgs()[0], gcnew System::Security::Policy::Evidence(), args);
		try {
			sc = gcnew ServiceController(SRV_NAME);	
			this->ServiceMenuItem->Text = "Uninstall";
			ShowStatus();
		} catch (...) {}
		this->Cursor = cur;
	}

	System::Void ControlPage::UninstallService() {
		System::Windows::Forms::Cursor ^cur = this->Cursor;
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		AppDomain^ dom = AppDomain::CreateDomain("execDom");
		array<String^> ^args = gcnew array<String^>(1);
		args[0] = "-Uninstall";
		dom->ExecuteAssembly(System::Environment::GetCommandLineArgs()[0], gcnew System::Security::Policy::Evidence(), args);
		this->ServiceMenuItem->Text = "Install";
		this->stoppedRadio->Checked = false;
		this->startedRadio->Checked = false;
		this->startButton->Enabled = false;
		this->stopButton->Enabled = false;
		this->restartButton->Enabled = false;
		this->Cursor = cur;
	}
	
}
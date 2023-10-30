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

#include "ForwardInfo.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PassPort
{
	

	/// <summary> 
	/// Summary for ConfigPage
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ConfigPage : public System::Windows::Forms::Form
	{
	public: 
		ConfigPage(void)
		{
			InitializeComponent();
		}

		System::Windows::Forms::ListBox ^ GetForwardsList() {
			return Forwards;
		}
        
	

	private: System::Windows::Forms::ListBox ^  Forwards;
	private: System::Windows::Forms::Button ^  AddButton;
	private: System::Windows::Forms::Button ^  RemoveButton;
	private: System::Windows::Forms::Button ^  OkButton;
	private: System::Windows::Forms::GroupBox ^  ForwardsFrame;
	private: System::Windows::Forms::Button ^  CancelButton;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  TargetPort;
	private: System::Windows::Forms::TextBox^  TargetHost;
	private: System::Windows::Forms::TextBox^  SourcePort;
	private: System::Windows::Forms::TextBox^  SourceHost;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  combo_protocol;



		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ConfigPage::typeid));
			this->ForwardsFrame = (gcnew System::Windows::Forms::GroupBox());
			this->RemoveButton = (gcnew System::Windows::Forms::Button());
			this->Forwards = (gcnew System::Windows::Forms::ListBox());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TargetPort = (gcnew System::Windows::Forms::TextBox());
			this->TargetHost = (gcnew System::Windows::Forms::TextBox());
			this->SourcePort = (gcnew System::Windows::Forms::TextBox());
			this->SourceHost = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->combo_protocol = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ForwardsFrame->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// ForwardsFrame
			// 
			this->ForwardsFrame->Controls->Add(this->RemoveButton);
			this->ForwardsFrame->Controls->Add(this->Forwards);
			this->ForwardsFrame->Location = System::Drawing::Point(8, 8);
			this->ForwardsFrame->Name = L"ForwardsFrame";
			this->ForwardsFrame->Size = System::Drawing::Size(735, 224);
			this->ForwardsFrame->TabIndex = 0;
			this->ForwardsFrame->TabStop = false;
			this->ForwardsFrame->Text = L"Ports forwarded";
			// 
			// RemoveButton
			// 
			this->RemoveButton->Location = System::Drawing::Point(8, 192);
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size(56, 24);
			this->RemoveButton->TabIndex = 9;
			this->RemoveButton->Text = L"Remove";
			this->RemoveButton->Click += gcnew System::EventHandler(this, &ConfigPage::RemoveEntry);
			// 
			// Forwards
			// 
			this->Forwards->Location = System::Drawing::Point(8, 16);
			this->Forwards->Name = L"Forwards";
			this->Forwards->Size = System::Drawing::Size(721, 173);
			this->Forwards->Sorted = true;
			this->Forwards->TabIndex = 8;
			this->Forwards->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigPage::PopulateEditSection);
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->Location = System::Drawing::Point(689, 250);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(48, 24);
			this->CancelButton->TabIndex = 7;
			this->CancelButton->Text = L"Cancel";
			// 
			// OkButton
			// 
			this->OkButton->Location = System::Drawing::Point(689, 280);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(48, 24);
			this->OkButton->TabIndex = 6;
			this->OkButton->Text = L"OK";
			this->OkButton->Click += gcnew System::EventHandler(this, &ConfigPage::SaveListAndExit);
			// 
			// AddButton
			// 
			this->AddButton->Enabled = false;
			this->AddButton->Location = System::Drawing::Point(590, 30);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(78, 24);
			this->AddButton->TabIndex = 6;
			this->AddButton->Text = L"Add/Change";
			this->AddButton->Click += gcnew System::EventHandler(this, &ConfigPage::CopyPortsToList);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(245, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 16);
			this->label1->TabIndex = 13;
			this->label1->Text = L"==>>";
			// 
			// TargetPort
			// 
			this->TargetPort->Location = System::Drawing::Point(437, 30);
			this->TargetPort->Name = L"TargetPort";
			this->TargetPort->Size = System::Drawing::Size(56, 20);
			this->TargetPort->TabIndex = 4;
			this->TargetPort->Text = L"port";
			this->TargetPort->TextChanged += gcnew System::EventHandler(this, &ConfigPage::ValidateAddresses);
			this->TargetPort->Enter += gcnew System::EventHandler(this, &ConfigPage::ClearTextBox);
			// 
			// TargetHost
			// 
			this->TargetHost->Location = System::Drawing::Point(285, 30);
			this->TargetHost->Name = L"TargetHost";
			this->TargetHost->Size = System::Drawing::Size(144, 20);
			this->TargetHost->TabIndex = 3;
			this->TargetHost->Text = L"host address";
			this->TargetHost->TextChanged += gcnew System::EventHandler(this, &ConfigPage::ValidateAddresses);
			this->TargetHost->Enter += gcnew System::EventHandler(this, &ConfigPage::ClearTextBox);
			// 
			// SourcePort
			// 
			this->SourcePort->Location = System::Drawing::Point(173, 30);
			this->SourcePort->Name = L"SourcePort";
			this->SourcePort->Size = System::Drawing::Size(56, 20);
			this->SourcePort->TabIndex = 2;
			this->SourcePort->Text = L"port";
			this->SourcePort->TextChanged += gcnew System::EventHandler(this, &ConfigPage::ValidateAddresses);
			this->SourcePort->Enter += gcnew System::EventHandler(this, &ConfigPage::ClearTextBox);
			// 
			// SourceHost
			// 
			this->SourceHost->Location = System::Drawing::Point(21, 30);
			this->SourceHost->Name = L"SourceHost";
			this->SourceHost->Size = System::Drawing::Size(144, 20);
			this->SourceHost->TabIndex = 1;
			this->SourceHost->Text = L"interface address";
			this->SourceHost->TextChanged += gcnew System::EventHandler(this, &ConfigPage::ValidateAddresses);
			this->SourceHost->Enter += gcnew System::EventHandler(this, &ConfigPage::ClearTextBox);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(277, 14);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(224, 48);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Target port";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->combo_protocol);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->TargetPort);
			this->groupBox3->Controls->Add(this->TargetHost);
			this->groupBox3->Controls->Add(this->SourcePort);
			this->groupBox3->Controls->Add(this->SourceHost);
			this->groupBox3->Controls->Add(this->groupBox1);
			this->groupBox3->Controls->Add(this->groupBox2);
			this->groupBox3->Controls->Add(this->AddButton);
			this->groupBox3->Location = System::Drawing::Point(9, 236);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(674, 77);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Add new ";
			// 
			// combo_protocol
			// 
			this->combo_protocol->FormattingEnabled = true;
			this->combo_protocol->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"tcp", L"udp"});
			this->combo_protocol->Location = System::Drawing::Point(507, 30);
			this->combo_protocol->Name = L"combo_protocol";
			this->combo_protocol->Size = System::Drawing::Size(66, 21);
			this->combo_protocol->TabIndex = 5;
			this->combo_protocol->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigPage::comboBox1_SelectedIndexChanged);
			this->combo_protocol->TextChanged += gcnew System::EventHandler(this, &ConfigPage::ValidateAddresses);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(13, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(224, 48);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Source port";
			// 
			// ConfigPage
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(755, 316);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->ForwardsFrame);
			this->Controls->Add(this->OkButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ConfigPage";
			this->Text = L"PassPort Configuration";
			this->Load += gcnew System::EventHandler(this, &ConfigPage::LoadConfiguration);
			this->ForwardsFrame->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}		

	private: System::Void SaveListAndExit(System::Object ^  sender, System::EventArgs ^  e);

	private: System::Void RemoveEntry(System::Object ^  sender, System::EventArgs ^  e);

	private: 
		 
private: System::Void ClearTextBox(System::Object^  sender, System::EventArgs^  e);
private: System::Void CopyPortsToList(System::Object^  sender, System::EventArgs^  e);
private: System::Void PopulateEditSection(System::Object^  sender, System::EventArgs^  e);
 
private: System::Void ValidateAddresses(System::Object^  sender, System::EventArgs^  e);
private: System::Void LoadConfiguration(System::Object^  sender, System::EventArgs^  e);
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};


}
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


namespace PassPort {

	/// <summary>
	/// Summary for AboutDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AboutDialog : public System::Windows::Forms::Form
	{
	public:
		AboutDialog(void)
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
		~AboutDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  Version;
	protected: 
	private: System::Windows::Forms::GroupBox^  Info;
	private: System::Windows::Forms::GroupBox^  License;
	private: System::Windows::Forms::GroupBox^  Credits;
	private: System::Windows::Forms::TextBox^  LicenseTextBox;

	private: System::Windows::Forms::TextBox^  InfoText;
	private: System::Windows::Forms::TextBox^  VersionText;

	private: System::Windows::Forms::ColumnHeader^  CreditContact;
	private: System::Windows::Forms::ColumnHeader^  Credit;





	private: System::ComponentModel::IContainer^  components;






	protected: 

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
			System::Windows::Forms::ImageList^  PictureList;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutDialog::typeid));
			System::Windows::Forms::ListView^  CreditsView;
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"Kim", 1));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2) {L"pjs", 
				L"psocko@gmail.com"}, 0));
			System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2) {L"QuantumG", 
				L"qg@biodome.org"}, 1));
			System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2) {L"Xumxum", 
				L"cumxum@yahoo.com"}, 1));
			System::Windows::Forms::ImageList^  PictureListSmall;
			this->Credit = (gcnew System::Windows::Forms::ColumnHeader());
			this->CreditContact = (gcnew System::Windows::Forms::ColumnHeader());
			this->Version = (gcnew System::Windows::Forms::GroupBox());
			this->VersionText = (gcnew System::Windows::Forms::TextBox());
			this->Info = (gcnew System::Windows::Forms::GroupBox());
			this->InfoText = (gcnew System::Windows::Forms::TextBox());
			this->License = (gcnew System::Windows::Forms::GroupBox());
			this->LicenseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Credits = (gcnew System::Windows::Forms::GroupBox());
			PictureList = (gcnew System::Windows::Forms::ImageList(this->components));
			CreditsView = (gcnew System::Windows::Forms::ListView());
			PictureListSmall = (gcnew System::Windows::Forms::ImageList(this->components));
			this->Version->SuspendLayout();
			this->Info->SuspendLayout();
			this->License->SuspendLayout();
			this->Credits->SuspendLayout();
			this->SuspendLayout();
			// 
			// PictureList
			// 
			PictureList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"PictureList.ImageStream")));
			PictureList->TransparentColor = System::Drawing::Color::Transparent;
			PictureList->Images->SetKeyName(0, L"DARTH-PED(T)ER.JPG");
			PictureList->Images->SetKeyName(1, L"PassPort.ico");
			// 
			// CreditsView
			// 
			CreditsView->AllowColumnReorder = true;
			CreditsView->AutoArrange = false;
			CreditsView->BackColor = System::Drawing::SystemColors::Control;
			CreditsView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->Credit, this->CreditContact});
			CreditsView->FullRowSelect = true;
			listViewItem2->ToolTipText = L"psocko@gmail.com";
			listViewItem4->ToolTipText = L"cumxum@yahoo.com";
			CreditsView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(4) {listViewItem1, listViewItem2, 
				listViewItem3, listViewItem4});
			CreditsView->LargeImageList = PictureList;
			CreditsView->Location = System::Drawing::Point(13, 20);
			CreditsView->MultiSelect = false;
			CreditsView->Name = L"CreditsView";
			CreditsView->ShowGroups = false;
			CreditsView->ShowItemToolTips = true;
			CreditsView->Size = System::Drawing::Size(403, 83);
			CreditsView->SmallImageList = PictureList;
			CreditsView->TabIndex = 0;
			CreditsView->TabStop = false;
			CreditsView->UseCompatibleStateImageBehavior = false;
			// 
			// Credit
			// 
			this->Credit->Text = L"Credit";
			this->Credit->Width = 156;
			// 
			// CreditContact
			// 
			this->CreditContact->Text = L"Contact";
			this->CreditContact->Width = 241;
			// 
			// PictureListSmall
			// 
			PictureListSmall->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"PictureListSmall.ImageStream")));
			PictureListSmall->TransparentColor = System::Drawing::Color::Transparent;
			PictureListSmall->Images->SetKeyName(0, L"DARTH-PED(T)ER.JPG");
			// 
			// Version
			// 
			this->Version->Controls->Add(this->VersionText);
			this->Version->Location = System::Drawing::Point(12, 72);
			this->Version->Name = L"Version";
			this->Version->Size = System::Drawing::Size(422, 50);
			this->Version->TabIndex = 0;
			this->Version->TabStop = false;
			this->Version->Text = L"Version";
			// 
			// VersionText
			// 
			this->VersionText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->VersionText->Location = System::Drawing::Point(6, 19);
			this->VersionText->Multiline = true;
			this->VersionText->Name = L"VersionText";
			this->VersionText->ReadOnly = true;
			this->VersionText->Size = System::Drawing::Size(410, 25);
			this->VersionText->TabIndex = 2;
			this->VersionText->TabStop = false;
			this->VersionText->Text = L"1.0.1 (2008-Nov-09)";
			this->VersionText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->VersionText->WordWrap = false;
			// 
			// Info
			// 
			this->Info->Controls->Add(this->InfoText);
			this->Info->Location = System::Drawing::Point(13, 13);
			this->Info->Name = L"Info";
			this->Info->Size = System::Drawing::Size(421, 53);
			this->Info->TabIndex = 1;
			this->Info->TabStop = false;
			this->Info->Text = L"Info";
			// 
			// InfoText
			// 
			this->InfoText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->InfoText->Location = System::Drawing::Point(9, 19);
			this->InfoText->Multiline = true;
			this->InfoText->Name = L"InfoText";
			this->InfoText->ReadOnly = true;
			this->InfoText->Size = System::Drawing::Size(406, 28);
			this->InfoText->TabIndex = 1;
			this->InfoText->TabStop = false;
			this->InfoText->Text = L"The PassPort utility allows forwarding of any local port (on all local interfaces" 
				L") \r\nto any port on a remote server. Several ports can be forwarded at the same t" 
				L"ime.";
			this->InfoText->WordWrap = false;
			// 
			// License
			// 
			this->License->Controls->Add(this->LicenseTextBox);
			this->License->Location = System::Drawing::Point(13, 129);
			this->License->Name = L"License";
			this->License->Size = System::Drawing::Size(421, 144);
			this->License->TabIndex = 2;
			this->License->TabStop = false;
			this->License->Text = L"License";
			// 
			// LicenseTextBox
			// 
			this->LicenseTextBox->Location = System::Drawing::Point(9, 19);
			this->LicenseTextBox->Multiline = true;
			this->LicenseTextBox->Name = L"LicenseTextBox";
			this->LicenseTextBox->ReadOnly = true;
			this->LicenseTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->LicenseTextBox->Size = System::Drawing::Size(406, 119);
			this->LicenseTextBox->TabIndex = 0;
			this->LicenseTextBox->TabStop = false;
			this->LicenseTextBox->Text = resources->GetString(L"LicenseTextBox.Text");
			this->LicenseTextBox->WordWrap = false;
			// 
			// Credits
			// 
			this->Credits->Controls->Add(CreditsView);
			this->Credits->Location = System::Drawing::Point(12, 279);
			this->Credits->Name = L"Credits";
			this->Credits->Size = System::Drawing::Size(422, 114);
			this->Credits->TabIndex = 3;
			this->Credits->TabStop = false;
			this->Credits->Text = L"Credits";
			// 
			// AboutDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 399);
			this->Controls->Add(this->Credits);
			this->Controls->Add(this->License);
			this->Controls->Add(this->Info);
			this->Controls->Add(this->Version);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutDialog";
			this->Text = L"About PassPort";
			this->Version->ResumeLayout(false);
			this->Version->PerformLayout();
			this->Info->ResumeLayout(false);
			this->Info->PerformLayout();
			this->License->ResumeLayout(false);
			this->License->PerformLayout();
			this->Credits->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

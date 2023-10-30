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
	/// Summary for LogDetail
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class LogDetail : public System::Windows::Forms::Form
	{
	public:
		LogDetail(String ^ logMessage)
		{
			InitializeComponent();
			int endOfDate = logMessage->IndexOf(":  ");
			this->Text = logMessage->Substring(0, endOfDate);
			this->logMessage->Text = logMessage->Substring(endOfDate + 3);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogDetail()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  logMessage;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LogDetail::typeid));
			this->logMessage = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// logMessage
			// 
			this->logMessage->BackColor = System::Drawing::SystemColors::Window;
			this->logMessage->Location = System::Drawing::Point(9, 9);
			this->logMessage->Multiline = true;
			this->logMessage->Name = L"logMessage";
			this->logMessage->ReadOnly = true;
			this->logMessage->Size = System::Drawing::Size(414, 113);
			this->logMessage->TabIndex = 0;
			// 
			// LogDetail
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 129);
			this->Controls->Add(this->logMessage);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LogDetail";
			this->Text = L"Log detail";
			this->Load += gcnew System::EventHandler(this, &LogDetail::LogDetail_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LogDetail_Load(System::Object^  sender, System::EventArgs^  e) {
				 //Set coords
				this->DesktopLocation = System::Windows::Forms::Cursor::Position;
			 }
	};
}

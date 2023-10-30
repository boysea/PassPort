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
#include "ConfigPage.h"
#include "ForwardInfo.h"

using namespace System::Xml;

namespace PassPort {


System::Void ConfigPage::SaveListAndExit(System::Object ^  sender, System::EventArgs ^  e)
{
	XmlDocument ^xd = gcnew XmlDocument();
	XmlElement ^xe = xd->CreateElement("PassPort");
	for (int i = 0; i < Forwards->Items->Count; i++) {
		ForwardInfo ^ fi = gcnew ForwardInfo(Forwards->Items[i]->ToString());
		XmlElement ^fwEl = xd->CreateElement("Forward");
		XmlElement ^src = xd->CreateElement("Source");
		XmlElement ^trg = xd->CreateElement("Target");
		XmlElement ^proto = xd->CreateElement("Protocol");
		if (!String::IsNullOrEmpty(fi->GetSourceInterface()))
			src->SetAttribute("address", fi->GetSourceInterface());
		src->SetAttribute("port", fi->GetSourcePort());

		trg->SetAttribute("address", fi->GetTargetHost());
		trg->SetAttribute("port", fi->GetTargetPort());

		proto->SetAttribute("type", fi->GetProto());

		fwEl->AppendChild(src);
		fwEl->AppendChild(trg);
		fwEl->AppendChild(proto);

		xe->AppendChild(fwEl);
	}
	xd->AppendChild(xe);
	xd->Normalize();
	XmlWriter ^xw = XmlWriter::Create(String::Concat(AppDomain::CurrentDomain->SetupInformation->ApplicationBase, 
			gcnew String(CONFIG_FILE)));
	xd->Save(xw);
	xw->Close();

	
	this->Close();
}

System::Void ConfigPage::LoadConfiguration(System::Object^  sender, System::EventArgs^  e)
{	
	XmlDocument ^xd = gcnew XmlDocument();
	try {
		xd->Load(String::Concat(AppDomain::CurrentDomain->SetupInformation->ApplicationBase, 
			gcnew String(CONFIG_FILE)));
	} catch (System::IO::FileNotFoundException ^e) {
		//There is no configuration file. Don't need to load anything. 
		return;
	}
	XmlElement ^pp = xd->DocumentElement;
	XmlNodeList ^fwds = pp->GetElementsByTagName("Forward");
	for (int i = 0; i < fwds->Count; i++) {
		XmlElement ^fw = static_cast<XmlElement^>(fwds->Item(i));
		XmlElement ^src = static_cast<XmlElement^>(fw->GetElementsByTagName("Source")->Item(0));
		XmlElement ^trg = static_cast<XmlElement^>(fw->GetElementsByTagName("Target")->Item(0));
		XmlElement ^proto = static_cast<XmlElement^>(fw->GetElementsByTagName("Protocol")->Item(0));

		ForwardInfo ^fi = gcnew ForwardInfo(
			src->GetAttribute("address"), src->GetAttribute("port"), 
			trg->GetAttribute("address"), trg->GetAttribute("port"),proto->GetAttribute("type"));
		Forwards->Items->Add(fi->ToDisplayLine());
	}	
}

System::Void ConfigPage::RemoveEntry(System::Object ^  sender, System::EventArgs ^  e)
{
	int idx = GetForwardsList()->SelectedIndex;
	if (idx >= 0) {
		GetForwardsList()->Items->RemoveAt(idx);
	}
}

System::Void ConfigPage::ClearTextBox(System::Object^  sender, System::EventArgs^  e) 
{	System::Windows::Forms::TextBox^ tb = static_cast<System::Windows::Forms::TextBox^>(sender);
	if (tb->Text->Equals("port") || tb->Text->Equals("interface address") ||
		tb->Text->Equals("host address")) 
	{
		tb->Clear();
	}
}
System::Void ConfigPage::CopyPortsToList(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::ListBox ^ fwds = GetForwardsList();
	ForwardInfo ^fw = gcnew ForwardInfo(SourceHost->Text, SourcePort->Text, 
		TargetHost->Text, TargetPort->Text, combo_protocol->Text);
	String ^src = fw->SourcePartDisplayLine();
	int found = -1;
	if ((found = fwds->FindString(src)) >= 0) {
		ForwardInfo^ fi = gcnew ForwardInfo(static_cast<String^>(fwds->Items[found]));
		if (fi->GetProto() == fw->GetProto()) {
			fwds->Items->RemoveAt(found);
		}
	}
	fwds->Items->Add(fw->ToDisplayLine());	
	SourceHost->Text = "";
	SourcePort->Text = "";
	TargetHost->Text = "";
	TargetPort->Text = "";
	combo_protocol->Text="";
}
System::Void ConfigPage::PopulateEditSection(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::ListBox ^list = static_cast<System::Windows::Forms::ListBox ^>(sender);
	int idx  = list->SelectedIndex;
	if (idx >= 0) { 
		ForwardInfo ^fi = gcnew ForwardInfo(static_cast<String^>(list->Items[idx]));
		SourceHost->Text = fi->GetSourceInterface();
		SourcePort->Text = fi->GetSourcePort();
		TargetHost->Text = fi->GetTargetHost();
		TargetPort->Text = fi->GetTargetPort();
		combo_protocol->Text = fi->GetProto();
	} else {
		SourceHost->Text = "";
		SourcePort->Text = "";
		TargetHost->Text = "";
		TargetPort->Text = "";
		combo_protocol->Text="";
	}
}
System::Void ConfigPage::ValidateAddresses(System::Object^  sender, System::EventArgs^  e) 
{
	if (ForwardInfo::ValidSourceAddress(SourceHost->Text) &&
		ForwardInfo::ValidPort(SourcePort->Text) &&
		ForwardInfo::ValidTargetAddress(TargetHost->Text) &&
		ForwardInfo::ValidPort(TargetPort->Text) &&
		ForwardInfo::ValidProto(combo_protocol->Text) )
	{
		AddButton->Enabled = true;
	} else {
		AddButton->Enabled = false;
	}
}
}
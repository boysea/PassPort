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


#include "stdafx.h"
#include "ForwardInfo.h"

namespace PassPort {
	ForwardInfo::ForwardInfo(String ^srcIface, String ^srcPort, String ^trgHost, String ^trgPort, String ^proto) {
		this->sourceInterface = srcIface;
		this->sourcePort = srcPort;
		this->targetHost = trgHost;
		this->targetPort = trgPort;
		this->proto = proto;
	}
	ForwardInfo::ForwardInfo(String ^displayedLine) {
		array<System::String ^> ^delims = gcnew array<System::String ^>(1);
		delims[0] = gcnew String(" ==> ");
		array<String ^> ^split = displayedLine->Split(delims, StringSplitOptions::None);
		delims[0] = gcnew String(":");
		//Source:
		array<String ^> ^src = split[0]->Split(delims, StringSplitOptions::None);
		if (src->Length == 2) {
			sourceInterface = src[0];
			sourcePort = src[1];
		} else {
			sourcePort = src[0];
		}
		//Target:

		array<String ^> ^trg = split[1]->Split(delims, StringSplitOptions::None);
		targetHost = trg[0];
		
		delims[0] = gcnew String(" ");
		array<String ^> ^trg2 = trg[1]->Split(delims, StringSplitOptions::None);
		targetPort = trg2[0];
		proto = trg2[1];
	}
	String ^ForwardInfo::ToDisplayLine() {
		return String::Concat(sourceInterface, 
			gcnew String(String::IsNullOrEmpty(sourceInterface) ? "" : ":"), 
			sourcePort, 
			gcnew String(" ==> "), 
			targetHost, 
			gcnew String(":"), 
			targetPort,
			gcnew String(" "),
			proto);
	}
	String ^ForwardInfo::SourcePartDisplayLine() {
		return String::Concat(sourceInterface, 
			String::IsNullOrEmpty(sourceInterface) ? "" : ":", 
			sourcePort);
	}
	
	bool ForwardInfo::ValidSourceAddress(String ^addr) 
	{
		if (String::IsNullOrEmpty(addr)) return true;
		if (!Char::IsLetterOrDigit(addr->default[0])) return false;
		if (!Char::IsLetterOrDigit(addr->default[addr->Length - 1])) return false;

		for(int i = 1; i < addr->Length - 1; i++) {
			if (!Char::IsLetterOrDigit(addr->default[i]) &&
				!addr->default[i].Equals('.') &&
				!addr->default[i].Equals('-') &&
				!addr->default[i].Equals('_')) return false;
			if (addr->default[i].Equals('.') && addr->default[i - 1].Equals('.')) return false;
		}
		return true;
	}
	bool ForwardInfo::ValidTargetAddress(String ^addr) 
	{
		if (String::IsNullOrEmpty(addr)) return false;
		if (!Char::IsLetterOrDigit(addr->default[0])) return false;
		if (!Char::IsLetterOrDigit(addr->default[addr->Length - 1])) return false;

		for(int i = 1; i < addr->Length - 1; i++) {
			if (!Char::IsLetterOrDigit(addr->default[i]) &&
				!addr->default[i].Equals('.') &&
				!addr->default[i].Equals('-') &&
				!addr->default[i].Equals('_')) return false;
			if (addr->default[i].Equals('.') && addr->default[i - 1].Equals('.')) return false;
		}
		return true;
	}
	bool ForwardInfo::ValidPort(String ^port) 
	{
		if (String::IsNullOrEmpty(port)) return false;
		for (int i = 0; i < port->Length; i++) {
			if (!Char::IsDigit(port->default[i])) return false;
		}
		return true;
	}

	bool ForwardInfo::ValidProto(String ^port) 
	{
		if (port == gcnew String("tcp") || port == gcnew String("udp"))
			return true;
		else
			return false;
	}	

}
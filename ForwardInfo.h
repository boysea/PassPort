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
namespace PassPort {



public ref class ForwardInfo {
public:
	ForwardInfo(String ^srcIface, String ^srcPort, String ^trgHost, String ^trgPort, String ^proto);
	ForwardInfo(String ^displayedLine);
	String ^GetSourceInterface() {
		return sourceInterface;
	}
	String ^GetTargetHost() {
		return targetHost;
	}
	String ^GetSourcePort() {
		return sourcePort;
	}
	String ^GetTargetPort() {
		return targetPort;
	}
	String ^GetProto() {
		return proto;
	}
	String ^ToDisplayLine();
	String ^SourcePartDisplayLine();
	static bool ValidSourceAddress(String ^addr);
	static bool ValidTargetAddress(String ^addr);
	static bool ValidPort(String ^port);
	static bool ValidProto(String ^port);
private:
	String ^sourceInterface;
	String ^targetHost;
	String ^sourcePort;
	String ^targetPort;
	String ^proto;
};
}
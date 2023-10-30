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

#include <winsock2.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

namespace PassPort {

public ref class PortForwarder
{
public:
	PortForwarder(String ^srcAddr, String ^srcPort, String ^trgAddr, String ^trgPort,String ^proto);
	~PortForwarder(void);
	void Run();
	static void Init();
	static void ShutDown();
	static List<int> ^oldThreads = gcnew List<int>;
	//typedef ^SortedDictionary<int,SOCKET> malacka;

	static SortedDictionary<u_long,SortedDictionary<u_short ,SOCKET>^> ^udp_hosts = gcnew SortedDictionary<u_long, SortedDictionary<u_short ,SOCKET>^ >;
	static Mutex^ udp_hosts_mut = gcnew Mutex;
	static HANDLE h_Shutdown_Event ;
private: 
	static List<Thread^> ^forwarders = gcnew List<Thread^>;	
	
	//used to signal PortForwarder object to shutdown, ThreadAbortException not working on blocking socket operations
	 
	
	
private:
	String ^ srcAddr;
	String ^ srcPort;
	String ^ trgAddr;
	String ^ trgPort;
	String ^ proto;
};


}

//static SortedDictionary<String^,SOCKET> ^udp_connections = gcnew SortedDictionary<String^,SOCKET>;


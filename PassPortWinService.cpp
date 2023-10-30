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


// This is the main project file for VC++ Windows Service project

#include "stdafx.h"
#include <string.h>
#include "PassPortWinService.h"
#include "ConfigPage.h"
#include "stdio.h"
#include "PortForwarder.h"
#include "ControlPage.h"
//#include "stupid_mutex.h"

using namespace PassPort;
using namespace System::Text;

//To install the service, type: "PassPort.exe -Install"
[STAThreadAttribute]
int main(array<System::String ^> ^argv)
{

	if (argv->Length >= 1)
	{
		
		//Install this Windows Service using InstallUtil.exe
		if (argv[0] == "-Install" || argv[0] == "/Install")
		{		
			array<String^> ^myargs = System::Environment::GetCommandLineArgs();
			array<String^> ^args = gcnew array<String^>(myargs->Length - 1);
			args[0] = (myargs[0]);
			Array::Copy(myargs, 2, args, 1, args->Length - 1);
			AppDomain^ dom = AppDomain::CreateDomain("execDom");
			Type^ type = System::Object::typeid;
			String^ path = type->Assembly->Location;
			StringBuilder^ sb = gcnew StringBuilder(path->Substring(0, path->LastIndexOf("\\")));
			sb->Append("\\InstallUtil.exe");
			dom->ExecuteAssembly(sb->ToString(), gcnew System::Security::Policy::Evidence(), args);
		}

		//Uninstall this Windows Service using InstallUtil.exe
		if (argv[0] == "-Uninstall" || argv[0] == "/Uninstall")
		{			
			array<String^> ^myargs = System::Environment::GetCommandLineArgs();
			array<String^> ^args = gcnew array<String^>(myargs->Length);			
			args[0] = "/u";
			args[1] = (myargs[0]);
			AppDomain^ dom = AppDomain::CreateDomain("execDom");
			Type^ type = System::Object::typeid;
			String^ path = type->Assembly->Location;
			StringBuilder^ sb = gcnew StringBuilder(path->Substring(0, path->LastIndexOf("\\")));
			sb->Append("\\InstallUtil.exe");
			dom->ExecuteAssembly(sb->ToString(), gcnew System::Security::Policy::Evidence(), args);
		}

		//See if we are not asked to configure the service.
		if (argv[0] == "-Configure" || argv[0] == "/Configure")
		{	
			PassPort::ConfigPage ^cp = gcnew PassPort::ConfigPage();
			cp->ShowDialog();
		}

		//Run the program in Service Control mode
		if (argv[0] == "-Control" || argv[0] == "/Control")
		{	// Enabling Windows XP visual effects before any controls are created
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false); 
			Application::Run(gcnew PassPort::ControlPage());
		}
	}
	else 
	{
		ServiceBase::Run(gcnew PassPortWinService());    
	}
	return 0;
}



namespace PassPort {
	void PassPortWinService::OnStart(array<String^> ^args) 
	{
		PortForwarder::Init();
	
	}

	void PassPortWinService::OnStop()
	{
		PortForwarder::ShutDown();
	}


}
  
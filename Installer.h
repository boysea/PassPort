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

#using <System.dll>
#using <System.ServiceProcess.dll>
#using <System.Configuration.Install.dll>

using namespace System;
using namespace System::Collections;
using namespace System::Configuration::Install;
using namespace System::ServiceProcess;
using namespace System::ComponentModel;


namespace PassPort
{
	[RunInstallerAttribute(true)]
	public ref class PassPortInstaller : public Installer {
	private:
		ServiceInstaller^ serviceInstaller;		
		ServiceProcessInstaller^ processInstaller;

	public:
		PassPortInstaller();
	};
}
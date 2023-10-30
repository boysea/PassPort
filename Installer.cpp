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
#include "constants.h"
#include "Installer.h"

using namespace System::Configuration::Install;

namespace PassPort
{

	PassPortInstaller::PassPortInstaller() {
		// Instantiate installers for process and services.	
		processInstaller = gcnew ServiceProcessInstaller();
		serviceInstaller = gcnew ServiceInstaller();
      
		// The services run under the system account.
		processInstaller->Account = ServiceAccount::LocalSystem;
      
		// The services are started manually.
		serviceInstaller->StartType = ServiceStartMode::Manual;
      
		// ServiceName must equal those on ServiceBase derived classes.            
		serviceInstaller->ServiceName = SRV_NAME;
		
		// Add installers to collection. Order is not important.
		Installers->Add( serviceInstaller );
		Installers->Add( processInstaller );
	}

}
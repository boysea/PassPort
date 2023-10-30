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
using namespace System::Collections;
using namespace System::ServiceProcess;
using namespace System::ComponentModel;

#include "constants.h"
#include "ControlPage.h"


namespace PassPort
{

	/// <summary> 
	/// Summary for PassPortWinService
	/// </summary>
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	public ref class PassPortWinService : public System::ServiceProcess::ServiceBase 
	{
	public:
		PassPortWinService()
		{
			InitializeComponent();  			
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		
		
	protected:
		/// <summary>
		/// Set things in motion so your service can do its work.
		/// </summary>
		virtual void OnStart(array<String^> ^args) override;
		
		/// <summary>
		/// Stop this service.
		/// </summary>
		virtual void OnStop() override;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>	
		void InitializeComponent(void)
		{
			// 
			// PassPortWinService
			// 
			this->CanPauseAndContinue = true;
			this->ServiceName = SRV_NAME;
		}		
		
	};

	
}
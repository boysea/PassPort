#include "StdAfx.h"
#include "DebugLog.h"
#include "constants.h"
using namespace System::Diagnostics;
using namespace System::Text;
using namespace System;
using namespace System::Xml;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace System::IO;


DebugLog::DebugLog(void)
{
}

void DebugLog::debug_LogFile(String^ p_format, ... array<Object^>^ p_args)
{
	mut->WaitOne();

	StreamWriter^ sw = gcnew StreamWriter( String::Concat(AppDomain::CurrentDomain->SetupInformation->ApplicationBase, 
		gcnew String(LOG_FILE)),true,Encoding::ASCII );
		

	SYSTEMTIME time;

	GetLocalTime( &time );
	int hour = time.wHour;
	int min = time.wMinute;
	int sec = time.wSecond;
	int msec = time.wMilliseconds;


		sw->Write(gcnew String(String::Format("{0:D}:{1:D}:{2:D} . {3:D} :",hour,min,sec,msec)));

		sw->Write(String::Concat(p_format->Format(p_format,p_args),gcnew String("\n")));
		sw->Flush(); //just to be sure
		sw->Close();

	mut->ReleaseMutex();
}

void DebugLog::debug_EventLog(int p_debug_level,String^ p_format, ... array<Object^>^ p_args)
{

	//same mutex, but need to change this
	mut->WaitOne();

	EventLog ^log = gcnew EventLog("Application");
	switch (p_debug_level) {
		case D_ERROR:
			log->WriteEntry(LOG_SOURCE,String::Concat(p_format->Format(p_format,p_args), EventLogEntryType::Error));
			break;
		case D_WARNING:
			log->WriteEntry(LOG_SOURCE,String::Concat(p_format->Format(p_format,p_args), EventLogEntryType::Warning));
			break;
		default:
			log->WriteEntry(LOG_SOURCE,String::Concat(p_format->Format(p_format,p_args), EventLogEntryType::Information));
			break;
	}//end switch

	mut->ReleaseMutex();

}

//wraper so we don't have to declare a DebugLog object in every function
//and because I can't declare a global Mutex either..

void debug(int p_debug_level,String^ p_format, ... array<Object^>^ p_args)
{
#ifdef _DEBUG
	DebugLog ^log = gcnew DebugLog();//can be optimised to put in if, 
	//but gcnew or couple of if is more less expensive?

	if (p_debug_level<=DEBUG_LOGFILE_LEVEL)
		log->debug_LogFile(p_format,p_args);

	if (p_debug_level<=DEBUG_EVENTLOG_LEVEL)
		log->debug_EventLog(p_debug_level,p_format,p_args);


	
	//EventLog ^log = gcnew EventLog("Application");
#endif
}
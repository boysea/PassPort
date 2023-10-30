#pragma once


#define DEBUG_LOGFILE_LEVEL 4
#define DEBUG_EVENTLOG_LEVEL 2

#define D_ERROR		1
#define D_WARNING	2
#define D_INFO		3
#define D_VERBOSE	4


using namespace System;
using namespace System::Threading;

ref class DebugLog
{
public:
	DebugLog(void);

static Mutex^ mut = gcnew Mutex;

void debug_LogFile(String^ p_format, ... array<Object^>^ p_args);
void debug_EventLog(int p_debug_level,String^ p_format, ... array<Object^>^ p_args);
};

void debug(int p_debug_level,String^ p_format, ... array<Object^>^ p_args);
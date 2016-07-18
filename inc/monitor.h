/*
Cuckoo Sandbox - Automated Malware Analysis.
Copyright (C) 2010-2015 Cuckoo Foundation.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MONITOR_MONITOR_H
#define MONITOR_MONITOR_H

#include <stdint.h>
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////
// STRUCTS
/////////////////////////////////////////////////////////////////////////////

// Monitored process linked list 		
typedef struct _MONITORED_PROCESS_ENTRY {
		ULONG pid;
		PVOID flink;
} MONITORED_PROCESS_ENTRY,*PMONITORED_PROCESS_ENTRY;


void monitor_init(HMODULE module_handle);
void monitor_hook(const char *library, void *module_handle);
void monitor_unhook(const char *library, void *module_handle);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Removes all of the monitored list entries (stops monitoring).
//	Parameters :
//		None
//	Return value :
//		int : 1 if no error was encountered, otherwise, returns -1.	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cleanMonitoredProcessList();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Adds "pid" process in the monitored list and its associated socket id(starts monitoring this process).
//	Parameters :
//		_in_ ULONG new_pid : Process Identifier.
//	Return value :
//		int : 0 if success, -1 if not.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int startMonitoringProcess(ULONG new_pid);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Returns TRUE if pid is in the monitored list (if it is actually monitored).
//	Parameters :
//		_in_ ULONG pid : Process Identifier.
//	Return value :
//		int : 0 if found, -1 if not.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int isProcessMonitoredByPid(ULONG pid);

PMONITORED_PROCESS_ENTRY monitored_process_list;
extern uint32_t g_monitor_mode;

#endif

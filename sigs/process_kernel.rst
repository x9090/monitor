Signature::

    * Calling convention: WINAPI
    * Category: process
    * Library: ntoskrnl
    * Return value: NTSTATUS


NtCreateProcess
===============

Parameters::

    **# PHANDLE ProcessHandle process_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes
    **# HANDLE ParentProcess parent_process_handle
    **# BOOLEAN InheritObjectTable inherit_handles
    *  HANDLE SectionHandle
    *  HANDLE DebugPort
    *  HANDLE ExceptionPort

Flags::

    desired_access


NtCreateProcessEx
=================

Parameters::

    **# PHANDLE ProcessHandle process_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes
    **# HANDLE ParentProcess parent_process_handle
    **# ULONG Flags flags
    *  HANDLE SectionHandle
    *  HANDLE DebugPort
    *  HANDLE ExceptionPort
    *  BOOLEAN InJob

Flags::

    desired_access


NtCreateUserProcess
===================

Signature::

    * Prune: resolve

Parameters::

    **# PHANDLE ProcessHandle process_handle
    **# PHANDLE ThreadHandle thread_handle
    **# ACCESS_MASK ProcessDesiredAccess desired_access_process
    **# ACCESS_MASK ThreadDesiredAccess desired_access_thread
    *  POBJECT_ATTRIBUTES ProcessObjectAttributes
    *  POBJECT_ATTRIBUTES ThreadObjectAttributes
    **# ULONG ProcessFlags flags_process
    **# ULONG ThreadFlags flags_thread
    *  PRTL_USER_PROCESS_PARAMETERS ProcessParameters
    *  PPS_CREATE_INFO CreateInfo
    *  PPS_ATTRIBUTE_LIST AttributeList

Flags::

    desired_access_process
    desired_access_thread

Logging::

    s filepath filepath
    s command_line command_line

RtlCreateUserProcess
====================

Parameters::

    *  PUNICODE_STRING ImagePath
    **# ULONG ObjectAttributes flags
    *  PRTL_USER_PROCESS_PARAMETERS ProcessParameters
    *  PSECURITY_DESCRIPTOR ProcessSecurityDescriptor
    *  PSECURITY_DESCRIPTOR ThreadSecurityDescriptor
    **# HANDLE ParentProcess parent_process_handle
    **# BOOLEAN InheritHandles inherit_handles
    *  HANDLE DebugPort
    *  HANDLE ExceptionPort
    *  PRTL_USER_PROCESS_INFORMATION ProcessInformation

NtOpenProcess
=============

Parameters::

    **# PHANDLE ProcessHandle process_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes
    *  PCLIENT_ID ClientId

Flags::

    desired_access

Ensure::

    ClientId

Logging::

    s targetpid targetpid

NtTerminateProcess
==================

Signature::

    * Prelog: instant

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# NTSTATUS ExitStatus status_code


NtCreateSection
===============

Parameters::

    **# PHANDLE SectionHandle section_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *   POBJECT_ATTRIBUTES ObjectAttributes
    *   PLARGE_INTEGER MaximumSize
    **# ULONG SectionPageProtection protection
    *   ULONG AllocationAttributes
    **# HANDLE FileHandle file_handle

Flags::

    desired_access
    protection

Logging::

    s root_directory root_directory
    s section_name section_name

NtMakeTemporaryObject
=====================

Parameters::

    **# HANDLE ObjectHandle handle


NtMakePermanentObject
=====================

Parameters::

    **# HANDLE ObjectHandle handle


NtOpenSection
=============

Parameters::

    **# PHANDLE SectionHandle section_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes

Flags::

    desired_access

NtUnmapViewOfSection
====================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# PVOID BaseAddress base_address


NtAllocateVirtualMemory
=======================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# PVOID *BaseAddress base_address
    *  ULONG_PTR ZeroBits
    **# PSIZE_T RegionSize region_size
    **# ULONG AllocationType allocation_type
    **# ULONG Protect protection


NtReadVirtualMemory
===================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# LPCVOID BaseAddress base_address
    **# LPVOID Buffer
    *  SIZE_T NumberOfBytesToRead
    *  PSIZE_T NumberOfBytesReaded

Ensure::

    NumberOfBytesReaded


NtWriteVirtualMemory
====================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# LPVOID BaseAddress base_address
    **# LPCVOID Buffer
    *  SIZE_T NumberOfBytesToWrite
    *  PSIZE_T NumberOfBytesWritten

Ensure::

    NumberOfBytesWritten

NtProtectVirtualMemory
======================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# PVOID *BaseAddress base_address
    **# PSIZE_T NumberOfBytesToProtect length
    **# ULONG NewAccessProtection protection
    *  PULONG OldAccessProtection

Flags::

    protection


NtFreeVirtualMemory
===================

Parameters::

    **# HANDLE ProcessHandle process_handle
    **# PVOID *BaseAddress base_address
    **# PSIZE_T RegionSize size
    **# ULONG FreeType free_type


NtMapViewOfSection
==================

Parameters::

    **# HANDLE SectionHandle section_handle
    **# HANDLE ProcessHandle process_handle
    **# PVOID *BaseAddress base_address
    *  ULONG_PTR ZeroBits
    **# SIZE_T CommitSize commit_size
    * PLARGE_INTEGER SectionOffset section_offset
    **# PSIZE_T ViewSize view_size
    * UINT InheritDisposition
    **# ULONG AllocationType allocation_type
    **# ULONG Win32Protect win32_protect

Flags::

    allocation_type
    win32_protect

Logging::

    s map_buffer map_buffer

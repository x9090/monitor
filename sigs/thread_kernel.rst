Signature::

    * Calling convention: WINAPI
    * Category: process
    * Return value: NTSTATUS
    * Library: ntoskrnl

NtCreateThread
==============

Parameters::

    **# PHANDLE ThreadHandle thread_handle
    **# ACCESS_MASK DesiredAccess access
    *  POBJECT_ATTRIBUTES ObjectAttributes
    **# HANDLE ProcessHandle process_handle
    *  PCLIENT_ID ClientId
    *  PCONTEXT ThreadContext
    *  PINITIAL_TEB InitialTeb
    **# BOOLEAN CreateSuspended suspended

Flags::

    access

Logging::

    s thread_name thread_name


NtCreateThreadEx
================

Signature::

    * Prune: resolve

Parameters::

    **# PHANDLE hThread thread_handle
    **# ACCESS_MASK DesiredAccess access
    **# PVOID ObjectAttributes thread_name
    **# HANDLE ProcessHandle process_handle
    **# LPTHREAD_START_ROUTINE lpStartAddress function_address
    **# PVOID lpParameter parameter
    **# BOOL CreateSuspended suspended
    **# LONG StackZeroBits stack_zero_bits
    *   LONG SizeOfStackCommit
    *   LONG SizeOfStackReserve
    *   PVOID lpBytesBuffer

Flags::

    access

NtOpenThread
============

Parameters::

    **# PHANDLE ThreadHandle thread_handle
    **# ACCESS_MASK DesiredAccess access
    *   POBJECT_ATTRIBUTES ObjectAttributes
    *   PCLIENT_ID ClientId

Flags::

    access

Logging::

    s target_pid target_pid

NtGetContextThread
==================

Parameters::

    **# HANDLE ThreadHandle thread_handle
    *  LPCONTEXT Context


NtSetContextThread
==================

Parameters::

    **# HANDLE ThreadHandle thread_handle
    *  const CONTEXT *Context

NtSuspendThread
===============

Parameters::

    **# HANDLE ThreadHandle thread_handle
    **# ULONG *PreviousSuspendCount previous_suspend_count

Ensure::

    PreviousSuspendCount


NtResumeThread
==============

Parameters::

    **# HANDLE ThreadHandle thread_handle
    **# ULONG *SuspendCount suspend_count

Ensure::

    SuspendCount


NtTerminateThread
=================

Parameters::

    **# HANDLE ThreadHandle thread_handle
    **# NTSTATUS ExitStatus status_code


RtlCreateUserThread
===================

Parameters::

    **# HANDLE ProcessHandle process_handle
    *  PSECURITY_DESCRIPTOR SecurityDescriptor
    **# BOOLEAN CreateSuspended suspended
    *  ULONG StackZeroBits
    *  PULONG StackReserved
    *  PULONG StackCommit
    **# PVOID StartAddress function_address
    **# PVOID StartParameter parameter
    **# PHANDLE ThreadHandle thread_handle
    *  PCLIENT_ID ClientId

Pre::

    pipe("PROCESS:%d", pid_from_process_handle(ProcessHandle));

Post::

    if(NT_SUCCESS(ret) != FALSE) {
        sleep_skip_disable();
    }


NtQueueApcThread
================

Parameters::

    **# HANDLE ThreadHandle thread_handle
    *   PIO_APC_ROUTINE ApcRoutine
    **# PVOID ApcRoutineContext function_address
    **# PIO_STATUS_BLOCK ApcStatusBlock parameter
    *   ULONG ApcReserved

Logging::

    s process_identifier process_identifier


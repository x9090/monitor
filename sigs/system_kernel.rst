Signature::

    * Calling convention: WINAPI
    * Category: system

NtDuplicateObject
=================

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS
    * Special: true

Parameters::

    ** HANDLE SourceProcessHandle source_process_handle
    ** HANDLE SourceHandle source_handle
    ** HANDLE TargetProcessHandle target_process_handle
    ** HANDLE *TargetHandle target_handle
    ** ACCESS_MASK DesiredAccess desired_access
    ** ULONG HandleAttributes handle_attributes
    ** ULONG Options options

Logging::

    i source_process_identifier pid_from_process_handle(SourceProcessHandle)
    i target_process_identifier pid_from_process_handle(TargetProcessHandle)

Post::

    uintptr_t source_pid = pid_from_process_handle(SourceProcessHandle);
    uintptr_t target_pid = pid_from_process_handle(TargetProcessHandle);
    if(NT_SUCCESS(ret) != FALSE &&
            source_pid == get_current_process_id() &&
            target_pid == get_current_process_id()) {
        if(is_ignored_object_handle(SourceHandle) != 0) {
            ignored_object_add(*TargetHandle);
        }
    }


NtClose
=======

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS
    * Special: true

Parameters::

    ** HANDLE Handle handle

Post::

    if(NT_SUCCESS(ret) != FALSE) {
        ignored_object_remove(Handle);
    }


NtLoadDriver
============

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS

Parameters::

    *  PUNICODE_STRING DriverServiceName

Pre::

    wchar_t *driver_service_name =
        extract_unicode_string_unistr(DriverServiceName);

Logging::

    s driver_service_name driver_service_name

Post::

    free_unicode_buffer(driver_service_name);


NtUnloadDriver
==============

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS

Parameters::

    *  PUNICODE_STRING DriverServiceName

Pre::

    wchar_t *driver_service_name =
        extract_unicode_string_unistr(DriverServiceName);

Logging::

    u driver_service_name driver_service_name

Post::

    free_unicode_buffer(driver_service_name);


NtQuerySystemInformation
========================

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS

Parameters::

    ** SYSTEM_INFORMATION_CLASS SystemInformationClass information_class
    *  PVOID SystemInformation
    *  ULONG SystemInformationLength
    *  PULONG ReturnLength

Flags::

    information_class


NtShutdownSystem
================

Signature::

    * Library: ntoskrnl
    * Prelog: instant
    * Return value: NTSTATUS

Parameters::

    ** SHUTDOWN_ACTION Action action

Flags::

    action

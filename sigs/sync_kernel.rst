Signature::

    * Calling convention: WINAPI
    * Category: synchronisation


NtCreateMutant
==============

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS

Parameters::

    ** PHANDLE MutantHandle mutant_handle
    ** ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes
    ** BOOLEAN InitialOwner initial_owner

Flags::

    desired_access

Logging::

    u mutant_name mutant_name


NtOpenMutant
============

Signature::

    * Library: ntoskrnl
    * Return value: NTSTATUS

Parameters::

    ** PHANDLE MutantHandle mutant_handle
    ** ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes

Flags::

    desired_access

Logging::

    u mutant_name mutant_name

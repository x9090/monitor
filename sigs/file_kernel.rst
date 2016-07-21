Signature::

    * Calling convention: WINAPI
    * Category: file
    * Library: ntoskrnl
    * Return value: NTSTATUS

NtCreateFile
============

Signature::

    * Mode: exploit

Parameters::

    **# PHANDLE FileHandle file_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *   POBJECT_ATTRIBUTES ObjectAttributes
    *   PIO_STATUS_BLOCK IoStatusBlock
    *   PLARGE_INTEGER AllocationSize
    **# ULONG FileAttributes file_attributes
    **# ULONG ShareAccess share_access
    **# ULONG CreateDisposition create_disposition
    **# ULONG CreateOptions create_options
    *  PVOID EaBuffer
    *  ULONG EaLength

Flags::

    desired_access
    file_attributes
    share_access
    create_disposition
    create_options

Logging::

    s filepath filepath

Ensure::

    FileHandle
    IoStatusBlock


NtDeleteFile
============

Parameters::

    *  POBJECT_ATTRIBUTES ObjectAttributes

Pre::

    wchar_t *filepath = get_unicode_buffer();
    path_get_full_path_objattr(ObjectAttributes, filepath);
    pipe("FILE_DEL:%Z", filepath);

    wchar_t *filepath_r = extract_unicode_string_objattr(ObjectAttributes);

Interesting::

    u filepath

Logging::

    s filepath filepath
    s filepath_r filepath_r

Post::

    free_unicode_buffer(filepath);
    free_unicode_buffer(filepath_r);


NtOpenFile
==========

Signature::

    * Mode: exploit

Parameters::

    **# PHANDLE FileHandle file_handle
    **# ACCESS_MASK DesiredAccess desired_access
    * POBJECT_ATTRIBUTES ObjectAttributes
    *  PIO_STATUS_BLOCK IoStatusBlock
    **# ULONG ShareAccess share_access
    **# ULONG OpenOptions open_options

Flags::

    desired_access
    share_access
    open_options

Logging::

    s filepath filepath

NtReadFile
==========

Parameters::

    **# HANDLE FileHandle file_handle
    *   HANDLE Event
    *   PIO_APC_ROUTINE ApcRoutine
    *   PVOID ApcContext
    *   PIO_STATUS_BLOCK IoStatusBlock
    **# PVOID Buffer
    **# ULONG Length length
    **# PLARGE_INTEGER ByteOffset offset
    *   PULONG Key

Ensure::

    IoStatusBlock

NtWriteFile
===========

Signature::

    * Mode: exploit

Parameters::

    **# HANDLE FileHandle file_handle
    *  HANDLE Event
    *  PIO_APC_ROUTINE ApcRoutine
    *  PVOID ApcContext
    *  PIO_STATUS_BLOCK IoStatusBlock
    **# PVOID Buffer
    *  ULONG Length
    **# PLARGE_INTEGER ByteOffset offset
    *  PULONG Key


NtDeviceIoControlFile
=====================

Parameters::

    **# HANDLE FileHandle file_handle
    *  HANDLE Event
    *  PIO_APC_ROUTINE ApcRoutine
    *  PVOID ApcContext
    *  PIO_STATUS_BLOCK IoStatusBlock
    **# ULONG IoControlCode control_code
    **# PVOID InputBuffer
    *  ULONG InputBufferLength
    **# PVOID OutputBuffer
    *  ULONG OutputBufferLength

Flags::

    control_code

Ensure::

    IoStatusBlock


NtQueryDirectoryFile
====================

Parameters::

    **# HANDLE FileHandle file_handle
    *  HANDLE Event
    *  PIO_APC_ROUTINE ApcRoutine
    *  PVOID ApcContext
    *  PIO_STATUS_BLOCK IoStatusBlock
    *  PVOID FileInformation
    *  ULONG Length
    **# FILE_INFORMATION_CLASS FileInformationClass information_class
    *  BOOLEAN ReturnSingleEntry
    *  PUNICODE_STRING FileName
    *  BOOLEAN RestartScan

Flags::

    information_class

Ensure::

    IoStatusBlock


NtQueryInformationFile
======================

Parameters::

    **# HANDLE FileHandle file_handle
    *  PIO_STATUS_BLOCK IoStatusBlock
    *  PVOID FileInformation
    *  ULONG Length
    **# FILE_INFORMATION_CLASS FileInformationClass information_class

Flags::

    information_class


NtSetInformationFile
====================

Parameters::

    **# HANDLE FileHandle file_handle
    *  PIO_STATUS_BLOCK IoStatusBlock
    *  PVOID FileInformation
    *  ULONG Length
    **# FILE_INFORMATION_CLASS FileInformationClass information_class

Flags::

    information_class


NtOpenDirectoryObject
=====================

Parameters::

    **# PHANDLE DirectoryHandle directory_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes

Flags::

    desired_access


NtCreateDirectoryObject
=======================

Parameters::

    **# PHANDLE DirectoryHandle directory_handle
    **# ACCESS_MASK DesiredAccess desired_access
    *  POBJECT_ATTRIBUTES ObjectAttributes

Flags::

    desired_access


NtQueryAttributesFile
=====================

Parameters::

    *  POBJECT_ATTRIBUTES ObjectAttributes
    *  void *FileInformation

NtQueryFullAttributesFile
=========================

Parameters::

    *  POBJECT_ATTRIBUTES ObjectAttributes
    *  void *FileInformation

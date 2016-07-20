CreateProcessInternalW_creation_flags
=====================================

Inherits::

    PRIORITY_CLASS

Enum::

    CREATE_BREAKAWAY_FROM_JOB
    CREATE_DEFAULT_ERROR_MODE
    CREATE_NEW_CONSOLE
    CREATE_NEW_PROCESS_GROUP
    CREATE_NO_WINDOW
    CREATE_PROTECTED_PROCESS
    CREATE_PRESERVE_CODE_AUTHZ_LEVEL
    CREATE_SEPARATE_WOW_VDM
    CREATE_SHARED_WOW_VDM
    CREATE_SUSPENDED
    CREATE_UNICODE_ENVIRONMENT
    DEBUG_ONLY_THIS_PROCESS
    DEBUG_PROCESS
    DETACHED_PROCESS
    EXTENDED_STARTUPINFO_PRESENT
    INHERIT_PARENT_AFFINITY


MemoryProtectionFlags
=====================

Enum::

    PAGE_EXECUTE
    PAGE_EXECUTE_READ
    PAGE_EXECUTE_READWRITE
    PAGE_EXECUTE_WRITECOPY
    PAGE_NOACCESS
    PAGE_READONLY
    PAGE_READWRITE
    PAGE_WRITECOPY
    PAGE_GUARD
    PAGE_NOCACHE
    PAGE_WRITECOMBINE


VirtualProtectEx_flNewProtect
=============================

Inherits::

    MemoryProtectionFlags


NtProtectVirtualMemory_NewAccessProtection
==========================================

Inherits::

    MemoryProtectionFlags


NtAllocateVirtualMemory_Protect
===============================

Inherits::

    MemoryProtectionFlags


NtMapViewOfSection_Win32Protect
===============================

Inherits::

    MemoryProtectionFlags


AllocationType
==============

Enum::

    MEM_COMMIT
    MEM_RESERVE
    MEM_RESET
    MEM_LARGE_PAGES
    MEM_PHYSICAL
    MEM_TOP_DOWN
    MEM_WRITE_WATCH

NtAllocateVirtualMemory_AllocationType
======================================

Inherits::

    AllocationType


NtMapViewOfSection_AllocationType
=================================

Inherits::

    AllocationType


SectionDesiredAccess
====================

Enum::

    SECTION_QUERY
    SECTION_MAP_WRITE
    SECTION_MAP_READ
    SECTION_MAP_EXECUTE
    SECTION_EXTEND_SIZE
    SECTION_ALL_ACCESS

NtCreateSection_DesiredAccess
=============================

Inherits::

    SectionDesiredAccess

NtCreateSection_SectionPageProtection
=====================================

Inherits::

    MemoryProtectionFlags


NtOpenSection_DesiredAccess
=============================

Inherits::

    SectionDesiredAccess

ThreadDesiredAccess
===================

Enum::

    THREAD_TERMINATE           
    THREAD_SUSPEND_RESUME      
    THREAD_ALERT               
    THREAD_GET_CONTEXT         
    THREAD_SET_CONTEXT         
    THREAD_SET_INFORMATION     
    THREAD_QUERY_INFORMATION   
    THREAD_SET_THREAD_TOKEN    
    THREAD_IMPERSONATE         
    THREAD_DIRECT_IMPERSONATION
    THREAD_ALL_ACCESS     

NtCreateThread_DesiredAccess
============================

Inherits::

    ThreadDesiredAccess    


NtCreateThreadEx_DesiredAccess
==============================

Inherits::

    ThreadDesiredAccess

NtOpenThread_DesiredAccess
==========================

Inherits::

    ThreadDesiredAccess  
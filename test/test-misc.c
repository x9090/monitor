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

#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "misc.h"
#include "pipe.h"

#define assert(expr) \
    if((expr) == 0) { \
        pipe("CRITICAL:Test didn't pass: %z", #expr); \
    } \
    else { \
        pipe("INFO:Test passed: %z", #expr); \
    }

int main()
{
    static char buf[0x1000];

    pipe_init("\\\\.\\PIPE\\cuckoo");

    assert(ultostr(42, buf, 10) == 2 && strcmp(buf, "42") == 0);
    assert(ultostr(1337, buf, 10) == 4 && strcmp(buf, "1337") == 0);
    assert(ultostr(-20, buf, 10) == 3 && strcmp(buf, "-20") == 0);
    assert(ultostr(-42, buf, 10) == 3 && strcmp(buf, "-42") == 0);
    assert(ultostr(0x1337, buf, 16) == 4 && strcmp(buf, "1337") == 0);

#if __x86_64__
    assert(ultostr(0xffffffffffffffff, buf, 16) == 16 && strcmp(buf, "ffffffffffffffff") == 0);
#else
    assert(ultostr(0xffffffff, buf, 16) == 8  && strcmp(buf, "ffffffff") == 0);
#endif

    assert(our_snprintf(buf, 2, "hoi") == 2 && memcmp(buf, "ho", 2) == 0);
    assert(our_snprintf(buf, 4, "hoi") == 3 && memcmp(buf, "hoi", 3) == 0);
    assert(our_snprintf(buf, 64, "%s %s", "a", "b") == 3 && memcmp(buf, "a b", 3) == 0);
    assert(our_snprintf(buf, 64, "%s %s ccc", "a", "bb") == 8 && memcmp(buf, "a bb ccc", 8) == 0);
    assert(our_snprintf(buf, 64, "%p", 0x4141) == 6 && memcmp(buf, "0x4141", 6) == 0);
    assert(our_snprintf(buf, 64, "%p %p", 0x4141, 0x4242) == 13 && memcmp(buf, "0x4141 0x4242", 13) == 0);
}

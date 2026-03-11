#ifndef __STD_IO_H
#define __STD_IO_H

#include "STD_core.h"
#include <asm/unistd_64.h>
#if defined(__linux__)
    #include <unistd.h>
#endif

namespace STD {
    
};

inline void __PRINT(
    const char* __str,
    ...
) noexcept {
    #if defined(__linux__)
        syscall(
            __NR_write,
            STDOUT_FILENO,
            __str,
            __STR_LEN(__str)
        );
    #endif

}

#endif
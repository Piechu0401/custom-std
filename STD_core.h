#ifndef __STD_CORE_H
#define __STD_CORE_H

#include <asm/unistd_64.h>
#if defined(__linux__)
    #include <unistd.h>
    #include <syscall.h>
#endif

// the whole project will be about me trying to implement what std did trying my best
// to do the same or better if possible.

#define __EOF '\0'
#define __HALT_MESSAGE "__HALT called after throwing 'STD::HaltError'\n\treason(): "
#define __HALT_MESSAGE_SIZE 57

#define __INDEX_OUT_OF_SCOPE "Given index is out of memory scope!\n"

namespace STD {
    [[noreturn]] inline void __HALT(
        const char* __Message,
        const unsigned long& __MessageSize
    ) {
        #if defined(__linux__)
            syscall(
                __NR_write,
                STDOUT_FILENO,
                __HALT_MESSAGE,
                __HALT_MESSAGE_SIZE
            );
        
            syscall(
                __NR_write,
                STDOUT_FILENO,
                __Message,
                __MessageSize
            );
        
            syscall(
                __NR_exit_group
            );    
            
            syscall(
                __NR_exit,
                0
            );
        #endif

        _exit(0);

    }
    
    class HaltError {
        public:
        explicit HaltError() noexcept;
        explicit HaltError(
            const char* __Error
        ) noexcept;

        inline void __CHANGE( const char* __Message ) noexcept { __errorMessage = __Message; }

        private:
            const char* __errorMessage;

    };

};

#endif
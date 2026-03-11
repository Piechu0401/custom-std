#ifndef __STD_CORE_H
#define __STD_CORE_H

#include <asm/unistd_64.h>
#include <cstring>
#if defined(__linux__)
    #include <unistd.h>
    #include <syscall.h>
#endif

// the whole project will be about me trying to implement what std did trying my best
// to do the same or better if possible.

#define __ENDL '\n'
#define __EOF '\0'
#define __HALT_MESSAGE "__HALT called after throwing 'STD::HaltError'\n\t__Message: "
#define __HALT_MESSAGE_SIZE 57

#define __INDEX_OUT_OF_SCOPE "Given index is out of memory scope!\n"
#define __INVALID_SUB_STR_BEG_LEN "Given substring cannot be create due to bad values of begin and length!\n"

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
            
            _exit(0);

        #endif

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

inline unsigned long __STR_LEN(
    const char* __str
) {
    unsigned long __res{0L};

    while( __str[__res] != __EOF ) ++__res;
    return __res;

}

inline char* __STR_CPY(
    char* __Dst,
    const char* __Src
) noexcept {
    unsigned long __l = __STR_LEN( __Src );
    __Dst = new char[__l];

    for( int __i{0}; __i < __l; ++__i )
        __Dst[__i] = __Src[__i];

    __Dst[__l] = __EOF;

    return __Dst;

}

#endif
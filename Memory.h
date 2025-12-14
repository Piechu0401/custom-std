//////////////////////////////////////////////
//                                          //
// Michel Piech                             //
//                                          //
// simple memory library, check this out    //
//                                          //
//////////////////////////////////////////////

#ifndef __MEMORY_H
#define __MEMORY_H

#ifndef Byte
    #define Byte 1
#endif

#ifndef KiloByte
    #define KiloByte Byte << 10
#endif

#ifndef MegaByte
    #define MegaByte Byte << 20
#endif

#ifndef GigaByte
    #define GigaByte Byte << 30
#endif

#ifndef TeraByte
    #define TeraByte Byte << 40
#endif

#ifndef SIZE_VAR__
    #define SIZE_VAR__ 1
    typedef unsigned long Size;
#endif

#ifndef VOID_PTR__
    #define VOID_PTR__ 2
    typedef void* vPtr;
#endif

#ifndef U_PTR__
    #define U_PTR__ 3
    typedef unsigned long uPtr;
#endif

#ifndef NULL_PTR__
    #define NULL_PTR__ nullptr
#endif

#if defined(__linux__)
    #include <unistd.h>
    #include <sys/syscall.h>
    #include <sys/mman.h>

    #define MMAP_LIMIT_BITS_SIZE ((1 << 8) * KiloByte) // maybe will shrink it later
    #define MALLOC_PROT PROT_READ | PROT_WRITE

#elif defined(__WIN32) || defined(__WIN64)
    #include <windows.h>
#endif

namespace MyStd {
    struct __MEM_LIST {
        vPtr ChunkRequest(
            const Size ChunkSize
        ) noexcept;

        friend vPtr Malloc(
            const Size __size__
        );

        private:
            __MEM_LIST* __next;
            unsigned int __free;
            Size __size;

    };

    #define __MEM_LIST_BLOCK_SIZE sizeof(__MEM_LIST)

    static __MEM_LIST* __mem_list = NULL_PTR__;

    vPtr Malloc(
        const Size __size__
    );
    
    vPtr AlignedAlloc(
        const Size __size__,
        const Size __alignment__
    );
    
    vPtr Realloc(
        vPtr __old__,
        const Size __new_size__
    );
    
    const int Free(
        vPtr __free_memory__
    );

};

#endif
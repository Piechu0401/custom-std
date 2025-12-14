#include "Memory.h"
#include <sys/mman.h>
#include <sys/syscall.h>

namespace MyStd {
    vPtr __MEM_LIST::ChunkRequest(
        const Size ChunkSize
    ) noexcept {
        __MEM_LIST* __temp = __mem_list;

        while(
            __temp != (__MEM_LIST*)NULL_PTR__
        ) {
            if(         
                __temp->__free && 
                __temp->__size >= ChunkSize
            ) return __temp;

            __temp = __temp->__next;

        }

        return NULL_PTR__;

    }
    
    vPtr Malloc(
        const Size __size__
    ) {
        if(
            __size__ == 0
        ) return NULL_PTR__;

        __MEM_LIST* Chunk = (__MEM_LIST*)__mem_list->ChunkRequest(
            __size__
        );
        
        if(
            !Chunk
        ) {
            const Size TotalSize = __MEM_LIST_BLOCK_SIZE + __size__;
            
            #if defined(__linux__)
                if(
                    __size__ < MMAP_LIMIT_BITS_SIZE
                ) {
                    vPtr Old = (vPtr)syscall(
                        SYS_brk,
                        0
                    );
                    vPtr New = (char*)Old + TotalSize;

                    if(
                        (vPtr)syscall(
                            SYS_brk,
                            New
                        ) != New
                    ) return NULL_PTR__;

                    Chunk = (__MEM_LIST*)Old;
                    Chunk->__size = __size__;
                    Chunk->__next = NULL_PTR__;
                    Chunk->__free = 0;

                }

                // I think its valid

                int flags  =\
                    (__size__ > (4LU * GigaByte)) ?\
                    MAP_PRIVATE | MAP_ANONYMOUS | MAP_ABOVE4G :\
                    MAP_PRIVATE | MAP_ANONYMOUS;

                vPtr Chunk = (vPtr)syscall(
                    SYS_mmap,
                    Chunk,
                    TotalSize,
                    MALLOC_PROT,
                    flags,
                    -1,
                    0
                );

                if(
                    Chunk == MAP_FAILED
                ) return NULL_PTR__;

            #endif

        }

        return ((char*)(Chunk) + 1);

    }

};
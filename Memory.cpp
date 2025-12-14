#include "Memory.h"

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

        Size Bullshit = 
            __size__ + sizeof(Size);

        //round bullshit 
        Size RoundedBullshit = 
            ( __size__ + MIN_MEM - 1 ) & ~( MIN_MEM - 1 );

        Size TotalBullshit = 
            MIN_MEM + RoundedBullshit + MIN_MEM;

        int __flags = MAP_ANON | MAP_PRIVATE;

        vPtr NewChunk = (vPtr)syscall( 
            SYS_mmap,
            NULL_PTR__,
            TotalBullshit,
            MALLOC_PROT,
            __flags,
            -1,
            0
        );

        if(
            NewChunk == MAP_FAILED
        ) return NULL_PTR__;

        mprotect(
            NewChunk,
            MIN_MEM,
            PROT_NONE
        );

        mprotect(
            (char*)NewChunk + MIN_MEM + RoundedBullshit,
            MIN_MEM,
            PROT_NONE
        );

        vPtr HeaderMotherfucker = (char*)NewChunk + MIN_MEM;
        *(Size*) HeaderMotherfucker = __size__;

        return (vPtr)((char*)HeaderMotherfucker + sizeof(Size));

    }

};
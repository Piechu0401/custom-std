#include "lib.h"
#include "core.h"
#include <asm/unistd_64.h>
#include <sys/mman.h>
#include <unistd.h>

__MEMORY_BLOCK_T* __stackGangsta__ =     (__MEMORY_BLOCK_T*)NULL_PTR__;
__MEMORY_BLOCK_T* __lastMotherfucker__ = (__MEMORY_BLOCK_T*)NULL_PTR__;
vPtr __brkLocation__ = NULL_PTR__;

__MEMORY_BLOCK_T* ChunkRequest(
    size __size__
) {
    __MEMORY_BLOCK_T* __temp_block = __stackGangsta__;

    // go through every motherfucker while temp is null
    // if temp is free and size is big enough then return
    // when there is no available motherfucker then go fuck yourself and get null

    while(
        !__temp_block
    ) {
        if(
            __temp_block->__free__ &&
            __temp_block->__size__ >= __size__
        ) return __temp_block;

        __temp_block = __temp_block->__nextMotherfucker__;

    }

    return NULL_PTR__;

}

void MergeChunks(
    vPtr __memory__
) {


}

void SliceChunk(
    vPtr __memory__
) {


}

vPtr Alloc(
    size __size__
) {
    if(
        __size__ == 0
    ) return NULL_PTR__;

    size __neededRoomForShit__ = 
        __Align( ( __size__ ), __BYTE_SIZE ) + __BLOCK_SIZE;

    if(
        __neededRoomForShit__ <= __HEAP_ALLOC_LIMIT
    ) {
        if(
            !__stackGangsta__
        )   {
            __brkLocation__ = 
                (vPtr)syscall(
                    __NR_brk, 
                    0
                );

            if(
                (vPtr)syscall(
                    __NR_brk,    
                    (char*)__brkLocation__ + __neededRoomForShit__
                ) == __ALLOC_FAILED
            ) return NULL_PTR__;

            vPtr __tempBrk__ = 
                (vPtr)syscall(
                    __NR_brk, 
                    0
                );

            __stackGangsta__ = __brkLocation__;
            __stackGangsta__->__memSrart__ =
                (uint32*)__stackGangsta__;
            *__stackGangsta__->__memSrart__ = 
                __BLOCK_GUARD;
            __stackGangsta__->__memEnd__ = 
                (uint32*)((uint32*)((char*)__stackGangsta__ + __neededRoomForShit__ - __BLOCK_SIZE));
            *__stackGangsta__->__memEnd__ =
                __BLOCK_GUARD;
            __stackGangsta__->__prevMotherfucker__ = 
                NULL_PTR__;
            __stackGangsta__->__nextMotherfucker__ = 
                NULL_PTR__;
            __stackGangsta__->__free__ = 
                FALSE__;
            __stackGangsta__->__size__ = 
                __neededRoomForShit__ - __BLOCK_SIZE;
            __stackGangsta__->__type__ = 
                HEAP_ALLOC;

            __MEMORY_BLOCK_T* __newCunt__ = 
                __stackGangsta__;

            return ( vPtr )( ( char* ) __newCunt__ + __BLOCK_SIZE );

        } else {
            __MEMORY_BLOCK_T* __newCunt__;
            __brkLocation__ = 
                (vPtr)syscall(
                    __NR_brk, 
                    0
                );

            __MEMORY_BLOCK_T* __request__ = ChunkRequest(
                __neededRoomForShit__
            );

            if(
                !__request__
            ) {
                vPtr __tempBrk__ = 
                    (vPtr)syscall(
                        __NR_brk, 
                        (char*)__brkLocation__ + __neededRoomForShit__
                    );
                
                if(
                    __tempBrk__ == __ALLOC_FAILED
                ) return NULL_PTR__;

                __request__->__nextMotherfucker__ = NULL_PTR__;
                __request__->__prevMotherfucker__ = __lastMotherfucker__;
                __request__->__size__ = __neededRoomForShit__;
                __request__->__free__ = FALSE__;
                __request__->__type__ = HEAP_ALLOC;

                } else {

                }

            }

    } else {
        // mmap engaged

        if(
            !__stackGangsta__
        ) {
            int flags = MAP_ANON | MAP_PRIVATE;


        }

        __MEMORY_BLOCK_T* __newCunt__;

        return (vPtr)((char*)(__newCunt__) + __BLOCK_SIZE);

    }

}

vPtr Realloc(
    vPtr __memory__, 
    size __new_size__
) {
    

    return NULL_PTR__;

}

vPtr AlignedAlloc(
    size __size__, 
    size __alignment__ 
);

void Free(
    vPtr __memory__
) {
    __MEMORY_BLOCK_T* __temp = __stackGangsta__;

}


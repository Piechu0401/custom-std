#ifndef __LIB_H
#define __LIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "core.h"

#define __byte                                  1
#define __kilobyte                              __Shift_Bits_Left(__byte, 10)
#define __megabyte                              __Shift_Bits_Left(__kilobyte, 10)
#define __gigabyte                              __Shift_Bits_Left(__megabyte, 10)
#define __terabyte                              __Shift_Bits_Left(__gigabyte, 10)
#define __pagesize                              __Shift_Bits_Left(__byte, 12)
#define __ALLOC_FAILED                          ((void*)(-1))

typedef enum __ALLOC_TYPE {
    HEAP_ALLOC = 1 << 1,
    VIRTUAL_ALLOC = 1 << 2

} __ALLOC_TYPE_T;

typedef struct __MEMORY_BLOCK {
    struct __MEMORY_BLOCK*                      __prevMotherfucker__;
    struct __MEMORY_BLOCK*                      __nextMotherfucker__;
    uint32*                                     __memSrart__;
    uint32*                                     __memEnd__;
    size                                        __size__;
    Bool                                        __free__;
    __ALLOC_TYPE_T                              __type__;

} __MEMORY_BLOCK_T;

#define __BLOCK_SIZE                            sizeof(__MEMORY_BLOCK_T)
#define __BLOCK_GUARD                           0xDEADBEEF
#define __BYTE_SIZE                             (__byte * (1 << 3))
#define __HEAP_ALLOC_LIMIT                      (__kilobyte * (1 << 7))

// bullshit for __MEMORY_BLOCK_T

__MEMORY_BLOCK_T* ChunkRequest                  ( size __size__ );
void MergeChunks                                ( vPtr __memory__ );
void SliceChunk                                 ( vPtr __memory__ );

// rest of that dumpster

vPtr Alloc                                      ( size __size__ );
vPtr Realloc                                    ( vPtr __memory__, size __new_size__ );
vPtr AlignedAlloc                               ( size __size__, size __alignment__ );
void Free                                       ( vPtr __memory__ );

#ifdef __cplusplus
        }
#endif

#endif
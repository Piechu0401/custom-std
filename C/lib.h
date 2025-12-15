#ifndef __LIB_H
#define __LIB_H

#define __shift(a,b) (a << b)
#define __byte 1
#define __kilobyte __shift(__byte, 10)
#define __megabyte __shift(__kilobyte, 10)
#define __gigabyte __shift(__megabyte, 10)
#define __terabyte __shift(__gigabyte, 10)

typedef unsigned long MemSize;

typedef struct __MEMORY_BLOCK {
    struct __MEMORY_BLOCK* __PrevMotherfucker__;
    struct __MEMORY_BLOCK* __NextMotherfucker__;
    MemSize __Size__;


} __MEMORY_BLOCK_T;

#endif
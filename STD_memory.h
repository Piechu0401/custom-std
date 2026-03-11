#ifndef __STD_MEMORY_H
#define __STD_MEMORY_H

typedef unsigned long Size; 



namespace STD {

};

void __MEM_COPY(
    void* __To,
    const void* __From
) noexcept;

void* __MEM_ALLOC(
    void* __Ptr,
    Size __Size
) noexcept;

void* __MEM_REALLOC(
    void* __Ptr,
    Size __Size
) noexcept;

void __MEM_FREE(
    void* __Ptr
);

#endif
////////////////////////////////////////////////////////////////
//                                                            //
// basics, and not required bullshit                          //
//                                                            //
////////////////////////////////////////////////////////////////

#ifndef                     __CORE_H
#define                     __CORE_H

#ifdef __cplusplus
extern "C" {
#endif

// limits of those fuckers

#define MAX_UINT8           (1 << 8)
#define MAX_UINT16          (1 << 16)
#define MAX_UINT32          (1 << 32)
#define MAX_UINT64          ((((1 << 63) - 1) << 1) + 1)
#define MAX_INT8            (1 << 7)
#define MAX_INT16           (1 << 15)
#define MAX_INT32           (1 << 31)
#define MAX_INT64           (1 << 63)
#define MAX_INTN(N)         ( N <= 63 ) ? (1 << N) : 0

// numeric types and shit

typedef unsigned char               uint8;
typedef unsigned short              uint16;
typedef unsigned int                uint32;
typedef unsigned long               uint64;
typedef signed char                 int8;
typedef signed short                int16;
typedef signed int                  int32;
typedef signed long                 int64;

// my typedefs, not necessary, im just lazy

typedef unsigned int                size;
typedef void*                       vPtr;
typedef unsigned long               uPtr;
typedef uint32                      Bool;

#if defined(__linux__)
    #include                        <unistd.h>
    #include                        <sys/syscall.h>
    #include                        <sys/mman.h>
#elif                               defined(__WIN32) || defined(__WIN64)
    #include                        <windows.h>
#endif

// some macros like mac and cheese hehe... yeah I better stfu
#define __Align(Size, Align)            ( ( Size + Align - 1 ) & ~( Align - 1 ) )
#define __Floor(N)                      ( (int)(N) )
#define __Ceil(N)                       ( (int)( N + 1 ) )
#define __Max_Uint_N(N)                 ( (unsigned char)(N) < 64 ) ? ( 1 << (unsigned char)(N) ) : 0
#define __Shift_Bits_Left(a, b)         ( a << b )
#define __Shift_Bits_Right(a, b)        ( a >> b )

#define TRUE__                          1
#define FALSE__                         0
#define NULL_PTR__                      NULL

#ifdef __cplusplus
            }
#endif

#endif
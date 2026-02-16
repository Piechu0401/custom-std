#ifndef __STD_INT_H
#define __STD_INT_H

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long       u64;
typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long         i64;

#define U8_MAX              (((((u8)(1) << 7) - 1) << 1) + 1)
#define U16_MAX             (((((u16)(1) << 15) - 1) << 1) + 1)
#define U32_MAX             (((((u32)(1) << 31) - 1) << 1) + 1)
#define U64_MAX             (((((u64)(1) << 63) - 1) << 1) + 1)
#define I8_MAX              (((((i8)(1) << 7) - 1) << 1) + 1)
#define I16_MAX             (((((i16)(1) << 7) - 1) << 1) + 1)
#define I32_MAX             (((((i32)(1) << 7) - 1) << 1) + 1)
#define I64_MAX             (((((i64)(1) << 7) - 1) << 1) + 1)
#define I8_MIN              (((((i8)(-1) << 7) - 1) << 1) + 1)
#define I16_MIN             (((((i16)(-1) << 7) - 1) << 1) + 1)
#define I32_MIN             (((((i32)(-1) << 7) - 1) << 1) + 1)
#define I64_MIN             (((((i64)(-1) << 7) - 1) << 1) + 1)

namespace STD {};

#endif
// my attempt to recreate std as best as I can

#ifndef                 __STANINT_H
#define                 __STANINT_H

typedef unsigned char   UI8;    // basic stuff here, unsigned and signed ints.
typedef unsigned short  UI16;
typedef unsigned int    UI32;
typedef unsigned long   UI64;
typedef signed char     IN8;
typedef signed short    IN16;
typedef signed int      IN32;
typedef signed long     IN64;

#ifndef UI8_MAX                 // min and max define, nothing special
    #define UI8_MAX     ((UI8)1 << 8)
#endif

#ifndef UI16_MAX
    #define UI16_MAX    ((UI16)1 << 16)
#endif

#ifndef UI32_MAX
    #define UI32_MAX    ((UI32)1 << 32)
#endif

#ifndef UI64_MAX
    #define UI64_MAX    (((((UI64)1 << 63) - 1) << 1) + 1)
#endif

#ifndef IN8_MAX
    #define IN8_MAX     ((IN8)1 << 7)
#endif

#ifndef IN16_MAX
    #define IN16_MAX    ((IN16)1 << 15)
#endif

#ifndef IN32_MAX
    #define IN32_MAX    ((IN32)1 << 31)
#endif

#ifndef IN64_MAX
    #define IN64_MAX    ((IN64)1 << 63)
#endif

#ifndef IN8_MIN
    #define IN8_MIN     -((IN8)1 << 7)
#endif

#ifndef IN16_MIN
    #define IN16_MIN    -((IN16)1 << 15)
#endif

#ifndef IN32_MIN
    #define IN32_MIN    -((IN32)1 << 31)
#endif

#ifndef IN64_MIN
    #define IN64_MIN    -((IN64)1 << 63)
#endif

#endif
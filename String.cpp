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

namespace MyStd {
    void Malloc()

};

#endif
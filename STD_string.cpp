#include "STD_string.h"

namespace STD {
    String::String() noexcept {}
    
    String::String(
        const char* __Data
    ) noexcept {
        unsigned long __l = __STR_LEN( __Data );
        unsigned long __i{0};
        __size = __l;

        __data = new char[__size];

        while( __i < __size ) {
            __data[__i] = __Data[__i];
            ++__i;

        }

        __data[__size] = __EOF;

    }

    String::String(
        const String& __Other
    ) noexcept {
        __size = __Other.__LENGTH();
        __data = new char[__size];

        for( int __i{0}; __i < __size; ++__i )
            __data[__i] = __Other[__i];

    }

    String::~String() noexcept { delete[] __data; }

};
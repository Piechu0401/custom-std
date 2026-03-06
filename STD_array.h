#ifndef __STD_ARRAY_H
#define __STD_ARRAY_H

#include "STD_core.h"

namespace STD {
    template<typename __Type, unsigned long __Size>
    class Array {
        public:
            explicit Array() noexcept :
                __data(nullptr),
                __size(__Size)
            { __data = new __Type[__size]; }
            
            explicit Array( __Type __Data[__Size] ) noexcept :
                __data(nullptr),
                __size(__Size) 
            {
                __data = new __Type[__size];
                for( int __i{0}; __i < __size; ++__i )
                    __data[__i] = __Data[__i];

            }
            
            explicit Array( const __Type* __Data ) noexcept :
                __data(nullptr),
                __size(__Size) 
            {
                __data = __Data;
            }

            inline const bool operator==( const Array& __Other ) noexcept { return __Other == this; };
            
            inline const Array& operator=( const Array& __Other ) noexcept {
                if( this == __Other ) return this;
                return __Other;

            }

            inline __Type& operator[]( const unsigned long& __Index ) {
                if( __Index >= 0 && __Index < __size ) return *(__data + __Index);
                else throw HaltError(__INDEX_OUT_OF_SCOPE);

            }

            inline const __Type* __BEGIN() const noexcept { return __data; }
            inline const __Type* __END() const noexcept { return (__data + __size); }
            inline const unsigned long __SIZE() const noexcept { return __size; } 

        private:
            __Type* __data;
            unsigned long __size;

    };

};

#endif
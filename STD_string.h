#ifndef __STD_STRING_H
#define __STD_STRING_H

#include "STD_core.h"
#include <stdio.h>

namespace STD {
    class String {
        public:
            explicit String() noexcept;
            String(
                const char* __Data
            ) noexcept;
            String(
                const String& __Other
            ) noexcept;
            ~String() noexcept;

            inline const bool operator==(
                const String& __Other
            ) noexcept { return __data == __Other.__C_STR(); }

            inline const char* operator()() const noexcept { return __data; }

            inline const String& operator=(
                const String& __Other
            ) noexcept {
                if( __Other.__C_STR() == __data ) return *this;
                __data = __STR_CPY( __data, __Other.__C_STR() );
                return *this;

            }

            inline const char* operator=(
                char* __Other
            ) noexcept { 
                if( __Other == __data )
                    return __data; 
                __data = __Other;
                return __Other;
                
            }

            inline char& operator[](
                const unsigned long& __Index
            ) const noexcept { return *(__data + __Index); };

            inline const String& operator+(
                const String& __Other
            ) noexcept {
                char* __temp = new char[__size + __Other.__LENGTH()];
                unsigned long __i{0};

                for( __i = __i; __i < __size; ++__i )
                    __temp[__i] = __data[__i];

                __size += __Other.__LENGTH();

                for( __i = __i; __i < __size; ++__i )
                    __temp[__i] = __Other[__i - __Other.__LENGTH()];

                __data = __STR_CPY( __data, __temp );
            
                return *this;

            }

            inline const char* __C_STR() const noexcept { return __data; }
            inline const char* __BEGIN() noexcept { return __data; }
            inline const char* __END() noexcept { return __data + __size; }
            inline const unsigned long __LENGTH() const noexcept { return __size; }
            inline const String __SUB(
                const unsigned long& __Begin,
                const unsigned long& __Length
            ) const {
                if(
                    __Begin + __Length <= __size
                ) {
                    char* __temp = new char[__Length];
                    for( unsigned long __i{__Begin}; __i < __Begin + __Length; ++__i )
                        __temp[__i - __Begin] = __data[__i];
                    __temp[__Length] = __EOF;

                    return String(__temp);

                }

                throw HaltError(__INVALID_SUB_STR_BEG_LEN);

            }

        private:
            char* __data;
            unsigned long __size;

    };

};

#endif
//////////////////////////////////////////////
//                                          //
// Michel Piech                             //
//                                          //
// string library, nothing revolutionary.   //
//                                          //
//////////////////////////////////////////////

#ifndef __STRING_H
#define __STRING_H

namespace MyStd {
    struct String {
        explicit String() noexcept;
        explicit String(
            const char* string
        ) noexcept;
        explicit String(
            char string[]
        ) noexcept;

        virtual String& operator=(
            const String& Other
        );
        virtual String& operator+(
            const String& Other
        );
        virtual String& operator[](
            const unsigned int Index
        );

        private:
            const char* string;

    };

    struct String8 : String {


    };

    struct String16 {};

    struct String32 {};

};

#endif
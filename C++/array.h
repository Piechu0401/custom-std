#ifndef __ARRAY_H
#define __ARRAY_H

#include "../C/lib.h"

namespace MyStd {
    template<typename __type__, size __size__>
    struct Array {
        explicit Array() noexcept;
        explicit Array(
            const char* __other__
        ) noexcept;
        explicit Array(
            char __other__[]
        ) noexcept;

        Array& operator[](
            const uint64& __index__
        );
        Array& operator=(
            const Array& __other__
        );

        private:
        __type__* Data;
        size Limit;

    };

    #include "array.ipp"

};

#endif
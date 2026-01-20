// a basic array with constant size, nothing complicated at all

#ifndef __STANARRAY_H
#define __STANARRAY_H

namespace stan {
    template<typename ArrayType, unsigned long ArraySize>
    class array {
        public:
            explicit array() noexcept;

        private:
            ArrayType* Data[ArraySize];
            unsigned long Size = ArraySize;

    };  

}

#endif
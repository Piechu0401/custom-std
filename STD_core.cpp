#include "STD_core.h"

namespace STD {
    HaltError::HaltError() noexcept {}
    HaltError::HaltError( const char* __Error ) noexcept { 
        __HALT( 
            __Error, 
            __STR_LEN(__Error) 
        ); 
    }

};
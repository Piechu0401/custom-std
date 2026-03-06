#include "STD_core.h"

namespace STD {
    HaltError::HaltError() noexcept {}
    HaltError::HaltError( const char* __Error ) noexcept {
        unsigned long __len{0};

        while( __Error[__len] != __EOF ) ++__len;

        __HALT( __Error, __len );   
    
    }

};
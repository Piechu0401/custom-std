#include "STD_array.h"
#include "STD_int.h"
#include "STD_io.h"
#include <iostream>

int main() {
    STD::Array<char, 10> __arr;
    
    for( unsigned long __i{0}; __i < __arr.__SIZE(); ++__i ) {
        __arr[__i] = 97;
        std::cout << __arr[__i] << " ";

    }

    std::cout << "\n";

    __arr[2] = 98;

    for( auto* __it = __arr.__BEGIN(); __it != __arr.__END(); ++__it ) 
        std::cout << *__it << " ";

    return 0;

}

// g++ -o0 test.cpp -I*.h -o test
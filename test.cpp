#include "STD_string.h"
#include "STD_io.h"

int main() {
    STD::String __a = "AAAA";
    STD::String __b = "BBBB";
    __a = __a + __b;
    __PRINT( __a.__C_STR() );
    __PRINT("\n");
    __a = __a.__SUB( 2, 4 );
    __PRINT( __a.__C_STR() );
    __PRINT("\n");

    return 0;

}

// g++ -o0 test.cpp -I*.h -o test
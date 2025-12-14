#include <stdio.h>
#include "Memory.h"

// my notes
// g++ -g -O0 [...] -o test

int main(
    int ArgCount,
    const char* ArgValues[]
) {
    Size s = 5;
    int* lol = (int*)MyStd::Malloc(
        s * sizeof(int)
    );

    for(
        auto i{0u}; i < s; i++
    )   {
        lol[i] = i;
        printf(
            "%i\n",
            lol[i]
        );
    }

}
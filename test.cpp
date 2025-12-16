#include <cstddef>
#include <stdio.h>

#include "C/lib.h"

int main() {
    size a = 5;
    int* takichuj = (int*)Alloc(
        a * sizeof(int)
    );

    if(
        takichuj == NULL_PTR__
    ) printf("chuj");

    printf(
        "%i\n",
        takichuj[10000]
    );

    return 0;
}
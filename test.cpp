#include <cstddef>
#include <stdio.h>

#include "C/lib.h"

int main() {
    size a = 5;
    int* A = (int*)Alloc(
        a * sizeof(int)
    );

    if(
        A == NULL_PTR__
    ) printf("chuj");

    printf(
        "%i\n",
        A[1024]
    );

    return 0;
}
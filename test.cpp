#include <stdio.h>
#include <stdlib.h>

int main() {
    char* p = (char*)malloc(10);

    for (int i = 0; i < 1000; i++) {
        p[i] = 'A';   // WYJŚCIE DALEKO POZA 10
    }

    printf("still alive: %c\n", p[500]);

    free(p);
    return 0;
}
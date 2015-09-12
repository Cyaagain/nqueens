#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nqueens.h"

int main(int argc, char ** argv)
{
    int      n = 16;
    int      middle;
    uint64_t count = 0;
    int i = 0;
    int conflict = 0; // position of conflict

    if (argc == 2) {
        n = atoi(argv[1]);
    }
    if (n == 1) {
        printf("Totle: 1\n");
        return 0;
    }
    if (n < 4) {
        printf("Totle: 0\n");
        return 0;
    }
    // symmetrical
    middle = (n + 1) >> 1;

    // main loop
    while (i < middle) {

    }
    
    return 0;
}

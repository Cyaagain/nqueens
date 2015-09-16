#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nqueens.h"

int main(int argc, char ** argv)
{
    int      n = 16;
    uint64_t count = 0;
    q_body_t *nq = NULL;

    if (argc == 2) {
        n = atoi(argv[1]);
    }
    if (n == 1) {
        printf("1 Queen: 1\n");
        return 0;
    }
    if (n < 4) {
        printf("%d Queens: 0\n", n);
        return 0;
    }

    nq = q_queen_init(n);
    if (!nq) {
        printf("Malloc error! Exiting...\n");
        return 1;
    }

    count = q_nqueens_loop(nq);

    
    printf("%d Queens: %llu\n", n, count);
    
    return 0;
}

#include "nqueens.h"

//create and init
q_body_t *q_queen_init(int n)
{
    q_body_t *q;
    int i;
    q = malloc(sizeof(q_body_t));
    if (!q) {
        return q;
    }
    q->len = n;

    q->start = malloc(sizeof(int) * n);
    if (!q->start) {
        free(q);
        return NULL;
    }
    q->end = q->start + n;
    q->current = q->start;
    q->check_rest = calloc(sizeof(int) * n);
    if (!q->check_rest) {
        free(q->start);
        free(q);
        return NULL;
    }
    
    //init q->start as {0,1,2,...,n-1} 
    for(i = 0;i < n;i++) {
        q->start[i] = i;
    }

    //init diagonal arrays
    q->diag1.diag = calloc(sizeof(int) * (2 * n - 1));
    if (!q->diag1.diag) {
        free(q->start);
        free(q->check_rest);
        free(q);
        return NULL;
    }
    q->diag1.cur = q->diag1.diag;

    q->diag2.diag = calloc(sizeof(int) * (2 * n - 1));
    if (!q->diag2.diag) {
        free(q->diag1.diag);
        free(q->check_rest);
        free(q->start);
        free(q);
        return NULL;
    }
    q->diag2.cur = q->diag2.diag;
    
    //end

    return q;
}


void q_queen_free(q_body_t *q)
{
}

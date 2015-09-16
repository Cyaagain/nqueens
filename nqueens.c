#include "nqueens.h"

//create and init
q_body_t *
q_queen_init(int n)
{
    q_body_t *q;
    int i;
    q = calloc(1, sizeof(q_body_t));
    if (!q) {
        return q;
    }
    q->len = n;

    q->start = malloc(sizeof(int) * n);
    if (!q->start) {
        free(q);
        return NULL;
    }
    q->current = q->start;
    q->end = q->start + n;
    q->check_rest = calloc(n, sizeof(int));
    if (!q->check_rest) {
        free(q->start);
        free(q);
        return NULL;
    }
    q->cur_rest = q->check_rest;
    
    //init q->start as {0,1,2,...,n-1} 
//    for(i = 0;i < n;i++) {
//        q->start[i] = i;
//    }

    //init diagonal arrays
    q->diag1 = calloc((2 * n - 1),sizeof(int));
    if (!q->diag1) {
        free(q->start);
        free(q->check_rest);
        free(q);
        return NULL;
    }

    q->diag2 = calloc((2 * n - 1), sizeof(int));
    if (!q->diag2) {
        free(q->diag1);
        free(q->check_rest);
        free(q->start);
        free(q);
        return NULL;
    }
     
    //end

    return q;
}


void
q_queen_free(q_body_t *q)
{

        free(q->diag2);
        free(q->diag1);
        free(q->check_rest);
        free(q->start);
        free(q);
}

void 
q_pop_queen(q_body_t *q)
{
    q->current--;
    q->pos--;
    q->check_rest[*q->current] = 0;
    q->rest_pos = *q->current;
    q->cur_rest = q->check_rest + q->rest_pos;
    Q_DIAG1_CUR(q) = 0;
    Q_DIAG2_CUR(q) = 0;
}

uint64_t
q_nqueens_loop(q_body_t *q) 
{
    int middle = (q->len + 1) >> 1;
    int i = 0;
    int j = 0;
    uint64_t  count = 0;
    int n = q->len;

//    while (i < middle) {
    while (i < n) {
        while (!Q_IF_CONFLICT(q)) {
            
            *q->cur_rest = 1;
            *q->current = q->rest_pos;
            q->current ++;
            Q_DIAG1_CUR(q) = 1;
            Q_DIAG2_CUR(q) = 1;
            q->pos++;
            
            if (q->current == q->end) {
                count ++;
                //need to pop3
//                q_pop_queen(q);
                q_pop_queen(q);
                q_pop_queen(q);
                break;
            }
            
            j = 0;
            Q_FIND_NEXT_LINE_QUEEN(q->check_rest, j);
            q->cur_rest = q->check_rest + j;
            q->rest_pos = j;
        }
        q->rest_pos++;
        do {
            Q_FIND_NEXT_QUEEN(q->check_rest, q->rest_pos, q->len);
            if (q->rest_pos != q->len) {
                q->cur_rest = q->check_rest + q->rest_pos;
                break;
            }
            //this position all confilct. Then pop the previos one and check again
            q_pop_queen(q);
            q->rest_pos++;
        } while (q->current != q->start);
        if (q->current != q->start) {
            continue;
        }
        i++;
        *q->current = i;
        q->pos = 0;
        q->rest_pos = i;
        q->cur_rest = q->check_rest + i;
    }
//    count <<= 1;
    return count;
}



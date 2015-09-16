#ifndef NQUEENS_H_INCLUDED
#define NQUEENS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define QUEEN_OK        1
#define QUEEN_ERROR     0


typedef struct q_body_s{
    int       len;
    int      *start;
    int      *end; //end = start + len
    int      *current;
    int       pos; // start + pos = cur

    int      *diag1;
    int       *diag2;

    int      *check_rest;
    int      *cur_rest;
    int       rest_pos;
    
} q_body_t;


#define   Q_FIND_NEXT_LINE_QUEEN(q, i)    \
    do {                                  \
        while(q[i++]);                    \
        --i;                              \
    } while(0)

#define   Q_FIND_NEXT_QUEEN(q, start,end) \
    do {                                  \
        while(start < end && q[start]) { \
            start++;                      \
        }                                 \
    } while(0)

#define Q_DIAG1_CUR(q)  q->diag1[q->pos+q->rest_pos]
#define Q_DIAG2_CUR(q)  q->diag2[q->pos-q->rest_pos+q->len-1]

#define   Q_IF_CONFLICT(q)                \
    ((Q_DIAG1_CUR(q)) == 1 || (Q_DIAG2_CUR(q)) == 1)

/*
pos = q->rest_pos + q->current
di = q->diagi.cur
*/
#define   Q_POP_QUEEN(q)                  \
    do {                                  \
        q->rest_pos = *q->current;        \
        *q->cur_rest = 0;                 \
        Q_DIAG1_CUR(q) = 0;               \
        Q_DIAG2_CUR(q) = 0;               \
        q->current--;                     \
    } while(0)

    
q_body_t *q_queen_init(int n);
void q_queen_free(q_body_t *q);
uint64_t q_nqueens_loop(q_body_t *q);
#endif // NQUEENS_H_INCLUDED


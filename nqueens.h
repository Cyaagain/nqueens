#ifndef NQUEENS_H_INCLUDED
#define NQUEENS_H_INCLUDED

#define QUEEN_OK        1
#define QUEEN_ERROR     0

// struct to store arrays to check conflick in  diagonal lines
typedef struct q_diag_s {
    int    *diag; //len equals q_body_t.len * 2 - 1
    int    *cur;
} q_diag_t;

typedef struct q_body_s{
    int       len;
    int      *start;
    int      *end; //end = start + len
    int      *current;

    q_diag_t  diag1;
    q_diag_t  diag2;

    int      *check_rest;
    
} q_body_t;


#define   Q_FIND_NEXT_LINE_QUEEN(q, i)    \
    do {                                  \
        while(q[i++]);                    \
        --i;                              \
    } while(0)

#define   Q_FIND_NEXT_QUEEN(q, start,end) \
    do {                                  \
        while(start < end && q[start]) {  \
            start++;                      \
        }                                 \
    } while(0)

#define   Q_FIND_CONFLICT(p,q,i)          ((p)[i] == 1 || (q)[i] == 1)

#endif // NQUEENS_H_INCLUDED


#ifndef BID_STACK_H
#define BID_STACK_H
#define SNULL NULL

#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

typedef struct tNodeS *tPosS;
typedef tPosS tStack;

typedef struct tItemS{
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;

struct tNodeS{
    tItemS dataS;
    tPosS next;
};

void createEmptyStack(tStack *S);
bool isEmptyStack(tStack S);
tItemS peek(tStack S);
bool push(tItemS d, tStack *S);
void pop(tStack *S);


#endif

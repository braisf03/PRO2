#include "bid_stack.h"

void createEmptyStack(tStack *S){
    *S = SNULL;
}
bool isEmptyStack(tStack S){
    return S == SNULL;
}
tItemS peek(tStack S){
    return S->dataS;
}
bool createNodeS(tPosS *p){
    *p = malloc(sizeof(struct tNodeS));
    if (*p == SNULL) {
        return false;
    }else {
        return true;
    }
}
bool push(tItemS d, tStack *S){
    tPosS aux;

    if (!createNodeS(&aux)) {
        return false;
    }
    aux->dataS = d;
    aux->next = SNULL;
    if(isEmptyStack(*S)) {
        *S = aux;
    }else{
        aux->next = *S;
        *S = aux;
    }
    return true;
}
void pop(tStack *S){
    tPosS aux;
    aux = *S;
    *S = (*S)->next;
    free(aux);
}

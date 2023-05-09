#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "types.h"
#include "bid_stack.h"

#include "types.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define LNULL NULL

typedef struct Node *tPosL;

typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
} tItemL;

struct Node {
    tItemL datos;
    tPosL siguiente;
};

typedef tPosL tList;

void createEmptyList(tList *L); //Modificadora

bool isEmptyList(tList L);  //Observeadora

bool insertItem(tItemL d, tList *L); //Modificadora

void updateItem(tItemL d, tPosL p, tList *L);  //Modificadora

void deleteAtPosition(tPosL p, tList *L);  //Modificadora

tPosL findItem(tProductId d, tList L);  //Observadora

tPosL findPosition(tList L, tItemL d);

tItemL getItem(tPosL p, tList L);  //Observadora

tPosL first(tList L);  //Observadora

tPosL last(tList L);  //Observadora

tPosL previous(tPosL p, tList L);  //Observadora

tPosL next(tPosL p, tList L);  //Observadora

bool createNode(tPosL *p); //Función auxiliar para crear un nodo

#endif

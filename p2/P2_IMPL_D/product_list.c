/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Sánchez Ferreiro        LOGIN 1: brais.sferreiro
 * AUTHOR 2: José Moreira Fariña           LOGIN 2: j.moreira1
 * GROUP: 3.3
 * DATE: 08 / 04 / 22
 */

#include "product_list.h"


void createEmptyList (tList *L){  //Crea una lista vacía
    *L=LNULL;
}

bool isEmptyList(tList L){  //Comprueba si la lista dada esta vacía
    return L==LNULL;
}

bool insertItem(tItemL d, tList *L) {  // Inserta un objeto en la lista
    tPosL q,p;
    if (!createNode(&q)) {
        return false;
    } else {
        q->datos = d;
        q->siguiente = LNULL;
        if (*L == LNULL) {
            *L = q;
        } else {
            if(0>strcmp(d.productId,(*L)->datos.productId)){
                q->siguiente=*L;
                *L=q;
            }else{
                p=findPosition(*L,d);
                q->siguiente=p->siguiente;
                p->siguiente=q;

            }
        }
    }
    return true;
}

tPosL findPosition(tList L, tItemL d){
    tPosL p;
    p=L;
    while((p->siguiente!=NULL)&&(strcmp(p->siguiente->datos.productId,d.productId))<0){
        p=p->siguiente;
    }
    return p;
}

void updateItem(tItemL d, tPosL p, tList *L){  //Cambia los valores de un objeto de la lista
    p->datos=d;
}

void deleteAtPosition(tPosL p, tList *L) {  //Borra un objeto de la lista

    tPosL r,q;

    if (p == *L) {
        *L = p->siguiente;
    } else if (p->siguiente == LNULL) {
        r=previous (p,*L);
        r->siguiente = LNULL;
    } else {
        q=p->siguiente;
        p->datos=q->datos;
        p->siguiente=q->siguiente;
        p=q;
    }
    free(p);
}

tPosL findItem(tProductId d,tList L){  //Encuentra la posicion de un elemento de la lista
    if(isEmptyList(L)) {
        return LNULL;
    }else {
        tPosL q;
        for(q=L;(q!=LNULL) && (0!=strcmp(d,q->datos.productId)); q=q->siguiente);
        return q;
    }
}

tItemL getItem (tPosL p, tList L){  //Devuelve el contenido de un objeto
    return(p->datos);
}

tPosL first(tList L){  //Muestra la posición del primer elemento
    return (L);
}

tPosL last(tList L){  //Muestra la posición del ultimo elemento
    tPosL q;
    for(q=L;q->siguiente!=LNULL;q=q->siguiente);
    return q;
}

tPosL previous(tPosL p,tList L){  //Muestra la posicion del anterior objeto de la posición dada
    tPosL q;
    if (p==L) {
        return LNULL;
    }else {
        for(q=L; q->siguiente!=p; q=q->siguiente);
        return q;
    }
}

tPosL next(tPosL p,tList L){  //Muestra la posicion del siguiente objeto de la posición dada
    return p->siguiente;
}

bool createNode (tPosL *p) {  //Función auxiliar que crea la estructura en la que se va a almacenar un objeto
    *p = malloc(sizeof(struct Node));
    if (*p == LNULL) {
        return false;
    }else {
        return true;
    }
}
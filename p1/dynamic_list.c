/*
 * TÍTULO: PROGRAMACIÓN II LABORATORIOS
 * SUBTÍTULO: Práctica 1
 * AUTOR 1: Brais Sánchez Ferreiro USUARIO 1: brais.sferreiro
 * AUTOR 2: José Moreira Fariña    USUARIO 2: j.moreira1
 * GRUPO: 3.3
 * FECHA: 04 / 03 / 22
 */

#include "dynamic_list.h"

void createEmptyList (tList *L){  //Crea una lista vacía
    *L=LNULL;
}

bool isEmptyList(tList L){  //Comprueba si la lista dada esta vacía
    return L==LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {  // Inserta un objeto en la lista
    tPosL q;
    if (!createNode(&q)) {
        return false;
    } else {
        q->datos = d;
        q->siguiente = LNULL;
        if (*L == LNULL) {
            *L = q;
        } else {
            if (p == LNULL) {
                tPosL r;
                for (r = *L; r->siguiente != LNULL; r = r->siguiente){
                }
                r->siguiente = q;
            } else {
                if (p == *L) {
                    q->siguiente = p;
                    *L = q;
                } else {
                    q->siguiente = p->siguiente;
                    p->siguiente = q;
                    q->datos = p -> datos;
                    p->datos = d;

                }
            }
        }
    }
    return true;
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
        p->siguiente=q->siguiente;
        p->datos=q->datos;
        p=q;
    }
    free(p);
}

tPosL findItem(tProductId d,tList L){  //Encuentra la posicion de un elemento de la lista
    if(isEmptyList(L))
        return LNULL;
    else {
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
    if (p==L) return LNULL;
    else {
        for(q=L; q->siguiente!=p; q=q->siguiente);
        return q;
    }
}

tPosL next(tPosL p,tList L){  //Muestra la posicion del siguiente objeto de la posición dada
    return p->siguiente;
}

bool createNode (tPosL *p){  //Función auxiliar que crea la estructura en la que se va a almacenar un objeto
    *p=malloc(sizeof( struct Node));
    if (*p==LNULL) return false;
    else return true;
}
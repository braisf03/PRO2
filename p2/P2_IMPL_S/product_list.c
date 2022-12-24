/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Sánchez Ferreiro        LOGIN 1: brais.sferreiro
 * AUTHOR 2: José Moreira Fariña           LOGIN 2: j.moreira1
 * GROUP: 3.3
 * DATE: 29 / 04 / 22
 */

#include "product_list.h"

tPosL findPosition(tList L, tItemL d){ //Devuelve la posición del elemento en la lista
    tPosL p; // Variable auxiliar
    p=L; //Igualamos p al inicio de la lista
    while((p->siguiente!=NULL)&&(strcmp(p->siguiente->datos.productId,d.productId))<0){//Buscamos el elemento recorriendo la lista
        p=p->siguiente;
    }
    return p;
    //Devuelve la posición
}

bool createNode (tPosL *p) {  //Función auxiliar que crea la estructura en la que se va a almacenar un objeto.
    *p = malloc(sizeof(struct Node));//Se reserva espacio en memoria.
    if (*p == LNULL) { // Si se reserva con éxito se devuelve un true.
        return false;
    }else {            //Si falla se devuelve un false.
        return true;
    }
}

void createEmptyList (tList *L){  //Crea una lista vacía.
    *L=LNULL; //El puntero inicial se pone a nulo.
}

bool isEmptyList(tList L){  //Comprueba si la lista dada esta vacía
    return L==LNULL; //Compara lo que esta apuntando con nulo
}

bool insertItem(tItemL d, tList *L) {  // Inserta un objeto en la lista
    tPosL q,p; // Variables auxiliares
    if (!createNode(&q)) { //Si no se crea el nodo devuelve un error
        return false;
    } else { // Si se crea correctamente
        q->datos = d; // Se asignan los datos
        q->siguiente = LNULL; //Y el campo de siguiente
        if (*L == LNULL) { //Si la lista está vacía
            *L = q; // Se inserta al principio
        } else { //Si no esta vacía
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

void updateItem(tItemL d, tPosL p, tList *L){  //Cambia los valores de un objeto de la lista
    p->datos=d; // Actualiza los datos del elemento
}


void deleteAtPosition(tPosL p, tList *L) {  //Borra un objeto de la lista

    tPosL r,q; //Generamos variables auxiliares

    if (p == *L) { //Si el valor esta al principio
        *L = p->siguiente; //Cambiamos el puntero inicial
    } else if (p->siguiente == LNULL) { // Si el valor esta al final
        r=previous (p,*L); //Hacemos que una variable apunte al anterior
        r->siguiente = LNULL; // Y cambiamos el puntero
    } else { //Si el valor esta por en medio
        q=p->siguiente; //Reasignamos los punteros para dejar el elemento aislado
        p->datos=q->datos;
        p->siguiente=q->siguiente;
        p=q;
    }
    free(p);// Luego se borra
}

tPosL findItem(tProductId d,tList L){  //Encuentra la posición de un elemento de la lista.
    if(isEmptyList(L)) { //Si la lista está vacía devuelve nulo.
        return LNULL;
    }else { //Si no está vacía.
        tPosL q;//Recorremos la lista comparando los productId hasta encontrarlo o llegar al final de la lista.
        for(q=L;(q!=LNULL) && (0!=strcmp(d,q->datos.productId)); q=q->siguiente);
        return q;
    } //Devuelve nulo si no lo encuentra.
}

tItemL getItem (tPosL p, tList L){  //Devuelve el contenido de un objeto
    return(p->datos); //Devuelve los datos del elemento
}

tPosL first(tList L){  //Muestra la posición del primer elemento
    return (L); //Devuelve el elemento al que esté apuntando el primer puntero
}

tPosL last(tList L){  //Muestra la posición del último elemento
    tPosL q;
    for(q=L;q->siguiente!=LNULL;q=q->siguiente);//Recorremos la lista hasta el último elemento y lo devolvemos.
    return q;
}

tPosL previous(tPosL p,tList L){  //Muestra la posicion del anterior objeto de la posición dada
    tPosL q;
    if (p==L) { //Si el elemento es el primero devolvemos nulo.
        return LNULL;
    }else { //Si no, recorremos la lista hasta encontrar el elemento y devolvemos el anterior.
        for(q=L; q->siguiente!=p; q=q->siguiente);
        return q;
    }
}

tPosL next(tPosL p,tList L){  //Muestra la posicion del siguiente objeto de la posición dada
    return p->siguiente; //Devuelve el siguiente al elemento
}

void BorrarUltimo(tList *L){
    if((*L)->siguiente==NULL){
        *L=NULL;
    }else{
        tPosL p;
        for(p=*L;p->siguiente!=NULL;p=p->siguiente);
        p->anterior->siguiente=NULL;
        free(p);
    }
}
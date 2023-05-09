#include "static_list.h"

void createEmptyList(tList *L) {  //Crea una lista poniendo el lastPos en -1/NULL.
    L->lastPos = LNULL;
}

bool isEmptyList(tList L) {  //Comprueba si la lista está vacía.
    return (L.lastPos == LNULL);
}

tPosL first(tList L) {  //Devuelve la posición del primer elemento de la lista.
    return 0;
}

tPosL previous(tPosL p, tList L) {  //Devuelve la posición del anterior elemento de la lista.
    return p - 1;
}

tPosL last(tList L) {  //Devuelve la posición del último elemento de la lista.
    return L.lastPos;
}

tPosL next(tPosL p, tList L) {  //Devuelve la posición del siguiente elemento de la lista.
    if (p == L.lastPos) {
        return LNULL;
    } else {
        return p + 1;
    }
}

void updateItem(tItemL d, tPosL p, tList *L) {  //Actualiza el contenido del elemento seleccionado.
    L->data[p] = d;
}

tItemL getItem(tPosL p, tList L) {  //Devuelve la información del elemento dado.
    return L.data[p];
}

void deleteAtPosition(tPosL p, tList *L) {  //Borra un elemento.
    tPosL i;
    for (i = p; i < L->lastPos; i++) {
        L->data[i] = L->data[i + 1];  //Aquí se va copiando el elemento siguiente del que se quiere borrar en el mismo sitio hasta que se acaba el array el el lastPos.
    }
    L->lastPos--;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;
    if (L->lastPos == MAX - 1) {
        return false;  //Si la lista esta llena no puede introducir nada.
    } else {
        L->lastPos++;
        if (p == LNULL) { //Si p es LNULL se introduce en el final.
            L->data[L->lastPos] = d;
        } else {
            for (i = L->lastPos; i >= (p + 1); i--) { //Si se introduce en el medio hay que mover el resto de elementos que estan a su derecha una posición.
                L->data[i] = L->data[i - 1];  //Hasta lastPos.
            }
            L->data[i] = d;
        }
        return true;
    }
}

tPosL findItem(tProductId d, tList L) {  //Busca un elemento por su Id.
    tPosL i;
    if (isEmptyList(L)) {
        return LNULL;  // Si esta vacía devuelve un LNULL.
    } else {
        for (i = 0; (i <= L.lastPos) && (0 != strcmp(d, L.data[i].productId)); i++) { //Aquí va comparando los strings... hasta que lo encuentra o...
        }
        if (strcmp(L.data[i].productId, d) == 0) {
            return i; //...hasta que lo encuentra o...
        } else {
            return LNULL; // ...devuelve LNULL por no haberlo encontrado.
        }
    }
}


#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define SNULL -1
#define SMAX 25

typedef struct tItemS{
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;

typedef int tPosS;

typedef struct tStack{
    tItemS data[SMAX];
    tPosS top;
}tStack;

void createEmptyStack(tStack *stack); //Generadora.
/*
Objetivo: Crea una pila vacía
Salida: Una pila vacía
Post-condición: La pila sin datos
*/
bool isEmptyStack(tStack stack); //Observadora.
/*
Objetivo: Determina si una pila está vacía.
Entrada:
    Stack: Pila a comprobar.
Salida:
    Verdadero si la pila está vacía, falso en caso contrario.
Precondición:
    La pila debe estar inicializada.
 */

tItemS peek(tStack stack); //Observadora.
/*
+Objetivo: Recupera el contenido del elemento de la cima de la pila.
+Entrada:
    -Stack: Pila donde obtener el dato.
+Salida:
    -Item: Contenido del elemento de la cima de la pila.
+Precondición: La pila no está vacía.
 */

void pop(tStack *stack); //Destructora.
/*
+Objetivo: Saca el elemento de la cima de la pila.
+Entrada:
    -Stack: Pila de donde vamos a sacar.
+Salida:
    -Stack: Pila sin el elemento de su cima.
+Precondición: La pila no está vacía.
 */

bool push(tItemS item, tStack *stack); //Generadora.
/*
+Objetivo: Mete un elemento en la pila quedando en la cima.
+Entrada:
    -Item: Contenido del elemento a meter.
    -Stack: Pila donde vamos a meter.
+Salida:
    -Stack: Pila con el elemento Item en la cima y
     verdadero si se ha podido meter, falso en caso contrario.
 */

#endif

/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Sánchez Ferreiro        LOGIN 1: brais.sferreiro
 * AUTHOR 2: José Moreira Fariña           LOGIN 2: j.moreira1
 * GROUP: 3.3
 * DATE: 29 / 04 / 22
 */

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
    tPosL anterior;
};

typedef tPosL tList;

void createEmptyList(tList *L); //Modificadora.
/*
+Objetivo:
    -Crea una lista vacía y la inicializa.
+Salida:
    -Una lista vacía.
+Post-condición:
    -La lista sin datos.
 */

bool isEmptyList(tList L);  //Observadora.
/*
+Objetivo:
    -Determina si la lista está vacía.
+Entrada:
    -List: Lista a comprobar
+Salida:
    -Verdadero si la lista est ́a vac ́ıa, falso en caso contrario
 */

bool insertItem(tItemL d, tList *L); //Modificadora.
/*
+Objetivo:
    -Inserta un elemento en la lista seg ́un el criterio de ordenación
    sobre el campo Item.
+Entrada:
    -Item: Contenido del elemento a insertar.
    -List: Lista donde vamos a insertar.
+Salida:
    -List: Lista con el elemento Item insertado en la posición correspondiente según su contenido
    y verdadero si se ha podido insertar, falso en caso contrario.
+Precondición:
    -La lista est ́a inicializada
+Post-condición:
    -Las posiciones de los elementos de la lista posteriores a la del
    elemento insertado pueden haber variado.
 */

void updateItem(tItemL d, tPosL p, tList *L);  //Modificadora.
/*
+Objetivo:
    -Modifica el contenido de un elemento de la lista.
+Entrada:
    -Item: Nuevo contenido a asignar al elemento en Position.
    -Position: Posición del elemento que queremos modificar.
    -List: Lista a modificar.
+Salida:
    -List: Lista con el contenido del elemento modificado.
+Precondición:
    -Position es una posición válida de la lista.
 */

void deleteAtPosition(tPosL p, tList *L);  //Modificadora.
/*
+Objetivo:
    -Elimina de la lista un elemento con cierta posición.
+Entrada:
    -Position: Posición del elemento a eliminar
    -List: Lista a modificar
+Salida:
    -List: Lista sin el elemento correspondiente a Position
+Precondición:
    -Position es una posición válida de la lista
+Post-condición:
    -Las posiciones de los elementos de la lista posteriores a la de la
    posición eliminada pueden haber variado.
 */

tPosL findItem(tProductId d, tList L);  //Observadora.
/*
+Objetivo:
    -Busca el primer elemento con cierto contenido en la lista.
+Entrada:
    -Item: Contenido del elemento buscado.
    -List: Lista donde realizar la búsqueda.
+Salida:
    -Position: Posición del elemento encontrado o nulo si no se encuentra.
 */

tItemL getItem(tPosL p, tList L);  //Observadora.
/*
+Objetivo:
    -Recupera el contenido de un elemento de la lista.
+Entrada:
    -Position: Posición del elemento buscado.
    -List: Lista donde realizar la búsqueda.
+Salida:
    -Item: Contenido del elemento que está en Position.
+Precondición:
    -Position es una posición válida en la lista.
 */

tPosL first(tList L);  //Observadora.
/*
+Objetivo:
    -Devuelve la posición del primer elemento de la lista.
+Entrada:
    -List: Lista a manipular.
+Salida:
    -Position: Posición del primer elemento.
+Precondición:
    -La lista no está vacía.
 */

tPosL last(tList L);  //Observadora.
/*
+Objetivo:
    -Devuelve la posición del último elemento de la lista.
+Entrada:
    -List: Lista a manipular.
+Salida:
    -Position: Posición del último elemento.
+Precondición:
    -La lista no está vacía.
 */

tPosL previous(tPosL p, tList L);  //Observadora.
/*
+Objetivo:
    -Devuelve la posición del elemento anterior al actual.
+Entrada:
    -Position: Posición del elemento actual.
    -List: Lista a manipular.
+Salida:
    -Posición del elemento anterior o nulo si es el primero.
+Precondición:
    -Position es una posición válida de la lista.
 */

tPosL next(tPosL p, tList L);  //Observadora.
/*
+Objetivo:
    -Devuelve la posición del elemento siguiente al actual.
+Entrada:
    -Position: Posición del elemento actual.
    -List: Lista a manipular.
+Salida:
    -Position: Posición del elemento siguiente o nulo si es el último.
+Precondición:
    -Position es una posición válida de la lista.
 */

void BorrarUltimo(tList *L);

#endif

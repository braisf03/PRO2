#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 25
#define LNULL -1

typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList *L);
/*
   Objetivo: Crear una lista vacía.
   Entradas: El nombre de la lista a crear.
   Salidas: Ninguna ya que es un procedimiento.
   PreCD: Ninguna.
   PostCD: La lista queda creada, inicializada y no contiene elementos.
 */

bool isEmptyList(tList L);
/*
   Objetivo: Determinar si una lista está vacía.
   Entradas: La lista que va a inspeccionar.
   Salidas: Devuelve un true si está vacía y un false si no lo está.
   PreCD: Ninguna.
   PostCD: Ninguna.
 */

tPosL first(tList L);
/*
   Objetivo: Devolver la posición del primer elemento de la lista.
   Entradas: La lista de la que va a devolver la primera posición.
   Salidas: La primera posición de esa lista.
   PreCD: La lista no debe estar vacía.
   PostCD: Ninguna.
 */

tPosL previous(tPosL p, tList L);
/*
   Objetivo:Devolver la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
   Entradas: La posición del elemento del que se va a sacar el anterior y la lista en la que está.
   Salidas: La posición anterior de la dada.
   PreCD: Que la posición introducida sea válida en la lista.
   PostCD: Ninguna.
 */

tPosL last(tList L);
/*
   Objetivo: Devuelve la posición del último elemento de la lista.
   Entradas: La lista de la que se va a devolver el último elemento.
   Salidas: La posición del último elemento de la lista.
   PreCD: La lista no debe estar vacía.
   PostCD: Ninguna.
 */

tPosL next(tPosL p, tList L);
/*
   Objetivo:Devolve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
   Entradas: La posición de la que se va a mirar la siguiente y la lista en la que esta.
   Salidas: La posición del siguiente elemento de la lista al indicado.
   PreCD: La posición introducida debe ser válida dentro de la lista.
   PostCD: Ninguna.
 */

void updateItem(tItemL d, tPosL p, tList *L);
/*
   Objetivo: Modificar el contenido del elemento situado en la posición indicada.
   Entradas: El contenido que se quiere modificar, la posición que se va a actualizar y la lista en la que está.
   Salidas: Ninguna ya que es un procedimiento.
   PreCD: La posición introducida en la lista debe ser válida dentro de ésta.
   PostCD: El orden de los elementos de la lista no se ha modificado.
 */

tItemL getItem(tPosL p, tList L);
/*
   Objetivo: Devolver el contenido del elemento de la lista que ocupa la posición indicada.
   Entradas: La posición de la lista que se quiere consultar y la lista en la que se encuentra.
   Salidas: La información del elemento que se quería mirar.
   PreCD: La posición introducida es válida dentro de la lista.
   PostCD: Ninguna.
 */

void deleteAtPosition(tPosL p, tList *L);  //
/*
   Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
   Entradas: La posición a eliminar y la lista de la que se quiere eliminar.
   Salidas: Ninguna ya que es un procedimiento.
   PreCD: La posición introducida es válida en la lista.
   PostCD: Las posiciones posteriores dentro de la lista podrían haber variado.
 */

bool insertItem(tItemL d, tPosL p, tList *L);  //Modificadora
/*
   Objetivo: Insertar un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final.
   Entradas: El elemento que se quiere añadir, su posición y la lista en la que se va a introducir.
   Salidas: Un true si se ha insertado y un false si no.
   PreCD: La posición en la lista es válida o es nula (LNULL).
   PostCD: Las posiciones posteriores dentro de la lista podrían haber variado.
 */

tPosL findItem(tProductId d, tList L);  //Observadora
/*
   Objetivo: Devolver la posición del primer elemento de la lista cuyo identificador de producto se corresponda con el indicado (o LNULL si no existe tal elemento).
   Entradas: El identificador del producto en cuestión (tProductId (char)) y la lista en la que se va a buscar.
   Salidas: Devolver la posición del elemento buscado.
   PreCD: Ninguna.
   PostCD: Ninguna.
 */

#endif

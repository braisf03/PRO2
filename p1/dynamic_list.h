/*
 * TÍTULO: PROGRAMACIÓN II LABORATORIOS
 * SUBTÍTULO: Práctica 1
 * AUTOR 1: Brais Sánchez Ferreiro USUARIO 1: brais.sferreiro
 * AUTOR 2: José Moreira Fariña    USUARIO 2: j.moreira1
 * GRUPO: 3.3
 * FECHA: 04 / 03 / 22
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define LNULL NULL

typedef struct Node *tPosL;

struct Node {
    tItemL datos;
    tPosL siguiente;
};

typedef tPosL tList;

void createEmptyList(tList *L); //Modificadora

bool isEmptyList(tList L);  //Observeadora

bool insertItem(tItemL d, tPosL p, tList *L); //Modificadora

void updateItem(tItemL d, tPosL p, tList *L);  //Modificadora

void deleteAtPosition(tPosL p, tList *L);  //Modificadora

tPosL findItem(tProductId d, tList L);  //Observadora

tItemL getItem(tPosL p, tList L);  //Observadora

tPosL first(tList L);  //Observadora

tPosL last(tList L);  //Observadora

tPosL previous(tPosL p, tList L);  //Observadora

tPosL next(tPosL p, tList L);  //Observadora

bool createNode(tPosL *p); //Función auxiliar para crear un nodo

#endif

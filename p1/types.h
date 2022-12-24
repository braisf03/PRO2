/*
 * TÍTULO: PROGRAMACIÓN II LABORATORIOS
 * SUBTÍTULO: Práctica 1
 * AUTOR 1: Brais Sánchez Ferreiro USUARIO 1: brais.sferreiro
 * AUTOR 2: José Moreira Fariña    USUARIO 2: j.moreira1
 * GRUPO: 3.3
 * FECHA: 11 / 03 / 22
 */

#ifndef PRO2_2022_P1_TYPES_H
#define PRO2_2022_P1_TYPES_H

#define NAME_LENGTH_LIMIT 10

typedef char tUserId[NAME_LENGTH_LIMIT];

typedef char tProductId[NAME_LENGTH_LIMIT];

typedef enum {
    book, painting
} tProductCategory;

typedef float tProductPrice;

typedef int tBidCounter;

typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
} tItemL;

#endif

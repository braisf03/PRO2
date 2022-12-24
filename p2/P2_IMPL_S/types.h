/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Sánchez Ferreiro        LOGIN 1: brais.sferreiro
 * AUTHOR 2: José Moreira Fariña           LOGIN 2: j.moreira1
 * GROUP: 3.3
 * DATE: 29 / 04 / 22
 */

#ifndef PRO2_2022_P2_TYPES_H
#define PRO2_2022_P2_TYPES_H

#define NAME_LENGTH_LIMIT 10

typedef char tUserId[NAME_LENGTH_LIMIT];

typedef char tProductId[NAME_LENGTH_LIMIT];

typedef enum {book, painting} tProductCategory;

typedef float tProductPrice;

typedef int tBidCounter;

#endif //PRO2_2022_P2_TYPES_H

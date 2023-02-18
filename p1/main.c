#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif

#ifdef STATIC_LIST
#include "static_list.h"
#endif

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L);
/*
Objetivo:Procesar las operaciones entregadas por la función readTasks.
Entradas:El número de operación, la orden (N/D/B/S), el Id del producto, el vendedor, su categoría, precio y la lista en la que va a trabajar.
Salidas: Procesa la/las órdenes recibidas y realiza las operaciones correspondientes.
Precondiciones: Debe existir una lista en la que trabajar.
Post-condiciones: Ninguna.
*/

void readTasks(char *filename, tList *L);
/*
Objetivo: Leer las operaciones del archivo .txt que se entrega al programa.
Entradas: El archivo a leer y la lista en la que se va a trabajar.
Salidas: Las operaciones que se han introducido en el fichero realizadas.
Precondiciones: Debe existir una lista en la que trabajar.
Post-condiciones: Ninguna.
*/

void funcionN(char *commandNumber, char command, char *param1, const char *param2, const char *param3, const char *param4, tList *L);
/*
Objetivo:Crear un nuevo nodo en la lista que albergue un item nuevo pasado por el fichero .txt.
Entradas:El número de operación, la orden, el Id del producto, el vendedor, su categoría, precio y la lista en la que va a trabajar.
Salidas: Crea una nueva entrada en la lista con la información especificada en el archivo .txt.
Precondiciones: Debe existir una lista en la que se pueda añadir el elemento.
Post-condiciones: Ninguna.
*/

void funcionD(const char *commandNumber, char command, char *param1, tList *L);
/*
Objetivo: Borrar un elemento de la lista.
Entradas: El número de operación, la orden, el Id del producto y la lista en la que está el objeto a borrar.
Salidas: La lista nueva con el elemento borrado.
Precondiciones: Ninguna.
Post-condiciones: Al haber borrado un elemento, las posiciones de los siguientes elementos pueden haber variado.
*/

void funcionB(char *commandNumber, char command, char *param1, char *param2, char *param3, tList *L);
/*
Objetivo: Actualizar un objeto si la puja cumple ciertas condiciones y aumentar el contado de pujas del elemento en ese caso.
Entradas: El número de operación, la orden, el Id del producto, la persona que puja, el dinero que puja y la lista a cambiar.
Salidas: La información del producto que se ha hecho la puja actualizada.
Precondiciones: Ninguna.
Post-condiciones: Ninguna.
*/

void funcionS(char *commandNumber, char command, tList L);
/*
Objetivo: Mostrar todos los elementos de la lista y estadísticas de lso datos.
Entradas: El número de operación, la orden y la lista de la que se muestran los datos.
Salidas: Todos los elementos de la lista impresos y las estadísticas.
Precondiciones: Ninguna.
Post-condiciones: Ninguna.
*/

int main(int nargs, char **args) {

    tList L;
    createEmptyList(&L); //Aqui creamos la lista que vamos a usar

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &L); // Y aquí empezamos a leer los parámetros del fichero .txt.

    return 0;
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    //Aquí está en switch que según la operación que quieras te dirige a uno u otro caso.
    switch (command) {
        case 'N':
            // Si la petición es N/New se genera un elemento en la lista. Más detalles en la especificación.
            funcionN(commandNumber, command, param1, param2, param3, param4, L);
            break;

        case 'D':
            // Si la petición es D/Delete se destruye un elemento de la lista. Más detalles en la especificación.
            funcionD(commandNumber, command, param1, L);
            break;

        case 'B':
            // Si la petición es B/Bid se genera una puja por un elemento.
            funcionB(commandNumber, command, param1, param2, param3, L);
            break;
        case 'S':
            // Si la función es S/Stats se genera una lista que enseña los elementos que hay en la lista y estadísticas.
            //Más detalles en la especificación.
            funcionS(commandNumber, command, *L);
            break;

        default:
            // En caso de que no sea alguna de N/D/B/S se imprime esto por pantalla. Más detalles en la especificación.
            printf("* %s? That's not a command, try again.*\n", commandNumber);
            break;
    }
}

void funcionN(char *commandNumber, char command, char *param1, const char *param2, const char *param3, const char *param4, tList *L) {

    //Si ese item no existe:
    if (findItem(param1, *L) == LNULL) {
        printf("********************\n"
               "%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3,
               param4);
        printf("* New: product %s seller %s category %s price %s\n", param1, param2, param3, param4);
        // Escribimos la cabecera de la operación y su operación en la lista.

        //Definimos un tItemL para almacenar las variables.....
        tItemL item;

        //....y vamos introduciendo las variables en ese tItemL (en este caso "item").
        //Copiamos el productId y seller en el tItemL.
        strcpy(item.productId, param1);
        strcpy(item.seller, param2);

        //El productCategory.
        const char *books = "book";
        if (strcmp(param3, books) == 0) {
            item.productCategory = book;
        } else {
            item.productCategory = painting;
        }

        //El productPrice.
        item.productPrice = strtof(param4, NULL);

        //Inicializamos el bidCounter a 0.
        item.bidCounter = 0;

        // Y por último lo insertamos en la lista.
        insertItem(item, LNULL, L);

    } else { // En caso de ya existir o de no poder insertarlo se imprime por pantalla un error.
        printf("********************\n");
        printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
        printf("+ Error: New not possible\n");
    }
}

void funcionD(const char *commandNumber, char command, char *param1, tList *L) {

    // Si el item existe en la lista...
    if (findItem(param1, *L) != LNULL) {
        // ...conseguimos sus valores...

        tItemL item;
        item = getItem(findItem(param1, *L), *L);
        char *a; // Es auxiliar para determinar la categoría del elemento.
        if (item.productCategory == book) {
            a = "book";
        } else {
            a = "painting";
        }

        printf("********************\n"
               "%s %c: product %s \n", commandNumber, command, param1);//... e imprimimos por pantalla la cabecera y la operación.

        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", param1, item.seller, a, item.productPrice, item.bidCounter);
        // Luego borramos el item en cuestión.
        deleteAtPosition(findItem(param1, *L), L);
    } else {
        // Si ese item no se encuentra en la lista se imprime un error.
        printf("********************\n");
        printf("%s %c: product %s\n", commandNumber, command, param1);
        printf("+ Error: Delete not possible\n");
    }

}

void funcionB(char *commandNumber, char command, char *param1, char *param2, char *param3, tList *L) {

    // Genero unas variables auxiliares.
    tItemL item;
    item = getItem(findItem(param1, *L), *L);
    float b;
    b = strtof(param3, NULL); // Para poder evaluar el precio como un float lo transformo.

    if ((findItem(param1, *L) != LNULL) && (param1 != item.seller) && (b > item.productPrice)) { //Más detalles en especificación.
        char *a; // Dependiendo de la categoría asigno si es libro o pintura.
        if (item.productCategory == book) {
            a = "book";
        } else {
            a = "painting";
        }
        printf("********************\n" // Y se imprime la cabecera.
               "%s %c: product %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);

        item.productPrice = b;
        item.bidCounter = item.bidCounter + 1;
        updateItem(item, findItem(param1, *L), L); // Se hacen cuentas para cambiar el precio, el contador de pujas y se actualiza el elemento.

        printf("* Bid: product %s seller %s category %s price %.2f bids %d\n", item.productId, item.seller, a, item.productPrice, item.bidCounter);
        // Luego se imprime la operación por pantalla.
    } else {
        // Si no se cumplen las condiciones del if de arriba....
        printf("********************\n" //... se imprime un error por pantalla.
               "%s %c: product %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);
        printf("+ Error: Bid not possible\n");
    }
}


void funcionS(char *commandNumber, char command, tList L) {

    // Definicines auxiliares para el item.
    tPosL p;
    tItemL item;

    // Definiciones de las variables necesarias para las estadísticas.
    float sumbook = 0, sumpainting = 0; // La suma de su precio.
    int contbook = 0, contpainting = 0; // Cuantos hay en cada categoría.
    float mediabook, mediapainting;  // Y la media del precio de ellos.


    printf("********************\n");
    printf("%s %c\n", commandNumber, command); // Se imprime la operación a hacer.
    if (!isEmptyList(L)) { // Si la lista no esta vacía..
        p = first(L); //Nos preparamos para recorrer la lista...
        while (p != LNULL) { // Mientras no lleguemos al final de ésta....
            item = getItem(p, L); // ...miramos el item..

            // Variable auxiliar para imprimira la categoría.
            char *a;
            if (item.productCategory == book) {
                a = "book";
            } else {
                a = "painting";
            }

            //... y lo imprimimos.
            printf("Product %s seller %s category %s price %.2f bids %d\n", item.productId, item.seller, a, item.productPrice, item.bidCounter);
            p = next(p, L);

            // Aquí mientras se vayan imprimiendo los valores de la lista se hace una recopilación de estadísticas.
            if (item.productCategory == book) {
                sumbook = sumbook + item.productPrice; // Si el elemento es un libro se acumula su precio...
                contbook = contbook + 1; //. y se suma 1 al contador.
            } else {
                sumpainting = sumpainting + item.productPrice; // Si el elemento es una pintura se acumula su precio...
                contpainting = contpainting + 1; //. y se suma 1 al contador.
            }
        }

        // Y luego se hacen las medias de los dos categorías.
        if (contpainting == 0) {
            mediapainting = 0; // Si la media está partida de 0 es 0...
        } else {
            mediapainting = (sumpainting / contpainting); // ...y si no, se hace la media aritmética.
        }
        if (contbook == 0) {
            mediabook = 0; // Si la media está partida de 0 es 0...
        } else {
            mediabook = (sumbook / contbook);  // ...y si no, se hace la media aritmética.
        }

        // Y finalmente se imprimen por pantalla las estadísticas recopiladas de lso elementos de la lista.
        printf("\nCategory  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", contbook, sumbook, mediabook);
        printf("Painting  %8d %8.2f %8.2f\n", contpainting, sumpainting, mediapainting);
    } else {
        // Y si la lista esta vacía.
        printf("+ Error: Stats not possible");
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL; // Definimos el fichero a usar.
    char *commandNumber, *command, *param1, *param2, *param3, *param4; //Los parámetros que va a recoger.
    const char delimiters[] = " \n\r"; // Los delimitadores entre los parámetros.
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r"); //Abrimos el fichero.

    if (f != NULL) { // Si el fichero no esta vacío....

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, L);
        }// ....leemos el fichero línea por línea y procesamos las peticiones escritas.

        fclose(f); // Al acabar se cierra el fichero.

    } else {
        printf("Cannot open file %s.\n", filename); // En caso de que el fichero no exista o no se pueda abrir.
    }
}

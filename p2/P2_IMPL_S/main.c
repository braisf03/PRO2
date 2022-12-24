/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Sánchez Ferreiro        LOGIN 1: brais.sferreiro
 * AUTHOR 2: José Moreira Fariña           LOGIN 2: j.moreira1
 * GROUP: 3.3
 * DATE: 29 / 04 / 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "product_list.h"

#define MAX_BUFFER 255

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L);

void readTasks(char *filename, tList *L);

const char *Categoria(char categoria);
/*
 * Objetivo:
 *      -Función auxiliar para determinar la categoría de cada producto.
 * Entrada:
 *      -Categoría: Valor que va a evaluar.
 * Salida:
 *      -La categoría del producto.
 */

void funcion_N(char *commandNumber, char command, char *param1, const char *param2, const char *param3, const char *param4,tList *L);
/*
 * Objetivo:
 *      -Crear un elemento nuevo en la lista.
 * Entradas:
 *      -CommandNumber: El número de operación.
 *      -Command: Operación a realizar, en este caso, New.
 *      -Param1: El identificador del producto.
 *      -Param2: El vendedor del producto.
 *      -Param3: La categoría del producto
 *      -Param4: El precio del producto.
 *      -L: La lista a insertar eel elemento.
 * Salidas:
 *      -La lista con el elemento nuevo ya insertado.
 * Precondiciones:
 *      -La lista debe estar inicializada
 * Post-condiciones:
 *      -Las posiciones de los elementos de la lista pueden haber cambiado.
 */

void funcion_S(char *commandNumber, char command, tList L);
/*
 * Objetivo:
 *      -Mostrar el listado de los productos actuales y sus datos.
 * Entradas:
 *       -CommandNumber: El número de operación.
 *       -Command: La operación a realizar.
 *       -L: La lista a analizar.
 * Salidas:
 *      -Ninguna.
 * Precondiciones:
 *      La lista debe estar inicializada.
 * Post-condiciones:
 *      -Ninguna.
 */

void funcion_B(char *commandNumber, char command, char *param1, char *param2, char *param3, tList *L);
/*
 * Objetivo:
 *      -Pujar por un determinado producto.
 * Entradas:
 *      -CommandNumber: Número de operación.
 *      -Command: La operación a realizar.
 *      -Param1: El identificador del producto por el que se va a pujar.
 *      -Param2: El pujador del producto.
 *      -Param3: El precio por el que se hace la puja.
 *      -L: La lista que se va a modificar si se acepta la puja.
 * Salidas:
 *      -La lista con el elemento y la pila actualizada si se produce la puja, si no se mantiene igual.
 * Precondiciones:
 *      -La lista y la pila deben de estar inicializadas.
 * Post-condiciones:
 *      -Ninguna.
 */

void funcion_D(const char *commandNumber, char command, char *param1, tList *L);
/*
 * Objetivo:
 *      -Borrar un producto de la lista vaciando antes su pila de pujas.
 * Entradas:
 *      -CommandNumber: El número de la operación.
 *      -Command: La operación a realizar.
 *      -Param1: El identificador del producto que se va a borrar.
 *      -L: La lista de la que se va a eliminar el producto si se realiza.
 * Salidas:
 *      -La lista sin el elemento dicho si se produce el borrado o igual si no se borró.
 * Precondiciones:
 *      -La lista y la pila del producto deben estar inicializadas.
 * Post-condiciones:
 *      -La posición de los elementos dentro de la lista puede haber cambiado.
 */

void funcion_A(const char *commandNumber, char command, char *param1, tList *L);
/*
 * Objetivo:
 *      -Se asigna el ganador de la puja y se borra el producto vaciando su pila de pujas.
 * Entradas:
 *      -CommandNumber: El número de la operación.
 *      -Command: La operación a realizar.
 *      -Param1: El identificador del producto que se va a asignar el ganador de la puja y se va a borrar.
 *      -L: La lista de la que se va a borrar, vaciando su pila de pujas, el elemento.
 * Salidas:
 *      -La lista con el elemento borrado o la misma si no se pudo proceder a asignar el ganador.
 * Precondiciones:
 *      -La lista y la pila del producto deben estar inicializadas.
 * Post-condiciones:
 *      -Las posiciones de los elementos pueden haber cambiado si se produjo el borrado.
 */

void funcion_W(char *commandNumber, char command, char *param1, char *param2, tList *L);
/*
 * Objetivo:
 *      -Borrar la puja más alta de un producto si existe.
 * Entradas:
 *      -CommandNumber: El número de la operación.
 *      -Command: La operación a realizar.
 *      -Param1: El identificador del producto que se va a borrar.
 *      -Param2: El pujador del producto.
 *      -L: La lista de la que se va a eliminar el producto si se realiza.
 * Salidas:
 *      -La lista pila modificada si se ejecutó el borrado o igual si no se produjo.
 * Precondiciones:
 *      -La lista y la pila del producto deben estar inicializadas.
 * Post-condiciones:
 *      -La mayor puja del producto ha cambiado si se ejecutó el borrado.
 */

void funcion_R(char *commandNumber, char command, tList *L);
/*
 * Objetivo:
 *      -Borrar todos los productos que no tengan pujas, vaciando su pila de pujas antes.
 * Entradas:
 *      -CommandNumber: El número de la operación.
 *      -Command: La operación a realizar.
 *      -L: La lista de la que se van a borrar los productos que no tengan pujas.
 * Salidas:
 *      -La lista modificada si se borró algún elemento de la lista o igual si no se borró ninguno.
 * Precondiciones:
 *      -La lista y las pilas de los productos deben de estar inicializadas.
 * Post-condiciones:
 *      -Las posiciones de los elementos pueden haber cambiado si se ejecutó el borrado.
 */

int main(int nargs, char **args) {

    tList L;
    createEmptyList(&L);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &L);

    return 0;
}

const char *Categoria(char categoria) { //Esta es una función para mostrar por pantalla la categoría cada vez que haga falta.
    if (categoria == book) {
        return "book";//Si es un libro.
    } else {
        return "painting";//Si es un cuadro.
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {  //En esta función se procesan las peticiones de los .txt.

    switch (command) {
        case 'N':
            //Si la operación es New.
            funcion_N(commandNumber, command, param1, param2, param3, param4, L);
            break;
        case 'S':
            //Si la operación es Stats.
            funcion_S(commandNumber, command, *L);
            break;
        case 'B':
            //Si la operación es Bid.
            funcion_B(commandNumber, command, param1, param2, param3, L);
            break;
        case 'D':
            //Si la operación es Delete.
            funcion_D(commandNumber, command, param1, L);
            break;
        case 'A':
            //Si la operación es Award.
            funcion_A(commandNumber, command, param1, L);
            break;
        case 'W':
            //Si la operación es Withdraw.
            funcion_W(commandNumber, command, param1, param2, L);
            break;
        case 'R':
            //Si la operación es Remove.
            funcion_R(commandNumber, command, L);
            break;
        default:
            //Si no es ninguna de las operaciones aceptadas, da un error.
            printf("********************\n");
            printf("+ Error that's not a command\n");
            break;
    }
}

void funcion_N(char *commandNumber, char command, char *param1, const char *param2, const char *param3, const char *param4,tList *L) {// Crea un nuevo elemento en la lista.
    printf("********************\n"
           "%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3,param4);// Se muestra la cabecera.

    if (findItem(param1, *L) == LNULL) {//Si ese item no existe en la lista procedemos a agregarlo.
        tItemL item;//Definimos un tItemL para almacenar las variables y vamos introduciendo las variables en ese tItemL (en este caso "item").

        //Copiamos el productId y seller en el tItemL con strcpy.
        strcpy(item.productId, param1);
        strcpy(item.seller, param2);

        //Introducimos el ProductCategory
        if (strcmp(param3, "book") == 0) { //Comparamos el parámetro.
            item.productCategory = book;  //Si es book lo asignamos como tal.
        } else {
            item.productCategory = painting; //Si no, lo asignamos como painting.
        }

        //El productPrice.
        item.productPrice = atof(param4); // Transformamos el char a float para poder asignarlo.

        //Inicializamos el bidCounter a 0.
        item.bidCounter = 0;

        //Generamos la pila que se asigna al item.
        tStack X;  // Se crea una variable que aloje la pila y se crea.
        createEmptyStack(&X);
        item.bidStack = X; // Para luego asignarla.

        // Y por último lo insertamos en la lista comprobando que se inserta
        if (!insertItem(item, L)) {
            printf("+ Error: New not possible\n");
        }else{
            printf("* New: product %s seller %s category %s price %s\n", param1, param2, param3, param4);
            // Escribimos la cabecera de la operación y su operación en la lista.
        }
    } else { // En caso de ya existir se imprime por pantalla un error.
        printf("+ Error: New not possible\n");
    }
}

void funcion_S(char *commandNumber, char command, tList L) { // Muestra los elementos de la lista y estadísticas de ellos.

    // Definiciones auxiliares para el item.
    tPosL p; // Para recorrer la lista.
    tItemL item, maximo; // Para guardar elementos importantes.
    tItemS stack, stackM; // Para guardar las pilas necesarias.

    // Definiciones de las variables necesarias para las estadísticas.
    float sumbook = 0, sumpainting = 0, mediabook, mediapainting, aux = 0;
    int contbook = 0, contpainting = 0, sum = 0;
    char *b = "%";

    printf("********************\n");
    printf("%s %c\n", commandNumber, command); // Se imprime la operación a hacer.

    if (!isEmptyList(L)) { // Si la lista no está vacía se prosigue.

        for (p = L; p != LNULL; p = p->siguiente) { // Se recorre toda la lista.

            item = getItem(p, L); // Por cada vez sacamos el item y lo imprimimos.

            printf("Product %s seller %s category %s price %.2f", item.productId, item.seller,
                   Categoria(item.productCategory), item.productPrice);

            //Para dar datos sobre sus pujas
            if (item.bidCounter == 0) {// Si no tiene pujas se muestra por pantalla este mensaje.
                printf(". No bids\n");
            } else { //Y si tiene sacamos la mayor puja con peek, la guardamos en un tItemS y la mostramos.
                tItemS items;
                items = peek(item.bidStack);
                printf(" bids %d top bidder %s\n", item.bidCounter, items.bidder);
                sum = sum + 1;
            }

            // Aquí mientras se vayan imprimiendo los valores de la lista se hace una recopilación de estadísticas.
            if (item.productCategory == book) {
                sumbook = sumbook + item.productPrice; // Si el elemento es un libro se acumula su precio...
                contbook = contbook + 1; // Y se suma 1 al contador.
            } else {
                sumpainting = sumpainting + item.productPrice; // Si el elemento es una pintura se acumula su precio.
                contpainting = contpainting + 1; // Y se suma 1 al contador.
            }

            //Aquí almaceno el máximo
            if (item.bidCounter != 0) { // Si tiene pujas se extrae la más alta y se hace una cuenta para ver su incremento en %.
                stack = peek(item.bidStack);
                if (((stack.productPrice * 100 / item.productPrice) - 100) > aux) {
                    aux = ((stack.productPrice * 100 / item.productPrice) - 100);
                    maximo = item;
                    stackM = stack;
                }// Si el porcentaje es mas alto que el anterior, se guarda el nuevo.
            }

        }

        // Aquí se hacen las medias de las dos categorías.
        if (contpainting == 0) {// Si es un cuadro.
            mediapainting = 0; // Si la media está partida de 0, es 0...
        } else {
            mediapainting = (sumpainting / (float) contpainting); // ...y si no, se hace la media aritmética.
        }
        if (contbook == 0) {
            mediabook = 0; // Si la media está partida de 0, es 0...
        } else {
            mediabook = (sumbook / (float) contbook);  // ...y si no, se hace la media aritmética.
        }

        // Y finalmente se imprimen por pantalla las estadísticas recopiladas de lso elementos de la lista.
        printf("\nCategory  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", contbook, sumbook, mediabook);
        printf("Painting  %8d %8.2f %8.2f\n", contpainting, sumpainting, mediapainting);

        // Y para acabar se muestra la puja que más ha incrementado su valor en porcentaje a la inicial.
        if (sum > 0) { // Si algún elemento tiene pujas se muestra.
            printf("Top bid: Product %s seller %s category %s price %.2f bidder %s top price %.2f "
                   "increase %.2f%s\n", maximo.productId, maximo.seller, Categoria(maximo.productCategory),
                   maximo.productPrice, stackM.bidder, stackM.productPrice, aux, b);
        } else { // Y si ninguno tiene pujas se pone este mensaje.
            printf("Top bid not possible\n");
        }
    } else {// Si la lista esta vacía.
        printf("+ Error: Stats not possible");
    }
}

void funcion_B(char *commandNumber, char command, char *param1, char *param2, char *param3,tList *L) { // Realiza una puja de un objeto de la lista.
    //Transformo el char en float para usarlo.
    float price;
    price = atof(param3);

    //Muestro la cabecera de la función.
    printf("********************\n");
    printf("%s %c: product %s bidder %s price %.2f\n", commandNumber, command, param1, param2, price);

    //Genero variables auxiliares
    tItemL item; //Para guardar los elementos.
    tItemS stack;//Para guardar las pilas.
    tPosL ubicacion = findItem(param1, *L); // Para hacer llamadas a findItem.

    //Introduzco los datos en un nodo de una pila.
    stack.productPrice = price;
    strcpy(stack.bidder, param2);

    if (ubicacion != LNULL) { //Si el item se encuentra en la lista.

        item = getItem(ubicacion, *L); // Almacenamos sus valores.

        if ((param1 != item.seller)) { //Comparamos que el pujador es distinto que el vendedor.

            if ((isEmptyStack(item.bidStack)) && (stack.productPrice > item.productPrice)) { // Si la pila esta vacía y el precio nuevo es superior.

                //Se agrega la puja a la pila,se aumenta su contador de pujas y se actualiza el item en la lista.
                if (push(stack, &item.bidStack)) {
                    item.bidCounter = item.bidCounter + 1;
                    updateItem(item, ubicacion, L);
                    //Luego se muestra la cabecera.
                    printf("* Bid: product %s bidder %s category %s price %.2f bids %d\n", item.productId, stack.bidder,
                           Categoria(item.productCategory), price, item.bidCounter);
                } else {
                    //Si el push da un false se imprime un error.
                    printf("+ Error: Bid not possible\n");
                }
            } else { // Si la pila no esta vacía.
                if (!isEmptyStack(item.bidStack)) {
                    // Se obtiene la puja mas alta.
                    tItemS stack2;
                    stack2 = peek(item.bidStack);

                    if ((stack.productPrice > stack2.productPrice) && (stack.productPrice > item.productPrice)) {// Se comprueba que la puja nueva sea mayor que la vieja y si es asi se inserta.
                        if (push(stack, &item.bidStack)) {//Si push no da error se aumenta el contador de pujas y se actualiza el elemento.
                            item.bidCounter = item.bidCounter + 1;
                            updateItem(item, findItem(param1, *L), L);

                            printf("* Bid: product %s bidder %s category %s price %.2f bids %d\n", item.productId,
                                   stack.bidder, Categoria(item.productCategory), price, item.bidCounter);
                            //Luego se muestra la operación hecha.
                        } else {//Si el push da error se imprime este mensaje.
                            printf("+ Error: Bid not possible\n");
                        }
                    } else {// Si el precio del viejo es mayor que el del nuevo se imprime un error.
                        printf("+ Error: Bid not possible\n");
                    }
                } else {// Si la pila esta vacía se muestra un error.
                    printf("+ Error: Bid not possible\n");
                }
            }
        } else { // Si el pujador y el vendedor es el mismo sale un error.
            printf("+ Error: Bid not possible\n");
        }
    } else {//Si el elemento no se encuentra en la lista.
        printf("+ Error: Bid not possible\n");
    }
}

void funcion_D(const char *commandNumber, char command, char *param1, tList *L) {  // Borra un elemento de la lista.
    //Mostramos la cabecera.
    printf("********************\n"
           "%s %c: product %s \n", commandNumber, command, param1);

    tPosL ubicacion = findItem(param1, *L);// Para llamadas al findItem.

    if (ubicacion != LNULL) {// Si el item existe en la lista.

        //Obtenemos sus valores.
        tItemL item;
        item = getItem(ubicacion, *L);

        //E imprimimos la operación.
        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", param1, item.seller,
               Categoria(item.productCategory), item.productPrice, item.bidCounter);

        // Luego borramos el item en cuestión, vaciando la pila primero.
        while (!isEmptyStack(item.bidStack)) {//Aquí borramos todas sus pujas con pop y decrementamos el contador de pujas además de actualizar el elemento.
            pop(&item.bidStack);
            item.bidCounter = item.bidCounter - 1;
            updateItem(item, ubicacion, L);
        }
        deleteAtPosition(ubicacion, L);
    } else { //Si no existe se imprime un error.
        // Si ese item no se encuentra en la lista se imprime un error.
        printf("+ Error: Delete not possible\n");
    }
}

void funcion_A(const char *commandNumber, char command, char *param1, tList *L) { // Proclama la puja ganadora de ese elemento.
    printf("********************\n");
    printf("%s %c: product %s\n", commandNumber, command,param1);
    //Imprimimos por pantalla la cabecera y la operación.

    //Genero variables auxiliares.
    tItemL item;
    tItemS items;
    tPosL ubicacion = findItem(param1, *L); // Para las llamadas a findItem.

    if (ubicacion != LNULL) { //Si el elemento se encuentra en la lista.
        //Almacenamos sus valores.
        item = getItem(ubicacion, *L);

        if (!isEmptyStack(item.bidStack)) { // Si la pila no está vacía.
            //Conseguimos su mayor puja con peek.
            items = peek(item.bidStack);

            printf("* Award: product %s bidder %s category %s price %.2f\n", param1, items.bidder,
                   Categoria(item.productCategory), items.productPrice);
            //Y mostramos el ganador.

            // Luego borramos el item en cuestión, vaciando la pila primero.
            while (!isEmptyStack(item.bidStack)) {//Aquí borramos todas sus pujas con pop y decrementamos el contador de pujas además de actualizar el elemento.
                pop(&item.bidStack);
                item.bidCounter = item.bidCounter - 1;
                updateItem(item, ubicacion, L);
            }
            deleteAtPosition(ubicacion, L);
        } else {// Si la pila esta vacía se muestra un error.
            printf("+ Error: Award not possible\n");
        }
    } else {// Si el elemento no existe se muestra un error.
        printf("+ Error: Award not possible\n");
    }
}

void funcion_W(char *commandNumber, char command, char *param1, char *param2, tList *L) { //Borra la mejor puja de un elemento.
    printf("********************\n");
    printf("%s %c: product %s bidder %s\n", commandNumber, command, param1, param2);
    //Mostramos la cabecera.

    //Genero variables auxiliares.
    tItemL item;
    tItemS stack;
    tPosL ubicacion = findItem(param1, *L); // Para las llamadas a findItem.

    if (ubicacion != LNULL) {  //Si existe en la lista.

        //Conseguimos los valores.
        item = getItem(ubicacion, *L);

        if (!isEmptyStack(item.bidStack)) { //Comprobamos si la pila esta vacía.
            //Si no está vacía cogemos su mejor puja y la borramos con pop.
            stack = peek(item.bidStack);

            printf("* Withdraw: product %s bidder %s category %s price %.2f bids %d\n", param1, param2,
                   Categoria(item.productCategory), stack.productPrice, item.bidCounter);
            //
            pop(&item.bidStack);
            item.bidCounter = item.bidCounter - 1;
            updateItem(item, ubicacion, L);
            //
        } else { // Si esta vacía la pila da error.
            printf("+ Error: Withdraw not possible\n");
        }
    } else { //Si no existe da error.
        printf("+ Error: Withdraw not possible\n");
    }
}

void funcion_R(char *commandNumber, char command, tList *L) { // Borra todos los elementos que no tienen pujas.
    //Generamos unas variables auxiliares.
    tPosL p;
    tItemL item;
    float sumador = 0;//Sumador para contar los elementos que tienen pujas.

    //Mostramos la cabecera.
    printf("********************\n");
    printf("%s %c\n", commandNumber, command);

    if (!isEmptyList(*L)) { //Si la lista no está vacía seguimos.
        for (p = *L; p != NULL; p = p->siguiente) { //Recorremos la lista.

            //Vamos tomando los elementos.
            item = getItem(p, *L);

            if (item.bidCounter == 0) { //Comprobamos si no tiene pujas con el contador de pujas.
                sumador = sumador + 1;
                tPosL q;
                q = p; //Creamos una variable auxiliar para borrar el elemento, lo igualamos a la variable que recorre la lista y luego lo borramos.
                deleteAtPosition(q, L);

                printf("Removing product %s seller %s category %s price %.2f bids %d\n", item.productId, item.seller,
                       Categoria(item.productCategory),
                       item.productPrice, item.bidCounter);
                //Luego ponemos la operación realizada.
            }
        }
        if (sumador == 0) { // Si no se encontraron elementos sin pujas se imprime un error.
            printf("+ Error: Remove not possible\n");
        }
    } else { //Si está vacía de imprime un error.
        printf("+ Error: Remove not possible\n");
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, L);
        }
        fclose(f);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}
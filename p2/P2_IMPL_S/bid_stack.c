#include "bid_stack.h"

void createEmptyStack(tStack *stack){ //Crea una pila vacía
    (*stack).top = SNULL; // Iguala el campo top a nulo.
}

bool push (tItemS d, tStack *stack){ //Inserta un nodo en la pila
    if(stack -> top == SMAX-1){ //Si la pila esta llena devuelve falso.
        return false;
    }else{ // Si no está llena aumenta el campo top y lo inserta en el campo data.
        stack -> top++;
        stack -> data[stack->top] = d;
        return true;
    }//Devolviendo true.
}

void pop (tStack *stack){ //Borra el nodo mas alto de la pila.
    stack -> top = stack -> top-1; //Hace decrecer en 1 el campo top, no se puede borrar nada en un array.
}

tItemS peek(tStack stack){ // Devuelve los datos del nodo más alto de la pila.
    return (stack.data[stack.top]); //Devuelve los datos del campo top.
}

bool isEmptyStack(tStack stack){ //Comprueba si la pila está vacía.
    return (stack.top == SNULL); //Devuelve false si no está vacío.
}

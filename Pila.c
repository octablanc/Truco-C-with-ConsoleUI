#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

void inicPila(nodoCarta **pila){
    (*pila) = inicializar();
}

int pilaVacia(nodoCarta **pila){
    return ((*pila) == NULL);
}

nodoCarta *tope(nodoCarta **pila){
    return (*pila);
}

Carta desapilar(nodoCarta **pila){
    Carta rta = (*pila)->dato;
    (*pila) = eliminarPpio((*pila));
    return rta;
}

void apilar(nodoCarta **pilita, Carta dato){
    (*pilita) = ingresarAlprin((*pilita), crearNodo(dato));
}



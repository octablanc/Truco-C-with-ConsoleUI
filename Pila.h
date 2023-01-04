#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "Cartas.h"
#define Pila nodoCarta*

void inicPila(nodoCarta **pila);
int pilaVacia(nodoCarta **pila);
nodoCarta *tope(nodoCarta **pila);
Carta desapilar(nodoCarta **pila);
void apilar(nodoCarta **pilita, Carta dato);

#endif // PILA_H_INCLUDED

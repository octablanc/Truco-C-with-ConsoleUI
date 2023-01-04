#ifndef CARTAS_H_INCLUDED
#define CARTAS_H_INCLUDED
#include "Usuarios.h"

typedef struct{
    int num;
    char clase[10];
    int nivel;
}Carta;

typedef struct{
    Carta dato;
    struct nodoCarta *siguiente;
}nodoCarta;

nodoCarta * inicializar();
nodoCarta * crearNodo (Carta datos);
nodoCarta * ingresarAlprin(nodoCarta * lista , nodoCarta * nuevo);
nodoCarta * buscarUltimo (nodoCarta * lista);
nodoCarta * ingresarALfinal(nodoCarta* lista, nodoCarta * nuevo);
Carta verPrimeraCarta (nodoCarta * lista);
nodoCarta * extraerCarta (nodoCarta * lista);
void mostrarLista (nodoCarta * lista);//mejorar el mostrar . hacer algo con diseno
nodoCarta *eliminarPpio(nodoCarta *lista);
void archivoCartasToArreglo(char cartas[], Carta cartasMazo[]);

#endif // CARTAS_H_INCLUDED

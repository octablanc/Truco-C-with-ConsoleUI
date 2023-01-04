#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>

typedef struct{
    int idUsuario;
    char nombreDeUsuaro[30];
    char contrasenia[30];
    int puntosHistorial;
}Jugador;

typedef struct _nodo{
    Jugador dato;
    struct _nodo *siguiente;
}nodoJugador;

nodoJugador *crearNodoJugador(Jugador jug);
nodoJugador *agregarAlFinal(nodoJugador *lista, nodoJugador *insertar);
void lTF(FILE *fi, nodoJugador *lista);
nodoJugador *fTL(FILE *fi);
nodoJugador *listaToArchivo(char f[], nodoJugador *lista);
nodoJugador *archivoToLista(char archivoJugadores[]);
nodoJugador *borrarLista(nodoJugador *lista);
nodoJugador *buscarJugador(nodoJugador *lista, char nombreDeUsuario[]);
void ingresarNombreUsuario(char c[]);
void ingresarContrasenia(char c[]);
void intentos(int flag, int usuarioOcontrasenia);
void iniciarSesionAdmin();
nodoJugador *agregarUsuario(nodoJugador *lista);
nodoJugador *iniciarSesionUsuario(nodoJugador *lista);

#endif // USUARIOS_H_INCLUDED

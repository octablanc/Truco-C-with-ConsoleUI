#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <pthread.h>
#include "Usuarios.h"
#include "Visual.h"
#include "Cartas.h"
#include "CeldaMazo.h"

int main()
{
    char archivoUsuarios[20] = {"ArchivoUsuarios.dat"};
    char archivoCartas[20] = {"trickMazo.dat"};
    nodoJugador *lista = archivoToLista(archivoUsuarios);
    nodoJugador *jugador = NULL;
    CeldaMazo jugadores[2];

    marcoMenu(0);
    textoTheTrick();
    switch(menu1()){
    case 1:
        system("cls");
        menu2();
        iniciarSesionAdmin();
        getch();
        break;

    case 2:
        system("cls");
        menu2();
        jugador = iniciarSesionUsuario(lista);
        agregarCeldas(jugadores, jugador);
        repartirCartas(jugadores, archivoCartas);
        switch(menuDentroDelJuego()){
        case 1:
            marcoMenu(0);
            buscarPartida();
            marcoMenu(1);
            marcosTableros();
            mostrarCartasJugador1(jugadores);
            getch();
            break;
        }
        break;

    case 3:
        system("cls");
        menu2();
        lista = agregarUsuario(lista);
        break;
    case 4:
        system("cls");
        exit(0);
        break;
    }
    system("cls");
    //printf("%s", jugador->dato.nombreDeUsuaro);
    getch();
    lista = listaToArchivo(archivoUsuarios, lista);
    return 0;
}

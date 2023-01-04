#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "CeldaMazo.h"
#include "Cartas.h"

nodoJugador *generarBot(){
    char bots[30]={"Bots.dat"}; ///Ruta de los bots
    FILE *archi = fopen(bots, "rb");
    srand(time(NULL));
    nodoJugador *aux = NULL;

    if(archi != NULL){
        int num=rand()%10;
        fseek(archi, sizeof(Jugador)*num, SEEK_SET);
        Jugador aux2;
        fread(&aux2, sizeof(Jugador), 1, archi);
        aux = crearNodoJugador(aux2);
        if(fclose(archi) != 0){
            printf("Error al cerrar el archivo");
            Sleep(5000);
            exit(-1);
        }
    }
    else{
        printf("Error al abrir el archivo");
        Sleep(5000);
        exit(-1);
    }
    return aux;
}
void agregarCeldas(CeldaMazo celdas[], nodoJugador *jug){
    nodoJugador *bot = generarBot();
    celdas[0].puntos = 0;
    celdas[0].jug = bot;
    inicPila(&celdas[0].cartas);

    celdas[1].puntos = 0;
    celdas[1].jug = jug;
    inicPila(&celdas[1].cartas);
}

void eliminarPosArregloCartas(Carta cartas[], int validos, int pos){
    for(int i=pos; i<validos; i++){
        cartas[i] = cartas[i+1];
    }
}

void generarMazoMezclado(Pila *aux, Carta cartas[40]){
    srand(time(NULL));
    for(int i = 39; i>=0; i--){
        if(i != 0){
            int pos = rand()%i+1;
            apilar(aux, cartas[pos]);
            eliminarPosArregloCartas(cartas, i+1, pos);
        }
        else
            apilar(aux, cartas[0]);
    }
}

void repartirCartas(CeldaMazo jugadores[], char cartasArchivo[]){
    Carta cartas[cantRegistros(cartasArchivo)];
    Pila mazo;
    inicPila(&mazo);

    archivoCartasToArreglo(cartasArchivo, cartas);
    generarMazoMezclado(&mazo, cartas);

    for(int i=0; i<3; i++){
        apilar(&jugadores[0].cartas, desapilar(&mazo));
        apilar(&jugadores[1].cartas, desapilar(&mazo));
    }

    while(!pilaVacia(&mazo))
        desapilar(&mazo);
}








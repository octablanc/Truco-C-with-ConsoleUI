#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Cartas.h"
#include "Pila.h"
#include "CeldaMazo.h"
#include "gotoxy.h"

void marcoMenu(int linea){
    int x, y;
    color(5);

    /// Cuadrado Lineas
    for(y=1; y<144; y++){
        gotoxy(y, 0); printf("%c", 205);
    }
    for(x=0; x<34; x++){
        gotoxy(144, x); printf("%c", 186);
    }
    for(x=1; x<34; x++){
        gotoxy(1, x); printf("%c", 186);
    }
    for(y=1; y<144; y++){
        gotoxy(y, 34); printf("%c", 205);
    }
    /// Esquinas
    gotoxy(1, 0); printf("%c", 201);
    gotoxy(144, 0); printf("%c", 187);
    gotoxy(1, 34); printf("%c", 200);
    gotoxy(144, 34); printf("%c", 188);

    if(linea == 1){
        for(int i=17; i<34; i++){
            gotoxy(83, i);
            printf("%c", 186);
        }
        for(int i=83; i<144; i++){
            gotoxy(i, 17);
            printf("%c", 205);
        }
        gotoxy(144, 17); printf("%c", 185);
        gotoxy(83, 17); printf("%c", 201);
        gotoxy(83, 34); printf("%c", 202);
    }
    color(15);
}

void textoTheTrick(){

gotoxy(45, 5); puts(" _______ _              _______    _       _     ");
gotoxy(45, 6); puts("(_______) |            (_______)  (_)     | |    ");
gotoxy(45, 7); puts("    _   | |__  _____       _  ____ _  ____| |  _ ");
gotoxy(45, 8); puts("   | |  |  _ \\| ___ |     | |/ ___) |/ ___) |_/ )");
gotoxy(45, 9); puts("   | |  | | | | ____|     | | |   | ( (___|  _ ( ");
gotoxy(45, 10); puts("   |_|  |_| |_|_____)     |_|_|   |_|\\____)_| \\_)");
}

int moverCursor(int X, int Y, int arriba, int abajo, int saltos, int menu){
    int x=X, y=Y, opcion=1;
    char control;

    hidecursor(0);
    switch(menu){
    case 1:
        printOpcionesMenu1();
        break;
    case 2:
        printOpcionesDentroDelJuego();
    }

    do{
        control = getch();
        if(control !=13){
            if(control == 80 && x < abajo){
                x+=saltos;
                opcion++;
            }
            else if(control == 72 && x > arriba){
                x-=saltos;
                opcion--;
            }
            else if(control == 80 && x == abajo+1){
                x-=saltos;
                opcion--;
            }
            else if(control == 72 && x == arriba-1){
                x+=saltos;
                opcion++;
            }

            if(control == 80){
                switch(menu){
                case 1:
                    opcionesMenu1(opcion-1, 0);
                    opcionesMenu1(opcion, 1);
                    break;
                case 2:
                    opcionesMenuDentroDelJuego(opcion-1, 0);
                    opcionesMenuDentroDelJuego(opcion, 1);
                    break;
                }
            }
            else if(control == 72){
                switch(menu){
                case 1:
                    opcionesMenu1(opcion+1, 0);
                    opcionesMenu1(opcion, 1);
                    break;
                case 2:
                    opcionesMenuDentroDelJuego(opcion+1, 0);
                    opcionesMenuDentroDelJuego(opcion, 1);
                    break;
                }
            }
        }
    }while(control != 13);
    color(15);
    gotoxy(y, x); printf(" ");
    hidecursor(1);

    return opcion;
}

void printOpcionesMenu1(){
    color(240);
    gotoxy(59, 20); puts(" Iniciar como Admin   ");
    color(15);
    gotoxy(59, 21); puts(" Iniciar como Usuario ");
    gotoxy(59, 22); puts(" Registrarse          ");
    gotoxy(59, 23); puts(" Salir                ");
}

void printOpcionesDentroDelJuego(){
    color(240);
    gotoxy(59, 20); puts(" Jugar una partida    ");
    color(15);
    gotoxy(59, 21); puts(" Ver perfil           ");
    gotoxy(59, 22); puts(" Configuracion        ");
    gotoxy(59, 23); puts(" Salir                ");
}


void opcionesMenu1(int opcion, int color2){
    switch(opcion){
    case 1:
        if(color2 == 1){
            color(240);
            gotoxy(59, 20); puts(" Iniciar como Admin   ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 20); puts(" Iniciar como Admin   ");
        }
        break;
    case 2:
        if(color2 == 1){
            color(240);
            gotoxy(59, 21); puts(" Iniciar como Usuario ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 21); puts(" Iniciar como Usuario ");
        }
        break;
    case 3:
        if(color2 == 1){
            color(240);
            gotoxy(59, 22); puts(" Registrarse          ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 22); puts(" Registrarse          ");
        }
        break;
    case 4:
        if(color2 == 1){
            color(240);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        break;
    }
}

void opcionesMenuDentroDelJuego(int opcion, int color2){
    switch(opcion){
    case 1:
        if(color2 == 1){
            color(240);
            gotoxy(59, 20); puts(" Jugar una partida    ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 20); puts(" Jugar una partida    ");
            color(15);
        }
        break;
    case 2:
        if(color2 == 1){
            color(240);
            gotoxy(59, 21); puts(" Ver perfil           ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 21); puts(" Ver perfil           ");
            color(15);
        }
        break;
    case 3:
        if(color2 == 1){
            color(240);
            gotoxy(59, 22); puts(" Configuracion        ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 22); puts(" Configuracion        ");
            color(15);
        }
        break;
    case 4:
        if(color2 == 1){
            color(240);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        else{
            color(15);
            gotoxy(59, 23); puts(" Salir                ");
            color(15);
        }
        break;
    }
}

int menu1(){
    int opcion;

    marcoMenu(0);
    textoTheTrick();
    opcion = moverCursor(20, 58, 20, 23, 1, 1);

    return opcion;
}

int menuDentroDelJuego(){
    int opcion;

    color(15);
    gotoxy(59, 24); puts("                        ");
    marcoMenu(0);
    textoTheTrick();
    opcion = moverCursor(20, 58, 20, 23, 1, 2);

    return opcion;
}

void menu2(){
    color(15);
    gotoxy(60, 20); puts("Nombre de usuario");
    color(240);
    gotoxy(60, 21); printf("                     ");
    gotoxy(60, 24); printf("                     ");
    color(15);
    gotoxy(60, 23); printf("Contrase%ca", 164);
    marcoMenu(0);
    textoTheTrick();
}

void buscarPartida(){
    system("cls");
    marcoMenu(0);
    for(int i=0; i<2; i++){
        gotoxy(60, 17); printf("Buscando partida.  ");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida.. ");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida...");
        Sleep(300);
        gotoxy(60, 17); printf("Buscando partida   ");
    }

}

void marcosTableros(){
    ///Arriba
    for(int y=4; y<141; y++){
        gotoxy(y, 1); printf("%c", 196);
    }
    ///Derecha
    for(int x=1; x<16; x++){
        gotoxy(141, x); printf("%c", 179);
    }
    ///Izquierda
    for(int x=1; x<16; x++){
        gotoxy(4, x); printf("%c", 179);
    }
    ///Abajo
    for(int y=4; y<141; y++){
        gotoxy(y, 16); printf("%c", 196);
    }

    ///----------Segundo tablero----------
    ///Arriba
    for(int y=4; y<80; y++){
        gotoxy(y, 17); printf("%c", 196);
    }
    ///Derecha
    for(int x=17; x<34; x++){
        gotoxy(80, x); printf("%c", 179);
    }
    ///Izquierda
    for(int x=17; x<34; x++){
        gotoxy(4, x); printf("%c", 179);
    }
    ///Abajo
    for(int y=4; y<80; y++){
        gotoxy(y, 33); printf("%c", 196);
    }

    gotoxy(4, 1); printf("%c", 218);
    gotoxy(141, 1); printf("%c", 191);
    gotoxy(4, 16); printf("%c", 192);
    gotoxy(141, 16); printf("%c", 217);

    gotoxy(4, 17); printf("%c", 218);
    gotoxy(80, 17); printf("%c", 191);
    gotoxy(4, 33); printf("%c", 192);
    gotoxy(80, 33); printf("%c", 217);
}


void cartasAbajo(int de, int hasta, nodoCarta *carta, int numCarta){
    color(240);
    for(int i=19; i<32; i++){
        for(int j=de; j<hasta; j++){
            gotoxy(j, i); printf(" ");
        }
    }

    color(15);
    if(strcmpi(carta->dato.clase, "basto") == 0)
        color(47);
    else if(strcmpi(carta->dato.clase, "oro") == 0)
        color(224);
    else if(strcmpi(carta->dato.clase, "espada") == 0)
        color(159);
    else
        color(207);

    switch(numCarta){
        case 1:
            gotoxy(11,20); printf("%i", carta->dato.num);
            gotoxy(17, 25); printf("%s", carta->dato.clase);
            gotoxy(27, 30); printf("%i", carta->dato.num);
            color(15);
            break;
        case 2:
            gotoxy(34,20); printf("%i", carta->dato.num);
            gotoxy(40, 25); printf("%s", carta->dato.clase);
            gotoxy(50, 30); printf("%i", carta->dato.num);
            color(15);
            break;
        case 3:
            gotoxy(57,20); printf("%i", carta->dato.num);
            gotoxy(63, 25); printf("%s", carta->dato.clase);
            gotoxy(73, 30); printf("%i", carta->dato.num);
            color(15);
            break;
        }
}

void mostrarCartasJugador1(CeldaMazo celdas[]){
    Pila aux;
    inicPila(&aux);
    apilar(&aux, desapilar(&celdas[1].cartas));
    cartasAbajo(56,75, tope(&aux), 3);
    apilar(&aux, desapilar(&celdas[1].cartas));
    cartasAbajo(33,52, tope(&aux), 2);
    apilar(&aux, desapilar(&celdas[1].cartas));
    cartasAbajo(10,29, tope(&aux), 1);

    while(!pilaVacia(&aux))
        apilar(&celdas[1].cartas, desapilar(&aux));
}

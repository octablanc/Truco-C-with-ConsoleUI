#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"

nodoJugador *crearNodoJugador(Jugador jug){
    nodoJugador *aux = malloc(sizeof(nodoJugador));
    aux->dato = jug;
    aux->siguiente = NULL;
    return aux;
}

nodoJugador *agregarAlFinal(nodoJugador *lista, nodoJugador *insertar){
    if(lista != NULL){
        if(lista->siguiente != NULL)
            lista = agregarAlFinal(lista->siguiente, insertar);
        else{
            insertar->dato.idUsuario = lista->dato.idUsuario+1;
            lista->siguiente = insertar;
        }
    }
    else{
        lista = insertar;
        lista->dato.idUsuario = 0;
    }
    return lista;
}

void lTF(FILE *fi, nodoJugador *lista){
    if(lista != NULL){
        Jugador aux = lista->dato;
        fwrite(&aux, sizeof(Jugador), 1, fi);
        if(lista->siguiente != NULL)
            lTF(fi, lista->siguiente);
    }
}

nodoJugador *listaToArchivo(char f[], nodoJugador *lista){
    FILE *fi = fopen(f, "wb");

    if(fi != NULL){
        lTF(fi, lista);
        if(fclose(fi) != 0)
            printf("\n Error closing file");
    }
    else
        printf("\n Error opening file");
    return borrarLista(lista);
}

nodoJugador *fTL(FILE *fi){
    nodoJugador *aux = NULL;
    Jugador aux2;
    if(fread(&aux2, sizeof(Jugador), 1, fi) > 0){
        aux = crearNodoJugador(aux2);
        aux->siguiente = fTL(fi);
    }
    return aux;
}


nodoJugador *archivoToLista(char archivoJugadores[]){
    FILE *archi = fopen(archivoJugadores, "rb");
    nodoJugador *aux = NULL;
    if(archi != NULL){
        aux = fTL(archi);
        if(fclose(archi) != 0){
            system("cls");
            printf("\n Error al cerrar el archivo\n");
        }
    }
    else{
        system("cls");
        printf("\n Error al abrir el archivo\n");
    }
    return aux;
}

nodoJugador *borrarLista(nodoJugador *lista){
    if(lista != NULL){
        if(lista->siguiente != NULL)
            borrarLista(lista->siguiente);
        free(lista);
    }
    return NULL;
}

nodoJugador *buscarJugador(nodoJugador *lista, char nombreDeUsuario[]){
    nodoJugador *aux = NULL;
    if(lista != NULL){
        if(strcmpi(lista->dato.nombreDeUsuaro, nombreDeUsuario)==0)
            aux = lista;
        else if(lista->siguiente != NULL)
            aux = buscarJugador(lista->siguiente, nombreDeUsuario);
    }
    return aux;
}

void ingresarNombreUsuario(char c[]){
    int i = 0;
    fflush(stdin);
    hidecursor(1);

    gotoxy(60, 21); while(c[i]!=13){
        if(i == 1){
            color(4);
            gotoxy(55, 18); printf("                              ");
            color(240);
            gotoxy(61, 21);
        }
        c[i] = getch();

        if(c[i]>32 && i<20){
            putchar(c[i]);
            i++;
        }
        else if(c[i]==8 && i>0){
                putchar(8);
                putchar(' ');
                putchar(8);
                i--;
        }
    }
    c[i] = '\0';
    hidecursor(0);
}

void ingresarContrasenia(char c[]){
    int i = 0;
    fflush(stdin);
    hidecursor(1);

    gotoxy(60, 24); while(c[i]!=13){
        if(i == 1){
            color(4);
            gotoxy(55, 18); printf("                              ");
            color(240);
            gotoxy(61, 24);
        }
        c[i] = getch();

        if(c[i]>32 && i<20){
            putchar('*');
            i++;
        }
        else if(c[i]==8 && i>0){
                putchar(8);
                putchar(' ');
                putchar(8);
                i--;
        }
    }
    c[i] = '\0';
    hidecursor(0);
}

void intentos(int flag, int usuarioOcontrasenia){
    if(flag == 3){
        color(4);
        gotoxy(40, 27);
        printf("Intentaste mas de 3 veces, el programa se cerrara en 5 segundos");
        Sleep(5000);
        system("cls");
        exit(1);
    }
    else if(flag != -1){
        if(usuarioOcontrasenia == 1){
            color(4);
            gotoxy(60, 18); printf("Usuario incorrecto");
            hidecursor(0);
            color(240);
            gotoxy(60, 21); printf("                     ");
        }
        else if(usuarioOcontrasenia == 2){
            color(4);
            gotoxy(60, 18); printf("Contrase%ca incorrecta",164);
            hidecursor(0);
            color(240);
            gotoxy(60, 24); printf("                     ");
        }
        else{
            color(4);
            gotoxy(60, 18); printf("El usuario ya existe");
            hidecursor(0);
            color(240);
            gotoxy(60, 24); printf("                     ");
        }
    }
}


void iniciarSesionAdmin(){
    char nombre[30] = {"admin"};
    char contrasenia[30] = {"123451"};
    char nombreAevaluar[30];
    char contraseniaAevaluar[30];
    int flag = 0;

    color(240);
    do{
        ingresarNombreUsuario(nombreAevaluar);
        if(strcmpi(nombreAevaluar, nombre) != 0){
            flag ++;
            intentos(flag, 1);
        }
        else
            flag = -1;
    }while(flag != -1);
    flag = 0;

    do{
        ingresarContrasenia(contraseniaAevaluar);
        if(strcmpi(contraseniaAevaluar, contrasenia) != 0){
            flag ++;
            intentos(flag, 2);
        }
        else
            flag = -1;
    }while(flag != -1);
    color(15);
}

nodoJugador *agregarUsuario(nodoJugador *lista){
    Jugador aux;
    aux.puntosHistorial = 0;
    nodoJugador *usuario;
    int flag = 0;
    char aEvaluar[30];

    color(240);
    do{
        ingresarNombreUsuario(aEvaluar);
        usuario = buscarJugador(lista ,aEvaluar);
        if(usuario != NULL){
            flag++;
            intentos(flag, 3);
        }
    }while(usuario != NULL);
    strcpy(aux.nombreDeUsuaro, aEvaluar);

    ingresarContrasenia(aux.contrasenia);
    color(15);

    lista = agregarAlFinal(lista, crearNodoJugador(aux));
    return lista;
}

nodoJugador *iniciarSesionUsuario(nodoJugador *lista){
    char nombreUsuario[30];
    char contrasenia[30];
    nodoJugador *usuario = NULL;

    int flag = 0;
    color(240);
    do{
        ingresarNombreUsuario(nombreUsuario);
        usuario = buscarJugador(lista, nombreUsuario);
        if(usuario == NULL){
            flag ++;
            intentos(flag, 1);
        }
    }while(usuario == NULL);
    flag = 0;

    do{
        ingresarContrasenia(contrasenia);
        flag ++;
        if(strcmpi(contrasenia, usuario->dato.contrasenia) == 0)
            flag = -1;
        intentos(flag, 2);
    }while(flag != -1);

    return usuario;
}


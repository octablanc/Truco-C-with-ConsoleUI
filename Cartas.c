#include <stdio.h>
#include <stdlib.h>
#include "Cartas.h"

nodoCarta * inicializar()
{
    return NULL;
}

nodoCarta * crearNodo (Carta datos)
{
    nodoCarta * nuevo=(nodoCarta*) malloc(sizeof(nodoCarta));
    nuevo->dato=datos;
    nuevo->siguiente=NULL;
    return nuevo;
}
nodoCarta * ingresarAlprin(nodoCarta * lista , nodoCarta * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}
nodoCarta * buscarUltimo (nodoCarta * lista)
{
    nodoCarta * seg = lista;
    if(seg)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}
nodoCarta * ingresarALfinal(nodoCarta* lista, nodoCarta * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoCarta * ultimo = buscarUltimo(lista);
        ultimo ->siguiente = nuevo;

    }
    return lista;
}
Carta verPrimeraCarta (nodoCarta * lista)
{
    Carta primer;
    if (lista)
    {
        primer=lista->dato;
    }
    return primer;
}
nodoCarta * extraerCarta (nodoCarta * lista )
{
    nodoCarta * aux = lista;
    lista=lista->siguiente;
    free(aux);

    return lista;
}
void mostrarLista (nodoCarta * lista)
{
    nodoCarta * seg;
    seg = lista;

    printf("\ntope.........................................base\n");
    while(seg!=NULL)
    {
        printf(" | %d",seg->dato);
        seg=seg->siguiente;//recorre
    }
    printf("\ntope.........................................base\n");
}

nodoCarta *eliminarPpio(nodoCarta *lista){
    if(lista){
        nodoCarta *aux = lista;
        lista = aux->siguiente;
        free(aux);
    }
    return lista;
}

void archivoCartasToArreglo(char cartas[], Carta cartasMazo[]){
    FILE *archi = fopen(cartas, "rb");

    if(archi != NULL){
        int i=0;
        while(fread(&cartasMazo[i], sizeof(Carta), 1, archi)>0)
            i++;
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
}

int cantRegistros(char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    int cant = 0;
    if(archi != NULL){
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi) / sizeof(Carta);
        fclose(archi);
    }
    return cant;
}

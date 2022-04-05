#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define max 200 /*Macro que almacena un valor maximo para ser usado a la hora de leer una linea de un archivo*/

typedef struct nodo{
    char rut[max];
    char nombre[max];
    int cantEntradas;
    struct nodo *sig;
}lista;

lista *raiz = NULL;

void insertar(char linea[]){
    lista *nuevo = malloc(sizeof(lista));
    char *token;
    token = strtok(linea, ",");
    strcpy(nuevo->rut, token);
    token = strtok(NULL, ",");
    strcpy(nuevo->nombre, token);
    token = strtok(NULL, ",");
    nuevo->cantEntradas = atoi(token);
    if(raiz == NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void quitarDuplicados(){
    lista *recorrido, *duplicado;
    recorrido = raiz;
    while(recorrido != NULL){
        if(strcmp(recorrido->rut, recorrido->sig->rut) == 0){
            duplicado = recorrido->sig;
            recorrido->cantEntradas += recorrido->sig->cantEntradas;
            recorrido->sig = recorrido->sig->sig;
            free(duplicado);
        }
        else{
            recorrido = recorrido->sig;
        }
    }
}

void imprimir(){
    lista *recorrido = raiz;
    printf("\tCompras de usuarios\n");
    int i = 0;
    while(recorrido != NULL){
        printf("\n%i .- \nRut: %s\nNombre: %s\nCantidad de entradas: %i",i,recorrido->rut,recorrido->nombre,recorrido->cantEntradas);
        recorrido = recorrido->sig;
        i++;
    }
}

void limpiar(){
    lista *recorrido, *basura;
    recorrido = raiz;
    while(recorrido != NULL){
        basura = recorrido;
        recorrido = recorrido->sig;
        free(basura);
    }
}

int main(){
    FILE *f;
    f = fopen("entrada.txt", "r");
    char linea[max];
    while(!feof(f)){
        fgets(linea, max, f);
        insertar(linea);
    }
    quitarDuplicados();
    imprimir();
    fclose(f);
    limpiar();
}
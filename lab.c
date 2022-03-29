#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define max 200 /*Variable que almacena un valor maximo para ser usado a la hora de leer una linea de un archivo*/

typedef struct nodo{
    char linea[max];
    struct nodo *sig;
}lista;

lista *raiz = NULL;

void insertar(char linea[]){
    lista *nuevo = malloc(sizeof(lista));
    strcpy(nuevo->linea, linea);
    if(raiz == NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void imprimir(){
    lista *recorrido = raiz;
    printf("\tCompras de usuarios\n");
    while(recorrido != NULL){
        printf("1.- %s\n", recorrido->linea);
        recorrido = recorrido->sig;
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
}
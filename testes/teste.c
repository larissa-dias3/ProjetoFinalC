#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar (tFila *f){
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;
}

int vazia (tFila *f){
    return (f->head == NULL);
}

int inserir(tFila *f, int d){
    tipoNo *novo = (tipoNo*) malloc (sizeof(tipoNo));
    if(novo!=NULL){
        novo->prox = NULL;
        novo->ant = f->tail; 
        novo->dado = d; 
        if(vazia(f)) f->head = novo; 
        else f->tail->prox = novo;
        f->tail = novo; 
        f->size++; 
    } else return 0;
}

int remover(tFila *f, int *d){
    tipoNo * aux = f->head;
    if (vazia(f)) return 0;
    *d = aux->dado;
    if(f->head == f->tail ) f->tail = NULL; 
    f->head = f->head->prox; 
    if(f->head!=NULL) f->head->ant = NULL;
    f->size--;
    free (aux);
    return 1; 
}

void imprimeFila (tFila *f){
    tipoNo * aux = f->head;
    if(vazia(f)) {
        printf("Fila VAZIA.\n");
        return 0;
    }
    printf("\nElementos da fila: ");
    while (aux!=NULL){
        printf("%d ",aux->dado);
        aux = aux->prox; 
    }
    printf("\n\n");
}

int tamanho(tFila *f){
    return f->size; 
}
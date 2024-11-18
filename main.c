#include <stdio.h>

typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} contato;

typedef struct {
    contato *contatos;
    int prox;
    int ant;
} elo;

int main(){
    return 0;
}
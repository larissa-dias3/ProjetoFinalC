#include <stdio.h>

typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} contato;

typedef struct {
    contato contatos;
    struct elo* proximo;
    struct elo* anterior;
} elo;

typedef struct {
    elo* inicio;
    elo* fim;
    int tamanho;
} lista;

int main(){
    return 0;
}
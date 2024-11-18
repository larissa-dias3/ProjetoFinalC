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

#include "main.h"
int main(){
    int operacao;
    //mostra menu
    menu();
    printf("Informe o numero da operacao que deseja executar: ");
    scanf("%d", &operacao);

    switch (operacao){
    case 1:
        insereContato();
        break;
    
    default:    
        break;
    }
    return 0;
}
